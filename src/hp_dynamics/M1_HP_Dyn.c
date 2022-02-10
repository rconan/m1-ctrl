/*
 * File: M1_HP_Dyn.c
 *
 * Code generated for Simulink model 'M1_HP_Dyn'.
 *
 * Model version                  : 1.788
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Feb 10 11:49:55 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "M1_HP_Dyn.h"
#include "M1_HP_Dyn_private.h"

/* Exported block parameters */
real_T S1_HPstiff = 1.4293878534590691E+8;/* Variable: S1_HPstiff
                                           * Referenced by: '<S1>/HpK8'
                                           */
real_T S1_M1RBM2HP[36] = { 0.45316620426650039, -0.45320099619970017,
  0.22076712399478748, 0.6736409970367232, -0.67365191578851225,
  -0.22078757628106929, 0.51787128706274577, 0.51788371013690881,
  -0.65038384320181131, 0.13553726442641428, 0.13554657930211297,
  -0.65038850583103713, 0.72406079512619359, 0.72405561732726087,
  0.72605169966161343, 0.72567942920047235, 0.72566890054333422,
  0.72605474095037836, -1.6892659005258077, -1.6892501004491469,
  -0.33013193533525687, 2.0226468330892375, 2.0226476498841333,
  -0.3301628535510846, -1.3559507174012397, 1.3558249538661262,
  2.1448423595989019, 0.78023019187393639, -0.7804217314241596,
  -2.1449887437087858, 2.0267313005623837, -2.0264630567390984,
  2.0209881335582494, -2.0243893234252619, 2.0244054666644598,
  -2.020696625807858 } ;               /* Variable: S1_M1RBM2HP
                                        * Referenced by: '<S1>/CG2Hp6'
                                        */

real_T S2_HPstiff = 1.4293878534590691E+8;/* Variable: S2_HPstiff
                                           * Referenced by: '<S1>/HpK1'
                                           */
real_T S2_M1RBM2HP[36] = { 0.45313686160222133, -0.45316435257360271,
  0.22077424859596467, 0.673589785725886, -0.6736396099561125,
  -0.22082040147567061, 0.51783775867411708, 0.51787091660476814,
  -0.65039086201423912, 0.13549556127199761, 0.13548692643360435,
  -0.65044901778176667, 0.72416404782278, 0.72407646089217415,
  0.72605749814962561, 0.72579990987696441, 0.72579260261381273,
  0.72619762412792377, -1.6892151705267771, -1.6893040407493396,
  -0.33021715975002985, 2.0227260777745979, 2.022572294635987,
  -0.33017566817528277, -1.3559945810776004, 1.3560905385511746,
  2.1449266818468078, 0.780147259118827, -0.78006832488623712,
  -2.144944644417544, 2.0265629861842895, -2.0264840287237, 2.0203834946778843,
  -2.024664488524484, 2.0241355597557109, -2.0213765369161663 } ;/* Variable: S2_M1RBM2HP
                                                                  * Referenced by: '<S1>/CG2Hp8'
                                                                  */

real_T S3_HPstiff = 1.4293878534590691E+8;/* Variable: S3_HPstiff
                                           * Referenced by: '<S1>/HpK2'
                                           */
real_T S3_M1RBM2HP[36] = { 0.45316574731969433, -0.45314666457111358,
  0.2208031633226224, 0.67364646938507589, -0.67361561575497553,
  -0.22079217321893421, 0.51786018316136118, 0.5178438836582181,
  -0.65043924721505975, 0.135478059680234, 0.13551557683829574,
  -0.650387108938488, 0.72409475940966794, 0.72415569511706224,
  0.726170748143599, 0.72582064221982157, 0.7257686979516863, 0.7260254169126158,
  -1.6893092956049764, -1.6891969633284334, -0.33019807056004707,
  2.022540854652715, 2.0227475625918618, -0.33025541725134472,
  -1.3561268857418045, 1.3560474551147288, 2.1446310087802782,
  0.77986331366897088, -0.78025477639121388, -2.1451453087519465,
  2.0264349303914586, -2.0262291815157831, 2.0201821709445031,
  -2.0250100872812511, 2.0247342559668722, -2.0211103856813235 } ;/* Variable: S3_M1RBM2HP
                                                                   * Referenced by: '<S1>/CG2Hp1'
                                                                   */

real_T S4_HPstiff = 1.4293878534590691E+8;/* Variable: S4_HPstiff
                                           * Referenced by: '<S1>/HpK5'
                                           */
real_T S4_M1RBM2HP[36] = { 0.45317484881055997, -0.45317861231083645,
  0.22079674215571984, 0.67368663897267589, -0.673629618424038,
  -0.2207630151407742, 0.51785609254851916, 0.517861975560603,
  -0.65035459806957985, 0.13550851146990175, 0.13551309672176554,
  -0.65035255287540439, 0.72406393396860591, 0.72406894780027686,
  0.72603934639261292, 0.72569038436746869, 0.72568165998267953,
  0.72602891862067653, -1.6892762638438918, -1.689252772577545,
  -0.33011091603077092, 2.0225720951136106, 2.0225616190196254,
  -0.330131240563691, -1.3560273056727603, 1.3561326707958177,
  2.1450672778898472, 0.78025333714556866, -0.77997659629669513,
  -2.14479666332228, 2.0261595868369522, -2.026032459053281, 2.0204929418487922,
  -2.0252853402069939, 2.0248318282623954, -2.0207416896467336 } ;/* Variable: S4_M1RBM2HP
                                                                   * Referenced by: '<S1>/CG2Hp2'
                                                                   */

real_T S5_HPstiff = 1.4293878534590691E+8;/* Variable: S5_HPstiff
                                           * Referenced by: '<S1>/HpK3'
                                           */
real_T S5_M1RBM2HP[36] = { 0.45313229629291063, -0.4531785042365063,
  0.22079899000810529, 0.67360611101176893, -0.6736403581320517,
  -0.22079539929129452, 0.51785899129836233, 0.5178639856622429,
  -0.65039325813212789, 0.13552239395922491, 0.13550544204364112,
  -0.650444056522553, 0.72413772701693868, 0.72409484939669977,
  0.72600840853792759, 0.72576135776406758, 0.725816229840648,
  0.72612510147716858, -1.6891617270221797, -1.6892842580996672,
  -0.33031110906793709, 2.0227020364928046, 2.0225604743709118,
  -0.33025111351452807, -1.3560561582152666, 1.3560547427817793,
  2.1450497906302317, 0.78015080281996163, -0.77983761707841737,
  -2.1445087272085988, 2.0262945742033156, -2.0264121643553756,
  2.0209088137861171, -2.02484065669854, 2.0250219191121035, -2.0203380839329887
} ;                                    /* Variable: S5_M1RBM2HP
                                        * Referenced by: '<S1>/CG2Hp3'
                                        */

real_T S6_HPstiff = 1.4293878534590691E+8;/* Variable: S6_HPstiff
                                           * Referenced by: '<S1>/HpK4'
                                           */
real_T S6_M1RBM2HP[36] = { 0.45316029236086042, -0.45314235509787065,
  0.22082676718645386, 0.67365010653937185, -0.67358062441579536,
  -0.22077433421923889, 0.51785582860799617, 0.51787297738580051,
  -0.65045026810859718, 0.13549906478505941, 0.13552481369949712,
  -0.6503960284589273, 0.72407912480562109, 0.7241457766611511,
  0.72615836623437546, 0.72581207286770622, 0.72576211221698317,
  0.72602214501981277, -1.6893372741829058, -1.6891898087468276,
  -0.33020089008017134, 2.0225946991000776, 2.0226794930778174,
  -0.3303162113080283, -1.3560757054274244, 1.3559249462695231,
  2.1448756318713889, 0.7800569453849876, -0.78009400332856071,
  -2.1447940204922888, 2.0264996490859177, -2.0265961225374092,
  2.0213609396058279, -2.0242985944788376, 2.0247572222583785,
  -2.0202093018779417 } ;              /* Variable: S6_M1RBM2HP
                                        * Referenced by: '<S1>/CG2Hp4'
                                        */

real_T S7_HPstiff = 1.4293878534590691E+8;/* Variable: S7_HPstiff
                                           * Referenced by: '<S1>/HpK6'
                                           */
real_T S7_M1RBM2HP[36] = { 0.45244396288532968, -0.45244566289302363,
  0.22052066997925091, 0.67198011560532889, -0.67202323824543986,
  -0.22052837540800113, 0.51677675271050771, 0.51676419241312588,
  -0.651588146435804, 0.13546135345614824, 0.13546825648987859,
  -0.65156455674913116, 0.72627721261554512, 0.72628850943838918,
  0.7235534737623629, 0.72889901975474869, 0.72897329882949213,
  0.7235623624031392, -1.6982467200615741, -1.6981544569611835,
  -0.31980713081820533, 2.024818200648749, 2.0249153593011697,
  -0.31966748258228833, -1.3593824337838709, 1.3593422061703235,
  2.1521830941915385, 0.79363514912296051, -0.79368071885792546,
  -2.1521070991036066, 2.026282075007809, -2.0262756231624985,
  2.0258424000376967, -2.0223020034862071, 2.0223493547558777,
  -2.0255785210130384 } ;              /* Variable: S7_M1RBM2HP
                                        * Referenced by: '<S1>/CG2Hp5'
                                        */

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
  real_T denAccum_0;
  real_T denAccum_1;
  real_T denAccum_2;
  real_T denAccum_3;
  real_T denAccum_4;
  real_T denAccum_5;
  real_T rtb_CG2Hp6[6];
  int32_T k;
  int32_T i;
  int32_T memOffset_tmp;
  real_T denAccum_tmp;
  real_T denAccum_tmp_0;
  real_T denAccum_tmp_1;
  real_T denAccum_tmp_2;
  real_T denAccum_tmp_3;
  real_T denAccum_tmp_4;
  real_T denAccum_tmp_5;
  real_T denAccum_tmp_6;
  real_T denAccum_tmp_7;
  real_T denAccum_tmp_8;
  real_T denAccum_tmp_9;
  real_T denAccum_tmp_a;
  real_T denAccum_tmp_b;
  real_T denAccum_tmp_c;
  real_T denAccum_tmp_d;
  real_T denAccum_tmp_e;
  real_T denAccum_tmp_f;
  real_T denAccum_tmp_g;
  real_T denAccum_tmp_h;
  real_T denAccum_tmp_i;
  real_T denAccum_tmp_j;
  for (k = 0; k < 6; k++) {
    /* Gain: '<S1>/CG2Hp6' incorporates:
     *  Inport: '<Root>/M1_RBM_cmd'
     */
    rtb_CG2Hp6[k] = 0.0;
    for (i = 0; i < 6; i++) {
      rtb_CG2Hp6[k] += S1_M1RBM2HP[6 * i + k] * M1_HP_Dyn_U.M1_RBM_cmd[i];
    }

    /* End of Gain: '<S1>/CG2Hp6' */

    /* DiscreteTransferFcn: '<S1>/S1HP_dyn_dTF' incorporates:
     *  DiscreteTransferFcn: '<S1>/S2HP_dyn_dTF'
     *  DiscreteTransferFcn: '<S1>/S2HP_dyn_dTF'
     *  DiscreteTransferFcn: '<S1>/S3HP_dyn_dTF'
     *  DiscreteTransferFcn: '<S1>/S3HP_dyn_dTF'
     *  DiscreteTransferFcn: '<S1>/S4HP_dyn_dTF'
     *  DiscreteTransferFcn: '<S1>/S4HP_dyn_dTF'
     *  DiscreteTransferFcn: '<S1>/S5HP_dyn_dTF'
     *  DiscreteTransferFcn: '<S1>/S5HP_dyn_dTF'
     *  DiscreteTransferFcn: '<S1>/S6HP_dyn_dTF'
     *  DiscreteTransferFcn: '<S1>/S6HP_dyn_dTF'
     *  DiscreteTransferFcn: '<S1>/S7HP_dyn_dTF'
     *  DiscreteTransferFcn: '<S1>/S7HP_dyn_dTF'
     */
    memOffset_tmp = k << 2;
    denAccum_tmp = M1_HP_Dyn_S1HP_dyn_dTF_states[memOffset_tmp + 1];
    denAccum_tmp_0 = M1_HP_Dyn_S1HP_dyn_dTF_states[memOffset_tmp + 2];
    denAccum_tmp_1 = M1_HP_Dyn_S1HP_dyn_dTF_states[memOffset_tmp + 3];
    denAccum = (((rtb_CG2Hp6[k] - -3.9324030529437657 *
                  M1_HP_Dyn_S1HP_dyn_dTF_states[memOffset_tmp]) - denAccum_tmp *
                 5.7980159366164923) - denAccum_tmp_0 * -3.7988189837355097) -
      denAccum_tmp_1 * 0.93320610759369726;

    /* Gain: '<S1>/CG2Hp8' incorporates:
     *  Inport: '<Root>/M1_RBM_cmd'
     */
    rtb_CG2Hp6[k] = 0.0;
    for (i = 0; i < 6; i++) {
      rtb_CG2Hp6[k] += S2_M1RBM2HP[6 * i + k] * M1_HP_Dyn_U.M1_RBM_cmd[6 + i];
    }

    /* End of Gain: '<S1>/CG2Hp8' */

    /* DiscreteTransferFcn: '<S1>/S2HP_dyn_dTF' */
    denAccum_tmp_2 = M1_HP_Dyn_S2HP_dyn_dTF_states[memOffset_tmp + 1];
    denAccum_tmp_3 = M1_HP_Dyn_S2HP_dyn_dTF_states[memOffset_tmp + 2];
    denAccum_tmp_4 = M1_HP_Dyn_S2HP_dyn_dTF_states[memOffset_tmp + 3];
    denAccum_0 = (((rtb_CG2Hp6[k] - -3.9324030529437657 *
                    M1_HP_Dyn_S2HP_dyn_dTF_states[memOffset_tmp]) -
                   denAccum_tmp_2 * 5.7980159366164923) - denAccum_tmp_3 *
                  -3.7988189837355097) - denAccum_tmp_4 * 0.93320610759369726;

    /* Gain: '<S1>/CG2Hp1' incorporates:
     *  Inport: '<Root>/M1_RBM_cmd'
     */
    rtb_CG2Hp6[k] = 0.0;
    for (i = 0; i < 6; i++) {
      rtb_CG2Hp6[k] += S3_M1RBM2HP[6 * i + k] * M1_HP_Dyn_U.M1_RBM_cmd[12 + i];
    }

    /* End of Gain: '<S1>/CG2Hp1' */

    /* DiscreteTransferFcn: '<S1>/S3HP_dyn_dTF' */
    denAccum_tmp_5 = M1_HP_Dyn_S3HP_dyn_dTF_states[memOffset_tmp + 1];
    denAccum_tmp_6 = M1_HP_Dyn_S3HP_dyn_dTF_states[memOffset_tmp + 2];
    denAccum_tmp_7 = M1_HP_Dyn_S3HP_dyn_dTF_states[memOffset_tmp + 3];
    denAccum_1 = (((rtb_CG2Hp6[k] - -3.9324030529437657 *
                    M1_HP_Dyn_S3HP_dyn_dTF_states[memOffset_tmp]) -
                   denAccum_tmp_5 * 5.7980159366164923) - denAccum_tmp_6 *
                  -3.7988189837355097) - denAccum_tmp_7 * 0.93320610759369726;

    /* Gain: '<S1>/CG2Hp2' incorporates:
     *  Inport: '<Root>/M1_RBM_cmd'
     */
    rtb_CG2Hp6[k] = 0.0;
    for (i = 0; i < 6; i++) {
      rtb_CG2Hp6[k] += S4_M1RBM2HP[6 * i + k] * M1_HP_Dyn_U.M1_RBM_cmd[18 + i];
    }

    /* End of Gain: '<S1>/CG2Hp2' */

    /* DiscreteTransferFcn: '<S1>/S4HP_dyn_dTF' */
    denAccum_tmp_8 = M1_HP_Dyn_S4HP_dyn_dTF_states[memOffset_tmp + 1];
    denAccum_tmp_9 = M1_HP_Dyn_S4HP_dyn_dTF_states[memOffset_tmp + 2];
    denAccum_tmp_a = M1_HP_Dyn_S4HP_dyn_dTF_states[memOffset_tmp + 3];
    denAccum_2 = (((rtb_CG2Hp6[k] - -3.9324030529437657 *
                    M1_HP_Dyn_S4HP_dyn_dTF_states[memOffset_tmp]) -
                   denAccum_tmp_8 * 5.7980159366164923) - denAccum_tmp_9 *
                  -3.7988189837355097) - denAccum_tmp_a * 0.93320610759369726;

    /* Gain: '<S1>/CG2Hp3' incorporates:
     *  Inport: '<Root>/M1_RBM_cmd'
     */
    rtb_CG2Hp6[k] = 0.0;
    for (i = 0; i < 6; i++) {
      rtb_CG2Hp6[k] += S5_M1RBM2HP[6 * i + k] * M1_HP_Dyn_U.M1_RBM_cmd[24 + i];
    }

    /* End of Gain: '<S1>/CG2Hp3' */

    /* DiscreteTransferFcn: '<S1>/S5HP_dyn_dTF' */
    denAccum_tmp_b = M1_HP_Dyn_S5HP_dyn_dTF_states[memOffset_tmp + 1];
    denAccum_tmp_c = M1_HP_Dyn_S5HP_dyn_dTF_states[memOffset_tmp + 2];
    denAccum_tmp_d = M1_HP_Dyn_S5HP_dyn_dTF_states[memOffset_tmp + 3];
    denAccum_3 = (((rtb_CG2Hp6[k] - -3.9324030529437657 *
                    M1_HP_Dyn_S5HP_dyn_dTF_states[memOffset_tmp]) -
                   denAccum_tmp_b * 5.7980159366164923) - denAccum_tmp_c *
                  -3.7988189837355097) - denAccum_tmp_d * 0.93320610759369726;

    /* Gain: '<S1>/CG2Hp4' incorporates:
     *  Inport: '<Root>/M1_RBM_cmd'
     */
    rtb_CG2Hp6[k] = 0.0;
    for (i = 0; i < 6; i++) {
      rtb_CG2Hp6[k] += S6_M1RBM2HP[6 * i + k] * M1_HP_Dyn_U.M1_RBM_cmd[30 + i];
    }

    /* End of Gain: '<S1>/CG2Hp4' */

    /* DiscreteTransferFcn: '<S1>/S6HP_dyn_dTF' */
    denAccum_tmp_e = M1_HP_Dyn_S6HP_dyn_dTF_states[memOffset_tmp + 1];
    denAccum_tmp_f = M1_HP_Dyn_S6HP_dyn_dTF_states[memOffset_tmp + 2];
    denAccum_tmp_g = M1_HP_Dyn_S6HP_dyn_dTF_states[memOffset_tmp + 3];
    denAccum_4 = (((rtb_CG2Hp6[k] - -3.9324030529437657 *
                    M1_HP_Dyn_S6HP_dyn_dTF_states[memOffset_tmp]) -
                   denAccum_tmp_e * 5.7980159366164923) - denAccum_tmp_f *
                  -3.7988189837355097) - denAccum_tmp_g * 0.93320610759369726;

    /* Gain: '<S1>/CG2Hp5' incorporates:
     *  Inport: '<Root>/M1_RBM_cmd'
     */
    rtb_CG2Hp6[k] = 0.0;
    for (i = 0; i < 6; i++) {
      rtb_CG2Hp6[k] += S7_M1RBM2HP[6 * i + k] * M1_HP_Dyn_U.M1_RBM_cmd[36 + i];
    }

    /* End of Gain: '<S1>/CG2Hp5' */

    /* DiscreteTransferFcn: '<S1>/S7HP_dyn_dTF' */
    denAccum_tmp_h = M1_HP_Dyn_S7HP_dyn_dTF_states[memOffset_tmp + 1];
    denAccum_tmp_i = M1_HP_Dyn_S7HP_dyn_dTF_states[memOffset_tmp + 2];
    denAccum_tmp_j = M1_HP_Dyn_S7HP_dyn_dTF_states[memOffset_tmp + 3];
    denAccum_5 = (((rtb_CG2Hp6[k] - -3.9324030529437657 *
                    M1_HP_Dyn_S7HP_dyn_dTF_states[memOffset_tmp]) -
                   denAccum_tmp_h * 5.7980159366164923) - denAccum_tmp_i *
                  -3.7988189837355097) - denAccum_tmp_j * 0.93320610759369726;

    /* Outport: '<Root>/HP_F_cmd' incorporates:
     *  DiscreteTransferFcn: '<S1>/S1HP_dyn_dTF'
     *  DiscreteTransferFcn: '<S1>/S2HP_dyn_dTF'
     *  DiscreteTransferFcn: '<S1>/S3HP_dyn_dTF'
     *  DiscreteTransferFcn: '<S1>/S4HP_dyn_dTF'
     *  DiscreteTransferFcn: '<S1>/S5HP_dyn_dTF'
     *  DiscreteTransferFcn: '<S1>/S6HP_dyn_dTF'
     *  DiscreteTransferFcn: '<S1>/S7HP_dyn_dTF'
     *  Gain: '<S1>/HpK1'
     *  Gain: '<S1>/HpK2'
     *  Gain: '<S1>/HpK3'
     *  Gain: '<S1>/HpK4'
     *  Gain: '<S1>/HpK5'
     *  Gain: '<S1>/HpK6'
     *  Gain: '<S1>/HpK8'
     */
    M1_HP_Dyn_Y.HP_F_cmd[k] = ((((0.00010538306295552853 * denAccum +
      9.3078381572247558E-7 * M1_HP_Dyn_S1HP_dyn_dTF_states[memOffset_tmp]) +
      denAccum_tmp * -0.00020983345936705571) + denAccum_tmp_0 *
      -9.27018359164759E-7) + denAccum_tmp_1 * 0.00010445416186808491) *
      S1_HPstiff;
    M1_HP_Dyn_Y.HP_F_cmd[k + 6] = ((((0.00010538306295552853 * denAccum_0 +
      9.3078381572247558E-7 * M1_HP_Dyn_S2HP_dyn_dTF_states[memOffset_tmp]) +
      denAccum_tmp_2 * -0.00020983345936705571) + denAccum_tmp_3 *
      -9.27018359164759E-7) + denAccum_tmp_4 * 0.00010445416186808491) *
      S2_HPstiff;
    M1_HP_Dyn_Y.HP_F_cmd[k + 12] = ((((0.00010538306295552853 * denAccum_1 +
      9.3078381572247558E-7 * M1_HP_Dyn_S3HP_dyn_dTF_states[memOffset_tmp]) +
      denAccum_tmp_5 * -0.00020983345936705571) + denAccum_tmp_6 *
      -9.27018359164759E-7) + denAccum_tmp_7 * 0.00010445416186808491) *
      S3_HPstiff;
    M1_HP_Dyn_Y.HP_F_cmd[k + 18] = ((((0.00010538306295552853 * denAccum_2 +
      9.3078381572247558E-7 * M1_HP_Dyn_S4HP_dyn_dTF_states[memOffset_tmp]) +
      denAccum_tmp_8 * -0.00020983345936705571) + denAccum_tmp_9 *
      -9.27018359164759E-7) + denAccum_tmp_a * 0.00010445416186808491) *
      S4_HPstiff;
    M1_HP_Dyn_Y.HP_F_cmd[k + 24] = ((((0.00010538306295552853 * denAccum_3 +
      9.3078381572247558E-7 * M1_HP_Dyn_S5HP_dyn_dTF_states[memOffset_tmp]) +
      denAccum_tmp_b * -0.00020983345936705571) + denAccum_tmp_c *
      -9.27018359164759E-7) + denAccum_tmp_d * 0.00010445416186808491) *
      S5_HPstiff;
    M1_HP_Dyn_Y.HP_F_cmd[k + 30] = ((((0.00010538306295552853 * denAccum_4 +
      9.3078381572247558E-7 * M1_HP_Dyn_S6HP_dyn_dTF_states[memOffset_tmp]) +
      denAccum_tmp_e * -0.00020983345936705571) + denAccum_tmp_f *
      -9.27018359164759E-7) + denAccum_tmp_g * 0.00010445416186808491) *
      S6_HPstiff;
    M1_HP_Dyn_Y.HP_F_cmd[k + 36] = ((((0.00010538306295552853 * denAccum_5 +
      9.3078381572247558E-7 * M1_HP_Dyn_S7HP_dyn_dTF_states[memOffset_tmp]) +
      denAccum_tmp_h * -0.00020983345936705571) + denAccum_tmp_i *
      -9.27018359164759E-7) + denAccum_tmp_j * 0.00010445416186808491) *
      S7_HPstiff;

    /* Update for DiscreteTransferFcn: '<S1>/S1HP_dyn_dTF' */
    M1_HP_Dyn_S1HP_dyn_dTF_states[memOffset_tmp + 3] =
      M1_HP_Dyn_S1HP_dyn_dTF_states[memOffset_tmp + 2];
    M1_HP_Dyn_S1HP_dyn_dTF_states[memOffset_tmp + 2] =
      M1_HP_Dyn_S1HP_dyn_dTF_states[memOffset_tmp + 1];
    M1_HP_Dyn_S1HP_dyn_dTF_states[memOffset_tmp + 1] =
      M1_HP_Dyn_S1HP_dyn_dTF_states[memOffset_tmp];
    M1_HP_Dyn_S1HP_dyn_dTF_states[memOffset_tmp] = denAccum;

    /* Update for DiscreteTransferFcn: '<S1>/S2HP_dyn_dTF' */
    M1_HP_Dyn_S2HP_dyn_dTF_states[memOffset_tmp + 3] =
      M1_HP_Dyn_S2HP_dyn_dTF_states[memOffset_tmp + 2];
    M1_HP_Dyn_S2HP_dyn_dTF_states[memOffset_tmp + 2] =
      M1_HP_Dyn_S2HP_dyn_dTF_states[memOffset_tmp + 1];
    M1_HP_Dyn_S2HP_dyn_dTF_states[memOffset_tmp + 1] =
      M1_HP_Dyn_S2HP_dyn_dTF_states[memOffset_tmp];
    M1_HP_Dyn_S2HP_dyn_dTF_states[memOffset_tmp] = denAccum_0;

    /* Update for DiscreteTransferFcn: '<S1>/S3HP_dyn_dTF' */
    M1_HP_Dyn_S3HP_dyn_dTF_states[memOffset_tmp + 3] =
      M1_HP_Dyn_S3HP_dyn_dTF_states[memOffset_tmp + 2];
    M1_HP_Dyn_S3HP_dyn_dTF_states[memOffset_tmp + 2] =
      M1_HP_Dyn_S3HP_dyn_dTF_states[memOffset_tmp + 1];
    M1_HP_Dyn_S3HP_dyn_dTF_states[memOffset_tmp + 1] =
      M1_HP_Dyn_S3HP_dyn_dTF_states[memOffset_tmp];
    M1_HP_Dyn_S3HP_dyn_dTF_states[memOffset_tmp] = denAccum_1;

    /* Update for DiscreteTransferFcn: '<S1>/S4HP_dyn_dTF' */
    M1_HP_Dyn_S4HP_dyn_dTF_states[memOffset_tmp + 3] =
      M1_HP_Dyn_S4HP_dyn_dTF_states[memOffset_tmp + 2];
    M1_HP_Dyn_S4HP_dyn_dTF_states[memOffset_tmp + 2] =
      M1_HP_Dyn_S4HP_dyn_dTF_states[memOffset_tmp + 1];
    M1_HP_Dyn_S4HP_dyn_dTF_states[memOffset_tmp + 1] =
      M1_HP_Dyn_S4HP_dyn_dTF_states[memOffset_tmp];
    M1_HP_Dyn_S4HP_dyn_dTF_states[memOffset_tmp] = denAccum_2;

    /* Update for DiscreteTransferFcn: '<S1>/S5HP_dyn_dTF' */
    M1_HP_Dyn_S5HP_dyn_dTF_states[memOffset_tmp + 3] =
      M1_HP_Dyn_S5HP_dyn_dTF_states[memOffset_tmp + 2];
    M1_HP_Dyn_S5HP_dyn_dTF_states[memOffset_tmp + 2] =
      M1_HP_Dyn_S5HP_dyn_dTF_states[memOffset_tmp + 1];
    M1_HP_Dyn_S5HP_dyn_dTF_states[memOffset_tmp + 1] =
      M1_HP_Dyn_S5HP_dyn_dTF_states[memOffset_tmp];
    M1_HP_Dyn_S5HP_dyn_dTF_states[memOffset_tmp] = denAccum_3;

    /* Update for DiscreteTransferFcn: '<S1>/S6HP_dyn_dTF' */
    M1_HP_Dyn_S6HP_dyn_dTF_states[memOffset_tmp + 3] =
      M1_HP_Dyn_S6HP_dyn_dTF_states[memOffset_tmp + 2];
    M1_HP_Dyn_S6HP_dyn_dTF_states[memOffset_tmp + 2] =
      M1_HP_Dyn_S6HP_dyn_dTF_states[memOffset_tmp + 1];
    M1_HP_Dyn_S6HP_dyn_dTF_states[memOffset_tmp + 1] =
      M1_HP_Dyn_S6HP_dyn_dTF_states[memOffset_tmp];
    M1_HP_Dyn_S6HP_dyn_dTF_states[memOffset_tmp] = denAccum_4;

    /* Update for DiscreteTransferFcn: '<S1>/S7HP_dyn_dTF' */
    M1_HP_Dyn_S7HP_dyn_dTF_states[memOffset_tmp + 3] =
      M1_HP_Dyn_S7HP_dyn_dTF_states[memOffset_tmp + 2];
    M1_HP_Dyn_S7HP_dyn_dTF_states[memOffset_tmp + 2] =
      M1_HP_Dyn_S7HP_dyn_dTF_states[memOffset_tmp + 1];
    M1_HP_Dyn_S7HP_dyn_dTF_states[memOffset_tmp + 1] =
      M1_HP_Dyn_S7HP_dyn_dTF_states[memOffset_tmp];
    M1_HP_Dyn_S7HP_dyn_dTF_states[memOffset_tmp] = denAccum_5;
  }
}

/* Model initialize function */
void M1_HP_Dyn_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(M1_HP_Dyn_M, (NULL));

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
