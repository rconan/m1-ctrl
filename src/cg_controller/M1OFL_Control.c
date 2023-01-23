/*
 * File: M1OFL_Control.c
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

#include "M1OFL_Control.h"
#include "M1OFL_Control_private.h"

/* Block states (default storage) */
DW_M1OFL_Control_T M1OFL_Control_DW;

/* External inputs (root inport signals with default storage) */
ExtU_M1OFL_Control_T M1OFL_Control_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_M1OFL_Control_T M1OFL_Control_Y;

/* Real-time model */
RT_MODEL_M1OFL_Control_T M1OFL_Control_M_;
RT_MODEL_M1OFL_Control_T *const M1OFL_Control_M = &M1OFL_Control_M_;

/* Model step function */
void M1OFL_Control_step(void)
{
  /* local block i/o variables */
  real_T rtb_LC2CG1[6];
  real_T rtb_LC2CG2[6];
  real_T rtb_LC2CG3[6];
  real_T rtb_LC2CG4[6];
  real_T rtb_LC2CG5[6];
  real_T rtb_LC2CG6[6];
  real_T rtb_LC2CG7[6];
  real_T rtb_Mzcontroller;
  real_T rtb_Mycontroller;
  real_T rtb_Mxcontroller;
  real_T rtb_Fzcontroller;
  real_T rtb_Fycontroller;
  real_T rtb_Fxcontroller;
  int32_T k;
  real_T denAccum;
  real_T rtb_TmpSignalConversionAtSADynamicsS1Inport1[6];
  real_T rtb_SADynamicsS1[6];
  real_T rtb_SADynamicsS2[6];
  real_T rtb_SADynamicsS3[6];
  real_T rtb_SADynamicsS4[6];
  real_T rtb_SADynamicsS5[6];
  real_T rtb_SADynamicsS6[6];
  int32_T i;
  real_T SADynamicsS1_tmp[6];
  real_T SADynamicsS2_tmp[6];
  real_T SADynamicsS3_tmp[6];
  real_T SADynamicsS4_tmp[6];
  real_T SADynamicsS5_tmp[6];
  real_T SADynamicsS6_tmp[6];
  real_T SADynamicsS7_tmp[6];
  int32_T rtb_LC2CG1_tmp;
  real_T denAccum_tmp;
  int32_T memOffset_tmp;
  for (k = 0; k < 6; k++) {
    /* Gain: '<S1>/LC2CG1' */
    rtb_LC2CG1[k] = 0.0;

    /* Gain: '<S1>/LC2CG2' incorporates:
     *  Gain: '<S1>/LC2CG1'
     */
    rtb_LC2CG2[k] = 0.0;

    /* Gain: '<S1>/LC2CG3' incorporates:
     *  Gain: '<S1>/LC2CG1'
     */
    rtb_LC2CG3[k] = 0.0;

    /* Gain: '<S1>/LC2CG4' incorporates:
     *  Gain: '<S1>/LC2CG1'
     */
    rtb_LC2CG4[k] = 0.0;

    /* Gain: '<S1>/LC2CG5' incorporates:
     *  Gain: '<S1>/LC2CG1'
     */
    rtb_LC2CG5[k] = 0.0;

    /* Gain: '<S1>/LC2CG6' incorporates:
     *  Gain: '<S1>/LC2CG1'
     */
    rtb_LC2CG6[k] = 0.0;

    /* Gain: '<S1>/LC2CG7' incorporates:
     *  Gain: '<S1>/LC2CG1'
     */
    rtb_LC2CG7[k] = 0.0;

    /* Gain: '<S1>/LC2CG1' incorporates:
     *  Gain: '<S1>/LC2CG2'
     *  Gain: '<S1>/LC2CG3'
     *  Gain: '<S1>/LC2CG4'
     *  Gain: '<S1>/LC2CG5'
     *  Gain: '<S1>/LC2CG6'
     *  Gain: '<S1>/LC2CG7'
     *  Inport: '<Root>/HP_LC'
     */
    memOffset_tmp = 0;
    for (i = 0; i < 6; i++) {
      rtb_LC2CG1_tmp = memOffset_tmp + k;
      rtb_LC2CG1[k] += M1OFL_Control_ConstP.LC2CG1_Gain[rtb_LC2CG1_tmp] *
        M1OFL_Control_U.HP_LC[i];
      rtb_LC2CG2[k] += M1OFL_Control_ConstP.LC2CG2_Gain[rtb_LC2CG1_tmp] *
        M1OFL_Control_U.HP_LC[i + 6];
      rtb_LC2CG3[k] += M1OFL_Control_ConstP.LC2CG3_Gain[rtb_LC2CG1_tmp] *
        M1OFL_Control_U.HP_LC[i + 12];
      rtb_LC2CG4[k] += M1OFL_Control_ConstP.LC2CG4_Gain[rtb_LC2CG1_tmp] *
        M1OFL_Control_U.HP_LC[i + 18];
      rtb_LC2CG5[k] += M1OFL_Control_ConstP.LC2CG5_Gain[rtb_LC2CG1_tmp] *
        M1OFL_Control_U.HP_LC[i + 24];
      rtb_LC2CG6[k] += M1OFL_Control_ConstP.LC2CG6_Gain[rtb_LC2CG1_tmp] *
        M1OFL_Control_U.HP_LC[i + 30];
      rtb_LC2CG7[k] += M1OFL_Control_ConstP.LC2CG7_Gain[rtb_LC2CG1_tmp] *
        M1OFL_Control_U.HP_LC[i + 36];
      memOffset_tmp += 6;
    }
  }

  /* DiscreteStateSpace: '<S2>/Fx controller' */
  {
    rtb_Mzcontroller = (6.5598720805159942)*
      M1OFL_Control_DW.Fxcontroller_DSTATE[0]
      + (-5.94467376914989)*M1OFL_Control_DW.Fxcontroller_DSTATE[1]
      + (1.5)*M1OFL_Control_DW.Fxcontroller_DSTATE[2];
    rtb_Mzcontroller += 0.0205612224491055*rtb_LC2CG1[0];
  }

  /* DiscreteStateSpace: '<S2>/Fy controller' */
  {
    rtb_Mycontroller = (6.5598720805159942)*
      M1OFL_Control_DW.Fycontroller_DSTATE[0]
      + (-5.94467376914989)*M1OFL_Control_DW.Fycontroller_DSTATE[1]
      + (1.5)*M1OFL_Control_DW.Fycontroller_DSTATE[2];
    rtb_Mycontroller += 0.0205612224491055*rtb_LC2CG1[1];
  }

  /* DiscreteStateSpace: '<S2>/Fz controller' */
  {
    rtb_Mxcontroller = (11.530556837169614)*
      M1OFL_Control_DW.Fzcontroller_DSTATE[0]
      + (-10.851053072456448)*M1OFL_Control_DW.Fzcontroller_DSTATE[1]
      + (2.5)*M1OFL_Control_DW.Fzcontroller_DSTATE[2];
    rtb_Mxcontroller += 0.027443636441156067*rtb_LC2CG1[2];
  }

  /* DiscreteStateSpace: '<S2>/Mx controller' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = M1OFL_Control_ConstP.pooled12;
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE[0];
      real_T *y0 = &rtb_Fzcontroller;
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_Fzcontroller += 0.01117010856270375*rtb_LC2CG1[3];
  }

  /* DiscreteStateSpace: '<S2>/My controller' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = M1OFL_Control_ConstP.pooled12;
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE[0];
      real_T *y0 = &rtb_Fycontroller;
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_Fycontroller += 0.01117010856270375*rtb_LC2CG1[4];
  }

  /* DiscreteStateSpace: '<S2>/Mz controller' */
  {
    rtb_Fxcontroller = (-20.532898991147984)*
      M1OFL_Control_DW.Mzcontroller_DSTATE[0]
      + (6.3249300064723526)*M1OFL_Control_DW.Mzcontroller_DSTATE[1]
      + (2.5)*M1OFL_Control_DW.Mzcontroller_DSTATE[2];
    rtb_Fxcontroller += 0.019188774883241673*rtb_LC2CG1[5];
  }

  /* SignalConversion: '<S1>/TmpSignal ConversionAtSA Dynamics - S1Inport1' */
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[0] = rtb_Mzcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[1] = rtb_Mycontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[2] = rtb_Mxcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[3] = rtb_Fzcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[4] = rtb_Fycontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[5] = rtb_Fxcontroller;

  /* DiscreteTransferFcn: '<S1>/SA Dynamics - S1' */
  for (k = 0; k < 6; k++) {
    memOffset_tmp = k << 1;
    denAccum_tmp = M1OFL_Control_DW.SADynamicsS1_states[memOffset_tmp + 1];
    denAccum = (rtb_TmpSignalConversionAtSADynamicsS1Inport1[k] -
                -0.77932227475069393 *
                M1OFL_Control_DW.SADynamicsS1_states[memOffset_tmp]) -
      denAccum_tmp * 0.15183580198064905;
    SADynamicsS1_tmp[k] = denAccum;
    denAccum *= 0.094481844738029327;
    denAccum += 0.24121577940998443 *
      M1OFL_Control_DW.SADynamicsS1_states[memOffset_tmp];
    rtb_SADynamicsS1[k] = denAccum_tmp * 0.036815903081941416 + denAccum;
  }

  /* End of DiscreteTransferFcn: '<S1>/SA Dynamics - S1' */

  /* DiscreteStateSpace: '<S3>/Fx controller' */
  {
    rtb_Fxcontroller = (6.5598720805159942)*
      M1OFL_Control_DW.Fxcontroller_DSTATE_h[0]
      + (-5.94467376914989)*M1OFL_Control_DW.Fxcontroller_DSTATE_h[1]
      + (1.5)*M1OFL_Control_DW.Fxcontroller_DSTATE_h[2];
    rtb_Fxcontroller += 0.0205612224491055*rtb_LC2CG2[0];
  }

  /* DiscreteStateSpace: '<S3>/Fy controller' */
  {
    rtb_Fycontroller = (6.5598720805159942)*
      M1OFL_Control_DW.Fycontroller_DSTATE_a[0]
      + (-5.94467376914989)*M1OFL_Control_DW.Fycontroller_DSTATE_a[1]
      + (1.5)*M1OFL_Control_DW.Fycontroller_DSTATE_a[2];
    rtb_Fycontroller += 0.0205612224491055*rtb_LC2CG2[1];
  }

  /* DiscreteStateSpace: '<S3>/Fz controller' */
  {
    rtb_Fzcontroller = (11.530556837169614)*
      M1OFL_Control_DW.Fzcontroller_DSTATE_l[0]
      + (-10.851053072456448)*M1OFL_Control_DW.Fzcontroller_DSTATE_l[1]
      + (2.5)*M1OFL_Control_DW.Fzcontroller_DSTATE_l[2];
    rtb_Fzcontroller += 0.027443636441156067*rtb_LC2CG2[2];
  }

  /* DiscreteStateSpace: '<S3>/Mx controller' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = M1OFL_Control_ConstP.pooled12;
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_o[0];
      real_T *y0 = &rtb_Mxcontroller;
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_Mxcontroller += 0.01117010856270375*rtb_LC2CG2[3];
  }

  /* DiscreteStateSpace: '<S3>/My controller' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = M1OFL_Control_ConstP.pooled12;
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_p[0];
      real_T *y0 = &rtb_Mycontroller;
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_Mycontroller += 0.01117010856270375*rtb_LC2CG2[4];
  }

  /* DiscreteStateSpace: '<S3>/Mz controller' */
  {
    rtb_Mzcontroller = (-20.532898991147984)*
      M1OFL_Control_DW.Mzcontroller_DSTATE_k[0]
      + (6.3249300064723526)*M1OFL_Control_DW.Mzcontroller_DSTATE_k[1]
      + (2.5)*M1OFL_Control_DW.Mzcontroller_DSTATE_k[2];
    rtb_Mzcontroller += 0.019188774883241673*rtb_LC2CG2[5];
  }

  /* SignalConversion: '<S1>/TmpSignal ConversionAtSA Dynamics - S2Inport1' */
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[0] = rtb_Fxcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[1] = rtb_Fycontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[2] = rtb_Fzcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[3] = rtb_Mxcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[4] = rtb_Mycontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[5] = rtb_Mzcontroller;

  /* DiscreteTransferFcn: '<S1>/SA Dynamics - S2' incorporates:
   *  SignalConversion: '<S1>/TmpSignal ConversionAtSA Dynamics - S2Inport1'
   */
  for (k = 0; k < 6; k++) {
    memOffset_tmp = k << 1;
    denAccum_tmp = M1OFL_Control_DW.SADynamicsS2_states[memOffset_tmp + 1];
    denAccum = (rtb_TmpSignalConversionAtSADynamicsS1Inport1[k] -
                -0.77932227475069393 *
                M1OFL_Control_DW.SADynamicsS2_states[memOffset_tmp]) -
      denAccum_tmp * 0.15183580198064905;
    SADynamicsS2_tmp[k] = denAccum;
    denAccum *= 0.094481844738029327;
    denAccum += 0.24121577940998443 *
      M1OFL_Control_DW.SADynamicsS2_states[memOffset_tmp];
    rtb_SADynamicsS2[k] = denAccum_tmp * 0.036815903081941416 + denAccum;
  }

  /* End of DiscreteTransferFcn: '<S1>/SA Dynamics - S2' */

  /* DiscreteStateSpace: '<S4>/Fx controller' */
  {
    rtb_Fxcontroller = (6.5598720805159942)*
      M1OFL_Control_DW.Fxcontroller_DSTATE_o[0]
      + (-5.94467376914989)*M1OFL_Control_DW.Fxcontroller_DSTATE_o[1]
      + (1.5)*M1OFL_Control_DW.Fxcontroller_DSTATE_o[2];
    rtb_Fxcontroller += 0.0205612224491055*rtb_LC2CG3[0];
  }

  /* DiscreteStateSpace: '<S4>/Fy controller' */
  {
    rtb_Fycontroller = (6.5598720805159942)*
      M1OFL_Control_DW.Fycontroller_DSTATE_h[0]
      + (-5.94467376914989)*M1OFL_Control_DW.Fycontroller_DSTATE_h[1]
      + (1.5)*M1OFL_Control_DW.Fycontroller_DSTATE_h[2];
    rtb_Fycontroller += 0.0205612224491055*rtb_LC2CG3[1];
  }

  /* DiscreteStateSpace: '<S4>/Fz controller' */
  {
    rtb_Fzcontroller = (11.530556837169614)*
      M1OFL_Control_DW.Fzcontroller_DSTATE_n[0]
      + (-10.851053072456448)*M1OFL_Control_DW.Fzcontroller_DSTATE_n[1]
      + (2.5)*M1OFL_Control_DW.Fzcontroller_DSTATE_n[2];
    rtb_Fzcontroller += 0.027443636441156067*rtb_LC2CG3[2];
  }

  /* DiscreteStateSpace: '<S4>/Mx controller' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = M1OFL_Control_ConstP.pooled12;
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_l[0];
      real_T *y0 = &rtb_Mxcontroller;
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_Mxcontroller += 0.01117010856270375*rtb_LC2CG3[3];
  }

  /* DiscreteStateSpace: '<S4>/My controller' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = M1OFL_Control_ConstP.pooled12;
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_d[0];
      real_T *y0 = &rtb_Mycontroller;
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_Mycontroller += 0.01117010856270375*rtb_LC2CG3[4];
  }

  /* DiscreteStateSpace: '<S4>/Mz controller' */
  {
    rtb_Mzcontroller = (-20.532898991147984)*
      M1OFL_Control_DW.Mzcontroller_DSTATE_a[0]
      + (6.3249300064723526)*M1OFL_Control_DW.Mzcontroller_DSTATE_a[1]
      + (2.5)*M1OFL_Control_DW.Mzcontroller_DSTATE_a[2];
    rtb_Mzcontroller += 0.019188774883241673*rtb_LC2CG3[5];
  }

  /* SignalConversion: '<S1>/TmpSignal ConversionAtSA Dynamics - S3Inport1' */
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[0] = rtb_Fxcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[1] = rtb_Fycontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[2] = rtb_Fzcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[3] = rtb_Mxcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[4] = rtb_Mycontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[5] = rtb_Mzcontroller;

  /* DiscreteTransferFcn: '<S1>/SA Dynamics - S3' incorporates:
   *  SignalConversion: '<S1>/TmpSignal ConversionAtSA Dynamics - S3Inport1'
   */
  for (k = 0; k < 6; k++) {
    memOffset_tmp = k << 1;
    denAccum_tmp = M1OFL_Control_DW.SADynamicsS3_states[memOffset_tmp + 1];
    denAccum = (rtb_TmpSignalConversionAtSADynamicsS1Inport1[k] -
                -0.77932227475069393 *
                M1OFL_Control_DW.SADynamicsS3_states[memOffset_tmp]) -
      denAccum_tmp * 0.15183580198064905;
    SADynamicsS3_tmp[k] = denAccum;
    denAccum *= 0.094481844738029327;
    denAccum += 0.24121577940998443 *
      M1OFL_Control_DW.SADynamicsS3_states[memOffset_tmp];
    rtb_SADynamicsS3[k] = denAccum_tmp * 0.036815903081941416 + denAccum;
  }

  /* End of DiscreteTransferFcn: '<S1>/SA Dynamics - S3' */

  /* DiscreteStateSpace: '<S5>/Fx controller' */
  {
    rtb_Fxcontroller = (6.5598720805159942)*
      M1OFL_Control_DW.Fxcontroller_DSTATE_i[0]
      + (-5.94467376914989)*M1OFL_Control_DW.Fxcontroller_DSTATE_i[1]
      + (1.5)*M1OFL_Control_DW.Fxcontroller_DSTATE_i[2];
    rtb_Fxcontroller += 0.0205612224491055*rtb_LC2CG4[0];
  }

  /* DiscreteStateSpace: '<S5>/Fy controller' */
  {
    rtb_Fycontroller = (6.5598720805159942)*
      M1OFL_Control_DW.Fycontroller_DSTATE_n[0]
      + (-5.94467376914989)*M1OFL_Control_DW.Fycontroller_DSTATE_n[1]
      + (1.5)*M1OFL_Control_DW.Fycontroller_DSTATE_n[2];
    rtb_Fycontroller += 0.0205612224491055*rtb_LC2CG4[1];
  }

  /* DiscreteStateSpace: '<S5>/Fz controller' */
  {
    rtb_Fzcontroller = (11.530556837169614)*
      M1OFL_Control_DW.Fzcontroller_DSTATE_f[0]
      + (-10.851053072456448)*M1OFL_Control_DW.Fzcontroller_DSTATE_f[1]
      + (2.5)*M1OFL_Control_DW.Fzcontroller_DSTATE_f[2];
    rtb_Fzcontroller += 0.027443636441156067*rtb_LC2CG4[2];
  }

  /* DiscreteStateSpace: '<S5>/Mx controller' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = M1OFL_Control_ConstP.pooled12;
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_k[0];
      real_T *y0 = &rtb_Mxcontroller;
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_Mxcontroller += 0.01117010856270375*rtb_LC2CG4[3];
  }

  /* DiscreteStateSpace: '<S5>/My controller' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = M1OFL_Control_ConstP.pooled12;
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_pv[0];
      real_T *y0 = &rtb_Mycontroller;
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_Mycontroller += 0.01117010856270375*rtb_LC2CG4[4];
  }

  /* DiscreteStateSpace: '<S5>/Mz controller' */
  {
    rtb_Mzcontroller = (-20.532898991147984)*
      M1OFL_Control_DW.Mzcontroller_DSTATE_ka[0]
      + (6.3249300064723526)*M1OFL_Control_DW.Mzcontroller_DSTATE_ka[1]
      + (2.5)*M1OFL_Control_DW.Mzcontroller_DSTATE_ka[2];
    rtb_Mzcontroller += 0.019188774883241673*rtb_LC2CG4[5];
  }

  /* SignalConversion: '<S1>/TmpSignal ConversionAtSA Dynamics - S4Inport1' */
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[0] = rtb_Fxcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[1] = rtb_Fycontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[2] = rtb_Fzcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[3] = rtb_Mxcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[4] = rtb_Mycontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[5] = rtb_Mzcontroller;

  /* DiscreteTransferFcn: '<S1>/SA Dynamics - S4' incorporates:
   *  SignalConversion: '<S1>/TmpSignal ConversionAtSA Dynamics - S4Inport1'
   */
  for (k = 0; k < 6; k++) {
    memOffset_tmp = k << 1;
    denAccum_tmp = M1OFL_Control_DW.SADynamicsS4_states[memOffset_tmp + 1];
    denAccum = (rtb_TmpSignalConversionAtSADynamicsS1Inport1[k] -
                -0.77932227475069393 *
                M1OFL_Control_DW.SADynamicsS4_states[memOffset_tmp]) -
      denAccum_tmp * 0.15183580198064905;
    SADynamicsS4_tmp[k] = denAccum;
    denAccum *= 0.094481844738029327;
    denAccum += 0.24121577940998443 *
      M1OFL_Control_DW.SADynamicsS4_states[memOffset_tmp];
    rtb_SADynamicsS4[k] = denAccum_tmp * 0.036815903081941416 + denAccum;
  }

  /* End of DiscreteTransferFcn: '<S1>/SA Dynamics - S4' */

  /* DiscreteStateSpace: '<S6>/Fx controller' */
  {
    rtb_Fxcontroller = (6.5598720805159942)*
      M1OFL_Control_DW.Fxcontroller_DSTATE_j[0]
      + (-5.94467376914989)*M1OFL_Control_DW.Fxcontroller_DSTATE_j[1]
      + (1.5)*M1OFL_Control_DW.Fxcontroller_DSTATE_j[2];
    rtb_Fxcontroller += 0.0205612224491055*rtb_LC2CG5[0];
  }

  /* DiscreteStateSpace: '<S6>/Fy controller' */
  {
    rtb_Fycontroller = (6.5598720805159942)*
      M1OFL_Control_DW.Fycontroller_DSTATE_k[0]
      + (-5.94467376914989)*M1OFL_Control_DW.Fycontroller_DSTATE_k[1]
      + (1.5)*M1OFL_Control_DW.Fycontroller_DSTATE_k[2];
    rtb_Fycontroller += 0.0205612224491055*rtb_LC2CG5[1];
  }

  /* DiscreteStateSpace: '<S6>/Fz controller' */
  {
    rtb_Fzcontroller = (11.530556837169614)*
      M1OFL_Control_DW.Fzcontroller_DSTATE_f2[0]
      + (-10.851053072456448)*M1OFL_Control_DW.Fzcontroller_DSTATE_f2[1]
      + (2.5)*M1OFL_Control_DW.Fzcontroller_DSTATE_f2[2];
    rtb_Fzcontroller += 0.027443636441156067*rtb_LC2CG5[2];
  }

  /* DiscreteStateSpace: '<S6>/Mx controller' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = M1OFL_Control_ConstP.pooled12;
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_d[0];
      real_T *y0 = &rtb_Mxcontroller;
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_Mxcontroller += 0.01117010856270375*rtb_LC2CG5[3];
  }

  /* DiscreteStateSpace: '<S6>/My controller' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = M1OFL_Control_ConstP.pooled12;
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_f[0];
      real_T *y0 = &rtb_Mycontroller;
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_Mycontroller += 0.01117010856270375*rtb_LC2CG5[4];
  }

  /* DiscreteStateSpace: '<S6>/Mz controller' */
  {
    rtb_Mzcontroller = (-20.532898991147984)*
      M1OFL_Control_DW.Mzcontroller_DSTATE_f[0]
      + (6.3249300064723526)*M1OFL_Control_DW.Mzcontroller_DSTATE_f[1]
      + (2.5)*M1OFL_Control_DW.Mzcontroller_DSTATE_f[2];
    rtb_Mzcontroller += 0.019188774883241673*rtb_LC2CG5[5];
  }

  /* SignalConversion: '<S1>/TmpSignal ConversionAtSA Dynamics - S5Inport1' */
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[0] = rtb_Fxcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[1] = rtb_Fycontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[2] = rtb_Fzcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[3] = rtb_Mxcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[4] = rtb_Mycontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[5] = rtb_Mzcontroller;

  /* DiscreteTransferFcn: '<S1>/SA Dynamics - S5' incorporates:
   *  SignalConversion: '<S1>/TmpSignal ConversionAtSA Dynamics - S5Inport1'
   */
  for (k = 0; k < 6; k++) {
    memOffset_tmp = k << 1;
    denAccum_tmp = M1OFL_Control_DW.SADynamicsS5_states[memOffset_tmp + 1];
    denAccum = (rtb_TmpSignalConversionAtSADynamicsS1Inport1[k] -
                -0.77932227475069393 *
                M1OFL_Control_DW.SADynamicsS5_states[memOffset_tmp]) -
      denAccum_tmp * 0.15183580198064905;
    SADynamicsS5_tmp[k] = denAccum;
    denAccum *= 0.094481844738029327;
    denAccum += 0.24121577940998443 *
      M1OFL_Control_DW.SADynamicsS5_states[memOffset_tmp];
    rtb_SADynamicsS5[k] = denAccum_tmp * 0.036815903081941416 + denAccum;
  }

  /* End of DiscreteTransferFcn: '<S1>/SA Dynamics - S5' */

  /* DiscreteStateSpace: '<S7>/Fx controller' */
  {
    rtb_Fxcontroller = (6.5598720805159942)*
      M1OFL_Control_DW.Fxcontroller_DSTATE_d[0]
      + (-5.94467376914989)*M1OFL_Control_DW.Fxcontroller_DSTATE_d[1]
      + (1.5)*M1OFL_Control_DW.Fxcontroller_DSTATE_d[2];
    rtb_Fxcontroller += 0.0205612224491055*rtb_LC2CG6[0];
  }

  /* DiscreteStateSpace: '<S7>/Fy controller' */
  {
    rtb_Fycontroller = (6.5598720805159942)*
      M1OFL_Control_DW.Fycontroller_DSTATE_i[0]
      + (-5.94467376914989)*M1OFL_Control_DW.Fycontroller_DSTATE_i[1]
      + (1.5)*M1OFL_Control_DW.Fycontroller_DSTATE_i[2];
    rtb_Fycontroller += 0.0205612224491055*rtb_LC2CG6[1];
  }

  /* DiscreteStateSpace: '<S7>/Fz controller' */
  {
    rtb_Fzcontroller = (11.530556837169614)*
      M1OFL_Control_DW.Fzcontroller_DSTATE_b[0]
      + (-10.851053072456448)*M1OFL_Control_DW.Fzcontroller_DSTATE_b[1]
      + (2.5)*M1OFL_Control_DW.Fzcontroller_DSTATE_b[2];
    rtb_Fzcontroller += 0.027443636441156067*rtb_LC2CG6[2];
  }

  /* DiscreteStateSpace: '<S7>/Mx controller' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = M1OFL_Control_ConstP.pooled12;
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_m[0];
      real_T *y0 = &rtb_Mxcontroller;
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_Mxcontroller += 0.01117010856270375*rtb_LC2CG6[3];
  }

  /* DiscreteStateSpace: '<S7>/My controller' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = M1OFL_Control_ConstP.pooled12;
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_b[0];
      real_T *y0 = &rtb_Mycontroller;
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_Mycontroller += 0.01117010856270375*rtb_LC2CG6[4];
  }

  /* DiscreteStateSpace: '<S7>/Mz controller' */
  {
    rtb_Mzcontroller = (-20.532898991147984)*
      M1OFL_Control_DW.Mzcontroller_DSTATE_kn[0]
      + (6.3249300064723526)*M1OFL_Control_DW.Mzcontroller_DSTATE_kn[1]
      + (2.5)*M1OFL_Control_DW.Mzcontroller_DSTATE_kn[2];
    rtb_Mzcontroller += 0.019188774883241673*rtb_LC2CG6[5];
  }

  /* SignalConversion: '<S1>/TmpSignal ConversionAtSA Dynamics - S6Inport1' */
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[0] = rtb_Fxcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[1] = rtb_Fycontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[2] = rtb_Fzcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[3] = rtb_Mxcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[4] = rtb_Mycontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[5] = rtb_Mzcontroller;

  /* DiscreteTransferFcn: '<S1>/SA Dynamics - S6' incorporates:
   *  SignalConversion: '<S1>/TmpSignal ConversionAtSA Dynamics - S6Inport1'
   */
  for (k = 0; k < 6; k++) {
    memOffset_tmp = k << 1;
    denAccum_tmp = M1OFL_Control_DW.SADynamicsS6_states[memOffset_tmp + 1];
    denAccum = (rtb_TmpSignalConversionAtSADynamicsS1Inport1[k] -
                -0.77932227475069393 *
                M1OFL_Control_DW.SADynamicsS6_states[memOffset_tmp]) -
      denAccum_tmp * 0.15183580198064905;
    SADynamicsS6_tmp[k] = denAccum;
    denAccum *= 0.094481844738029327;
    denAccum += 0.24121577940998443 *
      M1OFL_Control_DW.SADynamicsS6_states[memOffset_tmp];
    rtb_SADynamicsS6[k] = denAccum_tmp * 0.036815903081941416 + denAccum;
  }

  /* End of DiscreteTransferFcn: '<S1>/SA Dynamics - S6' */

  /* DiscreteStateSpace: '<S8>/Fx controller' */
  {
    rtb_Fxcontroller = (6.5598720805159942)*
      M1OFL_Control_DW.Fxcontroller_DSTATE_b[0]
      + (-5.94467376914989)*M1OFL_Control_DW.Fxcontroller_DSTATE_b[1]
      + (1.5)*M1OFL_Control_DW.Fxcontroller_DSTATE_b[2];
    rtb_Fxcontroller += 0.0205612224491055*rtb_LC2CG7[0];
  }

  /* DiscreteStateSpace: '<S8>/Fy controller' */
  {
    rtb_Fycontroller = (6.5598720805159942)*
      M1OFL_Control_DW.Fycontroller_DSTATE_nj[0]
      + (-5.94467376914989)*M1OFL_Control_DW.Fycontroller_DSTATE_nj[1]
      + (1.5)*M1OFL_Control_DW.Fycontroller_DSTATE_nj[2];
    rtb_Fycontroller += 0.0205612224491055*rtb_LC2CG7[1];
  }

  /* DiscreteStateSpace: '<S8>/Fz controller' */
  {
    rtb_Fzcontroller = (11.530556837169614)*
      M1OFL_Control_DW.Fzcontroller_DSTATE_c[0]
      + (-10.851053072456448)*M1OFL_Control_DW.Fzcontroller_DSTATE_c[1]
      + (2.5)*M1OFL_Control_DW.Fzcontroller_DSTATE_c[2];
    rtb_Fzcontroller += 0.027443636441156067*rtb_LC2CG7[2];
  }

  /* DiscreteStateSpace: '<S8>/Mx controller' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = M1OFL_Control_ConstP.pooled12;
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_i[0];
      real_T *y0 = &rtb_Mxcontroller;
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_Mxcontroller += 0.01117010856270375*rtb_LC2CG7[3];
  }

  /* DiscreteStateSpace: '<S8>/My controller' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = M1OFL_Control_ConstP.pooled12;
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_o[0];
      real_T *y0 = &rtb_Mycontroller;
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_Mycontroller += 0.01117010856270375*rtb_LC2CG7[4];
  }

  /* DiscreteStateSpace: '<S8>/Mz controller' */
  {
    rtb_Mzcontroller = (-20.532898991147984)*
      M1OFL_Control_DW.Mzcontroller_DSTATE_i[0]
      + (6.3249300064723526)*M1OFL_Control_DW.Mzcontroller_DSTATE_i[1]
      + (2.5)*M1OFL_Control_DW.Mzcontroller_DSTATE_i[2];
    rtb_Mzcontroller += 0.019188774883241673*rtb_LC2CG7[5];
  }

  /* SignalConversion: '<S1>/TmpSignal ConversionAtSA Dynamics - S7Inport1' */
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[0] = rtb_Fxcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[1] = rtb_Fycontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[2] = rtb_Fzcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[3] = rtb_Mxcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[4] = rtb_Mycontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[5] = rtb_Mzcontroller;
  for (k = 0; k < 6; k++) {
    /* DiscreteTransferFcn: '<S1>/SA Dynamics - S7' incorporates:
     *  SignalConversion: '<S1>/TmpSignal ConversionAtSA Dynamics - S7Inport1'
     */
    memOffset_tmp = k << 1;
    denAccum_tmp = M1OFL_Control_DW.SADynamicsS7_states[memOffset_tmp + 1];
    denAccum = (rtb_TmpSignalConversionAtSADynamicsS1Inport1[k] -
                -0.77932227475069393 *
                M1OFL_Control_DW.SADynamicsS7_states[memOffset_tmp]) -
      denAccum_tmp * 0.15183580198064905;
    SADynamicsS7_tmp[k] = denAccum;
    denAccum *= 0.094481844738029327;
    denAccum += 0.24121577940998443 *
      M1OFL_Control_DW.SADynamicsS7_states[memOffset_tmp];
    denAccum += denAccum_tmp * 0.036815903081941416;

    /* Outport: '<Root>/M1_Rel_F' incorporates:
     *  DiscreteTransferFcn: '<S1>/SA Dynamics - S7'
     */
    M1OFL_Control_Y.M1_Rel_F[k] = rtb_SADynamicsS1[k];
    M1OFL_Control_Y.M1_Rel_F[k + 6] = rtb_SADynamicsS2[k];
    M1OFL_Control_Y.M1_Rel_F[k + 12] = rtb_SADynamicsS3[k];
    M1OFL_Control_Y.M1_Rel_F[k + 18] = rtb_SADynamicsS4[k];
    M1OFL_Control_Y.M1_Rel_F[k + 24] = rtb_SADynamicsS5[k];
    M1OFL_Control_Y.M1_Rel_F[k + 30] = rtb_SADynamicsS6[k];
    M1OFL_Control_Y.M1_Rel_F[k + 36] = denAccum;
  }

  /* Update for DiscreteStateSpace: '<S2>/Fx controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.47684153921414885)*M1OFL_Control_DW.Fxcontroller_DSTATE[0]
      + (0.68480541865093592)*M1OFL_Control_DW.Fxcontroller_DSTATE[1]
      + (-0.051399221529844809)*M1OFL_Control_DW.Fxcontroller_DSTATE[2];
    xnew[0] += (-0.0017355509321005055)*rtb_LC2CG1[0];
    xnew[1] = (-0.0016575308145891927)*M1OFL_Control_DW.Fxcontroller_DSTATE[0]
      + (0.54422361645762907)*M1OFL_Control_DW.Fxcontroller_DSTATE[1]
      + (0.11154561057231037)*M1OFL_Control_DW.Fxcontroller_DSTATE[2];
    xnew[1] += (0.0042956013256257343)*rtb_LC2CG1[0];
    xnew[2] = (1.0)*M1OFL_Control_DW.Fxcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG1[0];
    (void) memcpy(&M1OFL_Control_DW.Fxcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Fy controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.47684153921414885)*M1OFL_Control_DW.Fycontroller_DSTATE[0]
      + (0.68480541865093592)*M1OFL_Control_DW.Fycontroller_DSTATE[1]
      + (-0.051399221529844809)*M1OFL_Control_DW.Fycontroller_DSTATE[2];
    xnew[0] += (-0.0017355509321005055)*rtb_LC2CG1[1];
    xnew[1] = (-0.0016575308145891927)*M1OFL_Control_DW.Fycontroller_DSTATE[0]
      + (0.54422361645762907)*M1OFL_Control_DW.Fycontroller_DSTATE[1]
      + (0.11154561057231037)*M1OFL_Control_DW.Fycontroller_DSTATE[2];
    xnew[1] += (0.0042956013256257343)*rtb_LC2CG1[1];
    xnew[2] = (1.0)*M1OFL_Control_DW.Fycontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG1[1];
    (void) memcpy(&M1OFL_Control_DW.Fycontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Fz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.24588323456423122)*M1OFL_Control_DW.Fzcontroller_DSTATE[0]
      + (0.7046784245026928)*M1OFL_Control_DW.Fzcontroller_DSTATE[1]
      + (0.0010918487408774443)*M1OFL_Control_DW.Fzcontroller_DSTATE[2];
    xnew[0] += (0.00026134526724467871)*rtb_LC2CG1[2];
    xnew[1] = (-0.00064951930680838814)*M1OFL_Control_DW.Fzcontroller_DSTATE[0]
      + (0.28867118809350589)*M1OFL_Control_DW.Fzcontroller_DSTATE[1]
      + (0.15553729939777869)*M1OFL_Control_DW.Fzcontroller_DSTATE[2];
    xnew[1] += (0.0058792052074552442)*rtb_LC2CG1[2];
    xnew[2] = (1.0)*M1OFL_Control_DW.Fzcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG1[2];
    (void) memcpy(&M1OFL_Control_DW.Fzcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Mx controller' */
  {
    real_T xnew[5];

    {
      static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = M1OFL_Control_ConstP.pooled10;
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 4;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    xnew[0] += (-0.0036100737148655128)*rtb_LC2CG1[3];

    {
      static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA5 = &M1OFL_Control_ConstP.pooled10[5];
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 4;
      *pxnew1 = (*pA5++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA5++) * xd[*pAidx++];
      }
    }

    xnew[1] += (0.0028052699927021453)*rtb_LC2CG1[3];

    {
      static const int_T colAidxRow2[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA10 = &M1OFL_Control_ConstP.pooled10[10];
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 4;
      *pxnew2 = (*pA10++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA10++) * xd[*pAidx++];
      }
    }

    xnew[2] += (0.00059969188090775545)*rtb_LC2CG1[3];

    {
      static const int_T colAidxRow3[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA15 = &M1OFL_Control_ConstP.pooled10[15];
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 4;
      *pxnew3 = (*pA15++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA15++) * xd[*pAidx++];
      }
    }

    xnew[3] += (0.000550854762514463)*rtb_LC2CG1[3];
    xnew[4] = (1.0)*M1OFL_Control_DW.Mxcontroller_DSTATE[4];
    xnew[4] += (0.039999999999999994)*rtb_LC2CG1[3];
    (void) memcpy(&M1OFL_Control_DW.Mxcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*5);
  }

  /* Update for DiscreteStateSpace: '<S2>/My controller' */
  {
    real_T xnew[5];

    {
      static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = M1OFL_Control_ConstP.pooled10;
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 4;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    xnew[0] += (-0.0036100737148655128)*rtb_LC2CG1[4];

    {
      static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA5 = &M1OFL_Control_ConstP.pooled10[5];
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 4;
      *pxnew1 = (*pA5++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA5++) * xd[*pAidx++];
      }
    }

    xnew[1] += (0.0028052699927021453)*rtb_LC2CG1[4];

    {
      static const int_T colAidxRow2[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA10 = &M1OFL_Control_ConstP.pooled10[10];
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 4;
      *pxnew2 = (*pA10++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA10++) * xd[*pAidx++];
      }
    }

    xnew[2] += (0.00059969188090775545)*rtb_LC2CG1[4];

    {
      static const int_T colAidxRow3[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA15 = &M1OFL_Control_ConstP.pooled10[15];
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 4;
      *pxnew3 = (*pA15++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA15++) * xd[*pAidx++];
      }
    }

    xnew[3] += (0.000550854762514463)*rtb_LC2CG1[4];
    xnew[4] = (1.0)*M1OFL_Control_DW.Mycontroller_DSTATE[4];
    xnew[4] += (0.039999999999999994)*rtb_LC2CG1[4];
    (void) memcpy(&M1OFL_Control_DW.Mycontroller_DSTATE[0], xnew,
                  sizeof(real_T)*5);
  }

  /* Update for DiscreteStateSpace: '<S2>/Mz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.027853439610535102)*M1OFL_Control_DW.Mzcontroller_DSTATE[0]
      + (0.4384495239533896)*M1OFL_Control_DW.Mzcontroller_DSTATE[1]
      + (0.05976437398581852)*M1OFL_Control_DW.Mzcontroller_DSTATE[2];
    xnew[0] += (0.0022548103799476128)*rtb_LC2CG1[5];
    xnew[1] = (0.025863212654755947)*M1OFL_Control_DW.Mzcontroller_DSTATE[0]
      + (0.70999971403230988)*M1OFL_Control_DW.Mzcontroller_DSTATE[1]
      + (-0.121271115438719)*M1OFL_Control_DW.Mzcontroller_DSTATE[2];
    xnew[1] += (-0.0047377249105599022)*rtb_LC2CG1[5];
    xnew[2] = (1.0)*M1OFL_Control_DW.Mzcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG1[5];
    (void) memcpy(&M1OFL_Control_DW.Mzcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteTransferFcn: '<S1>/SA Dynamics - S1' */
  for (k = 0; k < 6; k++) {
    memOffset_tmp = k << 1;
    M1OFL_Control_DW.SADynamicsS1_states[memOffset_tmp - -1] =
      M1OFL_Control_DW.SADynamicsS1_states[memOffset_tmp];
    M1OFL_Control_DW.SADynamicsS1_states[memOffset_tmp] = SADynamicsS1_tmp[k];
  }

  /* End of Update for DiscreteTransferFcn: '<S1>/SA Dynamics - S1' */

  /* Update for DiscreteStateSpace: '<S3>/Fx controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.47684153921414885)*M1OFL_Control_DW.Fxcontroller_DSTATE_h[0]
      + (0.68480541865093592)*M1OFL_Control_DW.Fxcontroller_DSTATE_h[1]
      + (-0.051399221529844809)*M1OFL_Control_DW.Fxcontroller_DSTATE_h[2];
    xnew[0] += (-0.0017355509321005055)*rtb_LC2CG2[0];
    xnew[1] = (-0.0016575308145891927)*M1OFL_Control_DW.Fxcontroller_DSTATE_h[0]
      + (0.54422361645762907)*M1OFL_Control_DW.Fxcontroller_DSTATE_h[1]
      + (0.11154561057231037)*M1OFL_Control_DW.Fxcontroller_DSTATE_h[2];
    xnew[1] += (0.0042956013256257343)*rtb_LC2CG2[0];
    xnew[2] = (1.0)*M1OFL_Control_DW.Fxcontroller_DSTATE_h[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG2[0];
    (void) memcpy(&M1OFL_Control_DW.Fxcontroller_DSTATE_h[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S3>/Fy controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.47684153921414885)*M1OFL_Control_DW.Fycontroller_DSTATE_a[0]
      + (0.68480541865093592)*M1OFL_Control_DW.Fycontroller_DSTATE_a[1]
      + (-0.051399221529844809)*M1OFL_Control_DW.Fycontroller_DSTATE_a[2];
    xnew[0] += (-0.0017355509321005055)*rtb_LC2CG2[1];
    xnew[1] = (-0.0016575308145891927)*M1OFL_Control_DW.Fycontroller_DSTATE_a[0]
      + (0.54422361645762907)*M1OFL_Control_DW.Fycontroller_DSTATE_a[1]
      + (0.11154561057231037)*M1OFL_Control_DW.Fycontroller_DSTATE_a[2];
    xnew[1] += (0.0042956013256257343)*rtb_LC2CG2[1];
    xnew[2] = (1.0)*M1OFL_Control_DW.Fycontroller_DSTATE_a[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG2[1];
    (void) memcpy(&M1OFL_Control_DW.Fycontroller_DSTATE_a[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S3>/Fz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.24588323456423122)*M1OFL_Control_DW.Fzcontroller_DSTATE_l[0]
      + (0.7046784245026928)*M1OFL_Control_DW.Fzcontroller_DSTATE_l[1]
      + (0.0010918487408774443)*M1OFL_Control_DW.Fzcontroller_DSTATE_l[2];
    xnew[0] += (0.00026134526724467871)*rtb_LC2CG2[2];
    xnew[1] = (-0.00064951930680838814)*M1OFL_Control_DW.Fzcontroller_DSTATE_l[0]
      + (0.28867118809350589)*M1OFL_Control_DW.Fzcontroller_DSTATE_l[1]
      + (0.15553729939777869)*M1OFL_Control_DW.Fzcontroller_DSTATE_l[2];
    xnew[1] += (0.0058792052074552442)*rtb_LC2CG2[2];
    xnew[2] = (1.0)*M1OFL_Control_DW.Fzcontroller_DSTATE_l[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG2[2];
    (void) memcpy(&M1OFL_Control_DW.Fzcontroller_DSTATE_l[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S3>/Mx controller' */
  {
    real_T xnew[5];

    {
      static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = M1OFL_Control_ConstP.pooled10;
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_o[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 4;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    xnew[0] += (-0.0036100737148655128)*rtb_LC2CG2[3];

    {
      static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA5 = &M1OFL_Control_ConstP.pooled10[5];
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_o[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 4;
      *pxnew1 = (*pA5++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA5++) * xd[*pAidx++];
      }
    }

    xnew[1] += (0.0028052699927021453)*rtb_LC2CG2[3];

    {
      static const int_T colAidxRow2[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA10 = &M1OFL_Control_ConstP.pooled10[10];
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_o[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 4;
      *pxnew2 = (*pA10++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA10++) * xd[*pAidx++];
      }
    }

    xnew[2] += (0.00059969188090775545)*rtb_LC2CG2[3];

    {
      static const int_T colAidxRow3[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA15 = &M1OFL_Control_ConstP.pooled10[15];
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_o[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 4;
      *pxnew3 = (*pA15++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA15++) * xd[*pAidx++];
      }
    }

    xnew[3] += (0.000550854762514463)*rtb_LC2CG2[3];
    xnew[4] = (1.0)*M1OFL_Control_DW.Mxcontroller_DSTATE_o[4];
    xnew[4] += (0.039999999999999994)*rtb_LC2CG2[3];
    (void) memcpy(&M1OFL_Control_DW.Mxcontroller_DSTATE_o[0], xnew,
                  sizeof(real_T)*5);
  }

  /* Update for DiscreteStateSpace: '<S3>/My controller' */
  {
    real_T xnew[5];

    {
      static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = M1OFL_Control_ConstP.pooled10;
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_p[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 4;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    xnew[0] += (-0.0036100737148655128)*rtb_LC2CG2[4];

    {
      static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA5 = &M1OFL_Control_ConstP.pooled10[5];
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_p[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 4;
      *pxnew1 = (*pA5++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA5++) * xd[*pAidx++];
      }
    }

    xnew[1] += (0.0028052699927021453)*rtb_LC2CG2[4];

    {
      static const int_T colAidxRow2[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA10 = &M1OFL_Control_ConstP.pooled10[10];
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_p[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 4;
      *pxnew2 = (*pA10++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA10++) * xd[*pAidx++];
      }
    }

    xnew[2] += (0.00059969188090775545)*rtb_LC2CG2[4];

    {
      static const int_T colAidxRow3[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA15 = &M1OFL_Control_ConstP.pooled10[15];
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_p[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 4;
      *pxnew3 = (*pA15++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA15++) * xd[*pAidx++];
      }
    }

    xnew[3] += (0.000550854762514463)*rtb_LC2CG2[4];
    xnew[4] = (1.0)*M1OFL_Control_DW.Mycontroller_DSTATE_p[4];
    xnew[4] += (0.039999999999999994)*rtb_LC2CG2[4];
    (void) memcpy(&M1OFL_Control_DW.Mycontroller_DSTATE_p[0], xnew,
                  sizeof(real_T)*5);
  }

  /* Update for DiscreteStateSpace: '<S3>/Mz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.027853439610535102)*M1OFL_Control_DW.Mzcontroller_DSTATE_k[0]
      + (0.4384495239533896)*M1OFL_Control_DW.Mzcontroller_DSTATE_k[1]
      + (0.05976437398581852)*M1OFL_Control_DW.Mzcontroller_DSTATE_k[2];
    xnew[0] += (0.0022548103799476128)*rtb_LC2CG2[5];
    xnew[1] = (0.025863212654755947)*M1OFL_Control_DW.Mzcontroller_DSTATE_k[0]
      + (0.70999971403230988)*M1OFL_Control_DW.Mzcontroller_DSTATE_k[1]
      + (-0.121271115438719)*M1OFL_Control_DW.Mzcontroller_DSTATE_k[2];
    xnew[1] += (-0.0047377249105599022)*rtb_LC2CG2[5];
    xnew[2] = (1.0)*M1OFL_Control_DW.Mzcontroller_DSTATE_k[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG2[5];
    (void) memcpy(&M1OFL_Control_DW.Mzcontroller_DSTATE_k[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteTransferFcn: '<S1>/SA Dynamics - S2' */
  for (k = 0; k < 6; k++) {
    memOffset_tmp = k << 1;
    M1OFL_Control_DW.SADynamicsS2_states[memOffset_tmp - -1] =
      M1OFL_Control_DW.SADynamicsS2_states[memOffset_tmp];
    M1OFL_Control_DW.SADynamicsS2_states[memOffset_tmp] = SADynamicsS2_tmp[k];
  }

  /* End of Update for DiscreteTransferFcn: '<S1>/SA Dynamics - S2' */

  /* Update for DiscreteStateSpace: '<S4>/Fx controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.47684153921414885)*M1OFL_Control_DW.Fxcontroller_DSTATE_o[0]
      + (0.68480541865093592)*M1OFL_Control_DW.Fxcontroller_DSTATE_o[1]
      + (-0.051399221529844809)*M1OFL_Control_DW.Fxcontroller_DSTATE_o[2];
    xnew[0] += (-0.0017355509321005055)*rtb_LC2CG3[0];
    xnew[1] = (-0.0016575308145891927)*M1OFL_Control_DW.Fxcontroller_DSTATE_o[0]
      + (0.54422361645762907)*M1OFL_Control_DW.Fxcontroller_DSTATE_o[1]
      + (0.11154561057231037)*M1OFL_Control_DW.Fxcontroller_DSTATE_o[2];
    xnew[1] += (0.0042956013256257343)*rtb_LC2CG3[0];
    xnew[2] = (1.0)*M1OFL_Control_DW.Fxcontroller_DSTATE_o[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG3[0];
    (void) memcpy(&M1OFL_Control_DW.Fxcontroller_DSTATE_o[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S4>/Fy controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.47684153921414885)*M1OFL_Control_DW.Fycontroller_DSTATE_h[0]
      + (0.68480541865093592)*M1OFL_Control_DW.Fycontroller_DSTATE_h[1]
      + (-0.051399221529844809)*M1OFL_Control_DW.Fycontroller_DSTATE_h[2];
    xnew[0] += (-0.0017355509321005055)*rtb_LC2CG3[1];
    xnew[1] = (-0.0016575308145891927)*M1OFL_Control_DW.Fycontroller_DSTATE_h[0]
      + (0.54422361645762907)*M1OFL_Control_DW.Fycontroller_DSTATE_h[1]
      + (0.11154561057231037)*M1OFL_Control_DW.Fycontroller_DSTATE_h[2];
    xnew[1] += (0.0042956013256257343)*rtb_LC2CG3[1];
    xnew[2] = (1.0)*M1OFL_Control_DW.Fycontroller_DSTATE_h[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG3[1];
    (void) memcpy(&M1OFL_Control_DW.Fycontroller_DSTATE_h[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S4>/Fz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.24588323456423122)*M1OFL_Control_DW.Fzcontroller_DSTATE_n[0]
      + (0.7046784245026928)*M1OFL_Control_DW.Fzcontroller_DSTATE_n[1]
      + (0.0010918487408774443)*M1OFL_Control_DW.Fzcontroller_DSTATE_n[2];
    xnew[0] += (0.00026134526724467871)*rtb_LC2CG3[2];
    xnew[1] = (-0.00064951930680838814)*M1OFL_Control_DW.Fzcontroller_DSTATE_n[0]
      + (0.28867118809350589)*M1OFL_Control_DW.Fzcontroller_DSTATE_n[1]
      + (0.15553729939777869)*M1OFL_Control_DW.Fzcontroller_DSTATE_n[2];
    xnew[1] += (0.0058792052074552442)*rtb_LC2CG3[2];
    xnew[2] = (1.0)*M1OFL_Control_DW.Fzcontroller_DSTATE_n[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG3[2];
    (void) memcpy(&M1OFL_Control_DW.Fzcontroller_DSTATE_n[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S4>/Mx controller' */
  {
    real_T xnew[5];

    {
      static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = M1OFL_Control_ConstP.pooled10;
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_l[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 4;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    xnew[0] += (-0.0036100737148655128)*rtb_LC2CG3[3];

    {
      static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA5 = &M1OFL_Control_ConstP.pooled10[5];
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_l[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 4;
      *pxnew1 = (*pA5++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA5++) * xd[*pAidx++];
      }
    }

    xnew[1] += (0.0028052699927021453)*rtb_LC2CG3[3];

    {
      static const int_T colAidxRow2[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA10 = &M1OFL_Control_ConstP.pooled10[10];
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_l[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 4;
      *pxnew2 = (*pA10++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA10++) * xd[*pAidx++];
      }
    }

    xnew[2] += (0.00059969188090775545)*rtb_LC2CG3[3];

    {
      static const int_T colAidxRow3[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA15 = &M1OFL_Control_ConstP.pooled10[15];
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_l[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 4;
      *pxnew3 = (*pA15++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA15++) * xd[*pAidx++];
      }
    }

    xnew[3] += (0.000550854762514463)*rtb_LC2CG3[3];
    xnew[4] = (1.0)*M1OFL_Control_DW.Mxcontroller_DSTATE_l[4];
    xnew[4] += (0.039999999999999994)*rtb_LC2CG3[3];
    (void) memcpy(&M1OFL_Control_DW.Mxcontroller_DSTATE_l[0], xnew,
                  sizeof(real_T)*5);
  }

  /* Update for DiscreteStateSpace: '<S4>/My controller' */
  {
    real_T xnew[5];

    {
      static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = M1OFL_Control_ConstP.pooled10;
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_d[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 4;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    xnew[0] += (-0.0036100737148655128)*rtb_LC2CG3[4];

    {
      static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA5 = &M1OFL_Control_ConstP.pooled10[5];
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_d[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 4;
      *pxnew1 = (*pA5++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA5++) * xd[*pAidx++];
      }
    }

    xnew[1] += (0.0028052699927021453)*rtb_LC2CG3[4];

    {
      static const int_T colAidxRow2[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA10 = &M1OFL_Control_ConstP.pooled10[10];
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_d[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 4;
      *pxnew2 = (*pA10++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA10++) * xd[*pAidx++];
      }
    }

    xnew[2] += (0.00059969188090775545)*rtb_LC2CG3[4];

    {
      static const int_T colAidxRow3[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA15 = &M1OFL_Control_ConstP.pooled10[15];
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_d[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 4;
      *pxnew3 = (*pA15++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA15++) * xd[*pAidx++];
      }
    }

    xnew[3] += (0.000550854762514463)*rtb_LC2CG3[4];
    xnew[4] = (1.0)*M1OFL_Control_DW.Mycontroller_DSTATE_d[4];
    xnew[4] += (0.039999999999999994)*rtb_LC2CG3[4];
    (void) memcpy(&M1OFL_Control_DW.Mycontroller_DSTATE_d[0], xnew,
                  sizeof(real_T)*5);
  }

  /* Update for DiscreteStateSpace: '<S4>/Mz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.027853439610535102)*M1OFL_Control_DW.Mzcontroller_DSTATE_a[0]
      + (0.4384495239533896)*M1OFL_Control_DW.Mzcontroller_DSTATE_a[1]
      + (0.05976437398581852)*M1OFL_Control_DW.Mzcontroller_DSTATE_a[2];
    xnew[0] += (0.0022548103799476128)*rtb_LC2CG3[5];
    xnew[1] = (0.025863212654755947)*M1OFL_Control_DW.Mzcontroller_DSTATE_a[0]
      + (0.70999971403230988)*M1OFL_Control_DW.Mzcontroller_DSTATE_a[1]
      + (-0.121271115438719)*M1OFL_Control_DW.Mzcontroller_DSTATE_a[2];
    xnew[1] += (-0.0047377249105599022)*rtb_LC2CG3[5];
    xnew[2] = (1.0)*M1OFL_Control_DW.Mzcontroller_DSTATE_a[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG3[5];
    (void) memcpy(&M1OFL_Control_DW.Mzcontroller_DSTATE_a[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteTransferFcn: '<S1>/SA Dynamics - S3' */
  for (k = 0; k < 6; k++) {
    memOffset_tmp = k << 1;
    M1OFL_Control_DW.SADynamicsS3_states[memOffset_tmp - -1] =
      M1OFL_Control_DW.SADynamicsS3_states[memOffset_tmp];
    M1OFL_Control_DW.SADynamicsS3_states[memOffset_tmp] = SADynamicsS3_tmp[k];
  }

  /* End of Update for DiscreteTransferFcn: '<S1>/SA Dynamics - S3' */

  /* Update for DiscreteStateSpace: '<S5>/Fx controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.47684153921414885)*M1OFL_Control_DW.Fxcontroller_DSTATE_i[0]
      + (0.68480541865093592)*M1OFL_Control_DW.Fxcontroller_DSTATE_i[1]
      + (-0.051399221529844809)*M1OFL_Control_DW.Fxcontroller_DSTATE_i[2];
    xnew[0] += (-0.0017355509321005055)*rtb_LC2CG4[0];
    xnew[1] = (-0.0016575308145891927)*M1OFL_Control_DW.Fxcontroller_DSTATE_i[0]
      + (0.54422361645762907)*M1OFL_Control_DW.Fxcontroller_DSTATE_i[1]
      + (0.11154561057231037)*M1OFL_Control_DW.Fxcontroller_DSTATE_i[2];
    xnew[1] += (0.0042956013256257343)*rtb_LC2CG4[0];
    xnew[2] = (1.0)*M1OFL_Control_DW.Fxcontroller_DSTATE_i[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG4[0];
    (void) memcpy(&M1OFL_Control_DW.Fxcontroller_DSTATE_i[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S5>/Fy controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.47684153921414885)*M1OFL_Control_DW.Fycontroller_DSTATE_n[0]
      + (0.68480541865093592)*M1OFL_Control_DW.Fycontroller_DSTATE_n[1]
      + (-0.051399221529844809)*M1OFL_Control_DW.Fycontroller_DSTATE_n[2];
    xnew[0] += (-0.0017355509321005055)*rtb_LC2CG4[1];
    xnew[1] = (-0.0016575308145891927)*M1OFL_Control_DW.Fycontroller_DSTATE_n[0]
      + (0.54422361645762907)*M1OFL_Control_DW.Fycontroller_DSTATE_n[1]
      + (0.11154561057231037)*M1OFL_Control_DW.Fycontroller_DSTATE_n[2];
    xnew[1] += (0.0042956013256257343)*rtb_LC2CG4[1];
    xnew[2] = (1.0)*M1OFL_Control_DW.Fycontroller_DSTATE_n[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG4[1];
    (void) memcpy(&M1OFL_Control_DW.Fycontroller_DSTATE_n[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S5>/Fz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.24588323456423122)*M1OFL_Control_DW.Fzcontroller_DSTATE_f[0]
      + (0.7046784245026928)*M1OFL_Control_DW.Fzcontroller_DSTATE_f[1]
      + (0.0010918487408774443)*M1OFL_Control_DW.Fzcontroller_DSTATE_f[2];
    xnew[0] += (0.00026134526724467871)*rtb_LC2CG4[2];
    xnew[1] = (-0.00064951930680838814)*M1OFL_Control_DW.Fzcontroller_DSTATE_f[0]
      + (0.28867118809350589)*M1OFL_Control_DW.Fzcontroller_DSTATE_f[1]
      + (0.15553729939777869)*M1OFL_Control_DW.Fzcontroller_DSTATE_f[2];
    xnew[1] += (0.0058792052074552442)*rtb_LC2CG4[2];
    xnew[2] = (1.0)*M1OFL_Control_DW.Fzcontroller_DSTATE_f[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG4[2];
    (void) memcpy(&M1OFL_Control_DW.Fzcontroller_DSTATE_f[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S5>/Mx controller' */
  {
    real_T xnew[5];

    {
      static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = M1OFL_Control_ConstP.pooled10;
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_k[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 4;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    xnew[0] += (-0.0036100737148655128)*rtb_LC2CG4[3];

    {
      static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA5 = &M1OFL_Control_ConstP.pooled10[5];
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_k[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 4;
      *pxnew1 = (*pA5++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA5++) * xd[*pAidx++];
      }
    }

    xnew[1] += (0.0028052699927021453)*rtb_LC2CG4[3];

    {
      static const int_T colAidxRow2[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA10 = &M1OFL_Control_ConstP.pooled10[10];
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_k[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 4;
      *pxnew2 = (*pA10++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA10++) * xd[*pAidx++];
      }
    }

    xnew[2] += (0.00059969188090775545)*rtb_LC2CG4[3];

    {
      static const int_T colAidxRow3[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA15 = &M1OFL_Control_ConstP.pooled10[15];
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_k[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 4;
      *pxnew3 = (*pA15++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA15++) * xd[*pAidx++];
      }
    }

    xnew[3] += (0.000550854762514463)*rtb_LC2CG4[3];
    xnew[4] = (1.0)*M1OFL_Control_DW.Mxcontroller_DSTATE_k[4];
    xnew[4] += (0.039999999999999994)*rtb_LC2CG4[3];
    (void) memcpy(&M1OFL_Control_DW.Mxcontroller_DSTATE_k[0], xnew,
                  sizeof(real_T)*5);
  }

  /* Update for DiscreteStateSpace: '<S5>/My controller' */
  {
    real_T xnew[5];

    {
      static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = M1OFL_Control_ConstP.pooled10;
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_pv[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 4;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    xnew[0] += (-0.0036100737148655128)*rtb_LC2CG4[4];

    {
      static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA5 = &M1OFL_Control_ConstP.pooled10[5];
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_pv[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 4;
      *pxnew1 = (*pA5++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA5++) * xd[*pAidx++];
      }
    }

    xnew[1] += (0.0028052699927021453)*rtb_LC2CG4[4];

    {
      static const int_T colAidxRow2[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA10 = &M1OFL_Control_ConstP.pooled10[10];
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_pv[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 4;
      *pxnew2 = (*pA10++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA10++) * xd[*pAidx++];
      }
    }

    xnew[2] += (0.00059969188090775545)*rtb_LC2CG4[4];

    {
      static const int_T colAidxRow3[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA15 = &M1OFL_Control_ConstP.pooled10[15];
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_pv[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 4;
      *pxnew3 = (*pA15++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA15++) * xd[*pAidx++];
      }
    }

    xnew[3] += (0.000550854762514463)*rtb_LC2CG4[4];
    xnew[4] = (1.0)*M1OFL_Control_DW.Mycontroller_DSTATE_pv[4];
    xnew[4] += (0.039999999999999994)*rtb_LC2CG4[4];
    (void) memcpy(&M1OFL_Control_DW.Mycontroller_DSTATE_pv[0], xnew,
                  sizeof(real_T)*5);
  }

  /* Update for DiscreteStateSpace: '<S5>/Mz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.027853439610535102)*M1OFL_Control_DW.Mzcontroller_DSTATE_ka[0]
      + (0.4384495239533896)*M1OFL_Control_DW.Mzcontroller_DSTATE_ka[1]
      + (0.05976437398581852)*M1OFL_Control_DW.Mzcontroller_DSTATE_ka[2];
    xnew[0] += (0.0022548103799476128)*rtb_LC2CG4[5];
    xnew[1] = (0.025863212654755947)*M1OFL_Control_DW.Mzcontroller_DSTATE_ka[0]
      + (0.70999971403230988)*M1OFL_Control_DW.Mzcontroller_DSTATE_ka[1]
      + (-0.121271115438719)*M1OFL_Control_DW.Mzcontroller_DSTATE_ka[2];
    xnew[1] += (-0.0047377249105599022)*rtb_LC2CG4[5];
    xnew[2] = (1.0)*M1OFL_Control_DW.Mzcontroller_DSTATE_ka[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG4[5];
    (void) memcpy(&M1OFL_Control_DW.Mzcontroller_DSTATE_ka[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteTransferFcn: '<S1>/SA Dynamics - S4' */
  for (k = 0; k < 6; k++) {
    memOffset_tmp = k << 1;
    M1OFL_Control_DW.SADynamicsS4_states[memOffset_tmp - -1] =
      M1OFL_Control_DW.SADynamicsS4_states[memOffset_tmp];
    M1OFL_Control_DW.SADynamicsS4_states[memOffset_tmp] = SADynamicsS4_tmp[k];
  }

  /* End of Update for DiscreteTransferFcn: '<S1>/SA Dynamics - S4' */

  /* Update for DiscreteStateSpace: '<S6>/Fx controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.47684153921414885)*M1OFL_Control_DW.Fxcontroller_DSTATE_j[0]
      + (0.68480541865093592)*M1OFL_Control_DW.Fxcontroller_DSTATE_j[1]
      + (-0.051399221529844809)*M1OFL_Control_DW.Fxcontroller_DSTATE_j[2];
    xnew[0] += (-0.0017355509321005055)*rtb_LC2CG5[0];
    xnew[1] = (-0.0016575308145891927)*M1OFL_Control_DW.Fxcontroller_DSTATE_j[0]
      + (0.54422361645762907)*M1OFL_Control_DW.Fxcontroller_DSTATE_j[1]
      + (0.11154561057231037)*M1OFL_Control_DW.Fxcontroller_DSTATE_j[2];
    xnew[1] += (0.0042956013256257343)*rtb_LC2CG5[0];
    xnew[2] = (1.0)*M1OFL_Control_DW.Fxcontroller_DSTATE_j[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG5[0];
    (void) memcpy(&M1OFL_Control_DW.Fxcontroller_DSTATE_j[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S6>/Fy controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.47684153921414885)*M1OFL_Control_DW.Fycontroller_DSTATE_k[0]
      + (0.68480541865093592)*M1OFL_Control_DW.Fycontroller_DSTATE_k[1]
      + (-0.051399221529844809)*M1OFL_Control_DW.Fycontroller_DSTATE_k[2];
    xnew[0] += (-0.0017355509321005055)*rtb_LC2CG5[1];
    xnew[1] = (-0.0016575308145891927)*M1OFL_Control_DW.Fycontroller_DSTATE_k[0]
      + (0.54422361645762907)*M1OFL_Control_DW.Fycontroller_DSTATE_k[1]
      + (0.11154561057231037)*M1OFL_Control_DW.Fycontroller_DSTATE_k[2];
    xnew[1] += (0.0042956013256257343)*rtb_LC2CG5[1];
    xnew[2] = (1.0)*M1OFL_Control_DW.Fycontroller_DSTATE_k[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG5[1];
    (void) memcpy(&M1OFL_Control_DW.Fycontroller_DSTATE_k[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S6>/Fz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.24588323456423122)*M1OFL_Control_DW.Fzcontroller_DSTATE_f2[0]
      + (0.7046784245026928)*M1OFL_Control_DW.Fzcontroller_DSTATE_f2[1]
      + (0.0010918487408774443)*M1OFL_Control_DW.Fzcontroller_DSTATE_f2[2];
    xnew[0] += (0.00026134526724467871)*rtb_LC2CG5[2];
    xnew[1] = (-0.00064951930680838814)*M1OFL_Control_DW.Fzcontroller_DSTATE_f2
      [0]
      + (0.28867118809350589)*M1OFL_Control_DW.Fzcontroller_DSTATE_f2[1]
      + (0.15553729939777869)*M1OFL_Control_DW.Fzcontroller_DSTATE_f2[2];
    xnew[1] += (0.0058792052074552442)*rtb_LC2CG5[2];
    xnew[2] = (1.0)*M1OFL_Control_DW.Fzcontroller_DSTATE_f2[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG5[2];
    (void) memcpy(&M1OFL_Control_DW.Fzcontroller_DSTATE_f2[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S6>/Mx controller' */
  {
    real_T xnew[5];

    {
      static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = M1OFL_Control_ConstP.pooled10;
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_d[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 4;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    xnew[0] += (-0.0036100737148655128)*rtb_LC2CG5[3];

    {
      static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA5 = &M1OFL_Control_ConstP.pooled10[5];
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_d[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 4;
      *pxnew1 = (*pA5++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA5++) * xd[*pAidx++];
      }
    }

    xnew[1] += (0.0028052699927021453)*rtb_LC2CG5[3];

    {
      static const int_T colAidxRow2[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA10 = &M1OFL_Control_ConstP.pooled10[10];
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_d[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 4;
      *pxnew2 = (*pA10++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA10++) * xd[*pAidx++];
      }
    }

    xnew[2] += (0.00059969188090775545)*rtb_LC2CG5[3];

    {
      static const int_T colAidxRow3[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA15 = &M1OFL_Control_ConstP.pooled10[15];
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_d[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 4;
      *pxnew3 = (*pA15++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA15++) * xd[*pAidx++];
      }
    }

    xnew[3] += (0.000550854762514463)*rtb_LC2CG5[3];
    xnew[4] = (1.0)*M1OFL_Control_DW.Mxcontroller_DSTATE_d[4];
    xnew[4] += (0.039999999999999994)*rtb_LC2CG5[3];
    (void) memcpy(&M1OFL_Control_DW.Mxcontroller_DSTATE_d[0], xnew,
                  sizeof(real_T)*5);
  }

  /* Update for DiscreteStateSpace: '<S6>/My controller' */
  {
    real_T xnew[5];

    {
      static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = M1OFL_Control_ConstP.pooled10;
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_f[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 4;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    xnew[0] += (-0.0036100737148655128)*rtb_LC2CG5[4];

    {
      static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA5 = &M1OFL_Control_ConstP.pooled10[5];
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_f[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 4;
      *pxnew1 = (*pA5++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA5++) * xd[*pAidx++];
      }
    }

    xnew[1] += (0.0028052699927021453)*rtb_LC2CG5[4];

    {
      static const int_T colAidxRow2[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA10 = &M1OFL_Control_ConstP.pooled10[10];
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_f[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 4;
      *pxnew2 = (*pA10++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA10++) * xd[*pAidx++];
      }
    }

    xnew[2] += (0.00059969188090775545)*rtb_LC2CG5[4];

    {
      static const int_T colAidxRow3[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA15 = &M1OFL_Control_ConstP.pooled10[15];
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_f[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 4;
      *pxnew3 = (*pA15++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA15++) * xd[*pAidx++];
      }
    }

    xnew[3] += (0.000550854762514463)*rtb_LC2CG5[4];
    xnew[4] = (1.0)*M1OFL_Control_DW.Mycontroller_DSTATE_f[4];
    xnew[4] += (0.039999999999999994)*rtb_LC2CG5[4];
    (void) memcpy(&M1OFL_Control_DW.Mycontroller_DSTATE_f[0], xnew,
                  sizeof(real_T)*5);
  }

  /* Update for DiscreteStateSpace: '<S6>/Mz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.027853439610535102)*M1OFL_Control_DW.Mzcontroller_DSTATE_f[0]
      + (0.4384495239533896)*M1OFL_Control_DW.Mzcontroller_DSTATE_f[1]
      + (0.05976437398581852)*M1OFL_Control_DW.Mzcontroller_DSTATE_f[2];
    xnew[0] += (0.0022548103799476128)*rtb_LC2CG5[5];
    xnew[1] = (0.025863212654755947)*M1OFL_Control_DW.Mzcontroller_DSTATE_f[0]
      + (0.70999971403230988)*M1OFL_Control_DW.Mzcontroller_DSTATE_f[1]
      + (-0.121271115438719)*M1OFL_Control_DW.Mzcontroller_DSTATE_f[2];
    xnew[1] += (-0.0047377249105599022)*rtb_LC2CG5[5];
    xnew[2] = (1.0)*M1OFL_Control_DW.Mzcontroller_DSTATE_f[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG5[5];
    (void) memcpy(&M1OFL_Control_DW.Mzcontroller_DSTATE_f[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteTransferFcn: '<S1>/SA Dynamics - S5' */
  for (k = 0; k < 6; k++) {
    memOffset_tmp = k << 1;
    M1OFL_Control_DW.SADynamicsS5_states[memOffset_tmp - -1] =
      M1OFL_Control_DW.SADynamicsS5_states[memOffset_tmp];
    M1OFL_Control_DW.SADynamicsS5_states[memOffset_tmp] = SADynamicsS5_tmp[k];
  }

  /* End of Update for DiscreteTransferFcn: '<S1>/SA Dynamics - S5' */

  /* Update for DiscreteStateSpace: '<S7>/Fx controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.47684153921414885)*M1OFL_Control_DW.Fxcontroller_DSTATE_d[0]
      + (0.68480541865093592)*M1OFL_Control_DW.Fxcontroller_DSTATE_d[1]
      + (-0.051399221529844809)*M1OFL_Control_DW.Fxcontroller_DSTATE_d[2];
    xnew[0] += (-0.0017355509321005055)*rtb_LC2CG6[0];
    xnew[1] = (-0.0016575308145891927)*M1OFL_Control_DW.Fxcontroller_DSTATE_d[0]
      + (0.54422361645762907)*M1OFL_Control_DW.Fxcontroller_DSTATE_d[1]
      + (0.11154561057231037)*M1OFL_Control_DW.Fxcontroller_DSTATE_d[2];
    xnew[1] += (0.0042956013256257343)*rtb_LC2CG6[0];
    xnew[2] = (1.0)*M1OFL_Control_DW.Fxcontroller_DSTATE_d[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG6[0];
    (void) memcpy(&M1OFL_Control_DW.Fxcontroller_DSTATE_d[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S7>/Fy controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.47684153921414885)*M1OFL_Control_DW.Fycontroller_DSTATE_i[0]
      + (0.68480541865093592)*M1OFL_Control_DW.Fycontroller_DSTATE_i[1]
      + (-0.051399221529844809)*M1OFL_Control_DW.Fycontroller_DSTATE_i[2];
    xnew[0] += (-0.0017355509321005055)*rtb_LC2CG6[1];
    xnew[1] = (-0.0016575308145891927)*M1OFL_Control_DW.Fycontroller_DSTATE_i[0]
      + (0.54422361645762907)*M1OFL_Control_DW.Fycontroller_DSTATE_i[1]
      + (0.11154561057231037)*M1OFL_Control_DW.Fycontroller_DSTATE_i[2];
    xnew[1] += (0.0042956013256257343)*rtb_LC2CG6[1];
    xnew[2] = (1.0)*M1OFL_Control_DW.Fycontroller_DSTATE_i[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG6[1];
    (void) memcpy(&M1OFL_Control_DW.Fycontroller_DSTATE_i[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S7>/Fz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.24588323456423122)*M1OFL_Control_DW.Fzcontroller_DSTATE_b[0]
      + (0.7046784245026928)*M1OFL_Control_DW.Fzcontroller_DSTATE_b[1]
      + (0.0010918487408774443)*M1OFL_Control_DW.Fzcontroller_DSTATE_b[2];
    xnew[0] += (0.00026134526724467871)*rtb_LC2CG6[2];
    xnew[1] = (-0.00064951930680838814)*M1OFL_Control_DW.Fzcontroller_DSTATE_b[0]
      + (0.28867118809350589)*M1OFL_Control_DW.Fzcontroller_DSTATE_b[1]
      + (0.15553729939777869)*M1OFL_Control_DW.Fzcontroller_DSTATE_b[2];
    xnew[1] += (0.0058792052074552442)*rtb_LC2CG6[2];
    xnew[2] = (1.0)*M1OFL_Control_DW.Fzcontroller_DSTATE_b[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG6[2];
    (void) memcpy(&M1OFL_Control_DW.Fzcontroller_DSTATE_b[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S7>/Mx controller' */
  {
    real_T xnew[5];

    {
      static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = M1OFL_Control_ConstP.pooled10;
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_m[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 4;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    xnew[0] += (-0.0036100737148655128)*rtb_LC2CG6[3];

    {
      static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA5 = &M1OFL_Control_ConstP.pooled10[5];
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_m[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 4;
      *pxnew1 = (*pA5++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA5++) * xd[*pAidx++];
      }
    }

    xnew[1] += (0.0028052699927021453)*rtb_LC2CG6[3];

    {
      static const int_T colAidxRow2[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA10 = &M1OFL_Control_ConstP.pooled10[10];
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_m[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 4;
      *pxnew2 = (*pA10++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA10++) * xd[*pAidx++];
      }
    }

    xnew[2] += (0.00059969188090775545)*rtb_LC2CG6[3];

    {
      static const int_T colAidxRow3[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA15 = &M1OFL_Control_ConstP.pooled10[15];
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_m[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 4;
      *pxnew3 = (*pA15++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA15++) * xd[*pAidx++];
      }
    }

    xnew[3] += (0.000550854762514463)*rtb_LC2CG6[3];
    xnew[4] = (1.0)*M1OFL_Control_DW.Mxcontroller_DSTATE_m[4];
    xnew[4] += (0.039999999999999994)*rtb_LC2CG6[3];
    (void) memcpy(&M1OFL_Control_DW.Mxcontroller_DSTATE_m[0], xnew,
                  sizeof(real_T)*5);
  }

  /* Update for DiscreteStateSpace: '<S7>/My controller' */
  {
    real_T xnew[5];

    {
      static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = M1OFL_Control_ConstP.pooled10;
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_b[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 4;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    xnew[0] += (-0.0036100737148655128)*rtb_LC2CG6[4];

    {
      static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA5 = &M1OFL_Control_ConstP.pooled10[5];
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_b[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 4;
      *pxnew1 = (*pA5++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA5++) * xd[*pAidx++];
      }
    }

    xnew[1] += (0.0028052699927021453)*rtb_LC2CG6[4];

    {
      static const int_T colAidxRow2[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA10 = &M1OFL_Control_ConstP.pooled10[10];
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_b[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 4;
      *pxnew2 = (*pA10++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA10++) * xd[*pAidx++];
      }
    }

    xnew[2] += (0.00059969188090775545)*rtb_LC2CG6[4];

    {
      static const int_T colAidxRow3[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA15 = &M1OFL_Control_ConstP.pooled10[15];
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_b[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 4;
      *pxnew3 = (*pA15++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA15++) * xd[*pAidx++];
      }
    }

    xnew[3] += (0.000550854762514463)*rtb_LC2CG6[4];
    xnew[4] = (1.0)*M1OFL_Control_DW.Mycontroller_DSTATE_b[4];
    xnew[4] += (0.039999999999999994)*rtb_LC2CG6[4];
    (void) memcpy(&M1OFL_Control_DW.Mycontroller_DSTATE_b[0], xnew,
                  sizeof(real_T)*5);
  }

  /* Update for DiscreteStateSpace: '<S7>/Mz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.027853439610535102)*M1OFL_Control_DW.Mzcontroller_DSTATE_kn[0]
      + (0.4384495239533896)*M1OFL_Control_DW.Mzcontroller_DSTATE_kn[1]
      + (0.05976437398581852)*M1OFL_Control_DW.Mzcontroller_DSTATE_kn[2];
    xnew[0] += (0.0022548103799476128)*rtb_LC2CG6[5];
    xnew[1] = (0.025863212654755947)*M1OFL_Control_DW.Mzcontroller_DSTATE_kn[0]
      + (0.70999971403230988)*M1OFL_Control_DW.Mzcontroller_DSTATE_kn[1]
      + (-0.121271115438719)*M1OFL_Control_DW.Mzcontroller_DSTATE_kn[2];
    xnew[1] += (-0.0047377249105599022)*rtb_LC2CG6[5];
    xnew[2] = (1.0)*M1OFL_Control_DW.Mzcontroller_DSTATE_kn[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG6[5];
    (void) memcpy(&M1OFL_Control_DW.Mzcontroller_DSTATE_kn[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteTransferFcn: '<S1>/SA Dynamics - S6' */
  for (k = 0; k < 6; k++) {
    memOffset_tmp = k << 1;
    M1OFL_Control_DW.SADynamicsS6_states[memOffset_tmp - -1] =
      M1OFL_Control_DW.SADynamicsS6_states[memOffset_tmp];
    M1OFL_Control_DW.SADynamicsS6_states[memOffset_tmp] = SADynamicsS6_tmp[k];
  }

  /* End of Update for DiscreteTransferFcn: '<S1>/SA Dynamics - S6' */

  /* Update for DiscreteStateSpace: '<S8>/Fx controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.47684153921414885)*M1OFL_Control_DW.Fxcontroller_DSTATE_b[0]
      + (0.68480541865093592)*M1OFL_Control_DW.Fxcontroller_DSTATE_b[1]
      + (-0.051399221529844809)*M1OFL_Control_DW.Fxcontroller_DSTATE_b[2];
    xnew[0] += (-0.0017355509321005055)*rtb_LC2CG7[0];
    xnew[1] = (-0.0016575308145891927)*M1OFL_Control_DW.Fxcontroller_DSTATE_b[0]
      + (0.54422361645762907)*M1OFL_Control_DW.Fxcontroller_DSTATE_b[1]
      + (0.11154561057231037)*M1OFL_Control_DW.Fxcontroller_DSTATE_b[2];
    xnew[1] += (0.0042956013256257343)*rtb_LC2CG7[0];
    xnew[2] = (1.0)*M1OFL_Control_DW.Fxcontroller_DSTATE_b[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG7[0];
    (void) memcpy(&M1OFL_Control_DW.Fxcontroller_DSTATE_b[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S8>/Fy controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.47684153921414885)*M1OFL_Control_DW.Fycontroller_DSTATE_nj[0]
      + (0.68480541865093592)*M1OFL_Control_DW.Fycontroller_DSTATE_nj[1]
      + (-0.051399221529844809)*M1OFL_Control_DW.Fycontroller_DSTATE_nj[2];
    xnew[0] += (-0.0017355509321005055)*rtb_LC2CG7[1];
    xnew[1] = (-0.0016575308145891927)*M1OFL_Control_DW.Fycontroller_DSTATE_nj[0]
      + (0.54422361645762907)*M1OFL_Control_DW.Fycontroller_DSTATE_nj[1]
      + (0.11154561057231037)*M1OFL_Control_DW.Fycontroller_DSTATE_nj[2];
    xnew[1] += (0.0042956013256257343)*rtb_LC2CG7[1];
    xnew[2] = (1.0)*M1OFL_Control_DW.Fycontroller_DSTATE_nj[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG7[1];
    (void) memcpy(&M1OFL_Control_DW.Fycontroller_DSTATE_nj[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S8>/Fz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.24588323456423122)*M1OFL_Control_DW.Fzcontroller_DSTATE_c[0]
      + (0.7046784245026928)*M1OFL_Control_DW.Fzcontroller_DSTATE_c[1]
      + (0.0010918487408774443)*M1OFL_Control_DW.Fzcontroller_DSTATE_c[2];
    xnew[0] += (0.00026134526724467871)*rtb_LC2CG7[2];
    xnew[1] = (-0.00064951930680838814)*M1OFL_Control_DW.Fzcontroller_DSTATE_c[0]
      + (0.28867118809350589)*M1OFL_Control_DW.Fzcontroller_DSTATE_c[1]
      + (0.15553729939777869)*M1OFL_Control_DW.Fzcontroller_DSTATE_c[2];
    xnew[1] += (0.0058792052074552442)*rtb_LC2CG7[2];
    xnew[2] = (1.0)*M1OFL_Control_DW.Fzcontroller_DSTATE_c[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG7[2];
    (void) memcpy(&M1OFL_Control_DW.Fzcontroller_DSTATE_c[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S8>/Mx controller' */
  {
    real_T xnew[5];

    {
      static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = M1OFL_Control_ConstP.pooled10;
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_i[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 4;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    xnew[0] += (-0.0036100737148655128)*rtb_LC2CG7[3];

    {
      static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA5 = &M1OFL_Control_ConstP.pooled10[5];
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_i[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 4;
      *pxnew1 = (*pA5++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA5++) * xd[*pAidx++];
      }
    }

    xnew[1] += (0.0028052699927021453)*rtb_LC2CG7[3];

    {
      static const int_T colAidxRow2[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA10 = &M1OFL_Control_ConstP.pooled10[10];
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_i[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 4;
      *pxnew2 = (*pA10++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA10++) * xd[*pAidx++];
      }
    }

    xnew[2] += (0.00059969188090775545)*rtb_LC2CG7[3];

    {
      static const int_T colAidxRow3[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA15 = &M1OFL_Control_ConstP.pooled10[15];
      const real_T *xd = &M1OFL_Control_DW.Mxcontroller_DSTATE_i[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 4;
      *pxnew3 = (*pA15++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA15++) * xd[*pAidx++];
      }
    }

    xnew[3] += (0.000550854762514463)*rtb_LC2CG7[3];
    xnew[4] = (1.0)*M1OFL_Control_DW.Mxcontroller_DSTATE_i[4];
    xnew[4] += (0.039999999999999994)*rtb_LC2CG7[3];
    (void) memcpy(&M1OFL_Control_DW.Mxcontroller_DSTATE_i[0], xnew,
                  sizeof(real_T)*5);
  }

  /* Update for DiscreteStateSpace: '<S8>/My controller' */
  {
    real_T xnew[5];

    {
      static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = M1OFL_Control_ConstP.pooled10;
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_o[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 4;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    xnew[0] += (-0.0036100737148655128)*rtb_LC2CG7[4];

    {
      static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA5 = &M1OFL_Control_ConstP.pooled10[5];
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_o[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 4;
      *pxnew1 = (*pA5++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA5++) * xd[*pAidx++];
      }
    }

    xnew[1] += (0.0028052699927021453)*rtb_LC2CG7[4];

    {
      static const int_T colAidxRow2[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA10 = &M1OFL_Control_ConstP.pooled10[10];
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_o[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 4;
      *pxnew2 = (*pA10++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA10++) * xd[*pAidx++];
      }
    }

    xnew[2] += (0.00059969188090775545)*rtb_LC2CG7[4];

    {
      static const int_T colAidxRow3[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA15 = &M1OFL_Control_ConstP.pooled10[15];
      const real_T *xd = &M1OFL_Control_DW.Mycontroller_DSTATE_o[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 4;
      *pxnew3 = (*pA15++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA15++) * xd[*pAidx++];
      }
    }

    xnew[3] += (0.000550854762514463)*rtb_LC2CG7[4];
    xnew[4] = (1.0)*M1OFL_Control_DW.Mycontroller_DSTATE_o[4];
    xnew[4] += (0.039999999999999994)*rtb_LC2CG7[4];
    (void) memcpy(&M1OFL_Control_DW.Mycontroller_DSTATE_o[0], xnew,
                  sizeof(real_T)*5);
  }

  /* Update for DiscreteStateSpace: '<S8>/Mz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.027853439610535102)*M1OFL_Control_DW.Mzcontroller_DSTATE_i[0]
      + (0.4384495239533896)*M1OFL_Control_DW.Mzcontroller_DSTATE_i[1]
      + (0.05976437398581852)*M1OFL_Control_DW.Mzcontroller_DSTATE_i[2];
    xnew[0] += (0.0022548103799476128)*rtb_LC2CG7[5];
    xnew[1] = (0.025863212654755947)*M1OFL_Control_DW.Mzcontroller_DSTATE_i[0]
      + (0.70999971403230988)*M1OFL_Control_DW.Mzcontroller_DSTATE_i[1]
      + (-0.121271115438719)*M1OFL_Control_DW.Mzcontroller_DSTATE_i[2];
    xnew[1] += (-0.0047377249105599022)*rtb_LC2CG7[5];
    xnew[2] = (1.0)*M1OFL_Control_DW.Mzcontroller_DSTATE_i[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG7[5];
    (void) memcpy(&M1OFL_Control_DW.Mzcontroller_DSTATE_i[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteTransferFcn: '<S1>/SA Dynamics - S7' */
  for (k = 0; k < 6; k++) {
    memOffset_tmp = k << 1;
    M1OFL_Control_DW.SADynamicsS7_states[memOffset_tmp - -1] =
      M1OFL_Control_DW.SADynamicsS7_states[memOffset_tmp];
    M1OFL_Control_DW.SADynamicsS7_states[memOffset_tmp] = SADynamicsS7_tmp[k];
  }

  /* End of Update for DiscreteTransferFcn: '<S1>/SA Dynamics - S7' */
}

/* Model initialize function */
void M1OFL_Control_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(M1OFL_Control_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&M1OFL_Control_DW, 0,
                sizeof(DW_M1OFL_Control_T));

  /* external inputs */
  (void)memset(&M1OFL_Control_U, 0, sizeof(ExtU_M1OFL_Control_T));

  /* external outputs */
  (void) memset(&M1OFL_Control_Y.M1_Rel_F[0], 0,
                42U*sizeof(real_T));
}

/* Model terminate function */
void M1OFL_Control_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
