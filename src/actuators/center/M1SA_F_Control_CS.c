/*
 * File: M1SA_F_Control_CS.c
 *
 * Code generated for Simulink model 'M1SA_F_Control_CS'.
 *
 * Model version                  : 1.966
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar  9 10:44:51 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "M1SA_F_Control_CS.h"
#include "M1SA_F_Control_CS_private.h"

/* Exported block parameters */
real_T CSseg_LC2CG[36] = { -0.43533006963859777, -0.49723457223199613,
  -0.69884947685527476, 1.7179183353107261, 1.2349382218036942,
  -1.9495595047822099, 0.43532832769594748, -0.49723244982978382,
  -0.6988473995862301, 1.7179249633896383, -1.2349231332267661,
  1.9495444510449105, -0.21219477334719458, 0.626930979805201,
  -0.69617717901199816, 0.20217496038154539, -2.1064722909290179,
  -1.9488300420728881, -0.64650671116231151, -0.13031228512691892,
  -0.70141525922167647, -1.9262782222178461, -0.87239894008060448,
  1.9464850305809298, 0.64653537265488548, -0.13031227005799478,
  -0.70147311866005679, -1.926399723326049, 0.8723631932145568,
  -1.946594422671988, 0.2121986881312, 0.62692411081540345, -0.69618760729299511,
  0.2021311825824266, 2.1064191896475548, 1.9487807766658261 } ;/* Variable: CSseg_LC2CG
                                                                 * Referenced by: '<S1>/CSseg_LC2CG'
                                                                 */

real_T CSseg_SA_dynDen[2] = { 1.0, -0.53348809109110329 } ;/* Variable: CSseg_SA_dynDen
                                                            * Referenced by: '<S1>/CSseg_SA_dyn'
                                                            */

real_T CSseg_SA_dynNum[2] = { 0.25752323685913081, 0.20898867204976596 } ;/* Variable: CSseg_SA_dynNum
                                                                      * Referenced by: '<S1>/CSseg_SA_dyn'
                                                                      */

/* Block states (default storage) */
DW_M1SA_F_Control_CS_T M1SA_F_Control_CS_DW;

/* External inputs (root inport signals with default storage) */
ExtU_M1SA_F_Control_CS_T M1SA_F_Control_CS_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_M1SA_F_Control_CS_T M1SA_F_Control_CS_Y;

/* Real-time model */
RT_MODEL_M1SA_F_Control_CS_T M1SA_F_Control_CS_M_;
RT_MODEL_M1SA_F_Control_CS_T *const M1SA_F_Control_CS_M = &M1SA_F_Control_CS_M_;

/* Model step function */
void M1SA_F_Control_CS_step(void)
{
  /* local block i/o variables */
  real_T rtb_CSseg_LC2CG[6];
  real_T rtb_Fxcontroller;
  real_T rtb_Fycontroller;
  real_T rtb_Fzcontroller;
  real_T rtb_Mxcontroller;
  real_T rtb_Mycontroller;
  real_T rtb_Mzcontroller;
  real_T denAccum;
  real_T rtb_CSseg_SA_dyn[306];
  real_T tmp[6];
  int32_T i;
  int32_T i_0;
  real_T CSseg_SA_dyn_tmp[306];
  int32_T i_1;

  /* Gain: '<S1>/CSseg_LC2CG' incorporates:
   *  Inport: '<Root>/HP_LC'
   */
  for (i = 0; i < 6; i++) {
    rtb_CSseg_LC2CG[i] = 0.0;
    i_1 = 0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_CSseg_LC2CG[i] += CSseg_LC2CG[i_1 + i] * M1SA_F_Control_CS_U.HP_LC[i_0];
      i_1 += 6;
    }
  }

  /* End of Gain: '<S1>/CSseg_LC2CG' */

  /* DiscreteStateSpace: '<S2>/Fx controller' */
  {
    rtb_Fxcontroller = (-6.8610656930319749)*
      M1SA_F_Control_CS_DW.Fxcontroller_DSTATE[0]
      + (8.7455483888425327)*M1SA_F_Control_CS_DW.Fxcontroller_DSTATE[1]
      + (1.8)*M1SA_F_Control_CS_DW.Fxcontroller_DSTATE[2];
    rtb_Fxcontroller += 0.024370329855613257*rtb_CSseg_LC2CG[0];
  }

  /* DiscreteStateSpace: '<S2>/Fy controller' */
  {
    rtb_Fycontroller = (-6.8610656930319749)*
      M1SA_F_Control_CS_DW.Fycontroller_DSTATE[0]
      + (8.7455483888425327)*M1SA_F_Control_CS_DW.Fycontroller_DSTATE[1]
      + (1.8)*M1SA_F_Control_CS_DW.Fycontroller_DSTATE[2];
    rtb_Fycontroller += 0.024370329855613257*rtb_CSseg_LC2CG[1];
  }

  /* DiscreteStateSpace: '<S2>/Fz controller' */
  {
    rtb_Fzcontroller = (-11.624022612778809)*
      M1SA_F_Control_CS_DW.Fzcontroller_DSTATE[0]
      + (13.310955668383137)*M1SA_F_Control_CS_DW.Fzcontroller_DSTATE[1]
      + (2.4)*M1SA_F_Control_CS_DW.Fzcontroller_DSTATE[2];
    rtb_Fzcontroller += 0.026005628588130474*rtb_CSseg_LC2CG[2];
  }

  /* DiscreteStateSpace: '<S2>/Mx controller' */
  {
    rtb_Mxcontroller = (10.799355933329354)*
      M1SA_F_Control_CS_DW.Mxcontroller_DSTATE[0]
      + (-10.162942348382657)*M1SA_F_Control_CS_DW.Mxcontroller_DSTATE[1]
      + (2.0)*M1SA_F_Control_CS_DW.Mxcontroller_DSTATE[2];
    rtb_Mxcontroller += 0.024170972941162154*rtb_CSseg_LC2CG[3];
  }

  /* DiscreteStateSpace: '<S2>/My controller' */
  {
    rtb_Mycontroller = (10.799355933329354)*
      M1SA_F_Control_CS_DW.Mycontroller_DSTATE[0]
      + (-10.162942348382657)*M1SA_F_Control_CS_DW.Mycontroller_DSTATE[1]
      + (2.0)*M1SA_F_Control_CS_DW.Mycontroller_DSTATE[2];
    rtb_Mycontroller += 0.024170972941162154*rtb_CSseg_LC2CG[4];
  }

  /* DiscreteStateSpace: '<S2>/Mz controller' */
  {
    rtb_Mzcontroller = (-9.8843504316129263)*
      M1SA_F_Control_CS_DW.Mzcontroller_DSTATE[0]
      + (11.363212843833221)*M1SA_F_Control_CS_DW.Mzcontroller_DSTATE[1]
      + (2.0)*M1SA_F_Control_CS_DW.Mzcontroller_DSTATE[2];
    rtb_Mzcontroller += 0.02274996590750189*rtb_CSseg_LC2CG[5];
  }

  /* SignalConversion: '<S1>/TmpSignal ConversionAtCSseg_KbalInport1' */
  tmp[0] = rtb_Fxcontroller;
  tmp[1] = rtb_Fycontroller;
  tmp[2] = rtb_Fzcontroller;
  tmp[3] = rtb_Mxcontroller;
  tmp[4] = rtb_Mycontroller;
  tmp[5] = rtb_Mzcontroller;
  for (i_0 = 0; i_0 < 306; i_0++) {
    /* Gain: '<S1>/CSseg_Kbal' */
    rtb_CSseg_SA_dyn[i_0] = 0.0;
    i = 0;
    for (i_1 = 0; i_1 < 6; i_1++) {
      rtb_CSseg_SA_dyn[i_0] += M1SA_F_Control_CS_ConstP.CSseg_Kbal_Gain[i + i_0]
        * tmp[i_1];
      i += 306;
    }

    /* DiscreteTransferFcn: '<S1>/CSseg_SA_dyn' incorporates:
     *  Gain: '<S1>/CSseg_Kbal'
     *  Inport: '<Root>/SA_offsetF_cmd'
     *  Sum: '<S1>/Add'
     */
    denAccum = (rtb_CSseg_SA_dyn[i_0] + M1SA_F_Control_CS_U.SA_offsetF_cmd[i_0])
      - CSseg_SA_dynDen[1] * M1SA_F_Control_CS_DW.CSseg_SA_dyn_states[i_0];
    CSseg_SA_dyn_tmp[i_0] = denAccum;
    denAccum *= CSseg_SA_dynNum[0];
    rtb_CSseg_SA_dyn[i_0] = CSseg_SA_dynNum[1] *
      M1SA_F_Control_CS_DW.CSseg_SA_dyn_states[i_0] + denAccum;

    /* Outport: '<Root>/Res_Act_F' incorporates:
     *  Gain: '<S1>/CSseg_Kbal'
     */
    M1SA_F_Control_CS_Y.Res_Act_F[i_0] = rtb_CSseg_SA_dyn[i_0];
  }

  /* Update for DiscreteStateSpace: '<S2>/Fx controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.569006949265765)*M1SA_F_Control_CS_DW.Fxcontroller_DSTATE[0]
      + (-0.01008281122133318)*M1SA_F_Control_CS_DW.Fxcontroller_DSTATE[1]
      + (0.10624490391424918)*M1SA_F_Control_CS_DW.Fxcontroller_DSTATE[2];
    xnew[0] += (0.0041005206649182965)*rtb_CSseg_LC2CG[0];
    xnew[1] = (0.69153586838988734)*M1SA_F_Control_CS_DW.Fxcontroller_DSTATE[0]
      + (0.40200245095801357)*M1SA_F_Control_CS_DW.Fxcontroller_DSTATE[1]
      + (-0.053834780381561045)*M1SA_F_Control_CS_DW.Fxcontroller_DSTATE[2];
    xnew[1] += (-0.0018292791104672016)*rtb_CSseg_LC2CG[0];
    xnew[2] = (1.0)*M1SA_F_Control_CS_DW.Fxcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_CSseg_LC2CG[0];
    (void) memcpy(&M1SA_F_Control_CS_DW.Fxcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Fy controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.569006949265765)*M1SA_F_Control_CS_DW.Fycontroller_DSTATE[0]
      + (-0.01008281122133318)*M1SA_F_Control_CS_DW.Fycontroller_DSTATE[1]
      + (0.10624490391424918)*M1SA_F_Control_CS_DW.Fycontroller_DSTATE[2];
    xnew[0] += (0.0041005206649182965)*rtb_CSseg_LC2CG[1];
    xnew[1] = (0.69153586838988734)*M1SA_F_Control_CS_DW.Fycontroller_DSTATE[0]
      + (0.40200245095801357)*M1SA_F_Control_CS_DW.Fycontroller_DSTATE[1]
      + (-0.053834780381561045)*M1SA_F_Control_CS_DW.Fycontroller_DSTATE[2];
    xnew[1] += (-0.0018292791104672016)*rtb_CSseg_LC2CG[1];
    xnew[2] = (1.0)*M1SA_F_Control_CS_DW.Fycontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_CSseg_LC2CG[1];
    (void) memcpy(&M1SA_F_Control_CS_DW.Fycontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Fz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.30106701605566411)*M1SA_F_Control_CS_DW.Fzcontroller_DSTATE[0]
      + (-0.0031724351959647483)*M1SA_F_Control_CS_DW.Fzcontroller_DSTATE[1]
      + (0.13638180429146238)*M1SA_F_Control_CS_DW.Fzcontroller_DSTATE[2];
    xnew[0] += (0.0051578505311074786)*rtb_CSseg_LC2CG[2];
    xnew[1] = (0.69313056645169)*M1SA_F_Control_CS_DW.Fzcontroller_DSTATE[0]
      + (0.20728190413675984)*M1SA_F_Control_CS_DW.Fzcontroller_DSTATE[1]
      + (-0.00017021067138710554)*M1SA_F_Control_CS_DW.Fzcontroller_DSTATE[2];
    xnew[1] += (0.00017169440437669642)*rtb_CSseg_LC2CG[2];
    xnew[2] = (1.0)*M1SA_F_Control_CS_DW.Fzcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_CSseg_LC2CG[2];
    (void) memcpy(&M1SA_F_Control_CS_DW.Fzcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Mx controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.24588323456423145)*M1SA_F_Control_CS_DW.Mxcontroller_DSTATE[0]
      + (0.70467842450269291)*M1SA_F_Control_CS_DW.Mxcontroller_DSTATE[1]
      + (0.00081808803127932854)*M1SA_F_Control_CS_DW.Mxcontroller_DSTATE[2];
    xnew[0] += (0.00019581781538031463)*rtb_CSseg_LC2CG[3];
    xnew[1] = (-0.00064951930680839346)*
      M1SA_F_Control_CS_DW.Mxcontroller_DSTATE[0]
      + (0.28867118809350589)*M1SA_F_Control_CS_DW.Mxcontroller_DSTATE[1]
      + (0.11653922223015478)*M1SA_F_Control_CS_DW.Mxcontroller_DSTATE[2];
    xnew[1] += (0.0044051041445438335)*rtb_CSseg_LC2CG[3];
    xnew[2] = (1.0)*M1SA_F_Control_CS_DW.Mxcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_CSseg_LC2CG[3];
    (void) memcpy(&M1SA_F_Control_CS_DW.Mxcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/My controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.24588323456423145)*M1SA_F_Control_CS_DW.Mycontroller_DSTATE[0]
      + (0.70467842450269291)*M1SA_F_Control_CS_DW.Mycontroller_DSTATE[1]
      + (0.00081808803127932854)*M1SA_F_Control_CS_DW.Mycontroller_DSTATE[2];
    xnew[0] += (0.00019581781538031463)*rtb_CSseg_LC2CG[4];
    xnew[1] = (-0.00064951930680839346)*
      M1SA_F_Control_CS_DW.Mycontroller_DSTATE[0]
      + (0.28867118809350589)*M1SA_F_Control_CS_DW.Mycontroller_DSTATE[1]
      + (0.11653922223015478)*M1SA_F_Control_CS_DW.Mycontroller_DSTATE[2];
    xnew[1] += (0.0044051041445438335)*rtb_CSseg_LC2CG[4];
    xnew[2] = (1.0)*M1SA_F_Control_CS_DW.Mycontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_CSseg_LC2CG[4];
    (void) memcpy(&M1SA_F_Control_CS_DW.Mycontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S2>/Mz controller' */
  {
    real_T xnew[3];
    xnew[0] = (0.35318690302308442)*M1SA_F_Control_CS_DW.Mzcontroller_DSTATE[0]
      + (0.72011465131225016)*M1SA_F_Control_CS_DW.Mzcontroller_DSTATE[1]
      + (-0.0038868874920811648)*M1SA_F_Control_CS_DW.Mzcontroller_DSTATE[2];
    xnew[0] += (-0.00035257232440118728)*rtb_CSseg_LC2CG[5];
    xnew[1] = (-0.0034885015967498082)*M1SA_F_Control_CS_DW.Mzcontroller_DSTATE
      [0]
      + (0.25294477393664205)*M1SA_F_Control_CS_DW.Mzcontroller_DSTATE[1]
      + (-0.12437198598757729)*M1SA_F_Control_CS_DW.Mzcontroller_DSTATE[2];
    xnew[1] += (-0.0046911246844348262)*rtb_CSseg_LC2CG[5];
    xnew[2] = (1.0)*M1SA_F_Control_CS_DW.Mzcontroller_DSTATE[2];
    xnew[2] += (0.039999999999999994)*rtb_CSseg_LC2CG[5];
    (void) memcpy(&M1SA_F_Control_CS_DW.Mzcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteTransferFcn: '<S1>/CSseg_SA_dyn' */
  memcpy(&M1SA_F_Control_CS_DW.CSseg_SA_dyn_states[0], &CSseg_SA_dyn_tmp[0],
         306U * sizeof(real_T));
}

/* Model initialize function */
void M1SA_F_Control_CS_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(M1SA_F_Control_CS_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&M1SA_F_Control_CS_DW, 0,
                sizeof(DW_M1SA_F_Control_CS_T));

  /* external inputs */
  (void)memset(&M1SA_F_Control_CS_U, 0, sizeof(ExtU_M1SA_F_Control_CS_T));

  /* external outputs */
  (void) memset(&M1SA_F_Control_CS_Y.Res_Act_F[0], 0,
                306U*sizeof(real_T));
}

/* Model terminate function */
void M1SA_F_Control_CS_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
