/*
 * File: M1SA_F_Control_CS.h
 *
 * Code generated for Simulink model 'M1SA_F_Control_CS'.
 *
 * Model version                  : 1.785
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Feb 10 11:20:29 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_M1SA_F_Control_CS_h_
#define RTW_HEADER_M1SA_F_Control_CS_h_
#include <string.h>
#include <stddef.h>
#ifndef M1SA_F_Control_CS_COMMON_INCLUDES_
# define M1SA_F_Control_CS_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* M1SA_F_Control_CS_COMMON_INCLUDES_ */

#include "M1SA_F_Control_CS_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: m1sys{7}.Kbal
   * Referenced by: '<S1>/CSseg_Kbal'
   */
  real_T CSseg_Kbal_Gain[1836];
} ConstP_M1SA_F_Control_CS_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T HP_LC[6];                     /* '<Root>/HP_LC' */
  real_T SA_offsetF_cmd[306];          /* '<Root>/SA_offsetF_cmd' */
} ExtU_M1SA_F_Control_CS_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Res_Act_F[306];               /* '<Root>/Res_Act_F' */
} ExtY_M1SA_F_Control_CS_T;

/* Real-time Model Data Structure */
struct tag_RTM_M1SA_F_Control_CS_T {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_M1SA_F_Control_CS_T M1SA_F_Control_CS_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_M1SA_F_Control_CS_T M1SA_F_Control_CS_Y;

/* Constant parameters (default storage) */
extern const ConstP_M1SA_F_Control_CS_T M1SA_F_Control_CS_ConstP;

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real_T CSseg_LC2CG[36];         /* Variable: CSseg_LC2CG
                                        * Referenced by: '<S1>/CSseg_LC2CG'
                                        */
extern real_T OAseg_SA_dynDen[2];      /* Variable: OAseg_SA_dynDen
                                        * Referenced by: '<S1>/CSseg_SA_dyn'
                                        */
extern real_T OAseg_SA_dynNum[2];      /* Variable: OAseg_SA_dynNum
                                        * Referenced by: '<S1>/CSseg_SA_dyn'
                                        */

/* Model entry point functions */
extern void M1SA_F_Control_CS_initialize(void);
extern void M1SA_F_Control_CS_step(void);
extern void M1SA_F_Control_CS_terminate(void);

/* Real-time Model object */
extern RT_MODEL_M1SA_F_Control_CS_T *const M1SA_F_Control_CS_M;

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
 * hilite_system('M1DCS/M1SA_F_Control_CS')    - opens subsystem M1DCS/M1SA_F_Control_CS
 * hilite_system('M1DCS/M1SA_F_Control_CS/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'M1DCS'
 * '<S1>'   : 'M1DCS/M1SA_F_Control_CS'
 * '<S2>'   : 'M1DCS/M1SA_F_Control_CS/CSseg_ofl_SSdtC_'
 */
#endif                                 /* RTW_HEADER_M1SA_F_Control_CS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
