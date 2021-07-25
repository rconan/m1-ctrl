/*
 * File: M1SA_F_Control_OA.c
 *
 * Code generated for Simulink model 'M1SA_F_Control_OA'.
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

#include "M1SA_F_Control_OA.h"
#include "M1SA_F_Control_OA_private.h"

/* Block states (default storage) */
DW_M1SA_F_Control_OA_T M1SA_F_Control_OA_DW;

/* External inputs (root inport signals with default storage) */
ExtU_M1SA_F_Control_OA_T M1SA_F_Control_OA_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_M1SA_F_Control_OA_T M1SA_F_Control_OA_Y;

/* Real-time model */
RT_MODEL_M1SA_F_Control_OA_T M1SA_F_Control_OA_M_;
RT_MODEL_M1SA_F_Control_OA_T *const M1SA_F_Control_OA_M = &M1SA_F_Control_OA_M_;

/* Model step function */
void M1SA_F_Control_OA_step(void)
{
  /* local block i/o variables */
  real_T rtb_LC2CG[6];
  real_T rtb_Fxcontroller;
  real_T rtb_Fycontroller;
  real_T rtb_Fzcontroller;
  real_T rtb_Mxcontroller;
  real_T rtb_Mycontroller;
  real_T rtb_Mzcontroller;
  int32_T k;
  real_T denAccum;
  real_T rtb_TmpSignalConversionAtSADynamicsS1Inport1[6];
  real_T rtb_SADynamics[27];
  real_T rtb_SADynamicsS1[6];
  real_T tmp[335];
  real_T tmp_0[335];
  int32_T i;
  real_T SADynamics_tmp[27];
  real_T SADynamicsS1_tmp[6];
  real_T denAccum_tmp;
  int32_T memOffset_tmp;

  /* DiscreteTransferFcn: '<S1>/SA Dynamics' incorporates:
   *  Inport: '<Root>/BM_cmd'
   */
  for (k = 0; k < 27; k++) {
    memOffset_tmp = k << 1;
    denAccum_tmp = M1SA_F_Control_OA_DW.SADynamics_states[memOffset_tmp + 1];
    denAccum = (M1SA_F_Control_OA_U.BM_cmd[k] - -0.77932227475069393 *
                M1SA_F_Control_OA_DW.SADynamics_states[memOffset_tmp]) -
      denAccum_tmp * 0.15183580198064905;
    SADynamics_tmp[k] = denAccum;
    denAccum *= 0.094481844738029327;
    denAccum += 0.24121577940998443 *
      M1SA_F_Control_OA_DW.SADynamics_states[memOffset_tmp];
    rtb_SADynamics[k] = denAccum_tmp * 0.036815903081941416 + denAccum;
  }

  /* End of DiscreteTransferFcn: '<S1>/SA Dynamics' */

  /* Gain: '<S1>/LC2CG' incorporates:
   *  Inport: '<Root>/HP_LC'
   */
  for (k = 0; k < 6; k++) {
    rtb_LC2CG[k] = 0.0;
    memOffset_tmp = 0;
    for (i = 0; i < 6; i++) {
      rtb_LC2CG[k] += M1SA_F_Control_OA_ConstP.LC2CG_Gain[memOffset_tmp + k] *
        M1SA_F_Control_OA_U.HP_LC[i];
      memOffset_tmp += 6;
    }
  }

  /* End of Gain: '<S1>/LC2CG' */

  /* DiscreteStateSpace: '<S2>/Fx controller' */
  {
    rtb_Fxcontroller = (6.5598720805159942)*
      M1SA_F_Control_OA_DW.Fxcontroller_DSTATE[0]
      + (-5.94467376914989)*M1SA_F_Control_OA_DW.Fxcontroller_DSTATE[1]
      + (1.5)*M1SA_F_Control_OA_DW.Fxcontroller_DSTATE[2];
    rtb_Fxcontroller += 0.0205612224491055*rtb_LC2CG[0];
  }

  /* DiscreteStateSpace: '<S2>/Fy controller' */
  {
    rtb_Fycontroller = (6.5598720805159942)*
      M1SA_F_Control_OA_DW.Fycontroller_DSTATE[0]
      + (-5.94467376914989)*M1SA_F_Control_OA_DW.Fycontroller_DSTATE[1]
      + (1.5)*M1SA_F_Control_OA_DW.Fycontroller_DSTATE[2];
    rtb_Fycontroller += 0.0205612224491055*rtb_LC2CG[1];
  }

  /* DiscreteStateSpace: '<S2>/Fz controller' */
  {
    rtb_Fzcontroller = (11.530556837169614)*
      M1SA_F_Control_OA_DW.Fzcontroller_DSTATE[0]
      + (-10.851053072456448)*M1SA_F_Control_OA_DW.Fzcontroller_DSTATE[1]
      + (2.5)*M1SA_F_Control_OA_DW.Fzcontroller_DSTATE[2];
    rtb_Fzcontroller += 0.027443636441156067*rtb_LC2CG[2];
  }

  /* DiscreteStateSpace: '<S2>/Mx controller' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = M1SA_F_Control_OA_ConstP.pooled10;
      const real_T *xd = &M1SA_F_Control_OA_DW.Mxcontroller_DSTATE[0];
      real_T *y0 = &rtb_Mxcontroller;
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_Mxcontroller += 0.01117010856270375*rtb_LC2CG[3];
  }

  /* DiscreteStateSpace: '<S2>/My controller' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = M1SA_F_Control_OA_ConstP.pooled10;
      const real_T *xd = &M1SA_F_Control_OA_DW.Mycontroller_DSTATE[0];
      real_T *y0 = &rtb_Mycontroller;
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_Mycontroller += 0.01117010856270375*rtb_LC2CG[4];
  }

  /* DiscreteStateSpace: '<S2>/Mz controller' */
  {
    rtb_Mzcontroller = (-20.532898991147984)*
      M1SA_F_Control_OA_DW.Mzcontroller_DSTATE[0]
      + (6.3249300064723526)*M1SA_F_Control_OA_DW.Mzcontroller_DSTATE[1]
      + (2.5)*M1SA_F_Control_OA_DW.Mzcontroller_DSTATE[2];
    rtb_Mzcontroller += 0.019188774883241673*rtb_LC2CG[5];
  }

  /* SignalConversion: '<S1>/TmpSignal ConversionAtSA Dynamics - S1Inport1' */
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[0] = rtb_Fxcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[1] = rtb_Fycontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[2] = rtb_Fzcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[3] = rtb_Mxcontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[4] = rtb_Mycontroller;
  rtb_TmpSignalConversionAtSADynamicsS1Inport1[5] = rtb_Mzcontroller;

  /* DiscreteTransferFcn: '<S1>/SA Dynamics - S1' */
  for (k = 0; k < 6; k++) {
    memOffset_tmp = k << 1;
    denAccum_tmp = M1SA_F_Control_OA_DW.SADynamicsS1_states[memOffset_tmp + 1];
    denAccum = (rtb_TmpSignalConversionAtSADynamicsS1Inport1[k] -
                -0.77932227475069393 *
                M1SA_F_Control_OA_DW.SADynamicsS1_states[memOffset_tmp]) -
      denAccum_tmp * 0.15183580198064905;
    SADynamicsS1_tmp[k] = denAccum;
    denAccum *= 0.094481844738029327;
    denAccum += 0.24121577940998443 *
      M1SA_F_Control_OA_DW.SADynamicsS1_states[memOffset_tmp];
    rtb_SADynamicsS1[k] = denAccum_tmp * 0.036815903081941416 + denAccum;
  }

  /* End of DiscreteTransferFcn: '<S1>/SA Dynamics - S1' */
  for (k = 0; k < 335; k++) {
    /* Gain: '<S1>/Force balance S1' */
    tmp[k] = 0.0;
    for (memOffset_tmp = 0; memOffset_tmp < 6; memOffset_tmp++) {
      tmp[k] += M1SA_F_Control_OA_ConstP.ForcebalanceS1_Gain[335 * memOffset_tmp
        + k] * rtb_SADynamicsS1[memOffset_tmp];
    }

    /* End of Gain: '<S1>/Force balance S1' */

    /* Gain: '<S1>/BM2Forces' */
    tmp_0[k] = 0.0;
    for (memOffset_tmp = 0; memOffset_tmp < 27; memOffset_tmp++) {
      tmp_0[k] += M1SA_F_Control_OA_ConstP.BM2Forces_Gain[335 * memOffset_tmp +
        k] * rtb_SADynamics[memOffset_tmp];
    }

    /* End of Gain: '<S1>/BM2Forces' */

    /* Outport: '<Root>/M1_ACT_F' incorporates:
     *  Sum: '<S1>/Add'
     */
    M1SA_F_Control_OA_Y.M1_ACT_F[k] = tmp[k] + tmp_0[k];
  }

  /* Update for DiscreteTransferFcn: '<S1>/SA Dynamics' */
  for (k = 0; k < 27; k++) {
    memOffset_tmp = k << 1;
    M1SA_F_Control_OA_DW.SADynamics_states[memOffset_tmp - -1] =
      M1SA_F_Control_OA_DW.SADynamics_states[memOffset_tmp];
    M1SA_F_Control_OA_DW.SADynamics_states[memOffset_tmp] = SADynamics_tmp[k];
  }

  /* End of Update for DiscreteTransferFcn: '<S1>/SA Dynamics' */

  /* Update for DiscreteStateSpace: '<S2>/Fx controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.47684153921414885)*M1SA_F_Control_OA_DW.Fxcontroller_DSTATE[0]
      + (0.68480541865093592)*M1SA_F_Control_OA_DW.Fxcontroller_DSTATE[1]
      + (-0.051399221529844809)*M1SA_F_Control_OA_DW.Fxcontroller_DSTATE[2];
    xnew[0] += (-0.0017355509321005055)*rtb_LC2CG[0];
    xnew[1] = (-0.0016575308145891927)*M1SA_F_Control_OA_DW.Fxcontroller_DSTATE
      [0]
      + (0.54422361645762907)*M1SA_F_Control_OA_DW.Fxcontroller_DSTATE[1]
      + (0.11154561057231037)*M1SA_F_Control_OA_DW.Fxcontroller_DSTATE[2];
    xnew[1] += (0.0042956013256257343)*rtb_LC2CG[0];
    xnew[2] = (1.0)*M1SA_F_Control_OA_DW.Fxcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG[0];
    (void) memcpy(&M1SA_F_Control_OA_DW.Fxcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Fy controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.47684153921414885)*M1SA_F_Control_OA_DW.Fycontroller_DSTATE[0]
      + (0.68480541865093592)*M1SA_F_Control_OA_DW.Fycontroller_DSTATE[1]
      + (-0.051399221529844809)*M1SA_F_Control_OA_DW.Fycontroller_DSTATE[2];
    xnew[0] += (-0.0017355509321005055)*rtb_LC2CG[1];
    xnew[1] = (-0.0016575308145891927)*M1SA_F_Control_OA_DW.Fycontroller_DSTATE
      [0]
      + (0.54422361645762907)*M1SA_F_Control_OA_DW.Fycontroller_DSTATE[1]
      + (0.11154561057231037)*M1SA_F_Control_OA_DW.Fycontroller_DSTATE[2];
    xnew[1] += (0.0042956013256257343)*rtb_LC2CG[1];
    xnew[2] = (1.0)*M1SA_F_Control_OA_DW.Fycontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG[1];
    (void) memcpy(&M1SA_F_Control_OA_DW.Fycontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Fz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.24588323456423122)*M1SA_F_Control_OA_DW.Fzcontroller_DSTATE[0]
      + (0.7046784245026928)*M1SA_F_Control_OA_DW.Fzcontroller_DSTATE[1]
      + (0.0010918487408774443)*M1SA_F_Control_OA_DW.Fzcontroller_DSTATE[2];
    xnew[0] += (0.00026134526724467871)*rtb_LC2CG[2];
    xnew[1] = (-0.00064951930680838814)*
      M1SA_F_Control_OA_DW.Fzcontroller_DSTATE[0]
      + (0.28867118809350589)*M1SA_F_Control_OA_DW.Fzcontroller_DSTATE[1]
      + (0.15553729939777869)*M1SA_F_Control_OA_DW.Fzcontroller_DSTATE[2];
    xnew[1] += (0.0058792052074552442)*rtb_LC2CG[2];
    xnew[2] = (1.0)*M1SA_F_Control_OA_DW.Fzcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG[2];
    (void) memcpy(&M1SA_F_Control_OA_DW.Fzcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Mx controller' */
  {
    real_T xnew[5];

    {
      static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = M1SA_F_Control_OA_ConstP.pooled8;
      const real_T *xd = &M1SA_F_Control_OA_DW.Mxcontroller_DSTATE[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 4;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    xnew[0] += (-0.0036100737148655128)*rtb_LC2CG[3];

    {
      static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA5 = &M1SA_F_Control_OA_ConstP.pooled8[5];
      const real_T *xd = &M1SA_F_Control_OA_DW.Mxcontroller_DSTATE[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 4;
      *pxnew1 = (*pA5++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA5++) * xd[*pAidx++];
      }
    }

    xnew[1] += (0.0028052699927021453)*rtb_LC2CG[3];

    {
      static const int_T colAidxRow2[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA10 = &M1SA_F_Control_OA_ConstP.pooled8[10];
      const real_T *xd = &M1SA_F_Control_OA_DW.Mxcontroller_DSTATE[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 4;
      *pxnew2 = (*pA10++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA10++) * xd[*pAidx++];
      }
    }

    xnew[2] += (0.00059969188090775545)*rtb_LC2CG[3];

    {
      static const int_T colAidxRow3[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA15 = &M1SA_F_Control_OA_ConstP.pooled8[15];
      const real_T *xd = &M1SA_F_Control_OA_DW.Mxcontroller_DSTATE[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 4;
      *pxnew3 = (*pA15++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA15++) * xd[*pAidx++];
      }
    }

    xnew[3] += (0.000550854762514463)*rtb_LC2CG[3];
    xnew[4] = (1.0)*M1SA_F_Control_OA_DW.Mxcontroller_DSTATE[4];
    xnew[4] += (0.039999999999999994)*rtb_LC2CG[3];
    (void) memcpy(&M1SA_F_Control_OA_DW.Mxcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*5);
  }

  /* Update for DiscreteStateSpace: '<S2>/My controller' */
  {
    real_T xnew[5];

    {
      static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = M1SA_F_Control_OA_ConstP.pooled8;
      const real_T *xd = &M1SA_F_Control_OA_DW.Mycontroller_DSTATE[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 4;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    xnew[0] += (-0.0036100737148655128)*rtb_LC2CG[4];

    {
      static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA5 = &M1SA_F_Control_OA_ConstP.pooled8[5];
      const real_T *xd = &M1SA_F_Control_OA_DW.Mycontroller_DSTATE[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 4;
      *pxnew1 = (*pA5++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA5++) * xd[*pAidx++];
      }
    }

    xnew[1] += (0.0028052699927021453)*rtb_LC2CG[4];

    {
      static const int_T colAidxRow2[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA10 = &M1SA_F_Control_OA_ConstP.pooled8[10];
      const real_T *xd = &M1SA_F_Control_OA_DW.Mycontroller_DSTATE[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 4;
      *pxnew2 = (*pA10++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA10++) * xd[*pAidx++];
      }
    }

    xnew[2] += (0.00059969188090775545)*rtb_LC2CG[4];

    {
      static const int_T colAidxRow3[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA15 = &M1SA_F_Control_OA_ConstP.pooled8[15];
      const real_T *xd = &M1SA_F_Control_OA_DW.Mycontroller_DSTATE[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 4;
      *pxnew3 = (*pA15++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA15++) * xd[*pAidx++];
      }
    }

    xnew[3] += (0.000550854762514463)*rtb_LC2CG[4];
    xnew[4] = (1.0)*M1SA_F_Control_OA_DW.Mycontroller_DSTATE[4];
    xnew[4] += (0.039999999999999994)*rtb_LC2CG[4];
    (void) memcpy(&M1SA_F_Control_OA_DW.Mycontroller_DSTATE[0], xnew,
                  sizeof(real_T)*5);
  }

  /* Update for DiscreteStateSpace: '<S2>/Mz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.027853439610535102)*M1SA_F_Control_OA_DW.Mzcontroller_DSTATE[0]
      + (0.4384495239533896)*M1SA_F_Control_OA_DW.Mzcontroller_DSTATE[1]
      + (0.05976437398581852)*M1SA_F_Control_OA_DW.Mzcontroller_DSTATE[2];
    xnew[0] += (0.0022548103799476128)*rtb_LC2CG[5];
    xnew[1] = (0.025863212654755947)*M1SA_F_Control_OA_DW.Mzcontroller_DSTATE[0]
      + (0.70999971403230988)*M1SA_F_Control_OA_DW.Mzcontroller_DSTATE[1]
      + (-0.121271115438719)*M1SA_F_Control_OA_DW.Mzcontroller_DSTATE[2];
    xnew[1] += (-0.0047377249105599022)*rtb_LC2CG[5];
    xnew[2] = (1.0)*M1SA_F_Control_OA_DW.Mzcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG[5];
    (void) memcpy(&M1SA_F_Control_OA_DW.Mzcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteTransferFcn: '<S1>/SA Dynamics - S1' */
  for (k = 0; k < 6; k++) {
    memOffset_tmp = k << 1;
    M1SA_F_Control_OA_DW.SADynamicsS1_states[memOffset_tmp - -1] =
      M1SA_F_Control_OA_DW.SADynamicsS1_states[memOffset_tmp];
    M1SA_F_Control_OA_DW.SADynamicsS1_states[memOffset_tmp] = SADynamicsS1_tmp[k];
  }

  /* End of Update for DiscreteTransferFcn: '<S1>/SA Dynamics - S1' */
}

/* Model initialize function */
void M1SA_F_Control_OA_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(M1SA_F_Control_OA_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&M1SA_F_Control_OA_DW, 0,
                sizeof(DW_M1SA_F_Control_OA_T));

  /* external inputs */
  (void)memset(&M1SA_F_Control_OA_U, 0, sizeof(ExtU_M1SA_F_Control_OA_T));

  /* external outputs */
  (void) memset(&M1SA_F_Control_OA_Y.M1_ACT_F[0], 0,
                335U*sizeof(real_T));
}

/* Model terminate function */
void M1SA_F_Control_OA_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
