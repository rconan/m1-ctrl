/*
 * File: M1SA_F_Control_CS_data.c
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

/* Constant parameters (default storage) */
const ConstP_M1SA_F_Control_CS_T M1SA_F_Control_CS_ConstP = {
  /* Expression: m1sys{7}.Kbal
   * Referenced by: '<S1>/CSseg_Kbal'
   */
  { 0.00053499497347404574, 0.003401910714119283, -9.4778882976882291E-5,
    0.0034334334851266577, -0.00064782852678143556, -0.000556821142243168,
    -0.00053482181996883209, -0.0034017607144805968, 9.4823396223859031E-5,
    -0.003433254287877698, 0.00064783759007352407, 0.00055684841643622858,
    0.00061154330350744507, -0.0013835428099746362, 0.00073240062207219586,
    0.0028171842869394131, 0.0010543090101360348, 8.4377386589294318E-5,
    -3.9390211491715587E-5, 0.0061649036620883488, -0.0048971195618863527,
    -3.8236018001763333E-5, -0.00074862089926909948, 0.00078681359755212706,
    0.0027396697942108535, 0.00097687446143718336, 0.0011038791219959096,
    2.92998117953113E-5, -0.0048884115917856626, -0.0019775781052265161,
    -0.0039448220692557181, -0.0021132559827102644, -0.0006113198141090364,
    0.0013834990398186517, -0.00073257692947474964, -0.0028170469905090872,
    -0.0010542826582486029, -8.464465438770632E-5, 3.9128013778781761E-5,
    -0.0061650423962462831, 0.0048967704502447772, 3.8330346972490928E-5,
    0.00074856981510772213, -0.00078684382488203926, -0.0027396243921695243,
    -0.00097696858051256178, -0.0011036718962151816, -2.9449272512261541E-5,
    0.0048881194177878892, 0.0019775146792385097, 0.0039450213419334581,
    0.0021132003111960025, -0.0021242613244912383, 0.0022551263403637971,
    -0.0013383100001393836, 0.003281772403502475, 0.0035935690327182066,
    0.00021321024882945964, -0.0015440397082680578, -0.00036466680915340767,
    0.0012911129775453711, -0.0021273579250874106, 0.0033902409964687093,
    0.0036423761771724474, 0.00010638272953296538, 0.0021237897871763528,
    -0.0022550506500028248, 0.0013387958060771992, -0.0032816891285566783,
    -0.0035934592829896454, -0.00021307925220383136, 0.0015440494350502782,
    0.00036459399009693724, -0.0012912964342919259, 0.00212725818065839,
    -0.0033899451913396543, -0.0036421566629268676, -0.00010642329781396811,
    0.012999645679897363, 0.0, 0.002630905289383582, 0.013845481523453862, 0.0,
    0.0046051906488859444, 0.012999642363147343, 0.0, 0.0026666723312988049,
    0.013845552740614176, 0.0, 0.0045912854349362065, 0.012999625130827922, 0.0,
    -0.0026310604320208889, 0.013845484612728866, 0.0, -0.00460514271092503,
    0.012999622677499384, 0.0, -0.0026667966004837473, 0.01384555924009593, 0.0,
    -0.00459120456064699, 0.013247155947633893, 0.0, -0.0006843931061462083,
    0.013031067621099022, 0.0, -0.00080266180688069722, 0.0131078574835389, 0.0,
    -0.00035351500328005672, 0.013242343956369765, 0.0, -0.000678165589033235,
    0.013029149312581978, 0.0, 0.0020408867507275578, 0.013506772005034294, 0.0,
    -0.00200367383885596, 0.013106571544573615, 0.0, 0.00090638064526738773,
    0.013237623151148221, 0.0, -0.00031316383564936376, 0.013490126571311016,
    0.0, -0.00055850745095335612, 0.013106617550466416, 0.0,
    0.00064149099151713824, 0.013237602018850237, 0.0, 0.0020541361011331056,
    0.013477466284451458, 0.0, 0.0025407421236712893, 0.014189395749160467, 0.0,
    -0.000984731734637663, 0.014077678837846897, 0.0, 0.00070732383388690478,
    0.013972202561813417, 0.0, 0.0012904723775008767, 0.015576731317385304, 0.0,
    -0.0026070910894579833, 0.014889513885111833, 0.0, 0.00036765707620092862,
    0.013247369620937434, 0.0, -0.00068093032152519032, 0.013031109796488883,
    0.0, -0.0010364782364901675, 0.013107999550458363, 0.0,
    -0.000507751820228163, 0.013242494413092082, 0.0, -0.00060471747393355663,
    0.013029182690237997, 0.0, 0.0023479795469126276, 0.013506871780257303, 0.0,
    -0.0020324607991680597, 0.013106670547139944, 0.0, 0.0011231398664369105,
    0.013237684933249167, 0.0, -0.00038312685600771747, 0.013490203524910739,
    0.0, -0.00060783831988517713, 0.013106611947231782, 0.0,
    0.00085718601631467749, 0.013237628409754775, 0.0, 0.0020824296674372819,
    0.013477403151909617, 0.0, 0.0025022731708574117, 0.014189342359537716, 0.0,
    -0.00091007815190511667, 0.014077668559031633, 0.0, 0.00065122774208024349,
    0.013972221217655362, 0.0, 0.0013285360869889115, 0.013247155947633893, 0.0,
    0.0006845410257303986, 0.013031069333911193, 0.0, 0.00080090815718791386,
    0.0131078574835389, 0.0, 0.0003538443469284974, 0.01324233881793325, 0.0,
    0.00067816275860637981, 0.01302914674336372, 0.0, -0.0020404985412919223,
    0.013506766010191693, 0.0, 0.0020040213139767191, 0.013106567262543186, 0.0,
    -0.00090658160942698267, 0.013237618869117793, 0.0, 0.00031313628903822656,
    0.013490126571311016, 0.0, 0.00055847236023117157, 0.013106603847969044, 0.0,
    -0.00064168096097747343, 0.013237590029165035, 0.0, -0.0020541297617194328,
    0.0134774577203906, 0.0, -0.0025407595047226409, 0.014189395749160467, 0.0,
    0.00098485945955029911, 0.014077680550659069, 0.0, -0.00070751397247098135,
    0.013972204274625588, 0.0, -0.0012904174580288918, 0.015576735599415734, 0.0,
    0.0026072826271537654, 0.014889517310736176, 0.0, -0.00036777955092332561,
    0.013247368764531349, 0.0, 0.000680898735955838, 0.013031107227270626, 0.0,
    0.0010365755424555148, 0.013107995268427933, 0.0, 0.00050761471125103743,
    0.013242490131061652, 0.0, 0.0006046298774621023, 0.013029169844146709, 0.0,
    -0.0023479326734060215, 0.013506865785414704, 0.0, 0.0020326534127976617,
    0.013106660270266914, 0.0, -0.0011233036521027594, 0.013237682364030908, 0.0,
    0.00038376390421854636, 0.013490201812098567, 0.0, 0.00060824182123680732,
    0.013106600813952665, 0.0, -0.00085699925356330891, 0.013237621558506088,
    0.0, -0.0020819185009500604, 0.013477402295503531, 0.0, -0.00250228564728289,
    0.014189344072349888, 0.0, 0.00091009669586504559, 0.014077666846219462, 0.0,
    -0.00065130357569573468, 0.013972224643279706, 0.0, -0.0013285900481002824,
    0.0068616480258905811, 0.0, -0.0010413889329174025, 0.0068616480258905811,
    0.0, 0.0010407503072837432, 0.0068617490818087112, 0.0,
    -0.00085974593811159706, 0.0068617687791486855, 0.0, 0.00085986283641365207,
    0.00028003105938025156, -0.0049745860948970343, -0.00025602778186647644,
    0.0050000349307631545, 0.002338860328416556, -0.0022968709976310632,
    0.00028704947508481469, -0.00497524450691298, -0.00025326903842407314,
    0.0049993990530172285, 0.0023386904131817276, -0.0022969244142920795,
    0.00024439820109859405, -0.00044527946170084062, -0.0049720240590723185,
    -0.002468885695173971, -0.00026231741040843594, -0.00095729198208389444,
    0.00017088739304040856, 2.8673678374200951E-5, 0.0019572071935073554,
    -0.00014788634791553269, 0.000542052018093152, 0.0050202163216930863,
    0.002517347053978413, 0.00027133322692673257, 0.00094643540984715212,
    -9.5067076437041161E-5, -0.0019792108039946976, 0.00411577570968632,
    -7.1285499063178174E-7, -0.0040935215525737308, 0.00025001460436986466,
    -0.00045412401735148047, -0.0049736751354573219, -0.0024687304766649798,
    -0.00026247824408787173, -0.0009684065498013519, 0.00017138386692111226,
    2.8142853994393139E-5, 0.0019572135437573995, -0.0001457220106021992,
    0.00053858887079062841, 0.005019618889202943, 0.002517361795903744,
    0.0002712005807456969, 0.00094207642225082743, -9.4708147554005989E-5,
    -0.0019792467795326923, 0.0041158089174853554, -7.5600487189429689E-7,
    -0.0040935102336105119, -0.002548986367891564, -0.0043662078479657042,
    -0.0011411953339990376, 0.0017654640547017635, -0.0033028979827919047,
    -0.0021823304610974546, -2.9775524499162715E-5, 0.0024758786128377093,
    0.0042486044964639685, 0.0010789484875535558, -0.0017532819588818613,
    0.0032687647025193512, 0.0020889911438279731, -0.0025662349650676132,
    -0.004352222976064724, -0.0011316785274155612, 0.0017666891099196935,
    -0.0033040736737382577, -0.0021818217684614477, -2.97533779659569E-5,
    0.0024692212390777066, 0.0042540440159415547, 0.001082705003980333,
    -0.001752595531958453, 0.0032683084781796835, 0.0020892515384554953, 0.0,
    0.013385007893867169, -0.0033422433025251884, 0.0, 0.013335945576518904,
    0.0014754561390354852, 0.0, 0.013392943139079226, 0.0033137305723075, 0.0,
    0.013338623203497777, -0.0014827771861705551, 0.0, 0.013385085436896853,
    -0.0033425996574350495, 0.0, 0.013336338821203317, 0.0014762310191966683,
    0.0, 0.01339313721530311, 0.0033134318503860965, 0.0, 0.01333903750263989,
    -0.0014820733714791181, 0.0, 0.013981788879520349, 0.0011389804420255897,
    0.0, 0.0139211947752402, -0.0024837049917405506, 0.0, 0.016201510403549623,
    0.00080433611660248722, 0.0, 0.01279907526775761, 0.0021978001702394677, 0.0,
    0.013012148009191551, -0.0030181535365344896, 0.0, 0.013353738729741462,
    0.00057223705645239676, 0.0, 0.011931241765255387, -0.0021072625872760732,
    0.0, 0.013671290106729213, 0.00029927140890503645, 0.0, 0.013412129832285572,
    0.00011252939929277179, 0.0, 0.013966371906102448, -0.001286249409937771,
    0.0, 0.013174694601855714, -0.0014923027246806482, 0.0, 0.013432753642380424,
    -0.0010833688122535248, 0.0, 0.013483651257334979, 0.001596255392518699, 0.0,
    0.013245720212028135, -0.00059875327977153216, 0.0, 0.013437821460827495,
    -0.00015816676700538605, 0.0, 0.013375478956634757, 2.4338461554863126E-5,
    0.0, 0.013381027512711804, -1.4226862589436251E-5, 0.0, 0.013992202442291645,
    -0.0011491452830750518, 0.0, 0.013902298612782717, 0.0024665200775473043,
    0.0, 0.016221142069349243, -0.00080852364437985656, 0.0,
    0.012769113394975442, -0.0021871581767164382, 0.0, 0.013026945670230838,
    0.0029924442074599636, 0.0, 0.013341980486934512, -0.00057666001111410182,
    0.0, 0.011910654661429571, 0.0020956138360516911, 0.0, 0.01370360853263632,
    -0.00031490027722339166, 0.0, 0.013424969156287962, -9.8696764404419379E-5,
    0.0, 0.013961742174135155, 0.0012677411109999076, 0.0, 0.013163212047635669,
    0.00150352912108832, 0.0, 0.013426143169872656, 0.0010756945462016179, 0.0,
    0.013489179408680909, -0.0015243370133528787, 0.0, 0.013241841887160401,
    0.00058471402796261536, 0.0, 0.01343798177116735, 0.00013673122039954504,
    0.0, 0.013981624262317076, 0.0011395267886515205, 0.0, 0.013921050929603709,
    -0.0024811207440722351, 0.0, 0.016201563283445002, 0.00080541981954479556,
    0.0, 0.012799195733352389, 0.0021972697587525759, 0.0, 0.013012190912461913,
    -0.0030227672978421216, 0.0, 0.013353646221181494, 0.00057208894972081566,
    0.0, 0.01193119228994644, -0.0021074387478514866, 0.0, 0.013671259803528684,
    0.00030046198411100246, 0.0, 0.013412161992529592, 0.00011174188141495856,
    0.0, 0.013966182028232077, -0.0012902256007150945, 0.0, 0.01317472400464061,
    -0.0014910838005847606, 0.0, 0.013432762167481514, -0.0010832841762770924,
    0.0, 0.013483288971194614, 0.0015964335455014474, 0.0, 0.013246300240876887,
    -0.000598366792427635, 0.0, 0.013437096497593134, -0.00015863883518531894,
    0.0, 0.01337550486302469, 2.3976583619617513E-5, 0.0, 0.013381045373342322,
    -1.4107348266667413E-5, 0.0, 0.013991995499859758, -0.0011490145086365075,
    0.0, 0.013902089933336689, 0.0024674082968587649, 0.0, 0.016221203178115488,
    -0.00080822839055765742, 0.0, 0.012769265946355579, -0.0021873135343672342,
    0.0, 0.013026990893844768, 0.0029906554661852489, 0.0, 0.013341849652638339,
    -0.0005767050706171914, 0.0, 0.011910600675593064, 0.0020956188980005121,
    0.0, 0.013703590786380419, -0.00031451659663968382, 0.0, 0.01342507125648679,
    -9.9356773806592589E-5, 0.0, 0.01396149242105409, 0.0012663229866107582, 0.0,
    0.013163257979480156, 0.0015037985986031874, 0.0, 0.013426114677901176,
    0.0010756687521299155, 0.0, 0.013488813975223954, -0.0015240946676989167,
    0.0, 0.013242425691589836, 0.00058502310012063373, 0.0, 0.013437241951997537,
    0.00013641031312865853, 0.0, 0.0068766950749313514, -9.34504631947243E-5,
    0.0, 0.0068766950749313514, -9.5623631099443784E-5, 0.0,
    0.0068765220809021586, 8.2338057103378351E-5, 0.0, 0.0068765220809021586,
    8.17530666657098E-5, 0.0032423958120135969, 0.0029909754733096236,
    0.0032445938549548366, 0.0029933670633869847, 0.002577851964238125,
    0.0025864980881915925, 0.0032425219284646927, 0.0029909636964787103,
    0.0032447677952867396, 0.0029935068557103012, 0.0025779319750482256,
    0.0025865292548982789, 0.006620162265674725, 0.0060963848457353158,
    0.0067464166888367384, 0.005371091976381197, 0.0063692969076647151,
    0.0041651194689881271, 0.0058973239258932938, 0.0065172858242917835,
    0.0042474963768827185, 0.0066279485408100129, 0.00609288245737991,
    0.0067468826179001122, 0.005370674172665779, 0.0063693718858573948,
    0.0041628689180725816, 0.0058957061357295133, 0.0042551690810087341,
    0.0055548794856753753, 0.0059242778801049832, 0.0055503428714508115,
    0.0066202493517508159, 0.0060962823965231743, 0.006746412583213947,
    0.0053710667179118626, 0.0063692145952579582, 0.0041649458152696059,
    0.0058973242049426156, 0.0065173177768521927, 0.004247419556393516,
    0.00662794529867079, 0.006092742180451376, 0.0067467690346266918,
    0.0053704911260563162, 0.0063693956255430782, 0.0041627092953966634,
    0.0058957107135482866, 0.0042551930907842065, 0.00555490072520627,
    0.0059243153904603527, 0.0055502805628468788, 0.0073430351742293874,
    0.0074829814323640314, 0.0067254979464945316, 0.0069427412141961,
    0.0077605455029132308, 0.00687913276697135, 0.0069417626893327712,
    0.0073226577843312265, 0.0074907642143056631, 0.0067256267425834463,
    0.00694267457906562, 0.0077623775888338471, 0.006880779041596034,
    0.0073430629334720627, 0.0074831577167309895, 0.0067255575048830382,
    0.0069429320127886943, 0.00776059467004368, 0.0068791508429705463,
    0.0069415985516401817, 0.007322478117005796, 0.0074909381555332347,
    0.0067259663635778908, 0.00694280654342485, 0.0077623467207180823,
    0.0068807391914360453, 0.0, 0.0, 0.0083395608467054117, 0.0, 0.0,
    0.0082146984833121259, 0.0, 0.0, 0.0083367064170566541, 0.0, 0.0,
    0.0082141602174124455, 0.0, 0.0, 0.0083395525076144957, 0.0, 0.0,
    0.0082147651916854268, 0.0, 0.0, 0.0083368126189850289, 0.0, 0.0,
    0.0082141496663569648, 0.0, 0.0, 0.0067823968688300266, 0.0, 0.0,
    0.00757201213537606, 0.0, 0.0, 0.0064092850504906514, 0.0, 0.0,
    0.007598415623429714, 0.0, 0.0, 0.0077646283947497875, 0.0, 0.0,
    0.0065714453253794018, 0.0, 0.0, 0.0072438034276277067, 0.0, 0.0,
    0.0068804072451822459, 0.0, 0.0, 0.0072829434801050148, 0.0, 0.0,
    0.0077704315661985537, 0.0, 0.0, 0.0073186859414666608, 0.0, 0.0,
    0.0072007217374429654, 0.0, 0.0, 0.0063670813133354289, 0.0, 0.0,
    0.0070424817944814257, 0.0, 0.0, 0.0076329676293532414, 0.0, 0.0,
    0.00750742475521715, 0.0, 0.0, 0.0071296474731532434, 0.0, 0.0,
    0.006773440242945592, 0.0, 0.0, 0.0075865897010252295, 0.0, 0.0,
    0.0063928926897263505, 0.0, 0.0, 0.0076001029386304443, 0.0, 0.0,
    0.0077614265155917838, 0.0, 0.0, 0.006568071509741041, 0.0, 0.0,
    0.0072522488047913345, 0.0, 0.0, 0.00687827651433122, 0.0, 0.0,
    0.0072882452506641011, 0.0, 0.0, 0.0077685366208577258, 0.0, 0.0,
    0.0073194865825536035, 0.0, 0.0, 0.0071960299378586992, 0.0, 0.0,
    0.0063605541614451481, 0.0, 0.0, 0.0070436115070305642, 0.0, 0.0,
    0.0076352308341330923, 0.0, 0.0, 0.0067821140663191452, 0.0, 0.0,
    0.0075715618295895369, 0.0, 0.0, 0.0064091587372668794, 0.0, 0.0,
    0.0075984897249433752, 0.0, 0.0, 0.0077647055853428872, 0.0, 0.0,
    0.0065715039667920642, 0.0, 0.0, 0.0072438651534637117, 0.0, 0.0,
    0.0068802914406011139, 0.0, 0.0, 0.0072829720610177191, 0.0, 0.0,
    0.0077703756520507454, 0.0, 0.0, 0.0073186376796051007, 0.0, 0.0,
    0.0072006622043447911, 0.0, 0.0, 0.0063671136574993212, 0.0, 0.0,
    0.0070425042443770019, 0.0, 0.0, 0.0076329559739686621, 0.0, 0.0,
    0.0075074482977017121, 0.0, 0.0, 0.0071297289823874944, 0.0, 0.0,
    0.0067734637839410548, 0.0, 0.0, 0.0075865626418239133, 0.0, 0.0,
    0.0063929106226087587, 0.0, 0.0, 0.0076001428784919882, 0.0, 0.0,
    0.0077613038746282663, 0.0, 0.0, 0.0065680629444516163, 0.0, 0.0,
    0.0072522357798707106, 0.0, 0.0, 0.0068782298385226242, 0.0, 0.0,
    0.0072884893343803225, 0.0, 0.0, 0.0077682910870457995, 0.0, 0.0,
    0.0073193955002871592, 0.0, 0.0, 0.00719613945770739, 0.0, 0.0,
    0.0063604904291813327, 0.0, 0.0, 0.007043430843083372, 0.0, 0.0,
    0.0076352316528734724, 0.0, 0.0, 0.0059849572629789962, 0.0, 0.0,
    0.0059855901553038339, 0.0, 0.0, 0.0059924865129767054, 0.0, 0.0,
    0.0059924884881630532, 0.0048144456369158123, 0.0013008325707500438,
    -0.0048144456369158123, -0.0013006630709713578, 0.0017541923249577616,
    -0.0017541923249577616, 0.0048144456369158123, 0.0013008325707500438,
    -0.0048144456369158123, -0.0013006630709713578, 0.0017541923249577616,
    -0.0017541923249577616, 0.00522189702798858, 0.0050495287915091561,
    0.0044805310729038586, 0.0035793137880734704, 0.0028259524640355678,
    0.0042601813606117063, 0.0019792358772750722, 9.1331696133968553E-8,
    0.00081445947503204648, -0.0052217666435434365, -0.0050495287915091561,
    -0.0044805310729038586, -0.0035793137880734704, -0.0028259524640355678,
    -0.0042601813606117063, -0.0019792358772750722, -0.00081445947503204648,
    0.0015035934213923671, 1.9948820106922663E-9, -0.0015035934213923671,
    0.00522189702798858, 0.0050495287915091561, 0.0044805310729038586,
    0.0035793137880734704, 0.0028259524640355678, 0.0042601813606117063,
    0.0019792358772750722, 9.1331696133968553E-8, 0.00081445947503204648,
    -0.0052217666435434365, -0.0050495287915091561, -0.0044805310729038586,
    -0.0035793137880734704, -0.0028259524640355678, -0.0042601813606117063,
    -0.0019792358772750722, -0.00081445947503204648, 0.0015035934213923671,
    1.9948820106922663E-9, -0.0015035934213923671, 0.004510780264177101,
    0.004510780264177101, 0.0037589835534809178, 0.0030071868427847342,
    0.0022553901320885505, 0.0015035934213923671, 1.9427282326349521E-9,
    -0.004510780264177101, -0.004510780264177101, -0.0037589835534809178,
    -0.0030071868427847342, -0.0022553901320885505, -0.0015035934213923671,
    0.004510780264177101, 0.004510780264177101, 0.0037589835534809178,
    0.0030071868427847342, 0.0022553901320885505, 0.0015035934213923671,
    1.9427282326349521E-9, -0.004510780264177101, -0.004510780264177101,
    -0.0037589835534809178, -0.0030071868427847342, -0.0022553901320885505,
    -0.0015035934213923671, 0.0, 0.0, 0.0037928835092181715, 0.0, 0.0,
    0.00072032190563859439, 0.0, 0.0, -0.0037928835092181715, 0.0, 0.0,
    -0.00072020455963796553, 0.0, 0.0, 0.0037928835092181715, 0.0, 0.0,
    0.00072032190563859439, 0.0, 0.0, -0.0037928835092181715, 0.0, 0.0,
    -0.00072020455963796553, 0.0, 0.0, 0.0022553901320885505, 0.0, 0.0,
    0.0037589835534809178, 0.0, 0.0, 0.0030071868427847342, 0.0, 0.0,
    0.0022553901320885505, 0.0, 0.0, 0.0037589835534809178, 0.0, 0.0,
    0.0015035934213923671, 0.0, 0.0, 0.0030071868427847342, 0.0, 0.0,
    0.0022553901320885505, 0.0, 0.0, 0.0015035934213923671, 0.0, 0.0,
    0.0030071868427847342, 0.0, 0.0, 0.0022553901320885505, 0.0, 0.0,
    0.0015035934213923671, 0.0, 0.0, 0.00075178367225166927, 0.0, 0.0,
    0.00075179671069618354, 0.0, 0.0, 0.00075180974914069781, 0.0, 0.0,
    6.1019920327057558E-9, 0.0, 0.0, -1.007871760957596E-8, 0.0, 0.0,
    -0.0022553901320885505, 0.0, 0.0, -0.0037589835534809178, 0.0, 0.0,
    -0.0030071868427847342, 0.0, 0.0, -0.0022553901320885505, 0.0, 0.0,
    -0.0037589835534809178, 0.0, 0.0, -0.0015035934213923671, 0.0, 0.0,
    -0.0030071868427847342, 0.0, 0.0, -0.0022553901320885505, 0.0, 0.0,
    -0.0015035934213923671, 0.0, 0.0, -0.0030071868427847342, 0.0, 0.0,
    -0.0022553901320885505, 0.0, 0.0, -0.0015035934213923671, 0.0, 0.0,
    -0.00075180974914069781, 0.0, 0.0, -0.00075179671069618354, 0.0, 0.0,
    -0.00075178367225166927, 0.0, 0.0, 0.0022553901320885505, 0.0, 0.0,
    0.0037589835534809178, 0.0, 0.0, 0.0030071868427847342, 0.0, 0.0,
    0.0022553901320885505, 0.0, 0.0, 0.0037589835534809178, 0.0, 0.0,
    0.0015035934213923671, 0.0, 0.0, 0.0030071868427847342, 0.0, 0.0,
    0.0022553901320885505, 0.0, 0.0, 0.0015035934213923671, 0.0, 0.0,
    0.0030071868427847342, 0.0, 0.0, 0.0022553901320885505, 0.0, 0.0,
    0.0015035934213923671, 0.0, 0.0, 0.00075178367225166927, 0.0, 0.0,
    0.00075179671069618354, 0.0, 0.0, 0.00075180974914069781, 0.0, 0.0,
    6.1019920327057558E-9, 0.0, 0.0, -1.007871760957596E-8, 0.0, 0.0,
    -0.0022553901320885505, 0.0, 0.0, -0.0037589835534809178, 0.0, 0.0,
    -0.0030071868427847342, 0.0, 0.0, -0.0022553901320885505, 0.0, 0.0,
    -0.0037589835534809178, 0.0, 0.0, -0.0015035934213923671, 0.0, 0.0,
    -0.0030071868427847342, 0.0, 0.0, -0.0022553901320885505, 0.0, 0.0,
    -0.0015035934213923671, 0.0, 0.0, -0.0030071868427847342, 0.0, 0.0,
    -0.0022553901320885505, 0.0, 0.0, -0.0015035934213923671, 0.0, 0.0,
    -0.00075180974914069781, 0.0, 0.0, -0.00075179671069618354, 0.0, 0.0,
    -0.00075178367225166927, 0.0, 0.0, 0.0030071868427847342, 0.0, 0.0,
    0.0030118806828098926, 0.0, 0.0, -0.0030071868427847342, 0.0, 0.0,
    -0.0030071868427847342, 0.0021238412011774406, 0.0051648618611000461,
    0.002123973626741799, 0.0051648618611000461, 0.00029389205498024027,
    0.00029389205498024027, -0.0021238412011774406, -0.0051648618611000461,
    -0.002123973626741799, -0.0051648618611000461, -0.00029389205498024027,
    -0.00029389205498024027, 0.00048417434840659424, 0.0014369497988512537,
    0.0027672970183941249, 0.0038925170387460835, 0.0044865781204571449,
    0.0020572311423052462, 0.00493219014452262, 0.0052546463937349318,
    0.0016532007454482583, 0.00048437298675313157, 0.0014369497988512537,
    0.0027672970183941249, 0.0038925170387460835, 0.0044865781204571449,
    0.0020573635678696046, 0.00493219014452262, 0.0016532007454482583,
    0.0010286420562654946, 0.0019103711914319592, 0.0010286288137090589,
    -0.00048417434840659424, -0.0014369497988512537, -0.0027672970183941249,
    -0.0038925170387460835, -0.0044865781204571449, -0.0020572311423052462,
    -0.00493219014452262, -0.0052546463937349318, -0.0016532007454482583,
    -0.00048437298675313157, -0.0014369497988512537, -0.0027672970183941249,
    -0.0038925170387460835, -0.0044865781204571449, -0.0020573635678696046,
    -0.00493219014452262, -0.0016532007454482583, -0.0010286420562654946,
    -0.0019103711914319592, -0.0010286288137090589, 0.00029389205498024027,
    0.0011755947050338328, 0.0023512158951805376, 0.0036737500064262722,
    0.00411459471017485, 0.0045554394139234291, 0.0045554394139234291,
    0.00029387881242380447, 0.0011756079475902688, 0.0023512158951805376,
    0.0036737500064262722, 0.00411459471017485, 0.0045554394139234291,
    -0.00029389205498024027, -0.0011755947050338328, -0.0023512158951805376,
    -0.0036737500064262722, -0.00411459471017485, -0.0045554394139234291,
    -0.0045554394139234291, -0.00029387881242380447, -0.0011756079475902688,
    -0.0023512158951805376, -0.0036737500064262722, -0.00411459471017485,
    -0.0045554394139234291, 0.0, 0.0, 0.0032499882004799071, 0.0, 0.0,
    0.0050378657448804948, 0.0, 0.0, 0.003250120626044265, 0.0, 0.0,
    0.0050379981704448528, 0.0, 0.0, -0.0032499882004799071, 0.0, 0.0,
    -0.0050379981704448528, 0.0, 0.0, -0.003250120626044265, 0.0, 0.0,
    -0.0050379981704448528, 0.0, 0.0, 0.00058781059507335227, 0.0, 0.0,
    0.00058781059507335227, 0.0, 0.0, 0.0010286420562654946, 0.0, 0.0,
    0.0014695264876833805, 0.0, 0.0, 0.0014695264876833805, 0.0, 0.0,
    0.0019103711914319592, 0.0, 0.0, 0.0019103711914319592, 0.0, 0.0,
    0.0023512158951805376, 0.0, 0.0, 0.0027920605989291158, 0.0, 0.0,
    0.0027920605989291158, 0.0, 0.0, 0.003232905302677694, 0.0, 0.0,
    0.0036737500064262722, 0.0, 0.0, 0.0023512158951805376, 0.0, 0.0,
    0.003232905302677694, 0.0, 0.0, 0.00411459471017485, 0.0, 0.0,
    0.0027920605989291158, 0.0, 0.0, 0.0036737500064262722, 0.0, 0.0,
    0.00058781059507335227, 0.0, 0.0, 0.00058779735251691641, 0.0, 0.0,
    0.0010286552988219306, 0.0, 0.0, 0.0014695264876833805, 0.0, 0.0,
    0.0014695264876833805, 0.0, 0.0, 0.0019103711914319592, 0.0, 0.0,
    0.0019103711914319592, 0.0, 0.0, 0.0023512158951805376, 0.0, 0.0,
    0.0027920605989291158, 0.0, 0.0, 0.0027920605989291158, 0.0, 0.0,
    0.003232905302677694, 0.0, 0.0, 0.0036737500064262722, 0.0, 0.0,
    0.0023512158951805376, 0.0, 0.0, 0.003232905302677694, 0.0, 0.0,
    0.00411459471017485, 0.0, 0.0, -0.00058781059507335227, 0.0, 0.0,
    -0.00058781059507335227, 0.0, 0.0, -0.0010286420562654946, 0.0, 0.0,
    -0.0014695264876833805, 0.0, 0.0, -0.0014695264876833805, 0.0, 0.0,
    -0.0019103711914319592, 0.0, 0.0, -0.0019103711914319592, 0.0, 0.0,
    -0.0023512158951805376, 0.0, 0.0, -0.0027920605989291158, 0.0, 0.0,
    -0.0027920605989291158, 0.0, 0.0, -0.003232905302677694, 0.0, 0.0,
    -0.0036737500064262722, 0.0, 0.0, -0.0023512158951805376, 0.0, 0.0,
    -0.003232905302677694, 0.0, 0.0, -0.00411459471017485, 0.0, 0.0,
    -0.0027920605989291158, 0.0, 0.0, -0.0036737500064262722, 0.0, 0.0,
    -0.00058781059507335227, 0.0, 0.0, -0.00058779735251691641, 0.0, 0.0,
    -0.0010286552988219306, 0.0, 0.0, -0.0014695264876833805, 0.0, 0.0,
    -0.0014695264876833805, 0.0, 0.0, -0.0019103711914319592, 0.0, 0.0,
    -0.0019103711914319592, 0.0, 0.0, -0.0023512158951805376, 0.0, 0.0,
    -0.0027920605989291158, 0.0, 0.0, -0.0027920605989291158, 0.0, 0.0,
    -0.003232905302677694, 0.0, 0.0, -0.0036737500064262722, 0.0, 0.0,
    -0.0023512158951805376, 0.0, 0.0, -0.003232905302677694, 0.0, 0.0,
    -0.00411459471017485, 0.0, 0.0, 0.00029389205498024027, 0.0, 0.0,
    -0.00029389205498024027, 0.0, 0.0, 0.00029389205498024027, 0.0, 0.0,
    -0.00029389205498024027, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0057147912814261561,
    -0.003897794059768039, 0.0, -0.0010853192132474025, -0.0060420413746131319,
    0.0, 0.0057147912814261561, -0.0038979528811379257, 0.0,
    0.0010851424063669187, -0.0060422001959830191, 0.0, -0.0057147912814261561,
    0.003897794059768039, 0.0, -0.0010853192132474025, 0.0060422001959830191,
    0.0, 0.0057147912814261561, 0.0038979528811379257, 0.0,
    0.0010851424063669187, 0.0060422001959830191, 0.0, -0.00339822824290511,
    -0.000704976296654648, 0.0, -0.0056637137381751841, -0.000704976296654648,
    0.0, -0.0045309709905401469, -0.0012336767548716565, 0.0,
    -0.00339822824290511, -0.0017624407416366196, 0.0, -0.0056637137381751841,
    -0.0017624407416366196, 0.0, -0.0022654854952700735, -0.0022911570819906172,
    0.0, -0.0045309709905401469, -0.0022911570819906172, 0.0,
    -0.00339822824290511, -0.0028198734223446147, 0.0, -0.0022654854952700735,
    -0.0033485897626986116, 0.0, -0.0045309709905401469, -0.0033485897626986116,
    0.0, -0.00339822824290511, -0.003877306103052609, 0.0,
    -0.0022654854952700735, -0.0044060224434066065, 0.0, -0.0011327231024260943,
    -0.0028198734223446147, 0.0, -0.0011327427476350367, -0.003877306103052609,
    0.0, -0.0011327623928439794, -0.0049347387837606034, 0.0,
    -9.1939577851751161E-9, -0.0033485897626986116, 0.0, 1.5185746512693088E-8,
    -0.0044060224434066065, 0.0, 0.00339822824290511, -0.000704976296654648, 0.0,
    0.0056637137381751841, -0.00070496041451765926, 0.0, 0.0045309709905401469,
    -0.0012336926370086453, 0.0, 0.00339822824290511, -0.0017624407416366196,
    0.0, 0.0056637137381751841, -0.0017624407416366196, 0.0,
    0.0022654854952700735, -0.0022911570819906172, 0.0, 0.0045309709905401469,
    -0.0022911570819906172, 0.0, 0.00339822824290511, -0.0028198734223446147,
    0.0, 0.0022654854952700735, -0.0033485897626986116, 0.0,
    0.0045309709905401469, -0.0033485897626986116, 0.0, 0.00339822824290511,
    -0.003877306103052609, 0.0, 0.0022654854952700735, -0.0044060224434066065,
    0.0, 0.0011327623928439794, -0.0028198734223446147, 0.0,
    0.0011327427476350367, -0.003877306103052609, 0.0, 0.0011327231024260943,
    -0.0049347387837606034, 0.0, -0.00339822824290511, 0.000704976296654648, 0.0,
    -0.0056637137381751841, 0.000704976296654648, 0.0, -0.0045309709905401469,
    0.0012336767548716565, 0.0, -0.00339822824290511, 0.0017624407416366196, 0.0,
    -0.0056637137381751841, 0.0017624407416366196, 0.0, -0.0022654854952700735,
    0.0022911570819906172, 0.0, -0.0045309709905401469, 0.0022911570819906172,
    0.0, -0.00339822824290511, 0.0028198734223446147, 0.0,
    -0.0022654854952700735, 0.0033485897626986116, 0.0, -0.0045309709905401469,
    0.0033485897626986116, 0.0, -0.00339822824290511, 0.003877306103052609, 0.0,
    -0.0022654854952700735, 0.0044060224434066065, 0.0, -0.0011327231024260943,
    0.0028198734223446147, 0.0, -0.0011327427476350367, 0.003877306103052609,
    0.0, -0.0011327623928439794, 0.0049347387837606034, 0.0,
    -9.1939577851751161E-9, 0.0033485897626986116, 0.0, 1.5185746512693088E-8,
    0.0044060224434066065, 0.0, 0.00339822824290511, 0.000704976296654648, 0.0,
    0.0056637137381751841, 0.00070496041451765926, 0.0, 0.0045309709905401469,
    0.0012336926370086453, 0.0, 0.00339822824290511, 0.0017624407416366196, 0.0,
    0.0056637137381751841, 0.0017624407416366196, 0.0, 0.0022654854952700735,
    0.0022911570819906172, 0.0, 0.0045309709905401469, 0.0022911570819906172,
    0.0, 0.00339822824290511, 0.0028198734223446147, 0.0, 0.0022654854952700735,
    0.0033485897626986116, 0.0, 0.0045309709905401469, 0.0033485897626986116,
    0.0, 0.00339822824290511, 0.003877306103052609, 0.0, 0.0022654854952700735,
    0.0044060224434066065, 0.0, 0.0011327623928439794, 0.0028198734223446147,
    0.0, 0.0011327427476350367, 0.003877306103052609, 0.0, 0.0011327231024260943,
    0.0049347387837606034, 0.0, -0.0045309709905401469, -0.00035247226619033523,
    0.0, -0.0045380432657595128, 0.00035247226619033523, 0.0,
    0.0045309709905401469, -0.00035247226619033523, 0.0, 0.0045309709905401469,
    0.00035247226619033523, 0.0 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
