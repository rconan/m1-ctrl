use std::sync::Arc;

use dos_actors::{
    io::{Data, Read, Write},
    UniqueIdentifier, Update, UID,
};

#[derive(Debug, Clone)]
pub struct HpLoadCell {
    hp_f_cmd: Arc<Data<HpFCmd>>,
    hp_d_cell: Arc<Data<HpDCell>>,
    hp_d_face: Arc<Data<HpDFace>>,
    hp_f_meas: Arc<Data<HpFMeas>>,
    m1_hpk: f64,
}
impl HpLoadCell {
    pub fn new(m1_hpk: f64) -> Self {
        Self {
            m1_hpk,
            hp_f_cmd: Arc::new(Data::new(vec![])),
            hp_d_cell: Arc::new(Data::new(vec![])),
            hp_d_face: Arc::new(Data::new(vec![])),
            hp_f_meas: Arc::new(Data::new(vec![])),
        }
    }
}

impl Update for HpLoadCell {
    fn update(&mut self) {
        self.hp_f_meas = Arc::new(Data::new(
            self.hp_d_cell
                .iter()
                .zip(self.hp_d_face.iter())
                .map(|(hp_d_cell, hp_d_face)| hp_d_face - hp_d_cell)
                .map(|hp_relative_displacements| hp_relative_displacements * self.m1_hpk)
                .zip(self.hp_f_cmd.iter())
                .map(|(hp_relative_force, hp_f_cmd)| hp_relative_force - hp_f_cmd)
                .collect(),
        ));
    }
}

#[derive(UID)]
pub enum HpFCmd {}

#[derive(UID)]
pub enum HpDCell {}

#[derive(UID)]
pub enum HpDFace {}

#[derive(UID)]
pub enum HpFMeas {}

impl Read<HpFCmd> for HpLoadCell {
    fn read(&mut self, data: std::sync::Arc<dos_actors::io::Data<HpFCmd>>) {
        self.hp_f_cmd = data.clone();
    }
}
impl Read<HpDCell> for HpLoadCell {
    fn read(&mut self, data: std::sync::Arc<dos_actors::io::Data<HpDCell>>) {
        self.hp_d_cell = data.clone();
    }
}
impl Read<HpDFace> for HpLoadCell {
    fn read(&mut self, data: std::sync::Arc<dos_actors::io::Data<HpDFace>>) {
        self.hp_d_face = data.clone();
    }
}
impl Write<HpFMeas> for HpLoadCell {
    fn write(&mut self) -> Option<Arc<Data<HpFMeas>>> {
        Some(self.hp_f_meas.clone())
    }
}
