use dosio::{io::Tags, ios, DOSIOSError, Dos, IOTags, IO};
use simulink_binder::import;

import! {M1_HP_Dyn,
r##"	 
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
/*
 * File: M1_HP_Dyn.h
 *
 * Code generated for Simulink model 'M1_HP_Dyn'.
 *
 * Model version                  : 1.903
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Aug 24 15:16:11 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_M1_HP_Dyn_h_
#define RTW_HEADER_M1_HP_Dyn_h_
#include <string.h>
#include <stddef.h>
#ifndef M1_HP_Dyn_COMMON_INCLUDES_
# define M1_HP_Dyn_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* M1_HP_Dyn_COMMON_INCLUDES_ */

#include "M1_HP_Dyn_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T S1HP_dyn_dTF_states[24];      /* '<S1>/S1HP_dyn_dTF' */
  real_T S2HP_dyn_dTF_states[24];      /* '<S1>/S2HP_dyn_dTF' */
  real_T S3HP_dyn_dTF_states[24];      /* '<S1>/S3HP_dyn_dTF' */
  real_T S4HP_dyn_dTF_states[24];      /* '<S1>/S4HP_dyn_dTF' */
  real_T S5HP_dyn_dTF_states[24];      /* '<S1>/S5HP_dyn_dTF' */
  real_T S6HP_dyn_dTF_states[24];      /* '<S1>/S6HP_dyn_dTF' */
  real_T S7HP_dyn_dTF_states[24];      /* '<S1>/S7HP_dyn_dTF' */
} DW_M1_HP_Dyn_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: m1sys{1}.M1RBM2HP
   * Referenced by: '<S1>/CG2Hp6'
   */
  real_T CG2Hp6_Gain[36];

  /* Expression: m1sys{2}.M1RBM2HP
   * Referenced by: '<S1>/CG2Hp8'
   */
  real_T CG2Hp8_Gain[36];

  /* Expression: m1sys{3}.M1RBM2HP
   * Referenced by: '<S1>/CG2Hp1'
   */
  real_T CG2Hp1_Gain[36];

  /* Expression: m1sys{4}.M1RBM2HP
   * Referenced by: '<S1>/CG2Hp2'
   */
  real_T CG2Hp2_Gain[36];

  /* Expression: m1sys{5}.M1RBM2HP
   * Referenced by: '<S1>/CG2Hp3'
   */
  real_T CG2Hp3_Gain[36];

  /* Expression: m1sys{6}.M1RBM2HP
   * Referenced by: '<S1>/CG2Hp4'
   */
  real_T CG2Hp4_Gain[36];

  /* Expression: m1sys{7}.M1RBM2HP
   * Referenced by: '<S1>/CG2Hp5'
   */
  real_T CG2Hp5_Gain[36];
} ConstP_M1_HP_Dyn_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T M1_RBM_cmd[42];               /* '<Root>/M1_RBM_cmd' */
} ExtU_M1_HP_Dyn_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T HP_F_cmd[42];                 /* '<Root>/HP_F_cmd' */
} ExtY_M1_HP_Dyn_T;

/* Real-time Model Data Structure */
struct tag_RTM_M1_HP_Dyn_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_M1_HP_Dyn_T M1_HP_Dyn_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_M1_HP_Dyn_T M1_HP_Dyn_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_M1_HP_Dyn_T M1_HP_Dyn_Y;

/* Constant parameters (default storage) */
extern const ConstP_M1_HP_Dyn_T M1_HP_Dyn_ConstP;

/* Model entry point functions */
extern void M1_HP_Dyn_initialize(void);
extern void M1_HP_Dyn_step(void);
extern void M1_HP_Dyn_terminate(void);

/* Real-time Model object */
extern RT_MODEL_M1_HP_Dyn_T *const M1_HP_Dyn_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('ims_Build5pt1e/M1_HP_Dyn')    - opens subsystem ims_Build5pt1e/M1_HP_Dyn
 * hilite_system('ims_Build5pt1e/M1_HP_Dyn/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ims_Build5pt1e'
 * '<S1>'   : 'ims_Build5pt1e/M1_HP_Dyn'
 */
#endif                                 /* RTW_HEADER_M1_HP_Dyn_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
"##}

impl<'a> IOTags for Controller<'a> {
    fn outputs_tags(&self) -> Vec<Tags> {
        vec![ios!(OSSHarpointDeltaF)]
    }
    fn inputs_tags(&self) -> Vec<Tags> {
        vec![ios!(M1RBMcmd)]
    }
}
impl<'a> Dos for Controller<'a> {
    type Input = Vec<f64>;
    type Output = Vec<f64>;
    fn inputs(&mut self, data: Option<Vec<IO<Self::Input>>>) -> Result<&mut Self, DOSIOSError> {
        match data {
            Some(data) => {
                if data.into_iter().fold(2, |mut a, io| {
                    match io {
                        IO::M1RBMcmd { data: Some(values) } => {
                            for (k, v) in values.into_iter().enumerate() {
                                self.m1_rbm_cmd[k] = v;
                            }
                            a -= 1;
                        }
                        _ => (),
                    }
                    if a == 0 {
                        return a;
                    }
                    a
                }) == 0
                {
                    Ok(self)
                } else {
                    Err(DOSIOSError::Inputs(
                        "Either HP load cell controller OSSHardpointD or M1HPCmd not found".into(),
                    ))
                }
            }
            None => Err(DOSIOSError::Inputs(
                "None data passed to HP load cell controller".into(),
            )),
        }
    }
    fn outputs(&mut self) -> Option<Vec<IO<Self::Output>>> {
        Some(vec![ios!(OSSHarpointDeltaF(Vec::<f64>::from(
            &self.hp_f_cmd
        )))])
    }
}
