use simulink_binder::import;

import! {M1OFL_Control,
r##"	 
/*
 * File: M1OFL_Control.h
 *
 * Code generated for Simulink model 'M1OFL_Control'.
 *
 * Model version                  : 1.758
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Mar  2 10:27:22 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_M1OFL_Control_h_
#define RTW_HEADER_M1OFL_Control_h_
#include <string.h>
#include <stddef.h>
#ifndef M1OFL_Control_COMMON_INCLUDES_
# define M1OFL_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* M1OFL_Control_COMMON_INCLUDES_ */

#include "M1OFL_Control_types.h"

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
  real_T Mxcontroller_DSTATE[5];       /* '<S2>/Mx controller' */
  real_T Mycontroller_DSTATE[5];       /* '<S2>/My controller' */
  real_T Mzcontroller_DSTATE[3];       /* '<S2>/Mz controller' */
  real_T SADynamicsS1_states[12];      /* '<S1>/SA Dynamics - S1' */
  real_T Fxcontroller_DSTATE_h[3];     /* '<S3>/Fx controller' */
  real_T Fycontroller_DSTATE_a[3];     /* '<S3>/Fy controller' */
  real_T Fzcontroller_DSTATE_l[3];     /* '<S3>/Fz controller' */
  real_T Mxcontroller_DSTATE_o[5];     /* '<S3>/Mx controller' */
  real_T Mycontroller_DSTATE_p[5];     /* '<S3>/My controller' */
  real_T Mzcontroller_DSTATE_k[3];     /* '<S3>/Mz controller' */
  real_T SADynamicsS2_states[12];      /* '<S1>/SA Dynamics - S2' */
  real_T Fxcontroller_DSTATE_o[3];     /* '<S4>/Fx controller' */
  real_T Fycontroller_DSTATE_h[3];     /* '<S4>/Fy controller' */
  real_T Fzcontroller_DSTATE_n[3];     /* '<S4>/Fz controller' */
  real_T Mxcontroller_DSTATE_l[5];     /* '<S4>/Mx controller' */
  real_T Mycontroller_DSTATE_d[5];     /* '<S4>/My controller' */
  real_T Mzcontroller_DSTATE_a[3];     /* '<S4>/Mz controller' */
  real_T SADynamicsS3_states[12];      /* '<S1>/SA Dynamics - S3' */
  real_T Fxcontroller_DSTATE_i[3];     /* '<S5>/Fx controller' */
  real_T Fycontroller_DSTATE_n[3];     /* '<S5>/Fy controller' */
  real_T Fzcontroller_DSTATE_f[3];     /* '<S5>/Fz controller' */
  real_T Mxcontroller_DSTATE_k[5];     /* '<S5>/Mx controller' */
  real_T Mycontroller_DSTATE_pv[5];    /* '<S5>/My controller' */
  real_T Mzcontroller_DSTATE_ka[3];    /* '<S5>/Mz controller' */
  real_T SADynamicsS4_states[12];      /* '<S1>/SA Dynamics - S4' */
  real_T Fxcontroller_DSTATE_j[3];     /* '<S6>/Fx controller' */
  real_T Fycontroller_DSTATE_k[3];     /* '<S6>/Fy controller' */
  real_T Fzcontroller_DSTATE_f2[3];    /* '<S6>/Fz controller' */
  real_T Mxcontroller_DSTATE_d[5];     /* '<S6>/Mx controller' */
  real_T Mycontroller_DSTATE_f[5];     /* '<S6>/My controller' */
  real_T Mzcontroller_DSTATE_f[3];     /* '<S6>/Mz controller' */
  real_T SADynamicsS5_states[12];      /* '<S1>/SA Dynamics - S5' */
  real_T Fxcontroller_DSTATE_d[3];     /* '<S7>/Fx controller' */
  real_T Fycontroller_DSTATE_i[3];     /* '<S7>/Fy controller' */
  real_T Fzcontroller_DSTATE_b[3];     /* '<S7>/Fz controller' */
  real_T Mxcontroller_DSTATE_m[5];     /* '<S7>/Mx controller' */
  real_T Mycontroller_DSTATE_b[5];     /* '<S7>/My controller' */
  real_T Mzcontroller_DSTATE_kn[3];    /* '<S7>/Mz controller' */
  real_T SADynamicsS6_states[12];      /* '<S1>/SA Dynamics - S6' */
  real_T Fxcontroller_DSTATE_b[3];     /* '<S8>/Fx controller' */
  real_T Fycontroller_DSTATE_nj[3];    /* '<S8>/Fy controller' */
  real_T Fzcontroller_DSTATE_c[3];     /* '<S8>/Fz controller' */
  real_T Mxcontroller_DSTATE_i[5];     /* '<S8>/Mx controller' */
  real_T Mycontroller_DSTATE_o[5];     /* '<S8>/My controller' */
  real_T Mzcontroller_DSTATE_i[3];     /* '<S8>/Mz controller' */
  real_T SADynamicsS7_states[12];      /* '<S1>/SA Dynamics - S7' */
} DW_M1OFL_Control_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: m1sys{1}.LC2CG
   * Referenced by: '<S1>/LC2CG1'
   */
  real_T LC2CG1_Gain[36];

  /* Expression: m1sys{2}.LC2CG
   * Referenced by: '<S1>/LC2CG2'
   */
  real_T LC2CG2_Gain[36];

  /* Expression: m1sys{3}.LC2CG
   * Referenced by: '<S1>/LC2CG3'
   */
  real_T LC2CG3_Gain[36];

  /* Expression: m1sys{4}.LC2CG
   * Referenced by: '<S1>/LC2CG4'
   */
  real_T LC2CG4_Gain[36];

  /* Expression: m1sys{5}.LC2CG
   * Referenced by: '<S1>/LC2CG5'
   */
  real_T LC2CG5_Gain[36];

  /* Expression: m1sys{6}.LC2CG
   * Referenced by: '<S1>/LC2CG6'
   */
  real_T LC2CG6_Gain[36];

  /* Expression: m1sys{7}.LC2CG
   * Referenced by: '<S1>/LC2CG7'
   */
  real_T LC2CG7_Gain[36];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S2>/Mx controller'
   *   '<S2>/My controller'
   *   '<S3>/Mx controller'
   *   '<S3>/My controller'
   *   '<S4>/Mx controller'
   *   '<S4>/My controller'
   *   '<S5>/Mx controller'
   *   '<S5>/My controller'
   *   '<S6>/Mx controller'
   *   '<S6>/My controller'
   *   '<S7>/Mx controller'
   *   '<S7>/My controller'
   *   '<S8>/Mx controller'
   *   '<S8>/My controller'
   */
  real_T pooled10[21];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S2>/Mx controller'
   *   '<S2>/My controller'
   *   '<S3>/Mx controller'
   *   '<S3>/My controller'
   *   '<S4>/Mx controller'
   *   '<S4>/My controller'
   *   '<S5>/Mx controller'
   *   '<S5>/My controller'
   *   '<S6>/Mx controller'
   *   '<S6>/My controller'
   *   '<S7>/Mx controller'
   *   '<S7>/My controller'
   *   '<S8>/Mx controller'
   *   '<S8>/My controller'
   */
  real_T pooled12[5];
} ConstP_M1OFL_Control_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T HP_LC[42];                    /* '<Root>/HP_LC' */
} ExtU_M1OFL_Control_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T M1_Rel_F[42];                 /* '<Root>/M1_Rel_F' */
} ExtY_M1OFL_Control_T;

/* Real-time Model Data Structure */
struct tag_RTM_M1OFL_Control_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_M1OFL_Control_T M1OFL_Control_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_M1OFL_Control_T M1OFL_Control_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_M1OFL_Control_T M1OFL_Control_Y;

/* Constant parameters (default storage) */
extern const ConstP_M1OFL_Control_T M1OFL_Control_ConstP;

/* Model entry point functions */
extern void M1OFL_Control_initialize(void);
extern void M1OFL_Control_step(void);
extern void M1OFL_Control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_M1OFL_Control_T *const M1OFL_Control_M;

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
 * hilite_system('M1DCS/M1OFL_Control')    - opens subsystem M1DCS/M1OFL_Control
 * hilite_system('M1DCS/M1OFL_Control/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'M1DCS'
 * '<S1>'   : 'M1DCS/M1OFL_Control'
 * '<S2>'   : 'M1DCS/M1OFL_Control/M1S1 OFL DT_SS_C'
 * '<S3>'   : 'M1DCS/M1OFL_Control/M1S2 OFL DT_SS_C1'
 * '<S4>'   : 'M1DCS/M1OFL_Control/M1S3 OFL DT_SS_C'
 * '<S5>'   : 'M1DCS/M1OFL_Control/M1S4 OFL DT_SS_C'
 * '<S6>'   : 'M1DCS/M1OFL_Control/M1S5 OFL DT_SS_C'
 * '<S7>'   : 'M1DCS/M1OFL_Control/M1S6 OFL DT_SS_C'
 * '<S8>'   : 'M1DCS/M1OFL_Control/M1S7 OFL DT_SS_C'
 */
#endif                                 /* RTW_HEADER_M1OFL_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
"##}
