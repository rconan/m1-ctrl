use simulink_binder::import;

import! {M1SA_F_Control_S7,
r##"
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
/*
 * File: M1SA_F_Control_S7.h
 *
 * Code generated for Simulink model 'M1SA_F_Control_S7'.
 *
 * Model version                  : 1.766
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Sep 20 17:25:16 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_M1SA_F_Control_S7_h_
#define RTW_HEADER_M1SA_F_Control_S7_h_
#include <string.h>
#include <stddef.h>
#ifndef M1SA_F_Control_S7_COMMON_INCLUDES_
# define M1SA_F_Control_S7_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* M1SA_F_Control_S7_COMMON_INCLUDES_ */

#include "M1SA_F_Control_S7_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Fxcontroller_DSTATE[3];       /* '<S2>/Fx controller' */
  real_T Fycontroller_DSTATE[3];       /* '<S2>/Fy controller' */
  real_T Fzcontroller_DSTATE[3];       /* '<S2>/Fz controller' */
  real_T Mxcontroller_DSTATE[3];       /* '<S2>/Mx controller' */
  real_T Mycontroller_DSTATE[3];       /* '<S2>/My controller' */
  real_T Mzcontroller_DSTATE[3];       /* '<S2>/Mz controller' */
  real_T SADynamicsS7_states[306];     /* '<S1>/SA Dynamics - S7' */
} DW_M1SA_F_Control_S7_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: m1sys{7}.LC2CG
   * Referenced by: '<S1>/LC2CG'
   */
  real_T LC2CG_Gain[36];

  /* Expression: m1sys{7}.Kbal
   * Referenced by: '<S1>/Force balance S7'
   */
  real_T ForcebalanceS7_Gain[1836];
} ConstP_M1SA_F_Control_S7_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T HP_LC[6];                     /* '<Root>/HP_LC' */
  real_T SA_offsetF_cmd[306];          /* '<Root>/SA_offsetF_cmd' */
} ExtU_M1SA_F_Control_S7_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T M1_ACT_F[306];                /* '<Root>/M1_ACT_F' */
} ExtY_M1SA_F_Control_S7_T;

/* Real-time Model Data Structure */
struct tag_RTM_M1SA_F_Control_S7_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_M1SA_F_Control_S7_T M1SA_F_Control_S7_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_M1SA_F_Control_S7_T M1SA_F_Control_S7_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_M1SA_F_Control_S7_T M1SA_F_Control_S7_Y;

/* Constant parameters (default storage) */
extern const ConstP_M1SA_F_Control_S7_T M1SA_F_Control_S7_ConstP;

/* Model entry point functions */
extern void M1SA_F_Control_S7_initialize(void);
extern void M1SA_F_Control_S7_step(void);
extern void M1SA_F_Control_S7_terminate(void);

/* Real-time Model object */
extern RT_MODEL_M1SA_F_Control_S7_T *const M1SA_F_Control_S7_M;

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
 * hilite_system('M1DCS/M1SA_F_Control_S7')    - opens subsystem M1DCS/M1SA_F_Control_S7
 * hilite_system('M1DCS/M1SA_F_Control_S7/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'M1DCS'
 * '<S1>'   : 'M1DCS/M1SA_F_Control_S7'
 * '<S2>'   : 'M1DCS/M1SA_F_Control_S7/M1S7 OFL DT_SS_C'
 */
#endif                                 /* RTW_HEADER_M1SA_F_Control_S7_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
"##}
