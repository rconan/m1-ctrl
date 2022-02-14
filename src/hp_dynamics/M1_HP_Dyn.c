/*
 * File: M1_HP_Dyn.c
 *
 * Code generated for Simulink model 'M1_HP_Dyn'.
 *
 * Model version                  : 1.964
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Feb 14 14:52:11 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "M1_HP_Dyn.h"
#include "M1_HP_Dyn_private.h"

/* Exported block parameters */
real_T S1_HPstiff = 2.6043836850140852E+8;/* Variable: S1_HPstiff
                                           * Referenced by: '<S1>/HpK8'
                                           */
real_T S1_M1RBM2HP[36] = { 0.25541766364513235, -0.25552880189329025,
  0.12355931823751305, 0.38113655755120918, -0.38113980014636739,
  -0.1237463185871308, 0.28913447575394363, 0.28877583335090429,
  -0.36726114257440362, 0.076949965399053, 0.0771330226619703,
  -0.36745949707440478, 0.40796603528334147, 0.40788361880452778,
  0.4131814515357386, 0.41492732779214264, 0.4151445762830322,
  0.41380208466544621, -0.945925179706834, -0.94635599685941285,
  -0.18623212271665093, 1.1480466824689315, 1.1486063986918946,
  -0.18310399237716912, -0.77131143916395539, 0.772664059331836,
  1.2151041069277142, 0.43873660405991882, -0.44137026443639227,
  -1.216353422257392, 1.1278901113404334, -1.126038365480897, 1.1222204549278825,
  -1.1306360586356758, 1.1287909615772767, -1.1230334279337066 } ;/* Variable: S1_M1RBM2HP
                                                                   * Referenced by: '<S1>/CG2Hp6'
                                                                   */

real_T S2_HPstiff = 2.6043836850140852E+8;/* Variable: S2_HPstiff
                                           * Referenced by: '<S1>/HpK1'
                                           */
real_T S2_M1RBM2HP[36] = { 0.25709378530911214, -0.25413192873442381,
  0.12830665068165381, 0.3872345142462203, -0.38072921263212073,
  -0.12184863654326737, 0.28898127731426704, 0.28939162889719616,
  -0.36668873162459065, 0.077317642836595771, 0.079032275009777553,
  -0.36600764171441125, 0.40592228472814684, 0.40432863371589789,
  0.40912417732277917, 0.41319437800538555, 0.40674811239396214,
  0.40807330966205796, -0.94480657658984912, -0.94768579203584591,
  -0.18795962204256947, 1.1460609555680334, 1.1455693777932205,
  -0.18546312958304459, -0.771159293077826, 0.77401542021296821,
  1.2179932883206481, 0.44124106886538011, -0.44376245652031676,
  -1.217799735065572, 1.1255315455718073, -1.1290094468751339,
  1.1196368703653337, -1.1342922484811993, 1.1298987268679026,
  -1.1245654654590058 } ;              /* Variable: S2_M1RBM2HP
                                        * Referenced by: '<S1>/CG2Hp8'
                                        */

real_T S3_HPstiff = 2.6043836850140852E+8;/* Variable: S3_HPstiff
                                           * Referenced by: '<S1>/HpK2'
                                           */
real_T S3_M1RBM2HP[36] = { 0.25686827953250707, -0.25557082481563959,
  0.12642592670089156, 0.38715485650922493, -0.38511063228578635,
  -0.12456460021214485, 0.28905754963614727, 0.28887831189240387,
  -0.36619531598875527, 0.077615972180762854, 0.078136244812872957,
  -0.36699687389720748, 0.40423859789127131, 0.40417803774447558,
  0.40825383652683717, 0.41173269111468419, 0.40918789398717531,
  0.40896807334925006, -0.94527378046661492, -0.94579487683250152,
  -0.18820243692559155, 1.1473967433879164, 1.1473372330616443,
  -0.182904379003194, -0.77008628242945509, 0.77334085919200923,
  1.2156308776740568, 0.43995261013666481, -0.44395535729921176,
  -1.2175357605821895, 1.1273132446530818, -1.1264429448855326,
  1.1196866723395251, -1.1370329950019948, 1.1304255210208867,
  -1.124335433573036 } ;               /* Variable: S3_M1RBM2HP
                                        * Referenced by: '<S1>/CG2Hp1'
                                        */

real_T S4_HPstiff = 2.6043836850140852E+8;/* Variable: S4_HPstiff
                                           * Referenced by: '<S1>/HpK5'
                                           */
real_T S4_M1RBM2HP[36] = { 0.25657235342875062, -0.25675898819174314,
  0.12470261945485719, 0.38596599909629026, -0.38499919021773549,
  -0.1242428124537928, 0.28935083707965642, 0.28916443481532028,
  -0.36778194974271672, 0.076869474820634373, 0.077084887352533882,
  -0.36675515799275243, 0.40751584130352753, 0.40818514169315312,
  0.41379230218459567, 0.41496234468259874, 0.41398036668196359,
  0.41234633057189918, -0.94691706054736147, -0.94764244724653868,
  -0.18420660337976158, 1.1484369234235219, 1.1485591722716886,
  -0.18546607445300739, -0.769815377004048, 0.771069726540999, 1.214326229842043,
  0.440332984209167, -0.43777741058412589, -1.2119931791617926,
  1.1251934236899415, -1.1269469902855713, 1.122274949284223,
  -1.1324803010405013, 1.1334564546859129, -1.121884187819522 } ;/* Variable: S4_M1RBM2HP
                                                                  * Referenced by: '<S1>/CG2Hp2'
                                                                  */

real_T S5_HPstiff = 2.6043836850140852E+8;/* Variable: S5_HPstiff
                                           * Referenced by: '<S1>/HpK3'
                                           */
real_T S5_M1RBM2HP[36] = { 0.25430083581771468, -0.25681856524240732,
  0.12506322114851587, 0.38505662108223687, -0.38964648878989427,
  -0.12934768160388921, 0.289075795510577, 0.28893507799955059,
  -0.3666180245774861, 0.0778583210532471, 0.0769959965418921,
  -0.36716950708555318, 0.40684978012828504, 0.40428565012606027,
  0.4073669741158773, 0.40927583874636436, 0.41658515259425544,
  0.41414364530351944, -0.94483333047324525, -0.9467138050311048,
  -0.1869360221235965, 1.1471873680353146, 1.1511189347947286,
  -0.1819777767352419, -0.77748218884147413, 0.77202961621523558,
  1.2191323334180528, 0.44079199553120224, -0.45425483643948311,
  -1.2296064758605032, 1.1285016318194028, -1.1255618929525844,
  1.123029092164963, -1.1320396668637358, 1.1360373272602329,
  -1.1193465611961118 } ;              /* Variable: S5_M1RBM2HP
                                        * Referenced by: '<S1>/CG2Hp3'
                                        */

real_T S6_HPstiff = 2.6043836850140852E+8;/* Variable: S6_HPstiff
                                           * Referenced by: '<S1>/HpK4'
                                           */
real_T S6_M1RBM2HP[36] = { 0.25382941361856826, -0.25566463762473451,
  0.12579124863948105, 0.38457774789818794, -0.38641369339380616,
  -0.1289062877242157, 0.28934877297764289, 0.2880745436357231,
  -0.36801497031042357, 0.077844806154012292, 0.0773604755245395,
  -0.3657340796068978, 0.40264178779353493, 0.40822116034957523,
  0.41555552439659016, 0.41313707248362752, 0.41276603196199, 0.4058909423431335,
  -0.94605615820374833, -0.9430546569850814, -0.18049472925182439,
  1.1491952257580971, 1.1474305681407577, -0.18864461284059836,
  -0.77355012828305969, 0.78035674432695135, 1.2373343490608575,
  0.46064969241108877, -0.43947277702328436, -1.2210375241122751,
  1.1279428009888828, -1.1269572779008643, 1.1243897923774961,
  -1.1292111026388076, 1.1355255794127941, -1.1186639047310558 } ;/* Variable: S6_M1RBM2HP
                                                                   * Referenced by: '<S1>/CG2Hp4'
                                                                   */

real_T S7_HPstiff = 2.6043836850140852E+8;/* Variable: S7_HPstiff
                                           * Referenced by: '<S1>/HpK6'
                                           */
real_T S7_M1RBM2HP[36] = { 0.2609979108660761, -0.26092968218461943,
  0.12023208633640883, 0.37983346563608011, -0.380260978365483,
  -0.12042796034325208, 0.2902246422191132, 0.29004751932471851,
  -0.37135676379572696, 0.08260087857304145, 0.082600657187778412,
  -0.37109358415679328, 0.41431068765938389, 0.4137477836434178,
  0.41304029811397353, 0.41820786533239929, 0.41901155701155923,
  0.41342671543438969, -0.956671015439575, -0.9576377792774784,
  -0.18894255488399847, 1.1581220524891662, 1.159334183882023,
  -0.18697618902450128, -0.7810003402806901, 0.781001944928686,
  1.2207810759513762, 0.44083424702329405, -0.44297008657512404,
  -1.2219672400858075, 1.1278435291224278, -1.126711961718224,
  1.1262183329222208, -1.1232210110724363, 1.1246341058353535,
  -1.1247973436748939 } ;              /* Variable: S7_M1RBM2HP
                                        * Referenced by: '<S1>/CG2Hp5'
                                        */

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
      rtb_CG2Hp6[k] += S1_M1RBM2HP[6 * memOffset + k] *
        M1_HP_Dyn_U.M1_RBM_cmd[memOffset];
    }

    /* End of Gain: '<S1>/CG2Hp6' */

    /* DiscreteTransferFcn: '<S1>/S1HP_dyn_dTF' */
    memOffset = k << 2;
    denAccum_tmp = M1_HP_Dyn_DW.S1HP_dyn_dTF_states[memOffset + 1];
    denAccum_tmp_0 = M1_HP_Dyn_DW.S1HP_dyn_dTF_states[memOffset + 2];
    denAccum_tmp_1 = M1_HP_Dyn_DW.S1HP_dyn_dTF_states[memOffset + 3];
    denAccum = (((rtb_CG2Hp6[k] - -3.9324030529437657 *
                  M1_HP_Dyn_DW.S1HP_dyn_dTF_states[memOffset]) - denAccum_tmp *
                 5.7980159366164923) - denAccum_tmp_0 * -3.7988189837355097) -
      denAccum_tmp_1 * 0.93320610759369726;
    S1HP_dyn_dTF_tmp[k] = denAccum;
    denAccum *= 0.00010538306295552853;
    denAccum += 9.3078381572247558E-7 *
      M1_HP_Dyn_DW.S1HP_dyn_dTF_states[memOffset];
    denAccum += denAccum_tmp * -0.00020983345936705571;
    denAccum += denAccum_tmp_0 * -9.27018359164759E-7;
    denAccum += denAccum_tmp_1 * 0.00010445416186808491;

    /* Gain: '<S1>/CG2Hp8' incorporates:
     *  Inport: '<Root>/M1_RBM_cmd'
     */
    rtb_CG2Hp6[k] = 0.0;
    for (memOffset = 0; memOffset < 6; memOffset++) {
      rtb_CG2Hp6[k] += S2_M1RBM2HP[6 * memOffset + k] * M1_HP_Dyn_U.M1_RBM_cmd[6
        + memOffset];
    }

    /* End of Gain: '<S1>/CG2Hp8' */

    /* DiscreteTransferFcn: '<S1>/S1HP_dyn_dTF' incorporates:
     *  Gain: '<S1>/HpK8'
     */
    rtb_HpK8[k] = S1_HPstiff * denAccum;
  }

  for (k = 0; k < 6; k++) {
    /* DiscreteTransferFcn: '<S1>/S2HP_dyn_dTF' */
    memOffset = k << 2;
    denAccum_tmp = M1_HP_Dyn_DW.S2HP_dyn_dTF_states[memOffset + 1];
    denAccum_tmp_0 = M1_HP_Dyn_DW.S2HP_dyn_dTF_states[memOffset + 2];
    denAccum_tmp_1 = M1_HP_Dyn_DW.S2HP_dyn_dTF_states[memOffset + 3];
    denAccum = (((rtb_CG2Hp6[k] - -3.9324030529437657 *
                  M1_HP_Dyn_DW.S2HP_dyn_dTF_states[memOffset]) - denAccum_tmp *
                 5.7980159366164923) - denAccum_tmp_0 * -3.7988189837355097) -
      denAccum_tmp_1 * 0.93320610759369726;
    S2HP_dyn_dTF_tmp[k] = denAccum;
    denAccum *= 0.00010538306295552853;
    denAccum += 9.3078381572247558E-7 *
      M1_HP_Dyn_DW.S2HP_dyn_dTF_states[memOffset];
    denAccum += denAccum_tmp * -0.00020983345936705571;
    denAccum += denAccum_tmp_0 * -9.27018359164759E-7;
    denAccum += denAccum_tmp_1 * 0.00010445416186808491;

    /* Gain: '<S1>/CG2Hp1' incorporates:
     *  Inport: '<Root>/M1_RBM_cmd'
     */
    rtb_CG2Hp6[k] = 0.0;
    for (memOffset = 0; memOffset < 6; memOffset++) {
      rtb_CG2Hp6[k] += S3_M1RBM2HP[6 * memOffset + k] * M1_HP_Dyn_U.M1_RBM_cmd
        [12 + memOffset];
    }

    /* End of Gain: '<S1>/CG2Hp1' */

    /* DiscreteTransferFcn: '<S1>/S2HP_dyn_dTF' incorporates:
     *  Gain: '<S1>/HpK1'
     */
    rtb_HpK1[k] = S2_HPstiff * denAccum;
  }

  for (k = 0; k < 6; k++) {
    /* DiscreteTransferFcn: '<S1>/S3HP_dyn_dTF' */
    memOffset = k << 2;
    denAccum_tmp = M1_HP_Dyn_DW.S3HP_dyn_dTF_states[memOffset + 1];
    denAccum_tmp_0 = M1_HP_Dyn_DW.S3HP_dyn_dTF_states[memOffset + 2];
    denAccum_tmp_1 = M1_HP_Dyn_DW.S3HP_dyn_dTF_states[memOffset + 3];
    denAccum = (((rtb_CG2Hp6[k] - -3.9324030529437657 *
                  M1_HP_Dyn_DW.S3HP_dyn_dTF_states[memOffset]) - denAccum_tmp *
                 5.7980159366164923) - denAccum_tmp_0 * -3.7988189837355097) -
      denAccum_tmp_1 * 0.93320610759369726;
    S3HP_dyn_dTF_tmp[k] = denAccum;
    denAccum *= 0.00010538306295552853;
    denAccum += 9.3078381572247558E-7 *
      M1_HP_Dyn_DW.S3HP_dyn_dTF_states[memOffset];
    denAccum += denAccum_tmp * -0.00020983345936705571;
    denAccum += denAccum_tmp_0 * -9.27018359164759E-7;
    denAccum += denAccum_tmp_1 * 0.00010445416186808491;

    /* Gain: '<S1>/CG2Hp2' incorporates:
     *  Inport: '<Root>/M1_RBM_cmd'
     */
    rtb_CG2Hp6[k] = 0.0;
    for (memOffset = 0; memOffset < 6; memOffset++) {
      rtb_CG2Hp6[k] += S4_M1RBM2HP[6 * memOffset + k] * M1_HP_Dyn_U.M1_RBM_cmd
        [18 + memOffset];
    }

    /* End of Gain: '<S1>/CG2Hp2' */

    /* DiscreteTransferFcn: '<S1>/S3HP_dyn_dTF' incorporates:
     *  Gain: '<S1>/HpK2'
     */
    rtb_HpK2[k] = S3_HPstiff * denAccum;
  }

  for (k = 0; k < 6; k++) {
    /* DiscreteTransferFcn: '<S1>/S4HP_dyn_dTF' */
    memOffset = k << 2;
    denAccum_tmp = M1_HP_Dyn_DW.S4HP_dyn_dTF_states[memOffset + 1];
    denAccum_tmp_0 = M1_HP_Dyn_DW.S4HP_dyn_dTF_states[memOffset + 2];
    denAccum_tmp_1 = M1_HP_Dyn_DW.S4HP_dyn_dTF_states[memOffset + 3];
    denAccum = (((rtb_CG2Hp6[k] - -3.9324030529437657 *
                  M1_HP_Dyn_DW.S4HP_dyn_dTF_states[memOffset]) - denAccum_tmp *
                 5.7980159366164923) - denAccum_tmp_0 * -3.7988189837355097) -
      denAccum_tmp_1 * 0.93320610759369726;
    S4HP_dyn_dTF_tmp[k] = denAccum;
    denAccum *= 0.00010538306295552853;
    denAccum += 9.3078381572247558E-7 *
      M1_HP_Dyn_DW.S4HP_dyn_dTF_states[memOffset];
    denAccum += denAccum_tmp * -0.00020983345936705571;
    denAccum += denAccum_tmp_0 * -9.27018359164759E-7;
    denAccum += denAccum_tmp_1 * 0.00010445416186808491;

    /* Gain: '<S1>/CG2Hp3' incorporates:
     *  Inport: '<Root>/M1_RBM_cmd'
     */
    rtb_CG2Hp6[k] = 0.0;
    for (memOffset = 0; memOffset < 6; memOffset++) {
      rtb_CG2Hp6[k] += S5_M1RBM2HP[6 * memOffset + k] * M1_HP_Dyn_U.M1_RBM_cmd
        [24 + memOffset];
    }

    /* End of Gain: '<S1>/CG2Hp3' */

    /* DiscreteTransferFcn: '<S1>/S4HP_dyn_dTF' incorporates:
     *  Gain: '<S1>/HpK5'
     */
    rtb_HpK5[k] = S4_HPstiff * denAccum;
  }

  for (k = 0; k < 6; k++) {
    /* DiscreteTransferFcn: '<S1>/S5HP_dyn_dTF' */
    memOffset = k << 2;
    denAccum_tmp = M1_HP_Dyn_DW.S5HP_dyn_dTF_states[memOffset + 1];
    denAccum_tmp_0 = M1_HP_Dyn_DW.S5HP_dyn_dTF_states[memOffset + 2];
    denAccum_tmp_1 = M1_HP_Dyn_DW.S5HP_dyn_dTF_states[memOffset + 3];
    denAccum = (((rtb_CG2Hp6[k] - -3.9324030529437657 *
                  M1_HP_Dyn_DW.S5HP_dyn_dTF_states[memOffset]) - denAccum_tmp *
                 5.7980159366164923) - denAccum_tmp_0 * -3.7988189837355097) -
      denAccum_tmp_1 * 0.93320610759369726;
    S5HP_dyn_dTF_tmp[k] = denAccum;
    denAccum *= 0.00010538306295552853;
    denAccum += 9.3078381572247558E-7 *
      M1_HP_Dyn_DW.S5HP_dyn_dTF_states[memOffset];
    denAccum += denAccum_tmp * -0.00020983345936705571;
    denAccum += denAccum_tmp_0 * -9.27018359164759E-7;
    denAccum += denAccum_tmp_1 * 0.00010445416186808491;

    /* Gain: '<S1>/CG2Hp4' incorporates:
     *  Inport: '<Root>/M1_RBM_cmd'
     */
    rtb_CG2Hp6[k] = 0.0;
    for (memOffset = 0; memOffset < 6; memOffset++) {
      rtb_CG2Hp6[k] += S6_M1RBM2HP[6 * memOffset + k] * M1_HP_Dyn_U.M1_RBM_cmd
        [30 + memOffset];
    }

    /* End of Gain: '<S1>/CG2Hp4' */

    /* DiscreteTransferFcn: '<S1>/S5HP_dyn_dTF' incorporates:
     *  Gain: '<S1>/HpK3'
     */
    rtb_HpK3[k] = S5_HPstiff * denAccum;
  }

  for (k = 0; k < 6; k++) {
    /* DiscreteTransferFcn: '<S1>/S6HP_dyn_dTF' */
    memOffset = k << 2;
    denAccum_tmp = M1_HP_Dyn_DW.S6HP_dyn_dTF_states[memOffset + 1];
    denAccum_tmp_0 = M1_HP_Dyn_DW.S6HP_dyn_dTF_states[memOffset + 2];
    denAccum_tmp_1 = M1_HP_Dyn_DW.S6HP_dyn_dTF_states[memOffset + 3];
    denAccum = (((rtb_CG2Hp6[k] - -3.9324030529437657 *
                  M1_HP_Dyn_DW.S6HP_dyn_dTF_states[memOffset]) - denAccum_tmp *
                 5.7980159366164923) - denAccum_tmp_0 * -3.7988189837355097) -
      denAccum_tmp_1 * 0.93320610759369726;
    S6HP_dyn_dTF_tmp[k] = denAccum;
    denAccum *= 0.00010538306295552853;
    denAccum += 9.3078381572247558E-7 *
      M1_HP_Dyn_DW.S6HP_dyn_dTF_states[memOffset];
    denAccum += denAccum_tmp * -0.00020983345936705571;
    denAccum += denAccum_tmp_0 * -9.27018359164759E-7;
    denAccum += denAccum_tmp_1 * 0.00010445416186808491;

    /* Gain: '<S1>/CG2Hp5' incorporates:
     *  Inport: '<Root>/M1_RBM_cmd'
     */
    rtb_CG2Hp6[k] = 0.0;
    for (memOffset = 0; memOffset < 6; memOffset++) {
      rtb_CG2Hp6[k] += S7_M1RBM2HP[6 * memOffset + k] * M1_HP_Dyn_U.M1_RBM_cmd
        [36 + memOffset];
    }

    /* End of Gain: '<S1>/CG2Hp5' */

    /* DiscreteTransferFcn: '<S1>/S6HP_dyn_dTF' incorporates:
     *  Gain: '<S1>/HpK4'
     */
    rtb_HpK4[k] = S6_HPstiff * denAccum;
  }

  for (k = 0; k < 6; k++) {
    /* DiscreteTransferFcn: '<S1>/S7HP_dyn_dTF' */
    memOffset = k << 2;
    denAccum_tmp = M1_HP_Dyn_DW.S7HP_dyn_dTF_states[memOffset + 1];
    denAccum_tmp_0 = M1_HP_Dyn_DW.S7HP_dyn_dTF_states[memOffset + 2];
    denAccum_tmp_1 = M1_HP_Dyn_DW.S7HP_dyn_dTF_states[memOffset + 3];
    denAccum = (((rtb_CG2Hp6[k] - -3.9324030529437657 *
                  M1_HP_Dyn_DW.S7HP_dyn_dTF_states[memOffset]) - denAccum_tmp *
                 5.7980159366164923) - denAccum_tmp_0 * -3.7988189837355097) -
      denAccum_tmp_1 * 0.93320610759369726;
    S7HP_dyn_dTF_tmp[k] = denAccum;
    denAccum *= 0.00010538306295552853;
    denAccum += 9.3078381572247558E-7 *
      M1_HP_Dyn_DW.S7HP_dyn_dTF_states[memOffset];
    denAccum += denAccum_tmp * -0.00020983345936705571;
    denAccum += denAccum_tmp_0 * -9.27018359164759E-7;
    denAccum += denAccum_tmp_1 * 0.00010445416186808491;

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
    M1_HP_Dyn_Y.HP_F_cmd[k + 36] = S7_HPstiff * denAccum;
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
