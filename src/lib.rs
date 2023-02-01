//! # M1 control system

pub use actuators::Actuators;
use gmt_dos_actors::prelude::Signals;
pub use hardpoints::{Hardpoints, LoadCells};

mod hardpoints;
#[cfg(feature = "full")]
mod model;

type M = nalgebra::Matrix6<f64>;

/// Buider for M1 segment control system
/// 
/// The control system is made of the [Actuators], [Hardpoints] and [LoadCells] controllers.
#[derive(Debug, Default, Clone)]
pub struct SegmentBuilder {
    rbm_inputs: Option<Signals>,
    actuators_inputs: Option<Signals>,
    stiffness: Option<f64>,
    rbm_2_hp: Option<Vec<M>>,
    lc_2_cg: Option<Vec<M>>,
}
