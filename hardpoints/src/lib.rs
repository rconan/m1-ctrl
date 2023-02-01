//! # M1 hardpoints controller
//!
//! The control system implements the transfer function that models
//! the hardpoints dynamic behavior.
//!
//! This is imported from a Simulink model converted into C code.

#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(improper_ctypes)]

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

/// Simulink controller wrapper
#[derive(Debug, Clone, Copy, Default)]
pub struct HardpointsDynamics {
    /// Inputs Simulink structure
    pub inputs: ExtU_HP_dyn_dTF_T,
    /// Outputs Simulink structure
    pub outputs: ExtY_HP_dyn_dTF_T,
    states: DW_HP_dyn_dTF_T,
}
impl Default for ExtU_HP_dyn_dTF_T {
    fn default() -> Self {
        ExtU_HP_dyn_dTF_T { In1: [0f64; 6] }
    }
}
impl Default for ExtY_HP_dyn_dTF_T {
    fn default() -> Self {
        ExtY_HP_dyn_dTF_T { Out1: [0f64; 6] }
    }
}
impl Default for DW_HP_dyn_dTF_T {
    fn default() -> Self {
        DW_HP_dyn_dTF_T {
            HP_dyn_dTF_states: [0f64; 24],
        }
    }
}
impl HardpointsDynamics {
    /// Creates a new controller
    pub fn new() -> Self {
        Default::default()
    }
    /// Steps the controller
    pub fn step(&mut self) {
        let mut data: RT_MODEL_HP_dyn_dTF_T = tag_RTM_HP_dyn_dTF_T {
            dwork: &mut self.states as *mut _,
        };
        unsafe {
            HP_dyn_dTF_step(
                &mut data as *mut _,
                &mut self.inputs as *mut _,
                &mut self.outputs as &mut _,
            )
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use matio_rs::MatFile;
    #[test]
    fn step() {
        let mat = MatFile::load("hp_dyn_step_test.mat").unwrap();
        let hp_dyn_step_t: Vec<f64> = mat.var("hp_dyn_step_t").unwrap();
        let hp_dyn_step_y: Vec<f64> = mat.var("hp_dyn_step_y").unwrap();

        let mut ctrl = HardpointsDynamics::new();
        ctrl.inputs.In1.iter_mut().for_each(|x| *x = 1f64);
        let mut y = vec![];
        for _ in &hp_dyn_step_t {
            ctrl.step();
            y.extend_from_slice(ctrl.outputs.Out1.as_slice());
        }

        // dbg!(&y[y.len() - 6..]);

        let y_err = (y
            .chunks(6)
            .take(6 * 5)
            .zip(&hp_dyn_step_y)
            .map(|(y, y0)| y.iter().map(|y| *y - *y0).map(|x| x * x).sum::<f64>())
            .sum::<f64>()
            / y.len() as f64)
            .sqrt();
        dbg!(y_err);
    }
}
