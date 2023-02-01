//! # M1 outer segment actuators controller
//!
//! The control system converts forces and moments at the segment
//! center of gravity into actuators forces in addition to any
//! offset actuators forces
//!
//! This is imported from a Simulink model converted into C code.

#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(improper_ctypes)]

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

#[derive(Debug, Clone, Copy, Default)]
pub struct OuterActuatorsController {
    /// Inputs Simulink structure
    pub inputs: ExtU_M1SA_Control_OA_T,
    /// Outputs Simulink structure
    pub outputs: ExtY_M1SA_Control_OA_T,
    states: DW_M1SA_Control_OA_T,
}
impl Default for ExtU_M1SA_Control_OA_T {
    fn default() -> Self {
        ExtU_M1SA_Control_OA_T {
            LC_FxyzMxyz_CG: [0f64; 6],
            SA_offsetF_cmd: [0f64; 335],
        }
    }
}
impl Default for ExtY_M1SA_Control_OA_T {
    fn default() -> Self {
        ExtY_M1SA_Control_OA_T {
            Res_Act_F: [0f64; 335],
        }
    }
}
impl Default for DW_M1SA_Control_OA_T {
    fn default() -> Self {
        DW_M1SA_Control_OA_T {
            Fxcontroller_DSTATE: [0f64; 3],
            Fycontroller_DSTATE: [0f64; 3],
            Fzcontroller_DSTATE: [0f64; 3],
            Mxcontroller_DSTATE: [0f64; 3],
            Mycontroller_DSTATE: [0f64; 3],
            Mzcontroller_DSTATE: [0f64; 3],
            OA_SA_dyn_states: [0f64; 335],
        }
    }
}
impl OuterActuatorsController {
    /// Creates a new controller
    pub fn new() -> Self {
        Default::default()
    }
    /// Steps the controller
    pub fn step(&mut self) {
        let mut data: RT_MODEL_M1SA_Control_OA_T = tag_RTM_M1SA_Control_OA_T {
            dwork: &mut self.states as *mut _,
        };
        unsafe {
            M1SA_Control_OA_step(
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
    #[test]
    fn zero() {
        let mut ctrl = OuterActuatorsController::new();
        ctrl.inputs.LC_FxyzMxyz_CG[0] = 1f64;
        ctrl.step();
        dbg!(&ctrl.states);
    }
}
