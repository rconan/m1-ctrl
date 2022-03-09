/*
 * File: M1SA_F_Control_OA.c
 *
 * Code generated for Simulink model 'M1SA_F_Control_OA'.
 *
 * Model version                  : 1.779
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Feb 10 10:43:30 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "M1SA_F_Control_OA.h"
#include "M1SA_F_Control_OA_private.h"

/* Exported block parameters */
real_T OAseg_LC2CG[36] = { -0.43586401604199182, -0.49853163379465776,
  -0.73689706763959328, 1.8378167364642604, 1.2615001568984616,
  -1.9496070837919632, 0.43572855246616188, -0.49855038794733575,
  -0.73688918898380951, 1.8378434279119285, -1.2613870694306475,
  1.949565256760863, -0.21202530007247583, 0.62567512274900694,
  -0.7099516401194772, 0.24117316519875343, -2.165839731037698,
  -1.9442407404971678, -0.64826645797354554, -0.13032667141744514,
  -0.679806399685948, -1.9770788021572447, -0.89951157463928511,
  1.9484211834062763, 0.648324956879229, -0.13032934014068392,
  -0.67979409189869444, -1.9770499411461597, 0.89967750261937218,
  -1.9484513151993625, 0.21197435506194731, 0.62569097891597658,
  -0.709956789254709, 0.24118789480690317, 2.1659580988086113,
  1.9444035305656977 } ;               /* Variable: OAseg_LC2CG
                                        * Referenced by: '<S1>/OAseg_LC2CG'
                                        */

real_T OAseg_SA_dynDen[2] = { 1.0, -0.53348809109110329 } ;/* Variable: OAseg_SA_dynDen
                                                            * Referenced by: '<S1>/OAseg_SA_dyn'
                                                            */

real_T OAseg_SA_dynNum[2] = { 0.25752323685913081, 0.20898867204976596 } ;/* Variable: OAseg_SA_dynNum
                                                                      * Referenced by: '<S1>/OAseg_SA_dyn'
                                                                      */

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
  real_T M1SA_F_Control_OA_OAseg_SA_dyn_tmp_p[335];

  /* Gain: '<S1>/OAseg_LC2CG' incorporates:
   *  Inport: '<Root>/HP_LC'
   */
  for (i = 0; i < 6; i++) {
    rtb_OAseg_LC2CG[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_OAseg_LC2CG[i] += OAseg_LC2CG[6 * i_0 + i] *
        M1SA_F_Control_OA_U.HP_LC[i_0];
    }
  }

  /* End of Gain: '<S1>/OAseg_LC2CG' */

  /* DiscreteStateSpace: '<S3>/Fx controller' */
  {
    rtb_Fxcontroller = (-6.8610656930319749)*
      M1SA_F_Control_OA_Fxcontroller_DSTATE[0]
      + (8.7455483888425327)*M1SA_F_Control_OA_Fxcontroller_DSTATE[1]
      + (1.8)*M1SA_F_Control_OA_Fxcontroller_DSTATE[2];
    rtb_Fxcontroller += 0.024370329855613257*rtb_OAseg_LC2CG[0];
  }

  /* DiscreteStateSpace: '<S3>/Fy controller' */
  {
    rtb_Fycontroller = (-6.8610656930319749)*
      M1SA_F_Control_OA_Fycontroller_DSTATE[0]
      + (8.7455483888425327)*M1SA_F_Control_OA_Fycontroller_DSTATE[1]
      + (1.8)*M1SA_F_Control_OA_Fycontroller_DSTATE[2];
    rtb_Fycontroller += 0.024370329855613257*rtb_OAseg_LC2CG[1];
  }

  /* DiscreteStateSpace: '<S3>/Fz controller' */
  {
    rtb_Fzcontroller = (-11.022867857707155)*
      M1SA_F_Control_OA_Fzcontroller_DSTATE[0]
      + (14.667973716577512)*M1SA_F_Control_OA_Fzcontroller_DSTATE[1]
      + (2.4)*M1SA_F_Control_OA_Fzcontroller_DSTATE[2];
    rtb_Fzcontroller += 0.025354461628138772*rtb_OAseg_LC2CG[2];
  }

  /* DiscreteStateSpace: '<S3>/Mx controller' */
  {
    rtb_Mxcontroller = (-10.04307867717106)*
      M1SA_F_Control_OA_Mxcontroller_DSTATE[0]
      + (10.41998468921483)*M1SA_F_Control_OA_Mxcontroller_DSTATE[1]
      + (2.0)*M1SA_F_Control_OA_Mxcontroller_DSTATE[2];
    rtb_Mxcontroller += 0.024505707216075836*rtb_OAseg_LC2CG[3];
  }

  /* DiscreteStateSpace: '<S3>/My controller' */
  {
    rtb_Mycontroller = (-10.04307867717106)*
      M1SA_F_Control_OA_Mycontroller_DSTATE[0]
      + (10.41998468921483)*M1SA_F_Control_OA_Mycontroller_DSTATE[1]
      + (2.0)*M1SA_F_Control_OA_Mycontroller_DSTATE[2];
    rtb_Mycontroller += 0.024505707216075836*rtb_OAseg_LC2CG[4];
  }

  /* DiscreteStateSpace: '<S3>/Mz controller' */
  {
    rtb_Mzcontroller = (-9.4551745922133)*M1SA_F_Control_OA_Mzcontroller_DSTATE
      [0] + (11.4653232391471)*M1SA_F_Control_OA_Mzcontroller_DSTATE[1]
      + (2.0)*M1SA_F_Control_OA_Mzcontroller_DSTATE[2];
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
    for (i = 0; i < 6; i++) {
      OFL_act_Fcmd[i_0] += M1SA_F_Control_OA_ConstP.OAseg_Kbal_Gain[335 * i +
        i_0] * tmp[i];
    }

    /* End of Gain: '<S1>/OAseg_Kbal' */

    /* DiscreteTransferFcn: '<S1>/OAseg_SA_dyn' incorporates:
     *  Inport: '<Root>/SA_offsetF_cmd'
     *  Sum: '<S1>/Add'
     */
    denAccum = (OFL_act_Fcmd[i_0] + M1SA_F_Control_OA_U.SA_offsetF_cmd[i_0]) -
      OAseg_SA_dynDen[1] * M1SA_F_Control_OA_OAseg_SA_dyn_states[i_0];
    M1SA_F_Control_OA_Y.Res_Act_F[i_0] = OAseg_SA_dynNum[0] * denAccum +
      OAseg_SA_dynNum[1] * M1SA_F_Control_OA_OAseg_SA_dyn_states[i_0];
    M1SA_F_Control_OA_OAseg_SA_dyn_tmp_p[i_0] = denAccum;
  }

  /* Update for DiscreteStateSpace: '<S3>/Fx controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.569006949265765)*M1SA_F_Control_OA_Fxcontroller_DSTATE[0] +
      (-0.01008281122133318)*M1SA_F_Control_OA_Fxcontroller_DSTATE[1]
      + (0.10624490391424918)*M1SA_F_Control_OA_Fxcontroller_DSTATE[2];
    xnew[0] += (0.0041005206649182965)*rtb_OAseg_LC2CG[0];
    xnew[1] = (0.69153586838988734)*M1SA_F_Control_OA_Fxcontroller_DSTATE[0]
      + (0.40200245095801357)*M1SA_F_Control_OA_Fxcontroller_DSTATE[1]
      + (-0.053834780381561045)*M1SA_F_Control_OA_Fxcontroller_DSTATE[2];
    xnew[1] += (-0.0018292791104672016)*rtb_OAseg_LC2CG[0];
    xnew[2] = (1.0)*M1SA_F_Control_OA_Fxcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_OAseg_LC2CG[0];
    (void) memcpy(&M1SA_F_Control_OA_Fxcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S3>/Fy controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.569006949265765)*M1SA_F_Control_OA_Fycontroller_DSTATE[0] +
      (-0.01008281122133318)*M1SA_F_Control_OA_Fycontroller_DSTATE[1]
      + (0.10624490391424918)*M1SA_F_Control_OA_Fycontroller_DSTATE[2];
    xnew[0] += (0.0041005206649182965)*rtb_OAseg_LC2CG[1];
    xnew[1] = (0.69153586838988734)*M1SA_F_Control_OA_Fycontroller_DSTATE[0]
      + (0.40200245095801357)*M1SA_F_Control_OA_Fycontroller_DSTATE[1]
      + (-0.053834780381561045)*M1SA_F_Control_OA_Fycontroller_DSTATE[2];
    xnew[1] += (-0.0018292791104672016)*rtb_OAseg_LC2CG[1];
    xnew[2] = (1.0)*M1SA_F_Control_OA_Fycontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_OAseg_LC2CG[1];
    (void) memcpy(&M1SA_F_Control_OA_Fycontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S3>/Fz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.3222450105115563)*M1SA_F_Control_OA_Fzcontroller_DSTATE[0]
      + (-0.013311547842537916)*M1SA_F_Control_OA_Fzcontroller_DSTATE[1]
      + (0.13664330677325981)*M1SA_F_Control_OA_Fzcontroller_DSTATE[2];
    xnew[0] += (0.005170012950170496)*rtb_OAseg_LC2CG[2];
    xnew[1] = (0.66124884843011622)*M1SA_F_Control_OA_Fzcontroller_DSTATE[0]
      + (0.13460444259831861)*M1SA_F_Control_OA_Fzcontroller_DSTATE[1]
      + (-0.0021677560864410391)*M1SA_F_Control_OA_Fzcontroller_DSTATE[2];
    xnew[1] += (6.2680779829774611E-5)*rtb_OAseg_LC2CG[2];
    xnew[2] = (1.0)*M1SA_F_Control_OA_Fzcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_OAseg_LC2CG[2];
    (void) memcpy(&M1SA_F_Control_OA_Fzcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S3>/Mx controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.29778010884776307)*M1SA_F_Control_OA_Mxcontroller_DSTATE[0]
      + (0.71505921377142712)*M1SA_F_Control_OA_Mxcontroller_DSTATE[1]
      + (-0.0021601236457374955)*M1SA_F_Control_OA_Mxcontroller_DSTATE[2];
    xnew[0] += (-0.00026117608623345441)*rtb_OAseg_LC2CG[3];
    xnew[1] = (-0.00024258661738509195)*M1SA_F_Control_OA_Mxcontroller_DSTATE[0]
      + (0.27143897782429549)*M1SA_F_Control_OA_Mxcontroller_DSTATE[1]
      + (-0.11649383326807114)*M1SA_F_Control_OA_Mxcontroller_DSTATE[2];
    xnew[1] += (-0.0043992827840101858)*rtb_OAseg_LC2CG[3];
    xnew[2] = (1.0)*M1SA_F_Control_OA_Mxcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_OAseg_LC2CG[3];
    (void) memcpy(&M1SA_F_Control_OA_Mxcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S3>/My controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.29778010884776307)*M1SA_F_Control_OA_Mycontroller_DSTATE[0]
      + (0.71505921377142712)*M1SA_F_Control_OA_Mycontroller_DSTATE[1]
      + (-0.0021601236457374955)*M1SA_F_Control_OA_Mycontroller_DSTATE[2];
    xnew[0] += (-0.00026117608623345441)*rtb_OAseg_LC2CG[4];
    xnew[1] = (-0.00024258661738509195)*M1SA_F_Control_OA_Mycontroller_DSTATE[0]
      + (0.27143897782429549)*M1SA_F_Control_OA_Mycontroller_DSTATE[1]
      + (-0.11649383326807114)*M1SA_F_Control_OA_Mycontroller_DSTATE[2];
    xnew[1] += (-0.0043992827840101858)*rtb_OAseg_LC2CG[4];
    xnew[2] = (1.0)*M1SA_F_Control_OA_Mycontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_OAseg_LC2CG[4];
    (void) memcpy(&M1SA_F_Control_OA_Mycontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S3>/Mz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.38195738947508884)*M1SA_F_Control_OA_Mzcontroller_DSTATE[0]
      + (0.72039580968966876)*M1SA_F_Control_OA_Mzcontroller_DSTATE[1]
      + (-0.0047245815737020904)*M1SA_F_Control_OA_Mzcontroller_DSTATE[2];
    xnew[0] += (-0.00039049368346384173)*rtb_OAseg_LC2CG[5];
    xnew[1] = (-0.0066509471364728252)*M1SA_F_Control_OA_Mzcontroller_DSTATE[0]
      + (0.24351874678335261)*M1SA_F_Control_OA_Mzcontroller_DSTATE[1]
      + (-0.12438032071830714)*M1SA_F_Control_OA_Mzcontroller_DSTATE[2];
    xnew[1] += (-0.0046882022587151594)*rtb_OAseg_LC2CG[5];
    xnew[2] = (1.0)*M1SA_F_Control_OA_Mzcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_OAseg_LC2CG[5];
    (void) memcpy(&M1SA_F_Control_OA_Mzcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteTransferFcn: '<S1>/OAseg_SA_dyn' */
  memcpy((&(M1SA_F_Control_OA_OAseg_SA_dyn_states[0])),
         &M1SA_F_Control_OA_OAseg_SA_dyn_tmp_p[0], 335U * sizeof(real_T));
}

/* Model initialize function */
void M1SA_F_Control_OA_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(M1SA_F_Control_OA_M, (NULL));

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
