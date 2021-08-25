/*
 * File: M1SA_F_Control_S7.c
 *
 * Code generated for Simulink model 'M1SA_F_Control_S7'.
 *
 * Model version                  : 1.763
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Aug 24 14:53:07 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "M1SA_F_Control_S7.h"
#include "M1SA_F_Control_S7_private.h"

/* Block states (default storage) */
DW_M1SA_F_Control_S7_T M1SA_F_Control_S7_DW;

/* External inputs (root inport signals with default storage) */
ExtU_M1SA_F_Control_S7_T M1SA_F_Control_S7_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_M1SA_F_Control_S7_T M1SA_F_Control_S7_Y;

/* Real-time model */
RT_MODEL_M1SA_F_Control_S7_T M1SA_F_Control_S7_M_;
RT_MODEL_M1SA_F_Control_S7_T *const M1SA_F_Control_S7_M = &M1SA_F_Control_S7_M_;

/* Model step function */
void M1SA_F_Control_S7_step(void)
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
  real_T rtb_TmpSignalConversionAtSADynamicsS7Inport1[6];
  real_T rtb_SADynamics[27];
  real_T rtb_SADynamicsS7[6];
  real_T tmp[306];
  real_T tmp_0[306];
  int32_T i;
  real_T SADynamics_tmp[27];
  real_T SADynamicsS7_tmp[6];
  real_T denAccum_tmp;
  int32_T memOffset_tmp;

  /* DiscreteTransferFcn: '<S1>/SA Dynamics' incorporates:
   *  Inport: '<Root>/BM_cmd'
   */
  for (k = 0; k < 27; k++) {
    memOffset_tmp = k << 1;
    denAccum_tmp = M1SA_F_Control_S7_DW.SADynamics_states[memOffset_tmp + 1];
    denAccum = (M1SA_F_Control_S7_U.BM_cmd[k] - -0.77932227475069393 *
                M1SA_F_Control_S7_DW.SADynamics_states[memOffset_tmp]) -
      denAccum_tmp * 0.15183580198064905;
    SADynamics_tmp[k] = denAccum;
    denAccum *= 0.094481844738029327;
    denAccum += 0.24121577940998443 *
      M1SA_F_Control_S7_DW.SADynamics_states[memOffset_tmp];
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
      rtb_LC2CG[k] += M1SA_F_Control_S7_ConstP.LC2CG_Gain[memOffset_tmp + k] *
        M1SA_F_Control_S7_U.HP_LC[i];
      memOffset_tmp += 6;
    }
  }

  /* End of Gain: '<S1>/LC2CG' */

  /* DiscreteStateSpace: '<S2>/Fx controller' */
  {
    rtb_Fxcontroller = (-4.8638195027756757)*
      M1SA_F_Control_S7_DW.Fxcontroller_DSTATE[0]
      + (5.7964459762938336)*M1SA_F_Control_S7_DW.Fxcontroller_DSTATE[1]
      + (1.8)*M1SA_F_Control_S7_DW.Fxcontroller_DSTATE[2];
    rtb_Fxcontroller += 0.029643056294262716*rtb_LC2CG[0];
  }

  /* DiscreteStateSpace: '<S2>/Fy controller' */
  {
    rtb_Fycontroller = (-4.8638195027756757)*
      M1SA_F_Control_S7_DW.Fycontroller_DSTATE[0]
      + (5.7964459762938336)*M1SA_F_Control_S7_DW.Fycontroller_DSTATE[1]
      + (1.8)*M1SA_F_Control_S7_DW.Fycontroller_DSTATE[2];
    rtb_Fycontroller += 0.029643056294262716*rtb_LC2CG[1];
  }

  /* DiscreteStateSpace: '<S2>/Fz controller' */
  {
    rtb_Fzcontroller = (-10.950108858889026)*
      M1SA_F_Control_S7_DW.Fzcontroller_DSTATE[0]
      + (14.571154350139892)*M1SA_F_Control_S7_DW.Fzcontroller_DSTATE[1]
      + (2.4)*M1SA_F_Control_S7_DW.Fzcontroller_DSTATE[2];
    rtb_Fzcontroller += 0.02565242923829485*rtb_LC2CG[2];
  }

  /* DiscreteStateSpace: '<S2>/Mx controller' */
  {
    rtb_Mxcontroller = (-10.04307867717106)*
      M1SA_F_Control_S7_DW.Mxcontroller_DSTATE[0]
      + (10.41998468921483)*M1SA_F_Control_S7_DW.Mxcontroller_DSTATE[1]
      + (2.0)*M1SA_F_Control_S7_DW.Mxcontroller_DSTATE[2];
    rtb_Mxcontroller += 0.024505707216075836*rtb_LC2CG[3];
  }

  /* DiscreteStateSpace: '<S2>/My controller' */
  {
    rtb_Mycontroller = (-8.9504417867707922)*
      M1SA_F_Control_S7_DW.Mycontroller_DSTATE[0]
      + (13.479205452131694)*M1SA_F_Control_S7_DW.Mycontroller_DSTATE[1]
      + (2.0)*M1SA_F_Control_S7_DW.Mycontroller_DSTATE[2];
    rtb_Mycontroller += 0.023081148046321883*rtb_LC2CG[4];
  }

  /* DiscreteStateSpace: '<S2>/Mz controller' */
  {
    rtb_Mzcontroller = (-9.4551745922133)*
      M1SA_F_Control_S7_DW.Mzcontroller_DSTATE[0]
      + (11.4653232391471)*M1SA_F_Control_S7_DW.Mzcontroller_DSTATE[1]
      + (2.0)*M1SA_F_Control_S7_DW.Mzcontroller_DSTATE[2];
    rtb_Mzcontroller += 0.022969235998287645*rtb_LC2CG[5];
  }

  /* SignalConversion: '<S1>/TmpSignal ConversionAtSA Dynamics - S7Inport1' */
  rtb_TmpSignalConversionAtSADynamicsS7Inport1[0] = rtb_Fxcontroller;
  rtb_TmpSignalConversionAtSADynamicsS7Inport1[1] = rtb_Fycontroller;
  rtb_TmpSignalConversionAtSADynamicsS7Inport1[2] = rtb_Fzcontroller;
  rtb_TmpSignalConversionAtSADynamicsS7Inport1[3] = rtb_Mxcontroller;
  rtb_TmpSignalConversionAtSADynamicsS7Inport1[4] = rtb_Mycontroller;
  rtb_TmpSignalConversionAtSADynamicsS7Inport1[5] = rtb_Mzcontroller;

  /* DiscreteTransferFcn: '<S1>/SA Dynamics - S7' */
  for (k = 0; k < 6; k++) {
    memOffset_tmp = k << 1;
    denAccum_tmp = M1SA_F_Control_S7_DW.SADynamicsS7_states[memOffset_tmp + 1];
    denAccum = (rtb_TmpSignalConversionAtSADynamicsS7Inport1[k] -
                -0.77932227475069393 *
                M1SA_F_Control_S7_DW.SADynamicsS7_states[memOffset_tmp]) -
      denAccum_tmp * 0.15183580198064905;
    SADynamicsS7_tmp[k] = denAccum;
    denAccum *= 0.094481844738029327;
    denAccum += 0.24121577940998443 *
      M1SA_F_Control_S7_DW.SADynamicsS7_states[memOffset_tmp];
    rtb_SADynamicsS7[k] = denAccum_tmp * 0.036815903081941416 + denAccum;
  }

  /* End of DiscreteTransferFcn: '<S1>/SA Dynamics - S7' */
  for (k = 0; k < 306; k++) {
    /* Gain: '<S1>/Force balance S7' */
    tmp[k] = 0.0;
    for (memOffset_tmp = 0; memOffset_tmp < 6; memOffset_tmp++) {
      tmp[k] += M1SA_F_Control_S7_ConstP.ForcebalanceS7_Gain[306 * memOffset_tmp
        + k] * rtb_SADynamicsS7[memOffset_tmp];
    }

    /* End of Gain: '<S1>/Force balance S7' */

    /* Gain: '<S1>/BM2Forces' */
    tmp_0[k] = 0.0;
    for (memOffset_tmp = 0; memOffset_tmp < 27; memOffset_tmp++) {
      tmp_0[k] += M1SA_F_Control_S7_ConstP.BM2Forces_Gain[306 * memOffset_tmp +
        k] * rtb_SADynamics[memOffset_tmp];
    }

    /* End of Gain: '<S1>/BM2Forces' */

    /* Outport: '<Root>/M1_ACT_F' incorporates:
     *  Sum: '<S1>/Add'
     */
    M1SA_F_Control_S7_Y.M1_ACT_F[k] = tmp[k] + tmp_0[k];
  }

  /* Update for DiscreteTransferFcn: '<S1>/SA Dynamics' */
  for (k = 0; k < 27; k++) {
    memOffset_tmp = k << 1;
    M1SA_F_Control_S7_DW.SADynamics_states[memOffset_tmp - -1] =
      M1SA_F_Control_S7_DW.SADynamics_states[memOffset_tmp];
    M1SA_F_Control_S7_DW.SADynamics_states[memOffset_tmp] = SADynamics_tmp[k];
  }

  /* End of Update for DiscreteTransferFcn: '<S1>/SA Dynamics' */

  /* Update for DiscreteStateSpace: '<S2>/Fx controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.63236929833750544)*M1SA_F_Control_S7_DW.Fxcontroller_DSTATE[0]
      + (-0.2314604952889496)*M1SA_F_Control_S7_DW.Fxcontroller_DSTATE[1]
      + (0.095986156740783091)*M1SA_F_Control_S7_DW.Fxcontroller_DSTATE[2];
    xnew[0] += (0.0037575554537456791)*rtb_LC2CG[0];
    xnew[1] = (0.68052710878128941)*M1SA_F_Control_S7_DW.Fxcontroller_DSTATE[0]
      + (0.55318897160816316)*M1SA_F_Control_S7_DW.Fxcontroller_DSTATE[1]
      + (-0.052209612755755933)*M1SA_F_Control_S7_DW.Fxcontroller_DSTATE[2];
    xnew[1] += (-0.0017928578591570792)*rtb_LC2CG[0];
    xnew[2] = (1.0)*M1SA_F_Control_S7_DW.Fxcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG[0];
    (void) memcpy(&M1SA_F_Control_S7_DW.Fxcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Fy controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.63236929833750544)*M1SA_F_Control_S7_DW.Fycontroller_DSTATE[0]
      + (-0.2314604952889496)*M1SA_F_Control_S7_DW.Fycontroller_DSTATE[1]
      + (0.095986156740783091)*M1SA_F_Control_S7_DW.Fycontroller_DSTATE[2];
    xnew[0] += (0.0037575554537456791)*rtb_LC2CG[1];
    xnew[1] = (0.68052710878128941)*M1SA_F_Control_S7_DW.Fycontroller_DSTATE[0]
      + (0.55318897160816316)*M1SA_F_Control_S7_DW.Fycontroller_DSTATE[1]
      + (-0.052209612755755933)*M1SA_F_Control_S7_DW.Fycontroller_DSTATE[2];
    xnew[1] += (-0.0017928578591570792)*rtb_LC2CG[1];
    xnew[2] = (1.0)*M1SA_F_Control_S7_DW.Fycontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG[1];
    (void) memcpy(&M1SA_F_Control_S7_DW.Fycontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Fz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.32224501051155652)*M1SA_F_Control_S7_DW.Fzcontroller_DSTATE[0]
      + (-0.013311547842537925)*M1SA_F_Control_S7_DW.Fzcontroller_DSTATE[1]
      + (0.13574136089816072)*M1SA_F_Control_S7_DW.Fzcontroller_DSTATE[2];
    xnew[0] += (0.0051358870792095942)*rtb_LC2CG[2];
    xnew[1] = (0.66124884843011622)*M1SA_F_Control_S7_DW.Fzcontroller_DSTATE[0]
      + (0.13460444259831872)*M1SA_F_Control_S7_DW.Fzcontroller_DSTATE[1]
      + (-0.0021534473090368935)*M1SA_F_Control_S7_DW.Fzcontroller_DSTATE[2];
    xnew[1] += (6.2267040787955009E-5)*rtb_LC2CG[2];
    xnew[2] = (1.0)*M1SA_F_Control_S7_DW.Fzcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG[2];
    (void) memcpy(&M1SA_F_Control_S7_DW.Fzcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Mx controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.29778010884776307)*M1SA_F_Control_S7_DW.Mxcontroller_DSTATE[0]
      + (0.71505921377142712)*M1SA_F_Control_S7_DW.Mxcontroller_DSTATE[1]
      + (-0.0021601236457374955)*M1SA_F_Control_S7_DW.Mxcontroller_DSTATE[2];
    xnew[0] += (-0.00026117608623345441)*rtb_LC2CG[3];
    xnew[1] = (-0.00024258661738509195)*
      M1SA_F_Control_S7_DW.Mxcontroller_DSTATE[0]
      + (0.27143897782429549)*M1SA_F_Control_S7_DW.Mxcontroller_DSTATE[1]
      + (-0.11649383326807114)*M1SA_F_Control_S7_DW.Mxcontroller_DSTATE[2];
    xnew[1] += (-0.0043992827840101858)*rtb_LC2CG[3];
    xnew[2] = (1.0)*M1SA_F_Control_S7_DW.Mxcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG[3];
    (void) memcpy(&M1SA_F_Control_S7_DW.Mxcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/My controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.33457623873733711)*M1SA_F_Control_S7_DW.Mycontroller_DSTATE[0]
      + (-0.02558128690243703)*M1SA_F_Control_S7_DW.Mycontroller_DSTATE[1]
      + (0.11711699668675964)*M1SA_F_Control_S7_DW.Mycontroller_DSTATE[2];
    xnew[0] += (0.004429681001502127)*rtb_LC2CG[4];
    xnew[1] = (0.627491662992475)*M1SA_F_Control_S7_DW.Mycontroller_DSTATE[0]
      + (0.081182913964186532)*M1SA_F_Control_S7_DW.Mycontroller_DSTATE[1]
      + (-0.0029828208753129326)*M1SA_F_Control_S7_DW.Mycontroller_DSTATE[2];
    xnew[1] += (-1.5627371761007224E-5)*rtb_LC2CG[4];
    xnew[2] = (1.0)*M1SA_F_Control_S7_DW.Mycontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG[4];
    (void) memcpy(&M1SA_F_Control_S7_DW.Mycontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Mz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.38195738947508884)*M1SA_F_Control_S7_DW.Mzcontroller_DSTATE[0]
      + (0.72039580968966876)*M1SA_F_Control_S7_DW.Mzcontroller_DSTATE[1]
      + (-0.0047245815737020904)*M1SA_F_Control_S7_DW.Mzcontroller_DSTATE[2];
    xnew[0] += (-0.00039049368346384173)*rtb_LC2CG[5];
    xnew[1] = (-0.0066509471364728252)*M1SA_F_Control_S7_DW.Mzcontroller_DSTATE
      [0]
      + (0.24351874678335261)*M1SA_F_Control_S7_DW.Mzcontroller_DSTATE[1]
      + (-0.12438032071830714)*M1SA_F_Control_S7_DW.Mzcontroller_DSTATE[2];
    xnew[1] += (-0.0046882022587151594)*rtb_LC2CG[5];
    xnew[2] = (1.0)*M1SA_F_Control_S7_DW.Mzcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG[5];
    (void) memcpy(&M1SA_F_Control_S7_DW.Mzcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteTransferFcn: '<S1>/SA Dynamics - S7' */
  for (k = 0; k < 6; k++) {
    memOffset_tmp = k << 1;
    M1SA_F_Control_S7_DW.SADynamicsS7_states[memOffset_tmp - -1] =
      M1SA_F_Control_S7_DW.SADynamicsS7_states[memOffset_tmp];
    M1SA_F_Control_S7_DW.SADynamicsS7_states[memOffset_tmp] = SADynamicsS7_tmp[k];
  }

  /* End of Update for DiscreteTransferFcn: '<S1>/SA Dynamics - S7' */
}

/* Model initialize function */
void M1SA_F_Control_S7_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(M1SA_F_Control_S7_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&M1SA_F_Control_S7_DW, 0,
                sizeof(DW_M1SA_F_Control_S7_T));

  /* external inputs */
  (void)memset(&M1SA_F_Control_S7_U, 0, sizeof(ExtU_M1SA_F_Control_S7_T));

  /* external outputs */
  (void) memset(&M1SA_F_Control_S7_Y.M1_ACT_F[0], 0,
                306U*sizeof(real_T));
}

/* Model terminate function */
void M1SA_F_Control_S7_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
