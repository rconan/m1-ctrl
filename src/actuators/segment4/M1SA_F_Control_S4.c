/*
 * File: M1SA_F_Control_S4.c
 *
 * Code generated for Simulink model 'M1SA_F_Control_S4'.
 *
 * Model version                  : 1.766
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Sep 20 17:27:17 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "M1SA_F_Control_S4.h"
#include "M1SA_F_Control_S4_private.h"

/* Block states (default storage) */
DW_M1SA_F_Control_S4_T M1SA_F_Control_S4_DW;

/* External inputs (root inport signals with default storage) */
ExtU_M1SA_F_Control_S4_T M1SA_F_Control_S4_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_M1SA_F_Control_S4_T M1SA_F_Control_S4_Y;

/* Real-time model */
RT_MODEL_M1SA_F_Control_S4_T M1SA_F_Control_S4_M_;
RT_MODEL_M1SA_F_Control_S4_T *const M1SA_F_Control_S4_M = &M1SA_F_Control_S4_M_;

/* Model step function */
void M1SA_F_Control_S4_step(void)
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
  real_T rtb_SADynamicsS1[335];
  real_T tmp[6];
  int32_T i;
  int32_T i_0;
  real_T SADynamicsS1_tmp[335];
  int32_T i_1;

  /* Gain: '<S1>/LC2CG' incorporates:
   *  Inport: '<Root>/HP_LC'
   */
  for (i = 0; i < 6; i++) {
    rtb_LC2CG[i] = 0.0;
    i_1 = 0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_LC2CG[i] += M1SA_F_Control_S4_ConstP.LC2CG_Gain[i_1 + i] *
        M1SA_F_Control_S4_U.HP_LC[i_0];
      i_1 += 6;
    }
  }

  /* End of Gain: '<S1>/LC2CG' */

  /* DiscreteStateSpace: '<S2>/Fx controller' */
  {
    rtb_Fxcontroller = (5.5100401607158833)*
      M1SA_F_Control_S4_DW.Fxcontroller_DSTATE[0]
      + (-5.0303630344232824)*M1SA_F_Control_S4_DW.Fxcontroller_DSTATE[1]
      + (1.8)*M1SA_F_Control_S4_DW.Fxcontroller_DSTATE[2];
    rtb_Fxcontroller += 0.029786030929472216*rtb_LC2CG[0];
  }

  /* DiscreteStateSpace: '<S2>/Fy controller' */
  {
    rtb_Fycontroller = (5.5100401607158833)*
      M1SA_F_Control_S4_DW.Fycontroller_DSTATE[0]
      + (-5.0303630344232824)*M1SA_F_Control_S4_DW.Fycontroller_DSTATE[1]
      + (1.8)*M1SA_F_Control_S4_DW.Fycontroller_DSTATE[2];
    rtb_Fycontroller += 0.029786030929472216*rtb_LC2CG[1];
  }

  /* DiscreteStateSpace: '<S2>/Fz controller' */
  {
    rtb_Fzcontroller = (-10.950108858889026)*
      M1SA_F_Control_S4_DW.Fzcontroller_DSTATE[0]
      + (14.571154350139892)*M1SA_F_Control_S4_DW.Fzcontroller_DSTATE[1]
      + (2.4)*M1SA_F_Control_S4_DW.Fzcontroller_DSTATE[2];
    rtb_Fzcontroller += 0.02565242923829485*rtb_LC2CG[2];
  }

  /* DiscreteStateSpace: '<S2>/Mx controller' */
  {
    rtb_Mxcontroller = (-10.04307867717106)*
      M1SA_F_Control_S4_DW.Mxcontroller_DSTATE[0]
      + (10.41998468921483)*M1SA_F_Control_S4_DW.Mxcontroller_DSTATE[1]
      + (2.0)*M1SA_F_Control_S4_DW.Mxcontroller_DSTATE[2];
    rtb_Mxcontroller += 0.024505707216075836*rtb_LC2CG[3];
  }

  /* DiscreteStateSpace: '<S2>/My controller' */
  {
    rtb_Mycontroller = (-10.04307867717106)*
      M1SA_F_Control_S4_DW.Mycontroller_DSTATE[0]
      + (10.41998468921483)*M1SA_F_Control_S4_DW.Mycontroller_DSTATE[1]
      + (2.0)*M1SA_F_Control_S4_DW.Mycontroller_DSTATE[2];
    rtb_Mycontroller += 0.024505707216075836*rtb_LC2CG[4];
  }

  /* DiscreteStateSpace: '<S2>/Mz controller' */
  {
    rtb_Mzcontroller = (-9.4551745922133)*
      M1SA_F_Control_S4_DW.Mzcontroller_DSTATE[0]
      + (11.4653232391471)*M1SA_F_Control_S4_DW.Mzcontroller_DSTATE[1]
      + (2.0)*M1SA_F_Control_S4_DW.Mzcontroller_DSTATE[2];
    rtb_Mzcontroller += 0.022969235998287645*rtb_LC2CG[5];
  }

  /* SignalConversion: '<S1>/TmpSignal ConversionAtForce balance S1Inport1' */
  tmp[0] = rtb_Fxcontroller;
  tmp[1] = rtb_Fycontroller;
  tmp[2] = rtb_Fzcontroller;
  tmp[3] = rtb_Mxcontroller;
  tmp[4] = rtb_Mycontroller;
  tmp[5] = rtb_Mzcontroller;
  for (i_0 = 0; i_0 < 335; i_0++) {
    /* Gain: '<S1>/Force balance S1' */
    rtb_SADynamicsS1[i_0] = 0.0;
    i = 0;
    for (i_1 = 0; i_1 < 6; i_1++) {
      rtb_SADynamicsS1[i_0] += M1SA_F_Control_S4_ConstP.ForcebalanceS1_Gain[i +
        i_0] * tmp[i_1];
      i += 335;
    }

    /* DiscreteTransferFcn: '<S1>/SA Dynamics - S1' incorporates:
     *  Gain: '<S1>/Force balance S1'
     *  Inport: '<Root>/SA_offsetF_cmd'
     *  Sum: '<S1>/Add'
     */
    denAccum = (rtb_SADynamicsS1[i_0] + M1SA_F_Control_S4_U.SA_offsetF_cmd[i_0])
      - -0.53348809109110329 * M1SA_F_Control_S4_DW.SADynamicsS1_states[i_0];
    SADynamicsS1_tmp[i_0] = denAccum;
    denAccum *= 0.25752323685913081;
    rtb_SADynamicsS1[i_0] = 0.20898867204976596 *
      M1SA_F_Control_S4_DW.SADynamicsS1_states[i_0] + denAccum;

    /* Outport: '<Root>/M1_ACT_F' incorporates:
     *  Gain: '<S1>/Force balance S1'
     */
    M1SA_F_Control_S4_Y.M1_ACT_F[i_0] = rtb_SADynamicsS1[i_0];
  }

  /* Update for DiscreteStateSpace: '<S2>/Fx controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.58443008685641118)*M1SA_F_Control_S4_DW.Fxcontroller_DSTATE[0]
      + (0.67252934225212191)*M1SA_F_Control_S4_DW.Fxcontroller_DSTATE[1]
      + (-0.048965038524629384)*M1SA_F_Control_S4_DW.Fxcontroller_DSTATE[2];
    xnew[0] += (-0.0016734052711992048)*rtb_LC2CG[0];
    xnew[1] = (-0.2254136550158379)*M1SA_F_Control_S4_DW.Fxcontroller_DSTATE[0]
      + (0.62520960147916238)*M1SA_F_Control_S4_DW.Fxcontroller_DSTATE[1]
      + (0.096979099095789667)*M1SA_F_Control_S4_DW.Fxcontroller_DSTATE[2];
    xnew[1] += (0.0037906423432266163)*rtb_LC2CG[0];
    xnew[2] = (1.0)*M1SA_F_Control_S4_DW.Fxcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG[0];
    (void) memcpy(&M1SA_F_Control_S4_DW.Fxcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Fy controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.58443008685641118)*M1SA_F_Control_S4_DW.Fycontroller_DSTATE[0]
      + (0.67252934225212191)*M1SA_F_Control_S4_DW.Fycontroller_DSTATE[1]
      + (-0.048965038524629384)*M1SA_F_Control_S4_DW.Fycontroller_DSTATE[2];
    xnew[0] += (-0.0016734052711992048)*rtb_LC2CG[1];
    xnew[1] = (-0.2254136550158379)*M1SA_F_Control_S4_DW.Fycontroller_DSTATE[0]
      + (0.62520960147916238)*M1SA_F_Control_S4_DW.Fycontroller_DSTATE[1]
      + (0.096979099095789667)*M1SA_F_Control_S4_DW.Fycontroller_DSTATE[2];
    xnew[1] += (0.0037906423432266163)*rtb_LC2CG[1];
    xnew[2] = (1.0)*M1SA_F_Control_S4_DW.Fycontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG[1];
    (void) memcpy(&M1SA_F_Control_S4_DW.Fycontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Fz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.32224501051155652)*M1SA_F_Control_S4_DW.Fzcontroller_DSTATE[0]
      + (-0.013311547842537925)*M1SA_F_Control_S4_DW.Fzcontroller_DSTATE[1]
      + (0.13574136089816072)*M1SA_F_Control_S4_DW.Fzcontroller_DSTATE[2];
    xnew[0] += (0.0051358870792095942)*rtb_LC2CG[2];
    xnew[1] = (0.66124884843011622)*M1SA_F_Control_S4_DW.Fzcontroller_DSTATE[0]
      + (0.13460444259831872)*M1SA_F_Control_S4_DW.Fzcontroller_DSTATE[1]
      + (-0.0021534473090368935)*M1SA_F_Control_S4_DW.Fzcontroller_DSTATE[2];
    xnew[1] += (6.2267040787955009E-5)*rtb_LC2CG[2];
    xnew[2] = (1.0)*M1SA_F_Control_S4_DW.Fzcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG[2];
    (void) memcpy(&M1SA_F_Control_S4_DW.Fzcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Mx controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.29778010884776307)*M1SA_F_Control_S4_DW.Mxcontroller_DSTATE[0]
      + (0.71505921377142712)*M1SA_F_Control_S4_DW.Mxcontroller_DSTATE[1]
      + (-0.0021601236457374955)*M1SA_F_Control_S4_DW.Mxcontroller_DSTATE[2];
    xnew[0] += (-0.00026117608623345441)*rtb_LC2CG[3];
    xnew[1] = (-0.00024258661738509195)*
      M1SA_F_Control_S4_DW.Mxcontroller_DSTATE[0]
      + (0.27143897782429549)*M1SA_F_Control_S4_DW.Mxcontroller_DSTATE[1]
      + (-0.11649383326807114)*M1SA_F_Control_S4_DW.Mxcontroller_DSTATE[2];
    xnew[1] += (-0.0043992827840101858)*rtb_LC2CG[3];
    xnew[2] = (1.0)*M1SA_F_Control_S4_DW.Mxcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG[3];
    (void) memcpy(&M1SA_F_Control_S4_DW.Mxcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/My controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.29778010884776307)*M1SA_F_Control_S4_DW.Mycontroller_DSTATE[0]
      + (0.71505921377142712)*M1SA_F_Control_S4_DW.Mycontroller_DSTATE[1]
      + (-0.0021601236457374955)*M1SA_F_Control_S4_DW.Mycontroller_DSTATE[2];
    xnew[0] += (-0.00026117608623345441)*rtb_LC2CG[4];
    xnew[1] = (-0.00024258661738509195)*
      M1SA_F_Control_S4_DW.Mycontroller_DSTATE[0]
      + (0.27143897782429549)*M1SA_F_Control_S4_DW.Mycontroller_DSTATE[1]
      + (-0.11649383326807114)*M1SA_F_Control_S4_DW.Mycontroller_DSTATE[2];
    xnew[1] += (-0.0043992827840101858)*rtb_LC2CG[4];
    xnew[2] = (1.0)*M1SA_F_Control_S4_DW.Mycontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG[4];
    (void) memcpy(&M1SA_F_Control_S4_DW.Mycontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Mz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.38195738947508884)*M1SA_F_Control_S4_DW.Mzcontroller_DSTATE[0]
      + (0.72039580968966876)*M1SA_F_Control_S4_DW.Mzcontroller_DSTATE[1]
      + (-0.0047245815737020904)*M1SA_F_Control_S4_DW.Mzcontroller_DSTATE[2];
    xnew[0] += (-0.00039049368346384173)*rtb_LC2CG[5];
    xnew[1] = (-0.0066509471364728252)*M1SA_F_Control_S4_DW.Mzcontroller_DSTATE
      [0]
      + (0.24351874678335261)*M1SA_F_Control_S4_DW.Mzcontroller_DSTATE[1]
      + (-0.12438032071830714)*M1SA_F_Control_S4_DW.Mzcontroller_DSTATE[2];
    xnew[1] += (-0.0046882022587151594)*rtb_LC2CG[5];
    xnew[2] = (1.0)*M1SA_F_Control_S4_DW.Mzcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_LC2CG[5];
    (void) memcpy(&M1SA_F_Control_S4_DW.Mzcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteTransferFcn: '<S1>/SA Dynamics - S1' */
  memcpy(&M1SA_F_Control_S4_DW.SADynamicsS1_states[0], &SADynamicsS1_tmp[0],
         335U * sizeof(real_T));
}

/* Model initialize function */
void M1SA_F_Control_S4_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(M1SA_F_Control_S4_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&M1SA_F_Control_S4_DW, 0,
                sizeof(DW_M1SA_F_Control_S4_T));

  /* external inputs */
  (void)memset(&M1SA_F_Control_S4_U, 0, sizeof(ExtU_M1SA_F_Control_S4_T));

  /* external outputs */
  (void) memset(&M1SA_F_Control_S4_Y.M1_ACT_F[0], 0,
                335U*sizeof(real_T));
}

/* Model terminate function */
void M1SA_F_Control_S4_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
