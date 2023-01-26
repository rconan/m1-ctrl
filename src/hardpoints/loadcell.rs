use dos_actors::{
    io::{Data, Read, Write},
    Update,
};
use dos_clients_io::gmt_m1::segment;
use std::sync::Arc;

type M = nalgebra::Matrix6<f64>;
type V = nalgebra::Vector6<f64>;

#[derive(Debug, Clone)]
pub struct LoadCell {
    pub(super) hp_f_cmd: Vec<f64>,
    pub(super) hp_d_cell: Vec<f64>,
    pub(super) hp_d_face: Vec<f64>,
    hp_f_meas: Vec<f64>,
    m1_hpk: f64,
    lc_2_cg: M,
}
impl LoadCell {
    pub fn new(m1_hpk: f64, lc_2_cg: M) -> Self {
        Self {
            m1_hpk,
            hp_f_cmd: vec![0f64; 6],
            hp_d_cell: vec![0f64; 6],
            hp_d_face: vec![0f64; 6],
            hp_f_meas: vec![0f64; 6],
            lc_2_cg,
        }
    }
}

impl Update for LoadCell {
    fn update(&mut self) {
        self.hp_d_cell
            .iter()
            .zip(self.hp_d_face.iter())
            .map(|(hp_d_cell, hp_d_face)| hp_d_face - hp_d_cell)
            .map(|hp_relative_displacements| hp_relative_displacements * self.m1_hpk)
            .zip(self.hp_f_cmd.iter())
            .map(|(hp_relative_force, hp_f_cmd)| hp_relative_force - hp_f_cmd)
            .zip(&mut self.hp_f_meas)
            .for_each(|(hp_f_diff_force, hp_f_meas)| *hp_f_meas = hp_f_diff_force);
    }
}

impl<const ID: u8> Read<segment::HardpointsForces<ID>> for LoadCell {
    fn read(&mut self, data: std::sync::Arc<dos_actors::io::Data<segment::HardpointsForces<ID>>>) {
        self.hp_f_cmd = (**data).to_vec();
    }
}

impl<const ID: u8> Read<segment::HardpointsMotion<ID>> for LoadCell {
    fn read(&mut self, data: Arc<Data<segment::HardpointsMotion<ID>>>) {
        let (cell, face) = (**data).as_slice().split_at(6);
        self.hp_d_cell
            .iter_mut()
            .zip(cell)
            .for_each(|(a, b)| *a = *b);
        self.hp_d_face
            .iter_mut()
            .zip(face)
            .for_each(|(a, b)| *a = *b);
    }
}

impl Write<segment::BarycentricForce> for LoadCell {
    fn write(&mut self) -> Option<Arc<Data<segment::BarycentricForce>>> {
        let cg = self.lc_2_cg * V::from_column_slice(self.hp_f_meas.as_slice());
        Some(Arc::new(Data::new(cg.as_slice().to_vec())))
    }
}
