/*
 * File: M1_HP_loadcells.c
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

#include "M1_HP_loadcells.h"
#include "M1_HP_loadcells_private.h"

/* Exported block parameters */
real_T S1_LC_HPstiff = 1.4293878534590691E+8;/* Variable: S1_HPstiff
                                           * Referenced by: '<S2>/HpK'
                                           */
real_T S2_LC_HPstiff = 1.4293878534590691E+8;/* Variable: S2_HPstiff
                                           * Referenced by: '<S3>/HpK'
                                           */
real_T S3_LC_HPstiff = 1.4293878534590691E+8;/* Variable: S3_HPstiff
                                           * Referenced by: '<S4>/HpK'
                                           */
real_T S4_LC_HPstiff = 1.4293878534590691E+8;/* Variable: S4_HPstiff
                                           * Referenced by: '<S5>/HpK'
                                           */
real_T S5_LC_HPstiff = 1.4293878534590691E+8;/* Variable: S5_HPstiff
                                           * Referenced by: '<S6>/HpK'
                                           */
real_T S6_LC_HPstiff = 1.4293878534590691E+8;/* Variable: S6_HPstiff
                                           * Referenced by: '<S7>/HpK'
                                           */
real_T S7_LC_HPstiff = 1.4293878534590691E+8;/* Variable: S7_HPstiff
                                           * Referenced by: '<S8>/HpK'
                                           */

/* External inputs (root inport signals with default storage) */
ExtU_M1_HP_loadcells_T M1_HP_loadcells_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_M1_HP_loadcells_T M1_HP_loadcells_Y;

/* Real-time model */
RT_MODEL_M1_HP_loadcells_T M1_HP_loadcells_M_;
RT_MODEL_M1_HP_loadcells_T *const M1_HP_loadcells_M = &M1_HP_loadcells_M_;

/* Model step function */
void M1_HP_loadcells_step(void)
{
  int32_T i;

  /* Outport: '<Root>/M1_HP_LC' incorporates:
   *  Gain: '<S2>/HpK'
   *  Gain: '<S3>/HpK'
   *  Gain: '<S4>/HpK'
   *  Gain: '<S5>/HpK'
   *  Gain: '<S6>/HpK'
   *  Gain: '<S7>/HpK'
   *  Gain: '<S8>/HpK'
   *  Inport: '<Root>/M1_HP_D'
   *  Inport: '<Root>/M1_HP_cmd'
   *  Sum: '<S2>/Sum1'
   *  Sum: '<S2>/Sum9'
   *  Sum: '<S3>/Sum1'
   *  Sum: '<S3>/Sum9'
   *  Sum: '<S4>/Sum1'
   *  Sum: '<S4>/Sum9'
   *  Sum: '<S5>/Sum1'
   *  Sum: '<S5>/Sum9'
   *  Sum: '<S6>/Sum1'
   *  Sum: '<S6>/Sum9'
   *  Sum: '<S7>/Sum1'
   *  Sum: '<S7>/Sum9'
   *  Sum: '<S8>/Sum1'
   *  Sum: '<S8>/Sum9'
   */
  for (i = 0; i < 6; i++) {
    M1_HP_loadcells_Y.M1_HP_LC[i] = (M1_HP_loadcells_U.M1_HP_D[i + 6] -
      M1_HP_loadcells_U.M1_HP_D[i]) * S1_LC_HPstiff - M1_HP_loadcells_U.M1_HP_cmd[i];
    M1_HP_loadcells_Y.M1_HP_LC[i + 6] = (M1_HP_loadcells_U.M1_HP_D[i + 18] -
      M1_HP_loadcells_U.M1_HP_D[i + 12]) * S2_LC_HPstiff -
      M1_HP_loadcells_U.M1_HP_cmd[i + 6];
    M1_HP_loadcells_Y.M1_HP_LC[i + 12] = (M1_HP_loadcells_U.M1_HP_D[i + 30] -
      M1_HP_loadcells_U.M1_HP_D[i + 24]) * S3_LC_HPstiff -
      M1_HP_loadcells_U.M1_HP_cmd[i + 12];
    M1_HP_loadcells_Y.M1_HP_LC[i + 18] = (M1_HP_loadcells_U.M1_HP_D[i + 42] -
      M1_HP_loadcells_U.M1_HP_D[i + 36]) * S4_LC_HPstiff -
      M1_HP_loadcells_U.M1_HP_cmd[i + 18];
    M1_HP_loadcells_Y.M1_HP_LC[i + 24] = (M1_HP_loadcells_U.M1_HP_D[i + 54] -
      M1_HP_loadcells_U.M1_HP_D[i + 48]) * S5_LC_HPstiff -
      M1_HP_loadcells_U.M1_HP_cmd[i + 24];
    M1_HP_loadcells_Y.M1_HP_LC[i + 30] = (M1_HP_loadcells_U.M1_HP_D[i + 66] -
      M1_HP_loadcells_U.M1_HP_D[i + 60]) * S6_LC_HPstiff -
      M1_HP_loadcells_U.M1_HP_cmd[i + 30];
    M1_HP_loadcells_Y.M1_HP_LC[i + 36] = (M1_HP_loadcells_U.M1_HP_D[i + 78] -
      M1_HP_loadcells_U.M1_HP_D[i + 72]) * S7_LC_HPstiff -
      M1_HP_loadcells_U.M1_HP_cmd[i + 36];
  }

  /* End of Outport: '<Root>/M1_HP_LC' */
}

/* Model initialize function */
void M1_HP_loadcells_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(M1_HP_loadcells_M, (NULL));

  /* external inputs */
  (void)memset(&M1_HP_loadcells_U, 0, sizeof(ExtU_M1_HP_loadcells_T));

  /* external outputs */
  (void) memset(&M1_HP_loadcells_Y.M1_HP_LC[0], 0,
                42U*sizeof(real_T));
}

/* Model terminate function */
void M1_HP_loadcells_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
