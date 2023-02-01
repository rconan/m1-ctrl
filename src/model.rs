use crate::{Hardpoints, LoadCells};
use actuators::Actuators;
use dos_clients_io::gmt_m1::segment::{
    ActuatorAppliedForces, ActuatorCommandForces, BarycentricForce, HardpointsForces,
    HardpointsMotion, RBM,
};
use gmt_dos_actors::{io::Size, model::Unknown, prelude::*};
use gmt_fem::{
    dos::{DiscreteModalSolver, ExponentialMatrix},
    FEM,
};
use nalgebra as na;

type M = na::Matrix6<f64>;

#[derive(Debug, Default, Clone)]
pub struct SegmentBuilder {
    rbm_inputs: Option<Signals>,
    actuators_inputs: Option<Signals>,
    stiffness: Option<f64>,
    rbm_2_hp: Option<Vec<M>>,
    lc_2_cg: Option<Vec<M>>,
}
impl SegmentBuilder {
    pub fn new() -> Self {
        Default::default()
    }
    pub fn rigid_body_motions_inputs(mut self, signals: Signals) -> Self {
        self.rbm_inputs = Some(signals);
        self
    }
    pub fn actuators_inputs(mut self, signals: Signals) -> Self {
        self.actuators_inputs = Some(signals);
        self
    }
    pub fn fem_calibration(self, whole_fem: &FEM) -> Self {
        // Hardpoints stiffness
        println!("HARDPOINTS STIFFNESS");
        let mut fem = whole_fem.clone();
        fem.keep_inputs(&[15]);
        fem.keep_outputs(&[22]);
        let gain = fem.reduced_static_gain().unwrap();
        let mut stiffness = 0f64;
        for i in 0..7 {
            let rows = gain.rows(i * 12, 12);
            let segment = rows.columns(i * 6, 6);
            let cell = segment.rows(0, 6);
            let face = segment.rows(6, 6);
            stiffness += (face - cell).diagonal().map(f64::recip).mean();
        }
        stiffness /= 7f64;

        // RBM2HP
        println!("RBM 2 HP");
        let mut fem = whole_fem.clone();
        fem.keep_inputs(&[15]);
        fem.keep_outputs(&[24]);
        let gain = fem.reduced_static_gain().unwrap();
        let mut rbm_2_hp = vec![];
        for i in 0..7 {
            let rows = gain.rows(i * 6, 6);
            let segment = rows
                .columns(i * 6, 6)
                .try_inverse()
                .unwrap()
                .map(|x| x / stiffness);
            rbm_2_hp.push(na::Matrix6::from_column_slice(segment.as_slice()))
        }

        // LC2CG (include negative feedback)
        println!("LC 2 CG");
        let mut fem = whole_fem.clone();
        fem.keep_inputs(&[16]);
        fem.keep_outputs(&[22]);
        let gain = fem.reduced_static_gain().unwrap();
        let mut lc_2_cg = vec![];
        for i in 0..7 {
            let rows = gain.rows(i * 12, 12);
            let segment = rows.columns(i * 6, 6);
            let cell = segment.rows(0, 6);
            let face = segment.rows(6, 6);
            let mat = (cell - face).try_inverse().unwrap().map(|x| x / stiffness);
            lc_2_cg.push(na::Matrix6::from_column_slice(mat.as_slice()));
        }

        Self {
            stiffness: Some(stiffness),
            rbm_2_hp: Some(rbm_2_hp),
            lc_2_cg: Some(lc_2_cg),
            ..self
        }
    }
    pub fn build<const ID: u8, const ACTUATOR_RATE: usize>(
        self,
        plant: &mut Actor<DiscreteModalSolver<ExponentialMatrix>>,
    ) -> Model<Unknown> {
        let n_step = 3_000;
        let mut hp_setpoint: Initiator<_> = (
            self.rbm_inputs.unwrap_or_else(|| Signals::new(6, n_step)),
            format!(
                "M1S{ID}
            RBM Inputs"
            ),
        )
            .into();
        let stiffness = self.stiffness.unwrap_or(135e6);
        let rbm_2_hp = self.rbm_2_hp.unwrap_or_else(|| todo!());
        let lc_2_cg = self.lc_2_cg.unwrap_or_else(|| todo!());
        let mut hardpoints: Actor<_> = (
            Hardpoints::new(stiffness, rbm_2_hp[ID as usize - 1]),
            format!(
                "M1S{ID}
                    Hardpoints"
            ),
        )
            .into();

        let mut loadcells: Actor<_, 1, ACTUATOR_RATE> = (
            LoadCells::new(stiffness, lc_2_cg[ID as usize - 1]),
            format!(
                "M1S{ID}
                    Loadcells"
            ),
        )
            .into();

        let mut actuators: Actor<_, ACTUATOR_RATE, 1> = (
            Actuators::<ID>::new(),
            format!(
                "M1S{ID}
                    Actuators"
            ),
        )
            .into();
        let mut actuators_setpoint: Initiator<_, ACTUATOR_RATE> = (
            Signals::new(
                Size::<ActuatorCommandForces<ID>>::len(&Actuators::<ID>::new()),
                n_step,
            ),
            format!(
                "M1S{ID}
                    Actuators Inputs"
            ),
        )
            .into();

        hp_setpoint
            .add_output()
            .build::<RBM<ID>>()
            .into_input(&mut hardpoints);

        actuators_setpoint
            .add_output()
            .build::<ActuatorCommandForces<ID>>()
            .into_input(&mut actuators);

        hardpoints
            .add_output()
            .multiplex(2)
            .build::<HardpointsForces<ID>>()
            .into_input(&mut loadcells)
            .into_input(plant);

        loadcells
            .add_output()
            .bootstrap()
            .build::<BarycentricForce<ID>>()
            .into_input(&mut actuators);

        actuators
            .add_output()
            .build::<ActuatorAppliedForces<ID>>()
            .into_input(plant);

        plant
            .add_output()
            .bootstrap()
            .build::<HardpointsMotion<ID>>()
            .into_input(&mut loadcells);

        model!(
            hp_setpoint,
            hardpoints,
            loadcells,
            actuators_setpoint,
            actuators
        )
    }
}
