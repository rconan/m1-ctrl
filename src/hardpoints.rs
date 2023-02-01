use dos_clients_io::gmt_m1::segment::{HardpointsForces, RBM};
use gmt_dos_actors::{
    io::{Data, Read, Size, Write},
    Update,
};
use hardpoints_dynamics::HardpointsDynamics;
use std::sync::Arc;

mod loadcell;
pub use loadcell::LoadCells;

type M = nalgebra::Matrix6<f64>;
type V = nalgebra::Vector6<f64>;

/// [gmt_dos_actors](https://docs.rs/gmt_dos-actors) client interface for [HardpointsDynamics]
pub struct Hardpoints {
    dynamics: HardpointsDynamics,
    rbm_2_hp: M,
    m1_hpk: f64,
}
impl Hardpoints {
    /// Creates a new hardpoints client
    /// 
    /// The hardpoints stiffness and the matrix transformation
    /// from rigid body motion to hardpoint motion are provided.
    pub fn new(stiffness: f64, rbm_2_hp: M) -> Self {
        Self {
            dynamics: HardpointsDynamics::new(),
            rbm_2_hp,
            m1_hpk: stiffness,
        }
    }
}

impl<const ID: u8> Size<RBM<ID>> for Hardpoints {
    fn len(&self) -> usize {
        6
    }
}

impl<const ID: u8> Size<HardpointsForces<ID>> for Hardpoints {
    fn len(&self) -> usize {
        6
    }
}

impl<const ID: u8> Read<RBM<ID>> for Hardpoints {
    fn read(&mut self, data: Arc<Data<RBM<ID>>>) {
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

impl<const ID: u8> Write<HardpointsForces<ID>> for Hardpoints {
    fn write(&mut self) -> Option<Arc<Data<HardpointsForces<ID>>>> {
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
