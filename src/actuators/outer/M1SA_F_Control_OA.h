/*
 * File: M1SA_F_Control_OA.h
 *
 * Code generated for Simulink model 'M1SA_F_Control_OA'.
 *
 * Model version                  : 1.964
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Feb 14 14:42:59 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_M1SA_F_Control_OA_h_
#define RTW_HEADER_M1SA_F_Control_OA_h_
#include <string.h>
#include <stddef.h>
#ifndef M1SA_F_Control_OA_COMMON_INCLUDES_
# define M1SA_F_Control_OA_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* M1SA_F_Control_OA_COMMON_INCLUDES_ */

#include "M1SA_F_Control_OA_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Fxcontroller_DSTATE[3];       /* '<S3>/Fx controller' */
  real_T Fycontroller_DSTATE[3];       /* '<S3>/Fy controller' */
  real_T Fzcontroller_DSTATE[3];       /* '<S3>/Fz controller' */
  real_T Mxcontroller_DSTATE[3];       /* '<S3>/Mx controller' */
  real_T Mycontroller_DSTATE[3];       /* '<S3>/My controller' */
  real_T Mzcontroller_DSTATE[3];       /* '<S3>/Mz controller' */
  real_T OAseg_SA_dyn_states[335];     /* '<S1>/OAseg_SA_dyn' */
} DW_M1SA_F_Control_OA_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: m1sys{1}.Kbal
   * Referenced by: '<S1>/OAseg_Kbal'
   */
  real_T OAseg_Kbal_Gain[2010];
} ConstP_M1SA_F_Control_OA_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T HP_LC[6];                     /* '<Root>/HP_LC' */
  real_T SA_offsetF_cmd[335];          /* '<Root>/SA_offsetF_cmd' */
} ExtU_M1SA_F_Control_OA_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Res_Act_F[335];               /* '<Root>/Res_Act_F' */
} ExtY_M1SA_F_Control_OA_T;

/* Real-time Model Data Structure */
struct tag_RTM_M1SA_F_Control_OA_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_M1SA_F_Control_OA_T M1SA_F_Control_OA_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_M1SA_F_Control_OA_T M1SA_F_Control_OA_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_M1SA_F_Control_OA_T M1SA_F_Control_OA_Y;

/* Constant parameters (default storage) */
extern const ConstP_M1SA_F_Control_OA_T M1SA_F_Control_OA_ConstP;

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real_T OAseg_LC2CG[36];         /* Variable: OAseg_LC2CG
                                        * Referenced by: '<S1>/OAseg_LC2CG'
                                        */
extern real_T OAseg_SA_dynDen[2];      /* Variable: OAseg_SA_dynDen
                                        * Referenced by: '<S1>/OAseg_SA_dyn'
                                        */
extern real_T OAseg_SA_dynNum[2];      /* Variable: OAseg_SA_dynNum
                                        * Referenced by: '<S1>/OAseg_SA_dyn'
                                        */

/* Model entry point functions */
extern void M1SA_F_Control_OA_initialize(void);
extern void M1SA_F_Control_OA_step(void);
extern void M1SA_F_Control_OA_terminate(void);

/* Real-time Model object */
extern RT_MODEL_M1SA_F_Control_OA_T *const M1SA_F_Control_OA_M;

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
 * hilite_system('M1DCS/M1SA_F_Control_OA')    - opens subsystem M1DCS/M1SA_F_Control_OA
 * hilite_system('M1DCS/M1SA_F_Control_OA/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'M1DCS'
 * '<S1>'   : 'M1DCS/M1SA_F_Control_OA'
 * '<S2>'   : 'M1DCS/M1SA_F_Control_OA/OAseg_ofl_SSdtC'
 * '<S3>'   : 'M1DCS/M1SA_F_Control_OA/OAseg_ofl_SSdtC_'
 */
#endif                                 /* RTW_HEADER_M1SA_F_Control_OA_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
