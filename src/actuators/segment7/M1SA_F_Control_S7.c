/*
 * File: M1SA_F_Control_S7.c
 *
 * Code generated for Simulink model 'M1SA_F_Control_S7'.
 *
 * Model version                  : 1.766
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Sep 20 17:25:16 2021
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
  real_T denAccum;
  real_T rtb_SADynamicsS7[306];
  real_T tmp[6];
  int32_T i;
  int32_T i_0;
  real_T SADynamicsS7_tmp[306];
  int32_T i_1;

  /* Gain: '<S1>/LC2CG' incorporates:
   *  Inport: '<Root>/HP_LC'
   */
  for (i = 0; i < 6; i++) {
    rtb_LC2CG[i] = 0.0;
    i_1 = 0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_LC2CG[i] += M1SA_F_Control_S7_ConstP.LC2CG_Gain[i_1 + i] *
        M1SA_F_Control_S7_U.HP_LC[i_0];
      i_1 += 6;
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
    rtb_Fzcontroller = (-11.547295552410962)*
      M1SA_F_Control_S7_DW.Fzcontroller_DSTATE[0]
      + (13.223093614673868)*M1SA_F_Control_S7_DW.Fzcontroller_DSTATE[1]
      + (2.4)*M1SA_F_Control_S7_DW.Fzcontroller_DSTATE[2];
    rtb_Fzcontroller += 0.026295028211970869*rtb_LC2CG[2];
  }

  /* DiscreteStateSpace: '<S2>/Mx controller' */
  {
    rtb_Mxcontroller = (10.799355933329354)*
      M1SA_F_Control_S7_DW.Mxcontroller_DSTATE[0]
      + (-10.162942348382657)*M1SA_F_Control_S7_DW.Mxcontroller_DSTATE[1]
      + (2.0)*M1SA_F_Control_S7_DW.Mxcontroller_DSTATE[2];
    rtb_Mxcontroller += 0.024170972941162154*rtb_LC2CG[3];
  }

  /* DiscreteStateSpace: '<S2>/My controller' */
  {
    rtb_Mycontroller = (10.799355933329354)*
      M1SA_F_Control_S7_DW.Mycontroller_DSTATE[0]
      + (-10.162942348382657)*M1SA_F_Control_S7_DW.Mycontroller_DSTATE[1]
      + (2.0)*M1SA_F_Control_S7_DW.Mycontroller_DSTATE[2];
    rtb_Mycontroller += 0.024170972941162154*rtb_LC2CG[4];
  }

  /* DiscreteStateSpace: '<S2>/Mz controller' */
  {
    rtb_Mzcontroller = (-9.8843504316129263)*
      M1SA_F_Control_S7_DW.Mzcontroller_DSTATE[0]
      + (11.363212843833221)*M1SA_F_Control_S7_DW.Mzcontroller_DSTATE[1]
      + (2.0)*M1SA_F_Control_S7_DW.Mzcontroller_DSTATE[2];
    rtb_Mzcontroller += 0.02274996590750189*rtb_LC2CG[5];
  }

  /* SignalConversion: '<S1>/TmpSignal ConversionAtForce balance S7Inport1' */
  tmp[0] = rtb_Fxcontroller;
  tmp[1] = rtb_Fycontroller;
  tmp[2] = rtb_Fzcontroller;
  tmp[3] = rtb_Mxcontroller;
  tmp[4] = rtb_Mycontroller;
  tmp[5] = rtb_Mzcontroller;
  for (i_0 = 0; i_0 < 306; i_0++) {
    /* Gain: '<S1>/Force balance S7' */
    rtb_SADynamicsS7[i_0] = 0.0;
    i = 0;
    for (i_1 = 0; i_1 < 6; i_1++) {
      rtb_SADynamicsS7[i_0] += M1SA_F_Control_S7_ConstP.ForcebalanceS7_Gain[i +
        i_0] * tmp[i_1];
      i += 306;
    }

    /* DiscreteTransferFcn: '<S1>/SA Dynamics - S7' incorporates:
     *  Gain: '<S1>/Force balance S7'
     *  Inport: '<Root>/SA_offsetF_cmd'
     *  Sum: '<S1>/Add'
     */
    denAccum = (rtb_SADynamicsS7[i_0] + M1SA_F_Control_S7_U.SA_offsetF_cmd[i_0])
      - -0.53348809109110329 * M1SA_F_Control_S7_DW.SADynamicsS7_states[i_0];
    SADynamicsS7_tmp[i_0] = denAccum;
    denAccum *= 0.25752323685913081;
    rtb_SADynamicsS7[i_0] = 0.20898867204976596 *
      M1SA_F_Control_S7_DW.SADynamicsS7_states[i_0] + denAccum;

    /* Outport: '<Root>/M1_ACT_F' incorporates:
     *  Gain: '<S1>/Force balance S7'
     */
    M1SA_F_Control_S7_Y.M1_ACT_F[i_0] = rtb_SADynamicsS7[i_0];
  }

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
    xnew[0] = (0.301067016055664)*M1SA_F_Control_S7_DW.Fzcontroller_DSTATE[0]
      + (-0.0031724351959647448)*M1SA_F_Control_S7_DW.Fzcontroller_DSTATE[1]
      + (0.13548158452421563)*M1SA_F_Control_S7_DW.Fzcontroller_DSTATE[2];
    xnew[0] += (0.0051238049410177334)*rtb_LC2CG[2];
    xnew[1] = (0.69313056645168969)*M1SA_F_Control_S7_DW.Fzcontroller_DSTATE[0]
      + (0.20728190413675973)*M1SA_F_Control_S7_DW.Fzcontroller_DSTATE[1]
      + (-0.00016908715632750395)*M1SA_F_Control_S7_DW.Fzcontroller_DSTATE[2];
    xnew[1] += (0.00017056109559295831)*rtb_LC2CG[2];
    xnew[2] = (1.0)*M1SA_F_Control_S7_DW.Fzcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG[2];
    (void) memcpy(&M1SA_F_Control_S7_DW.Fzcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Mx controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.24588323456423145)*M1SA_F_Control_S7_DW.Mxcontroller_DSTATE[0]
      + (0.70467842450269291)*M1SA_F_Control_S7_DW.Mxcontroller_DSTATE[1]
      + (0.00081808803127932854)*M1SA_F_Control_S7_DW.Mxcontroller_DSTATE[2];
    xnew[0] += (0.00019581781538031463)*rtb_LC2CG[3];
    xnew[1] = (-0.00064951930680839346)*
      M1SA_F_Control_S7_DW.Mxcontroller_DSTATE[0]
      + (0.28867118809350589)*M1SA_F_Control_S7_DW.Mxcontroller_DSTATE[1]
      + (0.11653922223015478)*M1SA_F_Control_S7_DW.Mxcontroller_DSTATE[2];
    xnew[1] += (0.0044051041445438335)*rtb_LC2CG[3];
    xnew[2] = (1.0)*M1SA_F_Control_S7_DW.Mxcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG[3];
    (void) memcpy(&M1SA_F_Control_S7_DW.Mxcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/My controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.24588323456423145)*M1SA_F_Control_S7_DW.Mycontroller_DSTATE[0]
      + (0.70467842450269291)*M1SA_F_Control_S7_DW.Mycontroller_DSTATE[1]
      + (0.00081808803127932854)*M1SA_F_Control_S7_DW.Mycontroller_DSTATE[2];
    xnew[0] += (0.00019581781538031463)*rtb_LC2CG[4];
    xnew[1] = (-0.00064951930680839346)*
      M1SA_F_Control_S7_DW.Mycontroller_DSTATE[0]
      + (0.28867118809350589)*M1SA_F_Control_S7_DW.Mycontroller_DSTATE[1]
      + (0.11653922223015478)*M1SA_F_Control_S7_DW.Mycontroller_DSTATE[2];
    xnew[1] += (0.0044051041445438335)*rtb_LC2CG[4];
    xnew[2] = (1.0)*M1SA_F_Control_S7_DW.Mycontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG[4];
    (void) memcpy(&M1SA_F_Control_S7_DW.Mycontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Mz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.35318690302308442)*M1SA_F_Control_S7_DW.Mzcontroller_DSTATE[0]
      + (0.72011465131225016)*M1SA_F_Control_S7_DW.Mzcontroller_DSTATE[1]
      + (-0.0038868874920811648)*M1SA_F_Control_S7_DW.Mzcontroller_DSTATE[2];
    xnew[0] += (-0.00035257232440118728)*rtb_LC2CG[5];
    xnew[1] = (-0.0034885015967498082)*M1SA_F_Control_S7_DW.Mzcontroller_DSTATE
      [0]
      + (0.25294477393664205)*M1SA_F_Control_S7_DW.Mzcontroller_DSTATE[1]
      + (-0.12437198598757729)*M1SA_F_Control_S7_DW.Mzcontroller_DSTATE[2];
    xnew[1] += (-0.0046911246844348262)*rtb_LC2CG[5];
    xnew[2] = (1.0)*M1SA_F_Control_S7_DW.Mzcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG[5];
    (void) memcpy(&M1SA_F_Control_S7_DW.Mzcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteTransferFcn: '<S1>/SA Dynamics - S7' */
  memcpy(&M1SA_F_Control_S7_DW.SADynamicsS7_states[0], &SADynamicsS7_tmp[0],
         306U * sizeof(real_T));
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
