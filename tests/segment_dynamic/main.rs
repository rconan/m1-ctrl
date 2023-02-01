use dos_clients_io::gmt_m1::segment::{
    ActuatorAppliedForces, ActuatorCommandForces, BarycentricForce, HardpointsForces,
    HardpointsMotion, RBM,
};
use gmt_dos_actors::{io::Size, prelude::*};
use gmt_fem::{
    dos::{DiscreteModalSolver, ExponentialMatrix},
    fem_io::{M1ActuatorsSegment1, OSSHardpointD, OSSHarpointDeltaF, OSSM1Lcl},
    FEM,
};
use gmt_m1_ctrl::{Actuators, Hardpoints, LoadCells};
use nalgebra as na;

const ACTUATOR_RATE: usize = 100;

macro_rules! segment_model {
    ($sid:expr) => {
        let sim_sampling_frequency = 1000;
        let sim_duration = 10_usize; // second
        let n_step = sim_sampling_frequency * sim_duration;

        let whole_fem = FEM::from_env()?;
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

        let fem_dss = DiscreteModalSolver::<ExponentialMatrix>::from_fem(whole_fem)
            .sampling(sim_sampling_frequency as f64)
            .proportional_damping(2. / 100.)
            .ins::<OSSHarpointDeltaF>()
            .ins::<M1ActuatorsSegment1>()
            .outs::<OSSHardpointD>()
            .outs::<OSSM1Lcl>()
            .use_static_gain_compensation()
            .build()?;

        let rbm_fun = |i| (-1f64).powi(i as i32) * (1 + (i % 3)) as f64;
        let mut hp_setpoint: Initiator<_> = (
            (0..6).fold(Signals::new(6, n_step), |signals, i| {
                signals.channel(
                    i,
                    Signal::Sigmoid {
                        amplitude: rbm_fun(i) * 1e-6,
                        sampling_frequency_hz: sim_sampling_frequency as f64,
                    },
                )
            }),
            "RBM",
        )
            .into();
        let mut hardpoints: Actor<_> =
            Hardpoints::new(dbg!(stiffness), rbm_2_hp[$sid as usize - 1]).into();

        let mut loadcell: Actor<_, 1, ACTUATOR_RATE> =
            LoadCells::new(stiffness, lc_2_cg[$sid as usize - 1]).into();

        let mut actuators: Actor<_, ACTUATOR_RATE, 1> = Actuators::<$sid>::new().into();
        let mut actuators_setpoint: Initiator<_, ACTUATOR_RATE> = (
            Signals::new(
                Size::<ActuatorCommandForces<$sid>>::len(&Actuators::<$sid>::new()),
                n_step,
            ),
            "Actuators",
        )
            .into();

        let mut plant: Actor<_> = fem_dss.into();

        // let logging = Logging::<f64>::new(1).into_arcx();
        // let mut logger: Terminator<_> = Actor::new(logging.clone());

        // let a_logging = Logging::<f64>::new(1).into_arcx();
        // let mut a_logger: Terminator<_, 100> = Actor::new(a_logging.clone());

        let plant_logging = Logging::<f64>::new(1).into_arcx();
        let mut plant_logger: Terminator<_> = Actor::new(plant_logging.clone());

        hp_setpoint
            .add_output()
            .build::<RBM<$sid>>()
            .into_input(&mut hardpoints);

        actuators_setpoint
            .add_output()
            .build::<ActuatorCommandForces<$sid>>()
            .into_input(&mut actuators);

        hardpoints
            .add_output()
            .multiplex(2)
            .build::<HardpointsForces<$sid>>()
            .into_input(&mut loadcell)
            .into_input(&mut plant);
        // .into_input(&mut logger);

        loadcell
            .add_output()
            .bootstrap()
            .build::<BarycentricForce>()
            .into_input(&mut actuators);
        // .into_input(&mut a_logger);

        actuators
            .add_output()
            .build::<ActuatorAppliedForces<$sid>>()
            .into_input(&mut plant);

        plant
            .add_output()
            .bootstrap()
            .build::<HardpointsMotion<$sid>>()
            .into_input(&mut loadcell);

        plant
            .add_output()
            .bootstrap()
            .unbounded()
            .build::<RBM<$sid>>()
            .into_input(&mut plant_logger);

        model!(
            hp_setpoint,
            actuators_setpoint,
            hardpoints,
            loadcell,
            actuators,
            plant,
            // logger,
            // a_logger,
            plant_logger
        )
        .flowchart()
        .check()?
        .run()
        .await?;

        /*     println!("HardpointsForces");
                (*logging.lock().await)
                    .chunks()
                    .enumerate()
                    .skip(n_step - 20)
                    .for_each(|(i, x)| println!("{:4}: {:+.3?}", i, x));

                println!("BarycentricForce");
                (*a_logging.lock().await)
                    .chunks()
                    .enumerate()
                    .skip(n_step / ACTUATOR_RATE - 20)
                    .for_each(|(i, x)| println!("{:4}: {:+.3?}", i, x));
        */
        println!("Plant HardpointsMotion & M1 S1 RBM");
        (*plant_logging.lock().await)
            .chunks()
            .enumerate()
            .skip(n_step - 20)
            .map(|(i, x)| (i, x.iter().map(|x| x * 1e6).collect::<Vec<f64>>()))
            .for_each(|(i, x)| println!("{:4}: {:+.3?}", i, x));

        let rbm_err = ((*plant_logging.lock().await)
            .chunks()
            .last()
            .unwrap()
            .iter()
            .enumerate()
            .map(|(i, x)| x * 1e6 - rbm_fun(i))
            .map(|x| x * x)
            .sum::<f64>()
            / 6f64)
            .sqrt();

        assert!(dbg!(rbm_err) < 5e-2);
    };
}

#[tokio::test]
async fn segment() -> anyhow::Result<()> {
    {
        const S1: u8 = 1;
        segment_model!(S1);
    }
    {
        const S2: u8 = 2;
        segment_model!(S2);
    }
    {
        const S3: u8 = 3;
        segment_model!(S3);
    }
    {
        const S4: u8 = 4;
        segment_model!(S4);
    }
    {
        const S5: u8 = 5;
        segment_model!(S5);
    }
    {
        const S6: u8 = 6;
        segment_model!(S6);
    }
    {
        const S7: u8 = 7;
        segment_model!(S7);
    }

    Ok(())
}
