use simulink_binder::import;

import! {M1SA_F_Control_S4,
r##"
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
/*
 * File: M1SA_F_Control_S4.h
 *
 * Code generated for Simulink model 'M1SA_F_Control_S4'.
 *
 * Model version                  : 1.762
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jul 23 14:05:18 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_M1SA_F_Control_S4_h_
#define RTW_HEADER_M1SA_F_Control_S4_h_
#include <string.h>
#include <stddef.h>
#ifndef M1SA_F_Control_S4_COMMON_INCLUDES_
# define M1SA_F_Control_S4_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* M1SA_F_Control_S4_COMMON_INCLUDES_ */

#include "M1SA_F_Control_S4_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T SADynamics_states[54];        /* '<S1>/SA Dynamics' */
  real_T Fxcontroller_DSTATE[3];       /* '<S2>/Fx controller' */
  real_T Fycontroller_DSTATE[3];       /* '<S2>/Fy controller' */
  real_T Fzcontroller_DSTATE[3];       /* '<S2>/Fz controller' */
  real_T Mxcontroller_DSTATE[5];       /* '<S2>/Mx controller' */
  real_T Mycontroller_DSTATE[5];       /* '<S2>/My controller' */
  real_T Mzcontroller_DSTATE[3];       /* '<S2>/Mz controller' */
  real_T SADynamicsS1_states[12];      /* '<S1>/SA Dynamics - S1' */
} DW_M1SA_F_Control_S4_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: m1BM2F_OA
   * Referenced by: '<S1>/BM2Forces'
   */
  real_T BM2Forces_Gain[9045];

  /* Expression: m1sys{1}.LC2CG
   * Referenced by: '<S1>/LC2CG'
   */
  real_T LC2CG_Gain[36];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S2>/Mx controller'
   *   '<S2>/My controller'
   */
  real_T pooled8[21];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S2>/Mx controller'
   *   '<S2>/My controller'
   */
  real_T pooled10[5];

  /* Expression: OA_Kbal
   * Referenced by: '<S1>/Force balance S1'
   */
  real_T ForcebalanceS1_Gain[2010];
} ConstP_M1SA_F_Control_S4_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T HP_LC[6];                     /* '<Root>/HP_LC' */
  real_T BM_cmd[27];                   /* '<Root>/BM_cmd' */
} ExtU_M1SA_F_Control_S4_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T M1_ACT_F[335];                /* '<Root>/M1_ACT_F' */
} ExtY_M1SA_F_Control_S4_T;

/* Real-time Model Data Structure */
struct tag_RTM_M1SA_F_Control_S4_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_M1SA_F_Control_S4_T M1SA_F_Control_S4_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_M1SA_F_Control_S4_T M1SA_F_Control_S4_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_M1SA_F_Control_S4_T M1SA_F_Control_S4_Y;

/* Constant parameters (default storage) */
extern const ConstP_M1SA_F_Control_S4_T M1SA_F_Control_S4_ConstP;

/* Model entry point functions */
extern void M1SA_F_Control_S4_initialize(void);
extern void M1SA_F_Control_S4_step(void);
extern void M1SA_F_Control_S4_terminate(void);

/* Real-time Model object */
extern RT_MODEL_M1SA_F_Control_S4_T *const M1SA_F_Control_S4_M;

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
 * hilite_system('M1DCS/M1SA_F_Control_S4')    - opens subsystem M1DCS/M1SA_F_Control_S4
 * hilite_system('M1DCS/M1SA_F_Control_S4/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'M1DCS'
 * '<S1>'   : 'M1DCS/M1SA_F_Control_S4'
 * '<S2>'   : 'M1DCS/M1SA_F_Control_S4/M1S1-6 OFL DT_SS_C'
 */
#endif                                 /* RTW_HEADER_M1SA_F_Control_S4_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
"##}