mod hardpoints;

pub use actuators::Actuators;
use gmt_dos_actors::prelude::Signals;
pub use hardpoints::{Hardpoints, LoadCells};

#[cfg(feature = "full")]
mod model;

type M = nalgebra::Matrix6<f64>;

#[derive(Debug, Default, Clone)]
pub struct SegmentBuilder {
    rbm_inputs: Option<Signals>,
    actuators_inputs: Option<Signals>,
    stiffness: Option<f64>,
    rbm_2_hp: Option<Vec<M>>,
    lc_2_cg: Option<Vec<M>>,
}
