/*
 * File: M1_HP_Dyn.c
 *
 * Code generated for Simulink model 'M1_HP_Dyn'.
 *
 * Model version                  : 1.903
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Aug 24 15:16:11 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "M1_HP_Dyn.h"
#include "M1_HP_Dyn_private.h"

/* Block states (default storage) */
DW_M1_HP_Dyn_T M1_HP_Dyn_DW;

/* External inputs (root inport signals with default storage) */
ExtU_M1_HP_Dyn_T M1_HP_Dyn_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_M1_HP_Dyn_T M1_HP_Dyn_Y;

/* Real-time model */
RT_MODEL_M1_HP_Dyn_T M1_HP_Dyn_M_;
RT_MODEL_M1_HP_Dyn_T *const M1_HP_Dyn_M = &M1_HP_Dyn_M_;

/* Model step function */
void M1_HP_Dyn_step(void)
{
  real_T denAccum;
  int32_T memOffset;
  real_T rtb_CG2Hp6[6];
  real_T rtb_HpK8[6];
  real_T rtb_HpK1[6];
  real_T rtb_HpK2[6];
  real_T rtb_HpK5[6];
  real_T rtb_HpK3[6];
  real_T rtb_HpK4[6];
  int32_T k;
  real_T S1HP_dyn_dTF_tmp[6];
  real_T S2HP_dyn_dTF_tmp[6];
  real_T S3HP_dyn_dTF_tmp[6];
  real_T S4HP_dyn_dTF_tmp[6];
  real_T S5HP_dyn_dTF_tmp[6];
  real_T S6HP_dyn_dTF_tmp[6];
  real_T S7HP_dyn_dTF_tmp[6];
  real_T denAccum_tmp;
  real_T denAccum_tmp_0;
  real_T denAccum_tmp_1;
  for (k = 0; k < 6; k++) {
    /* Gain: '<S1>/CG2Hp6' incorporates:
     *  Inport: '<Root>/M1_RBM_cmd'
     */
    rtb_CG2Hp6[k] = 0.0;
    for (memOffset = 0; memOffset < 6; memOffset++) {
      rtb_CG2Hp6[k] += M1_HP_Dyn_ConstP.CG2Hp6_Gain[6 * memOffset + k] *
        M1_HP_Dyn_U.M1_RBM_cmd[memOffset];
    }

    /* End of Gain: '<S1>/CG2Hp6' */

    /* DiscreteTransferFcn: '<S1>/S1HP_dyn_dTF' */
    memOffset = k << 2;
    denAccum_tmp = M1_HP_Dyn_DW.S1HP_dyn_dTF_states[memOffset + 1];
    denAccum_tmp_0 = M1_HP_Dyn_DW.S1HP_dyn_dTF_states[memOffset + 2];
    denAccum_tmp_1 = M1_HP_Dyn_DW.S1HP_dyn_dTF_states[memOffset + 3];
    denAccum = (((rtb_CG2Hp6[k] - -3.9323939066475968 *
                  M1_HP_Dyn_DW.S1HP_dyn_dTF_states[memOffset]) - denAccum_tmp *
                 5.7979978715556353) - denAccum_tmp_0 * -3.7988101955494251) -
      denAccum_tmp_1 * 0.93320623842210537;
    S1HP_dyn_dTF_tmp[k] = denAccum;
    denAccum *= 0.00010770254974318945;
    denAccum += 9.54959583974631E-7 * M1_HP_Dyn_DW.S1HP_dyn_dTF_states[memOffset];
    denAccum += denAccum_tmp * -0.00021444819472271384;
    denAccum += denAccum_tmp_0 * -9.5106922459374865E-7;
    denAccum += denAccum_tmp_1 * 0.00010674953533890526;

    /* Gain: '<S1>/CG2Hp8' incorporates:
     *  Inport: '<Root>/M1_RBM_cmd'
     */
    rtb_CG2Hp6[k] = 0.0;
    for (memOffset = 0; memOffset < 6; memOffset++) {
      rtb_CG2Hp6[k] += M1_HP_Dyn_ConstP.CG2Hp8_Gain[6 * memOffset + k] *
        M1_HP_Dyn_U.M1_RBM_cmd[6 + memOffset];
    }

    /* End of Gain: '<S1>/CG2Hp8' */

    /* DiscreteTransferFcn: '<S1>/S1HP_dyn_dTF' incorporates:
     *  Gain: '<S1>/HpK8'
     */
    rtb_HpK8[k] = 1.6612584871854693E+8 * denAccum;
  }

  for (k = 0; k < 6; k++) {
    /* DiscreteTransferFcn: '<S1>/S2HP_dyn_dTF' */
    memOffset = k << 2;
    denAccum_tmp = M1_HP_Dyn_DW.S2HP_dyn_dTF_states[memOffset + 1];
    denAccum_tmp_0 = M1_HP_Dyn_DW.S2HP_dyn_dTF_states[memOffset + 2];
    denAccum_tmp_1 = M1_HP_Dyn_DW.S2HP_dyn_dTF_states[memOffset + 3];
    denAccum = (((rtb_CG2Hp6[k] - -3.9323939066475968 *
                  M1_HP_Dyn_DW.S2HP_dyn_dTF_states[memOffset]) - denAccum_tmp *
                 5.7979978715556353) - denAccum_tmp_0 * -3.7988101955494251) -
      denAccum_tmp_1 * 0.93320623842210537;
    S2HP_dyn_dTF_tmp[k] = denAccum;
    denAccum *= 0.00010770254974318945;
    denAccum += 9.54959583974631E-7 * M1_HP_Dyn_DW.S2HP_dyn_dTF_states[memOffset];
    denAccum += denAccum_tmp * -0.00021444819472271384;
    denAccum += denAccum_tmp_0 * -9.5106922459374865E-7;
    denAccum += denAccum_tmp_1 * 0.00010674953533890526;

    /* Gain: '<S1>/CG2Hp1' incorporates:
     *  Inport: '<Root>/M1_RBM_cmd'
     */
    rtb_CG2Hp6[k] = 0.0;
    for (memOffset = 0; memOffset < 6; memOffset++) {
      rtb_CG2Hp6[k] += M1_HP_Dyn_ConstP.CG2Hp1_Gain[6 * memOffset + k] *
        M1_HP_Dyn_U.M1_RBM_cmd[12 + memOffset];
    }

    /* End of Gain: '<S1>/CG2Hp1' */

    /* DiscreteTransferFcn: '<S1>/S2HP_dyn_dTF' incorporates:
     *  Gain: '<S1>/HpK1'
     */
    rtb_HpK1[k] = 1.6612584871854693E+8 * denAccum;
  }

  for (k = 0; k < 6; k++) {
    /* DiscreteTransferFcn: '<S1>/S3HP_dyn_dTF' */
    memOffset = k << 2;
    denAccum_tmp = M1_HP_Dyn_DW.S3HP_dyn_dTF_states[memOffset + 1];
    denAccum_tmp_0 = M1_HP_Dyn_DW.S3HP_dyn_dTF_states[memOffset + 2];
    denAccum_tmp_1 = M1_HP_Dyn_DW.S3HP_dyn_dTF_states[memOffset + 3];
    denAccum = (((rtb_CG2Hp6[k] - -3.9323939066475968 *
                  M1_HP_Dyn_DW.S3HP_dyn_dTF_states[memOffset]) - denAccum_tmp *
                 5.7979978715556353) - denAccum_tmp_0 * -3.7988101955494251) -
      denAccum_tmp_1 * 0.93320623842210537;
    S3HP_dyn_dTF_tmp[k] = denAccum;
    denAccum *= 0.00010770254974318945;
    denAccum += 9.54959583974631E-7 * M1_HP_Dyn_DW.S3HP_dyn_dTF_states[memOffset];
    denAccum += denAccum_tmp * -0.00021444819472271384;
    denAccum += denAccum_tmp_0 * -9.5106922459374865E-7;
    denAccum += denAccum_tmp_1 * 0.00010674953533890526;

    /* Gain: '<S1>/CG2Hp2' incorporates:
     *  Inport: '<Root>/M1_RBM_cmd'
     */
    rtb_CG2Hp6[k] = 0.0;
    for (memOffset = 0; memOffset < 6; memOffset++) {
      rtb_CG2Hp6[k] += M1_HP_Dyn_ConstP.CG2Hp2_Gain[6 * memOffset + k] *
        M1_HP_Dyn_U.M1_RBM_cmd[18 + memOffset];
    }

    /* End of Gain: '<S1>/CG2Hp2' */

    /* DiscreteTransferFcn: '<S1>/S3HP_dyn_dTF' incorporates:
     *  Gain: '<S1>/HpK2'
     */
    rtb_HpK2[k] = 1.6612584871854693E+8 * denAccum;
  }

  for (k = 0; k < 6; k++) {
    /* DiscreteTransferFcn: '<S1>/S4HP_dyn_dTF' */
    memOffset = k << 2;
    denAccum_tmp = M1_HP_Dyn_DW.S4HP_dyn_dTF_states[memOffset + 1];
    denAccum_tmp_0 = M1_HP_Dyn_DW.S4HP_dyn_dTF_states[memOffset + 2];
    denAccum_tmp_1 = M1_HP_Dyn_DW.S4HP_dyn_dTF_states[memOffset + 3];
    denAccum = (((rtb_CG2Hp6[k] - -3.9323939066475968 *
                  M1_HP_Dyn_DW.S4HP_dyn_dTF_states[memOffset]) - denAccum_tmp *
                 5.7979978715556353) - denAccum_tmp_0 * -3.7988101955494251) -
      denAccum_tmp_1 * 0.93320623842210537;
    S4HP_dyn_dTF_tmp[k] = denAccum;
    denAccum *= 0.00010770254974318945;
    denAccum += 9.54959583974631E-7 * M1_HP_Dyn_DW.S4HP_dyn_dTF_states[memOffset];
    denAccum += denAccum_tmp * -0.00021444819472271384;
    denAccum += denAccum_tmp_0 * -9.5106922459374865E-7;
    denAccum += denAccum_tmp_1 * 0.00010674953533890526;

    /* Gain: '<S1>/CG2Hp3' incorporates:
     *  Inport: '<Root>/M1_RBM_cmd'
     */
    rtb_CG2Hp6[k] = 0.0;
    for (memOffset = 0; memOffset < 6; memOffset++) {
      rtb_CG2Hp6[k] += M1_HP_Dyn_ConstP.CG2Hp3_Gain[6 * memOffset + k] *
        M1_HP_Dyn_U.M1_RBM_cmd[24 + memOffset];
    }

    /* End of Gain: '<S1>/CG2Hp3' */

    /* DiscreteTransferFcn: '<S1>/S4HP_dyn_dTF' incorporates:
     *  Gain: '<S1>/HpK5'
     */
    rtb_HpK5[k] = 1.6612584871854693E+8 * denAccum;
  }

  for (k = 0; k < 6; k++) {
    /* DiscreteTransferFcn: '<S1>/S5HP_dyn_dTF' */
    memOffset = k << 2;
    denAccum_tmp = M1_HP_Dyn_DW.S5HP_dyn_dTF_states[memOffset + 1];
    denAccum_tmp_0 = M1_HP_Dyn_DW.S5HP_dyn_dTF_states[memOffset + 2];
    denAccum_tmp_1 = M1_HP_Dyn_DW.S5HP_dyn_dTF_states[memOffset + 3];
    denAccum = (((rtb_CG2Hp6[k] - -3.9323939066475968 *
                  M1_HP_Dyn_DW.S5HP_dyn_dTF_states[memOffset]) - denAccum_tmp *
                 5.7979978715556353) - denAccum_tmp_0 * -3.7988101955494251) -
      denAccum_tmp_1 * 0.93320623842210537;
    S5HP_dyn_dTF_tmp[k] = denAccum;
    denAccum *= 0.00010770254974318945;
    denAccum += 9.54959583974631E-7 * M1_HP_Dyn_DW.S5HP_dyn_dTF_states[memOffset];
    denAccum += denAccum_tmp * -0.00021444819472271384;
    denAccum += denAccum_tmp_0 * -9.5106922459374865E-7;
    denAccum += denAccum_tmp_1 * 0.00010674953533890526;

    /* Gain: '<S1>/CG2Hp4' incorporates:
     *  Inport: '<Root>/M1_RBM_cmd'
     */
    rtb_CG2Hp6[k] = 0.0;
    for (memOffset = 0; memOffset < 6; memOffset++) {
      rtb_CG2Hp6[k] += M1_HP_Dyn_ConstP.CG2Hp4_Gain[6 * memOffset + k] *
        M1_HP_Dyn_U.M1_RBM_cmd[30 + memOffset];
    }

    /* End of Gain: '<S1>/CG2Hp4' */

    /* DiscreteTransferFcn: '<S1>/S5HP_dyn_dTF' incorporates:
     *  Gain: '<S1>/HpK3'
     */
    rtb_HpK3[k] = 1.6612584871854693E+8 * denAccum;
  }

  for (k = 0; k < 6; k++) {
    /* DiscreteTransferFcn: '<S1>/S6HP_dyn_dTF' */
    memOffset = k << 2;
    denAccum_tmp = M1_HP_Dyn_DW.S6HP_dyn_dTF_states[memOffset + 1];
    denAccum_tmp_0 = M1_HP_Dyn_DW.S6HP_dyn_dTF_states[memOffset + 2];
    denAccum_tmp_1 = M1_HP_Dyn_DW.S6HP_dyn_dTF_states[memOffset + 3];
    denAccum = (((rtb_CG2Hp6[k] - -3.9323939066475968 *
                  M1_HP_Dyn_DW.S6HP_dyn_dTF_states[memOffset]) - denAccum_tmp *
                 5.7979978715556353) - denAccum_tmp_0 * -3.7988101955494251) -
      denAccum_tmp_1 * 0.93320623842210537;
    S6HP_dyn_dTF_tmp[k] = denAccum;
    denAccum *= 0.00010770254974318945;
    denAccum += 9.54959583974631E-7 * M1_HP_Dyn_DW.S6HP_dyn_dTF_states[memOffset];
    denAccum += denAccum_tmp * -0.00021444819472271384;
    denAccum += denAccum_tmp_0 * -9.5106922459374865E-7;
    denAccum += denAccum_tmp_1 * 0.00010674953533890526;

    /* Gain: '<S1>/CG2Hp5' incorporates:
     *  Inport: '<Root>/M1_RBM_cmd'
     */
    rtb_CG2Hp6[k] = 0.0;
    for (memOffset = 0; memOffset < 6; memOffset++) {
      rtb_CG2Hp6[k] += M1_HP_Dyn_ConstP.CG2Hp5_Gain[6 * memOffset + k] *
        M1_HP_Dyn_U.M1_RBM_cmd[36 + memOffset];
    }

    /* End of Gain: '<S1>/CG2Hp5' */

    /* DiscreteTransferFcn: '<S1>/S6HP_dyn_dTF' incorporates:
     *  Gain: '<S1>/HpK4'
     */
    rtb_HpK4[k] = 1.6612584871854693E+8 * denAccum;
  }

  for (k = 0; k < 6; k++) {
    /* DiscreteTransferFcn: '<S1>/S7HP_dyn_dTF' */
    memOffset = k << 2;
    denAccum_tmp = M1_HP_Dyn_DW.S7HP_dyn_dTF_states[memOffset + 1];
    denAccum_tmp_0 = M1_HP_Dyn_DW.S7HP_dyn_dTF_states[memOffset + 2];
    denAccum_tmp_1 = M1_HP_Dyn_DW.S7HP_dyn_dTF_states[memOffset + 3];
    denAccum = (((rtb_CG2Hp6[k] - -3.9323939066475968 *
                  M1_HP_Dyn_DW.S7HP_dyn_dTF_states[memOffset]) - denAccum_tmp *
                 5.7979978715556353) - denAccum_tmp_0 * -3.7988101955494251) -
      denAccum_tmp_1 * 0.93320623842210537;
    S7HP_dyn_dTF_tmp[k] = denAccum;
    denAccum *= 0.00010770254974318945;
    denAccum += 9.54959583974631E-7 * M1_HP_Dyn_DW.S7HP_dyn_dTF_states[memOffset];
    denAccum += denAccum_tmp * -0.00021444819472271384;
    denAccum += denAccum_tmp_0 * -9.5106922459374865E-7;
    denAccum += denAccum_tmp_1 * 0.00010674953533890526;

    /* Outport: '<Root>/HP_F_cmd' incorporates:
     *  DiscreteTransferFcn: '<S1>/S7HP_dyn_dTF'
     *  Gain: '<S1>/HpK6'
     */
    M1_HP_Dyn_Y.HP_F_cmd[k] = rtb_HpK8[k];
    M1_HP_Dyn_Y.HP_F_cmd[k + 6] = rtb_HpK1[k];
    M1_HP_Dyn_Y.HP_F_cmd[k + 12] = rtb_HpK2[k];
    M1_HP_Dyn_Y.HP_F_cmd[k + 18] = rtb_HpK5[k];
    M1_HP_Dyn_Y.HP_F_cmd[k + 24] = rtb_HpK3[k];
    M1_HP_Dyn_Y.HP_F_cmd[k + 30] = rtb_HpK4[k];
    M1_HP_Dyn_Y.HP_F_cmd[k + 36] = 1.6612584871854693E+8 * denAccum;
  }

  /* Update for DiscreteTransferFcn: '<S1>/S1HP_dyn_dTF' */
  for (k = 0; k < 6; k++) {
    memOffset = k << 2;
    M1_HP_Dyn_DW.S1HP_dyn_dTF_states[memOffset + 3] =
      M1_HP_Dyn_DW.S1HP_dyn_dTF_states[memOffset + 2];
    M1_HP_Dyn_DW.S1HP_dyn_dTF_states[memOffset + 2] =
      M1_HP_Dyn_DW.S1HP_dyn_dTF_states[memOffset + 1];
    M1_HP_Dyn_DW.S1HP_dyn_dTF_states[memOffset + 1] =
      M1_HP_Dyn_DW.S1HP_dyn_dTF_states[memOffset];
    M1_HP_Dyn_DW.S1HP_dyn_dTF_states[memOffset] = S1HP_dyn_dTF_tmp[k];
  }

  /* End of Update for DiscreteTransferFcn: '<S1>/S1HP_dyn_dTF' */

  /* Update for DiscreteTransferFcn: '<S1>/S2HP_dyn_dTF' */
  for (k = 0; k < 6; k++) {
    memOffset = k << 2;
    M1_HP_Dyn_DW.S2HP_dyn_dTF_states[memOffset + 3] =
      M1_HP_Dyn_DW.S2HP_dyn_dTF_states[memOffset + 2];
    M1_HP_Dyn_DW.S2HP_dyn_dTF_states[memOffset + 2] =
      M1_HP_Dyn_DW.S2HP_dyn_dTF_states[memOffset + 1];
    M1_HP_Dyn_DW.S2HP_dyn_dTF_states[memOffset + 1] =
      M1_HP_Dyn_DW.S2HP_dyn_dTF_states[memOffset];
    M1_HP_Dyn_DW.S2HP_dyn_dTF_states[memOffset] = S2HP_dyn_dTF_tmp[k];
  }

  /* End of Update for DiscreteTransferFcn: '<S1>/S2HP_dyn_dTF' */

  /* Update for DiscreteTransferFcn: '<S1>/S3HP_dyn_dTF' */
  for (k = 0; k < 6; k++) {
    memOffset = k << 2;
    M1_HP_Dyn_DW.S3HP_dyn_dTF_states[memOffset + 3] =
      M1_HP_Dyn_DW.S3HP_dyn_dTF_states[memOffset + 2];
    M1_HP_Dyn_DW.S3HP_dyn_dTF_states[memOffset + 2] =
      M1_HP_Dyn_DW.S3HP_dyn_dTF_states[memOffset + 1];
    M1_HP_Dyn_DW.S3HP_dyn_dTF_states[memOffset + 1] =
      M1_HP_Dyn_DW.S3HP_dyn_dTF_states[memOffset];
    M1_HP_Dyn_DW.S3HP_dyn_dTF_states[memOffset] = S3HP_dyn_dTF_tmp[k];
  }

  /* End of Update for DiscreteTransferFcn: '<S1>/S3HP_dyn_dTF' */

  /* Update for DiscreteTransferFcn: '<S1>/S4HP_dyn_dTF' */
  for (k = 0; k < 6; k++) {
    memOffset = k << 2;
    M1_HP_Dyn_DW.S4HP_dyn_dTF_states[memOffset + 3] =
      M1_HP_Dyn_DW.S4HP_dyn_dTF_states[memOffset + 2];
    M1_HP_Dyn_DW.S4HP_dyn_dTF_states[memOffset + 2] =
      M1_HP_Dyn_DW.S4HP_dyn_dTF_states[memOffset + 1];
    M1_HP_Dyn_DW.S4HP_dyn_dTF_states[memOffset + 1] =
      M1_HP_Dyn_DW.S4HP_dyn_dTF_states[memOffset];
    M1_HP_Dyn_DW.S4HP_dyn_dTF_states[memOffset] = S4HP_dyn_dTF_tmp[k];
  }

  /* End of Update for DiscreteTransferFcn: '<S1>/S4HP_dyn_dTF' */

  /* Update for DiscreteTransferFcn: '<S1>/S5HP_dyn_dTF' */
  for (k = 0; k < 6; k++) {
    memOffset = k << 2;
    M1_HP_Dyn_DW.S5HP_dyn_dTF_states[memOffset + 3] =
      M1_HP_Dyn_DW.S5HP_dyn_dTF_states[memOffset + 2];
    M1_HP_Dyn_DW.S5HP_dyn_dTF_states[memOffset + 2] =
      M1_HP_Dyn_DW.S5HP_dyn_dTF_states[memOffset + 1];
    M1_HP_Dyn_DW.S5HP_dyn_dTF_states[memOffset + 1] =
      M1_HP_Dyn_DW.S5HP_dyn_dTF_states[memOffset];
    M1_HP_Dyn_DW.S5HP_dyn_dTF_states[memOffset] = S5HP_dyn_dTF_tmp[k];
  }

  /* End of Update for DiscreteTransferFcn: '<S1>/S5HP_dyn_dTF' */

  /* Update for DiscreteTransferFcn: '<S1>/S6HP_dyn_dTF' */
  for (k = 0; k < 6; k++) {
    memOffset = k << 2;
    M1_HP_Dyn_DW.S6HP_dyn_dTF_states[memOffset + 3] =
      M1_HP_Dyn_DW.S6HP_dyn_dTF_states[memOffset + 2];
    M1_HP_Dyn_DW.S6HP_dyn_dTF_states[memOffset + 2] =
      M1_HP_Dyn_DW.S6HP_dyn_dTF_states[memOffset + 1];
    M1_HP_Dyn_DW.S6HP_dyn_dTF_states[memOffset + 1] =
      M1_HP_Dyn_DW.S6HP_dyn_dTF_states[memOffset];
    M1_HP_Dyn_DW.S6HP_dyn_dTF_states[memOffset] = S6HP_dyn_dTF_tmp[k];
  }

  /* End of Update for DiscreteTransferFcn: '<S1>/S6HP_dyn_dTF' */

  /* Update for DiscreteTransferFcn: '<S1>/S7HP_dyn_dTF' */
  for (k = 0; k < 6; k++) {
    memOffset = k << 2;
    M1_HP_Dyn_DW.S7HP_dyn_dTF_states[memOffset + 3] =
      M1_HP_Dyn_DW.S7HP_dyn_dTF_states[memOffset + 2];
    M1_HP_Dyn_DW.S7HP_dyn_dTF_states[memOffset + 2] =
      M1_HP_Dyn_DW.S7HP_dyn_dTF_states[memOffset + 1];
    M1_HP_Dyn_DW.S7HP_dyn_dTF_states[memOffset + 1] =
      M1_HP_Dyn_DW.S7HP_dyn_dTF_states[memOffset];
    M1_HP_Dyn_DW.S7HP_dyn_dTF_states[memOffset] = S7HP_dyn_dTF_tmp[k];
  }

  /* End of Update for DiscreteTransferFcn: '<S1>/S7HP_dyn_dTF' */
}

/* Model initialize function */
void M1_HP_Dyn_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(M1_HP_Dyn_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&M1_HP_Dyn_DW, 0,
                sizeof(DW_M1_HP_Dyn_T));

  /* external inputs */
  (void)memset(&M1_HP_Dyn_U, 0, sizeof(ExtU_M1_HP_Dyn_T));

  /* external outputs */
  (void) memset(&M1_HP_Dyn_Y.HP_F_cmd[0], 0,
                42U*sizeof(real_T));
}

/* Model terminate function */
void M1_HP_Dyn_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
