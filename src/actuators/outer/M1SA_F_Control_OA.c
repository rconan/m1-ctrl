/*
 * File: M1SA_F_Control_OA.c
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

#include "M1SA_F_Control_OA.h"
#include "M1SA_F_Control_OA_private.h"

/* Exported block parameters */
real_T OAseg_LC2CG[36] = { -0.22799574789736529, -0.27195775967986541,
  -0.41096869984045575, 1.0328136709306797, 0.75368341155073215,
  -1.0107568018754711, 0.22787198443521323, -0.27182292919959417,
  -0.41142434356008656, 1.0321841151606388, -0.75463539923265754,
  1.0069552042063206, -0.13444219199661295, 0.34256563125623,
  -0.38562490379587239, 0.14663231474803934, -1.3120654422528462,
  -1.0134924749348628, -0.36946127679967372, -0.079461913691955544,
  -0.36440719007442052, -1.079299924811522, -0.56284610251738754,
  1.024940123761539, 0.36837710925808687, -0.080009091798008788,
  -0.36470372852238292, -1.0772870720803633, 0.55669075007643409,
  -1.0270106437966451, 0.13397305523605524, 0.34407186480507496,
  -0.38684843213894382, 0.14476193493042036, 1.3102367728968352,
  1.0158784811642807 } ;               /* Variable: OAseg_LC2CG
                                        * Referenced by: '<S1>/OAseg_LC2CG'
                                        */

real_T OAseg_SA_dynDen[2] = { 1.0, -0.53348809109110329 } ;/* Variable: OAseg_SA_dynDen
                                                            * Referenced by: '<S1>/OAseg_SA_dyn'
                                                            */

real_T OAseg_SA_dynNum[2] = { 0.25752323685913081, 0.20898867204976596 } ;/* Variable: OAseg_SA_dynNum
                                                                      * Referenced by: '<S1>/OAseg_SA_dyn'
                                                                      */

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
  real_T rtb_OAseg_LC2CG[6];
  real_T rtb_Fxcontroller;
  real_T rtb_Fycontroller;
  real_T rtb_Fzcontroller;
  real_T rtb_Mxcontroller;
  real_T rtb_Mycontroller;
  real_T rtb_Mzcontroller;
  real_T denAccum;
  real_T tmp[6];
  int32_T i;
  int32_T i_0;
  real_T OAseg_SA_dyn_tmp[335];
  int32_T i_1;

  /* Gain: '<S1>/OAseg_LC2CG' incorporates:
   *  Inport: '<Root>/HP_LC'
   */
  for (i = 0; i < 6; i++) {
    rtb_OAseg_LC2CG[i] = 0.0;
    i_1 = 0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_OAseg_LC2CG[i] += OAseg_LC2CG[i_1 + i] * M1SA_F_Control_OA_U.HP_LC[i_0];
      i_1 += 6;
    }
  }

  /* End of Gain: '<S1>/OAseg_LC2CG' */

  /* DiscreteStateSpace: '<S3>/Fx controller' */
  {
    rtb_Fxcontroller = (-6.8610656930319749)*
      M1SA_F_Control_OA_DW.Fxcontroller_DSTATE[0]
      + (8.7455483888425327)*M1SA_F_Control_OA_DW.Fxcontroller_DSTATE[1]
      + (1.8)*M1SA_F_Control_OA_DW.Fxcontroller_DSTATE[2];
    rtb_Fxcontroller += 0.024370329855613257*rtb_OAseg_LC2CG[0];
  }

  /* DiscreteStateSpace: '<S3>/Fy controller' */
  {
    rtb_Fycontroller = (-6.8610656930319749)*
      M1SA_F_Control_OA_DW.Fycontroller_DSTATE[0]
      + (8.7455483888425327)*M1SA_F_Control_OA_DW.Fycontroller_DSTATE[1]
      + (1.8)*M1SA_F_Control_OA_DW.Fycontroller_DSTATE[2];
    rtb_Fycontroller += 0.024370329855613257*rtb_OAseg_LC2CG[1];
  }

  /* DiscreteStateSpace: '<S3>/Fz controller' */
  {
    rtb_Fzcontroller = (-11.022867857707155)*
      M1SA_F_Control_OA_DW.Fzcontroller_DSTATE[0]
      + (14.667973716577512)*M1SA_F_Control_OA_DW.Fzcontroller_DSTATE[1]
      + (2.4)*M1SA_F_Control_OA_DW.Fzcontroller_DSTATE[2];
    rtb_Fzcontroller += 0.025354461628138772*rtb_OAseg_LC2CG[2];
  }

  /* DiscreteStateSpace: '<S3>/Mx controller' */
  {
    rtb_Mxcontroller = (-10.04307867717106)*
      M1SA_F_Control_OA_DW.Mxcontroller_DSTATE[0]
      + (10.41998468921483)*M1SA_F_Control_OA_DW.Mxcontroller_DSTATE[1]
      + (2.0)*M1SA_F_Control_OA_DW.Mxcontroller_DSTATE[2];
    rtb_Mxcontroller += 0.024505707216075836*rtb_OAseg_LC2CG[3];
  }

  /* DiscreteStateSpace: '<S3>/My controller' */
  {
    rtb_Mycontroller = (-10.04307867717106)*
      M1SA_F_Control_OA_DW.Mycontroller_DSTATE[0]
      + (10.41998468921483)*M1SA_F_Control_OA_DW.Mycontroller_DSTATE[1]
      + (2.0)*M1SA_F_Control_OA_DW.Mycontroller_DSTATE[2];
    rtb_Mycontroller += 0.024505707216075836*rtb_OAseg_LC2CG[4];
  }

  /* DiscreteStateSpace: '<S3>/Mz controller' */
  {
    rtb_Mzcontroller = (-9.4551745922133)*
      M1SA_F_Control_OA_DW.Mzcontroller_DSTATE[0]
      + (11.4653232391471)*M1SA_F_Control_OA_DW.Mzcontroller_DSTATE[1]
      + (2.0)*M1SA_F_Control_OA_DW.Mzcontroller_DSTATE[2];
    rtb_Mzcontroller += 0.022969235998287645*rtb_OAseg_LC2CG[5];
  }

  /* SignalConversion: '<S1>/TmpSignal ConversionAtOAseg_KbalInport1' */
  tmp[0] = rtb_Fxcontroller;
  tmp[1] = rtb_Fycontroller;
  tmp[2] = rtb_Fzcontroller;
  tmp[3] = rtb_Mxcontroller;
  tmp[4] = rtb_Mycontroller;
  tmp[5] = rtb_Mzcontroller;
  for (i_0 = 0; i_0 < 335; i_0++) {
    /* Gain: '<S1>/OAseg_Kbal' */
    OFL_act_Fcmd[i_0] = 0.0;
    i = 0;
    for (i_1 = 0; i_1 < 6; i_1++) {
      OFL_act_Fcmd[i_0] += M1SA_F_Control_OA_ConstP.OAseg_Kbal_Gain[i + i_0] *
        tmp[i_1];
      i += 335;
    }

    /* DiscreteTransferFcn: '<S1>/OAseg_SA_dyn' incorporates:
     *  Gain: '<S1>/OAseg_Kbal'
     *  Inport: '<Root>/SA_offsetF_cmd'
     *  Sum: '<S1>/Add'
     */
    denAccum = (OFL_act_Fcmd[i_0] + M1SA_F_Control_OA_U.SA_offsetF_cmd[i_0]) -
      OAseg_SA_dynDen[1] * M1SA_F_Control_OA_DW.OAseg_SA_dyn_states[i_0];
    OAseg_SA_dyn_tmp[i_0] = denAccum;
    denAccum *= OAseg_SA_dynNum[0];

    /* Outport: '<Root>/Res_Act_F' incorporates:
     *  DiscreteTransferFcn: '<S1>/OAseg_SA_dyn'
     *  Gain: '<S1>/OAseg_Kbal'
     */
    M1SA_F_Control_OA_Y.Res_Act_F[i_0] = OAseg_SA_dynNum[1] *
      M1SA_F_Control_OA_DW.OAseg_SA_dyn_states[i_0] + denAccum;
  }

  /* Update for DiscreteStateSpace: '<S3>/Fx controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.569006949265765)*M1SA_F_Control_OA_DW.Fxcontroller_DSTATE[0]
      + (-0.01008281122133318)*M1SA_F_Control_OA_DW.Fxcontroller_DSTATE[1]
      + (0.10624490391424918)*M1SA_F_Control_OA_DW.Fxcontroller_DSTATE[2];
    xnew[0] += (0.0041005206649182965)*rtb_OAseg_LC2CG[0];
    xnew[1] = (0.69153586838988734)*M1SA_F_Control_OA_DW.Fxcontroller_DSTATE[0]
      + (0.40200245095801357)*M1SA_F_Control_OA_DW.Fxcontroller_DSTATE[1]
      + (-0.053834780381561045)*M1SA_F_Control_OA_DW.Fxcontroller_DSTATE[2];
    xnew[1] += (-0.0018292791104672016)*rtb_OAseg_LC2CG[0];
    xnew[2] = (1.0)*M1SA_F_Control_OA_DW.Fxcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_OAseg_LC2CG[0];
    (void) memcpy(&M1SA_F_Control_OA_DW.Fxcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S3>/Fy controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.569006949265765)*M1SA_F_Control_OA_DW.Fycontroller_DSTATE[0]
      + (-0.01008281122133318)*M1SA_F_Control_OA_DW.Fycontroller_DSTATE[1]
      + (0.10624490391424918)*M1SA_F_Control_OA_DW.Fycontroller_DSTATE[2];
    xnew[0] += (0.0041005206649182965)*rtb_OAseg_LC2CG[1];
    xnew[1] = (0.69153586838988734)*M1SA_F_Control_OA_DW.Fycontroller_DSTATE[0]
      + (0.40200245095801357)*M1SA_F_Control_OA_DW.Fycontroller_DSTATE[1]
      + (-0.053834780381561045)*M1SA_F_Control_OA_DW.Fycontroller_DSTATE[2];
    xnew[1] += (-0.0018292791104672016)*rtb_OAseg_LC2CG[1];
    xnew[2] = (1.0)*M1SA_F_Control_OA_DW.Fycontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_OAseg_LC2CG[1];
    (void) memcpy(&M1SA_F_Control_OA_DW.Fycontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S3>/Fz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.3222450105115563)*M1SA_F_Control_OA_DW.Fzcontroller_DSTATE[0]
      + (-0.013311547842537916)*M1SA_F_Control_OA_DW.Fzcontroller_DSTATE[1]
      + (0.13664330677325981)*M1SA_F_Control_OA_DW.Fzcontroller_DSTATE[2];
    xnew[0] += (0.005170012950170496)*rtb_OAseg_LC2CG[2];
    xnew[1] = (0.66124884843011622)*M1SA_F_Control_OA_DW.Fzcontroller_DSTATE[0]
      + (0.13460444259831861)*M1SA_F_Control_OA_DW.Fzcontroller_DSTATE[1]
      + (-0.0021677560864410391)*M1SA_F_Control_OA_DW.Fzcontroller_DSTATE[2];
    xnew[1] += (6.2680779829774611E-5)*rtb_OAseg_LC2CG[2];
    xnew[2] = (1.0)*M1SA_F_Control_OA_DW.Fzcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_OAseg_LC2CG[2];
    (void) memcpy(&M1SA_F_Control_OA_DW.Fzcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S3>/Mx controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.29778010884776307)*M1SA_F_Control_OA_DW.Mxcontroller_DSTATE[0]
      + (0.71505921377142712)*M1SA_F_Control_OA_DW.Mxcontroller_DSTATE[1]
      + (-0.0021601236457374955)*M1SA_F_Control_OA_DW.Mxcontroller_DSTATE[2];
    xnew[0] += (-0.00026117608623345441)*rtb_OAseg_LC2CG[3];
    xnew[1] = (-0.00024258661738509195)*
      M1SA_F_Control_OA_DW.Mxcontroller_DSTATE[0]
      + (0.27143897782429549)*M1SA_F_Control_OA_DW.Mxcontroller_DSTATE[1]
      + (-0.11649383326807114)*M1SA_F_Control_OA_DW.Mxcontroller_DSTATE[2];
    xnew[1] += (-0.0043992827840101858)*rtb_OAseg_LC2CG[3];
    xnew[2] = (1.0)*M1SA_F_Control_OA_DW.Mxcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_OAseg_LC2CG[3];
    (void) memcpy(&M1SA_F_Control_OA_DW.Mxcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S3>/My controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.29778010884776307)*M1SA_F_Control_OA_DW.Mycontroller_DSTATE[0]
      + (0.71505921377142712)*M1SA_F_Control_OA_DW.Mycontroller_DSTATE[1]
      + (-0.0021601236457374955)*M1SA_F_Control_OA_DW.Mycontroller_DSTATE[2];
    xnew[0] += (-0.00026117608623345441)*rtb_OAseg_LC2CG[4];
    xnew[1] = (-0.00024258661738509195)*
      M1SA_F_Control_OA_DW.Mycontroller_DSTATE[0]
      + (0.27143897782429549)*M1SA_F_Control_OA_DW.Mycontroller_DSTATE[1]
      + (-0.11649383326807114)*M1SA_F_Control_OA_DW.Mycontroller_DSTATE[2];
    xnew[1] += (-0.0043992827840101858)*rtb_OAseg_LC2CG[4];
    xnew[2] = (1.0)*M1SA_F_Control_OA_DW.Mycontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_OAseg_LC2CG[4];
    (void) memcpy(&M1SA_F_Control_OA_DW.Mycontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S3>/Mz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.38195738947508884)*M1SA_F_Control_OA_DW.Mzcontroller_DSTATE[0]
      + (0.72039580968966876)*M1SA_F_Control_OA_DW.Mzcontroller_DSTATE[1]
      + (-0.0047245815737020904)*M1SA_F_Control_OA_DW.Mzcontroller_DSTATE[2];
    xnew[0] += (-0.00039049368346384173)*rtb_OAseg_LC2CG[5];
    xnew[1] = (-0.0066509471364728252)*M1SA_F_Control_OA_DW.Mzcontroller_DSTATE
      [0]
      + (0.24351874678335261)*M1SA_F_Control_OA_DW.Mzcontroller_DSTATE[1]
      + (-0.12438032071830714)*M1SA_F_Control_OA_DW.Mzcontroller_DSTATE[2];
    xnew[1] += (-0.0046882022587151594)*rtb_OAseg_LC2CG[5];
    xnew[2] = (1.0)*M1SA_F_Control_OA_DW.Mzcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_OAseg_LC2CG[5];
    (void) memcpy(&M1SA_F_Control_OA_DW.Mzcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteTransferFcn: '<S1>/OAseg_SA_dyn' */
  memcpy(&M1SA_F_Control_OA_DW.OAseg_SA_dyn_states[0], &OAseg_SA_dyn_tmp[0],
         335U * sizeof(real_T));
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
  (void) memset(&M1SA_F_Control_OA_Y.Res_Act_F[0], 0,
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
