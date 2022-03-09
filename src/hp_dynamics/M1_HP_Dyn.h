/*
 * File: M1_HP_Dyn.h
 *
 * Code generated for Simulink model 'M1_HP_Dyn'.
 *
 * Model version                  : 1.960
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Feb 11 10:27:20 2022
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

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real_T S1_HPstiff;              /* Variable: S1_HPstiff
                                        * Referenced by: '<S1>/HpK8'
                                        */
extern real_T S1_M1RBM2HP[36];         /* Variable: S1_M1RBM2HP
                                        * Referenced by: '<S1>/CG2Hp6'
                                        */
extern real_T S2_HPstiff;              /* Variable: S2_HPstiff
                                        * Referenced by: '<S1>/HpK1'
                                        */
extern real_T S2_M1RBM2HP[36];         /* Variable: S2_M1RBM2HP
                                        * Referenced by: '<S1>/CG2Hp8'
                                        */
extern real_T S3_HPstiff;              /* Variable: S3_HPstiff
                                        * Referenced by: '<S1>/HpK2'
                                        */
extern real_T S3_M1RBM2HP[36];         /* Variable: S3_M1RBM2HP
                                        * Referenced by: '<S1>/CG2Hp1'
                                        */
extern real_T S4_HPstiff;              /* Variable: S4_HPstiff
                                        * Referenced by: '<S1>/HpK5'
                                        */
extern real_T S4_M1RBM2HP[36];         /* Variable: S4_M1RBM2HP
                                        * Referenced by: '<S1>/CG2Hp2'
                                        */
extern real_T S5_HPstiff;              /* Variable: S5_HPstiff
                                        * Referenced by: '<S1>/HpK3'
                                        */
extern real_T S5_M1RBM2HP[36];         /* Variable: S5_M1RBM2HP
                                        * Referenced by: '<S1>/CG2Hp3'
                                        */
extern real_T S6_HPstiff;              /* Variable: S6_HPstiff
                                        * Referenced by: '<S1>/HpK4'
                                        */
extern real_T S6_M1RBM2HP[36];         /* Variable: S6_M1RBM2HP
                                        * Referenced by: '<S1>/CG2Hp4'
                                        */
extern real_T S7_HPstiff;              /* Variable: S7_HPstiff
                                        * Referenced by: '<S1>/HpK6'
                                        */
extern real_T S7_M1RBM2HP[36];         /* Variable: S7_M1RBM2HP
                                        * Referenced by: '<S1>/CG2Hp5'
                                        */

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
 * hilite_system('ims_Build5pt1f/M1_HP_Dyn')    - opens subsystem ims_Build5pt1f/M1_HP_Dyn
 * hilite_system('ims_Build5pt1f/M1_HP_Dyn/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ims_Build5pt1f'
 * '<S1>'   : 'ims_Build5pt1f/M1_HP_Dyn'
 */
#endif                                 /* RTW_HEADER_M1_HP_Dyn_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
