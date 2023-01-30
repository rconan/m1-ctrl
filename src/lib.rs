mod hardpoints;

pub use actuators::Actuators;
use dos_clients_io::gmt_m1::segment;
use gmt_dos_actors::{io::Read, Actor, AddOuput, IntoInputs, Task, Update};
pub use hardpoints::{Hardpoints, LoadCell};

type M = nalgebra::Matrix6<f64>;

pub struct Segment<const ID: u8, const NA: usize, const NI: usize = 1, const NO: usize = 1> {
    pub hardpoints: Actor<Hardpoints, NI, NO>,
    pub loadcell: Actor<LoadCell, NO, NA>,
    pub actuators: Actor<Actuators<ID>, NA, NO>,
}
impl<const ID: u8, const NA: usize, const NI: usize, const NO: usize> Segment<ID, NA, NI, NO> {
    pub fn new<C, const N: usize>(
        stiffness: f64,
        rbm_2_hp: M,
        lc_2_cg: M,
        actor: &mut Actor<C, NO, N>,
    ) -> Self
    where
        C: Update + Send + Read<segment::HardpointsForces<ID>> + 'static,
    {
        let mut hardpoints: Actor<_, NI, NO> = (
            Hardpoints::new(stiffness, rbm_2_hp),
            format!("M1S{} Hardpoints", ID),
        )
            .into();
        let mut loadcell: Actor<_, NO, NA> = (
            LoadCell::new(stiffness, lc_2_cg),
            format!("M1S{} Loadcell", ID),
        )
            .into();
        let mut actuators: Actor<_, NA, NO> =
            (Actuators::new(), format!("M1S{} Actuators", ID)).into();
        hardpoints
            .add_output()
            .multiplex(2)
            .build::<segment::HardpointsForces<ID>>()
            .into_input(&mut loadcell)
            .into_input(actor);
        loadcell
            .add_output()
            .build::<segment::BarycentricForce>()
            .into_input(&mut actuators);
        Self {
            hardpoints,
            loadcell,
            actuators,
        }
    }
}

impl<const ID: u8, const NA: usize, const NI: usize, const NO: usize> IntoIterator
    for Segment<ID, NA, NI, NO>
{
    type Item = Box<dyn Task>;
    type IntoIter = std::vec::IntoIter<Self::Item>;

    fn into_iter(self) -> Self::IntoIter {
        let actors: Vec<Box<dyn Task>> = vec![
            Box::new(self.hardpoints),
            Box::new(self.loadcell),
            Box::new(self.actuators),
        ];
        actors.into_iter()
    }
}

pub const SEGMENT_ID: [u8; 7] = [1, 2, 3, 4, 5, 6, 7];

pub struct M1<const NA: usize, const NI: usize, const NO: usize>(
    Option<Segment<1, NA, NI, NO>>,
    Option<Segment<2, NA, NI, NO>>,
    Option<Segment<3, NA, NI, NO>>,
    Option<Segment<4, NA, NI, NO>>,
    Option<Segment<5, NA, NI, NO>>,
    Option<Segment<6, NA, NI, NO>>,
    Option<Segment<7, NA, NI, NO>>,
);
