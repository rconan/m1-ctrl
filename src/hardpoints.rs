use dos_clients_io::gmt_m1::segment;
use gmt_dos_actors::{
    io::{Data, Read, Size, Write},
    Update,
};
use hardpoints_dynamics::HardpointsDynamics;
use std::sync::Arc;

mod loadcell;
pub use loadcell::LoadCell;

type M = nalgebra::Matrix6<f64>;
type V = nalgebra::Vector6<f64>;

pub struct Hardpoints {
    dynamics: HardpointsDynamics,
    rbm_2_hp: M,
    m1_hpk: f64,
}
impl Hardpoints {
    pub fn new(stiffness: f64, rbm_2_hp: M) -> Self {
        Self {
            dynamics: HardpointsDynamics::new(),
            rbm_2_hp,
            m1_hpk: stiffness,
        }
    }
}

impl<const ID: u8> Size<segment::RBM<ID>> for Hardpoints {
    fn len(&self) -> usize {
        6
    }
}

impl<const ID: u8> Size<segment::HardpointsForces<ID>> for Hardpoints {
    fn len(&self) -> usize {
        6
    }
}

impl<const ID: u8> Read<segment::RBM<ID>> for Hardpoints {
    fn read(&mut self, data: Arc<Data<segment::RBM<ID>>>) {
        let hp = self.rbm_2_hp * V::from_column_slice(&data);
        self.dynamics.inputs.In1 = hp
            .as_slice()
            .try_into()
            .expect("failed to import `RBM` in `HardpointsDynamics` input");
    }
}

impl Update for Hardpoints {
    fn update(&mut self) {
        self.dynamics.step();
    }
}

impl<const ID: u8> Write<segment::HardpointsForces<ID>> for Hardpoints {
    fn write(&mut self) -> Option<Arc<Data<segment::HardpointsForces<ID>>>> {
        let data: Vec<f64> = self
            .dynamics
            .outputs
            .Out1
            .iter()
            .map(|d| *d * self.m1_hpk)
            .collect();
        Some(Arc::new(Data::new(data)))
    }
}
