/*
 * File: M1_HP_loadcells.h
 *
 * Code generated for Simulink model 'M1_HP_loadcells'.
 *
 * Model version                  : 1.788
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Feb 10 11:47:20 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_M1_HP_loadcells_h_
#define RTW_HEADER_M1_HP_loadcells_h_
#include <string.h>
#include <stddef.h>
#ifndef M1_HP_loadcells_COMMON_INCLUDES_
# define M1_HP_loadcells_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* M1_HP_loadcells_COMMON_INCLUDES_ */

#include "M1_HP_loadcells_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T M1_HP_D[84];                  /* '<Root>/M1_HP_D' */
  real_T M1_HP_cmd[42];                /* '<Root>/M1_HP_cmd' */
} ExtU_M1_HP_loadcells_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T M1_HP_LC[42];                 /* '<Root>/M1_HP_LC' */
} ExtY_M1_HP_loadcells_T;

/* Real-time Model Data Structure */
struct tag_RTM_M1_HP_loadcells_T {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_M1_HP_loadcells_T M1_HP_loadcells_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_M1_HP_loadcells_T M1_HP_loadcells_Y;

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real_T S1_LC_HPstiff;              /* Variable: S1_HPstiff
                                        * Referenced by: '<S2>/HpK'
                                        */
extern real_T S2_LC_HPstiff;              /* Variable: S2_HPstiff
                                        * Referenced by: '<S3>/HpK'
                                        */
extern real_T S3_LC_HPstiff;              /* Variable: S3_HPstiff
                                        * Referenced by: '<S4>/HpK'
                                        */
extern real_T S4_LC_HPstiff;              /* Variable: S4_HPstiff
                                        * Referenced by: '<S5>/HpK'
                                        */
extern real_T S5_LC_HPstiff;              /* Variable: S5_HPstiff
                                        * Referenced by: '<S6>/HpK'
                                        */
extern real_T S6_LC_HPstiff;              /* Variable: S6_HPstiff
                                        * Referenced by: '<S7>/HpK'
                                        */
extern real_T S7_LC_HPstiff;              /* Variable: S7_HPstiff
                                        * Referenced by: '<S8>/HpK'
                                        */

/* Model entry point functions */
extern void M1_HP_loadcells_initialize(void);
extern void M1_HP_loadcells_step(void);
extern void M1_HP_loadcells_terminate(void);

/* Real-time Model object */
extern RT_MODEL_M1_HP_loadcells_T *const M1_HP_loadcells_M;

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
 * hilite_system('M1DCS/M1_HP_loadcells')    - opens subsystem M1DCS/M1_HP_loadcells
 * hilite_system('M1DCS/M1_HP_loadcells/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'M1DCS'
 * '<S1>'   : 'M1DCS/M1_HP_loadcells'
 * '<S2>'   : 'M1DCS/M1_HP_loadcells/M1S1 Loadcell'
 * '<S3>'   : 'M1DCS/M1_HP_loadcells/M1S2 Loadcell'
 * '<S4>'   : 'M1DCS/M1_HP_loadcells/M1S3 Loadcell'
 * '<S5>'   : 'M1DCS/M1_HP_loadcells/M1S4 Loadcell'
 * '<S6>'   : 'M1DCS/M1_HP_loadcells/M1S5 Loadcell'
 * '<S7>'   : 'M1DCS/M1_HP_loadcells/M1S6 Loadcell'
 * '<S8>'   : 'M1DCS/M1_HP_loadcells/M1S7 Control'
 */
#endif                                 /* RTW_HEADER_M1_HP_loadcells_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
