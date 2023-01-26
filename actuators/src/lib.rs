use std::sync::Arc;

use center::CenterActuatorsController;
use dos_actors::{
    io::{Data, Read, Size, Write},
    Update,
};
use dos_clients_io::gmt_m1::segment;
use outer::OuterActuatorsController;

pub enum ActuatorsController {
    Center(CenterActuatorsController),
    Outer(OuterActuatorsController),
}
impl ActuatorsController {
    pub fn center() -> Self {
        Self::Center(CenterActuatorsController::new())
    }
    pub fn outer() -> Self {
        Self::Outer(OuterActuatorsController::new())
    }
    pub fn step(&mut self) {
        match self {
            ActuatorsController::Center(actuators) => actuators.step(),
            ActuatorsController::Outer(actuators) => actuators.step(),
        }
    }
}

pub struct Actuators<const ID: u8> {
    pub controller: ActuatorsController,
}
impl<const ID: u8> Actuators<ID> {
    pub fn new() -> Self {
        assert!(
            ID >= 1 && ID <= 7,
            "{} is an invalid segment ID, the segment ID must be in the range [1,7]",
            ID
        );
        if ID == 7 {
            Self {
                controller: ActuatorsController::center(),
            }
        } else {
            Self {
                controller: ActuatorsController::outer(),
            }
        }
    }
    pub fn step(&mut self) {
        self.controller.step()
    }
}

impl<const ID: u8> Size<segment::BarycentricForce> for Actuators<ID> {
    fn len(&self) -> usize {
        6
    }
}
impl<const ID: u8> Size<segment::ActuatorAppliedForces<ID>> for Actuators<ID> {
    fn len(&self) -> usize {
        match self.controller {
            ActuatorsController::Center(_) => 306,
            ActuatorsController::Outer(_) => 335,
        }
    }
}
impl<const ID: u8> Size<segment::ActuatorCommandForces<ID>> for Actuators<ID> {
    fn len(&self) -> usize {
        match self.controller {
            ActuatorsController::Center(_) => 306,
            ActuatorsController::Outer(_) => 335,
        }
    }
}

impl<const ID: u8> Update for Actuators<ID> {
    fn update(&mut self) {
        self.step();
    }
}

impl<const ID: u8> Read<segment::BarycentricForce> for Actuators<ID> {
    fn read(&mut self, data: Arc<Data<segment::BarycentricForce>>) {
        match &mut self.controller {
            ActuatorsController::Outer(OuterActuatorsController { inputs, .. }) => {
                inputs.LC_FxyzMxyz_CG = (**data)
                    .as_slice()
                    .try_into()
                    .expect("failed to import `BarycentricForce` in `Actuators` input");
            }
            ActuatorsController::Center(CenterActuatorsController { inputs, .. }) => {
                inputs.LC_FxyzMxyz_CG = (**data)
                    .as_slice()
                    .try_into()
                    .expect("failed to import `BarycentricForce` in `Actuators` input");
            }
        };
    }
}

impl<const ID: u8> Read<segment::ActuatorCommandForces<ID>> for Actuators<ID> {
    fn read(&mut self, data: Arc<Data<segment::ActuatorCommandForces<ID>>>) {
        match &mut self.controller {
            ActuatorsController::Outer(OuterActuatorsController { inputs, .. }) => {
                inputs.SA_offsetF_cmd = (**data)
                    .as_slice()
                    .try_into()
                    .expect("failed to import `BarycentricForce` in `Actuators` input");
            }
            ActuatorsController::Center(CenterActuatorsController { inputs, .. }) => {
                inputs.SA_offsetF_cmd = (**data)
                    .as_slice()
                    .try_into()
                    .expect("failed to import `BarycentricForce` in `Actuators` input");
            }
        };
    }
}

impl<const ID: u8> Write<segment::ActuatorAppliedForces<ID>> for Actuators<ID> {
    fn write(&mut self) -> Option<Arc<Data<segment::ActuatorAppliedForces<ID>>>> {
        let data = match &self.controller {
            ActuatorsController::Outer(OuterActuatorsController { outputs, .. }) => outputs
                .Res_Act_F
                .try_into()
                .expect("failed to export `HardpointsDynamics` output to `BarycentricForce`"),
            ActuatorsController::Center(CenterActuatorsController { outputs, .. }) => outputs
                .Res_Act_F
                .try_into()
                .expect("failed to export `HardpointsDynamics` output to `BarycentricForce`"),
        };
        Some(Arc::new(Data::new(data)))
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use matio_rs::MatFile;

    #[test]
    fn impulse() {
        let mat = MatFile::load("m1_act_impulse_test.mat").unwrap();
        // mat var dims: time [24], actuator [335/306], impulse [6]
        let cs_act_imp_t: Vec<f64> = mat.var("CSact_imp_t").unwrap();
        let cs_act_imp_y: Vec<f64> = mat.var("CSact_imp_y").unwrap();
        let oa_act_imp_t: Vec<f64> = mat.var("OAact_imp_t").unwrap();
        let oa_act_imp_y: Vec<f64> = mat.var("OAact_imp_y").unwrap();

        dbg!(oa_act_imp_y.len());
        dbg!(cs_act_imp_y.len());

        oa_act_imp_y
            .chunks(24)
            .take(3)
            .for_each(|y| println!("{:8.6?}", y));

        let mut outer_ctrl = Actuators::<1>::new();
        let mut center_ctrl = Actuators::<7>::new();
        let mut center_y = vec![];
        let mut outer_y = vec![];

        let impulse_amplitude = 100f64;
        let impulse_channel = 0;

        let n_outer = 335;
        let n_center = 306;
        let mat_outer_y = oa_act_imp_y
            .chunks(24 * n_outer)
            .nth(impulse_channel)
            .unwrap();
        let mat_center_y = cs_act_imp_y
            .chunks(24 * n_center)
            .nth(impulse_channel)
            .unwrap();

        for (i, _) in cs_act_imp_t.iter().enumerate() {
            if i == 0 {
                match &mut outer_ctrl.controller {
                    ActuatorsController::Outer(OuterActuatorsController { inputs, .. }) => {
                        inputs.LC_FxyzMxyz_CG[impulse_channel] = impulse_amplitude
                    }
                    ActuatorsController::Center(CenterActuatorsController { inputs, .. }) => {
                        inputs.LC_FxyzMxyz_CG[impulse_channel] = impulse_amplitude
                    }
                };
                match &mut center_ctrl.controller {
                    ActuatorsController::Outer(OuterActuatorsController { inputs, .. }) => {
                        inputs.LC_FxyzMxyz_CG[impulse_channel] = impulse_amplitude
                    }
                    ActuatorsController::Center(CenterActuatorsController { inputs, .. }) => {
                        inputs.LC_FxyzMxyz_CG[impulse_channel] = impulse_amplitude
                    }
                };
            } else {
                match &mut outer_ctrl.controller {
                    ActuatorsController::Outer(OuterActuatorsController { inputs, .. }) => {
                        inputs.LC_FxyzMxyz_CG[impulse_channel] = 0f64
                    }
                    ActuatorsController::Center(CenterActuatorsController { inputs, .. }) => {
                        inputs.LC_FxyzMxyz_CG[impulse_channel] = 0f64
                    }
                };
                match &mut center_ctrl.controller {
                    ActuatorsController::Outer(OuterActuatorsController { inputs, .. }) => {
                        inputs.LC_FxyzMxyz_CG[impulse_channel] = 0f64
                    }
                    ActuatorsController::Center(CenterActuatorsController { inputs, .. }) => {
                        inputs.LC_FxyzMxyz_CG[impulse_channel] = 0f64
                    }
                };
            }
            outer_ctrl.step();
            center_ctrl.step();
            match &outer_ctrl.controller {
                ActuatorsController::Outer(OuterActuatorsController { outputs, .. }) => {
                    outer_y.extend_from_slice(outputs.Res_Act_F.as_slice());
                }
                ActuatorsController::Center(CenterActuatorsController { outputs, .. }) => {
                    center_y.extend_from_slice(outputs.Res_Act_F.as_slice());
                }
            };
            match &center_ctrl.controller {
                ActuatorsController::Outer(OuterActuatorsController { outputs, .. }) => {
                    outer_y.extend_from_slice(outputs.Res_Act_F.as_slice());
                }
                ActuatorsController::Center(CenterActuatorsController { outputs, .. }) => {
                    center_y.extend_from_slice(outputs.Res_Act_F.as_slice());
                }
            };
        }
        dbg!(outer_y.len());
        dbg!(mat_outer_y.len());
        let mut y_err = 0f64;
        for i in 0..n_outer {
            let mat_y = mat_outer_y.chunks(24).nth(i).unwrap();
            let rs_y: Vec<_> = outer_y.chunks(n_outer).map(|y| y[i]).collect();
            y_err += rs_y
                .iter()
                .zip(mat_y)
                .map(|(y, mat_y)| y - mat_y)
                .map(|x| x * x)
                .sum::<f64>();
        }
        let y_err = (y_err / (n_outer * 24) as f64).sqrt();
        dbg!(y_err);
        let mut y_err = 0f64;
        for i in 0..n_center {
            let mat_y = mat_center_y.chunks(24).nth(i).unwrap();
            let rs_y: Vec<_> = center_y.chunks(n_center).map(|y| y[i]).collect();
            y_err += rs_y
                .iter()
                .zip(mat_y)
                .map(|(y, mat_y)| y - mat_y)
                .map(|x| x * x)
                .sum::<f64>();
        }
        let y_err = (y_err / (n_center * 24) as f64).sqrt();
        dbg!(y_err);
    }
}
