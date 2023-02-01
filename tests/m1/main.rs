use dos_clients_io::gmt_m1::M1RigidBodyMotions;
use gmt_dos_actors::prelude::*;
use gmt_fem::{
    dos::{DiscreteModalSolver, ExponentialMatrix},
    fem_io::{M1ActuatorsSegment1, OSSHardpointD, OSSHarpointDeltaF, OSSM1Lcl},
    FEM,
};
use gmt_m1_ctrl::SegmentBuilder;
use std::env;

const ACTUATOR_RATE: usize = 100;

#[tokio::test]
async fn segment() -> anyhow::Result<()> {
    let sim_sampling_frequency = 1000;
    let sim_duration = 10_usize; // second
    let n_step = sim_sampling_frequency * sim_duration;

    let whole_fem = FEM::from_env()?;

    let rbm_fun =
        |i: usize, sid: u8| (-1f64).powi(i as i32) * (1 + (i % 3)) as f64 + sid as f64 / 10_f64;
    let rbm_signal = |sid: u8| -> Signals {
        (0..6).fold(Signals::new(6, n_step), |signals, i| {
            signals.channel(
                i,
                Signal::Sigmoid {
                    amplitude: rbm_fun(i, sid) * 1e-6,
                    sampling_frequency_hz: sim_sampling_frequency as f64,
                },
            )
        })
    };

    let segment = SegmentBuilder::new().fem_calibration(&whole_fem);

    let fem_dss = DiscreteModalSolver::<ExponentialMatrix>::from_fem(whole_fem)
        .sampling(sim_sampling_frequency as f64)
        .proportional_damping(2. / 100.)
        .ins::<OSSHarpointDeltaF>()
        .ins::<M1ActuatorsSegment1>()
        .outs::<OSSHardpointD>()
        .outs::<OSSM1Lcl>()
        .use_static_gain_compensation()
        .build()?;
    let mut plant: Actor<_> = (
        fem_dss,
        format!(
            "GMT
    Finite Element Model
    {}",
            env::var("FEM_REPO").unwrap()
        ),
    )
        .into();

    let m1 = (segment
        .clone()
        .rigid_body_motions_inputs(rbm_signal(1))
        .build::<1, ACTUATOR_RATE>(&mut plant)
        .name("m1-segment_model")
        .flowchart()
        + segment
            .clone()
            .rigid_body_motions_inputs(rbm_signal(2))
            .build::<2, ACTUATOR_RATE>(&mut plant)
        + segment
            .clone()
            .rigid_body_motions_inputs(rbm_signal(3))
            .build::<3, ACTUATOR_RATE>(&mut plant)
        + segment
            .clone()
            .rigid_body_motions_inputs(rbm_signal(4))
            .build::<4, ACTUATOR_RATE>(&mut plant)
        + segment
            .clone()
            .rigid_body_motions_inputs(rbm_signal(5))
            .build::<5, ACTUATOR_RATE>(&mut plant)
        + segment
            .clone()
            .rigid_body_motions_inputs(rbm_signal(6))
            .build::<6, ACTUATOR_RATE>(&mut plant)
        + segment
            .clone()
            .rigid_body_motions_inputs(rbm_signal(7))
            .build::<7, ACTUATOR_RATE>(&mut plant))
    .name("m1-model")
    .flowchart();

    let plant_logging = Logging::<f64>::new(1).into_arcx();
    let mut plant_logger: Terminator<_> = Actor::new(plant_logging.clone());

    plant
        .add_output()
        .bootstrap()
        .unbounded()
        .build::<M1RigidBodyMotions>()
        .into_input(&mut plant_logger);

    (model!(plant, plant_logger) + m1)
        .flowchart()
        .check()?
        .run()
        .await?;

    /*     println!("Plant HardpointsMotion & M1 S1 RBM");
    (*plant_logging.lock().await)
        .chunks()
        .enumerate()
        .skip(n_step - 20)
        .map(|(i, x)| (i, x.iter().map(|x| x * 1e6).collect::<Vec<f64>>()))
        .for_each(|(i, x)| println!("{:6}: {:+.1?}", i, x)); */

    let rbm_err = (*plant_logging.lock().await)
        .chunks()
        .last()
        .unwrap()
        .chunks(6)
        .map(|x| x.iter().map(|x| x * 1e6).collect::<Vec<_>>())
        .enumerate()
        .inspect(|(i, x)| println!("{:2}: {:+.3?}", i, x))
        .map(|(i, x)| {
            x.iter()
                .enumerate()
                .map(|(j, x)| x - rbm_fun(j, i as u8 + 1))
                .map(|x| x * x)
                .sum::<f64>()
                / 6f64
        })
        .map(|x| x.sqrt())
        .sum::<f64>()
        / 7f64;

    assert!(dbg!(rbm_err) < 5e-2);

    Ok(())
}
