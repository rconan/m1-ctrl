#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(improper_ctypes)]

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

#[derive(Debug, Clone, Copy, Default)]
pub struct CenterActuatorsController {
    pub inputs: ExtU_M1SA_Control_CS_T,
    pub outputs: ExtY_M1SA_Control_CS_T,
    states: DW_M1SA_Control_CS_T,
}
impl Default for ExtU_M1SA_Control_CS_T {
    fn default() -> Self {
        ExtU_M1SA_Control_CS_T {
            LC_FxyzMxyz_CG: [0f64; 6],
            SA_offsetF_cmd: [0f64; 306],
        }
    }
}
impl Default for ExtY_M1SA_Control_CS_T {
    fn default() -> Self {
        ExtY_M1SA_Control_CS_T {
            Res_Act_F: [0f64; 306],
        }
    }
}
impl Default for DW_M1SA_Control_CS_T {
    fn default() -> Self {
        DW_M1SA_Control_CS_T {
            Fxcontroller_DSTATE: [0f64; 3],
            Fycontroller_DSTATE: [0f64; 3],
            Fzcontroller_DSTATE: [0f64; 3],
            Mxcontroller_DSTATE: [0f64; 3],
            Mycontroller_DSTATE: [0f64; 3],
            Mzcontroller_DSTATE: [0f64; 3],
            CS_SA_dyn_states: [0f64; 306],
        }
    }
}
impl CenterActuatorsController {
    pub fn new() -> Self {
        Default::default()
    }
    pub fn step(&mut self) {
        let mut data: RT_MODEL_M1SA_Control_CS_T = tag_RTM_M1SA_Control_CS_T {
            dwork: &mut self.states as *mut _,
        };
        unsafe {
            M1SA_Control_CS_step(
                &mut data as *mut _,
                &mut self.inputs as *mut _,
                &mut self.outputs as &mut _,
            )
        }
    }
}
