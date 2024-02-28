/**********************************************************************
 * Copyright (C) 2014-2023 Cadence Design Systems, Inc.
 * All rights reserved worldwide
 * The material contained herein is the proprietary and confidential
 * information of Cadence or its licensors, and is supplied subject to, and may
 * be used only by Cadence's customer in accordance with a previously executed
 * license and maintenance agreement between Cadence and that customer.
 **********************************************************************
 * Auto generated test file
 * api-generator: 13.06.f48696b
 * based on description files: /project/chopin/work/dkangude/edac_rel/git/css/firmware/components/i3c/src/i3c.yml
 * generated on: 2024-01-31
 **********************************************************************/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>

#include "i3c_if.h"
#include "cdn_stdtypes.h"
#include "cdn_errno.h"
#include "mipi_i3c_regs.h"
#include "i3c_structs_if.h"
#include "mechanical_test_defs.h"

/* Unified macros for logging */
#include "test_harness_log.h"
/* objects with tests results for each group of mechanical tests:
 * null, getset, ranges
 */
TestData testData[4];

#define TEST_PD_SIZE    10240
#define PASS            0
#define FAIL            1
#define NOTSUP          2
#define COUNTOF(x)      (sizeof(x)/sizeof((x)[0]))

#undef LOG
#define LOG(...)        \
    do { \
        printf("TESTING: " __VA_ARGS__); \
        printf("\n"); \
    } while (0)

#define LOG_FAIL_COUNTER uint32_t API_TEST_loggedFirstFail = 0

#undef LOG_FIRST
#define LOG_FIRST(...) \
    do { \
        if (!API_TEST_loggedFirstFail) { \
            printf("TESTING: " __VA_ARGS__); \
            printf("\n"); \
            API_TEST_loggedFirstFail = 1; \
        } \
    } while (0)


#undef DEBUG
#define DEBUG(...)

/* Verbosity level, it may be passed to apigen as a parameter
 * see apigen help for more details
 */
uint32_t API_TEST_verbosity;
uint64_t API_TEST_testFunctionCallCounter;

#define DBG_PRINT_TEST_FUNCTION_CALL_COUNTER \
    do { \
        ++API_TEST_testFunctionCallCounter; \
        if (API_TEST_verbosity && (!(API_TEST_testFunctionCallCounter % 1000))) \
            printf("rep_count: %" PRIu64 "\n", API_TEST_testFunctionCallCounter); \
    } while (0)


/* Numeric ranges test tables: */
uint8_t API_TEST_table_uint8_t[] = {0U, 1U, 2U, 4U, 8U, 9U, 16U, 20U, 32U, 38U, 39U, 42U, 64U, 75U, 91U,
                                    127U, 128U, 135U, 153U, 159U, 180U, 197U, 199U, 211U
                                   };
uint16_t API_TEST_table_uint16_t[] = {0U, 1U, 2U, 4U, 8U, 16U, 32U, 64U, 128U, 256U, 512U, 1024U, 2048U,
                                      2606U, 3667U, 4096U, 5025U, 5228U, 8192U, 11189U, 11846U, 14319U,
                                      16384U, 18247U, 19033U, 19816U, 20688U, 20769U, 23421U, 25885U,
                                      26588U, 29016U, 32767U, 32768U, 38738U, 39694U, 41092U, 41880U,
                                      42355U, 45130U, 46651U, 50379U, 51721U, 56497U, 57632U, 60988U,
                                      62217U, 63605U
                                     };
uint32_t API_TEST_table_uint32_t[] = {0U, 1U, 2U, 4U, 8U, 16U, 32U, 64U, 128U, 256U, 512U, 1024U, 2048U,
                                      4096U, 8192U, 16384U, 32768U, 65536U, 131072U, 262144U, 524288U,
                                      1048576U, 2097152U, 4194304U, 8388608U, 16777216U, 24258374U,
                                      33554432U, 67108864U, 91066400U, 134217728U, 158527674U, 225576424U,
                                      262546402U, 268435456U, 272315039U, 397036135U, 407256804U,
                                      522049120U, 536870912U, 599264978U, 656854443U, 750191893U,
                                      911825313U, 947671328U, 983569679U, 1023672237U, 1069062352U,
                                      1073741824U, 1106516408U, 1172465768U, 1221046446U, 1326359119U,
                                      1327031483U, 1455752577U, 1562546591U, 1653189031U, 1706701447U,
                                      1758920551U, 1793238885U, 1794736472U, 1914882737U, 1924972832U,
                                      2147483647U, 2147483648U, 2254736849U, 2364410753U, 2467812973U,
                                      2521259143U, 2662475655U, 2711832081U, 2728725998U, 2753279284U,
                                      2811760654U, 2832151346U, 2875108032U, 2958012674U, 3002270526U,
                                      3029441596U, 3228179624U, 3280304829U, 3322099050U, 3327551439U,
                                      3366477628U, 3448629590U, 3511201845U, 3529931657U, 3696072945U,
                                      3786669711U, 3790341467U, 3980802259U, 4068279729U, 4095584117U,
                                      4135981146U, 4219601472U, 4256111420U
                                     };
int32_t API_TEST_table_int32_t[] = {-2147483648U, -1768271131U, -1612783628U, -1523601452U, -1514174595U,
                                    -1465641756U, -1461875348U, -1414489803U, -1194406971U, -1073741824U,
                                    -980953094U, -577424718U, -536870912U, -512592644U, -268435456U,
                                    -205251617U, -134217728U, -67108864U, -33554432U, -16777216U,
                                    -8388608U, -4194304U, -2097152U, -1048576U, -524288U, -262144U,
                                    -131072U, -65536U, -32768U, -16384U, -8192U, -4096U, -2048U, -1024U,
                                    -512U, -256U, -128U, -64U, -32U, -16U, -8U, -4U, -2U, -1U, 0U, 1U,
                                    2U, 4U, 8U, 16U, 32U, 64U, 128U, 256U, 512U, 1024U, 2048U, 4096U,
                                    8192U, 16384U, 32768U, 65536U, 131072U, 262144U, 524288U, 1048576U,
                                    2097152U, 4194304U, 8388608U, 16777216U, 33554432U, 67108864U,
                                    134217728U, 170954785U, 268435456U, 371374408U, 505209076U,
                                    520456430U, 536870912U, 547838503U, 616470856U, 790759766U,
                                    910128690U, 943424743U, 987629900U, 1050745412U, 1073741824U,
                                    1166264920U, 1238047252U, 1353862682U, 1363336796U, 1643368476U,
                                    1800235695U, 1811021760U, 1833318360U, 2147483647U
                                   };
uint64_t API_TEST_table_uint64_t[] = {0U, 1U, 2U, 4U, 8U, 16U, 32U, 64U, 128U, 256U, 512U, 1024U, 2048U,
                                      4096U, 8192U, 16384U, 32768U, 65536U, 131072U, 262144U, 524288U,
                                      1048576U, 2097152U, 4194304U, 8388608U, 16777216U, 33554432U,
                                      67108864U, 134217728U, 268435456U, 536870912U, 1073741824U,
                                      2147483648U, 4294967296U, 8589934592U, 17179869184U, 34359738368U,
                                      68719476736U, 137438953472U, 274877906944U, 549755813888U,
                                      1099511627776U, 2199023255552U, 4398046511104U, 8796093022208U,
                                      17592186044416U, 35184372088832U, 70368744177664U, 140737488355328U,
                                      281474976710656U, 562949953421312U, 1125899906842624U,
                                      2251799813685248U, 4503599627370496U, 9007199254740992U,
                                      13420768519534272U, 18014398509481984U, 36028797018963968U,
                                      72057594037927936U, 144115188075855872U, 276749545950707985U,
                                      288230376151711744U, 576460752303423488U, 607260939294438349U,
                                      753387150390897332U, 831912359416037387U, 901313595209767734U,
                                      971708431945298189U, 1129106406849318936U, 1152921504606846976U,
                                      1599925478352644179U, 1746275998251425236U, 1957735660671768022U,
                                      1979327794798617888U, 2264620679955988528U, 2305843009213693952U,
                                      2348503742409852798U, 2578580015407743695U, 2754719452735207605U,
                                      3228735712361760679U, 3368401706123512673U, 3495970166861065389U,
                                      3587658216512400236U, 3804979879158097834U, 4018463899582128972U,
                                      4087497357238026125U, 4206395283033265117U, 4322634238892097754U,
                                      4413483023049953819U, 4611686018427387904U, 4668784643095900086U,
                                      4669958453248763398U, 5006377758629985428U, 5020662903236851904U,
                                      5791680656729931499U, 6077275382616404215U, 6080826743608684014U,
                                      6150151622250525887U, 6205086641155308488U, 6681898468948301273U,
                                      6991684426462529606U, 6996857774080946187U, 7001462560959117959U,
                                      7145505207571838746U, 7146251129185255306U, 7329521266858995804U,
                                      7345892257167551899U, 8209030418627954348U, 8221199980292195163U,
                                      8327352203941226849U, 8391169105237293020U, 8462931712016189585U,
                                      8520764955699486134U, 8521095595061522368U, 8547529532620310724U,
                                      8805422373150637154U, 8862348452724795212U, 8951683067338485841U,
                                      9007822837459835882U, 9092474367874386731U, 9223372036854775807U,
                                      9223372036854775808U, 9333247762926034011U, 9686420357386194992U,
                                      9706681004499904891U, 9763794573485052982U, 9954250467255851807U,
                                      9958798283568273615U, 9975167162924020105U, 10003311929818447961U,
                                      10315805037105633092U, 10383507335228560097U, 10626804139319438177U,
                                      10959069314822153244U, 10972572081416913760U, 11086122807696958868U,
                                      11262294578001182697U, 11582643798810002557U, 11607267000933496802U,
                                      11643896594021294341U, 11849146648064099715U, 11883749114493018773U,
                                      11897200019628232253U, 11934072838833802433U, 11949998031416241604U,
                                      12190851466994040836U, 12390169055696595492U, 12453185296436102918U,
                                      12471118035503072109U, 12602751169200246926U, 12791513079662825005U,
                                      12853792664280481554U, 12916557473578188586U, 13631747297464845364U,
                                      14085566053547060687U, 14335901514611911533U, 14362687844336117813U,
                                      14432799152868220929U, 14483273422669377110U, 14556638546749490769U,
                                      14565301295856610082U, 14813987000528419344U, 14851949406661861801U,
                                      14858683192877354562U, 14945477923392755008U, 15064687960334340407U,
                                      15256886649369883698U, 15349738963351329431U, 15663355656158798425U,
                                      15789646407032670566U, 15949000971146550379U, 15975265249915027605U,
                                      16081677261107459131U, 16187304596416821878U, 16406781243612865449U,
                                      16561649438940625062U, 17029982671239554528U, 17035959413542784109U,
                                      17053157409112091530U, 17158095039492396195U, 17244931517986591736U,
                                      17317338438316803259U, 17432602938954822462U, 17574140401027513164U,
                                      17782199563523209696U, 18143684265542111452U, 18301351629700177978U,
                                      18376284348935684590U, 18377690216000114136U, 18400694742979001076U,
                                      18430830316787694344U, 18434085879559059341U
                                     };
int64_t API_TEST_table_int64_t[] = {-9223372036854775808U, -9178708997387755754U, -9090434558340169764U,
                                    -8562788387007278101U, -8425738404786081544U, -7795184729384615267U,
                                    -7769651592028978492U, -7319020255755652802U, -7225065731623186105U,
                                    -7079043302095707782U, -7074216320577161588U, -7002963764432090238U,
                                    -6617356805778326446U, -6220207709896553556U, -6087439483586940515U,
                                    -5857125502883076595U, -5680873369455749294U, -4611686018427387904U,
                                    -4497500832993903545U, -4391590057039761090U, -4297317657806373340U,
                                    -3917714052509429654U, -3314975717422269049U, -3162618340470667355U,
                                    -2995276761023607855U, -2966630646112882919U, -2825710567758366261U,
                                    -2305843009213693952U, -1509145285287715581U, -1382238533400377530U,
                                    -1372556838229906497U, -1357233328244023056U, -1152921504606846976U,
                                    -926654584206758913U, -662135508533577956U, -576460752303423488U,
                                    -288230376151711744U, -144115188075855872U, -72057594037927936U,
                                    -36028797018963968U, -18014398509481984U, -9007199254740992U,
                                    -4503599627370496U, -2251799813685248U, -1125899906842624U,
                                    -562949953421312U, -281474976710656U, -140737488355328U,
                                    -70368744177664U, -35184372088832U, -17592186044416U,
                                    -8796093022208U, -4398046511104U, -2199023255552U, -1099511627776U,
                                    -549755813888U, -274877906944U, -137438953472U, -68719476736U,
                                    -34359738368U, -17179869184U, -8589934592U, -4294967296U,
                                    -2147483648U, -1073741824U, -536870912U, -268435456U, -134217728U,
                                    -67108864U, -33554432U, -16777216U, -8388608U, -4194304U, -2097152U,
                                    -1048576U, -524288U, -262144U, -131072U, -65536U, -32768U, -16384U,
                                    -8192U, -4096U, -2048U, -1024U, -512U, -256U, -128U, -64U, -32U,
                                    -16U, -8U, -4U, -2U, -1U, 0U, 1U, 2U, 4U, 8U, 16U, 32U, 64U, 128U,
                                    256U, 512U, 1024U, 2048U, 4096U, 8192U, 16384U, 32768U, 65536U,
                                    131072U, 262144U, 524288U, 1048576U, 2097152U, 4194304U, 8388608U,
                                    16777216U, 33554432U, 67108864U, 134217728U, 268435456U, 536870912U,
                                    1073741824U, 2147483648U, 4294967296U, 8589934592U, 17179869184U,
                                    34359738368U, 68719476736U, 137438953472U, 274877906944U,
                                    549755813888U, 1099511627776U, 2199023255552U, 4398046511104U,
                                    8796093022208U, 17592186044416U, 35184372088832U, 70368744177664U,
                                    140737488355328U, 281474976710656U, 562949953421312U,
                                    1125899906842624U, 2251799813685248U, 4503599627370496U,
                                    9007199254740992U, 18014398509481984U, 36028797018963968U,
                                    72057594037927936U, 144115188075855872U, 236915964565510859U,
                                    288230376151711744U, 296951648104140827U, 339953462365539876U,
                                    576460752303423488U, 629100381987462169U, 691304889275037423U,
                                    727473349848759582U, 829915502582523905U, 1152921504606846976U,
                                    1182500070114731351U, 1250163884734318749U, 1251818063216431473U,
                                    1366115799383751402U, 1708420339279185775U, 1793965184719019374U,
                                    2111597392023586108U, 2305843009213693952U, 2660890495398216654U,
                                    2856580135888348657U, 3853381856888583089U, 4036884699477568837U,
                                    4186904185729236758U, 4611686018427387904U, 4626331308388294158U,
                                    4834907972740799041U, 4936704778113999965U, 5160905382557389414U,
                                    6928894755792788272U, 7697590191404393405U, 7706340724624095309U,
                                    7830641026871723501U, 8033762161788889780U, 8742639031109458321U,
                                    9032318739606957412U, 9053118993138646163U, 9084461513675961632U,
                                    9223372036854775807U
                                   };
bool API_TEST_table_bool[] = {true, false};


/* Required global variables: */


#define API_TEST_structTestLen_I3C_InterruptConfig    ((uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1))
#define API_TEST_structTestLen_I3C_SlaveInterruptConfig    ((uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1))
#define API_TEST_structTestLen_I3C_ThresholdConfig    ((uint64_t)(UINT16_MAX)*(uint64_t)(UINT16_MAX)*(uint64_t)(UINT8_MAX)*(uint64_t)(UINT8_MAX))
#define API_TEST_structTestLen_I3C_Config    ((uint64_t)(UINT32_MAX)*(uint64_t)(UINT32_MAX)*(uint64_t)(UINT32_MAX)*(uint64_t)(UINT32_MAX)*(uint64_t)(UINT32_MAX)*(uint64_t)(UINT8_MAX)*(uint64_t)(UINT8_MAX)*(uint64_t)(UINT16_MAX)*(uint64_t)(UINT16_MAX)*(uint64_t)(UINT16_MAX)*(uint64_t)(UINT16_MAX)*(uint64_t)(API_TEST_structTestLen_I3C_ThresholdConfig)*(uint64_t)(API_TEST_structTestLen_I3C_InterruptConfig)*(uint64_t)(API_TEST_structTestLen_I3C_SlaveInterruptConfig))
#define API_TEST_structTestLen_I3C_SysReq    ((uint64_t)(UINT32_MAX))
#define API_TEST_structTestLen_I3C_Callbacks    (1)
#define API_TEST_structTestLen_I3C_DeviceDescriptor    ((uint64_t)(UINT8_MAX)*(uint64_t)(1)*(uint64_t)(UINT8_MAX)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(UINT16_MAX)*(uint64_t)(UINT16_MAX)*(uint64_t)(UINT32_MAX)*(uint64_t)(UINT8_MAX)*(uint64_t)(UINT8_MAX))
#define API_TEST_structTestLen_I3C_SlaveDescriptor    ((uint64_t)(UINT8_MAX)*(uint64_t)(UINT8_MAX)*(uint64_t)(UINT8_MAX)*(uint64_t)(UINT8_MAX))
#define API_TEST_structTestLen_I3C_SlaveDescriptors    ((uint64_t)(UINT8_MAX)*(uint64_t)(API_TEST_structTestLen_I3C_SlaveDescriptor))
#define API_TEST_structTestLen_I3C_IbiSirConfiguration    ((uint64_t)(2)*(uint64_t)(UINT16_MAX)*(uint64_t)(UINT8_MAX)*(uint64_t)(2)*(uint64_t)(2))
#define API_TEST_structTestLen_I3C_Ibi    ((uint64_t)(UINT8_MAX)*(uint64_t)(UINT8_MAX)*(uint64_t)(1)*(uint64_t)(UINT8_MAX)*(uint64_t)(1))
#define API_TEST_structTestLen_I3C_CommandDescriptor    ((uint64_t)(53)*(uint64_t)(UINT16_MAX))
#define API_TEST_structTestLen_I3C_cmd_t    ((uint64_t)(UINT8_MAX)*(uint64_t)(INT64_MAX)*(uint64_t)(UINT16_MAX)*(uint64_t)(UINT32_MAX)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(UINT16_MAX)*(uint64_t)(UINT16_MAX)*(uint64_t)(UINT8_MAX)*(uint64_t)(1))
#define API_TEST_structTestLen_I3C_cmd_list_element    ((uint64_t)(API_TEST_structTestLen_I3C_cmd_t)*(uint64_t)(1))
#define API_TEST_structTestLen_I3C_cmd_list    ((uint64_t)(0)*(uint64_t)(0))
#define API_TEST_structTestLen_I3C_CsrData    ((uint64_t)(UINT16_MAX)*(uint64_t)(1))
#define API_TEST_structTestLen_I3C_PayloadData    ((uint64_t)(UINT16_MAX))
#define API_TEST_structTestLen_I3C_TransmissionParameters    ((uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1))
#define API_TEST_structTestLen_I3C_PrivData    ((uint64_t)(1)*(uint64_t)(1)*(uint64_t)(UINT8_MAX)*(uint64_t)(UINT8_MAX)*(uint64_t)(UINT8_MAX)*(uint64_t)(UINT8_MAX)*(uint64_t)(API_TEST_structTestLen_I3C_Callbacks)*(uint64_t)(API_TEST_structTestLen_I3C_DeviceDescriptor)*(uint64_t)(API_TEST_structTestLen_I3C_InterruptConfig)*(uint64_t)(API_TEST_structTestLen_I3C_SlaveInterruptConfig)*(uint64_t)(API_TEST_structTestLen_I3C_ThresholdConfig)*(uint64_t)(2)*(uint64_t)(4)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(1)*(uint64_t)(UINT16_MAX)*(uint64_t)(1)*(uint64_t)(UINT16_MAX)*(uint64_t)(UINT16_MAX)*(uint64_t)(1)*(uint64_t)(UINT16_MAX)*(uint64_t)(UINT16_MAX)*(uint64_t)(UINT16_MAX)*(uint64_t)(UINT16_MAX)*(uint64_t)(UINT16_MAX)*(uint64_t)(API_TEST_structTestLen_I3C_cmd_t)*(uint64_t)(API_TEST_structTestLen_I3C_cmd_list)*(uint64_t)(API_TEST_structTestLen_I3C_cmd_list_element)*(uint64_t)(UINT8_MAX)*(uint64_t)(API_TEST_structTestLen_I3C_Ibi)*(uint64_t)(UINT16_MAX)*(uint64_t)(UINT16_MAX)*(uint64_t)(UINT16_MAX)*(uint64_t)(UINT16_MAX)*(uint64_t)(UINT16_MAX)*(uint64_t)(UINT16_MAX)*(uint64_t)(UINT16_MAX))
#define API_TEST_structTestLen_I3C_AsfInfo    (1)
#define API_TEST_structTestLen_I3C_MaxReadLength    ((uint64_t)(UINT16_MAX)*(uint64_t)(UINT8_MAX))
#define API_TEST_structTestLen_I3C_MaxDataSpeed    ((uint64_t)(UINT8_MAX)*(uint64_t)(UINT8_MAX))
#define API_TEST_structTestLen_I3C_Tcam0Data    ((uint64_t)(UINT8_MAX)*(uint64_t)(UINT8_MAX)*(uint64_t)(UINT8_MAX)*(uint64_t)(UINT8_MAX))
#define API_TEST_structTestLen_I3C_GroupDescriptors    ((uint64_t)(UINT8_MAX)*(uint64_t)(UINT8_MAX)*(uint64_t)(UINT8_MAX)*(uint64_t)(UINT8_MAX))


void API_TEST_printstruct_I3C_InterruptConfig(const I3C_InterruptConfig *obj, const char *name);
uint32_t API_TEST_verify_I3C_InterruptConfig(const I3C_InterruptConfig *obj);
uint32_t API_TEST_comparestruct_I3C_InterruptConfig(I3C_InterruptConfig *s1, I3C_InterruptConfig *s2, uint32_t nolog);
void API_TEST_fill_I3C_InterruptConfig(I3C_InterruptConfig *obj, uint32_t index);
void API_TEST_fillvalid_I3C_InterruptConfig(I3C_InterruptConfig *obj, uint64_t index);
void API_TEST_printstruct_I3C_SlaveInterruptConfig(const I3C_SlaveInterruptConfig *obj, const char *name);
uint32_t API_TEST_verify_I3C_SlaveInterruptConfig(const I3C_SlaveInterruptConfig *obj);
uint32_t API_TEST_comparestruct_I3C_SlaveInterruptConfig(I3C_SlaveInterruptConfig *s1, I3C_SlaveInterruptConfig *s2, uint32_t nolog);
void API_TEST_fill_I3C_SlaveInterruptConfig(I3C_SlaveInterruptConfig *obj, uint32_t index);
void API_TEST_fillvalid_I3C_SlaveInterruptConfig(I3C_SlaveInterruptConfig *obj, uint64_t index);
void API_TEST_printstruct_I3C_ThresholdConfig(const I3C_ThresholdConfig *obj, const char *name);
uint32_t API_TEST_verify_I3C_ThresholdConfig(const I3C_ThresholdConfig *obj);
uint32_t API_TEST_comparestruct_I3C_ThresholdConfig(I3C_ThresholdConfig *s1, I3C_ThresholdConfig *s2, uint32_t nolog);
void API_TEST_fill_I3C_ThresholdConfig(I3C_ThresholdConfig *obj, uint32_t index);
void API_TEST_fillvalid_I3C_ThresholdConfig(I3C_ThresholdConfig *obj, uint64_t index);
void API_TEST_printstruct_I3C_Config(const I3C_Config *obj, const char *name);
uint32_t API_TEST_verify_I3C_Config(const I3C_Config *obj);
uint32_t API_TEST_comparestruct_I3C_Config(I3C_Config *s1, I3C_Config *s2, uint32_t nolog);
void API_TEST_fill_I3C_Config(I3C_Config *obj, uint32_t index);
void API_TEST_fillvalid_I3C_Config(I3C_Config *obj, uint64_t index);
void API_TEST_printstruct_I3C_SysReq(const I3C_SysReq *obj, const char *name);
uint32_t API_TEST_verify_I3C_SysReq(const I3C_SysReq *obj);
uint32_t API_TEST_comparestruct_I3C_SysReq(I3C_SysReq *s1, I3C_SysReq *s2, uint32_t nolog);
void API_TEST_fill_I3C_SysReq(I3C_SysReq *obj, uint32_t index);
void API_TEST_fillvalid_I3C_SysReq(I3C_SysReq *obj, uint64_t index);
void API_TEST_printstruct_I3C_Callbacks(const I3C_Callbacks *obj, const char *name);
uint32_t API_TEST_verify_I3C_Callbacks(const I3C_Callbacks *obj);
uint32_t API_TEST_comparestruct_I3C_Callbacks(I3C_Callbacks *s1, I3C_Callbacks *s2, uint32_t nolog);
void API_TEST_fill_I3C_Callbacks(I3C_Callbacks *obj, uint32_t index);
void API_TEST_fillvalid_I3C_Callbacks(I3C_Callbacks *obj, uint64_t index);
void API_TEST_printstruct_I3C_DeviceDescriptor(const I3C_DeviceDescriptor *obj, const char *name);
uint32_t API_TEST_verify_I3C_DeviceDescriptor(const I3C_DeviceDescriptor *obj);
uint32_t API_TEST_comparestruct_I3C_DeviceDescriptor(I3C_DeviceDescriptor *s1, I3C_DeviceDescriptor *s2, uint32_t nolog);
void API_TEST_fill_I3C_DeviceDescriptor(I3C_DeviceDescriptor *obj, uint32_t index);
void API_TEST_fillvalid_I3C_DeviceDescriptor(I3C_DeviceDescriptor *obj, uint64_t index);
void API_TEST_printstruct_I3C_SlaveDescriptor(const I3C_SlaveDescriptor *obj, const char *name);
uint32_t API_TEST_verify_I3C_SlaveDescriptor(const I3C_SlaveDescriptor *obj);
uint32_t API_TEST_comparestruct_I3C_SlaveDescriptor(I3C_SlaveDescriptor *s1, I3C_SlaveDescriptor *s2, uint32_t nolog);
void API_TEST_fill_I3C_SlaveDescriptor(I3C_SlaveDescriptor *obj, uint32_t index);
void API_TEST_fillvalid_I3C_SlaveDescriptor(I3C_SlaveDescriptor *obj, uint64_t index);
void API_TEST_printstruct_I3C_SlaveDescriptors(const I3C_SlaveDescriptors *obj, const char *name);
uint32_t API_TEST_verify_I3C_SlaveDescriptors(const I3C_SlaveDescriptors *obj);
uint32_t API_TEST_comparestruct_I3C_SlaveDescriptors(I3C_SlaveDescriptors *s1, I3C_SlaveDescriptors *s2, uint32_t nolog);
void API_TEST_fill_I3C_SlaveDescriptors(I3C_SlaveDescriptors *obj, uint32_t index);
void API_TEST_fillvalid_I3C_SlaveDescriptors(I3C_SlaveDescriptors *obj, uint64_t index);
void API_TEST_printstruct_I3C_IbiSirConfiguration(const I3C_IbiSirConfiguration *obj, const char *name);
uint32_t API_TEST_verify_I3C_IbiSirConfiguration(const I3C_IbiSirConfiguration *obj);
uint32_t API_TEST_comparestruct_I3C_IbiSirConfiguration(I3C_IbiSirConfiguration *s1, I3C_IbiSirConfiguration *s2, uint32_t nolog);
void API_TEST_fill_I3C_IbiSirConfiguration(I3C_IbiSirConfiguration *obj, uint32_t index);
void API_TEST_fillvalid_I3C_IbiSirConfiguration(I3C_IbiSirConfiguration *obj, uint64_t index);
void API_TEST_printstruct_I3C_Ibi(const I3C_Ibi *obj, const char *name);
uint32_t API_TEST_verify_I3C_Ibi(const I3C_Ibi *obj);
uint32_t API_TEST_comparestruct_I3C_Ibi(I3C_Ibi *s1, I3C_Ibi *s2, uint32_t nolog);
void API_TEST_fill_I3C_Ibi(I3C_Ibi *obj, uint32_t index);
void API_TEST_fillvalid_I3C_Ibi(I3C_Ibi *obj, uint64_t index);
void API_TEST_printstruct_I3C_CommandDescriptor(const I3C_CommandDescriptor *obj, const char *name);
uint32_t API_TEST_verify_I3C_CommandDescriptor(const I3C_CommandDescriptor *obj);
uint32_t API_TEST_comparestruct_I3C_CommandDescriptor(I3C_CommandDescriptor *s1, I3C_CommandDescriptor *s2, uint32_t nolog);
void API_TEST_fill_I3C_CommandDescriptor(I3C_CommandDescriptor *obj, uint32_t index);
void API_TEST_fillvalid_I3C_CommandDescriptor(I3C_CommandDescriptor *obj, uint64_t index);
void API_TEST_printstruct_I3C_cmd_t(const I3C_cmd_t *obj, const char *name);
uint32_t API_TEST_verify_I3C_cmd_t(const I3C_cmd_t *obj);
uint32_t API_TEST_comparestruct_I3C_cmd_t(I3C_cmd_t *s1, I3C_cmd_t *s2, uint32_t nolog);
void API_TEST_fill_I3C_cmd_t(I3C_cmd_t *obj, uint32_t index);
void API_TEST_fillvalid_I3C_cmd_t(I3C_cmd_t *obj, uint64_t index);
void API_TEST_printstruct_I3C_cmd_list_element(const I3C_cmd_list_element *obj, const char *name);
uint32_t API_TEST_verify_I3C_cmd_list_element(const I3C_cmd_list_element *obj);
uint32_t API_TEST_comparestruct_I3C_cmd_list_element(I3C_cmd_list_element *s1, I3C_cmd_list_element *s2, uint32_t nolog);
void API_TEST_fill_I3C_cmd_list_element(I3C_cmd_list_element *obj, uint32_t index);
void API_TEST_fillvalid_I3C_cmd_list_element(I3C_cmd_list_element *obj, uint64_t index);
void API_TEST_printstruct_I3C_cmd_list(const I3C_cmd_list *obj, const char *name);
uint32_t API_TEST_verify_I3C_cmd_list(const I3C_cmd_list *obj);
uint32_t API_TEST_comparestruct_I3C_cmd_list(I3C_cmd_list *s1, I3C_cmd_list *s2, uint32_t nolog);
void API_TEST_fill_I3C_cmd_list(I3C_cmd_list *obj, uint32_t index);
void API_TEST_fillvalid_I3C_cmd_list(I3C_cmd_list *obj, uint64_t index);
void API_TEST_printstruct_I3C_CsrData(const I3C_CsrData *obj, const char *name);
uint32_t API_TEST_verify_I3C_CsrData(const I3C_CsrData *obj);
uint32_t API_TEST_comparestruct_I3C_CsrData(I3C_CsrData *s1, I3C_CsrData *s2, uint32_t nolog);
void API_TEST_fill_I3C_CsrData(I3C_CsrData *obj, uint32_t index);
void API_TEST_fillvalid_I3C_CsrData(I3C_CsrData *obj, uint64_t index);
void API_TEST_printstruct_I3C_PayloadData(const I3C_PayloadData *obj, const char *name);
uint32_t API_TEST_verify_I3C_PayloadData(const I3C_PayloadData *obj);
uint32_t API_TEST_comparestruct_I3C_PayloadData(I3C_PayloadData *s1, I3C_PayloadData *s2, uint32_t nolog);
void API_TEST_fill_I3C_PayloadData(I3C_PayloadData *obj, uint32_t index);
void API_TEST_fillvalid_I3C_PayloadData(I3C_PayloadData *obj, uint64_t index);
void API_TEST_printstruct_I3C_TransmissionParameters(const I3C_TransmissionParameters *obj, const char *name);
uint32_t API_TEST_verify_I3C_TransmissionParameters(const I3C_TransmissionParameters *obj);
uint32_t API_TEST_comparestruct_I3C_TransmissionParameters(I3C_TransmissionParameters *s1, I3C_TransmissionParameters *s2, uint32_t nolog);
void API_TEST_fill_I3C_TransmissionParameters(I3C_TransmissionParameters *obj, uint32_t index);
void API_TEST_fillvalid_I3C_TransmissionParameters(I3C_TransmissionParameters *obj, uint64_t index);
void API_TEST_printstruct_I3C_PrivData(const I3C_PrivData *obj, const char *name);
uint32_t API_TEST_verify_I3C_PrivData(const I3C_PrivData *obj);
uint32_t API_TEST_comparestruct_I3C_PrivData(I3C_PrivData *s1, I3C_PrivData *s2, uint32_t nolog);
void API_TEST_fill_I3C_PrivData(I3C_PrivData *obj, uint32_t index);
void API_TEST_fillvalid_I3C_PrivData(I3C_PrivData *obj, uint64_t index);
void API_TEST_printstruct_I3C_AsfInfo(const I3C_AsfInfo *obj, const char *name);
uint32_t API_TEST_verify_I3C_AsfInfo(const I3C_AsfInfo *obj);
uint32_t API_TEST_comparestruct_I3C_AsfInfo(I3C_AsfInfo *s1, I3C_AsfInfo *s2, uint32_t nolog);
void API_TEST_fill_I3C_AsfInfo(I3C_AsfInfo *obj, uint32_t index);
void API_TEST_fillvalid_I3C_AsfInfo(I3C_AsfInfo *obj, uint64_t index);
void API_TEST_printstruct_I3C_MaxReadLength(const I3C_MaxReadLength *obj, const char *name);
uint32_t API_TEST_verify_I3C_MaxReadLength(const I3C_MaxReadLength *obj);
uint32_t API_TEST_comparestruct_I3C_MaxReadLength(I3C_MaxReadLength *s1, I3C_MaxReadLength *s2, uint32_t nolog);
void API_TEST_fill_I3C_MaxReadLength(I3C_MaxReadLength *obj, uint32_t index);
void API_TEST_fillvalid_I3C_MaxReadLength(I3C_MaxReadLength *obj, uint64_t index);
void API_TEST_printstruct_I3C_MaxDataSpeed(const I3C_MaxDataSpeed *obj, const char *name);
uint32_t API_TEST_verify_I3C_MaxDataSpeed(const I3C_MaxDataSpeed *obj);
uint32_t API_TEST_comparestruct_I3C_MaxDataSpeed(I3C_MaxDataSpeed *s1, I3C_MaxDataSpeed *s2, uint32_t nolog);
void API_TEST_fill_I3C_MaxDataSpeed(I3C_MaxDataSpeed *obj, uint32_t index);
void API_TEST_fillvalid_I3C_MaxDataSpeed(I3C_MaxDataSpeed *obj, uint64_t index);
void API_TEST_printstruct_I3C_Tcam0Data(const I3C_Tcam0Data *obj, const char *name);
uint32_t API_TEST_verify_I3C_Tcam0Data(const I3C_Tcam0Data *obj);
uint32_t API_TEST_comparestruct_I3C_Tcam0Data(I3C_Tcam0Data *s1, I3C_Tcam0Data *s2, uint32_t nolog);
void API_TEST_fill_I3C_Tcam0Data(I3C_Tcam0Data *obj, uint32_t index);
void API_TEST_fillvalid_I3C_Tcam0Data(I3C_Tcam0Data *obj, uint64_t index);
void API_TEST_printstruct_I3C_GroupDescriptors(const I3C_GroupDescriptors *obj, const char *name);
uint32_t API_TEST_verify_I3C_GroupDescriptors(const I3C_GroupDescriptors *obj);
uint32_t API_TEST_comparestruct_I3C_GroupDescriptors(I3C_GroupDescriptors *s1, I3C_GroupDescriptors *s2, uint32_t nolog);
void API_TEST_fill_I3C_GroupDescriptors(I3C_GroupDescriptors *obj, uint32_t index);
void API_TEST_fillvalid_I3C_GroupDescriptors(I3C_GroupDescriptors *obj, uint64_t index);


uint32_t API_TEST_nullptr_probe(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_init(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_isr(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_start(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_stop(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_destroy(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_enableCore(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_disableCore(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_setBusMode(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_getBusMode(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_setBcr(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_setDcr(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_setPid(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_configureDevices(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_configureDevice(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_configurePrescalers(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_clearRrOfDevice(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_getNewDevices(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_configureInterrupts(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_configureThresholds(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdExec(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdExecImmediate(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_enableMcs(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_disableMcs(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_manualCommandStart(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdCount(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdMaxCount(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdClearAll(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_devPrint(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_enableTc(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddPrivWrite(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddPrivRead(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddPrivI2CWrite(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddPrivI2CRead(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddDdrWrite(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddDdrRead(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddSetSlaveEvents(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddEnterActivityState(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddResetDaa(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddEnterDaa(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddSetMaxWriteLength(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddGetMaxWriteLength(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddSetMaxReadLength(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddGetMaxReadLength(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddGetMaxDataSpeed(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_getSlavesList(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddDefineSlavesList(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddEnterTestMode(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddSetBuscon(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddEnterHdrMode(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddSetAaSa(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdSetDaFromSa(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddSetNewDa(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddSetRstAct(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddSetXTime(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddSetGroupAddr(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddDefineGroupList(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddResetGrpa(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddGetProvisionalId(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddGetBcr(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddGetDcr(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddGetStatus(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddGetAccMst(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_cmdAddGetXTime(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_CmdSetNCAMode(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_ibiConfigureDevices(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_ibiModifyDeviceConfig(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_ibiGetAddressOfIssuer(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_ibiGetData(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_hjConfigureResponse(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_configureSlaveInterrupts(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_slaveModeConfigure(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_slaveModeReqSdrRead(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_slaveModeReqSdrWrite(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_slaveModeReqDdrRead(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_slaveModeReqDdrWrite(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_slaveModeRequestHotJoin(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_slaveModeMastershipReq(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_slaveModeRequestIbi(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_slaveModeWriteIbiPayload(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_slaveModeReadIbiPayload(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_slaveModeReqFlowControl(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_slaveModeReadApbRo(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_slaveModeReadApbRw(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_slaveModeWriteApbRw(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_slaveModeReadGpo(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_slaveModeReadGpi(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_slaveModeReadMWL(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_slaveModeReadMRL(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_getFifoFillLvl(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_setSdrFifoFlush(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_slaveGetIbiStatus(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_getAsfInfo(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr_checkOperationMode(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_nullptr(I3C_OBJ *obj);
static uint32_t API_TEST_ranges_probe(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_init(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_isr(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_start(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_stop(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_destroy(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_enableCore(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_disableCore(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_setBusMode(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_getBusMode(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_setBcr(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_setDcr(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_setPid(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_configureDevices(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_configureDevice(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_configurePrescalers(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_clearRrOfDevice(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_getNewDevices(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_configureInterrupts(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_configureThresholds(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdExec(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdExecImmediate(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_enableMcs(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_disableMcs(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_manualCommandStart(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdCount(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdMaxCount(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdClearAll(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_devPrint(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_enableTc(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddPrivWrite(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddPrivRead(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddPrivI2CWrite(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddPrivI2CRead(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddDdrWrite(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddDdrRead(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddSetSlaveEvents(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddEnterActivityState(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddResetDaa(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddEnterDaa(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddSetMaxWriteLength(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddGetMaxWriteLength(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddSetMaxReadLength(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddGetMaxReadLength(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddGetMaxDataSpeed(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_getSlavesList(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddDefineSlavesList(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddEnterTestMode(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddSetBuscon(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddEnterHdrMode(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddSetAaSa(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdSetDaFromSa(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddSetNewDa(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddSetRstAct(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddSetXTime(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddSetGroupAddr(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddDefineGroupList(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddResetGrpa(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddGetProvisionalId(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddGetBcr(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddGetDcr(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddGetStatus(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddGetAccMst(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_cmdAddGetXTime(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_CmdSetNCAMode(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_ibiConfigureDevices(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_ibiModifyDeviceConfig(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_ibiGetAddressOfIssuer(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_ibiGetData(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_hjConfigureResponse(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_configureSlaveInterrupts(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_slaveModeConfigure(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_slaveModeReqSdrRead(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_slaveModeReqSdrWrite(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_slaveModeReqDdrRead(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_slaveModeReqDdrWrite(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_slaveModeRequestHotJoin(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_slaveModeMastershipReq(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_slaveModeRequestIbi(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_slaveModeWriteIbiPayload(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_slaveModeReadIbiPayload(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_slaveModeReqFlowControl(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_slaveModeReadApbRo(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_slaveModeReadApbRw(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_slaveModeWriteApbRw(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_slaveModeReadGpo(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_slaveModeReadGpi(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_slaveModeReadMWL(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_slaveModeReadMRL(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_getFifoFillLvl(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_setSdrFifoFlush(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_slaveGetIbiStatus(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_getAsfInfo(I3C_OBJ *obj, void *__unusedPd);
static uint32_t API_TEST_ranges_checkOperationMode(I3C_OBJ *obj, void *__unusedPd);
uint32_t API_TEST_ranges(I3C_OBJ *obj);
static uint32_t API_TEST_getset_BusMode(I3C_OBJ *obj, void *privateData);
uint32_t API_TEST_getset(I3C_OBJ *obj);


static void API_TEST_printTables(void)
{
    uint32_t i;

    printf("TESTING: TESTING TABLE uint8:");
    for (i = 0; i < COUNTOF(API_TEST_table_uint8_t); i++)
    {
        if (i % 8 == 0)
            printf("\nTESTING: ");
        printf("0x%08x ", API_TEST_table_uint8_t[i]);
    }
    printf("\n");
    printf("TESTING: TESTING TABLE uint16:");
    for (i = 0; i < COUNTOF(API_TEST_table_uint16_t); i++)
    {
        if (i % 8 == 0)
            printf("\nTESTING: ");
        printf("0x%08x ", API_TEST_table_uint16_t[i]);
    }
    printf("\n");
    printf("TESTING: TESTING TABLE uint32:");
    for (i = 0; i < COUNTOF(API_TEST_table_uint32_t); i++)
    {
        if (i % 8 == 0)
            printf("\nTESTING: ");
        printf("0x%08x ", API_TEST_table_uint32_t[i]);
    }
    printf("\n");
    printf("TESTING: TESTING TABLE int32:");
    for (i = 0; i < COUNTOF(API_TEST_table_int32_t); i++)
    {
        if (i % 8 == 0)
            printf("\nTESTING: ");
        printf("0x%08x ", API_TEST_table_int32_t[i]);
    }
    printf("\n");
}


/* Test function prototype: */
typedef uint32_t (*API_TEST_internal)(I3C_OBJ *obj, void *privateData);

uint32_t API_TEST_generic(I3C_OBJ *obj, API_TEST_internal func)
{
    void *privateData;
    uint32_t ret;

    if (func == NULL)
    {
        LOG("\t test function pointer is null");
        return FAIL;
    }

    API_TEST_testFunctionCallCounter = 0;

    ret = API_TEST_testSetup(obj, &privateData);
    if (ret)
    {
        LOG("\tAPI_TEST_testSetup returned %i", ret);
        return FAIL;
    }

    ret = func(obj, privateData);

    API_TEST_testTearDown(obj, privateData);
    return ret;
}


void API_TEST_printstruct_I3C_InterruptConfig(const I3C_InterruptConfig *obj, const char *name)
{
    LOG("%s->cmdResponseOverflow = 0x%x", name, obj->cmdResponseOverflow);
    LOG("%s->cmdResponseUnderflow = 0x%x", name, obj->cmdResponseUnderflow);
    LOG("%s->cmdResponseThreshold = 0x%x", name, obj->cmdResponseThreshold);
    LOG("%s->cmdDescriptorOverflow = 0x%x", name, obj->cmdDescriptorOverflow);
    LOG("%s->cmdDescriptorEmpty = 0x%x", name, obj->cmdDescriptorEmpty);
    LOG("%s->cmdDescriptorThreshold = 0x%x", name, obj->cmdDescriptorThreshold);
    LOG("%s->rxDataFifoUnderflow = 0x%x", name, obj->rxDataFifoUnderflow);
    LOG("%s->rxFifoThreshold = 0x%x", name, obj->rxFifoThreshold);
    LOG("%s->ibiResponseOverflow = 0x%x", name, obj->ibiResponseOverflow);
    LOG("%s->ibiResponseUnderflow = 0x%x", name, obj->ibiResponseUnderflow);
    LOG("%s->ibiResponseThreshold = 0x%x", name, obj->ibiResponseThreshold);
    LOG("%s->ibiDataUnderflow = 0x%x", name, obj->ibiDataUnderflow);
    LOG("%s->ibiDataThreshold = 0x%x", name, obj->ibiDataThreshold);
    LOG("%s->txDataFifoOverflow = 0x%x", name, obj->txDataFifoOverflow);
    LOG("%s->txFifoThreshold = 0x%x", name, obj->txFifoThreshold);
    LOG("%s->immComplete = 0x%x", name, obj->immComplete);
    LOG("%s->mastershipDone = 0x%x", name, obj->mastershipDone);
    LOG("%s->halted = 0x%x", name, obj->halted);
}


/**
 * Function to validate struct InterruptConfig
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_InterruptConfig(const I3C_InterruptConfig *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_InterruptConfig
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_InterruptConfig(I3C_InterruptConfig *s1, I3C_InterruptConfig *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("InterruptConfig: one of passed pointers is NULL");
        return FAIL;
    }

    if (s1->cmdResponseOverflow != s2->cmdResponseOverflow)
    {
        LOG("InterruptConfig: member cmdResponseOverflow mismatch. expected %i, got %i", s1->cmdResponseOverflow, s2->cmdResponseOverflow);
        return FAIL;
    }
    if (s1->cmdResponseUnderflow != s2->cmdResponseUnderflow)
    {
        LOG("InterruptConfig: member cmdResponseUnderflow mismatch. expected %i, got %i", s1->cmdResponseUnderflow, s2->cmdResponseUnderflow);
        return FAIL;
    }
    if (s1->cmdResponseThreshold != s2->cmdResponseThreshold)
    {
        LOG("InterruptConfig: member cmdResponseThreshold mismatch. expected %i, got %i", s1->cmdResponseThreshold, s2->cmdResponseThreshold);
        return FAIL;
    }
    if (s1->cmdDescriptorOverflow != s2->cmdDescriptorOverflow)
    {
        LOG("InterruptConfig: member cmdDescriptorOverflow mismatch. expected %i, got %i", s1->cmdDescriptorOverflow, s2->cmdDescriptorOverflow);
        return FAIL;
    }
    if (s1->cmdDescriptorEmpty != s2->cmdDescriptorEmpty)
    {
        LOG("InterruptConfig: member cmdDescriptorEmpty mismatch. expected %i, got %i", s1->cmdDescriptorEmpty, s2->cmdDescriptorEmpty);
        return FAIL;
    }
    if (s1->cmdDescriptorThreshold != s2->cmdDescriptorThreshold)
    {
        LOG("InterruptConfig: member cmdDescriptorThreshold mismatch. expected %i, got %i", s1->cmdDescriptorThreshold, s2->cmdDescriptorThreshold);
        return FAIL;
    }
    if (s1->rxDataFifoUnderflow != s2->rxDataFifoUnderflow)
    {
        LOG("InterruptConfig: member rxDataFifoUnderflow mismatch. expected %i, got %i", s1->rxDataFifoUnderflow, s2->rxDataFifoUnderflow);
        return FAIL;
    }
    if (s1->rxFifoThreshold != s2->rxFifoThreshold)
    {
        LOG("InterruptConfig: member rxFifoThreshold mismatch. expected %i, got %i", s1->rxFifoThreshold, s2->rxFifoThreshold);
        return FAIL;
    }
    if (s1->ibiResponseOverflow != s2->ibiResponseOverflow)
    {
        LOG("InterruptConfig: member ibiResponseOverflow mismatch. expected %i, got %i", s1->ibiResponseOverflow, s2->ibiResponseOverflow);
        return FAIL;
    }
    if (s1->ibiResponseUnderflow != s2->ibiResponseUnderflow)
    {
        LOG("InterruptConfig: member ibiResponseUnderflow mismatch. expected %i, got %i", s1->ibiResponseUnderflow, s2->ibiResponseUnderflow);
        return FAIL;
    }
    if (s1->ibiResponseThreshold != s2->ibiResponseThreshold)
    {
        LOG("InterruptConfig: member ibiResponseThreshold mismatch. expected %i, got %i", s1->ibiResponseThreshold, s2->ibiResponseThreshold);
        return FAIL;
    }
    if (s1->ibiDataUnderflow != s2->ibiDataUnderflow)
    {
        LOG("InterruptConfig: member ibiDataUnderflow mismatch. expected %i, got %i", s1->ibiDataUnderflow, s2->ibiDataUnderflow);
        return FAIL;
    }
    if (s1->ibiDataThreshold != s2->ibiDataThreshold)
    {
        LOG("InterruptConfig: member ibiDataThreshold mismatch. expected %i, got %i", s1->ibiDataThreshold, s2->ibiDataThreshold);
        return FAIL;
    }
    if (s1->txDataFifoOverflow != s2->txDataFifoOverflow)
    {
        LOG("InterruptConfig: member txDataFifoOverflow mismatch. expected %i, got %i", s1->txDataFifoOverflow, s2->txDataFifoOverflow);
        return FAIL;
    }
    if (s1->txFifoThreshold != s2->txFifoThreshold)
    {
        LOG("InterruptConfig: member txFifoThreshold mismatch. expected %i, got %i", s1->txFifoThreshold, s2->txFifoThreshold);
        return FAIL;
    }
    if (s1->immComplete != s2->immComplete)
    {
        LOG("InterruptConfig: member immComplete mismatch. expected %i, got %i", s1->immComplete, s2->immComplete);
        return FAIL;
    }
    if (s1->mastershipDone != s2->mastershipDone)
    {
        LOG("InterruptConfig: member mastershipDone mismatch. expected %i, got %i", s1->mastershipDone, s2->mastershipDone);
        return FAIL;
    }
    if (s1->halted != s2->halted)
    {
        LOG("InterruptConfig: member halted mismatch. expected %i, got %i", s1->halted, s2->halted);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_InterruptConfig
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_InterruptConfig(I3C_InterruptConfig *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        obj->cmdResponseOverflow = API_TEST_table_bool[index%2];
        obj->cmdResponseUnderflow = API_TEST_table_bool[index%2];
        obj->cmdResponseThreshold = API_TEST_table_bool[index%2];
        obj->cmdDescriptorOverflow = API_TEST_table_bool[index%2];
        obj->cmdDescriptorEmpty = API_TEST_table_bool[index%2];
        obj->cmdDescriptorThreshold = API_TEST_table_bool[index%2];
        obj->rxDataFifoUnderflow = API_TEST_table_bool[index%2];
        obj->rxFifoThreshold = API_TEST_table_bool[index%2];
        obj->ibiResponseOverflow = API_TEST_table_bool[index%2];
        obj->ibiResponseUnderflow = API_TEST_table_bool[index%2];
        obj->ibiResponseThreshold = API_TEST_table_bool[index%2];
        obj->ibiDataUnderflow = API_TEST_table_bool[index%2];
        obj->ibiDataThreshold = API_TEST_table_bool[index%2];
        obj->txDataFifoOverflow = API_TEST_table_bool[index%2];
        obj->txFifoThreshold = API_TEST_table_bool[index%2];
        obj->immComplete = API_TEST_table_bool[index%2];
        obj->mastershipDone = API_TEST_table_bool[index%2];
        obj->halted = API_TEST_table_bool[index%2];
        break;
    }
}


/**
 * Function to populate struct I3C_InterruptConfig
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_InterruptConfig(I3C_InterruptConfig *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_InterruptConfig)
        return;

    memset(obj, 0, sizeof(*obj));

    /* Set member cmdResponseOverflow */
    obj->cmdResponseOverflow = (index/divisor) % (1);
    divisor *= 1;
    /* Set member cmdResponseUnderflow */
    obj->cmdResponseUnderflow = (index/divisor) % (1);
    divisor *= 1;
    /* Set member cmdResponseThreshold */
    obj->cmdResponseThreshold = (index/divisor) % (1);
    divisor *= 1;
    /* Set member cmdDescriptorOverflow */
    obj->cmdDescriptorOverflow = (index/divisor) % (1);
    divisor *= 1;
    /* Set member cmdDescriptorEmpty */
    obj->cmdDescriptorEmpty = (index/divisor) % (1);
    divisor *= 1;
    /* Set member cmdDescriptorThreshold */
    obj->cmdDescriptorThreshold = (index/divisor) % (1);
    divisor *= 1;
    /* Set member rxDataFifoUnderflow */
    obj->rxDataFifoUnderflow = (index/divisor) % (1);
    divisor *= 1;
    /* Set member rxFifoThreshold */
    obj->rxFifoThreshold = (index/divisor) % (1);
    divisor *= 1;
    /* Set member ibiResponseOverflow */
    obj->ibiResponseOverflow = (index/divisor) % (1);
    divisor *= 1;
    /* Set member ibiResponseUnderflow */
    obj->ibiResponseUnderflow = (index/divisor) % (1);
    divisor *= 1;
    /* Set member ibiResponseThreshold */
    obj->ibiResponseThreshold = (index/divisor) % (1);
    divisor *= 1;
    /* Set member ibiDataUnderflow */
    obj->ibiDataUnderflow = (index/divisor) % (1);
    divisor *= 1;
    /* Set member ibiDataThreshold */
    obj->ibiDataThreshold = (index/divisor) % (1);
    divisor *= 1;
    /* Set member txDataFifoOverflow */
    obj->txDataFifoOverflow = (index/divisor) % (1);
    divisor *= 1;
    /* Set member txFifoThreshold */
    obj->txFifoThreshold = (index/divisor) % (1);
    divisor *= 1;
    /* Set member immComplete */
    obj->immComplete = (index/divisor) % (1);
    divisor *= 1;
    /* Set member mastershipDone */
    obj->mastershipDone = (index/divisor) % (1);
    divisor *= 1;
    /* Set member halted */
    obj->halted = (index/divisor) % (1);
    divisor *= 1;
}



void API_TEST_printstruct_I3C_SlaveInterruptConfig(const I3C_SlaveInterruptConfig *obj, const char *name)
{
    LOG("%s->sdrWrComplete = 0x%x", name, obj->sdrWrComplete);
    LOG("%s->sdrRdComplete = 0x%x", name, obj->sdrRdComplete);
    LOG("%s->ddrWrComplete = 0x%x", name, obj->ddrWrComplete);
    LOG("%s->ddrRdComplete = 0x%x", name, obj->ddrRdComplete);
    LOG("%s->sdrTxDataFifoOverflow = 0x%x", name, obj->sdrTxDataFifoOverflow);
    LOG("%s->sdrRxDataFifoUnderflow = 0x%x", name, obj->sdrRxDataFifoUnderflow);
    LOG("%s->ddrTxDataFifoOverflow = 0x%x", name, obj->ddrTxDataFifoOverflow);
    LOG("%s->ddrRxDataFifoUnderflow = 0x%x", name, obj->ddrRxDataFifoUnderflow);
    LOG("%s->sdrTxFifoThreshold = 0x%x", name, obj->sdrTxFifoThreshold);
    LOG("%s->sdrRxFifoThreshold = 0x%x", name, obj->sdrRxFifoThreshold);
    LOG("%s->ddrTxFifoThreshold = 0x%x", name, obj->ddrTxFifoThreshold);
    LOG("%s->ddrRxFifoThreshold = 0x%x", name, obj->ddrRxFifoThreshold);
    LOG("%s->masterReadAbort = 0x%x", name, obj->masterReadAbort);
    LOG("%s->ddrFail = 0x%x", name, obj->ddrFail);
    LOG("%s->sdrFail = 0x%x", name, obj->sdrFail);
    LOG("%s->dynamicAddrUpdated = 0x%x", name, obj->dynamicAddrUpdated);
    LOG("%s->ibiDone = 0x%x", name, obj->ibiDone);
    LOG("%s->ibiNack = 0x%x", name, obj->ibiNack);
    LOG("%s->mrDone = 0x%x", name, obj->mrDone);
    LOG("%s->hotJoinDone = 0x%x", name, obj->hotJoinDone);
    LOG("%s->hotJoinNack = 0x%x", name, obj->hotJoinNack);
    LOG("%s->eventUpdate = 0x%x", name, obj->eventUpdate);
    LOG("%s->protocolError = 0x%x", name, obj->protocolError);
    LOG("%s->testMode = 0x%x", name, obj->testMode);
    LOG("%s->defslvs = 0x%x", name, obj->defslvs);
    LOG("%s->ibid_thr = 0x%x", name, obj->ibid_thr);
    LOG("%s->mwl_up = 0x%x", name, obj->mwl_up);
    LOG("%s->mrl_up = 0x%x", name, obj->mrl_up);
    LOG("%s->resetDaa = 0x%x", name, obj->resetDaa);
    LOG("%s->buscon_up = 0x%x", name, obj->buscon_up);
    LOG("%s->flush_done = 0x%x", name, obj->flush_done);
}


/**
 * Function to validate struct SlaveInterruptConfig
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_SlaveInterruptConfig(const I3C_SlaveInterruptConfig *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_SlaveInterruptConfig
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_SlaveInterruptConfig(I3C_SlaveInterruptConfig *s1, I3C_SlaveInterruptConfig *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("SlaveInterruptConfig: one of passed pointers is NULL");
        return FAIL;
    }

    if (s1->sdrWrComplete != s2->sdrWrComplete)
    {
        LOG("SlaveInterruptConfig: member sdrWrComplete mismatch. expected %i, got %i", s1->sdrWrComplete, s2->sdrWrComplete);
        return FAIL;
    }
    if (s1->sdrRdComplete != s2->sdrRdComplete)
    {
        LOG("SlaveInterruptConfig: member sdrRdComplete mismatch. expected %i, got %i", s1->sdrRdComplete, s2->sdrRdComplete);
        return FAIL;
    }
    if (s1->ddrWrComplete != s2->ddrWrComplete)
    {
        LOG("SlaveInterruptConfig: member ddrWrComplete mismatch. expected %i, got %i", s1->ddrWrComplete, s2->ddrWrComplete);
        return FAIL;
    }
    if (s1->ddrRdComplete != s2->ddrRdComplete)
    {
        LOG("SlaveInterruptConfig: member ddrRdComplete mismatch. expected %i, got %i", s1->ddrRdComplete, s2->ddrRdComplete);
        return FAIL;
    }
    if (s1->sdrTxDataFifoOverflow != s2->sdrTxDataFifoOverflow)
    {
        LOG("SlaveInterruptConfig: member sdrTxDataFifoOverflow mismatch. expected %i, got %i", s1->sdrTxDataFifoOverflow, s2->sdrTxDataFifoOverflow);
        return FAIL;
    }
    if (s1->sdrRxDataFifoUnderflow != s2->sdrRxDataFifoUnderflow)
    {
        LOG("SlaveInterruptConfig: member sdrRxDataFifoUnderflow mismatch. expected %i, got %i", s1->sdrRxDataFifoUnderflow, s2->sdrRxDataFifoUnderflow);
        return FAIL;
    }
    if (s1->ddrTxDataFifoOverflow != s2->ddrTxDataFifoOverflow)
    {
        LOG("SlaveInterruptConfig: member ddrTxDataFifoOverflow mismatch. expected %i, got %i", s1->ddrTxDataFifoOverflow, s2->ddrTxDataFifoOverflow);
        return FAIL;
    }
    if (s1->ddrRxDataFifoUnderflow != s2->ddrRxDataFifoUnderflow)
    {
        LOG("SlaveInterruptConfig: member ddrRxDataFifoUnderflow mismatch. expected %i, got %i", s1->ddrRxDataFifoUnderflow, s2->ddrRxDataFifoUnderflow);
        return FAIL;
    }
    if (s1->sdrTxFifoThreshold != s2->sdrTxFifoThreshold)
    {
        LOG("SlaveInterruptConfig: member sdrTxFifoThreshold mismatch. expected %i, got %i", s1->sdrTxFifoThreshold, s2->sdrTxFifoThreshold);
        return FAIL;
    }
    if (s1->sdrRxFifoThreshold != s2->sdrRxFifoThreshold)
    {
        LOG("SlaveInterruptConfig: member sdrRxFifoThreshold mismatch. expected %i, got %i", s1->sdrRxFifoThreshold, s2->sdrRxFifoThreshold);
        return FAIL;
    }
    if (s1->ddrTxFifoThreshold != s2->ddrTxFifoThreshold)
    {
        LOG("SlaveInterruptConfig: member ddrTxFifoThreshold mismatch. expected %i, got %i", s1->ddrTxFifoThreshold, s2->ddrTxFifoThreshold);
        return FAIL;
    }
    if (s1->ddrRxFifoThreshold != s2->ddrRxFifoThreshold)
    {
        LOG("SlaveInterruptConfig: member ddrRxFifoThreshold mismatch. expected %i, got %i", s1->ddrRxFifoThreshold, s2->ddrRxFifoThreshold);
        return FAIL;
    }
    if (s1->masterReadAbort != s2->masterReadAbort)
    {
        LOG("SlaveInterruptConfig: member masterReadAbort mismatch. expected %i, got %i", s1->masterReadAbort, s2->masterReadAbort);
        return FAIL;
    }
    if (s1->ddrFail != s2->ddrFail)
    {
        LOG("SlaveInterruptConfig: member ddrFail mismatch. expected %i, got %i", s1->ddrFail, s2->ddrFail);
        return FAIL;
    }
    if (s1->sdrFail != s2->sdrFail)
    {
        LOG("SlaveInterruptConfig: member sdrFail mismatch. expected %i, got %i", s1->sdrFail, s2->sdrFail);
        return FAIL;
    }
    if (s1->dynamicAddrUpdated != s2->dynamicAddrUpdated)
    {
        LOG("SlaveInterruptConfig: member dynamicAddrUpdated mismatch. expected %i, got %i", s1->dynamicAddrUpdated, s2->dynamicAddrUpdated);
        return FAIL;
    }
    if (s1->ibiDone != s2->ibiDone)
    {
        LOG("SlaveInterruptConfig: member ibiDone mismatch. expected %i, got %i", s1->ibiDone, s2->ibiDone);
        return FAIL;
    }
    if (s1->ibiNack != s2->ibiNack)
    {
        LOG("SlaveInterruptConfig: member ibiNack mismatch. expected %i, got %i", s1->ibiNack, s2->ibiNack);
        return FAIL;
    }
    if (s1->mrDone != s2->mrDone)
    {
        LOG("SlaveInterruptConfig: member mrDone mismatch. expected %i, got %i", s1->mrDone, s2->mrDone);
        return FAIL;
    }
    if (s1->hotJoinDone != s2->hotJoinDone)
    {
        LOG("SlaveInterruptConfig: member hotJoinDone mismatch. expected %i, got %i", s1->hotJoinDone, s2->hotJoinDone);
        return FAIL;
    }
    if (s1->hotJoinNack != s2->hotJoinNack)
    {
        LOG("SlaveInterruptConfig: member hotJoinNack mismatch. expected %i, got %i", s1->hotJoinNack, s2->hotJoinNack);
        return FAIL;
    }
    if (s1->eventUpdate != s2->eventUpdate)
    {
        LOG("SlaveInterruptConfig: member eventUpdate mismatch. expected %i, got %i", s1->eventUpdate, s2->eventUpdate);
        return FAIL;
    }
    if (s1->protocolError != s2->protocolError)
    {
        LOG("SlaveInterruptConfig: member protocolError mismatch. expected %i, got %i", s1->protocolError, s2->protocolError);
        return FAIL;
    }
    if (s1->testMode != s2->testMode)
    {
        LOG("SlaveInterruptConfig: member testMode mismatch. expected %i, got %i", s1->testMode, s2->testMode);
        return FAIL;
    }
    if (s1->defslvs != s2->defslvs)
    {
        LOG("SlaveInterruptConfig: member defslvs mismatch. expected %i, got %i", s1->defslvs, s2->defslvs);
        return FAIL;
    }
    if (s1->ibid_thr != s2->ibid_thr)
    {
        LOG("SlaveInterruptConfig: member ibid_thr mismatch. expected %i, got %i", s1->ibid_thr, s2->ibid_thr);
        return FAIL;
    }
    if (s1->mwl_up != s2->mwl_up)
    {
        LOG("SlaveInterruptConfig: member mwl_up mismatch. expected %i, got %i", s1->mwl_up, s2->mwl_up);
        return FAIL;
    }
    if (s1->mrl_up != s2->mrl_up)
    {
        LOG("SlaveInterruptConfig: member mrl_up mismatch. expected %i, got %i", s1->mrl_up, s2->mrl_up);
        return FAIL;
    }
    if (s1->resetDaa != s2->resetDaa)
    {
        LOG("SlaveInterruptConfig: member resetDaa mismatch. expected %i, got %i", s1->resetDaa, s2->resetDaa);
        return FAIL;
    }
    if (s1->buscon_up != s2->buscon_up)
    {
        LOG("SlaveInterruptConfig: member buscon_up mismatch. expected %i, got %i", s1->buscon_up, s2->buscon_up);
        return FAIL;
    }
    if (s1->flush_done != s2->flush_done)
    {
        LOG("SlaveInterruptConfig: member flush_done mismatch. expected %i, got %i", s1->flush_done, s2->flush_done);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_SlaveInterruptConfig
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_SlaveInterruptConfig(I3C_SlaveInterruptConfig *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        obj->sdrWrComplete = API_TEST_table_bool[index%2];
        obj->sdrRdComplete = API_TEST_table_bool[index%2];
        obj->ddrWrComplete = API_TEST_table_bool[index%2];
        obj->ddrRdComplete = API_TEST_table_bool[index%2];
        obj->sdrTxDataFifoOverflow = API_TEST_table_bool[index%2];
        obj->sdrRxDataFifoUnderflow = API_TEST_table_bool[index%2];
        obj->ddrTxDataFifoOverflow = API_TEST_table_bool[index%2];
        obj->ddrRxDataFifoUnderflow = API_TEST_table_bool[index%2];
        obj->sdrTxFifoThreshold = API_TEST_table_bool[index%2];
        obj->sdrRxFifoThreshold = API_TEST_table_bool[index%2];
        obj->ddrTxFifoThreshold = API_TEST_table_bool[index%2];
        obj->ddrRxFifoThreshold = API_TEST_table_bool[index%2];
        obj->masterReadAbort = API_TEST_table_bool[index%2];
        obj->ddrFail = API_TEST_table_bool[index%2];
        obj->sdrFail = API_TEST_table_bool[index%2];
        obj->dynamicAddrUpdated = API_TEST_table_bool[index%2];
        obj->ibiDone = API_TEST_table_bool[index%2];
        obj->ibiNack = API_TEST_table_bool[index%2];
        obj->mrDone = API_TEST_table_bool[index%2];
        obj->hotJoinDone = API_TEST_table_bool[index%2];
        obj->hotJoinNack = API_TEST_table_bool[index%2];
        obj->eventUpdate = API_TEST_table_bool[index%2];
        obj->protocolError = API_TEST_table_bool[index%2];
        obj->testMode = API_TEST_table_bool[index%2];
        obj->defslvs = API_TEST_table_bool[index%2];
        obj->ibid_thr = API_TEST_table_bool[index%2];
        obj->mwl_up = API_TEST_table_bool[index%2];
        obj->mrl_up = API_TEST_table_bool[index%2];
        obj->resetDaa = API_TEST_table_bool[index%2];
        obj->buscon_up = API_TEST_table_bool[index%2];
        obj->flush_done = API_TEST_table_bool[index%2];
        break;
    }
}


/**
 * Function to populate struct I3C_SlaveInterruptConfig
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_SlaveInterruptConfig(I3C_SlaveInterruptConfig *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_SlaveInterruptConfig)
        return;

    memset(obj, 0, sizeof(*obj));

    /* Set member sdrWrComplete */
    obj->sdrWrComplete = (index/divisor) % (1);
    divisor *= 1;
    /* Set member sdrRdComplete */
    obj->sdrRdComplete = (index/divisor) % (1);
    divisor *= 1;
    /* Set member ddrWrComplete */
    obj->ddrWrComplete = (index/divisor) % (1);
    divisor *= 1;
    /* Set member ddrRdComplete */
    obj->ddrRdComplete = (index/divisor) % (1);
    divisor *= 1;
    /* Set member sdrTxDataFifoOverflow */
    obj->sdrTxDataFifoOverflow = (index/divisor) % (1);
    divisor *= 1;
    /* Set member sdrRxDataFifoUnderflow */
    obj->sdrRxDataFifoUnderflow = (index/divisor) % (1);
    divisor *= 1;
    /* Set member ddrTxDataFifoOverflow */
    obj->ddrTxDataFifoOverflow = (index/divisor) % (1);
    divisor *= 1;
    /* Set member ddrRxDataFifoUnderflow */
    obj->ddrRxDataFifoUnderflow = (index/divisor) % (1);
    divisor *= 1;
    /* Set member sdrTxFifoThreshold */
    obj->sdrTxFifoThreshold = (index/divisor) % (1);
    divisor *= 1;
    /* Set member sdrRxFifoThreshold */
    obj->sdrRxFifoThreshold = (index/divisor) % (1);
    divisor *= 1;
    /* Set member ddrTxFifoThreshold */
    obj->ddrTxFifoThreshold = (index/divisor) % (1);
    divisor *= 1;
    /* Set member ddrRxFifoThreshold */
    obj->ddrRxFifoThreshold = (index/divisor) % (1);
    divisor *= 1;
    /* Set member masterReadAbort */
    obj->masterReadAbort = (index/divisor) % (1);
    divisor *= 1;
    /* Set member ddrFail */
    obj->ddrFail = (index/divisor) % (1);
    divisor *= 1;
    /* Set member sdrFail */
    obj->sdrFail = (index/divisor) % (1);
    divisor *= 1;
    /* Set member dynamicAddrUpdated */
    obj->dynamicAddrUpdated = (index/divisor) % (1);
    divisor *= 1;
    /* Set member ibiDone */
    obj->ibiDone = (index/divisor) % (1);
    divisor *= 1;
    /* Set member ibiNack */
    obj->ibiNack = (index/divisor) % (1);
    divisor *= 1;
    /* Set member mrDone */
    obj->mrDone = (index/divisor) % (1);
    divisor *= 1;
    /* Set member hotJoinDone */
    obj->hotJoinDone = (index/divisor) % (1);
    divisor *= 1;
    /* Set member hotJoinNack */
    obj->hotJoinNack = (index/divisor) % (1);
    divisor *= 1;
    /* Set member eventUpdate */
    obj->eventUpdate = (index/divisor) % (1);
    divisor *= 1;
    /* Set member protocolError */
    obj->protocolError = (index/divisor) % (1);
    divisor *= 1;
    /* Set member testMode */
    obj->testMode = (index/divisor) % (1);
    divisor *= 1;
    /* Set member defslvs */
    obj->defslvs = (index/divisor) % (1);
    divisor *= 1;
    /* Set member ibid_thr */
    obj->ibid_thr = (index/divisor) % (1);
    divisor *= 1;
    /* Set member mwl_up */
    obj->mwl_up = (index/divisor) % (1);
    divisor *= 1;
    /* Set member mrl_up */
    obj->mrl_up = (index/divisor) % (1);
    divisor *= 1;
    /* Set member resetDaa */
    obj->resetDaa = (index/divisor) % (1);
    divisor *= 1;
    /* Set member buscon_up */
    obj->buscon_up = (index/divisor) % (1);
    divisor *= 1;
    /* Set member flush_done */
    obj->flush_done = (index/divisor) % (1);
    divisor *= 1;
}



void API_TEST_printstruct_I3C_ThresholdConfig(const I3C_ThresholdConfig *obj, const char *name)
{
    LOG("%s->txFifoThreshold = 0x%04x", name, obj->txFifoThreshold);
    LOG("%s->rxFifoThreshold = 0x%04x", name, obj->rxFifoThreshold);
    LOG("%s->ibirFifoThreshold = 0x%02x", name, obj->ibirFifoThreshold);
    LOG("%s->cmdrFifoThreshold = 0x%02x", name, obj->cmdrFifoThreshold);
}


/**
 * Function to validate struct ThresholdConfig
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_ThresholdConfig(const I3C_ThresholdConfig *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_ThresholdConfig
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_ThresholdConfig(I3C_ThresholdConfig *s1, I3C_ThresholdConfig *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("ThresholdConfig: one of passed pointers is NULL");
        return FAIL;
    }

    if (s1->txFifoThreshold != s2->txFifoThreshold)
    {
        LOG("ThresholdConfig: member txFifoThreshold mismatch. expected %i, got %i", s1->txFifoThreshold, s2->txFifoThreshold);
        return FAIL;
    }
    if (s1->rxFifoThreshold != s2->rxFifoThreshold)
    {
        LOG("ThresholdConfig: member rxFifoThreshold mismatch. expected %i, got %i", s1->rxFifoThreshold, s2->rxFifoThreshold);
        return FAIL;
    }
    if (s1->ibirFifoThreshold != s2->ibirFifoThreshold)
    {
        LOG("ThresholdConfig: member ibirFifoThreshold mismatch. expected %i, got %i", s1->ibirFifoThreshold, s2->ibirFifoThreshold);
        return FAIL;
    }
    if (s1->cmdrFifoThreshold != s2->cmdrFifoThreshold)
    {
        LOG("ThresholdConfig: member cmdrFifoThreshold mismatch. expected %i, got %i", s1->cmdrFifoThreshold, s2->cmdrFifoThreshold);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_ThresholdConfig
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_ThresholdConfig(I3C_ThresholdConfig *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        obj->txFifoThreshold = API_TEST_table_uint16_t[(index+0)%48];
        obj->rxFifoThreshold = API_TEST_table_uint16_t[(index+0)%48];
        obj->ibirFifoThreshold = API_TEST_table_uint8_t[(index+0)%24];
        obj->cmdrFifoThreshold = API_TEST_table_uint8_t[(index+0)%24];
        break;
    }
}


/**
 * Function to populate struct I3C_ThresholdConfig
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_ThresholdConfig(I3C_ThresholdConfig *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_ThresholdConfig)
        return;

    memset(obj, 0, sizeof(*obj));

    /* Set member txFifoThreshold */
    obj->txFifoThreshold = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member rxFifoThreshold */
    obj->rxFifoThreshold = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member ibirFifoThreshold */
    obj->ibirFifoThreshold = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member cmdrFifoThreshold */
    obj->cmdrFifoThreshold = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
}



void API_TEST_printstruct_I3C_Config(const I3C_Config *obj, const char *name)
{
    LOG("%s->regsBase = %p", name, obj->regsBase);
    LOG("%s->sysClk = 0x%08x", name, obj->sysClk);
    LOG("%s->i2cFreq = 0x%08x", name, obj->i2cFreq);
    LOG("%s->sdrFreq = 0x%08x", name, obj->sdrFreq);
    LOG("%s->sclLowPeriod = 0x%08x", name, obj->sclLowPeriod);
    LOG("%s->maxSclFreq = 0x%08x", name, obj->maxSclFreq);
    LOG("%s->devs = %p", name, obj->devs);
    LOG("%s->numDevs = 0x%02x", name, obj->numDevs);
    LOG("%s->ibiSirCfgs = %p", name, obj->ibiSirCfgs);
    LOG("%s->numSirCfgs = 0x%02x", name, obj->numSirCfgs);
    LOG("%s->cmdFifoSize = 0x%04x", name, obj->cmdFifoSize);
    LOG("%s->cmdFifoThreshold = 0x%04x", name, obj->cmdFifoThreshold);
    LOG("%s->txFifoSize = 0x%04x", name, obj->txFifoSize);
    LOG("%s->rxFifoSize = 0x%04x", name, obj->rxFifoSize);
    LOG("%s->thresholdConfig = %u", name, obj->thresholdConfig);
    LOG("%s->interruptConfig = %u", name, obj->interruptConfig);
    LOG("%s->slaveInterruptConfig = %u", name, obj->slaveInterruptConfig);
}


/**
 * Function to validate struct Config
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_Config(const I3C_Config *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        if (API_TEST_verify_I3C_ThresholdConfig(&obj->thresholdConfig) == CDN_EINVAL)
            ret = CDN_EINVAL;

        if (API_TEST_verify_I3C_InterruptConfig(&obj->interruptConfig) == CDN_EINVAL)
            ret = CDN_EINVAL;

        if (API_TEST_verify_I3C_SlaveInterruptConfig(&obj->slaveInterruptConfig) == CDN_EINVAL)
            ret = CDN_EINVAL;

    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_Config
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_Config(I3C_Config *s1, I3C_Config *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("Config: one of passed pointers is NULL");
        return FAIL;
    }

    if (s1->regsBase != s2->regsBase)
    {
        LOG("Config: member regsBase mismatch. expected %i, got %i", s1->regsBase, s2->regsBase);
        return FAIL;
    }
    if (s1->sysClk != s2->sysClk)
    {
        LOG("Config: member sysClk mismatch. expected %i, got %i", s1->sysClk, s2->sysClk);
        return FAIL;
    }
    if (s1->i2cFreq != s2->i2cFreq)
    {
        LOG("Config: member i2cFreq mismatch. expected %i, got %i", s1->i2cFreq, s2->i2cFreq);
        return FAIL;
    }
    if (s1->sdrFreq != s2->sdrFreq)
    {
        LOG("Config: member sdrFreq mismatch. expected %i, got %i", s1->sdrFreq, s2->sdrFreq);
        return FAIL;
    }
    if (s1->sclLowPeriod != s2->sclLowPeriod)
    {
        LOG("Config: member sclLowPeriod mismatch. expected %i, got %i", s1->sclLowPeriod, s2->sclLowPeriod);
        return FAIL;
    }
    if (s1->maxSclFreq != s2->maxSclFreq)
    {
        LOG("Config: member maxSclFreq mismatch. expected %i, got %i", s1->maxSclFreq, s2->maxSclFreq);
        return FAIL;
    }
    if (API_TEST_comparestruct_I3C_DeviceDescriptor(s1->devs, s2->devs, nolog))
    {
        LOG("Config: member devs mismatch. expected %i, got %i", s1->devs, s2->devs);
        return FAIL;
    }
    if (s1->numDevs != s2->numDevs)
    {
        LOG("Config: member numDevs mismatch. expected %i, got %i", s1->numDevs, s2->numDevs);
        return FAIL;
    }
    if (API_TEST_comparestruct_I3C_IbiSirConfiguration(s1->ibiSirCfgs, s2->ibiSirCfgs, nolog))
    {
        LOG("Config: member ibiSirCfgs mismatch. expected %i, got %i", s1->ibiSirCfgs, s2->ibiSirCfgs);
        return FAIL;
    }
    if (s1->numSirCfgs != s2->numSirCfgs)
    {
        LOG("Config: member numSirCfgs mismatch. expected %i, got %i", s1->numSirCfgs, s2->numSirCfgs);
        return FAIL;
    }
    if (s1->cmdFifoSize != s2->cmdFifoSize)
    {
        LOG("Config: member cmdFifoSize mismatch. expected %i, got %i", s1->cmdFifoSize, s2->cmdFifoSize);
        return FAIL;
    }
    if (s1->cmdFifoThreshold != s2->cmdFifoThreshold)
    {
        LOG("Config: member cmdFifoThreshold mismatch. expected %i, got %i", s1->cmdFifoThreshold, s2->cmdFifoThreshold);
        return FAIL;
    }
    if (s1->txFifoSize != s2->txFifoSize)
    {
        LOG("Config: member txFifoSize mismatch. expected %i, got %i", s1->txFifoSize, s2->txFifoSize);
        return FAIL;
    }
    if (s1->rxFifoSize != s2->rxFifoSize)
    {
        LOG("Config: member rxFifoSize mismatch. expected %i, got %i", s1->rxFifoSize, s2->rxFifoSize);
        return FAIL;
    }
    if (API_TEST_comparestruct_I3C_ThresholdConfig(&s1->thresholdConfig, &s2->thresholdConfig, nolog))
    {
        LOG("Config: member thresholdConfig mismatch. expected %i, got %i", s1->thresholdConfig, s2->thresholdConfig);
        return FAIL;
    }
    if (API_TEST_comparestruct_I3C_InterruptConfig(&s1->interruptConfig, &s2->interruptConfig, nolog))
    {
        LOG("Config: member interruptConfig mismatch. expected %i, got %i", s1->interruptConfig, s2->interruptConfig);
        return FAIL;
    }
    if (API_TEST_comparestruct_I3C_SlaveInterruptConfig(&s1->slaveInterruptConfig, &s2->slaveInterruptConfig, nolog))
    {
        LOG("Config: member slaveInterruptConfig mismatch. expected %i, got %i", s1->slaveInterruptConfig, s2->slaveInterruptConfig);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_Config
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_Config(I3C_Config *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        obj->regsBase = NULL;
        obj->devs = NULL;
        obj->ibiSirCfgs = NULL;
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        obj->regsBase = NULL;
        obj->sysClk = API_TEST_table_uint32_t[(index+0)%96];
        obj->i2cFreq = API_TEST_table_uint32_t[(index+0)%96];
        obj->sdrFreq = API_TEST_table_uint32_t[(index+0)%96];
        obj->sclLowPeriod = API_TEST_table_uint32_t[(index+0)%96];
        obj->maxSclFreq = API_TEST_table_uint32_t[(index+0)%96];
        obj->devs = NULL;
        obj->numDevs = API_TEST_table_uint8_t[(index+0)%24];
        obj->ibiSirCfgs = NULL;
        obj->numSirCfgs = API_TEST_table_uint8_t[(index+0)%24];
        obj->cmdFifoSize = API_TEST_table_uint16_t[(index+0)%48];
        obj->cmdFifoThreshold = API_TEST_table_uint16_t[(index+0)%48];
        obj->txFifoSize = API_TEST_table_uint16_t[(index+0)%48];
        obj->rxFifoSize = API_TEST_table_uint16_t[(index+0)%48];
        API_TEST_fill_I3C_ThresholdConfig(&(obj->thresholdConfig), index % 96);
        API_TEST_fill_I3C_InterruptConfig(&(obj->interruptConfig), index % 96);
        API_TEST_fill_I3C_SlaveInterruptConfig(&(obj->slaveInterruptConfig), index % 96);
        break;
    }
}


/**
 * Function to populate struct I3C_Config
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_Config(I3C_Config *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_Config)
        return;

    memset(obj, 0, sizeof(*obj));

    /* Set member sysClk */
    obj->sysClk = (index/divisor) % (UINT32_MAX);
    divisor *= UINT32_MAX;
    /* Set member i2cFreq */
    obj->i2cFreq = (index/divisor) % (UINT32_MAX);
    divisor *= UINT32_MAX;
    /* Set member sdrFreq */
    obj->sdrFreq = (index/divisor) % (UINT32_MAX);
    divisor *= UINT32_MAX;
    /* Set member sclLowPeriod */
    obj->sclLowPeriod = (index/divisor) % (UINT32_MAX);
    divisor *= UINT32_MAX;
    /* Set member maxSclFreq */
    obj->maxSclFreq = (index/divisor) % (UINT32_MAX);
    divisor *= UINT32_MAX;
    /* Set member numDevs */
    obj->numDevs = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member numSirCfgs */
    obj->numSirCfgs = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member cmdFifoSize */
    obj->cmdFifoSize = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member cmdFifoThreshold */
    obj->cmdFifoThreshold = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member txFifoSize */
    obj->txFifoSize = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member rxFifoSize */
    obj->rxFifoSize = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member thresholdConfig */
    API_TEST_fillvalid_I3C_ThresholdConfig(&obj->thresholdConfig, (index % API_TEST_structTestLen_I3C_ThresholdConfig));
    divisor *= API_TEST_structTestLen_I3C_ThresholdConfig;
    /* Set member interruptConfig */
    API_TEST_fillvalid_I3C_InterruptConfig(&obj->interruptConfig, (index % API_TEST_structTestLen_I3C_InterruptConfig));
    divisor *= API_TEST_structTestLen_I3C_InterruptConfig;
    /* Set member slaveInterruptConfig */
    API_TEST_fillvalid_I3C_SlaveInterruptConfig(&obj->slaveInterruptConfig, (index % API_TEST_structTestLen_I3C_SlaveInterruptConfig));
    divisor *= API_TEST_structTestLen_I3C_SlaveInterruptConfig;
}



void API_TEST_printstruct_I3C_SysReq(const I3C_SysReq *obj, const char *name)
{
    LOG("%s->memReq = 0x%08x", name, obj->memReq);
}


/**
 * Function to validate struct SysReq
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_SysReq(const I3C_SysReq *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_SysReq
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_SysReq(I3C_SysReq *s1, I3C_SysReq *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("SysReq: one of passed pointers is NULL");
        return FAIL;
    }

    if (s1->memReq != s2->memReq)
    {
        LOG("SysReq: member memReq mismatch. expected %i, got %i", s1->memReq, s2->memReq);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_SysReq
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_SysReq(I3C_SysReq *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        obj->memReq = API_TEST_table_uint32_t[(index+0)%96];
        break;
    }
}


/**
 * Function to populate struct I3C_SysReq
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_SysReq(I3C_SysReq *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_SysReq)
        return;

    memset(obj, 0, sizeof(*obj));

    /* Set member memReq */
    obj->memReq = (index/divisor) % (UINT32_MAX);
    divisor *= UINT32_MAX;
}



void API_TEST_printstruct_I3C_Callbacks(const I3C_Callbacks *obj, const char *name)
{
    LOG("%s->cmdResponseOverflow = %u", name, obj->cmdResponseOverflow);
    LOG("%s->cmdResponseUnderflow = %u", name, obj->cmdResponseUnderflow);
    LOG("%s->cmdResponseThreshold = %u", name, obj->cmdResponseThreshold);
    LOG("%s->cmdDescriptorOverflow = %u", name, obj->cmdDescriptorOverflow);
    LOG("%s->cmdDescriptorEmpty = %u", name, obj->cmdDescriptorEmpty);
    LOG("%s->cmdDescriptorThreshold = %u", name, obj->cmdDescriptorThreshold);
    LOG("%s->rxDataFifoUnderflow = %u", name, obj->rxDataFifoUnderflow);
    LOG("%s->rxFifoThreshold = %u", name, obj->rxFifoThreshold);
    LOG("%s->ibiResponseOverflow = %u", name, obj->ibiResponseOverflow);
    LOG("%s->ibiResponseUnderflow = %u", name, obj->ibiResponseUnderflow);
    LOG("%s->ibiResponseThreshold = %u", name, obj->ibiResponseThreshold);
    LOG("%s->ibiDataUnderflow = %u", name, obj->ibiDataUnderflow);
    LOG("%s->ibiDataThreshold = %u", name, obj->ibiDataThreshold);
    LOG("%s->txFifoThreshold = %u", name, obj->txFifoThreshold);
    LOG("%s->txDataFifoOverflow = %u", name, obj->txDataFifoOverflow);
    LOG("%s->immComplete = %u", name, obj->immComplete);
    LOG("%s->mastershipDone = %u", name, obj->mastershipDone);
    LOG("%s->halted = %u", name, obj->halted);
    LOG("%s->commandBufferEmpty = %u", name, obj->commandBufferEmpty);
    LOG("%s->commandComplete = %u", name, obj->commandComplete);
    LOG("%s->daaComplete = %u", name, obj->daaComplete);
    LOG("%s->mastershipRequest = %u", name, obj->mastershipRequest);
    LOG("%s->hotjoin = %u", name, obj->hotjoin);
    LOG("%s->inbandInterrupt = %u", name, obj->inbandInterrupt);
    LOG("%s->slaveSdrWrComplete = %u", name, obj->slaveSdrWrComplete);
    LOG("%s->slaveSdrRdComplete = %u", name, obj->slaveSdrRdComplete);
    LOG("%s->slaveDdrWrComplete = %u", name, obj->slaveDdrWrComplete);
    LOG("%s->slaveDdrRdComplete = %u", name, obj->slaveDdrRdComplete);
    LOG("%s->slaveIBIDone = %u", name, obj->slaveIBIDone);
    LOG("%s->slaveSdrError = %u", name, obj->slaveSdrError);
    LOG("%s->testMode = %u", name, obj->testMode);
    LOG("%s->slaveMwlChange = %u", name, obj->slaveMwlChange);
    LOG("%s->slaveMrlChange = %u", name, obj->slaveMrlChange);
    LOG("%s->slaveResetDaa = %u", name, obj->slaveResetDaa);
    LOG("%s->slaveBusconUp = %u", name, obj->slaveBusconUp);
    LOG("%s->slaveFlushDone = %u", name, obj->slaveFlushDone);
}


/**
 * Function to validate struct Callbacks
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_Callbacks(const I3C_Callbacks *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_Callbacks
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_Callbacks(I3C_Callbacks *s1, I3C_Callbacks *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("Callbacks: one of passed pointers is NULL");
        return FAIL;
    }

    if (s1->cmdResponseOverflow != s2->cmdResponseOverflow)
    {
        LOG("Callbacks: member cmdResponseOverflow mismatch. expected %i, got %i", s1->cmdResponseOverflow, s2->cmdResponseOverflow);
        return FAIL;
    }
    if (s1->cmdResponseUnderflow != s2->cmdResponseUnderflow)
    {
        LOG("Callbacks: member cmdResponseUnderflow mismatch. expected %i, got %i", s1->cmdResponseUnderflow, s2->cmdResponseUnderflow);
        return FAIL;
    }
    if (s1->cmdResponseThreshold != s2->cmdResponseThreshold)
    {
        LOG("Callbacks: member cmdResponseThreshold mismatch. expected %i, got %i", s1->cmdResponseThreshold, s2->cmdResponseThreshold);
        return FAIL;
    }
    if (s1->cmdDescriptorOverflow != s2->cmdDescriptorOverflow)
    {
        LOG("Callbacks: member cmdDescriptorOverflow mismatch. expected %i, got %i", s1->cmdDescriptorOverflow, s2->cmdDescriptorOverflow);
        return FAIL;
    }
    if (s1->cmdDescriptorEmpty != s2->cmdDescriptorEmpty)
    {
        LOG("Callbacks: member cmdDescriptorEmpty mismatch. expected %i, got %i", s1->cmdDescriptorEmpty, s2->cmdDescriptorEmpty);
        return FAIL;
    }
    if (s1->cmdDescriptorThreshold != s2->cmdDescriptorThreshold)
    {
        LOG("Callbacks: member cmdDescriptorThreshold mismatch. expected %i, got %i", s1->cmdDescriptorThreshold, s2->cmdDescriptorThreshold);
        return FAIL;
    }
    if (s1->rxDataFifoUnderflow != s2->rxDataFifoUnderflow)
    {
        LOG("Callbacks: member rxDataFifoUnderflow mismatch. expected %i, got %i", s1->rxDataFifoUnderflow, s2->rxDataFifoUnderflow);
        return FAIL;
    }
    if (s1->rxFifoThreshold != s2->rxFifoThreshold)
    {
        LOG("Callbacks: member rxFifoThreshold mismatch. expected %i, got %i", s1->rxFifoThreshold, s2->rxFifoThreshold);
        return FAIL;
    }
    if (s1->ibiResponseOverflow != s2->ibiResponseOverflow)
    {
        LOG("Callbacks: member ibiResponseOverflow mismatch. expected %i, got %i", s1->ibiResponseOverflow, s2->ibiResponseOverflow);
        return FAIL;
    }
    if (s1->ibiResponseUnderflow != s2->ibiResponseUnderflow)
    {
        LOG("Callbacks: member ibiResponseUnderflow mismatch. expected %i, got %i", s1->ibiResponseUnderflow, s2->ibiResponseUnderflow);
        return FAIL;
    }
    if (s1->ibiResponseThreshold != s2->ibiResponseThreshold)
    {
        LOG("Callbacks: member ibiResponseThreshold mismatch. expected %i, got %i", s1->ibiResponseThreshold, s2->ibiResponseThreshold);
        return FAIL;
    }
    if (s1->ibiDataUnderflow != s2->ibiDataUnderflow)
    {
        LOG("Callbacks: member ibiDataUnderflow mismatch. expected %i, got %i", s1->ibiDataUnderflow, s2->ibiDataUnderflow);
        return FAIL;
    }
    if (s1->ibiDataThreshold != s2->ibiDataThreshold)
    {
        LOG("Callbacks: member ibiDataThreshold mismatch. expected %i, got %i", s1->ibiDataThreshold, s2->ibiDataThreshold);
        return FAIL;
    }
    if (s1->txFifoThreshold != s2->txFifoThreshold)
    {
        LOG("Callbacks: member txFifoThreshold mismatch. expected %i, got %i", s1->txFifoThreshold, s2->txFifoThreshold);
        return FAIL;
    }
    if (s1->txDataFifoOverflow != s2->txDataFifoOverflow)
    {
        LOG("Callbacks: member txDataFifoOverflow mismatch. expected %i, got %i", s1->txDataFifoOverflow, s2->txDataFifoOverflow);
        return FAIL;
    }
    if (s1->immComplete != s2->immComplete)
    {
        LOG("Callbacks: member immComplete mismatch. expected %i, got %i", s1->immComplete, s2->immComplete);
        return FAIL;
    }
    if (s1->mastershipDone != s2->mastershipDone)
    {
        LOG("Callbacks: member mastershipDone mismatch. expected %i, got %i", s1->mastershipDone, s2->mastershipDone);
        return FAIL;
    }
    if (s1->halted != s2->halted)
    {
        LOG("Callbacks: member halted mismatch. expected %i, got %i", s1->halted, s2->halted);
        return FAIL;
    }
    if (s1->commandBufferEmpty != s2->commandBufferEmpty)
    {
        LOG("Callbacks: member commandBufferEmpty mismatch. expected %i, got %i", s1->commandBufferEmpty, s2->commandBufferEmpty);
        return FAIL;
    }
    if (s1->commandComplete != s2->commandComplete)
    {
        LOG("Callbacks: member commandComplete mismatch. expected %i, got %i", s1->commandComplete, s2->commandComplete);
        return FAIL;
    }
    if (s1->daaComplete != s2->daaComplete)
    {
        LOG("Callbacks: member daaComplete mismatch. expected %i, got %i", s1->daaComplete, s2->daaComplete);
        return FAIL;
    }
    if (s1->mastershipRequest != s2->mastershipRequest)
    {
        LOG("Callbacks: member mastershipRequest mismatch. expected %i, got %i", s1->mastershipRequest, s2->mastershipRequest);
        return FAIL;
    }
    if (s1->hotjoin != s2->hotjoin)
    {
        LOG("Callbacks: member hotjoin mismatch. expected %i, got %i", s1->hotjoin, s2->hotjoin);
        return FAIL;
    }
    if (s1->inbandInterrupt != s2->inbandInterrupt)
    {
        LOG("Callbacks: member inbandInterrupt mismatch. expected %i, got %i", s1->inbandInterrupt, s2->inbandInterrupt);
        return FAIL;
    }
    if (s1->slaveSdrWrComplete != s2->slaveSdrWrComplete)
    {
        LOG("Callbacks: member slaveSdrWrComplete mismatch. expected %i, got %i", s1->slaveSdrWrComplete, s2->slaveSdrWrComplete);
        return FAIL;
    }
    if (s1->slaveSdrRdComplete != s2->slaveSdrRdComplete)
    {
        LOG("Callbacks: member slaveSdrRdComplete mismatch. expected %i, got %i", s1->slaveSdrRdComplete, s2->slaveSdrRdComplete);
        return FAIL;
    }
    if (s1->slaveDdrWrComplete != s2->slaveDdrWrComplete)
    {
        LOG("Callbacks: member slaveDdrWrComplete mismatch. expected %i, got %i", s1->slaveDdrWrComplete, s2->slaveDdrWrComplete);
        return FAIL;
    }
    if (s1->slaveDdrRdComplete != s2->slaveDdrRdComplete)
    {
        LOG("Callbacks: member slaveDdrRdComplete mismatch. expected %i, got %i", s1->slaveDdrRdComplete, s2->slaveDdrRdComplete);
        return FAIL;
    }
    if (s1->slaveIBIDone != s2->slaveIBIDone)
    {
        LOG("Callbacks: member slaveIBIDone mismatch. expected %i, got %i", s1->slaveIBIDone, s2->slaveIBIDone);
        return FAIL;
    }
    if (s1->slaveSdrError != s2->slaveSdrError)
    {
        LOG("Callbacks: member slaveSdrError mismatch. expected %i, got %i", s1->slaveSdrError, s2->slaveSdrError);
        return FAIL;
    }
    if (s1->testMode != s2->testMode)
    {
        LOG("Callbacks: member testMode mismatch. expected %i, got %i", s1->testMode, s2->testMode);
        return FAIL;
    }
    if (s1->slaveMwlChange != s2->slaveMwlChange)
    {
        LOG("Callbacks: member slaveMwlChange mismatch. expected %i, got %i", s1->slaveMwlChange, s2->slaveMwlChange);
        return FAIL;
    }
    if (s1->slaveMrlChange != s2->slaveMrlChange)
    {
        LOG("Callbacks: member slaveMrlChange mismatch. expected %i, got %i", s1->slaveMrlChange, s2->slaveMrlChange);
        return FAIL;
    }
    if (s1->slaveResetDaa != s2->slaveResetDaa)
    {
        LOG("Callbacks: member slaveResetDaa mismatch. expected %i, got %i", s1->slaveResetDaa, s2->slaveResetDaa);
        return FAIL;
    }
    if (s1->slaveBusconUp != s2->slaveBusconUp)
    {
        LOG("Callbacks: member slaveBusconUp mismatch. expected %i, got %i", s1->slaveBusconUp, s2->slaveBusconUp);
        return FAIL;
    }
    if (s1->slaveFlushDone != s2->slaveFlushDone)
    {
        LOG("Callbacks: member slaveFlushDone mismatch. expected %i, got %i", s1->slaveFlushDone, s2->slaveFlushDone);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_Callbacks
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_Callbacks(I3C_Callbacks *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        obj->cmdResponseOverflow = 0;
        obj->cmdResponseUnderflow = 0;
        obj->cmdResponseThreshold = 0;
        obj->cmdDescriptorOverflow = 0;
        obj->cmdDescriptorEmpty = 0;
        obj->cmdDescriptorThreshold = 0;
        obj->rxDataFifoUnderflow = 0;
        obj->rxFifoThreshold = 0;
        obj->ibiResponseOverflow = 0;
        obj->ibiResponseUnderflow = 0;
        obj->ibiResponseThreshold = 0;
        obj->ibiDataUnderflow = 0;
        obj->ibiDataThreshold = 0;
        obj->txFifoThreshold = 0;
        obj->txDataFifoOverflow = 0;
        obj->immComplete = 0;
        obj->mastershipDone = 0;
        obj->halted = 0;
        obj->commandBufferEmpty = 0;
        obj->commandComplete = 0;
        obj->daaComplete = 0;
        obj->mastershipRequest = 0;
        obj->hotjoin = 0;
        obj->inbandInterrupt = 0;
        obj->slaveSdrWrComplete = 0;
        obj->slaveSdrRdComplete = 0;
        obj->slaveDdrWrComplete = 0;
        obj->slaveDdrRdComplete = 0;
        obj->slaveIBIDone = 0;
        obj->slaveSdrError = 0;
        obj->testMode = 0;
        obj->slaveMwlChange = 0;
        obj->slaveMrlChange = 0;
        obj->slaveResetDaa = 0;
        obj->slaveBusconUp = 0;
        obj->slaveFlushDone = 0;
        break;
    }
}


/**
 * Function to populate struct I3C_Callbacks
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_Callbacks(I3C_Callbacks *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_Callbacks)
        return;

    memset(obj, 0, sizeof(*obj));

}



void API_TEST_printstruct_I3C_DeviceDescriptor(const I3C_DeviceDescriptor *obj, const char *name)
{
    LOG("%s->i2cIdx = 0x%02x", name, obj->i2cIdx);
    LOG("%s->i2cFmPlusSpeed = 0x%x", name, obj->i2cFmPlusSpeed);
    LOG("%s->i2cRsvd = 0x%02x", name, obj->i2cRsvd);
    LOG("%s->i2c10bAddr = 0x%x", name, obj->i2c10bAddr);
    LOG("%s->hdrCapable = 0x%x", name, obj->hdrCapable);
    LOG("%s->legacyI2CDev = 0x%x", name, obj->legacyI2CDev);
    LOG("%s->isActive = 0x%x", name, obj->isActive);
    LOG("%s->addr = 0x%04x", name, obj->addr);
    LOG("%s->provIdHi = 0x%04x", name, obj->provIdHi);
    LOG("%s->provIdLo = 0x%08x", name, obj->provIdLo);
    LOG("%s->bcr = 0x%02x", name, obj->bcr);
    LOG("%s->dcr = 0x%02x", name, obj->dcr);
    LOG("%s->priv = %p", name, obj->priv);
}


/**
 * Function to validate struct DeviceDescriptor
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_DeviceDescriptor(const I3C_DeviceDescriptor *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_DeviceDescriptor
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_DeviceDescriptor(I3C_DeviceDescriptor *s1, I3C_DeviceDescriptor *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("DeviceDescriptor: one of passed pointers is NULL");
        return FAIL;
    }

    if (s1->i2cIdx != s2->i2cIdx)
    {
        LOG("DeviceDescriptor: member i2cIdx mismatch. expected %i, got %i", s1->i2cIdx, s2->i2cIdx);
        return FAIL;
    }
    if (s1->i2cFmPlusSpeed != s2->i2cFmPlusSpeed)
    {
        LOG("DeviceDescriptor: member i2cFmPlusSpeed mismatch. expected %i, got %i", s1->i2cFmPlusSpeed, s2->i2cFmPlusSpeed);
        return FAIL;
    }
    if (s1->i2cRsvd != s2->i2cRsvd)
    {
        LOG("DeviceDescriptor: member i2cRsvd mismatch. expected %i, got %i", s1->i2cRsvd, s2->i2cRsvd);
        return FAIL;
    }
    if (s1->i2c10bAddr != s2->i2c10bAddr)
    {
        LOG("DeviceDescriptor: member i2c10bAddr mismatch. expected %i, got %i", s1->i2c10bAddr, s2->i2c10bAddr);
        return FAIL;
    }
    if (s1->hdrCapable != s2->hdrCapable)
    {
        LOG("DeviceDescriptor: member hdrCapable mismatch. expected %i, got %i", s1->hdrCapable, s2->hdrCapable);
        return FAIL;
    }
    if (s1->legacyI2CDev != s2->legacyI2CDev)
    {
        LOG("DeviceDescriptor: member legacyI2CDev mismatch. expected %i, got %i", s1->legacyI2CDev, s2->legacyI2CDev);
        return FAIL;
    }
    if (s1->isActive != s2->isActive)
    {
        LOG("DeviceDescriptor: member isActive mismatch. expected %i, got %i", s1->isActive, s2->isActive);
        return FAIL;
    }
    if (s1->addr != s2->addr)
    {
        LOG("DeviceDescriptor: member addr mismatch. expected %i, got %i", s1->addr, s2->addr);
        return FAIL;
    }
    if (s1->provIdHi != s2->provIdHi)
    {
        LOG("DeviceDescriptor: member provIdHi mismatch. expected %i, got %i", s1->provIdHi, s2->provIdHi);
        return FAIL;
    }
    if (s1->provIdLo != s2->provIdLo)
    {
        LOG("DeviceDescriptor: member provIdLo mismatch. expected %i, got %i", s1->provIdLo, s2->provIdLo);
        return FAIL;
    }
    if (s1->bcr != s2->bcr)
    {
        LOG("DeviceDescriptor: member bcr mismatch. expected %i, got %i", s1->bcr, s2->bcr);
        return FAIL;
    }
    if (s1->dcr != s2->dcr)
    {
        LOG("DeviceDescriptor: member dcr mismatch. expected %i, got %i", s1->dcr, s2->dcr);
        return FAIL;
    }
    if (s1->priv != s2->priv)
    {
        LOG("DeviceDescriptor: member priv mismatch. expected %i, got %i", s1->priv, s2->priv);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_DeviceDescriptor
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_DeviceDescriptor(I3C_DeviceDescriptor *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        obj->priv = NULL;
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        obj->i2cIdx = API_TEST_table_uint8_t[(index+0)%24];
        obj->i2cFmPlusSpeed = API_TEST_table_bool[index%2];
        obj->i2cRsvd = API_TEST_table_uint8_t[(index+0)%24];
        obj->i2c10bAddr = API_TEST_table_bool[index%2];
        obj->hdrCapable = API_TEST_table_bool[index%2];
        obj->legacyI2CDev = API_TEST_table_bool[index%2];
        obj->isActive = API_TEST_table_bool[index%2];
        obj->addr = API_TEST_table_uint16_t[(index+0)%48];
        obj->provIdHi = API_TEST_table_uint16_t[(index+0)%48];
        obj->provIdLo = API_TEST_table_uint32_t[(index+0)%96];
        obj->bcr = API_TEST_table_uint8_t[(index+0)%24];
        obj->dcr = API_TEST_table_uint8_t[(index+0)%24];
        obj->priv = NULL;
        break;
    }
}


/**
 * Function to populate struct I3C_DeviceDescriptor
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_DeviceDescriptor(I3C_DeviceDescriptor *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_DeviceDescriptor)
        return;

    memset(obj, 0, sizeof(*obj));

    /* Set member i2cIdx */
    obj->i2cIdx = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member i2cFmPlusSpeed */
    obj->i2cFmPlusSpeed = (index/divisor) % (1);
    divisor *= 1;
    /* Set member i2cRsvd */
    obj->i2cRsvd = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member i2c10bAddr */
    obj->i2c10bAddr = (index/divisor) % (1);
    divisor *= 1;
    /* Set member hdrCapable */
    obj->hdrCapable = (index/divisor) % (1);
    divisor *= 1;
    /* Set member legacyI2CDev */
    obj->legacyI2CDev = (index/divisor) % (1);
    divisor *= 1;
    /* Set member isActive */
    obj->isActive = (index/divisor) % (1);
    divisor *= 1;
    /* Set member addr */
    obj->addr = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member provIdHi */
    obj->provIdHi = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member provIdLo */
    obj->provIdLo = (index/divisor) % (UINT32_MAX);
    divisor *= UINT32_MAX;
    /* Set member bcr */
    obj->bcr = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member dcr */
    obj->dcr = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
}



void API_TEST_printstruct_I3C_SlaveDescriptor(const I3C_SlaveDescriptor *obj, const char *name)
{
    LOG("%s->da = 0x%02x", name, obj->da);
    LOG("%s->dcrType = 0x%02x", name, obj->dcrType);
    LOG("%s->bcrType = 0x%02x", name, obj->bcrType);
    LOG("%s->sa = 0x%02x", name, obj->sa);
}


/**
 * Function to validate struct SlaveDescriptor
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_SlaveDescriptor(const I3C_SlaveDescriptor *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_SlaveDescriptor
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_SlaveDescriptor(I3C_SlaveDescriptor *s1, I3C_SlaveDescriptor *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("SlaveDescriptor: one of passed pointers is NULL");
        return FAIL;
    }

    if (s1->da != s2->da)
    {
        LOG("SlaveDescriptor: member da mismatch. expected %i, got %i", s1->da, s2->da);
        return FAIL;
    }
    if (s1->dcrType != s2->dcrType)
    {
        LOG("SlaveDescriptor: member dcrType mismatch. expected %i, got %i", s1->dcrType, s2->dcrType);
        return FAIL;
    }
    if (s1->bcrType != s2->bcrType)
    {
        LOG("SlaveDescriptor: member bcrType mismatch. expected %i, got %i", s1->bcrType, s2->bcrType);
        return FAIL;
    }
    if (s1->sa != s2->sa)
    {
        LOG("SlaveDescriptor: member sa mismatch. expected %i, got %i", s1->sa, s2->sa);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_SlaveDescriptor
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_SlaveDescriptor(I3C_SlaveDescriptor *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        obj->da = API_TEST_table_uint8_t[(index+0)%24];
        obj->dcrType = API_TEST_table_uint8_t[(index+0)%24];
        obj->bcrType = API_TEST_table_uint8_t[(index+0)%24];
        obj->sa = API_TEST_table_uint8_t[(index+0)%24];
        break;
    }
}


/**
 * Function to populate struct I3C_SlaveDescriptor
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_SlaveDescriptor(I3C_SlaveDescriptor *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_SlaveDescriptor)
        return;

    memset(obj, 0, sizeof(*obj));

    /* Set member da */
    obj->da = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member dcrType */
    obj->dcrType = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member bcrType */
    obj->bcrType = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member sa */
    obj->sa = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
}



void API_TEST_printstruct_I3C_SlaveDescriptors(const I3C_SlaveDescriptors *obj, const char *name)
{
    LOG("%s->slave_count = 0x%02x", name, obj->slave_count);
    LOG("%s->descriptors[I3C_ABSOLUTE_MAX_DEVS_NUM] = %u", name, obj->descriptors[I3C_ABSOLUTE_MAX_DEVS_NUM]);
}


/**
 * Function to validate struct SlaveDescriptors
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_SlaveDescriptors(const I3C_SlaveDescriptors *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        if (API_TEST_verify_I3C_SlaveDescriptor(&obj->descriptors[I3C_ABSOLUTE_MAX_DEVS_NUM]) == CDN_EINVAL)
            ret = CDN_EINVAL;

    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_SlaveDescriptors
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_SlaveDescriptors(I3C_SlaveDescriptors *s1, I3C_SlaveDescriptors *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("SlaveDescriptors: one of passed pointers is NULL");
        return FAIL;
    }

    if (s1->slave_count != s2->slave_count)
    {
        LOG("SlaveDescriptors: member slave_count mismatch. expected %i, got %i", s1->slave_count, s2->slave_count);
        return FAIL;
    }
    if (API_TEST_comparestruct_I3C_SlaveDescriptor(&s1->descriptors[I3C_ABSOLUTE_MAX_DEVS_NUM], &s2->descriptors[I3C_ABSOLUTE_MAX_DEVS_NUM], nolog))
    {
        LOG("SlaveDescriptors: member descriptors[I3C_ABSOLUTE_MAX_DEVS_NUM] mismatch. expected %i, got %i", s1->descriptors[I3C_ABSOLUTE_MAX_DEVS_NUM], s2->descriptors[I3C_ABSOLUTE_MAX_DEVS_NUM]);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_SlaveDescriptors
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_SlaveDescriptors(I3C_SlaveDescriptors *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        obj->slave_count = API_TEST_table_uint8_t[(index+0)%24];
        API_TEST_fill_I3C_SlaveDescriptor(&(obj->descriptors[I3C_ABSOLUTE_MAX_DEVS_NUM]), index % 96);
        break;
    }
}


/**
 * Function to populate struct I3C_SlaveDescriptors
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_SlaveDescriptors(I3C_SlaveDescriptors *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_SlaveDescriptors)
        return;

    memset(obj, 0, sizeof(*obj));

    /* Set member slave_count */
    obj->slave_count = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member descriptors[I3C_ABSOLUTE_MAX_DEVS_NUM] */
    API_TEST_fillvalid_I3C_SlaveDescriptor(&obj->descriptors[I3C_ABSOLUTE_MAX_DEVS_NUM], (index % API_TEST_structTestLen_I3C_SlaveDescriptor));
    divisor *= API_TEST_structTestLen_I3C_SlaveDescriptor;
}



void API_TEST_printstruct_I3C_IbiSirConfiguration(const I3C_IbiSirConfiguration *obj, const char *name)
{
    LOG("%s->ibiResp = %u", name, obj->ibiResp);
    LOG("%s->addr = 0x%04x", name, obj->addr);
    LOG("%s->ibiPayloadSize = 0x%02x", name, obj->ibiPayloadSize);
    LOG("%s->ibiPayloadSpeedLimit = %u", name, obj->ibiPayloadSpeedLimit);
    LOG("%s->ibiReqDevRole = %u", name, obj->ibiReqDevRole);
}


/**
 * Function to validate struct IbiSirConfiguration
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_IbiSirConfiguration(const I3C_IbiSirConfiguration *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        if (
            (obj->ibiResp != I3C_IBI_RESP_NACK) &&
            (obj->ibiResp != I3C_IBI_RESP_ACK)
        )
        {
            ret = CDN_EINVAL;
        }
        if (
            (obj->ibiPayloadSpeedLimit != I3C_IBI_DATA_SPEED_NOT_LIMITED) &&
            (obj->ibiPayloadSpeedLimit != I3C_IBI_DATA_SPEED_LIMITED)
        )
        {
            ret = CDN_EINVAL;
        }
        if (
            (obj->ibiReqDevRole != I3C_IBI_REQUESTING_DEV_ROLE_SLAVE) &&
            (obj->ibiReqDevRole != I3C_IBI_REQUESTING_DEV_ROLE_MASTER)
        )
        {
            ret = CDN_EINVAL;
        }
    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_IbiSirConfiguration
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_IbiSirConfiguration(I3C_IbiSirConfiguration *s1, I3C_IbiSirConfiguration *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("IbiSirConfiguration: one of passed pointers is NULL");
        return FAIL;
    }

    if (s1->ibiResp != s2->ibiResp)
    {
        LOG("IbiSirConfiguration: member ibiResp mismatch. expected %i, got %i", s1->ibiResp, s2->ibiResp);
        return FAIL;
    }
    if (s1->addr != s2->addr)
    {
        LOG("IbiSirConfiguration: member addr mismatch. expected %i, got %i", s1->addr, s2->addr);
        return FAIL;
    }
    if (s1->ibiPayloadSize != s2->ibiPayloadSize)
    {
        LOG("IbiSirConfiguration: member ibiPayloadSize mismatch. expected %i, got %i", s1->ibiPayloadSize, s2->ibiPayloadSize);
        return FAIL;
    }
    if (s1->ibiPayloadSpeedLimit != s2->ibiPayloadSpeedLimit)
    {
        LOG("IbiSirConfiguration: member ibiPayloadSpeedLimit mismatch. expected %i, got %i", s1->ibiPayloadSpeedLimit, s2->ibiPayloadSpeedLimit);
        return FAIL;
    }
    if (s1->ibiReqDevRole != s2->ibiReqDevRole)
    {
        LOG("IbiSirConfiguration: member ibiReqDevRole mismatch. expected %i, got %i", s1->ibiReqDevRole, s2->ibiReqDevRole);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_IbiSirConfiguration
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_IbiSirConfiguration(I3C_IbiSirConfiguration *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        obj->ibiResp = API_TEST_table_uint32_t[(index+0)%96];
        obj->addr = API_TEST_table_uint16_t[(index+0)%48];
        obj->ibiPayloadSize = API_TEST_table_uint8_t[(index+0)%24];
        obj->ibiPayloadSpeedLimit = API_TEST_table_uint32_t[(index+0)%96];
        obj->ibiReqDevRole = API_TEST_table_uint32_t[(index+0)%96];
        break;
    }
}


/**
 * Function to populate struct I3C_IbiSirConfiguration
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_IbiSirConfiguration(I3C_IbiSirConfiguration *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_IbiSirConfiguration)
        return;

    memset(obj, 0, sizeof(*obj));

    /* Set member ibiResp */
    uint32_t values_ibiResp[] = {I3C_IBI_RESP_NACK, I3C_IBI_RESP_ACK};

    obj->ibiResp = values_ibiResp[(index/divisor) % (2)];
    divisor *= 2;
    /* Set member addr */
    obj->addr = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member ibiPayloadSize */
    obj->ibiPayloadSize = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member ibiPayloadSpeedLimit */
    uint32_t values_ibiPayloadSpeedLimit[] = {I3C_IBI_DATA_SPEED_NOT_LIMITED, I3C_IBI_DATA_SPEED_LIMITED};

    obj->ibiPayloadSpeedLimit = values_ibiPayloadSpeedLimit[(index/divisor) % (2)];
    divisor *= 2;
    /* Set member ibiReqDevRole */
    uint32_t values_ibiReqDevRole[] = {I3C_IBI_REQUESTING_DEV_ROLE_SLAVE, I3C_IBI_REQUESTING_DEV_ROLE_MASTER};

    obj->ibiReqDevRole = values_ibiReqDevRole[(index/divisor) % (2)];
    divisor *= 2;
}



void API_TEST_printstruct_I3C_Ibi(const I3C_Ibi *obj, const char *name)
{
    LOG("%s->ibi_type = 0x%02x", name, obj->ibi_type);
    LOG("%s->xfer_bytes = 0x%02x", name, obj->xfer_bytes);
    LOG("%s->error = 0x%x", name, obj->error);
    LOG("%s->slv_id = 0x%02x", name, obj->slv_id);
    LOG("%s->acked = 0x%x", name, obj->acked);
}


/**
 * Function to validate struct Ibi
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_Ibi(const I3C_Ibi *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_Ibi
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_Ibi(I3C_Ibi *s1, I3C_Ibi *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("Ibi: one of passed pointers is NULL");
        return FAIL;
    }

    if (s1->ibi_type != s2->ibi_type)
    {
        LOG("Ibi: member ibi_type mismatch. expected %i, got %i", s1->ibi_type, s2->ibi_type);
        return FAIL;
    }
    if (s1->xfer_bytes != s2->xfer_bytes)
    {
        LOG("Ibi: member xfer_bytes mismatch. expected %i, got %i", s1->xfer_bytes, s2->xfer_bytes);
        return FAIL;
    }
    if (s1->error != s2->error)
    {
        LOG("Ibi: member error mismatch. expected %i, got %i", s1->error, s2->error);
        return FAIL;
    }
    if (s1->slv_id != s2->slv_id)
    {
        LOG("Ibi: member slv_id mismatch. expected %i, got %i", s1->slv_id, s2->slv_id);
        return FAIL;
    }
    if (s1->acked != s2->acked)
    {
        LOG("Ibi: member acked mismatch. expected %i, got %i", s1->acked, s2->acked);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_Ibi
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_Ibi(I3C_Ibi *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        obj->ibi_type = API_TEST_table_uint8_t[(index+0)%24];
        obj->xfer_bytes = API_TEST_table_uint8_t[(index+0)%24];
        obj->error = API_TEST_table_bool[index%2];
        obj->slv_id = API_TEST_table_uint8_t[(index+0)%24];
        obj->acked = API_TEST_table_bool[index%2];
        break;
    }
}


/**
 * Function to populate struct I3C_Ibi
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_Ibi(I3C_Ibi *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_Ibi)
        return;

    memset(obj, 0, sizeof(*obj));

    /* Set member ibi_type */
    obj->ibi_type = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member xfer_bytes */
    obj->xfer_bytes = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member error */
    obj->error = (index/divisor) % (1);
    divisor *= 1;
    /* Set member slv_id */
    obj->slv_id = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member acked */
    obj->acked = (index/divisor) % (1);
    divisor *= 1;
}



void API_TEST_printstruct_I3C_CommandDescriptor(const I3C_CommandDescriptor *obj, const char *name)
{
    LOG("%s->commomCommandCode = %u", name, obj->commomCommandCode);
    LOG("%s->payload = %p", name, obj->payload);
    LOG("%s->payloadSize = 0x%04x", name, obj->payloadSize);
}


/**
 * Function to validate struct CommandDescriptor
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_CommandDescriptor(const I3C_CommandDescriptor *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        if (
            (obj->commomCommandCode != I3C_CCC_ENEC_BC) &&
            (obj->commomCommandCode != I3C_CCC_DISEC_BC) &&
            (obj->commomCommandCode != I3C_CCC_ENTAS0_BC) &&
            (obj->commomCommandCode != I3C_CCC_ENTAS1_BC) &&
            (obj->commomCommandCode != I3C_CCC_ENTAS2_BC) &&
            (obj->commomCommandCode != I3C_CCC_ENTAS3_BC) &&
            (obj->commomCommandCode != I3C_CCC_RSTDAA_BC) &&
            (obj->commomCommandCode != I3C_CCC_ENTDAA_BC) &&
            (obj->commomCommandCode != I3C_CCC_DEFTGTS_BC) &&
            (obj->commomCommandCode != I3C_CCC_SETMWL_BC) &&
            (obj->commomCommandCode != I3C_CCC_SETMRL_BC) &&
            (obj->commomCommandCode != I3C_CCC_ENTTM_BC) &&
            (obj->commomCommandCode != I3C_CCC_SETBUSCON_BC) &&
            (obj->commomCommandCode != I3C_CCC_ENTHDR0_BC) &&
            (obj->commomCommandCode != I3C_CCC_ENTHDR1_BC) &&
            (obj->commomCommandCode != I3C_CCC_ENTHDR2_BC) &&
            (obj->commomCommandCode != I3C_CCC_ENTHDR3_BC) &&
            (obj->commomCommandCode != I3C_CCC_ENTHDR4_BC) &&
            (obj->commomCommandCode != I3C_CCC_ENTHDR5_BC) &&
            (obj->commomCommandCode != I3C_CCC_ENTHDR6_BC) &&
            (obj->commomCommandCode != I3C_CCC_ENTHDR7_BC) &&
            (obj->commomCommandCode != I3C_CCC_SETXTIME_BC) &&
            (obj->commomCommandCode != I3C_CCC_SETAASA_BC) &&
            (obj->commomCommandCode != I3C_CCC_RSTACT_BC) &&
            (obj->commomCommandCode != I3C_CCC_DEFGRPA_BC) &&
            (obj->commomCommandCode != I3C_CCC_RSTGRPA_BC) &&
            (obj->commomCommandCode != I3C_CCC_ENEC_DC) &&
            (obj->commomCommandCode != I3C_CCC_DISEC_DC) &&
            (obj->commomCommandCode != I3C_CCC_ENTAS0_DC) &&
            (obj->commomCommandCode != I3C_CCC_ENTAS1_DC) &&
            (obj->commomCommandCode != I3C_CCC_ENTAS2_DC) &&
            (obj->commomCommandCode != I3C_CCC_ENTAS3_DC) &&
            (obj->commomCommandCode != I3C_CCC_RSTDAA_DC) &&
            (obj->commomCommandCode != I3C_CCC_SETDASA_DC) &&
            (obj->commomCommandCode != I3C_CCC_SETNEWDA_DC) &&
            (obj->commomCommandCode != I3C_CCC_SETMWL_DC) &&
            (obj->commomCommandCode != I3C_CCC_SETMRL_DC) &&
            (obj->commomCommandCode != I3C_CCC_GETMWL_DC) &&
            (obj->commomCommandCode != I3C_CCC_GETMRL_DC) &&
            (obj->commomCommandCode != I3C_CCC_GETPID_DC) &&
            (obj->commomCommandCode != I3C_CCC_GETBCR_DC) &&
            (obj->commomCommandCode != I3C_CCC_GETDCR_DC) &&
            (obj->commomCommandCode != I3C_CCC_GETSTATUS_DC) &&
            (obj->commomCommandCode != I3C_CCC_GETACCMST_DC) &&
            (obj->commomCommandCode != I3C_CCC_SETBRGTGT_DC) &&
            (obj->commomCommandCode != I3C_CCC_GETMXDS_DC) &&
            (obj->commomCommandCode != I3C_CCC_GETHDRCAP_DC) &&
            (obj->commomCommandCode != I3C_CCC_SETXTIME_DC) &&
            (obj->commomCommandCode != I3C_CCC_GETXTIME_DC) &&
            (obj->commomCommandCode != I3C_CCC_RSTACT_DC) &&
            (obj->commomCommandCode != I3C_CCC_SETGRPA_DC) &&
            (obj->commomCommandCode != I3C_CCC_RSTGRPA_DC) &&
            (obj->commomCommandCode != I3C_CCC_SETTCTRL_DC)
        )
        {
            ret = CDN_EINVAL;
        }
    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_CommandDescriptor
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_CommandDescriptor(I3C_CommandDescriptor *s1, I3C_CommandDescriptor *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("CommandDescriptor: one of passed pointers is NULL");
        return FAIL;
    }

    if (s1->commomCommandCode != s2->commomCommandCode)
    {
        LOG("CommandDescriptor: member commomCommandCode mismatch. expected %i, got %i", s1->commomCommandCode, s2->commomCommandCode);
        return FAIL;
    }
    if (s1->payload != s2->payload)
    {
        LOG("CommandDescriptor: member payload mismatch. expected %i, got %i", s1->payload, s2->payload);
        return FAIL;
    }
    if (s1->payloadSize != s2->payloadSize)
    {
        LOG("CommandDescriptor: member payloadSize mismatch. expected %i, got %i", s1->payloadSize, s2->payloadSize);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_CommandDescriptor
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_CommandDescriptor(I3C_CommandDescriptor *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        obj->payload = NULL;
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        obj->commomCommandCode = API_TEST_table_uint32_t[(index+0)%96];
        obj->payload = NULL;
        obj->payloadSize = API_TEST_table_uint16_t[(index+0)%48];
        break;
    }
}


/**
 * Function to populate struct I3C_CommandDescriptor
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_CommandDescriptor(I3C_CommandDescriptor *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_CommandDescriptor)
        return;

    memset(obj, 0, sizeof(*obj));

    /* Set member commomCommandCode */
    uint32_t values_commomCommandCode[] = {I3C_CCC_ENEC_BC, I3C_CCC_DISEC_BC, I3C_CCC_ENTAS0_BC, I3C_CCC_ENTAS1_BC, I3C_CCC_ENTAS2_BC, I3C_CCC_ENTAS3_BC, I3C_CCC_RSTDAA_BC, I3C_CCC_ENTDAA_BC, I3C_CCC_DEFTGTS_BC, I3C_CCC_SETMWL_BC, I3C_CCC_SETMRL_BC, I3C_CCC_ENTTM_BC, I3C_CCC_SETBUSCON_BC, I3C_CCC_ENTHDR0_BC, I3C_CCC_ENTHDR1_BC, I3C_CCC_ENTHDR2_BC, I3C_CCC_ENTHDR3_BC, I3C_CCC_ENTHDR4_BC, I3C_CCC_ENTHDR5_BC, I3C_CCC_ENTHDR6_BC, I3C_CCC_ENTHDR7_BC, I3C_CCC_SETXTIME_BC, I3C_CCC_SETAASA_BC, I3C_CCC_RSTACT_BC, I3C_CCC_DEFGRPA_BC, I3C_CCC_RSTGRPA_BC, I3C_CCC_ENEC_DC, I3C_CCC_DISEC_DC, I3C_CCC_ENTAS0_DC, I3C_CCC_ENTAS1_DC, I3C_CCC_ENTAS2_DC, I3C_CCC_ENTAS3_DC, I3C_CCC_RSTDAA_DC, I3C_CCC_SETDASA_DC, I3C_CCC_SETNEWDA_DC, I3C_CCC_SETMWL_DC, I3C_CCC_SETMRL_DC, I3C_CCC_GETMWL_DC, I3C_CCC_GETMRL_DC, I3C_CCC_GETPID_DC, I3C_CCC_GETBCR_DC, I3C_CCC_GETDCR_DC, I3C_CCC_GETSTATUS_DC, I3C_CCC_GETACCMST_DC, I3C_CCC_SETBRGTGT_DC, I3C_CCC_GETMXDS_DC, I3C_CCC_GETHDRCAP_DC, I3C_CCC_SETXTIME_DC, I3C_CCC_GETXTIME_DC, I3C_CCC_RSTACT_DC, I3C_CCC_SETGRPA_DC, I3C_CCC_RSTGRPA_DC, I3C_CCC_SETTCTRL_DC};

    obj->commomCommandCode = values_commomCommandCode[(index/divisor) % (53)];
    divisor *= 53;
    /* Set member payloadSize */
    obj->payloadSize = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
}



void API_TEST_printstruct_I3C_cmd_t(const I3C_cmd_t *obj, const char *name)
{
    LOG("%s->id = 0x%02x", name, obj->id);
    LOG("%s->cmd = 0x%016x", name, obj->cmd);
    LOG("%s->payload_sdr = %p", name, obj->payload_sdr);
    LOG("%s->payload_ddr = %p", name, obj->payload_ddr);
    LOG("%s->payload_size = 0x%04x", name, obj->payload_size);
    LOG("%s->priv = 0x%08x", name, obj->priv);
    LOG("%s->is_wr_cmd = 0x%x", name, obj->is_wr_cmd);
    LOG("%s->in_cmd_fifo = 0x%x", name, obj->in_cmd_fifo);
    LOG("%s->bytes_fared = 0x%04x", name, obj->bytes_fared);
    LOG("%s->payload_iterator = 0x%04x", name, obj->payload_iterator);
    LOG("%s->ddr_crc = 0x%02x", name, obj->ddr_crc);
    LOG("%s->transfer_in_progress = 0x%x", name, obj->transfer_in_progress);
}


/**
 * Function to validate struct cmd_t
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_cmd_t(const I3C_cmd_t *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_cmd_t
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_cmd_t(I3C_cmd_t *s1, I3C_cmd_t *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("cmd_t: one of passed pointers is NULL");
        return FAIL;
    }

    if (s1->id != s2->id)
    {
        LOG("cmd_t: member id mismatch. expected %i, got %i", s1->id, s2->id);
        return FAIL;
    }
    if (s1->cmd != s2->cmd)
    {
        LOG("cmd_t: member cmd mismatch. expected %i, got %i", s1->cmd, s2->cmd);
        return FAIL;
    }
    if (s1->payload_sdr != s2->payload_sdr)
    {
        LOG("cmd_t: member payload_sdr mismatch. expected %i, got %i", s1->payload_sdr, s2->payload_sdr);
        return FAIL;
    }
    if (s1->payload_ddr != s2->payload_ddr)
    {
        LOG("cmd_t: member payload_ddr mismatch. expected %i, got %i", s1->payload_ddr, s2->payload_ddr);
        return FAIL;
    }
    if (s1->payload_size != s2->payload_size)
    {
        LOG("cmd_t: member payload_size mismatch. expected %i, got %i", s1->payload_size, s2->payload_size);
        return FAIL;
    }
    if (s1->priv != s2->priv)
    {
        LOG("cmd_t: member priv mismatch. expected %i, got %i", s1->priv, s2->priv);
        return FAIL;
    }
    if (s1->is_wr_cmd != s2->is_wr_cmd)
    {
        LOG("cmd_t: member is_wr_cmd mismatch. expected %i, got %i", s1->is_wr_cmd, s2->is_wr_cmd);
        return FAIL;
    }
    if (s1->in_cmd_fifo != s2->in_cmd_fifo)
    {
        LOG("cmd_t: member in_cmd_fifo mismatch. expected %i, got %i", s1->in_cmd_fifo, s2->in_cmd_fifo);
        return FAIL;
    }
    if (s1->bytes_fared != s2->bytes_fared)
    {
        LOG("cmd_t: member bytes_fared mismatch. expected %i, got %i", s1->bytes_fared, s2->bytes_fared);
        return FAIL;
    }
    if (s1->payload_iterator != s2->payload_iterator)
    {
        LOG("cmd_t: member payload_iterator mismatch. expected %i, got %i", s1->payload_iterator, s2->payload_iterator);
        return FAIL;
    }
    if (s1->ddr_crc != s2->ddr_crc)
    {
        LOG("cmd_t: member ddr_crc mismatch. expected %i, got %i", s1->ddr_crc, s2->ddr_crc);
        return FAIL;
    }
    if (s1->transfer_in_progress != s2->transfer_in_progress)
    {
        LOG("cmd_t: member transfer_in_progress mismatch. expected %i, got %i", s1->transfer_in_progress, s2->transfer_in_progress);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_cmd_t
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_cmd_t(I3C_cmd_t *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        obj->payload_sdr = NULL;
        obj->payload_ddr = NULL;
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        obj->id = API_TEST_table_uint8_t[(index+0)%24];
        obj->cmd = API_TEST_table_uint64_t[(index+0)%192];
        obj->payload_sdr = NULL;
        obj->payload_ddr = NULL;
        obj->payload_size = API_TEST_table_uint16_t[(index+0)%48];
        obj->priv = API_TEST_table_uint32_t[(index+0)%96];
        obj->is_wr_cmd = API_TEST_table_bool[index%2];
        obj->in_cmd_fifo = API_TEST_table_bool[index%2];
        obj->bytes_fared = API_TEST_table_uint16_t[(index+0)%48];
        obj->payload_iterator = API_TEST_table_uint16_t[(index+0)%48];
        obj->ddr_crc = API_TEST_table_uint8_t[(index+0)%24];
        obj->transfer_in_progress = API_TEST_table_bool[index%2];
        break;
    }
}


/**
 * Function to populate struct I3C_cmd_t
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_cmd_t(I3C_cmd_t *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_cmd_t)
        return;

    memset(obj, 0, sizeof(*obj));

    /* Set member id */
    obj->id = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member cmd */
    obj->cmd = (index/divisor) % (INT64_MAX);
    divisor *= INT64_MAX;
    /* Set member payload_size */
    obj->payload_size = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member priv */
    obj->priv = (index/divisor) % (UINT32_MAX);
    divisor *= UINT32_MAX;
    /* Set member is_wr_cmd */
    obj->is_wr_cmd = (index/divisor) % (1);
    divisor *= 1;
    /* Set member in_cmd_fifo */
    obj->in_cmd_fifo = (index/divisor) % (1);
    divisor *= 1;
    /* Set member bytes_fared */
    obj->bytes_fared = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member payload_iterator */
    obj->payload_iterator = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member ddr_crc */
    obj->ddr_crc = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member transfer_in_progress */
    obj->transfer_in_progress = (index/divisor) % (1);
    divisor *= 1;
}



void API_TEST_printstruct_I3C_cmd_list_element(const I3C_cmd_list_element *obj, const char *name)
{
    LOG("%s->cmd = %u", name, obj->cmd);
    LOG("%s->used = 0x%x", name, obj->used);
}


/**
 * Function to validate struct cmd_list_element
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_cmd_list_element(const I3C_cmd_list_element *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        if (API_TEST_verify_I3C_cmd_t(&obj->cmd) == CDN_EINVAL)
            ret = CDN_EINVAL;

    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_cmd_list_element
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_cmd_list_element(I3C_cmd_list_element *s1, I3C_cmd_list_element *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("cmd_list_element: one of passed pointers is NULL");
        return FAIL;
    }

    if (API_TEST_comparestruct_I3C_cmd_t(&s1->cmd, &s2->cmd, nolog))
    {
        LOG("cmd_list_element: member cmd mismatch. expected %i, got %i", s1->cmd, s2->cmd);
        return FAIL;
    }
    if (s1->used != s2->used)
    {
        LOG("cmd_list_element: member used mismatch. expected %i, got %i", s1->used, s2->used);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_cmd_list_element
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_cmd_list_element(I3C_cmd_list_element *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        API_TEST_fill_I3C_cmd_t(&(obj->cmd), index % 96);
        obj->used = API_TEST_table_bool[index%2];
        break;
    }
}


/**
 * Function to populate struct I3C_cmd_list_element
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_cmd_list_element(I3C_cmd_list_element *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_cmd_list_element)
        return;

    memset(obj, 0, sizeof(*obj));

    /* Set member cmd */
    API_TEST_fillvalid_I3C_cmd_t(&obj->cmd, (index % API_TEST_structTestLen_I3C_cmd_t));
    divisor *= API_TEST_structTestLen_I3C_cmd_t;
    /* Set member used */
    obj->used = (index/divisor) % (1);
    divisor *= 1;
}



void API_TEST_printstruct_I3C_cmd_list(const I3C_cmd_list *obj, const char *name)
{
    LOG("%s->capacity = 0x%x", name, obj->capacity);
    LOG("%s->buffer = %p", name, obj->buffer);
    LOG("%s->count = 0x%x", name, obj->count);
}


/**
 * Function to validate struct cmd_list
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_cmd_list(const I3C_cmd_list *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_cmd_list
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_cmd_list(I3C_cmd_list *s1, I3C_cmd_list *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("cmd_list: one of passed pointers is NULL");
        return FAIL;
    }

    if (s1->capacity != s2->capacity)
    {
        LOG("cmd_list: member capacity mismatch. expected %i, got %i", s1->capacity, s2->capacity);
        return FAIL;
    }
    if (API_TEST_comparestruct_I3C_cmd_list_element(s1->buffer, s2->buffer, nolog))
    {
        LOG("cmd_list: member buffer mismatch. expected %i, got %i", s1->buffer, s2->buffer);
        return FAIL;
    }
    if (s1->count != s2->count)
    {
        LOG("cmd_list: member count mismatch. expected %i, got %i", s1->count, s2->count);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_cmd_list
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_cmd_list(I3C_cmd_list *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        obj->buffer = NULL;
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        obj->capacity = 0;
        obj->buffer = NULL;
        obj->count = 0;
        break;
    }
}


/**
 * Function to populate struct I3C_cmd_list
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_cmd_list(I3C_cmd_list *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_cmd_list)
        return;

    memset(obj, 0, sizeof(*obj));

    /* Set member capacity */
    obj->capacity = (index/divisor) % (0);
    divisor *= 0;
    /* Set member count */
    obj->count = (index/divisor) % (0);
    divisor *= 0;
}



void API_TEST_printstruct_I3C_CsrData(const I3C_CsrData *obj, const char *name)
{
    LOG("%s->csr = 0x%04x", name, obj->csr);
    LOG("%s->csr16 = 0x%x", name, obj->csr16);
}


/**
 * Function to validate struct CsrData
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_CsrData(const I3C_CsrData *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_CsrData
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_CsrData(I3C_CsrData *s1, I3C_CsrData *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("CsrData: one of passed pointers is NULL");
        return FAIL;
    }

    if (s1->csr != s2->csr)
    {
        LOG("CsrData: member csr mismatch. expected %i, got %i", s1->csr, s2->csr);
        return FAIL;
    }
    if (s1->csr16 != s2->csr16)
    {
        LOG("CsrData: member csr16 mismatch. expected %i, got %i", s1->csr16, s2->csr16);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_CsrData
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_CsrData(I3C_CsrData *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        obj->csr = API_TEST_table_uint16_t[(index+0)%48];
        obj->csr16 = API_TEST_table_bool[index%2];
        break;
    }
}


/**
 * Function to populate struct I3C_CsrData
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_CsrData(I3C_CsrData *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_CsrData)
        return;

    memset(obj, 0, sizeof(*obj));

    /* Set member csr */
    obj->csr = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member csr16 */
    obj->csr16 = (index/divisor) % (1);
    divisor *= 1;
}



void API_TEST_printstruct_I3C_PayloadData(const I3C_PayloadData *obj, const char *name)
{
    LOG("%s->sdr_payload = %p", name, obj->sdr_payload);
    LOG("%s->ddr_payload = %p", name, obj->ddr_payload);
    LOG("%s->payloadSize = 0x%04x", name, obj->payloadSize);
}


/**
 * Function to validate struct PayloadData
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_PayloadData(const I3C_PayloadData *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_PayloadData
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_PayloadData(I3C_PayloadData *s1, I3C_PayloadData *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("PayloadData: one of passed pointers is NULL");
        return FAIL;
    }

    if (s1->sdr_payload != s2->sdr_payload)
    {
        LOG("PayloadData: member sdr_payload mismatch. expected %i, got %i", s1->sdr_payload, s2->sdr_payload);
        return FAIL;
    }
    if (s1->ddr_payload != s2->ddr_payload)
    {
        LOG("PayloadData: member ddr_payload mismatch. expected %i, got %i", s1->ddr_payload, s2->ddr_payload);
        return FAIL;
    }
    if (s1->payloadSize != s2->payloadSize)
    {
        LOG("PayloadData: member payloadSize mismatch. expected %i, got %i", s1->payloadSize, s2->payloadSize);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_PayloadData
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_PayloadData(I3C_PayloadData *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        obj->sdr_payload = NULL;
        obj->ddr_payload = NULL;
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        obj->sdr_payload = NULL;
        obj->ddr_payload = NULL;
        obj->payloadSize = API_TEST_table_uint16_t[(index+0)%48];
        break;
    }
}


/**
 * Function to populate struct I3C_PayloadData
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_PayloadData(I3C_PayloadData *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_PayloadData)
        return;

    memset(obj, 0, sizeof(*obj));

    /* Set member payloadSize */
    obj->payloadSize = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
}



void API_TEST_printstruct_I3C_TransmissionParameters(const I3C_TransmissionParameters *obj, const char *name)
{
    LOG("%s->broadcast = 0x%x", name, obj->broadcast);
    LOG("%s->immediate = 0x%x", name, obj->immediate);
    LOG("%s->rsbc = 0x%x", name, obj->rsbc);
}


/**
 * Function to validate struct TransmissionParameters
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_TransmissionParameters(const I3C_TransmissionParameters *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_TransmissionParameters
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_TransmissionParameters(I3C_TransmissionParameters *s1, I3C_TransmissionParameters *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("TransmissionParameters: one of passed pointers is NULL");
        return FAIL;
    }

    if (s1->broadcast != s2->broadcast)
    {
        LOG("TransmissionParameters: member broadcast mismatch. expected %i, got %i", s1->broadcast, s2->broadcast);
        return FAIL;
    }
    if (s1->immediate != s2->immediate)
    {
        LOG("TransmissionParameters: member immediate mismatch. expected %i, got %i", s1->immediate, s2->immediate);
        return FAIL;
    }
    if (s1->rsbc != s2->rsbc)
    {
        LOG("TransmissionParameters: member rsbc mismatch. expected %i, got %i", s1->rsbc, s2->rsbc);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_TransmissionParameters
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_TransmissionParameters(I3C_TransmissionParameters *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        obj->broadcast = API_TEST_table_bool[index%2];
        obj->immediate = API_TEST_table_bool[index%2];
        obj->rsbc = API_TEST_table_bool[index%2];
        break;
    }
}


/**
 * Function to populate struct I3C_TransmissionParameters
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_TransmissionParameters(I3C_TransmissionParameters *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_TransmissionParameters)
        return;

    memset(obj, 0, sizeof(*obj));

    /* Set member broadcast */
    obj->broadcast = (index/divisor) % (1);
    divisor *= 1;
    /* Set member immediate */
    obj->immediate = (index/divisor) % (1);
    divisor *= 1;
    /* Set member rsbc */
    obj->rsbc = (index/divisor) % (1);
    divisor *= 1;
}



void API_TEST_printstruct_I3C_PrivData(const I3C_PrivData *obj, const char *name)
{
    LOG("%s->regs_base = %p", name, obj->regs_base);
    LOG("%s->isr_en = 0x%x", name, obj->isr_en);
    LOG("%s->use_fifos = 0x%x", name, obj->use_fifos);
    LOG("%s->num_gpo = 0x%02x", name, obj->num_gpo);
    LOG("%s->num_gpi = 0x%02x", name, obj->num_gpi);
    LOG("%s->max_devs = 0x%02x", name, obj->max_devs);
    LOG("%s->max_ibi_devs = 0x%02x", name, obj->max_ibi_devs);
    LOG("%s->callbacks = %u", name, obj->callbacks);
    LOG("%s->devs[I3C_ABSOLUTE_MAX_DEVS_NUM] = %u", name, obj->devs[I3C_ABSOLUTE_MAX_DEVS_NUM]);
    LOG("%s->interrupt_config = %u", name, obj->interrupt_config);
    LOG("%s->slaveInterruptConfig = %u", name, obj->slaveInterruptConfig);
    LOG("%s->threshold_config = %u", name, obj->threshold_config);
    LOG("%s->dev_role = %u", name, obj->dev_role);
    LOG("%s->bus_mode = %u", name, obj->bus_mode);
    LOG("%s->cmd_comp = 0x%x", name, obj->cmd_comp);
    LOG("%s->cmd_empty = 0x%x", name, obj->cmd_empty);
    LOG("%s->cmd_abort = 0x%x", name, obj->cmd_abort);
    LOG("%s->cmd_in_progress = 0x%x", name, obj->cmd_in_progress);
    LOG("%s->imd_in_progress = 0x%x", name, obj->imd_in_progress);
    LOG("%s->cmd_fifo_used = 0x%04x", name, obj->cmd_fifo_used);
    LOG("%s->cmd_fifo_empty = 0x%x", name, obj->cmd_fifo_empty);
    LOG("%s->tx_fifo_used = 0x%04x", name, obj->tx_fifo_used);
    LOG("%s->rx_fifo_used = 0x%04x", name, obj->rx_fifo_used);
    LOG("%s->wait_for_rx = 0x%x", name, obj->wait_for_rx);
    LOG("%s->cmd_fifo_size = 0x%04x", name, obj->cmd_fifo_size);
    LOG("%s->ibi_fifo_size = 0x%04x", name, obj->ibi_fifo_size);
    LOG("%s->cmd_fifo_threshold = 0x%04x", name, obj->cmd_fifo_threshold);
    LOG("%s->tx_fifo_size = 0x%04x", name, obj->tx_fifo_size);
    LOG("%s->rx_fifo_size = 0x%04x", name, obj->rx_fifo_size);
    LOG("%s->imd_cmd = %u", name, obj->imd_cmd);
    LOG("%s->cmd_list = %u", name, obj->cmd_list);
    LOG("%s->CMD_LIST_BUFFER[I3C_CMD_BUFFER_SIZE] = %u", name, obj->CMD_LIST_BUFFER[I3C_CMD_BUFFER_SIZE]);
    LOG("%s->tx_cmd_in_progress = %p", name, obj->tx_cmd_in_progress);
    LOG("%s->rx_cmd_in_progress = %p", name, obj->rx_cmd_in_progress);
    LOG("%s->next_cmd_id = 0x%02x", name, obj->next_cmd_id);
    LOG("%s->ibi = %u", name, obj->ibi);
    LOG("%s->devs_active = 0x%04x", name, obj->devs_active);
    LOG("%s->hj_devices = 0x%04x", name, obj->hj_devices);
    LOG("%s->max_ibi_payload_size = 0x%04x", name, obj->max_ibi_payload_size);
    LOG("%s->num_apb_rw_csrs = 0x%04x", name, obj->num_apb_rw_csrs);
    LOG("%s->num_apb_ro_csrs = 0x%04x", name, obj->num_apb_ro_csrs);
    LOG("%s->num_gpi_csrs = 0x%04x", name, obj->num_gpi_csrs);
    LOG("%s->num_gpo_csrs = 0x%04x", name, obj->num_gpo_csrs);
}


/**
 * Function to validate struct PrivData
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_PrivData(const I3C_PrivData *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }
    else
    {
        if (API_TEST_verify_I3C_Callbacks(&obj->callbacks) == CDN_EINVAL)
            ret = CDN_EINVAL;

        if (API_TEST_verify_I3C_DeviceDescriptor(&obj->devs[I3C_ABSOLUTE_MAX_DEVS_NUM]) == CDN_EINVAL)
            ret = CDN_EINVAL;

        if (API_TEST_verify_I3C_InterruptConfig(&obj->interrupt_config) == CDN_EINVAL)
            ret = CDN_EINVAL;

        if (API_TEST_verify_I3C_SlaveInterruptConfig(&obj->slaveInterruptConfig) == CDN_EINVAL)
            ret = CDN_EINVAL;

        if (API_TEST_verify_I3C_ThresholdConfig(&obj->threshold_config) == CDN_EINVAL)
            ret = CDN_EINVAL;

        if (
            (obj->dev_role != I3C_DEV_ROLE_MASTER) &&
            (obj->dev_role != I3C_DEV_ROLE_SECONDARY_MASTER)
        )
        {
            ret = CDN_EINVAL;
        }
        if (
            (obj->bus_mode != I3C_BUS_MODE_PURE) &&
            (obj->bus_mode != I3C_BUS_MODE_INVALID) &&
            (obj->bus_mode != I3C_BUS_MODE_MIXED_FAST) &&
            (obj->bus_mode != I3C_BUS_MODE_MIXED_SLOW)
        )
        {
            ret = CDN_EINVAL;
        }
        if (API_TEST_verify_I3C_cmd_t(&obj->imd_cmd) == CDN_EINVAL)
            ret = CDN_EINVAL;

        if (API_TEST_verify_I3C_cmd_list(&obj->cmd_list) == CDN_EINVAL)
            ret = CDN_EINVAL;

        if (API_TEST_verify_I3C_cmd_list_element(&obj->CMD_LIST_BUFFER[I3C_CMD_BUFFER_SIZE]) == CDN_EINVAL)
            ret = CDN_EINVAL;

        if (API_TEST_verify_I3C_Ibi(&obj->ibi) == CDN_EINVAL)
            ret = CDN_EINVAL;

    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_PrivData
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_PrivData(I3C_PrivData *s1, I3C_PrivData *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("PrivData: one of passed pointers is NULL");
        return FAIL;
    }

    if (s1->regs_base != s2->regs_base)
    {
        LOG("PrivData: member regs_base mismatch. expected %i, got %i", s1->regs_base, s2->regs_base);
        return FAIL;
    }
    if (s1->isr_en != s2->isr_en)
    {
        LOG("PrivData: member isr_en mismatch. expected %i, got %i", s1->isr_en, s2->isr_en);
        return FAIL;
    }
    if (s1->use_fifos != s2->use_fifos)
    {
        LOG("PrivData: member use_fifos mismatch. expected %i, got %i", s1->use_fifos, s2->use_fifos);
        return FAIL;
    }
    if (s1->num_gpo != s2->num_gpo)
    {
        LOG("PrivData: member num_gpo mismatch. expected %i, got %i", s1->num_gpo, s2->num_gpo);
        return FAIL;
    }
    if (s1->num_gpi != s2->num_gpi)
    {
        LOG("PrivData: member num_gpi mismatch. expected %i, got %i", s1->num_gpi, s2->num_gpi);
        return FAIL;
    }
    if (s1->max_devs != s2->max_devs)
    {
        LOG("PrivData: member max_devs mismatch. expected %i, got %i", s1->max_devs, s2->max_devs);
        return FAIL;
    }
    if (s1->max_ibi_devs != s2->max_ibi_devs)
    {
        LOG("PrivData: member max_ibi_devs mismatch. expected %i, got %i", s1->max_ibi_devs, s2->max_ibi_devs);
        return FAIL;
    }
    if (API_TEST_comparestruct_I3C_Callbacks(&s1->callbacks, &s2->callbacks, nolog))
    {
        LOG("PrivData: member callbacks mismatch. expected %i, got %i", s1->callbacks, s2->callbacks);
        return FAIL;
    }
    if (API_TEST_comparestruct_I3C_DeviceDescriptor(&s1->devs[I3C_ABSOLUTE_MAX_DEVS_NUM], &s2->devs[I3C_ABSOLUTE_MAX_DEVS_NUM], nolog))
    {
        LOG("PrivData: member devs[I3C_ABSOLUTE_MAX_DEVS_NUM] mismatch. expected %i, got %i", s1->devs[I3C_ABSOLUTE_MAX_DEVS_NUM], s2->devs[I3C_ABSOLUTE_MAX_DEVS_NUM]);
        return FAIL;
    }
    if (API_TEST_comparestruct_I3C_InterruptConfig(&s1->interrupt_config, &s2->interrupt_config, nolog))
    {
        LOG("PrivData: member interrupt_config mismatch. expected %i, got %i", s1->interrupt_config, s2->interrupt_config);
        return FAIL;
    }
    if (API_TEST_comparestruct_I3C_SlaveInterruptConfig(&s1->slaveInterruptConfig, &s2->slaveInterruptConfig, nolog))
    {
        LOG("PrivData: member slaveInterruptConfig mismatch. expected %i, got %i", s1->slaveInterruptConfig, s2->slaveInterruptConfig);
        return FAIL;
    }
    if (API_TEST_comparestruct_I3C_ThresholdConfig(&s1->threshold_config, &s2->threshold_config, nolog))
    {
        LOG("PrivData: member threshold_config mismatch. expected %i, got %i", s1->threshold_config, s2->threshold_config);
        return FAIL;
    }
    if (s1->dev_role != s2->dev_role)
    {
        LOG("PrivData: member dev_role mismatch. expected %i, got %i", s1->dev_role, s2->dev_role);
        return FAIL;
    }
    if (s1->bus_mode != s2->bus_mode)
    {
        LOG("PrivData: member bus_mode mismatch. expected %i, got %i", s1->bus_mode, s2->bus_mode);
        return FAIL;
    }
    if (s1->cmd_comp != s2->cmd_comp)
    {
        LOG("PrivData: member cmd_comp mismatch. expected %i, got %i", s1->cmd_comp, s2->cmd_comp);
        return FAIL;
    }
    if (s1->cmd_empty != s2->cmd_empty)
    {
        LOG("PrivData: member cmd_empty mismatch. expected %i, got %i", s1->cmd_empty, s2->cmd_empty);
        return FAIL;
    }
    if (s1->cmd_abort != s2->cmd_abort)
    {
        LOG("PrivData: member cmd_abort mismatch. expected %i, got %i", s1->cmd_abort, s2->cmd_abort);
        return FAIL;
    }
    if (s1->cmd_in_progress != s2->cmd_in_progress)
    {
        LOG("PrivData: member cmd_in_progress mismatch. expected %i, got %i", s1->cmd_in_progress, s2->cmd_in_progress);
        return FAIL;
    }
    if (s1->imd_in_progress != s2->imd_in_progress)
    {
        LOG("PrivData: member imd_in_progress mismatch. expected %i, got %i", s1->imd_in_progress, s2->imd_in_progress);
        return FAIL;
    }
    if (s1->cmd_fifo_used != s2->cmd_fifo_used)
    {
        LOG("PrivData: member cmd_fifo_used mismatch. expected %i, got %i", s1->cmd_fifo_used, s2->cmd_fifo_used);
        return FAIL;
    }
    if (s1->cmd_fifo_empty != s2->cmd_fifo_empty)
    {
        LOG("PrivData: member cmd_fifo_empty mismatch. expected %i, got %i", s1->cmd_fifo_empty, s2->cmd_fifo_empty);
        return FAIL;
    }
    if (s1->tx_fifo_used != s2->tx_fifo_used)
    {
        LOG("PrivData: member tx_fifo_used mismatch. expected %i, got %i", s1->tx_fifo_used, s2->tx_fifo_used);
        return FAIL;
    }
    if (s1->rx_fifo_used != s2->rx_fifo_used)
    {
        LOG("PrivData: member rx_fifo_used mismatch. expected %i, got %i", s1->rx_fifo_used, s2->rx_fifo_used);
        return FAIL;
    }
    if (s1->wait_for_rx != s2->wait_for_rx)
    {
        LOG("PrivData: member wait_for_rx mismatch. expected %i, got %i", s1->wait_for_rx, s2->wait_for_rx);
        return FAIL;
    }
    if (s1->cmd_fifo_size != s2->cmd_fifo_size)
    {
        LOG("PrivData: member cmd_fifo_size mismatch. expected %i, got %i", s1->cmd_fifo_size, s2->cmd_fifo_size);
        return FAIL;
    }
    if (s1->ibi_fifo_size != s2->ibi_fifo_size)
    {
        LOG("PrivData: member ibi_fifo_size mismatch. expected %i, got %i", s1->ibi_fifo_size, s2->ibi_fifo_size);
        return FAIL;
    }
    if (s1->cmd_fifo_threshold != s2->cmd_fifo_threshold)
    {
        LOG("PrivData: member cmd_fifo_threshold mismatch. expected %i, got %i", s1->cmd_fifo_threshold, s2->cmd_fifo_threshold);
        return FAIL;
    }
    if (s1->tx_fifo_size != s2->tx_fifo_size)
    {
        LOG("PrivData: member tx_fifo_size mismatch. expected %i, got %i", s1->tx_fifo_size, s2->tx_fifo_size);
        return FAIL;
    }
    if (s1->rx_fifo_size != s2->rx_fifo_size)
    {
        LOG("PrivData: member rx_fifo_size mismatch. expected %i, got %i", s1->rx_fifo_size, s2->rx_fifo_size);
        return FAIL;
    }
    if (API_TEST_comparestruct_I3C_cmd_t(&s1->imd_cmd, &s2->imd_cmd, nolog))
    {
        LOG("PrivData: member imd_cmd mismatch. expected %i, got %i", s1->imd_cmd, s2->imd_cmd);
        return FAIL;
    }
    if (API_TEST_comparestruct_I3C_cmd_list(&s1->cmd_list, &s2->cmd_list, nolog))
    {
        LOG("PrivData: member cmd_list mismatch. expected %i, got %i", s1->cmd_list, s2->cmd_list);
        return FAIL;
    }
    if (API_TEST_comparestruct_I3C_cmd_list_element(&s1->CMD_LIST_BUFFER[I3C_CMD_BUFFER_SIZE], &s2->CMD_LIST_BUFFER[I3C_CMD_BUFFER_SIZE], nolog))
    {
        LOG("PrivData: member CMD_LIST_BUFFER[I3C_CMD_BUFFER_SIZE] mismatch. expected %i, got %i", s1->CMD_LIST_BUFFER[I3C_CMD_BUFFER_SIZE], s2->CMD_LIST_BUFFER[I3C_CMD_BUFFER_SIZE]);
        return FAIL;
    }
    if (API_TEST_comparestruct_I3C_cmd_t(s1->tx_cmd_in_progress, s2->tx_cmd_in_progress, nolog))
    {
        LOG("PrivData: member tx_cmd_in_progress mismatch. expected %i, got %i", s1->tx_cmd_in_progress, s2->tx_cmd_in_progress);
        return FAIL;
    }
    if (API_TEST_comparestruct_I3C_cmd_t(s1->rx_cmd_in_progress, s2->rx_cmd_in_progress, nolog))
    {
        LOG("PrivData: member rx_cmd_in_progress mismatch. expected %i, got %i", s1->rx_cmd_in_progress, s2->rx_cmd_in_progress);
        return FAIL;
    }
    if (s1->next_cmd_id != s2->next_cmd_id)
    {
        LOG("PrivData: member next_cmd_id mismatch. expected %i, got %i", s1->next_cmd_id, s2->next_cmd_id);
        return FAIL;
    }
    if (API_TEST_comparestruct_I3C_Ibi(&s1->ibi, &s2->ibi, nolog))
    {
        LOG("PrivData: member ibi mismatch. expected %i, got %i", s1->ibi, s2->ibi);
        return FAIL;
    }
    if (s1->devs_active != s2->devs_active)
    {
        LOG("PrivData: member devs_active mismatch. expected %i, got %i", s1->devs_active, s2->devs_active);
        return FAIL;
    }
    if (s1->hj_devices != s2->hj_devices)
    {
        LOG("PrivData: member hj_devices mismatch. expected %i, got %i", s1->hj_devices, s2->hj_devices);
        return FAIL;
    }
    if (s1->max_ibi_payload_size != s2->max_ibi_payload_size)
    {
        LOG("PrivData: member max_ibi_payload_size mismatch. expected %i, got %i", s1->max_ibi_payload_size, s2->max_ibi_payload_size);
        return FAIL;
    }
    if (s1->num_apb_rw_csrs != s2->num_apb_rw_csrs)
    {
        LOG("PrivData: member num_apb_rw_csrs mismatch. expected %i, got %i", s1->num_apb_rw_csrs, s2->num_apb_rw_csrs);
        return FAIL;
    }
    if (s1->num_apb_ro_csrs != s2->num_apb_ro_csrs)
    {
        LOG("PrivData: member num_apb_ro_csrs mismatch. expected %i, got %i", s1->num_apb_ro_csrs, s2->num_apb_ro_csrs);
        return FAIL;
    }
    if (s1->num_gpi_csrs != s2->num_gpi_csrs)
    {
        LOG("PrivData: member num_gpi_csrs mismatch. expected %i, got %i", s1->num_gpi_csrs, s2->num_gpi_csrs);
        return FAIL;
    }
    if (s1->num_gpo_csrs != s2->num_gpo_csrs)
    {
        LOG("PrivData: member num_gpo_csrs mismatch. expected %i, got %i", s1->num_gpo_csrs, s2->num_gpo_csrs);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_PrivData
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_PrivData(I3C_PrivData *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        obj->regs_base = NULL;
        obj->tx_cmd_in_progress = NULL;
        obj->rx_cmd_in_progress = NULL;
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        obj->regs_base = NULL;
        obj->isr_en = API_TEST_table_bool[index%2];
        obj->use_fifos = API_TEST_table_bool[index%2];
        obj->num_gpo = API_TEST_table_uint8_t[(index+0)%24];
        obj->num_gpi = API_TEST_table_uint8_t[(index+0)%24];
        obj->max_devs = API_TEST_table_uint8_t[(index+0)%24];
        obj->max_ibi_devs = API_TEST_table_uint8_t[(index+0)%24];
        API_TEST_fill_I3C_Callbacks(&(obj->callbacks), index % 96);
        API_TEST_fill_I3C_DeviceDescriptor(&(obj->devs[I3C_ABSOLUTE_MAX_DEVS_NUM]), index % 96);
        API_TEST_fill_I3C_InterruptConfig(&(obj->interrupt_config), index % 96);
        API_TEST_fill_I3C_SlaveInterruptConfig(&(obj->slaveInterruptConfig), index % 96);
        API_TEST_fill_I3C_ThresholdConfig(&(obj->threshold_config), index % 96);
        obj->dev_role = API_TEST_table_uint32_t[(index+0)%96];
        obj->bus_mode = API_TEST_table_uint32_t[(index+0)%96];
        obj->cmd_comp = API_TEST_table_bool[index%2];
        obj->cmd_empty = API_TEST_table_bool[index%2];
        obj->cmd_abort = API_TEST_table_bool[index%2];
        obj->cmd_in_progress = API_TEST_table_bool[index%2];
        obj->imd_in_progress = API_TEST_table_bool[index%2];
        obj->cmd_fifo_used = API_TEST_table_uint16_t[(index+0)%48];
        obj->cmd_fifo_empty = API_TEST_table_bool[index%2];
        obj->tx_fifo_used = API_TEST_table_uint16_t[(index+0)%48];
        obj->rx_fifo_used = API_TEST_table_uint16_t[(index+0)%48];
        obj->wait_for_rx = API_TEST_table_bool[index%2];
        obj->cmd_fifo_size = API_TEST_table_uint16_t[(index+0)%48];
        obj->ibi_fifo_size = API_TEST_table_uint16_t[(index+0)%48];
        obj->cmd_fifo_threshold = API_TEST_table_uint16_t[(index+0)%48];
        obj->tx_fifo_size = API_TEST_table_uint16_t[(index+0)%48];
        obj->rx_fifo_size = API_TEST_table_uint16_t[(index+0)%48];
        API_TEST_fill_I3C_cmd_t(&(obj->imd_cmd), index % 96);
        API_TEST_fill_I3C_cmd_list(&(obj->cmd_list), index % 96);
        API_TEST_fill_I3C_cmd_list_element(&(obj->CMD_LIST_BUFFER[I3C_CMD_BUFFER_SIZE]), index % 96);
        obj->tx_cmd_in_progress = NULL;
        obj->rx_cmd_in_progress = NULL;
        obj->next_cmd_id = API_TEST_table_uint8_t[(index+0)%24];
        API_TEST_fill_I3C_Ibi(&(obj->ibi), index % 96);
        obj->devs_active = API_TEST_table_uint16_t[(index+0)%48];
        obj->hj_devices = API_TEST_table_uint16_t[(index+0)%48];
        obj->max_ibi_payload_size = API_TEST_table_uint16_t[(index+0)%48];
        obj->num_apb_rw_csrs = API_TEST_table_uint16_t[(index+0)%48];
        obj->num_apb_ro_csrs = API_TEST_table_uint16_t[(index+0)%48];
        obj->num_gpi_csrs = API_TEST_table_uint16_t[(index+0)%48];
        obj->num_gpo_csrs = API_TEST_table_uint16_t[(index+0)%48];
        break;
    }
}


/**
 * Function to populate struct I3C_PrivData
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_PrivData(I3C_PrivData *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_PrivData)
        return;

    memset(obj, 0, sizeof(*obj));

    /* Set member isr_en */
    obj->isr_en = (index/divisor) % (1);
    divisor *= 1;
    /* Set member use_fifos */
    obj->use_fifos = (index/divisor) % (1);
    divisor *= 1;
    /* Set member num_gpo */
    obj->num_gpo = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member num_gpi */
    obj->num_gpi = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member max_devs */
    obj->max_devs = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member max_ibi_devs */
    obj->max_ibi_devs = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member callbacks */
    API_TEST_fillvalid_I3C_Callbacks(&obj->callbacks, (index % API_TEST_structTestLen_I3C_Callbacks));
    divisor *= API_TEST_structTestLen_I3C_Callbacks;
    /* Set member devs[I3C_ABSOLUTE_MAX_DEVS_NUM] */
    API_TEST_fillvalid_I3C_DeviceDescriptor(&obj->devs[I3C_ABSOLUTE_MAX_DEVS_NUM], (index % API_TEST_structTestLen_I3C_DeviceDescriptor));
    divisor *= API_TEST_structTestLen_I3C_DeviceDescriptor;
    /* Set member interrupt_config */
    API_TEST_fillvalid_I3C_InterruptConfig(&obj->interrupt_config, (index % API_TEST_structTestLen_I3C_InterruptConfig));
    divisor *= API_TEST_structTestLen_I3C_InterruptConfig;
    /* Set member slaveInterruptConfig */
    API_TEST_fillvalid_I3C_SlaveInterruptConfig(&obj->slaveInterruptConfig, (index % API_TEST_structTestLen_I3C_SlaveInterruptConfig));
    divisor *= API_TEST_structTestLen_I3C_SlaveInterruptConfig;
    /* Set member threshold_config */
    API_TEST_fillvalid_I3C_ThresholdConfig(&obj->threshold_config, (index % API_TEST_structTestLen_I3C_ThresholdConfig));
    divisor *= API_TEST_structTestLen_I3C_ThresholdConfig;
    /* Set member dev_role */
    uint32_t values_dev_role[] = {I3C_DEV_ROLE_MASTER, I3C_DEV_ROLE_SECONDARY_MASTER};

    obj->dev_role = values_dev_role[(index/divisor) % (2)];
    divisor *= 2;
    /* Set member bus_mode */
    uint32_t values_bus_mode[] = {I3C_BUS_MODE_PURE, I3C_BUS_MODE_INVALID, I3C_BUS_MODE_MIXED_FAST, I3C_BUS_MODE_MIXED_SLOW};

    obj->bus_mode = values_bus_mode[(index/divisor) % (4)];
    divisor *= 4;
    /* Set member cmd_comp */
    obj->cmd_comp = (index/divisor) % (1);
    divisor *= 1;
    /* Set member cmd_empty */
    obj->cmd_empty = (index/divisor) % (1);
    divisor *= 1;
    /* Set member cmd_abort */
    obj->cmd_abort = (index/divisor) % (1);
    divisor *= 1;
    /* Set member cmd_in_progress */
    obj->cmd_in_progress = (index/divisor) % (1);
    divisor *= 1;
    /* Set member imd_in_progress */
    obj->imd_in_progress = (index/divisor) % (1);
    divisor *= 1;
    /* Set member cmd_fifo_used */
    obj->cmd_fifo_used = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member cmd_fifo_empty */
    obj->cmd_fifo_empty = (index/divisor) % (1);
    divisor *= 1;
    /* Set member tx_fifo_used */
    obj->tx_fifo_used = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member rx_fifo_used */
    obj->rx_fifo_used = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member wait_for_rx */
    obj->wait_for_rx = (index/divisor) % (1);
    divisor *= 1;
    /* Set member cmd_fifo_size */
    obj->cmd_fifo_size = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member ibi_fifo_size */
    obj->ibi_fifo_size = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member cmd_fifo_threshold */
    obj->cmd_fifo_threshold = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member tx_fifo_size */
    obj->tx_fifo_size = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member rx_fifo_size */
    obj->rx_fifo_size = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member imd_cmd */
    API_TEST_fillvalid_I3C_cmd_t(&obj->imd_cmd, (index % API_TEST_structTestLen_I3C_cmd_t));
    divisor *= API_TEST_structTestLen_I3C_cmd_t;
    /* Set member cmd_list */
    API_TEST_fillvalid_I3C_cmd_list(&obj->cmd_list, (index % API_TEST_structTestLen_I3C_cmd_list));
    divisor *= API_TEST_structTestLen_I3C_cmd_list;
    /* Set member CMD_LIST_BUFFER[I3C_CMD_BUFFER_SIZE] */
    API_TEST_fillvalid_I3C_cmd_list_element(&obj->CMD_LIST_BUFFER[I3C_CMD_BUFFER_SIZE], (index % API_TEST_structTestLen_I3C_cmd_list_element));
    divisor *= API_TEST_structTestLen_I3C_cmd_list_element;
    /* Set member next_cmd_id */
    obj->next_cmd_id = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member ibi */
    API_TEST_fillvalid_I3C_Ibi(&obj->ibi, (index % API_TEST_structTestLen_I3C_Ibi));
    divisor *= API_TEST_structTestLen_I3C_Ibi;
    /* Set member devs_active */
    obj->devs_active = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member hj_devices */
    obj->hj_devices = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member max_ibi_payload_size */
    obj->max_ibi_payload_size = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member num_apb_rw_csrs */
    obj->num_apb_rw_csrs = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member num_apb_ro_csrs */
    obj->num_apb_ro_csrs = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member num_gpi_csrs */
    obj->num_gpi_csrs = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member num_gpo_csrs */
    obj->num_gpo_csrs = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
}



void API_TEST_printstruct_I3C_AsfInfo(const I3C_AsfInfo *obj, const char *name)
{
    LOG("%s->regs_base = %p", name, obj->regs_base);
}


/**
 * Function to validate struct AsfInfo
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_AsfInfo(const I3C_AsfInfo *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_AsfInfo
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_AsfInfo(I3C_AsfInfo *s1, I3C_AsfInfo *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("AsfInfo: one of passed pointers is NULL");
        return FAIL;
    }

    if (s1->regs_base != s2->regs_base)
    {
        LOG("AsfInfo: member regs_base mismatch. expected %i, got %i", s1->regs_base, s2->regs_base);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_AsfInfo
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_AsfInfo(I3C_AsfInfo *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        obj->regs_base = NULL;
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        obj->regs_base = NULL;
        break;
    }
}


/**
 * Function to populate struct I3C_AsfInfo
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_AsfInfo(I3C_AsfInfo *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_AsfInfo)
        return;

    memset(obj, 0, sizeof(*obj));

}



void API_TEST_printstruct_I3C_MaxReadLength(const I3C_MaxReadLength *obj, const char *name)
{
    LOG("%s->payload_length = 0x%04x", name, obj->payload_length);
    LOG("%s->ibi_payload_length = 0x%02x", name, obj->ibi_payload_length);
}


/**
 * Function to validate struct MaxReadLength
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_MaxReadLength(const I3C_MaxReadLength *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_MaxReadLength
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_MaxReadLength(I3C_MaxReadLength *s1, I3C_MaxReadLength *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("MaxReadLength: one of passed pointers is NULL");
        return FAIL;
    }

    if (s1->payload_length != s2->payload_length)
    {
        LOG("MaxReadLength: member payload_length mismatch. expected %i, got %i", s1->payload_length, s2->payload_length);
        return FAIL;
    }
    if (s1->ibi_payload_length != s2->ibi_payload_length)
    {
        LOG("MaxReadLength: member ibi_payload_length mismatch. expected %i, got %i", s1->ibi_payload_length, s2->ibi_payload_length);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_MaxReadLength
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_MaxReadLength(I3C_MaxReadLength *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        obj->payload_length = API_TEST_table_uint16_t[(index+0)%48];
        obj->ibi_payload_length = API_TEST_table_uint8_t[(index+0)%24];
        break;
    }
}


/**
 * Function to populate struct I3C_MaxReadLength
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_MaxReadLength(I3C_MaxReadLength *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_MaxReadLength)
        return;

    memset(obj, 0, sizeof(*obj));

    /* Set member payload_length */
    obj->payload_length = (index/divisor) % (UINT16_MAX);
    divisor *= UINT16_MAX;
    /* Set member ibi_payload_length */
    obj->ibi_payload_length = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
}



void API_TEST_printstruct_I3C_MaxDataSpeed(const I3C_MaxDataSpeed *obj, const char *name)
{
    LOG("%s->read_speed = 0x%02x", name, obj->read_speed);
    LOG("%s->write_speed = 0x%02x", name, obj->write_speed);
}


/**
 * Function to validate struct MaxDataSpeed
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_MaxDataSpeed(const I3C_MaxDataSpeed *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_MaxDataSpeed
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_MaxDataSpeed(I3C_MaxDataSpeed *s1, I3C_MaxDataSpeed *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("MaxDataSpeed: one of passed pointers is NULL");
        return FAIL;
    }

    if (s1->read_speed != s2->read_speed)
    {
        LOG("MaxDataSpeed: member read_speed mismatch. expected %i, got %i", s1->read_speed, s2->read_speed);
        return FAIL;
    }
    if (s1->write_speed != s2->write_speed)
    {
        LOG("MaxDataSpeed: member write_speed mismatch. expected %i, got %i", s1->write_speed, s2->write_speed);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_MaxDataSpeed
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_MaxDataSpeed(I3C_MaxDataSpeed *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        obj->read_speed = API_TEST_table_uint8_t[(index+0)%24];
        obj->write_speed = API_TEST_table_uint8_t[(index+0)%24];
        break;
    }
}


/**
 * Function to populate struct I3C_MaxDataSpeed
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_MaxDataSpeed(I3C_MaxDataSpeed *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_MaxDataSpeed)
        return;

    memset(obj, 0, sizeof(*obj));

    /* Set member read_speed */
    obj->read_speed = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member write_speed */
    obj->write_speed = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
}



void API_TEST_printstruct_I3C_Tcam0Data(const I3C_Tcam0Data *obj, const char *name)
{
    LOG("%s->supportedModes = 0x%02x", name, obj->supportedModes);
    LOG("%s->stateByte = 0x%02x", name, obj->stateByte);
    LOG("%s->freqByte = 0x%02x", name, obj->freqByte);
    LOG("%s->InaccuracyByte = 0x%02x", name, obj->InaccuracyByte);
}


/**
 * Function to validate struct Tcam0Data
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_Tcam0Data(const I3C_Tcam0Data *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_Tcam0Data
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_Tcam0Data(I3C_Tcam0Data *s1, I3C_Tcam0Data *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("Tcam0Data: one of passed pointers is NULL");
        return FAIL;
    }

    if (s1->supportedModes != s2->supportedModes)
    {
        LOG("Tcam0Data: member supportedModes mismatch. expected %i, got %i", s1->supportedModes, s2->supportedModes);
        return FAIL;
    }
    if (s1->stateByte != s2->stateByte)
    {
        LOG("Tcam0Data: member stateByte mismatch. expected %i, got %i", s1->stateByte, s2->stateByte);
        return FAIL;
    }
    if (s1->freqByte != s2->freqByte)
    {
        LOG("Tcam0Data: member freqByte mismatch. expected %i, got %i", s1->freqByte, s2->freqByte);
        return FAIL;
    }
    if (s1->InaccuracyByte != s2->InaccuracyByte)
    {
        LOG("Tcam0Data: member InaccuracyByte mismatch. expected %i, got %i", s1->InaccuracyByte, s2->InaccuracyByte);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_Tcam0Data
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_Tcam0Data(I3C_Tcam0Data *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        obj->supportedModes = API_TEST_table_uint8_t[(index+0)%24];
        obj->stateByte = API_TEST_table_uint8_t[(index+0)%24];
        obj->freqByte = API_TEST_table_uint8_t[(index+0)%24];
        obj->InaccuracyByte = API_TEST_table_uint8_t[(index+0)%24];
        break;
    }
}


/**
 * Function to populate struct I3C_Tcam0Data
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_Tcam0Data(I3C_Tcam0Data *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_Tcam0Data)
        return;

    memset(obj, 0, sizeof(*obj));

    /* Set member supportedModes */
    obj->supportedModes = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member stateByte */
    obj->stateByte = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member freqByte */
    obj->freqByte = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member InaccuracyByte */
    obj->InaccuracyByte = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
}



void API_TEST_printstruct_I3C_GroupDescriptors(const I3C_GroupDescriptors *obj, const char *name)
{
    LOG("%s->group_address = 0x%02x", name, obj->group_address);
    LOG("%s->group_descriptor = 0x%02x", name, obj->group_descriptor);
    LOG("%s->target_count = 0x%02x", name, obj->target_count);
    LOG("%s->da[I3C_ABSOLUTE_MAX_DEVS_NUM] = 0x%02x", name, obj->da[I3C_ABSOLUTE_MAX_DEVS_NUM]);
}


/**
 * Function to validate struct GroupDescriptors
 *
 * @param[in] obj pointer to struct to be verified
 * @returns 0 for valid
 * @returns CDN_EINVAL for invalid
 */
uint32_t API_TEST_verify_I3C_GroupDescriptors(const I3C_GroupDescriptors *obj)
{
    uint32_t ret = PASS;

    if (obj == NULL)
    {
        ret = CDN_EINVAL;
    }

    return ret;
}


/**
 * Function to compare instances of struct I3C_GroupDescriptors
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
uint32_t API_TEST_comparestruct_I3C_GroupDescriptors(I3C_GroupDescriptors *s1, I3C_GroupDescriptors *s2, uint32_t nolog)
{
    if ((s1 == NULL) || (s2 == NULL))
    {
        LOG("GroupDescriptors: one of passed pointers is NULL");
        return FAIL;
    }

    if (s1->group_address != s2->group_address)
    {
        LOG("GroupDescriptors: member group_address mismatch. expected %i, got %i", s1->group_address, s2->group_address);
        return FAIL;
    }
    if (s1->group_descriptor != s2->group_descriptor)
    {
        LOG("GroupDescriptors: member group_descriptor mismatch. expected %i, got %i", s1->group_descriptor, s2->group_descriptor);
        return FAIL;
    }
    if (s1->target_count != s2->target_count)
    {
        LOG("GroupDescriptors: member target_count mismatch. expected %i, got %i", s1->target_count, s2->target_count);
        return FAIL;
    }
    if (s1->da[I3C_ABSOLUTE_MAX_DEVS_NUM] != s2->da[I3C_ABSOLUTE_MAX_DEVS_NUM])
    {
        LOG("GroupDescriptors: member da[I3C_ABSOLUTE_MAX_DEVS_NUM] mismatch. expected %i, got %i", s1->da[I3C_ABSOLUTE_MAX_DEVS_NUM], s2->da[I3C_ABSOLUTE_MAX_DEVS_NUM]);
        return FAIL;
    }
    return PASS;
}


/**
 * Function to populate struct I3C_GroupDescriptors
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fill_I3C_GroupDescriptors(I3C_GroupDescriptors *obj, uint32_t index)
{
    if (obj == NULL)
        return;

    switch (index)
    {
    case 0:
        /* Fill with zeros */
        memset(obj, 0, sizeof(*obj));
        break;
    case 1:
        /* Fill with ones except pointers */
        memset(obj, 0xff, sizeof(*obj));
        break;
    default:
        memset(obj, 0, sizeof(*obj));
        obj->group_address = API_TEST_table_uint8_t[(index+0)%24];
        obj->group_descriptor = API_TEST_table_uint8_t[(index+0)%24];
        obj->target_count = API_TEST_table_uint8_t[(index+0)%24];
        obj->da[I3C_ABSOLUTE_MAX_DEVS_NUM] = API_TEST_table_uint8_t[(index+0)%24];
        break;
    }
}


/**
 * Function to populate struct I3C_GroupDescriptors
 *
 * @param[out] obj pointer to struct to be populated with data
 * @param[in] index index for populating data
 */
void API_TEST_fillvalid_I3C_GroupDescriptors(I3C_GroupDescriptors *obj, uint64_t index)
{
    uint64_t divisor = 1;

    if (obj == NULL)
        return;

    if (index >= API_TEST_structTestLen_I3C_GroupDescriptors)
        return;

    memset(obj, 0, sizeof(*obj));

    /* Set member group_address */
    obj->group_address = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member group_descriptor */
    obj->group_descriptor = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member target_count */
    obj->target_count = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
    /* Set member da[I3C_ABSOLUTE_MAX_DEVS_NUM] */
    obj->da[I3C_ABSOLUTE_MAX_DEVS_NUM] = (index/divisor) % (UINT8_MAX);
    divisor *= UINT8_MAX;
}



uint32_t API_TEST_expected_probe(const I3C_Config* config, I3C_SysReq* sysReq)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_Config(config) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_probe(const I3C_Config* config, I3C_SysReq* sysReq)
{
    LOG("probe(config=%p, sysReq=%p)", config, sysReq);
    LOG("struct parameter config (%p):", config);
    API_TEST_printstruct_I3C_Config(config, "config");
    LOG("struct parameter sysReq (%p):", sysReq);
    API_TEST_printstruct_I3C_SysReq(sysReq, "sysReq");
}


uint32_t API_TEST_expected_init(I3C_PrivData* pd, const I3C_Config* config, const I3C_Callbacks* callbacks)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_Config(config) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_Callbacks(callbacks) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_init(I3C_PrivData* pd, const I3C_Config* config, const I3C_Callbacks* callbacks)
{
    LOG("init(pd=%p, config=%p, callbacks=%p)", pd, config, callbacks);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter config (%p):", config);
    API_TEST_printstruct_I3C_Config(config, "config");
    LOG("struct parameter callbacks (%p):", callbacks);
    API_TEST_printstruct_I3C_Callbacks(callbacks, "callbacks");
}


uint32_t API_TEST_expected_isr(I3C_PrivData* pd)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_isr(I3C_PrivData* pd)
{
    LOG("isr(pd=%p)", pd);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_start(I3C_PrivData* pd)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_start(I3C_PrivData* pd)
{
    LOG("start(pd=%p)", pd);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_stop(I3C_PrivData* pd)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_stop(I3C_PrivData* pd)
{
    LOG("stop(pd=%p)", pd);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_destroy(I3C_PrivData* pd)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_destroy(I3C_PrivData* pd)
{
    LOG("destroy(pd=%p)", pd);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_enableCore(I3C_PrivData* pd)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_enableCore(I3C_PrivData* pd)
{
    LOG("enableCore(pd=%p)", pd);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_disableCore(I3C_PrivData* pd)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_disableCore(I3C_PrivData* pd)
{
    LOG("disableCore(pd=%p)", pd);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_setBusMode(I3C_PrivData* pd, I3C_BusMode mode)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (
        (mode != I3C_BUS_MODE_PURE) &&
        (mode != I3C_BUS_MODE_INVALID) &&
        (mode != I3C_BUS_MODE_MIXED_FAST) &&
        (mode != I3C_BUS_MODE_MIXED_SLOW)
    )
    {
        return CDN_EINVAL;
    }


    return expectedRet;
}


void API_TEST_printargs_setBusMode(I3C_PrivData* pd, I3C_BusMode mode)
{
    LOG("setBusMode(pd=%p, mode=%u)", pd, mode);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_getBusMode(I3C_PrivData* pd, I3C_BusMode* mode)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (
        (*mode != I3C_BUS_MODE_PURE) &&
        (*mode != I3C_BUS_MODE_INVALID) &&
        (*mode != I3C_BUS_MODE_MIXED_FAST) &&
        (*mode != I3C_BUS_MODE_MIXED_SLOW)
    )
    {
        return CDN_EINVAL;
    }


    return expectedRet;
}


void API_TEST_printargs_getBusMode(I3C_PrivData* pd, I3C_BusMode* mode)
{
    LOG("getBusMode(pd=%p, mode=%p)", pd, mode);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_setBcr(I3C_PrivData* pd, uint8_t bcr, uint8_t devId)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;





    return expectedRet;
}


void API_TEST_printargs_setBcr(I3C_PrivData* pd, uint8_t bcr, uint8_t devId)
{
    LOG("setBcr(pd=%p, bcr=0x%02x, devId=0x%02x)", pd, bcr, devId);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_setDcr(I3C_PrivData* pd, uint8_t dcr, uint8_t devId)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;





    return expectedRet;
}


void API_TEST_printargs_setDcr(I3C_PrivData* pd, uint8_t dcr, uint8_t devId)
{
    LOG("setDcr(pd=%p, dcr=0x%02x, devId=0x%02x)", pd, dcr, devId);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_setPid(I3C_PrivData* pd, const uint8_t* pid, uint8_t devId)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;





    return expectedRet;
}


void API_TEST_printargs_setPid(I3C_PrivData* pd, const uint8_t* pid, uint8_t devId)
{
    LOG("setPid(pd=%p, pid=%p, devId=0x%02x)", pd, pid, devId);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_configureDevices(I3C_PrivData* pd, I3C_DeviceDescriptor* devs, uint8_t numDevs)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_DeviceDescriptor(devs) == CDN_EINVAL)
        return CDN_EINVAL;




    return expectedRet;
}


void API_TEST_printargs_configureDevices(I3C_PrivData* pd, I3C_DeviceDescriptor* devs, uint8_t numDevs)
{
    LOG("configureDevices(pd=%p, devs=%p, numDevs=0x%02x)", pd, devs, numDevs);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter devs (%p):", devs);
    API_TEST_printstruct_I3C_DeviceDescriptor(devs, "devs");
}


uint32_t API_TEST_expected_configureDevice(I3C_PrivData* pd, I3C_DeviceDescriptor* dev, uint8_t index)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_DeviceDescriptor(dev) == CDN_EINVAL)
        return CDN_EINVAL;




    return expectedRet;
}


void API_TEST_printargs_configureDevice(I3C_PrivData* pd, I3C_DeviceDescriptor* dev, uint8_t index)
{
    LOG("configureDevice(pd=%p, dev=%p, index=0x%02x)", pd, dev, index);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter dev (%p):", dev);
    API_TEST_printstruct_I3C_DeviceDescriptor(dev, "dev");
}


uint32_t API_TEST_expected_configurePrescalers(I3C_PrivData* pd, const I3C_Config* config)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_Config(config) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_configurePrescalers(I3C_PrivData* pd, const I3C_Config* config)
{
    LOG("configurePrescalers(pd=%p, config=%p)", pd, config);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter config (%p):", config);
    API_TEST_printstruct_I3C_Config(config, "config");
}


uint32_t API_TEST_expected_clearRrOfDevice(I3C_PrivData* pd, uint8_t device_no)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;




    return expectedRet;
}


void API_TEST_printargs_clearRrOfDevice(I3C_PrivData* pd, uint8_t device_no)
{
    LOG("clearRrOfDevice(pd=%p, device_no=0x%02x)", pd, device_no);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_getNewDevices(I3C_PrivData* pd, uint16_t* hj_devices)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_getNewDevices(I3C_PrivData* pd, uint16_t* hj_devices)
{
    LOG("getNewDevices(pd=%p, hj_devices=%p)", pd, hj_devices);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_configureInterrupts(I3C_PrivData* pd, const I3C_InterruptConfig* interruptConfig)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_InterruptConfig(interruptConfig) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_configureInterrupts(I3C_PrivData* pd, const I3C_InterruptConfig* interruptConfig)
{
    LOG("configureInterrupts(pd=%p, interruptConfig=%p)", pd, interruptConfig);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter interruptConfig (%p):", interruptConfig);
    API_TEST_printstruct_I3C_InterruptConfig(interruptConfig, "interruptConfig");
}


uint32_t API_TEST_expected_configureThresholds(I3C_PrivData* pd, const I3C_ThresholdConfig* thresholdConfig)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_ThresholdConfig(thresholdConfig) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_configureThresholds(I3C_PrivData* pd, const I3C_ThresholdConfig* thresholdConfig)
{
    LOG("configureThresholds(pd=%p, thresholdConfig=%p)", pd, thresholdConfig);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter thresholdConfig (%p):", thresholdConfig);
    API_TEST_printstruct_I3C_ThresholdConfig(thresholdConfig, "thresholdConfig");
}


uint32_t API_TEST_expected_cmdExec(I3C_PrivData* pd)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdExec(I3C_PrivData* pd)
{
    LOG("cmdExec(pd=%p)", pd);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_cmdExecImmediate(I3C_PrivData* pd)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdExecImmediate(I3C_PrivData* pd)
{
    LOG("cmdExecImmediate(pd=%p)", pd);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_enableMcs(I3C_PrivData* pd)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_enableMcs(I3C_PrivData* pd)
{
    LOG("enableMcs(pd=%p)", pd);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_disableMcs(I3C_PrivData* pd)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_disableMcs(I3C_PrivData* pd)
{
    LOG("disableMcs(pd=%p)", pd);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_manualCommandStart(I3C_PrivData* pd)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_manualCommandStart(I3C_PrivData* pd)
{
    LOG("manualCommandStart(pd=%p)", pd);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_cmdCount(const I3C_PrivData* pd)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdCount(const I3C_PrivData* pd)
{
    LOG("cmdCount(pd=%p)", pd);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_cmdMaxCount(const I3C_PrivData* pd)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdMaxCount(const I3C_PrivData* pd)
{
    LOG("cmdMaxCount(pd=%p)", pd);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_cmdClearAll(I3C_PrivData* pd)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdClearAll(I3C_PrivData* pd)
{
    LOG("cmdClearAll(pd=%p)", pd);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_devPrint(const I3C_PrivData* pd)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_devPrint(const I3C_PrivData* pd)
{
    LOG("devPrint(pd=%p)", pd);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_enableTc(I3C_PrivData* pd)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_enableTc(I3C_PrivData* pd)
{
    LOG("enableTc(pd=%p)", pd);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_cmdAddPrivWrite(I3C_PrivData* pd, uint16_t da, const I3C_CsrData* csr_data, const I3C_PayloadData* payload_data, I3C_TransmitMode xmitMmode)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;


    if (API_TEST_verify_I3C_CsrData(csr_data) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_PayloadData(payload_data) == CDN_EINVAL)
        return CDN_EINVAL;

    if (
        (xmitMmode != I3C_CMD_XMIT_MODE_SINGLE_CSR) &&
        (xmitMmode != I3C_CMD_XMIT_MODE_MULTI_BYTE_INC) &&
        (xmitMmode != I3C_CMD_XMIT_MODE_MULTI_BYTE_STATIC) &&
        (xmitMmode != I3C_CMD_XMIT_MODE_NCA)
    )
    {
        return CDN_EINVAL;
    }


    return expectedRet;
}


void API_TEST_printargs_cmdAddPrivWrite(I3C_PrivData* pd, uint16_t da, const I3C_CsrData* csr_data, const I3C_PayloadData* payload_data, I3C_TransmitMode xmitMmode)
{
    LOG("cmdAddPrivWrite(pd=%p, da=0x%04x, csr_data=%p, payload_data=%p, xmitMmode=%u)", pd, da, csr_data, payload_data, xmitMmode);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter csr_data (%p):", csr_data);
    API_TEST_printstruct_I3C_CsrData(csr_data, "csr_data");
    LOG("struct parameter payload_data (%p):", payload_data);
    API_TEST_printstruct_I3C_PayloadData(payload_data, "payload_data");
}


uint32_t API_TEST_expected_cmdAddPrivRead(I3C_PrivData* pd, uint16_t da, const I3C_CsrData* csr_data, const I3C_PayloadData* payload_data, I3C_TransmitMode xmitMmode)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;


    if (API_TEST_verify_I3C_CsrData(csr_data) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_PayloadData(payload_data) == CDN_EINVAL)
        return CDN_EINVAL;

    if (
        (xmitMmode != I3C_CMD_XMIT_MODE_SINGLE_CSR) &&
        (xmitMmode != I3C_CMD_XMIT_MODE_MULTI_BYTE_INC) &&
        (xmitMmode != I3C_CMD_XMIT_MODE_MULTI_BYTE_STATIC) &&
        (xmitMmode != I3C_CMD_XMIT_MODE_NCA)
    )
    {
        return CDN_EINVAL;
    }


    return expectedRet;
}


void API_TEST_printargs_cmdAddPrivRead(I3C_PrivData* pd, uint16_t da, const I3C_CsrData* csr_data, const I3C_PayloadData* payload_data, I3C_TransmitMode xmitMmode)
{
    LOG("cmdAddPrivRead(pd=%p, da=0x%04x, csr_data=%p, payload_data=%p, xmitMmode=%u)", pd, da, csr_data, payload_data, xmitMmode);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter csr_data (%p):", csr_data);
    API_TEST_printstruct_I3C_CsrData(csr_data, "csr_data");
    LOG("struct parameter payload_data (%p):", payload_data);
    API_TEST_printstruct_I3C_PayloadData(payload_data, "payload_data");
}


uint32_t API_TEST_expected_cmdAddPrivI2CWrite(I3C_PrivData* pd, uint16_t da, uint8_t* payload, uint16_t payloadSize)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;






    return expectedRet;
}


void API_TEST_printargs_cmdAddPrivI2CWrite(I3C_PrivData* pd, uint16_t da, uint8_t* payload, uint16_t payloadSize)
{
    LOG("cmdAddPrivI2CWrite(pd=%p, da=0x%04x, payload=%p, payloadSize=0x%04x)", pd, da, payload, payloadSize);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_cmdAddPrivI2CRead(I3C_PrivData* pd, uint16_t da, uint8_t* payload, uint16_t payloadSize)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;






    return expectedRet;
}


void API_TEST_printargs_cmdAddPrivI2CRead(I3C_PrivData* pd, uint16_t da, uint8_t* payload, uint16_t payloadSize)
{
    LOG("cmdAddPrivI2CRead(pd=%p, da=0x%04x, payload=%p, payloadSize=0x%04x)", pd, da, payload, payloadSize);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_cmdAddDdrWrite(I3C_PrivData* pd, uint8_t da, uint8_t command, I3C_HdrMode hdrMode, I3C_PayloadData* payload_data)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    if (
        (hdrMode != I3C_HDR_MODE_DDR) &&
        (hdrMode != I3C_HDR_MODE_TSP) &&
        (hdrMode != I3C_HDR_MODE_TSL)
    )
    {
        return CDN_EINVAL;
    }
    if (API_TEST_verify_I3C_PayloadData(payload_data) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddDdrWrite(I3C_PrivData* pd, uint8_t da, uint8_t command, I3C_HdrMode hdrMode, I3C_PayloadData* payload_data)
{
    LOG("cmdAddDdrWrite(pd=%p, da=0x%02x, command=0x%02x, hdrMode=%u, payload_data=%p)", pd, da, command, hdrMode, payload_data);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter payload_data (%p):", payload_data);
    API_TEST_printstruct_I3C_PayloadData(payload_data, "payload_data");
}


uint32_t API_TEST_expected_cmdAddDdrRead(I3C_PrivData* pd, uint8_t da, uint8_t command, I3C_HdrMode hdrMode, I3C_PayloadData* payload_data)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    if (
        (hdrMode != I3C_HDR_MODE_DDR) &&
        (hdrMode != I3C_HDR_MODE_TSP) &&
        (hdrMode != I3C_HDR_MODE_TSL)
    )
    {
        return CDN_EINVAL;
    }
    if (API_TEST_verify_I3C_PayloadData(payload_data) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddDdrRead(I3C_PrivData* pd, uint8_t da, uint8_t command, I3C_HdrMode hdrMode, I3C_PayloadData* payload_data)
{
    LOG("cmdAddDdrRead(pd=%p, da=0x%02x, command=0x%02x, hdrMode=%u, payload_data=%p)", pd, da, command, hdrMode, payload_data);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter payload_data (%p):", payload_data);
    API_TEST_printstruct_I3C_PayloadData(payload_data, "payload_data");
}


uint32_t API_TEST_expected_cmdAddSetSlaveEvents(I3C_PrivData* pd, uint8_t eventsMask, bool enable, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (enable == 0)
    {
        /* do not check parameters
         */
    }
    else
    {
        if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
            return CDN_EINVAL;




        if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
            return CDN_EINVAL;

    }


    return expectedRet;
}


void API_TEST_printargs_cmdAddSetSlaveEvents(I3C_PrivData* pd, uint8_t eventsMask, bool enable, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddSetSlaveEvents(pd=%p, eventsMask=0x%02x, enable=0x%x, devAddr=0x%02x, tx_params=%p)", pd, eventsMask, enable, devAddr, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddEnterActivityState(I3C_PrivData* pd, I3C_ActivityState state, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (
        (state != I3C_ACTIVITY_STATE_0) &&
        (state != I3C_ACTIVITY_STATE_1) &&
        (state != I3C_ACTIVITY_STATE_2) &&
        (state != I3C_ACTIVITY_STATE_3)
    )
    {
        return CDN_EINVAL;
    }

    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddEnterActivityState(I3C_PrivData* pd, I3C_ActivityState state, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddEnterActivityState(pd=%p, state=%u, devAddr=0x%02x, tx_params=%p)", pd, state, devAddr, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddResetDaa(I3C_PrivData* pd, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;


    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddResetDaa(I3C_PrivData* pd, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddResetDaa(pd=%p, devAddr=0x%02x, tx_params=%p)", pd, devAddr, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddEnterDaa(I3C_PrivData* pd, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddEnterDaa(I3C_PrivData* pd, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddEnterDaa(pd=%p, tx_params=%p)", pd, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddSetMaxWriteLength(I3C_PrivData* pd, uint16_t length, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddSetMaxWriteLength(I3C_PrivData* pd, uint16_t length, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddSetMaxWriteLength(pd=%p, length=0x%04x, devAddr=0x%02x, tx_params=%p)", pd, length, devAddr, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddGetMaxWriteLength(I3C_PrivData* pd, uint16_t* length, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddGetMaxWriteLength(I3C_PrivData* pd, uint16_t* length, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddGetMaxWriteLength(pd=%p, length=%p, devAddr=0x%02x, tx_params=%p)", pd, length, devAddr, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddSetMaxReadLength(I3C_PrivData* pd, I3C_MaxReadLength max_read_length, uint8_t length_size, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_MaxReadLength(&max_read_length) == CDN_EINVAL)
        return CDN_EINVAL;



    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddSetMaxReadLength(I3C_PrivData* pd, I3C_MaxReadLength max_read_length, uint8_t length_size, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddSetMaxReadLength(pd=%p, max_read_length=%u, length_size=0x%02x, devAddr=0x%02x, tx_params=%p)", pd, max_read_length, length_size, devAddr, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter max_read_length (%u):", max_read_length);
    API_TEST_printstruct_I3C_MaxReadLength(&max_read_length, "max_read_length");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddGetMaxReadLength(I3C_PrivData* pd, I3C_MaxReadLength* max_read_length, uint8_t length_size, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_MaxReadLength(max_read_length) == CDN_EINVAL)
        return CDN_EINVAL;



    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddGetMaxReadLength(I3C_PrivData* pd, I3C_MaxReadLength* max_read_length, uint8_t length_size, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddGetMaxReadLength(pd=%p, max_read_length=%p, length_size=0x%02x, devAddr=0x%02x, tx_params=%p)", pd, max_read_length, length_size, devAddr, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter max_read_length (%p):", max_read_length);
    API_TEST_printstruct_I3C_MaxReadLength(max_read_length, "max_read_length");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddGetMaxDataSpeed(I3C_PrivData* pd, I3C_MaxDataSpeed* max_data_speed, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_MaxDataSpeed(max_data_speed) == CDN_EINVAL)
        return CDN_EINVAL;


    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddGetMaxDataSpeed(I3C_PrivData* pd, I3C_MaxDataSpeed* max_data_speed, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddGetMaxDataSpeed(pd=%p, max_data_speed=%p, devAddr=0x%02x, tx_params=%p)", pd, max_data_speed, devAddr, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter max_data_speed (%p):", max_data_speed);
    API_TEST_printstruct_I3C_MaxDataSpeed(max_data_speed, "max_data_speed");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_getSlavesList(const I3C_PrivData* pd, I3C_SlaveDescriptors* slaveDescs)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_SlaveDescriptors(slaveDescs) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_getSlavesList(const I3C_PrivData* pd, I3C_SlaveDescriptors* slaveDescs)
{
    LOG("getSlavesList(pd=%p, slaveDescs=%p)", pd, slaveDescs);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter slaveDescs (%p):", slaveDescs);
    API_TEST_printstruct_I3C_SlaveDescriptors(slaveDescs, "slaveDescs");
}


uint32_t API_TEST_expected_cmdAddDefineSlavesList(I3C_PrivData* pd, I3C_SlaveDescriptors* slaveDescs, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_SlaveDescriptors(slaveDescs) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddDefineSlavesList(I3C_PrivData* pd, I3C_SlaveDescriptors* slaveDescs, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddDefineSlavesList(pd=%p, slaveDescs=%p, tx_params=%p)", pd, slaveDescs, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter slaveDescs (%p):", slaveDescs);
    API_TEST_printstruct_I3C_SlaveDescriptors(slaveDescs, "slaveDescs");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddEnterTestMode(I3C_PrivData* pd, uint8_t mode, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;


    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddEnterTestMode(I3C_PrivData* pd, uint8_t mode, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddEnterTestMode(pd=%p, mode=0x%02x, tx_params=%p)", pd, mode, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddSetBuscon(I3C_PrivData* pd, uint8_t* context_buf, uint8_t length_size, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddSetBuscon(I3C_PrivData* pd, uint8_t* context_buf, uint8_t length_size, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddSetBuscon(pd=%p, context_buf=%p, length_size=0x%02x, tx_params=%p)", pd, context_buf, length_size, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddEnterHdrMode(I3C_PrivData* pd, I3C_HdrMode mode, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (
        (mode != I3C_HDR_MODE_DDR) &&
        (mode != I3C_HDR_MODE_TSP) &&
        (mode != I3C_HDR_MODE_TSL)
    )
    {
        return CDN_EINVAL;
    }
    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddEnterHdrMode(I3C_PrivData* pd, I3C_HdrMode mode, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddEnterHdrMode(pd=%p, mode=%u, tx_params=%p)", pd, mode, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddSetAaSa(I3C_PrivData* pd, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddSetAaSa(I3C_PrivData* pd, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddSetAaSa(pd=%p, tx_params=%p)", pd, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdSetDaFromSa(I3C_PrivData* pd, uint8_t address, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdSetDaFromSa(I3C_PrivData* pd, uint8_t address, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdSetDaFromSa(pd=%p, address=0x%02x, devAddr=0x%02x, tx_params=%p)", pd, address, devAddr, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddSetNewDa(I3C_PrivData* pd, uint8_t da, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddSetNewDa(I3C_PrivData* pd, uint8_t da, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddSetNewDa(pd=%p, da=0x%02x, devAddr=0x%02x, tx_params=%p)", pd, da, devAddr, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddSetRstAct(I3C_PrivData* pd, uint8_t DefiningByte, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddSetRstAct(I3C_PrivData* pd, uint8_t DefiningByte, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddSetRstAct(pd=%p, DefiningByte=0x%02x, devAddr=0x%02x, tx_params=%p)", pd, DefiningByte, devAddr, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddSetXTime(I3C_PrivData* pd, uint8_t SubCommandByte, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddSetXTime(I3C_PrivData* pd, uint8_t SubCommandByte, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddSetXTime(pd=%p, SubCommandByte=0x%02x, devAddr=0x%02x, tx_params=%p)", pd, SubCommandByte, devAddr, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddSetGroupAddr(I3C_PrivData* pd, uint8_t grpaddr, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddSetGroupAddr(I3C_PrivData* pd, uint8_t grpaddr, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddSetGroupAddr(pd=%p, grpaddr=0x%02x, devAddr=0x%02x, tx_params=%p)", pd, grpaddr, devAddr, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddDefineGroupList(I3C_PrivData* pd, I3C_GroupDescriptors* groupDescs, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_GroupDescriptors(groupDescs) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddDefineGroupList(I3C_PrivData* pd, I3C_GroupDescriptors* groupDescs, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddDefineGroupList(pd=%p, groupDescs=%p, tx_params=%p)", pd, groupDescs, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter groupDescs (%p):", groupDescs);
    API_TEST_printstruct_I3C_GroupDescriptors(groupDescs, "groupDescs");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddResetGrpa(I3C_PrivData* pd, uint8_t grpAddr, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddResetGrpa(I3C_PrivData* pd, uint8_t grpAddr, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddResetGrpa(pd=%p, grpAddr=0x%02x, devAddr=0x%02x, tx_params=%p)", pd, grpAddr, devAddr, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddGetProvisionalId(I3C_PrivData* pd, uint8_t* buff, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddGetProvisionalId(I3C_PrivData* pd, uint8_t* buff, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddGetProvisionalId(pd=%p, buff=%p, devAddr=0x%02x, tx_params=%p)", pd, buff, devAddr, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddGetBcr(I3C_PrivData* pd, uint8_t* bcr, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddGetBcr(I3C_PrivData* pd, uint8_t* bcr, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddGetBcr(pd=%p, bcr=%p, devAddr=0x%02x, tx_params=%p)", pd, bcr, devAddr, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddGetDcr(I3C_PrivData* pd, uint8_t* dcr, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddGetDcr(I3C_PrivData* pd, uint8_t* dcr, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddGetDcr(pd=%p, dcr=%p, devAddr=0x%02x, tx_params=%p)", pd, dcr, devAddr, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddGetStatus(I3C_PrivData* pd, uint16_t* status, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddGetStatus(I3C_PrivData* pd, uint16_t* status, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddGetStatus(pd=%p, status=%p, devAddr=0x%02x, tx_params=%p)", pd, status, devAddr, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddGetAccMst(I3C_PrivData* pd, uint8_t* recData, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddGetAccMst(I3C_PrivData* pd, uint8_t* recData, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddGetAccMst(pd=%p, recData=%p, devAddr=0x%02x, tx_params=%p)", pd, recData, devAddr, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_cmdAddGetXTime(I3C_PrivData* pd, I3C_Tcam0Data* tCamData, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_Tcam0Data(tCamData) == CDN_EINVAL)
        return CDN_EINVAL;


    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_cmdAddGetXTime(I3C_PrivData* pd, I3C_Tcam0Data* tCamData, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    LOG("cmdAddGetXTime(pd=%p, tCamData=%p, devAddr=0x%02x, tx_params=%p)", pd, tCamData, devAddr, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter tCamData (%p):", tCamData);
    API_TEST_printstruct_I3C_Tcam0Data(tCamData, "tCamData");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_CmdSetNCAMode(I3C_PrivData* pd, uint8_t mode, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    if (API_TEST_verify_I3C_TransmissionParameters(tx_params) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_CmdSetNCAMode(I3C_PrivData* pd, uint8_t mode, uint8_t devAddr, const I3C_TransmissionParameters* tx_params)
{
    LOG("CmdSetNCAMode(pd=%p, mode=0x%02x, devAddr=0x%02x, tx_params=%p)", pd, mode, devAddr, tx_params);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter tx_params (%p):", tx_params);
    API_TEST_printstruct_I3C_TransmissionParameters(tx_params, "tx_params");
}


uint32_t API_TEST_expected_ibiConfigureDevices(const I3C_PrivData* pd, const I3C_IbiSirConfiguration* ibi_sir_cfg, uint32_t num_sir_cfgs)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_IbiSirConfiguration(ibi_sir_cfg) == CDN_EINVAL)
        return CDN_EINVAL;




    return expectedRet;
}


void API_TEST_printargs_ibiConfigureDevices(const I3C_PrivData* pd, const I3C_IbiSirConfiguration* ibi_sir_cfg, uint32_t num_sir_cfgs)
{
    LOG("ibiConfigureDevices(pd=%p, ibi_sir_cfg=%p, num_sir_cfgs=0x%08x)", pd, ibi_sir_cfg, num_sir_cfgs);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter ibi_sir_cfg (%p):", ibi_sir_cfg);
    API_TEST_printstruct_I3C_IbiSirConfiguration(ibi_sir_cfg, "ibi_sir_cfg");
}


uint32_t API_TEST_expected_ibiModifyDeviceConfig(const I3C_PrivData* pd, const I3C_IbiSirConfiguration* ibi_sir_cfg, uint8_t da)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_IbiSirConfiguration(ibi_sir_cfg) == CDN_EINVAL)
        return CDN_EINVAL;




    return expectedRet;
}


void API_TEST_printargs_ibiModifyDeviceConfig(const I3C_PrivData* pd, const I3C_IbiSirConfiguration* ibi_sir_cfg, uint8_t da)
{
    LOG("ibiModifyDeviceConfig(pd=%p, ibi_sir_cfg=%p, da=0x%02x)", pd, ibi_sir_cfg, da);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter ibi_sir_cfg (%p):", ibi_sir_cfg);
    API_TEST_printstruct_I3C_IbiSirConfiguration(ibi_sir_cfg, "ibi_sir_cfg");
}


uint32_t API_TEST_expected_ibiGetAddressOfIssuer(I3C_PrivData* pd)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_ibiGetAddressOfIssuer(I3C_PrivData* pd)
{
    LOG("ibiGetAddressOfIssuer(pd=%p)", pd);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_ibiGetData(I3C_PrivData* pd, uint8_t* buf, uint16_t payload_size)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;





    return expectedRet;
}


void API_TEST_printargs_ibiGetData(I3C_PrivData* pd, uint8_t* buf, uint16_t payload_size)
{
    LOG("ibiGetData(pd=%p, buf=%p, payload_size=0x%04x)", pd, buf, payload_size);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_hjConfigureResponse(I3C_PrivData* pd, I3C_HjResponse hj_response, I3C_HjDisableSet hj_disable_set)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (
        (hj_response != I3C_HJ_RESP_NACK) &&
        (hj_response != I3C_HJ_RESP_ACK)
    )
    {
        return CDN_EINVAL;
    }
    if (
        (hj_disable_set != I3C_HJ_REQ_SLAVE_NOT_DISABLE) &&
        (hj_disable_set != I3C_HJ_REQ_SLAVE_DISABLE)
    )
    {
        return CDN_EINVAL;
    }


    return expectedRet;
}


void API_TEST_printargs_hjConfigureResponse(I3C_PrivData* pd, I3C_HjResponse hj_response, I3C_HjDisableSet hj_disable_set)
{
    LOG("hjConfigureResponse(pd=%p, hj_response=%u, hj_disable_set=%u)", pd, hj_response, hj_disable_set);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_configureSlaveInterrupts(I3C_PrivData* pd, const I3C_SlaveInterruptConfig* slaveInterruptConfig)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_SlaveInterruptConfig(slaveInterruptConfig) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_configureSlaveInterrupts(I3C_PrivData* pd, const I3C_SlaveInterruptConfig* slaveInterruptConfig)
{
    LOG("configureSlaveInterrupts(pd=%p, slaveInterruptConfig=%p)", pd, slaveInterruptConfig);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter slaveInterruptConfig (%p):", slaveInterruptConfig);
    API_TEST_printstruct_I3C_SlaveInterruptConfig(slaveInterruptConfig, "slaveInterruptConfig");
}


uint32_t API_TEST_expected_slaveModeConfigure(I3C_PrivData* pd, const I3C_SlaveInterruptConfig* slaveInterruptConfig)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_SlaveInterruptConfig(slaveInterruptConfig) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_slaveModeConfigure(I3C_PrivData* pd, const I3C_SlaveInterruptConfig* slaveInterruptConfig)
{
    LOG("slaveModeConfigure(pd=%p, slaveInterruptConfig=%p)", pd, slaveInterruptConfig);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter slaveInterruptConfig (%p):", slaveInterruptConfig);
    API_TEST_printstruct_I3C_SlaveInterruptConfig(slaveInterruptConfig, "slaveInterruptConfig");
}


uint32_t API_TEST_expected_slaveModeReqSdrRead(I3C_PrivData* pd, uint8_t* buf, uint16_t num_bytes)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;





    return expectedRet;
}


void API_TEST_printargs_slaveModeReqSdrRead(I3C_PrivData* pd, uint8_t* buf, uint16_t num_bytes)
{
    LOG("slaveModeReqSdrRead(pd=%p, buf=%p, num_bytes=0x%04x)", pd, buf, num_bytes);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_slaveModeReqSdrWrite(I3C_PrivData* pd, const uint8_t* buf, uint16_t num_bytes)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;





    return expectedRet;
}


void API_TEST_printargs_slaveModeReqSdrWrite(I3C_PrivData* pd, const uint8_t* buf, uint16_t num_bytes)
{
    LOG("slaveModeReqSdrWrite(pd=%p, buf=%p, num_bytes=0x%04x)", pd, buf, num_bytes);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_slaveModeReqDdrRead(I3C_PrivData* pd, uint16_t* buf, uint16_t num_words)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;





    return expectedRet;
}


void API_TEST_printargs_slaveModeReqDdrRead(I3C_PrivData* pd, uint16_t* buf, uint16_t num_words)
{
    LOG("slaveModeReqDdrRead(pd=%p, buf=%p, num_words=0x%04x)", pd, buf, num_words);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_slaveModeReqDdrWrite(I3C_PrivData* pd, const uint16_t* buf_in, uint16_t num_words_in)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;





    return expectedRet;
}


void API_TEST_printargs_slaveModeReqDdrWrite(I3C_PrivData* pd, const uint16_t* buf_in, uint16_t num_words_in)
{
    LOG("slaveModeReqDdrWrite(pd=%p, buf_in=%p, num_words_in=0x%04x)", pd, buf_in, num_words_in);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_slaveModeRequestHotJoin(I3C_PrivData* pd)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_slaveModeRequestHotJoin(I3C_PrivData* pd)
{
    LOG("slaveModeRequestHotJoin(pd=%p)", pd);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_slaveModeMastershipReq(I3C_PrivData* pd)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_slaveModeMastershipReq(I3C_PrivData* pd)
{
    LOG("slaveModeMastershipReq(pd=%p)", pd);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_slaveModeRequestIbi(I3C_PrivData* pd, uint8_t tCam0Event, bool ibiTCam0)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;





    return expectedRet;
}


void API_TEST_printargs_slaveModeRequestIbi(I3C_PrivData* pd, uint8_t tCam0Event, bool ibiTCam0)
{
    LOG("slaveModeRequestIbi(pd=%p, tCam0Event=0x%02x, ibiTCam0=0x%x)", pd, tCam0Event, ibiTCam0);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_slaveModeWriteIbiPayload(I3C_PrivData* pd, const uint8_t* buf, uint8_t numbytes)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;





    return expectedRet;
}


void API_TEST_printargs_slaveModeWriteIbiPayload(I3C_PrivData* pd, const uint8_t* buf, uint8_t numbytes)
{
    LOG("slaveModeWriteIbiPayload(pd=%p, buf=%p, numbytes=0x%02x)", pd, buf, numbytes);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_slaveModeReadIbiPayload(I3C_PrivData* pd, uint8_t* buf, uint8_t numbytes)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;





    return expectedRet;
}


void API_TEST_printargs_slaveModeReadIbiPayload(I3C_PrivData* pd, uint8_t* buf, uint8_t numbytes)
{
    LOG("slaveModeReadIbiPayload(pd=%p, buf=%p, numbytes=0x%02x)", pd, buf, numbytes);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_slaveModeReqFlowControl(I3C_PrivData* pd, I3C_FlowControlMode mode)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (
        (mode != I3C_NACK_NXT_PW_DISABLE) &&
        (mode != I3C_NACK_NXT_PR_DISABLE)
    )
    {
        return CDN_EINVAL;
    }


    return expectedRet;
}


void API_TEST_printargs_slaveModeReqFlowControl(I3C_PrivData* pd, I3C_FlowControlMode mode)
{
    LOG("slaveModeReqFlowControl(pd=%p, mode=%u)", pd, mode);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_slaveModeReadApbRo(I3C_PrivData* pd, uint16_t idx, uint8_t* val)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;




    return expectedRet;
}


void API_TEST_printargs_slaveModeReadApbRo(I3C_PrivData* pd, uint16_t idx, uint8_t* val)
{
    LOG("slaveModeReadApbRo(pd=%p, idx=0x%04x, val=%p)", pd, idx, val);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_slaveModeReadApbRw(I3C_PrivData* pd, uint16_t idx, uint8_t* val)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;




    return expectedRet;
}


void API_TEST_printargs_slaveModeReadApbRw(I3C_PrivData* pd, uint16_t idx, uint8_t* val)
{
    LOG("slaveModeReadApbRw(pd=%p, idx=0x%04x, val=%p)", pd, idx, val);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_slaveModeWriteApbRw(I3C_PrivData* pd, uint16_t idx, uint8_t val)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;





    return expectedRet;
}


void API_TEST_printargs_slaveModeWriteApbRw(I3C_PrivData* pd, uint16_t idx, uint8_t val)
{
    LOG("slaveModeWriteApbRw(pd=%p, idx=0x%04x, val=0x%02x)", pd, idx, val);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_slaveModeReadGpo(I3C_PrivData* pd, uint16_t idx, uint8_t* val)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;




    return expectedRet;
}


void API_TEST_printargs_slaveModeReadGpo(I3C_PrivData* pd, uint16_t idx, uint8_t* val)
{
    LOG("slaveModeReadGpo(pd=%p, idx=0x%04x, val=%p)", pd, idx, val);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_slaveModeReadGpi(I3C_PrivData* pd, uint16_t idx, uint8_t* val)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;




    return expectedRet;
}


void API_TEST_printargs_slaveModeReadGpi(I3C_PrivData* pd, uint16_t idx, uint8_t* val)
{
    LOG("slaveModeReadGpi(pd=%p, idx=0x%04x, val=%p)", pd, idx, val);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_slaveModeReadMWL(I3C_PrivData* pd, uint16_t* maxWriteLength)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;




    return expectedRet;
}


void API_TEST_printargs_slaveModeReadMWL(I3C_PrivData* pd, uint16_t* maxWriteLength)
{
    LOG("slaveModeReadMWL(pd=%p, maxWriteLength=%p)", pd, maxWriteLength);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_slaveModeReadMRL(I3C_PrivData* pd, uint16_t* maxReadLength, uint8_t* ibiPayloadSize)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;





    return expectedRet;
}


void API_TEST_printargs_slaveModeReadMRL(I3C_PrivData* pd, uint16_t* maxReadLength, uint8_t* ibiPayloadSize)
{
    LOG("slaveModeReadMRL(pd=%p, maxReadLength=%p, ibiPayloadSize=%p)", pd, maxReadLength, ibiPayloadSize);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_getFifoFillLvl(I3C_PrivData* pd, uint16_t* fillLvl_tx, uint16_t* fillLvl_rx)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;





    return expectedRet;
}


void API_TEST_printargs_getFifoFillLvl(I3C_PrivData* pd, uint16_t* fillLvl_tx, uint16_t* fillLvl_rx)
{
    LOG("getFifoFillLvl(pd=%p, fillLvl_tx=%p, fillLvl_rx=%p)", pd, fillLvl_tx, fillLvl_rx);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_setSdrFifoFlush(I3C_PrivData* pd, bool flush_tx, bool flush_rx)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;





    return expectedRet;
}


void API_TEST_printargs_setSdrFifoFlush(I3C_PrivData* pd, bool flush_tx, bool flush_rx)
{
    LOG("setSdrFifoFlush(pd=%p, flush_tx=0x%x, flush_rx=0x%x)", pd, flush_tx, flush_rx);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_slaveGetIbiStatus(I3C_PrivData* pd, uint8_t* ibi_stat, uint8_t* hj_stat, uint8_t* mr_stat)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;






    return expectedRet;
}


void API_TEST_printargs_slaveGetIbiStatus(I3C_PrivData* pd, uint8_t* ibi_stat, uint8_t* hj_stat, uint8_t* mr_stat)
{
    LOG("slaveGetIbiStatus(pd=%p, ibi_stat=%p, hj_stat=%p, mr_stat=%p)", pd, ibi_stat, hj_stat, mr_stat);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_expected_getAsfInfo(I3C_PrivData* pd, I3C_AsfInfo* asf_info)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;

    if (API_TEST_verify_I3C_AsfInfo(asf_info) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_getAsfInfo(I3C_PrivData* pd, I3C_AsfInfo* asf_info)
{
    LOG("getAsfInfo(pd=%p, asf_info=%p)", pd, asf_info);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
    LOG("struct parameter asf_info (%p):", asf_info);
    API_TEST_printstruct_I3C_AsfInfo(asf_info, "asf_info");
}


uint32_t API_TEST_expected_checkOperationMode(const I3C_PrivData* pd, I3C_OperationMode* opMode)
{
    uint32_t expectedRet = CDN_EOK;

    if (API_TEST_verify_I3C_PrivData(pd) == CDN_EINVAL)
        return CDN_EINVAL;



    return expectedRet;
}


void API_TEST_printargs_checkOperationMode(const I3C_PrivData* pd, I3C_OperationMode* opMode)
{
    LOG("checkOperationMode(pd=%p, opMode=%p)", pd, opMode);
    LOG("struct parameter pd (%p):", pd);
    API_TEST_printstruct_I3C_PrivData(pd, "pd");
}


uint32_t API_TEST_nullptr_probe(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    const I3C_Config config = { 0 };
    I3C_SysReq sysReq = { 0 };

    /* Check the function pointer first */
    if (obj->probe == NULL)
    {
        LOG("probe: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter config */
    ret = obj->probe(NULL, &sysReq);
    if (ret != EINVAL)
    {
        LOG("failed on parameter config, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter sysReq */
    ret = obj->probe(&config, NULL);
    if (ret != EINVAL)
    {
        LOG("failed on parameter sysReq, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_init(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    const I3C_Config config = { 0 };
    const I3C_Callbacks callbacks = { 0 };

    /* Check the function pointer first */
    if (obj->init == NULL)
    {
        LOG("init: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->init(NULL, &config, &callbacks);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter config */
    ret = obj->init(&pd, NULL, &callbacks);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter config, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter callbacks */
    ret = obj->init(&pd, &config, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter callbacks, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_isr(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };

    /* Check the function pointer first */
    if (obj->isr == NULL)
    {
        LOG("isr: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->isr(NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_start(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };

    /* Check the function pointer first */
    if (obj->start == NULL)
    {
        LOG("start: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->start(NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_stop(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };

    /* Check the function pointer first */
    if (obj->stop == NULL)
    {
        LOG("stop: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->stop(NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_destroy(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };

    /* Check the function pointer first */
    if (obj->destroy == NULL)
    {
        LOG("destroy: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->destroy(NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_enableCore(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };

    /* Check the function pointer first */
    if (obj->enableCore == NULL)
    {
        LOG("enableCore: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->enableCore(NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_disableCore(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };

    /* Check the function pointer first */
    if (obj->disableCore == NULL)
    {
        LOG("disableCore: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->disableCore(NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_setBusMode(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    I3C_BusMode mode = 0;

    /* Check the function pointer first */
    if (obj->setBusMode == NULL)
    {
        LOG("setBusMode: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->setBusMode(NULL, mode);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_getBusMode(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    I3C_BusMode mode = 0;

    /* Check the function pointer first */
    if (obj->getBusMode == NULL)
    {
        LOG("getBusMode: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->getBusMode(NULL, &mode);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter mode */
    ret = obj->getBusMode(&pd, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter mode, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_setBcr(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t bcr = 0;
    uint8_t devId = 0;

    /* Check the function pointer first */
    if (obj->setBcr == NULL)
    {
        LOG("setBcr: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->setBcr(NULL, bcr, devId);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_setDcr(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t dcr = 0;
    uint8_t devId = 0;

    /* Check the function pointer first */
    if (obj->setDcr == NULL)
    {
        LOG("setDcr: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->setDcr(NULL, dcr, devId);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_setPid(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    const uint8_t pid = 0;
    uint8_t devId = 0;

    /* Check the function pointer first */
    if (obj->setPid == NULL)
    {
        LOG("setPid: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->setPid(NULL, &pid, devId);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter pid */
    ret = obj->setPid(&pd, NULL, devId);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pid, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_configureDevices(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    I3C_DeviceDescriptor devs = { 0 };
    uint8_t numDevs = 0;

    /* Check the function pointer first */
    if (obj->configureDevices == NULL)
    {
        LOG("configureDevices: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->configureDevices(NULL, &devs, numDevs);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter devs */
    ret = obj->configureDevices(&pd, NULL, numDevs);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter devs, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_configureDevice(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    I3C_DeviceDescriptor dev = { 0 };
    uint8_t index = 0;

    /* Check the function pointer first */
    if (obj->configureDevice == NULL)
    {
        LOG("configureDevice: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->configureDevice(NULL, &dev, index);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter dev */
    ret = obj->configureDevice(&pd, NULL, index);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter dev, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_configurePrescalers(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    const I3C_Config config = { 0 };

    /* Check the function pointer first */
    if (obj->configurePrescalers == NULL)
    {
        LOG("configurePrescalers: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->configurePrescalers(NULL, &config);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter config */
    ret = obj->configurePrescalers(&pd, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter config, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_clearRrOfDevice(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t device_no = 0;

    /* Check the function pointer first */
    if (obj->clearRrOfDevice == NULL)
    {
        LOG("clearRrOfDevice: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->clearRrOfDevice(NULL, device_no);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_getNewDevices(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint16_t hj_devices = 0;

    /* Check the function pointer first */
    if (obj->getNewDevices == NULL)
    {
        LOG("getNewDevices: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->getNewDevices(NULL, &hj_devices);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter hj_devices */
    ret = obj->getNewDevices(&pd, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter hj_devices, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_configureInterrupts(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    const I3C_InterruptConfig interruptConfig = { 0 };

    /* Check the function pointer first */
    if (obj->configureInterrupts == NULL)
    {
        LOG("configureInterrupts: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->configureInterrupts(NULL, &interruptConfig);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter interruptConfig */
    ret = obj->configureInterrupts(&pd, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter interruptConfig, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_configureThresholds(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    const I3C_ThresholdConfig thresholdConfig = { 0 };

    /* Check the function pointer first */
    if (obj->configureThresholds == NULL)
    {
        LOG("configureThresholds: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->configureThresholds(NULL, &thresholdConfig);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter thresholdConfig */
    ret = obj->configureThresholds(&pd, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter thresholdConfig, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdExec(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };

    /* Check the function pointer first */
    if (obj->cmdExec == NULL)
    {
        LOG("cmdExec: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdExec(NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdExecImmediate(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };

    /* Check the function pointer first */
    if (obj->cmdExecImmediate == NULL)
    {
        LOG("cmdExecImmediate: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdExecImmediate(NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_enableMcs(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };

    /* Check the function pointer first */
    if (obj->enableMcs == NULL)
    {
        LOG("enableMcs: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->enableMcs(NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_disableMcs(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };

    /* Check the function pointer first */
    if (obj->disableMcs == NULL)
    {
        LOG("disableMcs: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->disableMcs(NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_manualCommandStart(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };

    /* Check the function pointer first */
    if (obj->manualCommandStart == NULL)
    {
        LOG("manualCommandStart: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->manualCommandStart(NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdCount(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    const I3C_PrivData pd = { 0 };

    /* Check the function pointer first */
    if (obj->cmdCount == NULL)
    {
        LOG("cmdCount: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdCount(NULL);
    if (ret != 0)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdMaxCount(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    const I3C_PrivData pd = { 0 };

    /* Check the function pointer first */
    if (obj->cmdMaxCount == NULL)
    {
        LOG("cmdMaxCount: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdMaxCount(NULL);
    if (ret != 0)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdClearAll(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };

    /* Check the function pointer first */
    if (obj->cmdClearAll == NULL)
    {
        LOG("cmdClearAll: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdClearAll(NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_devPrint(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    const I3C_PrivData pd = { 0 };

    /* Check the function pointer first */
    if (obj->devPrint == NULL)
    {
        LOG("devPrint: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->devPrint(NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_enableTc(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };

    /* Check the function pointer first */
    if (obj->enableTc == NULL)
    {
        LOG("enableTc: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->enableTc(NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddPrivWrite(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint16_t da = 0;
    const I3C_CsrData csr_data = { 0 };
    const I3C_PayloadData payload_data = { 0 };
    I3C_TransmitMode xmitMmode = 0;

    /* Check the function pointer first */
    if (obj->cmdAddPrivWrite == NULL)
    {
        LOG("cmdAddPrivWrite: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddPrivWrite(NULL, da, &csr_data, &payload_data, xmitMmode);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter csr_data */
    ret = obj->cmdAddPrivWrite(&pd, da, NULL, &payload_data, xmitMmode);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter csr_data, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter payload_data */
    ret = obj->cmdAddPrivWrite(&pd, da, &csr_data, NULL, xmitMmode);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter payload_data, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddPrivRead(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint16_t da = 0;
    const I3C_CsrData csr_data = { 0 };
    const I3C_PayloadData payload_data = { 0 };
    I3C_TransmitMode xmitMmode = 0;

    /* Check the function pointer first */
    if (obj->cmdAddPrivRead == NULL)
    {
        LOG("cmdAddPrivRead: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddPrivRead(NULL, da, &csr_data, &payload_data, xmitMmode);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter csr_data */
    ret = obj->cmdAddPrivRead(&pd, da, NULL, &payload_data, xmitMmode);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter csr_data, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter payload_data */
    ret = obj->cmdAddPrivRead(&pd, da, &csr_data, NULL, xmitMmode);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter payload_data, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddPrivI2CWrite(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint16_t da = 0;
    uint8_t payload = 0;
    uint16_t payloadSize = 0;

    /* Check the function pointer first */
    if (obj->cmdAddPrivI2CWrite == NULL)
    {
        LOG("cmdAddPrivI2CWrite: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddPrivI2CWrite(NULL, da, &payload, payloadSize);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter payload */
    ret = obj->cmdAddPrivI2CWrite(&pd, da, NULL, payloadSize);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter payload, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddPrivI2CRead(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint16_t da = 0;
    uint8_t payload = 0;
    uint16_t payloadSize = 0;

    /* Check the function pointer first */
    if (obj->cmdAddPrivI2CRead == NULL)
    {
        LOG("cmdAddPrivI2CRead: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddPrivI2CRead(NULL, da, &payload, payloadSize);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter payload */
    ret = obj->cmdAddPrivI2CRead(&pd, da, NULL, payloadSize);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter payload, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddDdrWrite(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t da = 0;
    uint8_t command = 0;
    I3C_HdrMode hdrMode = 0;
    I3C_PayloadData payload_data = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddDdrWrite == NULL)
    {
        LOG("cmdAddDdrWrite: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddDdrWrite(NULL, da, command, hdrMode, &payload_data);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter payload_data */
    ret = obj->cmdAddDdrWrite(&pd, da, command, hdrMode, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter payload_data, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddDdrRead(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t da = 0;
    uint8_t command = 0;
    I3C_HdrMode hdrMode = 0;
    I3C_PayloadData payload_data = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddDdrRead == NULL)
    {
        LOG("cmdAddDdrRead: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddDdrRead(NULL, da, command, hdrMode, &payload_data);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter payload_data */
    ret = obj->cmdAddDdrRead(&pd, da, command, hdrMode, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter payload_data, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddSetSlaveEvents(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t eventsMask = 0;
    bool enable = 0;
    uint8_t devAddr = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddSetSlaveEvents == NULL)
    {
        LOG("cmdAddSetSlaveEvents: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddSetSlaveEvents(NULL, eventsMask, enable, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddSetSlaveEvents(&pd, eventsMask, enable, devAddr, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddEnterActivityState(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    I3C_ActivityState state = 0;
    uint8_t devAddr = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddEnterActivityState == NULL)
    {
        LOG("cmdAddEnterActivityState: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddEnterActivityState(NULL, state, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddEnterActivityState(&pd, state, devAddr, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddResetDaa(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t devAddr = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddResetDaa == NULL)
    {
        LOG("cmdAddResetDaa: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddResetDaa(NULL, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddResetDaa(&pd, devAddr, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddEnterDaa(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddEnterDaa == NULL)
    {
        LOG("cmdAddEnterDaa: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddEnterDaa(NULL, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddEnterDaa(&pd, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddSetMaxWriteLength(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint16_t length = 0;
    uint8_t devAddr = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddSetMaxWriteLength == NULL)
    {
        LOG("cmdAddSetMaxWriteLength: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddSetMaxWriteLength(NULL, length, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddSetMaxWriteLength(&pd, length, devAddr, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddGetMaxWriteLength(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint16_t length = 0;
    uint8_t devAddr = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddGetMaxWriteLength == NULL)
    {
        LOG("cmdAddGetMaxWriteLength: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddGetMaxWriteLength(NULL, &length, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter length */
    ret = obj->cmdAddGetMaxWriteLength(&pd, NULL, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter length, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddGetMaxWriteLength(&pd, &length, devAddr, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddSetMaxReadLength(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    I3C_MaxReadLength max_read_length = { 0 };
    uint8_t length_size = 0;
    uint8_t devAddr = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddSetMaxReadLength == NULL)
    {
        LOG("cmdAddSetMaxReadLength: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddSetMaxReadLength(NULL, max_read_length, length_size, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddSetMaxReadLength(&pd, max_read_length, length_size, devAddr, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddGetMaxReadLength(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    I3C_MaxReadLength max_read_length = { 0 };
    uint8_t length_size = 0;
    uint8_t devAddr = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddGetMaxReadLength == NULL)
    {
        LOG("cmdAddGetMaxReadLength: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddGetMaxReadLength(NULL, &max_read_length, length_size, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter max_read_length */
    ret = obj->cmdAddGetMaxReadLength(&pd, NULL, length_size, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter max_read_length, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddGetMaxReadLength(&pd, &max_read_length, length_size, devAddr, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddGetMaxDataSpeed(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    I3C_MaxDataSpeed max_data_speed = { 0 };
    uint8_t devAddr = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddGetMaxDataSpeed == NULL)
    {
        LOG("cmdAddGetMaxDataSpeed: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddGetMaxDataSpeed(NULL, &max_data_speed, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter max_data_speed */
    ret = obj->cmdAddGetMaxDataSpeed(&pd, NULL, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter max_data_speed, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddGetMaxDataSpeed(&pd, &max_data_speed, devAddr, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_getSlavesList(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    const I3C_PrivData pd = { 0 };
    I3C_SlaveDescriptors slaveDescs = { 0 };

    /* Check the function pointer first */
    if (obj->getSlavesList == NULL)
    {
        LOG("getSlavesList: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->getSlavesList(NULL, &slaveDescs);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter slaveDescs */
    ret = obj->getSlavesList(&pd, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter slaveDescs, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddDefineSlavesList(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    I3C_SlaveDescriptors slaveDescs = { 0 };
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddDefineSlavesList == NULL)
    {
        LOG("cmdAddDefineSlavesList: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddDefineSlavesList(NULL, &slaveDescs, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter slaveDescs */
    ret = obj->cmdAddDefineSlavesList(&pd, NULL, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter slaveDescs, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddDefineSlavesList(&pd, &slaveDescs, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddEnterTestMode(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t mode = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddEnterTestMode == NULL)
    {
        LOG("cmdAddEnterTestMode: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddEnterTestMode(NULL, mode, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddEnterTestMode(&pd, mode, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddSetBuscon(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t context_buf = 0;
    uint8_t length_size = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddSetBuscon == NULL)
    {
        LOG("cmdAddSetBuscon: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddSetBuscon(NULL, &context_buf, length_size, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter context_buf */
    ret = obj->cmdAddSetBuscon(&pd, NULL, length_size, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter context_buf, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddSetBuscon(&pd, &context_buf, length_size, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddEnterHdrMode(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    I3C_HdrMode mode = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddEnterHdrMode == NULL)
    {
        LOG("cmdAddEnterHdrMode: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddEnterHdrMode(NULL, mode, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddEnterHdrMode(&pd, mode, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddSetAaSa(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddSetAaSa == NULL)
    {
        LOG("cmdAddSetAaSa: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddSetAaSa(NULL, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddSetAaSa(&pd, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdSetDaFromSa(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t address = 0;
    uint8_t devAddr = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdSetDaFromSa == NULL)
    {
        LOG("cmdSetDaFromSa: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdSetDaFromSa(NULL, address, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdSetDaFromSa(&pd, address, devAddr, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddSetNewDa(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t da = 0;
    uint8_t devAddr = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddSetNewDa == NULL)
    {
        LOG("cmdAddSetNewDa: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddSetNewDa(NULL, da, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddSetNewDa(&pd, da, devAddr, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddSetRstAct(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t DefiningByte = 0;
    uint8_t devAddr = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddSetRstAct == NULL)
    {
        LOG("cmdAddSetRstAct: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddSetRstAct(NULL, DefiningByte, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddSetRstAct(&pd, DefiningByte, devAddr, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddSetXTime(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t SubCommandByte = 0;
    uint8_t devAddr = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddSetXTime == NULL)
    {
        LOG("cmdAddSetXTime: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddSetXTime(NULL, SubCommandByte, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddSetXTime(&pd, SubCommandByte, devAddr, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddSetGroupAddr(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t grpaddr = 0;
    uint8_t devAddr = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddSetGroupAddr == NULL)
    {
        LOG("cmdAddSetGroupAddr: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddSetGroupAddr(NULL, grpaddr, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddSetGroupAddr(&pd, grpaddr, devAddr, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddDefineGroupList(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    I3C_GroupDescriptors groupDescs = { 0 };
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddDefineGroupList == NULL)
    {
        LOG("cmdAddDefineGroupList: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddDefineGroupList(NULL, &groupDescs, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter groupDescs */
    ret = obj->cmdAddDefineGroupList(&pd, NULL, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter groupDescs, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddDefineGroupList(&pd, &groupDescs, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddResetGrpa(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t grpAddr = 0;
    uint8_t devAddr = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddResetGrpa == NULL)
    {
        LOG("cmdAddResetGrpa: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddResetGrpa(NULL, grpAddr, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddResetGrpa(&pd, grpAddr, devAddr, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddGetProvisionalId(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t buff = 0;
    uint8_t devAddr = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddGetProvisionalId == NULL)
    {
        LOG("cmdAddGetProvisionalId: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddGetProvisionalId(NULL, &buff, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter buff */
    ret = obj->cmdAddGetProvisionalId(&pd, NULL, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter buff, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddGetProvisionalId(&pd, &buff, devAddr, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddGetBcr(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t bcr = 0;
    uint8_t devAddr = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddGetBcr == NULL)
    {
        LOG("cmdAddGetBcr: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddGetBcr(NULL, &bcr, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter bcr */
    ret = obj->cmdAddGetBcr(&pd, NULL, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter bcr, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddGetBcr(&pd, &bcr, devAddr, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddGetDcr(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t dcr = 0;
    uint8_t devAddr = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddGetDcr == NULL)
    {
        LOG("cmdAddGetDcr: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddGetDcr(NULL, &dcr, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter dcr */
    ret = obj->cmdAddGetDcr(&pd, NULL, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter dcr, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddGetDcr(&pd, &dcr, devAddr, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddGetStatus(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint16_t status = 0;
    uint8_t devAddr = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddGetStatus == NULL)
    {
        LOG("cmdAddGetStatus: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddGetStatus(NULL, &status, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter status */
    ret = obj->cmdAddGetStatus(&pd, NULL, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter status, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddGetStatus(&pd, &status, devAddr, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddGetAccMst(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t recData = 0;
    uint8_t devAddr = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddGetAccMst == NULL)
    {
        LOG("cmdAddGetAccMst: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddGetAccMst(NULL, &recData, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter recData */
    ret = obj->cmdAddGetAccMst(&pd, NULL, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter recData, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddGetAccMst(&pd, &recData, devAddr, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_cmdAddGetXTime(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    I3C_Tcam0Data tCamData = { 0 };
    uint8_t devAddr = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->cmdAddGetXTime == NULL)
    {
        LOG("cmdAddGetXTime: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->cmdAddGetXTime(NULL, &tCamData, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tCamData */
    ret = obj->cmdAddGetXTime(&pd, NULL, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tCamData, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->cmdAddGetXTime(&pd, &tCamData, devAddr, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_CmdSetNCAMode(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t mode = 0;
    uint8_t devAddr = 0;
    const I3C_TransmissionParameters tx_params = { 0 };

    /* Check the function pointer first */
    if (obj->CmdSetNCAMode == NULL)
    {
        LOG("CmdSetNCAMode: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->CmdSetNCAMode(NULL, mode, devAddr, &tx_params);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter tx_params */
    ret = obj->CmdSetNCAMode(&pd, mode, devAddr, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter tx_params, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_ibiConfigureDevices(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    const I3C_PrivData pd = { 0 };
    const I3C_IbiSirConfiguration ibi_sir_cfg = { 0 };
    uint32_t num_sir_cfgs = 0;

    /* Check the function pointer first */
    if (obj->ibiConfigureDevices == NULL)
    {
        LOG("ibiConfigureDevices: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->ibiConfigureDevices(NULL, &ibi_sir_cfg, num_sir_cfgs);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter ibi_sir_cfg */
    ret = obj->ibiConfigureDevices(&pd, NULL, num_sir_cfgs);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter ibi_sir_cfg, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_ibiModifyDeviceConfig(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    const I3C_PrivData pd = { 0 };
    const I3C_IbiSirConfiguration ibi_sir_cfg = { 0 };
    uint8_t da = 0;

    /* Check the function pointer first */
    if (obj->ibiModifyDeviceConfig == NULL)
    {
        LOG("ibiModifyDeviceConfig: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->ibiModifyDeviceConfig(NULL, &ibi_sir_cfg, da);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter ibi_sir_cfg */
    ret = obj->ibiModifyDeviceConfig(&pd, NULL, da);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter ibi_sir_cfg, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_ibiGetAddressOfIssuer(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };

    /* Check the function pointer first */
    if (obj->ibiGetAddressOfIssuer == NULL)
    {
        LOG("ibiGetAddressOfIssuer: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->ibiGetAddressOfIssuer(NULL);
    if (ret != 0)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_ibiGetData(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t buf = 0;
    uint16_t payload_size = 0;

    /* Check the function pointer first */
    if (obj->ibiGetData == NULL)
    {
        LOG("ibiGetData: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->ibiGetData(NULL, &buf, payload_size);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter buf */
    ret = obj->ibiGetData(&pd, NULL, payload_size);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter buf, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_hjConfigureResponse(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    I3C_HjResponse hj_response = 0;
    I3C_HjDisableSet hj_disable_set = 0;

    /* Check the function pointer first */
    if (obj->hjConfigureResponse == NULL)
    {
        LOG("hjConfigureResponse: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->hjConfigureResponse(NULL, hj_response, hj_disable_set);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_configureSlaveInterrupts(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    const I3C_SlaveInterruptConfig slaveInterruptConfig = { 0 };

    /* Check the function pointer first */
    if (obj->configureSlaveInterrupts == NULL)
    {
        LOG("configureSlaveInterrupts: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->configureSlaveInterrupts(NULL, &slaveInterruptConfig);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter slaveInterruptConfig */
    ret = obj->configureSlaveInterrupts(&pd, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter slaveInterruptConfig, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_slaveModeConfigure(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    const I3C_SlaveInterruptConfig slaveInterruptConfig = { 0 };

    /* Check the function pointer first */
    if (obj->slaveModeConfigure == NULL)
    {
        LOG("slaveModeConfigure: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->slaveModeConfigure(NULL, &slaveInterruptConfig);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter slaveInterruptConfig */
    ret = obj->slaveModeConfigure(&pd, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter slaveInterruptConfig, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_slaveModeReqSdrRead(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t buf = 0;
    uint16_t num_bytes = 0;

    /* Check the function pointer first */
    if (obj->slaveModeReqSdrRead == NULL)
    {
        LOG("slaveModeReqSdrRead: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->slaveModeReqSdrRead(NULL, &buf, num_bytes);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter buf */
    ret = obj->slaveModeReqSdrRead(&pd, NULL, num_bytes);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter buf, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_slaveModeReqSdrWrite(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    const uint8_t buf = 0;
    uint16_t num_bytes = 0;

    /* Check the function pointer first */
    if (obj->slaveModeReqSdrWrite == NULL)
    {
        LOG("slaveModeReqSdrWrite: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->slaveModeReqSdrWrite(NULL, &buf, num_bytes);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter buf */
    ret = obj->slaveModeReqSdrWrite(&pd, NULL, num_bytes);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter buf, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_slaveModeReqDdrRead(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint16_t buf = 0;
    uint16_t num_words = 0;

    /* Check the function pointer first */
    if (obj->slaveModeReqDdrRead == NULL)
    {
        LOG("slaveModeReqDdrRead: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->slaveModeReqDdrRead(NULL, &buf, num_words);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter buf */
    ret = obj->slaveModeReqDdrRead(&pd, NULL, num_words);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter buf, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_slaveModeReqDdrWrite(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    const uint16_t buf_in = 0;
    uint16_t num_words_in = 0;

    /* Check the function pointer first */
    if (obj->slaveModeReqDdrWrite == NULL)
    {
        LOG("slaveModeReqDdrWrite: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->slaveModeReqDdrWrite(NULL, &buf_in, num_words_in);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter buf_in */
    ret = obj->slaveModeReqDdrWrite(&pd, NULL, num_words_in);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter buf_in, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_slaveModeRequestHotJoin(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };

    /* Check the function pointer first */
    if (obj->slaveModeRequestHotJoin == NULL)
    {
        LOG("slaveModeRequestHotJoin: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->slaveModeRequestHotJoin(NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_slaveModeMastershipReq(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };

    /* Check the function pointer first */
    if (obj->slaveModeMastershipReq == NULL)
    {
        LOG("slaveModeMastershipReq: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->slaveModeMastershipReq(NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_slaveModeRequestIbi(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t tCam0Event = 0;
    bool ibiTCam0 = 0;

    /* Check the function pointer first */
    if (obj->slaveModeRequestIbi == NULL)
    {
        LOG("slaveModeRequestIbi: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->slaveModeRequestIbi(NULL, tCam0Event, ibiTCam0);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_slaveModeWriteIbiPayload(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    const uint8_t buf = 0;
    uint8_t numbytes = 0;

    /* Check the function pointer first */
    if (obj->slaveModeWriteIbiPayload == NULL)
    {
        LOG("slaveModeWriteIbiPayload: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->slaveModeWriteIbiPayload(NULL, &buf, numbytes);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter buf */
    ret = obj->slaveModeWriteIbiPayload(&pd, NULL, numbytes);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter buf, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_slaveModeReadIbiPayload(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t buf = 0;
    uint8_t numbytes = 0;

    /* Check the function pointer first */
    if (obj->slaveModeReadIbiPayload == NULL)
    {
        LOG("slaveModeReadIbiPayload: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->slaveModeReadIbiPayload(NULL, &buf, numbytes);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter buf */
    ret = obj->slaveModeReadIbiPayload(&pd, NULL, numbytes);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter buf, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_slaveModeReqFlowControl(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    I3C_FlowControlMode mode = 0;

    /* Check the function pointer first */
    if (obj->slaveModeReqFlowControl == NULL)
    {
        LOG("slaveModeReqFlowControl: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->slaveModeReqFlowControl(NULL, mode);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_slaveModeReadApbRo(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint16_t idx = 0;
    uint8_t val = 0;

    /* Check the function pointer first */
    if (obj->slaveModeReadApbRo == NULL)
    {
        LOG("slaveModeReadApbRo: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->slaveModeReadApbRo(NULL, idx, &val);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter val */
    ret = obj->slaveModeReadApbRo(&pd, idx, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter val, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_slaveModeReadApbRw(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint16_t idx = 0;
    uint8_t val = 0;

    /* Check the function pointer first */
    if (obj->slaveModeReadApbRw == NULL)
    {
        LOG("slaveModeReadApbRw: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->slaveModeReadApbRw(NULL, idx, &val);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter val */
    ret = obj->slaveModeReadApbRw(&pd, idx, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter val, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_slaveModeWriteApbRw(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint16_t idx = 0;
    uint8_t val = 0;

    /* Check the function pointer first */
    if (obj->slaveModeWriteApbRw == NULL)
    {
        LOG("slaveModeWriteApbRw: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->slaveModeWriteApbRw(NULL, idx, val);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_slaveModeReadGpo(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint16_t idx = 0;
    uint8_t val = 0;

    /* Check the function pointer first */
    if (obj->slaveModeReadGpo == NULL)
    {
        LOG("slaveModeReadGpo: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->slaveModeReadGpo(NULL, idx, &val);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter val */
    ret = obj->slaveModeReadGpo(&pd, idx, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter val, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_slaveModeReadGpi(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint16_t idx = 0;
    uint8_t val = 0;

    /* Check the function pointer first */
    if (obj->slaveModeReadGpi == NULL)
    {
        LOG("slaveModeReadGpi: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->slaveModeReadGpi(NULL, idx, &val);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter val */
    ret = obj->slaveModeReadGpi(&pd, idx, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter val, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_slaveModeReadMWL(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint16_t maxWriteLength = 0;

    /* Check the function pointer first */
    if (obj->slaveModeReadMWL == NULL)
    {
        LOG("slaveModeReadMWL: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->slaveModeReadMWL(NULL, &maxWriteLength);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter maxWriteLength */
    ret = obj->slaveModeReadMWL(&pd, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter maxWriteLength, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_slaveModeReadMRL(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint16_t maxReadLength = 0;
    uint8_t ibiPayloadSize = 0;

    /* Check the function pointer first */
    if (obj->slaveModeReadMRL == NULL)
    {
        LOG("slaveModeReadMRL: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->slaveModeReadMRL(NULL, &maxReadLength, &ibiPayloadSize);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter maxReadLength */
    ret = obj->slaveModeReadMRL(&pd, NULL, &ibiPayloadSize);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter maxReadLength, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter ibiPayloadSize */
    ret = obj->slaveModeReadMRL(&pd, &maxReadLength, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter ibiPayloadSize, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_getFifoFillLvl(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint16_t fillLvl_tx = 0;
    uint16_t fillLvl_rx = 0;

    /* Check the function pointer first */
    if (obj->getFifoFillLvl == NULL)
    {
        LOG("getFifoFillLvl: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->getFifoFillLvl(NULL, &fillLvl_tx, &fillLvl_rx);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter fillLvl_tx */
    ret = obj->getFifoFillLvl(&pd, NULL, &fillLvl_rx);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter fillLvl_tx, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter fillLvl_rx */
    ret = obj->getFifoFillLvl(&pd, &fillLvl_tx, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter fillLvl_rx, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_setSdrFifoFlush(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    bool flush_tx = 0;
    bool flush_rx = 0;

    /* Check the function pointer first */
    if (obj->setSdrFifoFlush == NULL)
    {
        LOG("setSdrFifoFlush: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->setSdrFifoFlush(NULL, flush_tx, flush_rx);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_slaveGetIbiStatus(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    uint8_t ibi_stat = 0;
    uint8_t hj_stat = 0;
    uint8_t mr_stat = 0;

    /* Check the function pointer first */
    if (obj->slaveGetIbiStatus == NULL)
    {
        LOG("slaveGetIbiStatus: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->slaveGetIbiStatus(NULL, &ibi_stat, &hj_stat, &mr_stat);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter ibi_stat */
    ret = obj->slaveGetIbiStatus(&pd, NULL, &hj_stat, &mr_stat);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter ibi_stat, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter hj_stat */
    ret = obj->slaveGetIbiStatus(&pd, &ibi_stat, NULL, &mr_stat);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter hj_stat, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter mr_stat */
    ret = obj->slaveGetIbiStatus(&pd, &ibi_stat, &hj_stat, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter mr_stat, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_getAsfInfo(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    I3C_PrivData pd = { 0 };
    I3C_AsfInfo asf_info = { 0 };

    /* Check the function pointer first */
    if (obj->getAsfInfo == NULL)
    {
        LOG("getAsfInfo: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->getAsfInfo(NULL, &asf_info);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter asf_info */
    ret = obj->getAsfInfo(&pd, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter asf_info, result: %i", ret);
        return FAIL;
    }
    return PASS;
}



uint32_t API_TEST_nullptr_checkOperationMode(I3C_OBJ *obj, void *__unusedPd)
{
    uint32_t ret;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Prepare valid parameters: */
    const I3C_PrivData pd = { 0 };
    I3C_OperationMode opMode = 0;

    /* Check the function pointer first */
    if (obj->checkOperationMode == NULL)
    {
        LOG("checkOperationMode: null function pointer, skipping");
        return NOTSUP;
    }


    /* Testing for null on parameter pd */
    ret = obj->checkOperationMode(NULL, &opMode);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter pd, result: %i", ret);
        return FAIL;
    }
    /* Testing for null on parameter opMode */
    ret = obj->checkOperationMode(&pd, NULL);
    if (ret != CDN_EINVAL)
    {
        LOG("failed on parameter opMode, result: %i", ret);
        return FAIL;
    }
    return PASS;
}


static uint32_t API_TEST_ranges_probe(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->probe == NULL)
    {
        LOG("probe: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_config;
    I3C_Config config;

    for (idx_config = 0; idx_config < 96; idx_config++)
    {
        API_TEST_fill_I3C_Config(&config, idx_config);

        I3C_SysReq sysReq = { 0 };
        /* Check valid-fail conditions */
        if (config.regsBase != I3C_REGS_BASE)
        {
            LOG_FIRST("COMMENT: Core driver cannot check if register base address is correct.");
            return NOTSUP;
        }


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_probe(&config, &sysReq);


        if (expectedRet == EINVAL)
        {

            /* Call function */
            ret = obj->probe(&config, &sysReq);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("probe: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_probe(&config, &sysReq);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_init(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->init == NULL)
    {
        LOG("init: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t idx_config;
        I3C_Config config;

        for (idx_config = 0; idx_config < 96; idx_config++)
        {
            API_TEST_fill_I3C_Config(&config, idx_config);

            uint32_t idx_callbacks;
            I3C_Callbacks callbacks;

            for (idx_callbacks = 0; idx_callbacks < 96; idx_callbacks++)
            {
                API_TEST_fill_I3C_Callbacks(&callbacks, idx_callbacks);

                /* Check valid-fail conditions */
                if (config.regsBase != I3C_REGS_BASE)
                {
                    LOG_FIRST("COMMENT: Core driver cannot check if register base address is correct.");
                    return NOTSUP;
                }


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_init(&pd, &config, &callbacks);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->init(&pd, &config, &callbacks);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("init: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_init(&pd, &config, &callbacks);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_isr(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->isr == NULL)
    {
        LOG("isr: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        /* Check valid-fail conditions */
        if (true)
        {
            LOG_FIRST("COMMENT: disableCore requires running HW.");
            return NOTSUP;
        }


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_isr(&pd);


        if (expectedRet == CDN_EINVAL)
        {

            /* Call function */
            ret = obj->isr(&pd);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("isr: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_isr(&pd);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_start(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->start == NULL)
    {
        LOG("start: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        /* Check valid-fail conditions */
        if (true)
        {
            LOG_FIRST("COMMENT: disableCore requires running HW.");
            return NOTSUP;
        }


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_start(&pd);


        if (expectedRet == CDN_EINVAL)
        {

            /* Call function */
            ret = obj->start(&pd);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("start: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_start(&pd);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_stop(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->stop == NULL)
    {
        LOG("stop: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        /* Check valid-fail conditions */
        if (true)
        {
            LOG_FIRST("COMMENT: disableCore requires running HW.");
            return NOTSUP;
        }


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_stop(&pd);


        if (expectedRet == CDN_EINVAL)
        {

            /* Call function */
            ret = obj->stop(&pd);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("stop: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_stop(&pd);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_destroy(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->destroy == NULL)
    {
        LOG("destroy: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        /* Check valid-fail conditions */
        if (true)
        {
            LOG_FIRST("COMMENT: destroy requires running HW.");
            return NOTSUP;
        }


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_destroy(&pd);


        if (expectedRet == CDN_EINVAL)
        {

            /* Call function */
            ret = obj->destroy(&pd);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("destroy: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_destroy(&pd);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_enableCore(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->enableCore == NULL)
    {
        LOG("enableCore: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        /* Check valid-fail conditions */
        if (true)
        {
            LOG_FIRST("COMMENT: enableCore requires running HW.");
            return NOTSUP;
        }


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_enableCore(&pd);


        if (expectedRet == CDN_EINVAL)
        {

            /* Call function */
            ret = obj->enableCore(&pd);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("enableCore: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_enableCore(&pd);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_disableCore(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->disableCore == NULL)
    {
        LOG("disableCore: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        /* Check valid-fail conditions */
        if (true)
        {
            LOG_FIRST("COMMENT: disableCore requires running HW.");
            return NOTSUP;
        }


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_disableCore(&pd);


        if (expectedRet == CDN_EINVAL)
        {

            /* Call function */
            ret = obj->disableCore(&pd);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("disableCore: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_disableCore(&pd);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_setBusMode(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->setBusMode == NULL)
    {
        LOG("setBusMode: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_mode;

        for (loop_mode = 0; loop_mode < (96); loop_mode++)
        {
            I3C_BusMode mode = API_TEST_table_uint32_t[loop_mode];
            /* Check valid-fail conditions */
            if (true)
            {
                LOG_FIRST("COMMENT: disableCore requires running HW.");
                return NOTSUP;
            }


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_setBusMode(&pd, mode);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->setBusMode(&pd, mode);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("setBusMode: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_setBusMode(&pd, mode);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_getBusMode(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->getBusMode == NULL)
    {
        LOG("getBusMode: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        I3C_BusMode mode = 0;
        /* Check valid-fail conditions */
        if (true)
        {
            LOG_FIRST("COMMENT: disableCore requires running HW.");
            return NOTSUP;
        }


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_getBusMode(&pd, &mode);


        if (expectedRet == CDN_EINVAL)
        {

            /* Call function */
            ret = obj->getBusMode(&pd, &mode);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("getBusMode: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_getBusMode(&pd, &mode);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_setBcr(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->setBcr == NULL)
    {
        LOG("setBcr: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_bcr;

        for (loop_bcr = 0; loop_bcr < (24); loop_bcr++)
        {
            uint8_t bcr = API_TEST_table_uint8_t[loop_bcr];
            uint32_t loop_devId;

            for (loop_devId = 0; loop_devId < (24); loop_devId++)
            {
                uint8_t devId = API_TEST_table_uint8_t[loop_devId];
                /* Check valid-fail conditions */
                if (true)
                {
                    LOG_FIRST("COMMENT: disableCore requires running HW.");
                    return NOTSUP;
                }


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_setBcr(&pd, bcr, devId);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->setBcr(&pd, bcr, devId);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("setBcr: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_setBcr(&pd, bcr, devId);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_setDcr(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->setDcr == NULL)
    {
        LOG("setDcr: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_dcr;

        for (loop_dcr = 0; loop_dcr < (24); loop_dcr++)
        {
            uint8_t dcr = API_TEST_table_uint8_t[loop_dcr];
            uint32_t loop_devId;

            for (loop_devId = 0; loop_devId < (24); loop_devId++)
            {
                uint8_t devId = API_TEST_table_uint8_t[loop_devId];
                /* Check valid-fail conditions */
                if (true)
                {
                    LOG_FIRST("COMMENT: disableCore requires running HW.");
                    return NOTSUP;
                }


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_setDcr(&pd, dcr, devId);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->setDcr(&pd, dcr, devId);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("setDcr: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_setDcr(&pd, dcr, devId);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_setPid(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->setPid == NULL)
    {
        LOG("setPid: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        const uint8_t pid = 0;
        uint32_t loop_devId;

        for (loop_devId = 0; loop_devId < (24); loop_devId++)
        {
            uint8_t devId = API_TEST_table_uint8_t[loop_devId];
            /* Check valid-fail conditions */
            if (true)
            {
                LOG_FIRST("COMMENT: disableCore requires running HW.");
                return NOTSUP;
            }


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_setPid(&pd, &pid, devId);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->setPid(&pd, &pid, devId);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("setPid: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_setPid(&pd, &pid, devId);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_configureDevices(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->configureDevices == NULL)
    {
        LOG("configureDevices: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t idx_devs;
        I3C_DeviceDescriptor devs;

        for (idx_devs = 0; idx_devs < 96; idx_devs++)
        {
            API_TEST_fill_I3C_DeviceDescriptor(&devs, idx_devs);

            uint32_t loop_numDevs;

            for (loop_numDevs = 0; loop_numDevs < (24); loop_numDevs++)
            {
                uint8_t numDevs = API_TEST_table_uint8_t[loop_numDevs];
                /* Check valid-fail conditions */
                if (true)
                {
                    LOG_FIRST("COMMENT: configureDevices requires running HW.");
                    return NOTSUP;
                }


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_configureDevices(&pd, &devs, numDevs);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->configureDevices(&pd, &devs, numDevs);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("configureDevices: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_configureDevices(&pd, &devs, numDevs);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_configureDevice(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->configureDevice == NULL)
    {
        LOG("configureDevice: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t idx_dev;
        I3C_DeviceDescriptor dev;

        for (idx_dev = 0; idx_dev < 96; idx_dev++)
        {
            API_TEST_fill_I3C_DeviceDescriptor(&dev, idx_dev);

            uint32_t loop_index;

            for (loop_index = 0; loop_index < (24); loop_index++)
            {
                uint8_t index = API_TEST_table_uint8_t[loop_index];
                /* Check valid-fail conditions */
                if (true)
                {
                    LOG_FIRST("COMMENT: configureDevice requires running HW.");
                    return NOTSUP;
                }


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_configureDevice(&pd, &dev, index);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->configureDevice(&pd, &dev, index);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("configureDevice: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_configureDevice(&pd, &dev, index);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_configurePrescalers(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->configurePrescalers == NULL)
    {
        LOG("configurePrescalers: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t idx_config;
        I3C_Config config;

        for (idx_config = 0; idx_config < 96; idx_config++)
        {
            API_TEST_fill_I3C_Config(&config, idx_config);

            /* Check valid-fail conditions */
            if (true)
            {
                LOG_FIRST("COMMENT: configurePrescalers requires running HW.");
                return NOTSUP;
            }


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_configurePrescalers(&pd, &config);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->configurePrescalers(&pd, &config);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("configurePrescalers: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_configurePrescalers(&pd, &config);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_clearRrOfDevice(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->clearRrOfDevice == NULL)
    {
        LOG("clearRrOfDevice: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_device_no;

        for (loop_device_no = 0; loop_device_no < (24); loop_device_no++)
        {
            uint8_t device_no = API_TEST_table_uint8_t[loop_device_no];
            /* Check valid-fail conditions */
            if (true)
            {
                LOG_FIRST("COMMENT: configureDevices requires running HW.");
                return NOTSUP;
            }


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_clearRrOfDevice(&pd, device_no);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->clearRrOfDevice(&pd, device_no);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("clearRrOfDevice: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_clearRrOfDevice(&pd, device_no);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_getNewDevices(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->getNewDevices == NULL)
    {
        LOG("getNewDevices: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint16_t hj_devices = 0;
        /* Check valid-fail conditions */
        if (true)
        {
            LOG_FIRST("COMMENT: getNewDevices requires running HW.");
            return NOTSUP;
        }


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_getNewDevices(&pd, &hj_devices);


        if (expectedRet == CDN_EINVAL)
        {

            /* Call function */
            ret = obj->getNewDevices(&pd, &hj_devices);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("getNewDevices: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_getNewDevices(&pd, &hj_devices);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_configureInterrupts(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->configureInterrupts == NULL)
    {
        LOG("configureInterrupts: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t idx_interruptConfig;
        I3C_InterruptConfig interruptConfig;

        for (idx_interruptConfig = 0; idx_interruptConfig < 96; idx_interruptConfig++)
        {
            API_TEST_fill_I3C_InterruptConfig(&interruptConfig, idx_interruptConfig);

            /* Check valid-fail conditions */
            if (true)
            {
                LOG_FIRST("COMMENT: configureInterrupts requires running HW.");
                return NOTSUP;
            }


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_configureInterrupts(&pd, &interruptConfig);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->configureInterrupts(&pd, &interruptConfig);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("configureInterrupts: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_configureInterrupts(&pd, &interruptConfig);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_configureThresholds(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->configureThresholds == NULL)
    {
        LOG("configureThresholds: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t idx_thresholdConfig;
        I3C_ThresholdConfig thresholdConfig;

        for (idx_thresholdConfig = 0; idx_thresholdConfig < 96; idx_thresholdConfig++)
        {
            API_TEST_fill_I3C_ThresholdConfig(&thresholdConfig, idx_thresholdConfig);

            /* Check valid-fail conditions */
            if (true)
            {
                LOG_FIRST("COMMENT: configureThresholds requires running HW.");
                return NOTSUP;
            }


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_configureThresholds(&pd, &thresholdConfig);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->configureThresholds(&pd, &thresholdConfig);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("configureThresholds: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_configureThresholds(&pd, &thresholdConfig);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdExec(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdExec == NULL)
    {
        LOG("cmdExec: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        /* Check valid-fail conditions */
        if (true)
        {
            LOG_FIRST("COMMENT: cmdExec requires running HW.");
            return NOTSUP;
        }


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_cmdExec(&pd);


        if (expectedRet == CDN_EINVAL)
        {

            /* Call function */
            ret = obj->cmdExec(&pd);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("cmdExec: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_cmdExec(&pd);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_cmdExecImmediate(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdExecImmediate == NULL)
    {
        LOG("cmdExecImmediate: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        /* Check valid-fail conditions */
        if (true)
        {
            LOG_FIRST("COMMENT: cmdExecImmediate requires running HW.");
            return NOTSUP;
        }


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_cmdExecImmediate(&pd);


        if (expectedRet == CDN_EINVAL)
        {

            /* Call function */
            ret = obj->cmdExecImmediate(&pd);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("cmdExecImmediate: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_cmdExecImmediate(&pd);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_enableMcs(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->enableMcs == NULL)
    {
        LOG("enableMcs: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        /* Check valid-fail conditions */
        if (true)
        {
            LOG_FIRST("COMMENT: cmdExec requires running HW.");
            return NOTSUP;
        }


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_enableMcs(&pd);


        if (expectedRet == CDN_EINVAL)
        {

            /* Call function */
            ret = obj->enableMcs(&pd);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("enableMcs: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_enableMcs(&pd);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_disableMcs(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->disableMcs == NULL)
    {
        LOG("disableMcs: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        /* Check valid-fail conditions */
        if (true)
        {
            LOG_FIRST("COMMENT: cmdExec requires running HW.");
            return NOTSUP;
        }


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_disableMcs(&pd);


        if (expectedRet == CDN_EINVAL)
        {

            /* Call function */
            ret = obj->disableMcs(&pd);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("disableMcs: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_disableMcs(&pd);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_manualCommandStart(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->manualCommandStart == NULL)
    {
        LOG("manualCommandStart: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        /* Check valid-fail conditions */
        if (true)
        {
            LOG_FIRST("COMMENT: cmdExec requires running HW.");
            return NOTSUP;
        }


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_manualCommandStart(&pd);


        if (expectedRet == CDN_EINVAL)
        {

            /* Call function */
            ret = obj->manualCommandStart(&pd);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("manualCommandStart: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_manualCommandStart(&pd);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_cmdCount(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdCount == NULL)
    {
        LOG("cmdCount: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        /* Check valid-fail conditions */
        if (true)
        {
            LOG_FIRST("COMMENT: disableCore requires running HW.");
            return NOTSUP;
        }


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_cmdCount(&pd);


        if (expectedRet == 0)
        {

            /* Call function */
            ret = obj->cmdCount(&pd);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("cmdCount: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_cmdCount(&pd);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_cmdMaxCount(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdMaxCount == NULL)
    {
        LOG("cmdMaxCount: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        /* Check valid-fail conditions */
        if (true)
        {
            LOG_FIRST("COMMENT: disableCore requires running HW.");
            return NOTSUP;
        }


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_cmdMaxCount(&pd);


        if (expectedRet == 0)
        {

            /* Call function */
            ret = obj->cmdMaxCount(&pd);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("cmdMaxCount: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_cmdMaxCount(&pd);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_cmdClearAll(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdClearAll == NULL)
    {
        LOG("cmdClearAll: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        /* Check valid-fail conditions */
        if (true)
        {
            LOG_FIRST("COMMENT: disableCore requires running HW.");
            return NOTSUP;
        }


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_cmdClearAll(&pd);


        if (expectedRet == CDN_EINVAL)
        {

            /* Call function */
            ret = obj->cmdClearAll(&pd);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("cmdClearAll: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_cmdClearAll(&pd);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_devPrint(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->devPrint == NULL)
    {
        LOG("devPrint: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        /* Check valid-fail conditions */
        if (true)
        {
            LOG_FIRST("COMMENT: disableCore requires running HW.");
            return NOTSUP;
        }


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_devPrint(&pd);


        if (expectedRet == CDN_EINVAL)
        {

            /* Call function */
            ret = obj->devPrint(&pd);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("devPrint: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_devPrint(&pd);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_enableTc(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->enableTc == NULL)
    {
        LOG("enableTc: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        /* Check valid-fail conditions */
        if (true)
        {
            return NOTSUP;
        }


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_enableTc(&pd);


        if (expectedRet == CDN_EINVAL)
        {

            /* Call function */
            ret = obj->enableTc(&pd);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("enableTc: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_enableTc(&pd);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddPrivWrite(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddPrivWrite == NULL)
    {
        LOG("cmdAddPrivWrite: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_da;

        for (loop_da = 0; loop_da < (48); loop_da++)
        {
            uint16_t da = API_TEST_table_uint16_t[loop_da];
            uint32_t idx_csr_data;
            I3C_CsrData csr_data;

            for (idx_csr_data = 0; idx_csr_data < 96; idx_csr_data++)
            {
                API_TEST_fill_I3C_CsrData(&csr_data, idx_csr_data);

                uint32_t idx_payload_data;
                I3C_PayloadData payload_data;

                for (idx_payload_data = 0; idx_payload_data < 96; idx_payload_data++)
                {
                    API_TEST_fill_I3C_PayloadData(&payload_data, idx_payload_data);

                    uint32_t loop_xmitMmode;

                    for (loop_xmitMmode = 0; loop_xmitMmode < (96); loop_xmitMmode++)
                    {
                        I3C_TransmitMode xmitMmode = API_TEST_table_uint32_t[loop_xmitMmode];
                        /* Check valid-fail conditions */
                        if (true)
                        {
                            LOG_FIRST("COMMENT: disableCore requires running HW.");
                            return NOTSUP;
                        }


                        /* Display info with iteration number */
                        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                        /* Calculate expected return value */
                        expectedRet = API_TEST_expected_cmdAddPrivWrite(&pd, da, &csr_data, &payload_data, xmitMmode);


                        if (expectedRet == CDN_EINVAL)
                        {

                            /* Call function */
                            ret = obj->cmdAddPrivWrite(&pd, da, &csr_data, &payload_data, xmitMmode);

                            /* Check returned value */
                            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                            {
                                if (!API_TEST_loggedFirstFail)
                                {
                                    LOG_FIRST("cmdAddPrivWrite: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                                    LOG("Failed call:");
                                    API_TEST_printargs_cmdAddPrivWrite(&pd, da, &csr_data, &payload_data, xmitMmode);
                                }

                                return FAIL;
                            }
                            else if (ret == CDN_ENOTSUP)
                            {
                                return NOTSUP;
                            }

                        }

                    }
                }
            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddPrivRead(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddPrivRead == NULL)
    {
        LOG("cmdAddPrivRead: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_da;

        for (loop_da = 0; loop_da < (48); loop_da++)
        {
            uint16_t da = API_TEST_table_uint16_t[loop_da];
            uint32_t idx_csr_data;
            I3C_CsrData csr_data;

            for (idx_csr_data = 0; idx_csr_data < 96; idx_csr_data++)
            {
                API_TEST_fill_I3C_CsrData(&csr_data, idx_csr_data);

                uint32_t idx_payload_data;
                I3C_PayloadData payload_data;

                for (idx_payload_data = 0; idx_payload_data < 96; idx_payload_data++)
                {
                    API_TEST_fill_I3C_PayloadData(&payload_data, idx_payload_data);

                    uint32_t loop_xmitMmode;

                    for (loop_xmitMmode = 0; loop_xmitMmode < (96); loop_xmitMmode++)
                    {
                        I3C_TransmitMode xmitMmode = API_TEST_table_uint32_t[loop_xmitMmode];
                        /* Check valid-fail conditions */
                        if (true)
                        {
                            LOG_FIRST("COMMENT: disableCore requires running HW.");
                            return NOTSUP;
                        }


                        /* Display info with iteration number */
                        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                        /* Calculate expected return value */
                        expectedRet = API_TEST_expected_cmdAddPrivRead(&pd, da, &csr_data, &payload_data, xmitMmode);


                        if (expectedRet == CDN_EINVAL)
                        {

                            /* Call function */
                            ret = obj->cmdAddPrivRead(&pd, da, &csr_data, &payload_data, xmitMmode);

                            /* Check returned value */
                            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                            {
                                if (!API_TEST_loggedFirstFail)
                                {
                                    LOG_FIRST("cmdAddPrivRead: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                                    LOG("Failed call:");
                                    API_TEST_printargs_cmdAddPrivRead(&pd, da, &csr_data, &payload_data, xmitMmode);
                                }

                                return FAIL;
                            }
                            else if (ret == CDN_ENOTSUP)
                            {
                                return NOTSUP;
                            }

                        }

                    }
                }
            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddPrivI2CWrite(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddPrivI2CWrite == NULL)
    {
        LOG("cmdAddPrivI2CWrite: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_da;

        for (loop_da = 0; loop_da < (48); loop_da++)
        {
            uint16_t da = API_TEST_table_uint16_t[loop_da];
            uint8_t payload = 0;
            uint32_t loop_payloadSize;

            for (loop_payloadSize = 0; loop_payloadSize < (48); loop_payloadSize++)
            {
                uint16_t payloadSize = API_TEST_table_uint16_t[loop_payloadSize];
                /* Check valid-fail conditions */
                if (true)
                {
                    LOG_FIRST("COMMENT: disableCore requires running HW.");
                    return NOTSUP;
                }


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_cmdAddPrivI2CWrite(&pd, da, &payload, payloadSize);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->cmdAddPrivI2CWrite(&pd, da, &payload, payloadSize);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("cmdAddPrivI2CWrite: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_cmdAddPrivI2CWrite(&pd, da, &payload, payloadSize);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddPrivI2CRead(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddPrivI2CRead == NULL)
    {
        LOG("cmdAddPrivI2CRead: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_da;

        for (loop_da = 0; loop_da < (48); loop_da++)
        {
            uint16_t da = API_TEST_table_uint16_t[loop_da];
            uint8_t payload = 0;
            uint32_t loop_payloadSize;

            for (loop_payloadSize = 0; loop_payloadSize < (48); loop_payloadSize++)
            {
                uint16_t payloadSize = API_TEST_table_uint16_t[loop_payloadSize];
                /* Check valid-fail conditions */
                if (true)
                {
                    LOG_FIRST("COMMENT: disableCore requires running HW.");
                    return NOTSUP;
                }


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_cmdAddPrivI2CRead(&pd, da, &payload, payloadSize);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->cmdAddPrivI2CRead(&pd, da, &payload, payloadSize);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("cmdAddPrivI2CRead: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_cmdAddPrivI2CRead(&pd, da, &payload, payloadSize);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddDdrWrite(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddDdrWrite == NULL)
    {
        LOG("cmdAddDdrWrite: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_da;

        for (loop_da = 0; loop_da < (24); loop_da++)
        {
            uint8_t da = API_TEST_table_uint8_t[loop_da];
            uint32_t loop_command;

            for (loop_command = 0; loop_command < (24); loop_command++)
            {
                uint8_t command = API_TEST_table_uint8_t[loop_command];
                uint32_t loop_hdrMode;

                for (loop_hdrMode = 0; loop_hdrMode < (96); loop_hdrMode++)
                {
                    I3C_HdrMode hdrMode = API_TEST_table_uint32_t[loop_hdrMode];
                    uint32_t idx_payload_data;
                    I3C_PayloadData payload_data;

                    for (idx_payload_data = 0; idx_payload_data < 96; idx_payload_data++)
                    {
                        API_TEST_fill_I3C_PayloadData(&payload_data, idx_payload_data);

                        /* Check valid-fail conditions */
                        if (true)
                        {
                            LOG_FIRST("COMMENT: disableCore requires running HW.");
                            return NOTSUP;
                        }


                        /* Display info with iteration number */
                        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                        /* Calculate expected return value */
                        expectedRet = API_TEST_expected_cmdAddDdrWrite(&pd, da, command, hdrMode, &payload_data);


                        if (expectedRet == CDN_EINVAL)
                        {

                            /* Call function */
                            ret = obj->cmdAddDdrWrite(&pd, da, command, hdrMode, &payload_data);

                            /* Check returned value */
                            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                            {
                                if (!API_TEST_loggedFirstFail)
                                {
                                    LOG_FIRST("cmdAddDdrWrite: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                                    LOG("Failed call:");
                                    API_TEST_printargs_cmdAddDdrWrite(&pd, da, command, hdrMode, &payload_data);
                                }

                                return FAIL;
                            }
                            else if (ret == CDN_ENOTSUP)
                            {
                                return NOTSUP;
                            }

                        }

                    }
                }
            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddDdrRead(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddDdrRead == NULL)
    {
        LOG("cmdAddDdrRead: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_da;

        for (loop_da = 0; loop_da < (24); loop_da++)
        {
            uint8_t da = API_TEST_table_uint8_t[loop_da];
            uint32_t loop_command;

            for (loop_command = 0; loop_command < (24); loop_command++)
            {
                uint8_t command = API_TEST_table_uint8_t[loop_command];
                uint32_t loop_hdrMode;

                for (loop_hdrMode = 0; loop_hdrMode < (96); loop_hdrMode++)
                {
                    I3C_HdrMode hdrMode = API_TEST_table_uint32_t[loop_hdrMode];
                    uint32_t idx_payload_data;
                    I3C_PayloadData payload_data;

                    for (idx_payload_data = 0; idx_payload_data < 96; idx_payload_data++)
                    {
                        API_TEST_fill_I3C_PayloadData(&payload_data, idx_payload_data);

                        /* Check valid-fail conditions */
                        if (true)
                        {
                            LOG_FIRST("COMMENT: disableCore requires running HW.");
                            return NOTSUP;
                        }


                        /* Display info with iteration number */
                        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                        /* Calculate expected return value */
                        expectedRet = API_TEST_expected_cmdAddDdrRead(&pd, da, command, hdrMode, &payload_data);


                        if (expectedRet == CDN_EINVAL)
                        {

                            /* Call function */
                            ret = obj->cmdAddDdrRead(&pd, da, command, hdrMode, &payload_data);

                            /* Check returned value */
                            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                            {
                                if (!API_TEST_loggedFirstFail)
                                {
                                    LOG_FIRST("cmdAddDdrRead: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                                    LOG("Failed call:");
                                    API_TEST_printargs_cmdAddDdrRead(&pd, da, command, hdrMode, &payload_data);
                                }

                                return FAIL;
                            }
                            else if (ret == CDN_ENOTSUP)
                            {
                                return NOTSUP;
                            }

                        }

                    }
                }
            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddSetSlaveEvents(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddSetSlaveEvents == NULL)
    {
        LOG("cmdAddSetSlaveEvents: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_eventsMask;

        for (loop_eventsMask = 0; loop_eventsMask < (24); loop_eventsMask++)
        {
            uint8_t eventsMask = API_TEST_table_uint8_t[loop_eventsMask];
            uint32_t loop_enable;

            for (loop_enable = 0; loop_enable < (2); loop_enable++)
            {
                bool enable = API_TEST_table_bool[loop_enable];
                uint32_t loop_devAddr;

                for (loop_devAddr = 0; loop_devAddr < (24); loop_devAddr++)
                {
                    uint8_t devAddr = API_TEST_table_uint8_t[loop_devAddr];
                    uint32_t idx_tx_params;
                    I3C_TransmissionParameters tx_params;

                    for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
                    {
                        API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                        /* Check valid-fail conditions */
                        if (true)
                        {
                            LOG_FIRST("COMMENT: disableCore requires running HW.");
                            return NOTSUP;
                        }


                        /* Display info with iteration number */
                        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                        /* Calculate expected return value */
                        expectedRet = API_TEST_expected_cmdAddSetSlaveEvents(&pd, eventsMask, enable, devAddr, &tx_params);


                        if (expectedRet == CDN_EINVAL)
                        {

                            /* Call function */
                            ret = obj->cmdAddSetSlaveEvents(&pd, eventsMask, enable, devAddr, &tx_params);

                            /* Check returned value */
                            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                            {
                                if (!API_TEST_loggedFirstFail)
                                {
                                    LOG_FIRST("cmdAddSetSlaveEvents: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                                    LOG("Failed call:");
                                    API_TEST_printargs_cmdAddSetSlaveEvents(&pd, eventsMask, enable, devAddr, &tx_params);
                                }

                                return FAIL;
                            }
                            else if (ret == CDN_ENOTSUP)
                            {
                                return NOTSUP;
                            }

                        }

                    }
                }
            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddEnterActivityState(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddEnterActivityState == NULL)
    {
        LOG("cmdAddEnterActivityState: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_state;

        for (loop_state = 0; loop_state < (96); loop_state++)
        {
            I3C_ActivityState state = API_TEST_table_uint32_t[loop_state];
            uint32_t loop_devAddr;

            for (loop_devAddr = 0; loop_devAddr < (24); loop_devAddr++)
            {
                uint8_t devAddr = API_TEST_table_uint8_t[loop_devAddr];
                uint32_t idx_tx_params;
                I3C_TransmissionParameters tx_params;

                for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
                {
                    API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                    /* Check valid-fail conditions */
                    if (true)
                    {
                        LOG_FIRST("COMMENT: disableCore requires running HW.");
                        return NOTSUP;
                    }


                    /* Display info with iteration number */
                    DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                    /* Calculate expected return value */
                    expectedRet = API_TEST_expected_cmdAddEnterActivityState(&pd, state, devAddr, &tx_params);


                    if (expectedRet == CDN_EINVAL)
                    {

                        /* Call function */
                        ret = obj->cmdAddEnterActivityState(&pd, state, devAddr, &tx_params);

                        /* Check returned value */
                        if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                        {
                            if (!API_TEST_loggedFirstFail)
                            {
                                LOG_FIRST("cmdAddEnterActivityState: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                                LOG("Failed call:");
                                API_TEST_printargs_cmdAddEnterActivityState(&pd, state, devAddr, &tx_params);
                            }

                            return FAIL;
                        }
                        else if (ret == CDN_ENOTSUP)
                        {
                            return NOTSUP;
                        }

                    }

                }
            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddResetDaa(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddResetDaa == NULL)
    {
        LOG("cmdAddResetDaa: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_devAddr;

        for (loop_devAddr = 0; loop_devAddr < (24); loop_devAddr++)
        {
            uint8_t devAddr = API_TEST_table_uint8_t[loop_devAddr];
            uint32_t idx_tx_params;
            I3C_TransmissionParameters tx_params;

            for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
            {
                API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                /* Check valid-fail conditions */
                if (true)
                {
                    LOG_FIRST("COMMENT: disableCore requires running HW.");
                    return NOTSUP;
                }


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_cmdAddResetDaa(&pd, devAddr, &tx_params);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->cmdAddResetDaa(&pd, devAddr, &tx_params);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("cmdAddResetDaa: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_cmdAddResetDaa(&pd, devAddr, &tx_params);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddEnterDaa(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddEnterDaa == NULL)
    {
        LOG("cmdAddEnterDaa: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t idx_tx_params;
        I3C_TransmissionParameters tx_params;

        for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
        {
            API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

            /* Check valid-fail conditions */
            if (true)
            {
                LOG_FIRST("COMMENT: disableCore requires running HW.");
                return NOTSUP;
            }


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_cmdAddEnterDaa(&pd, &tx_params);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->cmdAddEnterDaa(&pd, &tx_params);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("cmdAddEnterDaa: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_cmdAddEnterDaa(&pd, &tx_params);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddSetMaxWriteLength(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddSetMaxWriteLength == NULL)
    {
        LOG("cmdAddSetMaxWriteLength: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_length;

        for (loop_length = 0; loop_length < (48); loop_length++)
        {
            uint16_t length = API_TEST_table_uint16_t[loop_length];
            uint32_t loop_devAddr;

            for (loop_devAddr = 0; loop_devAddr < (24); loop_devAddr++)
            {
                uint8_t devAddr = API_TEST_table_uint8_t[loop_devAddr];
                uint32_t idx_tx_params;
                I3C_TransmissionParameters tx_params;

                for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
                {
                    API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                    /* Check valid-fail conditions */
                    if (true)
                    {
                        LOG_FIRST("COMMENT: disableCore requires running HW.");
                        return NOTSUP;
                    }


                    /* Display info with iteration number */
                    DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                    /* Calculate expected return value */
                    expectedRet = API_TEST_expected_cmdAddSetMaxWriteLength(&pd, length, devAddr, &tx_params);


                    if (expectedRet == CDN_EINVAL)
                    {

                        /* Call function */
                        ret = obj->cmdAddSetMaxWriteLength(&pd, length, devAddr, &tx_params);

                        /* Check returned value */
                        if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                        {
                            if (!API_TEST_loggedFirstFail)
                            {
                                LOG_FIRST("cmdAddSetMaxWriteLength: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                                LOG("Failed call:");
                                API_TEST_printargs_cmdAddSetMaxWriteLength(&pd, length, devAddr, &tx_params);
                            }

                            return FAIL;
                        }
                        else if (ret == CDN_ENOTSUP)
                        {
                            return NOTSUP;
                        }

                    }

                }
            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddGetMaxWriteLength(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddGetMaxWriteLength == NULL)
    {
        LOG("cmdAddGetMaxWriteLength: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint16_t length = 0;
        uint32_t loop_devAddr;

        for (loop_devAddr = 0; loop_devAddr < (24); loop_devAddr++)
        {
            uint8_t devAddr = API_TEST_table_uint8_t[loop_devAddr];
            uint32_t idx_tx_params;
            I3C_TransmissionParameters tx_params;

            for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
            {
                API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                /* Check valid-fail conditions */
                if (true)
                {
                    LOG_FIRST("COMMENT: disableCore requires running HW.");
                    return NOTSUP;
                }


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_cmdAddGetMaxWriteLength(&pd, &length, devAddr, &tx_params);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->cmdAddGetMaxWriteLength(&pd, &length, devAddr, &tx_params);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("cmdAddGetMaxWriteLength: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_cmdAddGetMaxWriteLength(&pd, &length, devAddr, &tx_params);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddSetMaxReadLength(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddSetMaxReadLength == NULL)
    {
        LOG("cmdAddSetMaxReadLength: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t idx_max_read_length;
        I3C_MaxReadLength max_read_length;

        for (idx_max_read_length = 0; idx_max_read_length < 96; idx_max_read_length++)
        {
            API_TEST_fill_I3C_MaxReadLength(&max_read_length, idx_max_read_length);

            uint32_t loop_length_size;

            for (loop_length_size = 0; loop_length_size < (24); loop_length_size++)
            {
                uint8_t length_size = API_TEST_table_uint8_t[loop_length_size];
                uint32_t loop_devAddr;

                for (loop_devAddr = 0; loop_devAddr < (24); loop_devAddr++)
                {
                    uint8_t devAddr = API_TEST_table_uint8_t[loop_devAddr];
                    uint32_t idx_tx_params;
                    I3C_TransmissionParameters tx_params;

                    for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
                    {
                        API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                        /* Check valid-fail conditions */
                        if (true)
                        {
                            LOG_FIRST("COMMENT: disableCore requires running HW.");
                            return NOTSUP;
                        }


                        /* Display info with iteration number */
                        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                        /* Calculate expected return value */
                        expectedRet = API_TEST_expected_cmdAddSetMaxReadLength(&pd, max_read_length, length_size, devAddr, &tx_params);


                        if (expectedRet == CDN_EINVAL)
                        {

                            /* Call function */
                            ret = obj->cmdAddSetMaxReadLength(&pd, max_read_length, length_size, devAddr, &tx_params);

                            /* Check returned value */
                            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                            {
                                if (!API_TEST_loggedFirstFail)
                                {
                                    LOG_FIRST("cmdAddSetMaxReadLength: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                                    LOG("Failed call:");
                                    API_TEST_printargs_cmdAddSetMaxReadLength(&pd, max_read_length, length_size, devAddr, &tx_params);
                                }

                                return FAIL;
                            }
                            else if (ret == CDN_ENOTSUP)
                            {
                                return NOTSUP;
                            }

                        }

                    }
                }
            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddGetMaxReadLength(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddGetMaxReadLength == NULL)
    {
        LOG("cmdAddGetMaxReadLength: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t idx_max_read_length;
        I3C_MaxReadLength max_read_length;

        for (idx_max_read_length = 0; idx_max_read_length < 96; idx_max_read_length++)
        {
            API_TEST_fill_I3C_MaxReadLength(&max_read_length, idx_max_read_length);

            uint32_t loop_length_size;

            for (loop_length_size = 0; loop_length_size < (24); loop_length_size++)
            {
                uint8_t length_size = API_TEST_table_uint8_t[loop_length_size];
                uint32_t loop_devAddr;

                for (loop_devAddr = 0; loop_devAddr < (24); loop_devAddr++)
                {
                    uint8_t devAddr = API_TEST_table_uint8_t[loop_devAddr];
                    uint32_t idx_tx_params;
                    I3C_TransmissionParameters tx_params;

                    for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
                    {
                        API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                        /* Check valid-fail conditions */
                        if (true)
                        {
                            LOG_FIRST("COMMENT: disableCore requires running HW.");
                            return NOTSUP;
                        }


                        /* Display info with iteration number */
                        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                        /* Calculate expected return value */
                        expectedRet = API_TEST_expected_cmdAddGetMaxReadLength(&pd, &max_read_length, length_size, devAddr, &tx_params);


                        if (expectedRet == CDN_EINVAL)
                        {

                            /* Call function */
                            ret = obj->cmdAddGetMaxReadLength(&pd, &max_read_length, length_size, devAddr, &tx_params);

                            /* Check returned value */
                            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                            {
                                if (!API_TEST_loggedFirstFail)
                                {
                                    LOG_FIRST("cmdAddGetMaxReadLength: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                                    LOG("Failed call:");
                                    API_TEST_printargs_cmdAddGetMaxReadLength(&pd, &max_read_length, length_size, devAddr, &tx_params);
                                }

                                return FAIL;
                            }
                            else if (ret == CDN_ENOTSUP)
                            {
                                return NOTSUP;
                            }

                        }

                    }
                }
            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddGetMaxDataSpeed(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddGetMaxDataSpeed == NULL)
    {
        LOG("cmdAddGetMaxDataSpeed: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t idx_max_data_speed;
        I3C_MaxDataSpeed max_data_speed;

        for (idx_max_data_speed = 0; idx_max_data_speed < 96; idx_max_data_speed++)
        {
            API_TEST_fill_I3C_MaxDataSpeed(&max_data_speed, idx_max_data_speed);

            uint32_t loop_devAddr;

            for (loop_devAddr = 0; loop_devAddr < (24); loop_devAddr++)
            {
                uint8_t devAddr = API_TEST_table_uint8_t[loop_devAddr];
                uint32_t idx_tx_params;
                I3C_TransmissionParameters tx_params;

                for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
                {
                    API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                    /* Check valid-fail conditions */
                    if (true)
                    {
                        LOG_FIRST("COMMENT: disableCore requires running HW.");
                        return NOTSUP;
                    }


                    /* Display info with iteration number */
                    DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                    /* Calculate expected return value */
                    expectedRet = API_TEST_expected_cmdAddGetMaxDataSpeed(&pd, &max_data_speed, devAddr, &tx_params);


                    if (expectedRet == CDN_EINVAL)
                    {

                        /* Call function */
                        ret = obj->cmdAddGetMaxDataSpeed(&pd, &max_data_speed, devAddr, &tx_params);

                        /* Check returned value */
                        if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                        {
                            if (!API_TEST_loggedFirstFail)
                            {
                                LOG_FIRST("cmdAddGetMaxDataSpeed: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                                LOG("Failed call:");
                                API_TEST_printargs_cmdAddGetMaxDataSpeed(&pd, &max_data_speed, devAddr, &tx_params);
                            }

                            return FAIL;
                        }
                        else if (ret == CDN_ENOTSUP)
                        {
                            return NOTSUP;
                        }

                    }

                }
            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_getSlavesList(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->getSlavesList == NULL)
    {
        LOG("getSlavesList: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t idx_slaveDescs;
        I3C_SlaveDescriptors slaveDescs;

        for (idx_slaveDescs = 0; idx_slaveDescs < 96; idx_slaveDescs++)
        {
            API_TEST_fill_I3C_SlaveDescriptors(&slaveDescs, idx_slaveDescs);

            /* Check valid-fail conditions */
            if (true)
            {
                LOG_FIRST("COMMENT: disableCore requires running HW.");
                return NOTSUP;
            }


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_getSlavesList(&pd, &slaveDescs);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->getSlavesList(&pd, &slaveDescs);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("getSlavesList: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_getSlavesList(&pd, &slaveDescs);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddDefineSlavesList(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddDefineSlavesList == NULL)
    {
        LOG("cmdAddDefineSlavesList: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t idx_slaveDescs;
        I3C_SlaveDescriptors slaveDescs;

        for (idx_slaveDescs = 0; idx_slaveDescs < 96; idx_slaveDescs++)
        {
            API_TEST_fill_I3C_SlaveDescriptors(&slaveDescs, idx_slaveDescs);

            uint32_t idx_tx_params;
            I3C_TransmissionParameters tx_params;

            for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
            {
                API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                /* Check valid-fail conditions */
                if (true)
                {
                    LOG_FIRST("COMMENT: disableCore requires running HW.");
                    return NOTSUP;
                }


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_cmdAddDefineSlavesList(&pd, &slaveDescs, &tx_params);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->cmdAddDefineSlavesList(&pd, &slaveDescs, &tx_params);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("cmdAddDefineSlavesList: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_cmdAddDefineSlavesList(&pd, &slaveDescs, &tx_params);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddEnterTestMode(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddEnterTestMode == NULL)
    {
        LOG("cmdAddEnterTestMode: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_mode;

        for (loop_mode = 0; loop_mode < (24); loop_mode++)
        {
            uint8_t mode = API_TEST_table_uint8_t[loop_mode];
            uint32_t idx_tx_params;
            I3C_TransmissionParameters tx_params;

            for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
            {
                API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                /* Check valid-fail conditions */
                if (true)
                {
                    LOG_FIRST("COMMENT: disableCore requires running HW.");
                    return NOTSUP;
                }


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_cmdAddEnterTestMode(&pd, mode, &tx_params);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->cmdAddEnterTestMode(&pd, mode, &tx_params);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("cmdAddEnterTestMode: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_cmdAddEnterTestMode(&pd, mode, &tx_params);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddSetBuscon(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddSetBuscon == NULL)
    {
        LOG("cmdAddSetBuscon: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint8_t context_buf = 0;
        uint32_t loop_length_size;

        for (loop_length_size = 0; loop_length_size < (24); loop_length_size++)
        {
            uint8_t length_size = API_TEST_table_uint8_t[loop_length_size];
            uint32_t idx_tx_params;
            I3C_TransmissionParameters tx_params;

            for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
            {
                API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                /* Check valid-fail conditions */
                if (true)
                {
                    LOG_FIRST("COMMENT: disableCore requires running HW.");
                    return NOTSUP;
                }


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_cmdAddSetBuscon(&pd, &context_buf, length_size, &tx_params);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->cmdAddSetBuscon(&pd, &context_buf, length_size, &tx_params);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("cmdAddSetBuscon: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_cmdAddSetBuscon(&pd, &context_buf, length_size, &tx_params);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddEnterHdrMode(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddEnterHdrMode == NULL)
    {
        LOG("cmdAddEnterHdrMode: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_mode;

        for (loop_mode = 0; loop_mode < (96); loop_mode++)
        {
            I3C_HdrMode mode = API_TEST_table_uint32_t[loop_mode];
            uint32_t idx_tx_params;
            I3C_TransmissionParameters tx_params;

            for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
            {
                API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                /* Check valid-fail conditions */
                if (true)
                {
                    LOG_FIRST("COMMENT: disableCore requires running HW.");
                    return NOTSUP;
                }


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_cmdAddEnterHdrMode(&pd, mode, &tx_params);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->cmdAddEnterHdrMode(&pd, mode, &tx_params);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("cmdAddEnterHdrMode: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_cmdAddEnterHdrMode(&pd, mode, &tx_params);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddSetAaSa(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddSetAaSa == NULL)
    {
        LOG("cmdAddSetAaSa: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t idx_tx_params;
        I3C_TransmissionParameters tx_params;

        for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
        {
            API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

            /* Check valid-fail conditions */
            if (true)
            {
                LOG_FIRST("COMMENT: disableCore requires running HW.");
                return NOTSUP;
            }


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_cmdAddSetAaSa(&pd, &tx_params);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->cmdAddSetAaSa(&pd, &tx_params);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("cmdAddSetAaSa: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_cmdAddSetAaSa(&pd, &tx_params);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdSetDaFromSa(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdSetDaFromSa == NULL)
    {
        LOG("cmdSetDaFromSa: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_address;

        for (loop_address = 0; loop_address < (24); loop_address++)
        {
            uint8_t address = API_TEST_table_uint8_t[loop_address];
            uint32_t loop_devAddr;

            for (loop_devAddr = 0; loop_devAddr < (24); loop_devAddr++)
            {
                uint8_t devAddr = API_TEST_table_uint8_t[loop_devAddr];
                uint32_t idx_tx_params;
                I3C_TransmissionParameters tx_params;

                for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
                {
                    API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                    /* Check valid-fail conditions */
                    if (true)
                    {
                        LOG_FIRST("COMMENT: disableCore requires running HW.");
                        return NOTSUP;
                    }


                    /* Display info with iteration number */
                    DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                    /* Calculate expected return value */
                    expectedRet = API_TEST_expected_cmdSetDaFromSa(&pd, address, devAddr, &tx_params);


                    if (expectedRet == CDN_EINVAL)
                    {

                        /* Call function */
                        ret = obj->cmdSetDaFromSa(&pd, address, devAddr, &tx_params);

                        /* Check returned value */
                        if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                        {
                            if (!API_TEST_loggedFirstFail)
                            {
                                LOG_FIRST("cmdSetDaFromSa: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                                LOG("Failed call:");
                                API_TEST_printargs_cmdSetDaFromSa(&pd, address, devAddr, &tx_params);
                            }

                            return FAIL;
                        }
                        else if (ret == CDN_ENOTSUP)
                        {
                            return NOTSUP;
                        }

                    }

                }
            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddSetNewDa(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddSetNewDa == NULL)
    {
        LOG("cmdAddSetNewDa: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_da;

        for (loop_da = 0; loop_da < (24); loop_da++)
        {
            uint8_t da = API_TEST_table_uint8_t[loop_da];
            uint32_t loop_devAddr;

            for (loop_devAddr = 0; loop_devAddr < (24); loop_devAddr++)
            {
                uint8_t devAddr = API_TEST_table_uint8_t[loop_devAddr];
                uint32_t idx_tx_params;
                I3C_TransmissionParameters tx_params;

                for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
                {
                    API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                    /* Check valid-fail conditions */
                    if (true)
                    {
                        LOG_FIRST("COMMENT: disableCore requires running HW.");
                        return NOTSUP;
                    }


                    /* Display info with iteration number */
                    DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                    /* Calculate expected return value */
                    expectedRet = API_TEST_expected_cmdAddSetNewDa(&pd, da, devAddr, &tx_params);


                    if (expectedRet == CDN_EINVAL)
                    {

                        /* Call function */
                        ret = obj->cmdAddSetNewDa(&pd, da, devAddr, &tx_params);

                        /* Check returned value */
                        if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                        {
                            if (!API_TEST_loggedFirstFail)
                            {
                                LOG_FIRST("cmdAddSetNewDa: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                                LOG("Failed call:");
                                API_TEST_printargs_cmdAddSetNewDa(&pd, da, devAddr, &tx_params);
                            }

                            return FAIL;
                        }
                        else if (ret == CDN_ENOTSUP)
                        {
                            return NOTSUP;
                        }

                    }

                }
            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddSetRstAct(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddSetRstAct == NULL)
    {
        LOG("cmdAddSetRstAct: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_DefiningByte;

        for (loop_DefiningByte = 0; loop_DefiningByte < (24); loop_DefiningByte++)
        {
            uint8_t DefiningByte = API_TEST_table_uint8_t[loop_DefiningByte];
            uint32_t loop_devAddr;

            for (loop_devAddr = 0; loop_devAddr < (24); loop_devAddr++)
            {
                uint8_t devAddr = API_TEST_table_uint8_t[loop_devAddr];
                uint32_t idx_tx_params;
                I3C_TransmissionParameters tx_params;

                for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
                {
                    API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                    /* Check valid-fail conditions */
                    if (true)
                    {
                        LOG_FIRST("COMMENT: disableCore requires running HW.");
                        return NOTSUP;
                    }


                    /* Display info with iteration number */
                    DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                    /* Calculate expected return value */
                    expectedRet = API_TEST_expected_cmdAddSetRstAct(&pd, DefiningByte, devAddr, &tx_params);


                    if (expectedRet == CDN_EINVAL)
                    {

                        /* Call function */
                        ret = obj->cmdAddSetRstAct(&pd, DefiningByte, devAddr, &tx_params);

                        /* Check returned value */
                        if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                        {
                            if (!API_TEST_loggedFirstFail)
                            {
                                LOG_FIRST("cmdAddSetRstAct: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                                LOG("Failed call:");
                                API_TEST_printargs_cmdAddSetRstAct(&pd, DefiningByte, devAddr, &tx_params);
                            }

                            return FAIL;
                        }
                        else if (ret == CDN_ENOTSUP)
                        {
                            return NOTSUP;
                        }

                    }

                }
            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddSetXTime(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddSetXTime == NULL)
    {
        LOG("cmdAddSetXTime: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_SubCommandByte;

        for (loop_SubCommandByte = 0; loop_SubCommandByte < (24); loop_SubCommandByte++)
        {
            uint8_t SubCommandByte = API_TEST_table_uint8_t[loop_SubCommandByte];
            uint32_t loop_devAddr;

            for (loop_devAddr = 0; loop_devAddr < (24); loop_devAddr++)
            {
                uint8_t devAddr = API_TEST_table_uint8_t[loop_devAddr];
                uint32_t idx_tx_params;
                I3C_TransmissionParameters tx_params;

                for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
                {
                    API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                    /* Check valid-fail conditions */
                    if (true)
                    {
                        LOG_FIRST("COMMENT: disableCore requires running HW.");
                        return NOTSUP;
                    }


                    /* Display info with iteration number */
                    DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                    /* Calculate expected return value */
                    expectedRet = API_TEST_expected_cmdAddSetXTime(&pd, SubCommandByte, devAddr, &tx_params);


                    if (expectedRet == CDN_EINVAL)
                    {

                        /* Call function */
                        ret = obj->cmdAddSetXTime(&pd, SubCommandByte, devAddr, &tx_params);

                        /* Check returned value */
                        if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                        {
                            if (!API_TEST_loggedFirstFail)
                            {
                                LOG_FIRST("cmdAddSetXTime: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                                LOG("Failed call:");
                                API_TEST_printargs_cmdAddSetXTime(&pd, SubCommandByte, devAddr, &tx_params);
                            }

                            return FAIL;
                        }
                        else if (ret == CDN_ENOTSUP)
                        {
                            return NOTSUP;
                        }

                    }

                }
            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddSetGroupAddr(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddSetGroupAddr == NULL)
    {
        LOG("cmdAddSetGroupAddr: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_grpaddr;

        for (loop_grpaddr = 0; loop_grpaddr < (24); loop_grpaddr++)
        {
            uint8_t grpaddr = API_TEST_table_uint8_t[loop_grpaddr];
            uint32_t loop_devAddr;

            for (loop_devAddr = 0; loop_devAddr < (24); loop_devAddr++)
            {
                uint8_t devAddr = API_TEST_table_uint8_t[loop_devAddr];
                uint32_t idx_tx_params;
                I3C_TransmissionParameters tx_params;

                for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
                {
                    API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                    /* Check valid-fail conditions */
                    if (true)
                    {
                        LOG_FIRST("COMMENT: disableCore requires running HW.");
                        return NOTSUP;
                    }


                    /* Display info with iteration number */
                    DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                    /* Calculate expected return value */
                    expectedRet = API_TEST_expected_cmdAddSetGroupAddr(&pd, grpaddr, devAddr, &tx_params);


                    if (expectedRet == CDN_EINVAL)
                    {

                        /* Call function */
                        ret = obj->cmdAddSetGroupAddr(&pd, grpaddr, devAddr, &tx_params);

                        /* Check returned value */
                        if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                        {
                            if (!API_TEST_loggedFirstFail)
                            {
                                LOG_FIRST("cmdAddSetGroupAddr: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                                LOG("Failed call:");
                                API_TEST_printargs_cmdAddSetGroupAddr(&pd, grpaddr, devAddr, &tx_params);
                            }

                            return FAIL;
                        }
                        else if (ret == CDN_ENOTSUP)
                        {
                            return NOTSUP;
                        }

                    }

                }
            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddDefineGroupList(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddDefineGroupList == NULL)
    {
        LOG("cmdAddDefineGroupList: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t idx_groupDescs;
        I3C_GroupDescriptors groupDescs;

        for (idx_groupDescs = 0; idx_groupDescs < 96; idx_groupDescs++)
        {
            API_TEST_fill_I3C_GroupDescriptors(&groupDescs, idx_groupDescs);

            uint32_t idx_tx_params;
            I3C_TransmissionParameters tx_params;

            for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
            {
                API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                /* Check valid-fail conditions */
                if (true)
                {
                    LOG_FIRST("COMMENT: disableCore requires running HW.");
                    return NOTSUP;
                }


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_cmdAddDefineGroupList(&pd, &groupDescs, &tx_params);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->cmdAddDefineGroupList(&pd, &groupDescs, &tx_params);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("cmdAddDefineGroupList: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_cmdAddDefineGroupList(&pd, &groupDescs, &tx_params);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddResetGrpa(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddResetGrpa == NULL)
    {
        LOG("cmdAddResetGrpa: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_grpAddr;

        for (loop_grpAddr = 0; loop_grpAddr < (24); loop_grpAddr++)
        {
            uint8_t grpAddr = API_TEST_table_uint8_t[loop_grpAddr];
            uint32_t loop_devAddr;

            for (loop_devAddr = 0; loop_devAddr < (24); loop_devAddr++)
            {
                uint8_t devAddr = API_TEST_table_uint8_t[loop_devAddr];
                uint32_t idx_tx_params;
                I3C_TransmissionParameters tx_params;

                for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
                {
                    API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                    /* Check valid-fail conditions */
                    if (true)
                    {
                        LOG_FIRST("COMMENT: disableCore requires running HW.");
                        return NOTSUP;
                    }


                    /* Display info with iteration number */
                    DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                    /* Calculate expected return value */
                    expectedRet = API_TEST_expected_cmdAddResetGrpa(&pd, grpAddr, devAddr, &tx_params);


                    if (expectedRet == CDN_EINVAL)
                    {

                        /* Call function */
                        ret = obj->cmdAddResetGrpa(&pd, grpAddr, devAddr, &tx_params);

                        /* Check returned value */
                        if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                        {
                            if (!API_TEST_loggedFirstFail)
                            {
                                LOG_FIRST("cmdAddResetGrpa: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                                LOG("Failed call:");
                                API_TEST_printargs_cmdAddResetGrpa(&pd, grpAddr, devAddr, &tx_params);
                            }

                            return FAIL;
                        }
                        else if (ret == CDN_ENOTSUP)
                        {
                            return NOTSUP;
                        }

                    }

                }
            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddGetProvisionalId(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddGetProvisionalId == NULL)
    {
        LOG("cmdAddGetProvisionalId: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint8_t buff = 0;
        uint32_t loop_devAddr;

        for (loop_devAddr = 0; loop_devAddr < (24); loop_devAddr++)
        {
            uint8_t devAddr = API_TEST_table_uint8_t[loop_devAddr];
            uint32_t idx_tx_params;
            I3C_TransmissionParameters tx_params;

            for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
            {
                API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                /* Check valid-fail conditions */
                if (true)
                {
                    LOG_FIRST("COMMENT: disableCore requires running HW.");
                    return NOTSUP;
                }


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_cmdAddGetProvisionalId(&pd, &buff, devAddr, &tx_params);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->cmdAddGetProvisionalId(&pd, &buff, devAddr, &tx_params);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("cmdAddGetProvisionalId: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_cmdAddGetProvisionalId(&pd, &buff, devAddr, &tx_params);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddGetBcr(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddGetBcr == NULL)
    {
        LOG("cmdAddGetBcr: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint8_t bcr = 0;
        uint32_t loop_devAddr;

        for (loop_devAddr = 0; loop_devAddr < (24); loop_devAddr++)
        {
            uint8_t devAddr = API_TEST_table_uint8_t[loop_devAddr];
            uint32_t idx_tx_params;
            I3C_TransmissionParameters tx_params;

            for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
            {
                API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                /* Check valid-fail conditions */
                if (true)
                {
                    LOG_FIRST("COMMENT: disableCore requires running HW.");
                    return NOTSUP;
                }


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_cmdAddGetBcr(&pd, &bcr, devAddr, &tx_params);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->cmdAddGetBcr(&pd, &bcr, devAddr, &tx_params);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("cmdAddGetBcr: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_cmdAddGetBcr(&pd, &bcr, devAddr, &tx_params);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddGetDcr(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddGetDcr == NULL)
    {
        LOG("cmdAddGetDcr: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint8_t dcr = 0;
        uint32_t loop_devAddr;

        for (loop_devAddr = 0; loop_devAddr < (24); loop_devAddr++)
        {
            uint8_t devAddr = API_TEST_table_uint8_t[loop_devAddr];
            uint32_t idx_tx_params;
            I3C_TransmissionParameters tx_params;

            for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
            {
                API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                /* Check valid-fail conditions */
                if (true)
                {
                    LOG_FIRST("COMMENT: disableCore requires running HW.");
                    return NOTSUP;
                }


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_cmdAddGetDcr(&pd, &dcr, devAddr, &tx_params);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->cmdAddGetDcr(&pd, &dcr, devAddr, &tx_params);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("cmdAddGetDcr: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_cmdAddGetDcr(&pd, &dcr, devAddr, &tx_params);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddGetStatus(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddGetStatus == NULL)
    {
        LOG("cmdAddGetStatus: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint16_t status = 0;
        uint32_t loop_devAddr;

        for (loop_devAddr = 0; loop_devAddr < (24); loop_devAddr++)
        {
            uint8_t devAddr = API_TEST_table_uint8_t[loop_devAddr];
            uint32_t idx_tx_params;
            I3C_TransmissionParameters tx_params;

            for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
            {
                API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                /* Check valid-fail conditions */
                if (true)
                {
                    LOG_FIRST("COMMENT: disableCore requires running HW.");
                    return NOTSUP;
                }


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_cmdAddGetStatus(&pd, &status, devAddr, &tx_params);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->cmdAddGetStatus(&pd, &status, devAddr, &tx_params);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("cmdAddGetStatus: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_cmdAddGetStatus(&pd, &status, devAddr, &tx_params);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddGetAccMst(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddGetAccMst == NULL)
    {
        LOG("cmdAddGetAccMst: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint8_t recData = 0;
        uint32_t loop_devAddr;

        for (loop_devAddr = 0; loop_devAddr < (24); loop_devAddr++)
        {
            uint8_t devAddr = API_TEST_table_uint8_t[loop_devAddr];
            uint32_t idx_tx_params;
            I3C_TransmissionParameters tx_params;

            for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
            {
                API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                /* Check valid-fail conditions */
                if (true)
                {
                    LOG_FIRST("COMMENT: disableCore requires running HW.");
                    return NOTSUP;
                }


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_cmdAddGetAccMst(&pd, &recData, devAddr, &tx_params);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->cmdAddGetAccMst(&pd, &recData, devAddr, &tx_params);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("cmdAddGetAccMst: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_cmdAddGetAccMst(&pd, &recData, devAddr, &tx_params);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_cmdAddGetXTime(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->cmdAddGetXTime == NULL)
    {
        LOG("cmdAddGetXTime: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t idx_tCamData;
        I3C_Tcam0Data tCamData;

        for (idx_tCamData = 0; idx_tCamData < 96; idx_tCamData++)
        {
            API_TEST_fill_I3C_Tcam0Data(&tCamData, idx_tCamData);

            uint32_t loop_devAddr;

            for (loop_devAddr = 0; loop_devAddr < (24); loop_devAddr++)
            {
                uint8_t devAddr = API_TEST_table_uint8_t[loop_devAddr];
                uint32_t idx_tx_params;
                I3C_TransmissionParameters tx_params;

                for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
                {
                    API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                    /* Check valid-fail conditions */
                    if (true)
                    {
                        LOG_FIRST("COMMENT: disableCore requires running HW.");
                        return NOTSUP;
                    }


                    /* Display info with iteration number */
                    DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                    /* Calculate expected return value */
                    expectedRet = API_TEST_expected_cmdAddGetXTime(&pd, &tCamData, devAddr, &tx_params);


                    if (expectedRet == CDN_EINVAL)
                    {

                        /* Call function */
                        ret = obj->cmdAddGetXTime(&pd, &tCamData, devAddr, &tx_params);

                        /* Check returned value */
                        if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                        {
                            if (!API_TEST_loggedFirstFail)
                            {
                                LOG_FIRST("cmdAddGetXTime: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                                LOG("Failed call:");
                                API_TEST_printargs_cmdAddGetXTime(&pd, &tCamData, devAddr, &tx_params);
                            }

                            return FAIL;
                        }
                        else if (ret == CDN_ENOTSUP)
                        {
                            return NOTSUP;
                        }

                    }

                }
            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_CmdSetNCAMode(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->CmdSetNCAMode == NULL)
    {
        LOG("CmdSetNCAMode: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_mode;

        for (loop_mode = 0; loop_mode < (24); loop_mode++)
        {
            uint8_t mode = API_TEST_table_uint8_t[loop_mode];
            uint32_t loop_devAddr;

            for (loop_devAddr = 0; loop_devAddr < (24); loop_devAddr++)
            {
                uint8_t devAddr = API_TEST_table_uint8_t[loop_devAddr];
                uint32_t idx_tx_params;
                I3C_TransmissionParameters tx_params;

                for (idx_tx_params = 0; idx_tx_params < 96; idx_tx_params++)
                {
                    API_TEST_fill_I3C_TransmissionParameters(&tx_params, idx_tx_params);

                    /* Check valid-fail conditions */
                    if (true)
                    {
                        LOG_FIRST("COMMENT: disableCore requires running HW.");
                        return NOTSUP;
                    }


                    /* Display info with iteration number */
                    DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                    /* Calculate expected return value */
                    expectedRet = API_TEST_expected_CmdSetNCAMode(&pd, mode, devAddr, &tx_params);


                    if (expectedRet == CDN_EINVAL)
                    {

                        /* Call function */
                        ret = obj->CmdSetNCAMode(&pd, mode, devAddr, &tx_params);

                        /* Check returned value */
                        if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                        {
                            if (!API_TEST_loggedFirstFail)
                            {
                                LOG_FIRST("CmdSetNCAMode: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                                LOG("Failed call:");
                                API_TEST_printargs_CmdSetNCAMode(&pd, mode, devAddr, &tx_params);
                            }

                            return FAIL;
                        }
                        else if (ret == CDN_ENOTSUP)
                        {
                            return NOTSUP;
                        }

                    }

                }
            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_ibiConfigureDevices(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->ibiConfigureDevices == NULL)
    {
        LOG("ibiConfigureDevices: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t idx_ibi_sir_cfg;
        I3C_IbiSirConfiguration ibi_sir_cfg;

        for (idx_ibi_sir_cfg = 0; idx_ibi_sir_cfg < 96; idx_ibi_sir_cfg++)
        {
            API_TEST_fill_I3C_IbiSirConfiguration(&ibi_sir_cfg, idx_ibi_sir_cfg);

            uint32_t loop_num_sir_cfgs;

            for (loop_num_sir_cfgs = 0; loop_num_sir_cfgs < (96); loop_num_sir_cfgs++)
            {
                uint32_t num_sir_cfgs = API_TEST_table_uint32_t[loop_num_sir_cfgs];
                /* Check valid-fail conditions */
                if (true)
                {
                    LOG_FIRST("COMMENT: disableCore requires running HW.");
                    return NOTSUP;
                }


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_ibiConfigureDevices(&pd, &ibi_sir_cfg, num_sir_cfgs);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->ibiConfigureDevices(&pd, &ibi_sir_cfg, num_sir_cfgs);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("ibiConfigureDevices: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_ibiConfigureDevices(&pd, &ibi_sir_cfg, num_sir_cfgs);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_ibiModifyDeviceConfig(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->ibiModifyDeviceConfig == NULL)
    {
        LOG("ibiModifyDeviceConfig: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t idx_ibi_sir_cfg;
        I3C_IbiSirConfiguration ibi_sir_cfg;

        for (idx_ibi_sir_cfg = 0; idx_ibi_sir_cfg < 96; idx_ibi_sir_cfg++)
        {
            API_TEST_fill_I3C_IbiSirConfiguration(&ibi_sir_cfg, idx_ibi_sir_cfg);

            uint32_t loop_da;

            for (loop_da = 0; loop_da < (24); loop_da++)
            {
                uint8_t da = API_TEST_table_uint8_t[loop_da];
                /* Check valid-fail conditions */
                if (true)
                {
                    LOG_FIRST("COMMENT: ibiModifyDeviceConfiguration requires running HW.");
                    return NOTSUP;
                }


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_ibiModifyDeviceConfig(&pd, &ibi_sir_cfg, da);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->ibiModifyDeviceConfig(&pd, &ibi_sir_cfg, da);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("ibiModifyDeviceConfig: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_ibiModifyDeviceConfig(&pd, &ibi_sir_cfg, da);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_ibiGetAddressOfIssuer(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->ibiGetAddressOfIssuer == NULL)
    {
        LOG("ibiGetAddressOfIssuer: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        /* Check valid-fail conditions */
        if (true)
        {
            LOG_FIRST("COMMENT: disableCore requires running HW.");
            return NOTSUP;
        }


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_ibiGetAddressOfIssuer(&pd);


        if (expectedRet == 0)
        {

            /* Call function */
            ret = obj->ibiGetAddressOfIssuer(&pd);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("ibiGetAddressOfIssuer: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_ibiGetAddressOfIssuer(&pd);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_ibiGetData(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->ibiGetData == NULL)
    {
        LOG("ibiGetData: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint8_t buf = 0;
        uint32_t loop_payload_size;

        for (loop_payload_size = 0; loop_payload_size < (48); loop_payload_size++)
        {
            uint16_t payload_size = API_TEST_table_uint16_t[loop_payload_size];
            /* Check valid-fail conditions */
            if (true)
            {
                LOG_FIRST("COMMENT: disableCore requires running HW.");
                return NOTSUP;
            }


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_ibiGetData(&pd, &buf, payload_size);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->ibiGetData(&pd, &buf, payload_size);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("ibiGetData: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_ibiGetData(&pd, &buf, payload_size);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_hjConfigureResponse(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->hjConfigureResponse == NULL)
    {
        LOG("hjConfigureResponse: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_hj_response;

        for (loop_hj_response = 0; loop_hj_response < (96); loop_hj_response++)
        {
            I3C_HjResponse hj_response = API_TEST_table_uint32_t[loop_hj_response];
            uint32_t loop_hj_disable_set;

            for (loop_hj_disable_set = 0; loop_hj_disable_set < (96); loop_hj_disable_set++)
            {
                I3C_HjDisableSet hj_disable_set = API_TEST_table_uint32_t[loop_hj_disable_set];
                /* Check valid-fail conditions */
                if (true)
                {
                    LOG_FIRST("COMMENT: disableCore requires running HW.");
                    return NOTSUP;
                }


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_hjConfigureResponse(&pd, hj_response, hj_disable_set);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->hjConfigureResponse(&pd, hj_response, hj_disable_set);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("hjConfigureResponse: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_hjConfigureResponse(&pd, hj_response, hj_disable_set);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_configureSlaveInterrupts(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->configureSlaveInterrupts == NULL)
    {
        LOG("configureSlaveInterrupts: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t idx_slaveInterruptConfig;
        I3C_SlaveInterruptConfig slaveInterruptConfig;

        for (idx_slaveInterruptConfig = 0; idx_slaveInterruptConfig < 96; idx_slaveInterruptConfig++)
        {
            API_TEST_fill_I3C_SlaveInterruptConfig(&slaveInterruptConfig, idx_slaveInterruptConfig);

            /* Check valid-fail conditions */
            if (true)
            {
                LOG_FIRST("COMMENT: configureSlaveInterrupts requires running HW.");
                return NOTSUP;
            }


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_configureSlaveInterrupts(&pd, &slaveInterruptConfig);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->configureSlaveInterrupts(&pd, &slaveInterruptConfig);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("configureSlaveInterrupts: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_configureSlaveInterrupts(&pd, &slaveInterruptConfig);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_slaveModeConfigure(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->slaveModeConfigure == NULL)
    {
        LOG("slaveModeConfigure: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t idx_slaveInterruptConfig;
        I3C_SlaveInterruptConfig slaveInterruptConfig;

        for (idx_slaveInterruptConfig = 0; idx_slaveInterruptConfig < 96; idx_slaveInterruptConfig++)
        {
            API_TEST_fill_I3C_SlaveInterruptConfig(&slaveInterruptConfig, idx_slaveInterruptConfig);

            /* Check valid-fail conditions */
            if (true)
            {
                LOG_FIRST("COMMENT: disableCore requires running HW.");
                return NOTSUP;
            }


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_slaveModeConfigure(&pd, &slaveInterruptConfig);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->slaveModeConfigure(&pd, &slaveInterruptConfig);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("slaveModeConfigure: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_slaveModeConfigure(&pd, &slaveInterruptConfig);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_slaveModeReqSdrRead(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->slaveModeReqSdrRead == NULL)
    {
        LOG("slaveModeReqSdrRead: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint8_t buf = 0;
        uint32_t loop_num_bytes;

        for (loop_num_bytes = 0; loop_num_bytes < (48); loop_num_bytes++)
        {
            uint16_t num_bytes = API_TEST_table_uint16_t[loop_num_bytes];
            /* Check valid-fail conditions */
            if (true)
            {
                LOG_FIRST("COMMENT: disableCore requires running HW.");
                return NOTSUP;
            }


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_slaveModeReqSdrRead(&pd, &buf, num_bytes);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->slaveModeReqSdrRead(&pd, &buf, num_bytes);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("slaveModeReqSdrRead: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_slaveModeReqSdrRead(&pd, &buf, num_bytes);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_slaveModeReqSdrWrite(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->slaveModeReqSdrWrite == NULL)
    {
        LOG("slaveModeReqSdrWrite: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        const uint8_t buf = 0;
        uint32_t loop_num_bytes;

        for (loop_num_bytes = 0; loop_num_bytes < (48); loop_num_bytes++)
        {
            uint16_t num_bytes = API_TEST_table_uint16_t[loop_num_bytes];
            /* Check valid-fail conditions */
            if (true)
            {
                LOG_FIRST("COMMENT: disableCore requires running HW.");
                return NOTSUP;
            }


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_slaveModeReqSdrWrite(&pd, &buf, num_bytes);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->slaveModeReqSdrWrite(&pd, &buf, num_bytes);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("slaveModeReqSdrWrite: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_slaveModeReqSdrWrite(&pd, &buf, num_bytes);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_slaveModeReqDdrRead(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->slaveModeReqDdrRead == NULL)
    {
        LOG("slaveModeReqDdrRead: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint16_t buf = 0;
        uint32_t loop_num_words;

        for (loop_num_words = 0; loop_num_words < (48); loop_num_words++)
        {
            uint16_t num_words = API_TEST_table_uint16_t[loop_num_words];
            /* Check valid-fail conditions */
            if (true)
            {
                LOG_FIRST("COMMENT: disableCore requires running HW.");
                return NOTSUP;
            }


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_slaveModeReqDdrRead(&pd, &buf, num_words);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->slaveModeReqDdrRead(&pd, &buf, num_words);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("slaveModeReqDdrRead: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_slaveModeReqDdrRead(&pd, &buf, num_words);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_slaveModeReqDdrWrite(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->slaveModeReqDdrWrite == NULL)
    {
        LOG("slaveModeReqDdrWrite: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        const uint16_t buf_in = 0;
        uint32_t loop_num_words_in;

        for (loop_num_words_in = 0; loop_num_words_in < (48); loop_num_words_in++)
        {
            uint16_t num_words_in = API_TEST_table_uint16_t[loop_num_words_in];
            /* Check valid-fail conditions */
            if (true)
            {
                LOG_FIRST("COMMENT: disableCore requires running HW.");
                return NOTSUP;
            }


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_slaveModeReqDdrWrite(&pd, &buf_in, num_words_in);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->slaveModeReqDdrWrite(&pd, &buf_in, num_words_in);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("slaveModeReqDdrWrite: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_slaveModeReqDdrWrite(&pd, &buf_in, num_words_in);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_slaveModeRequestHotJoin(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->slaveModeRequestHotJoin == NULL)
    {
        LOG("slaveModeRequestHotJoin: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        /* Check valid-fail conditions */
        if (true)
        {
            LOG_FIRST("COMMENT: disableCore requires running HW.");
            return NOTSUP;
        }


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_slaveModeRequestHotJoin(&pd);


        if (expectedRet == CDN_EINVAL)
        {

            /* Call function */
            ret = obj->slaveModeRequestHotJoin(&pd);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("slaveModeRequestHotJoin: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_slaveModeRequestHotJoin(&pd);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_slaveModeMastershipReq(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->slaveModeMastershipReq == NULL)
    {
        LOG("slaveModeMastershipReq: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        /* Check valid-fail conditions */
        if (true)
        {
            LOG_FIRST("COMMENT: disableCore requires running HW.");
            return NOTSUP;
        }


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_slaveModeMastershipReq(&pd);


        if (expectedRet == CDN_EINVAL)
        {

            /* Call function */
            ret = obj->slaveModeMastershipReq(&pd);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("slaveModeMastershipReq: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_slaveModeMastershipReq(&pd);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_slaveModeRequestIbi(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->slaveModeRequestIbi == NULL)
    {
        LOG("slaveModeRequestIbi: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_tCam0Event;

        for (loop_tCam0Event = 0; loop_tCam0Event < (24); loop_tCam0Event++)
        {
            uint8_t tCam0Event = API_TEST_table_uint8_t[loop_tCam0Event];
            uint32_t loop_ibiTCam0;

            for (loop_ibiTCam0 = 0; loop_ibiTCam0 < (2); loop_ibiTCam0++)
            {
                bool ibiTCam0 = API_TEST_table_bool[loop_ibiTCam0];
                /* Check valid-fail conditions */
                if (true)
                {
                    LOG_FIRST("COMMENT: disableCore requires running HW.");
                    return NOTSUP;
                }


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_slaveModeRequestIbi(&pd, tCam0Event, ibiTCam0);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->slaveModeRequestIbi(&pd, tCam0Event, ibiTCam0);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("slaveModeRequestIbi: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_slaveModeRequestIbi(&pd, tCam0Event, ibiTCam0);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_slaveModeWriteIbiPayload(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->slaveModeWriteIbiPayload == NULL)
    {
        LOG("slaveModeWriteIbiPayload: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        const uint8_t buf = 0;
        uint32_t loop_numbytes;

        for (loop_numbytes = 0; loop_numbytes < (24); loop_numbytes++)
        {
            uint8_t numbytes = API_TEST_table_uint8_t[loop_numbytes];
            /* Check valid-fail conditions */
            if (true)
            {
                LOG_FIRST("COMMENT: disableCore requires running HW.");
                return NOTSUP;
            }


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_slaveModeWriteIbiPayload(&pd, &buf, numbytes);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->slaveModeWriteIbiPayload(&pd, &buf, numbytes);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("slaveModeWriteIbiPayload: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_slaveModeWriteIbiPayload(&pd, &buf, numbytes);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_slaveModeReadIbiPayload(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->slaveModeReadIbiPayload == NULL)
    {
        LOG("slaveModeReadIbiPayload: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint8_t buf = 0;
        uint32_t loop_numbytes;

        for (loop_numbytes = 0; loop_numbytes < (24); loop_numbytes++)
        {
            uint8_t numbytes = API_TEST_table_uint8_t[loop_numbytes];
            /* Check valid-fail conditions */
            if (true)
            {
                LOG_FIRST("COMMENT: disableCore requires running HW.");
                return NOTSUP;
            }


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_slaveModeReadIbiPayload(&pd, &buf, numbytes);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->slaveModeReadIbiPayload(&pd, &buf, numbytes);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("slaveModeReadIbiPayload: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_slaveModeReadIbiPayload(&pd, &buf, numbytes);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_slaveModeReqFlowControl(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->slaveModeReqFlowControl == NULL)
    {
        LOG("slaveModeReqFlowControl: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_mode;

        for (loop_mode = 0; loop_mode < (96); loop_mode++)
        {
            I3C_FlowControlMode mode = API_TEST_table_uint32_t[loop_mode];
            /* Check valid-fail conditions */
            if (true)
            {
                LOG_FIRST("COMMENT: disableCore requires running HW.");
                return NOTSUP;
            }


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_slaveModeReqFlowControl(&pd, mode);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->slaveModeReqFlowControl(&pd, mode);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("slaveModeReqFlowControl: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_slaveModeReqFlowControl(&pd, mode);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_slaveModeReadApbRo(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->slaveModeReadApbRo == NULL)
    {
        LOG("slaveModeReadApbRo: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_idx;

        for (loop_idx = 0; loop_idx < (48); loop_idx++)
        {
            uint16_t idx = API_TEST_table_uint16_t[loop_idx];
            uint8_t val = 0;


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_slaveModeReadApbRo(&pd, idx, &val);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->slaveModeReadApbRo(&pd, idx, &val);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("slaveModeReadApbRo: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_slaveModeReadApbRo(&pd, idx, &val);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_slaveModeReadApbRw(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->slaveModeReadApbRw == NULL)
    {
        LOG("slaveModeReadApbRw: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_idx;

        for (loop_idx = 0; loop_idx < (48); loop_idx++)
        {
            uint16_t idx = API_TEST_table_uint16_t[loop_idx];
            uint8_t val = 0;


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_slaveModeReadApbRw(&pd, idx, &val);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->slaveModeReadApbRw(&pd, idx, &val);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("slaveModeReadApbRw: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_slaveModeReadApbRw(&pd, idx, &val);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_slaveModeWriteApbRw(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->slaveModeWriteApbRw == NULL)
    {
        LOG("slaveModeWriteApbRw: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_idx;

        for (loop_idx = 0; loop_idx < (48); loop_idx++)
        {
            uint16_t idx = API_TEST_table_uint16_t[loop_idx];
            uint32_t loop_val;

            for (loop_val = 0; loop_val < (24); loop_val++)
            {
                uint8_t val = API_TEST_table_uint8_t[loop_val];


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_slaveModeWriteApbRw(&pd, idx, val);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->slaveModeWriteApbRw(&pd, idx, val);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("slaveModeWriteApbRw: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_slaveModeWriteApbRw(&pd, idx, val);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_slaveModeReadGpo(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->slaveModeReadGpo == NULL)
    {
        LOG("slaveModeReadGpo: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_idx;

        for (loop_idx = 0; loop_idx < (48); loop_idx++)
        {
            uint16_t idx = API_TEST_table_uint16_t[loop_idx];
            uint8_t val = 0;


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_slaveModeReadGpo(&pd, idx, &val);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->slaveModeReadGpo(&pd, idx, &val);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("slaveModeReadGpo: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_slaveModeReadGpo(&pd, idx, &val);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_slaveModeReadGpi(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->slaveModeReadGpi == NULL)
    {
        LOG("slaveModeReadGpi: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_idx;

        for (loop_idx = 0; loop_idx < (48); loop_idx++)
        {
            uint16_t idx = API_TEST_table_uint16_t[loop_idx];
            uint8_t val = 0;


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_slaveModeReadGpi(&pd, idx, &val);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->slaveModeReadGpi(&pd, idx, &val);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("slaveModeReadGpi: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_slaveModeReadGpi(&pd, idx, &val);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_slaveModeReadMWL(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->slaveModeReadMWL == NULL)
    {
        LOG("slaveModeReadMWL: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint16_t maxWriteLength = 0;


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_slaveModeReadMWL(&pd, &maxWriteLength);


        if (expectedRet == CDN_EINVAL)
        {

            /* Call function */
            ret = obj->slaveModeReadMWL(&pd, &maxWriteLength);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("slaveModeReadMWL: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_slaveModeReadMWL(&pd, &maxWriteLength);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_slaveModeReadMRL(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->slaveModeReadMRL == NULL)
    {
        LOG("slaveModeReadMRL: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint16_t maxReadLength = 0;
        uint8_t ibiPayloadSize = 0;


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_slaveModeReadMRL(&pd, &maxReadLength, &ibiPayloadSize);


        if (expectedRet == CDN_EINVAL)
        {

            /* Call function */
            ret = obj->slaveModeReadMRL(&pd, &maxReadLength, &ibiPayloadSize);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("slaveModeReadMRL: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_slaveModeReadMRL(&pd, &maxReadLength, &ibiPayloadSize);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_getFifoFillLvl(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->getFifoFillLvl == NULL)
    {
        LOG("getFifoFillLvl: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint16_t fillLvl_tx = 0;
        uint16_t fillLvl_rx = 0;


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_getFifoFillLvl(&pd, &fillLvl_tx, &fillLvl_rx);


        if (expectedRet == CDN_EINVAL)
        {

            /* Call function */
            ret = obj->getFifoFillLvl(&pd, &fillLvl_tx, &fillLvl_rx);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("getFifoFillLvl: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_getFifoFillLvl(&pd, &fillLvl_tx, &fillLvl_rx);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_setSdrFifoFlush(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->setSdrFifoFlush == NULL)
    {
        LOG("setSdrFifoFlush: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t loop_flush_tx;

        for (loop_flush_tx = 0; loop_flush_tx < (2); loop_flush_tx++)
        {
            bool flush_tx = API_TEST_table_bool[loop_flush_tx];
            uint32_t loop_flush_rx;

            for (loop_flush_rx = 0; loop_flush_rx < (2); loop_flush_rx++)
            {
                bool flush_rx = API_TEST_table_bool[loop_flush_rx];


                /* Display info with iteration number */
                DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

                /* Calculate expected return value */
                expectedRet = API_TEST_expected_setSdrFifoFlush(&pd, flush_tx, flush_rx);


                if (expectedRet == CDN_EINVAL)
                {

                    /* Call function */
                    ret = obj->setSdrFifoFlush(&pd, flush_tx, flush_rx);

                    /* Check returned value */
                    if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                    {
                        if (!API_TEST_loggedFirstFail)
                        {
                            LOG_FIRST("setSdrFifoFlush: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                            LOG("Failed call:");
                            API_TEST_printargs_setSdrFifoFlush(&pd, flush_tx, flush_rx);
                        }

                        return FAIL;
                    }
                    else if (ret == CDN_ENOTSUP)
                    {
                        return NOTSUP;
                    }

                }

            }
        }
    }
    return result;
}



static uint32_t API_TEST_ranges_slaveGetIbiStatus(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->slaveGetIbiStatus == NULL)
    {
        LOG("slaveGetIbiStatus: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint8_t ibi_stat = 0;
        uint8_t hj_stat = 0;
        uint8_t mr_stat = 0;


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_slaveGetIbiStatus(&pd, &ibi_stat, &hj_stat, &mr_stat);


        if (expectedRet == CDN_EINVAL)
        {

            /* Call function */
            ret = obj->slaveGetIbiStatus(&pd, &ibi_stat, &hj_stat, &mr_stat);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("slaveGetIbiStatus: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_slaveGetIbiStatus(&pd, &ibi_stat, &hj_stat, &mr_stat);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}



static uint32_t API_TEST_ranges_getAsfInfo(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->getAsfInfo == NULL)
    {
        LOG("getAsfInfo: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        uint32_t idx_asf_info;
        I3C_AsfInfo asf_info;

        for (idx_asf_info = 0; idx_asf_info < 96; idx_asf_info++)
        {
            API_TEST_fill_I3C_AsfInfo(&asf_info, idx_asf_info);

            /* Check valid-fail conditions */
            if (true)
            {
                LOG_FIRST("COMMENT: getAsfInfo requires running HW.");
                return NOTSUP;
            }


            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Calculate expected return value */
            expectedRet = API_TEST_expected_getAsfInfo(&pd, &asf_info);


            if (expectedRet == CDN_EINVAL)
            {

                /* Call function */
                ret = obj->getAsfInfo(&pd, &asf_info);

                /* Check returned value */
                if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
                {
                    if (!API_TEST_loggedFirstFail)
                    {
                        LOG_FIRST("getAsfInfo: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                        LOG("Failed call:");
                        API_TEST_printargs_getAsfInfo(&pd, &asf_info);
                    }

                    return FAIL;
                }
                else if (ret == CDN_ENOTSUP)
                {
                    return NOTSUP;
                }

            }

        }
    }
    return result;
}



static uint32_t API_TEST_ranges_checkOperationMode(I3C_OBJ *obj, void *__unusedPd)
{
    LOG_FAIL_COUNTER;
    uint32_t ret;
    uint32_t expectedRet;
    uint32_t result = PASS;

    /* Private data is unused */
    __unusedPd = (void *) 0xDEADC0DE;

    /* Check the function pointer first */
    if (obj->checkOperationMode == NULL)
    {
        LOG("checkOperationMode: null function pointer, skipping");
        return NOTSUP;
    }


    uint32_t idx_pd;
    I3C_PrivData pd;

    for (idx_pd = 0; idx_pd < 96; idx_pd++)
    {
        API_TEST_fill_I3C_PrivData(&pd, idx_pd);

        I3C_OperationMode opMode = 0;
        /* Check valid-fail conditions */
        if (true)
        {
            LOG_FIRST("COMMENT: checkOperationMode requires running HW.");
            return NOTSUP;
        }


        /* Display info with iteration number */
        DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

        /* Calculate expected return value */
        expectedRet = API_TEST_expected_checkOperationMode(&pd, &opMode);


        if (expectedRet == CDN_EINVAL)
        {

            /* Call function */
            ret = obj->checkOperationMode(&pd, &opMode);

            /* Check returned value */
            if ((ret != expectedRet) && (ret != CDN_ENOTSUP))
            {
                if (!API_TEST_loggedFirstFail)
                {
                    LOG_FIRST("checkOperationMode: wrong return value. expected: %i, returned %i .",  expectedRet, ret);
                    LOG("Failed call:");
                    API_TEST_printargs_checkOperationMode(&pd, &opMode);
                }

                return FAIL;
            }
            else if (ret == CDN_ENOTSUP)
            {
                return NOTSUP;
            }

        }

    }
    return result;
}


static uint32_t API_TEST_getset_BusMode(I3C_OBJ *obj, void *privateData)
{
    LOG_FAIL_COUNTER;
    uint32_t getResult;
    uint32_t setResult;
    uint32_t setExpectedResult;

    /* Check function pointers */
    if (obj->getBusMode == NULL)
    {
        LOG("getBusMode: NULL function pointer, skipping");
        return NOTSUP;
    }

    if (obj->setBusMode == NULL)
    {
        LOG("setBusMode: NULL function pointer, skipping");
        return NOTSUP;
    }

    /* Test is disabled via yml configuration */
    return NOTSUP;

    uint32_t idx_mode;
    uint32_t values_mode[] = {I3C_BUS_MODE_PURE, I3C_BUS_MODE_INVALID, I3C_BUS_MODE_MIXED_FAST, I3C_BUS_MODE_MIXED_SLOW};

    for (idx_mode = 0; idx_mode < COUNTOF(values_mode); idx_mode++)
    {
        I3C_BusMode mode = (I3C_BusMode)values_mode[idx_mode];

        /* Check valid-fail conditions */
        if (true)
        {
            LOG_FIRST("COMMENT: disableCore requires running HW.");
            return NOTSUP;
        }


        /* Set get params: */
        I3C_BusMode get_mode = mode;

        /* Get set expected result */
        setExpectedResult = API_TEST_expected_setBusMode(privateData, mode);


        if (setExpectedResult == CDN_EINVAL)
        {

            /* Display info with iteration number */
            DBG_PRINT_TEST_FUNCTION_CALL_COUNTER;

            /* Call set */
            setResult = obj->setBusMode(privateData, mode);

            if ((setResult != setExpectedResult) && (setResult != CDN_ENOTSUP))
            {
                LOG_FIRST("setBusMode: failed, function returned: %" PRIu32, setResult);
                return FAIL;
            }
            else if (setResult == CDN_EINVAL)
            {
                LOG_FIRST("setBusMode: some 'get' calls disabled by valid-fail directive");
                continue;
            }
            else if (setResult == CDN_ENOTSUP)
            {
                LOG_FIRST("setBusMode: not supported");
                return NOTSUP;
            }

            /* Call get */
            getResult = obj->getBusMode(privateData, &get_mode);

            if ((getResult != 0) && (getResult != CDN_ENOTSUP))
            {
                LOG_FIRST("getBusMode: failed, function returned: %" PRIu32, getResult);
                return FAIL;
            }
            else if (getResult == CDN_ENOTSUP)
            {
                LOG_FIRST("getBusMode: not supported");
                return NOTSUP;
            }

            /* Compare results */
        }

    }

    return PASS;
}

/* NULL pointer tests */


uint32_t API_TEST_nullptr(I3C_OBJ *obj)
{
    uint32_t ret, i;
    struct
    {
        API_TEST_internal test;
        const char *name;
        bool disabled;
    } tests[] =
    {
        {&API_TEST_nullptr_probe, "probe", false },
        {&API_TEST_nullptr_init, "init", false },
        {&API_TEST_nullptr_isr, "isr", false },
        {&API_TEST_nullptr_start, "start", false },
        {&API_TEST_nullptr_stop, "stop", false },
        {&API_TEST_nullptr_destroy, "destroy", false },
        {&API_TEST_nullptr_enableCore, "enableCore", false },
        {&API_TEST_nullptr_disableCore, "disableCore", false },
        {&API_TEST_nullptr_setBusMode, "setBusMode", false },
        {&API_TEST_nullptr_getBusMode, "getBusMode", false },
        {&API_TEST_nullptr_setBcr, "setBcr", false },
        {&API_TEST_nullptr_setDcr, "setDcr", false },
        {&API_TEST_nullptr_setPid, "setPid", false },
        {&API_TEST_nullptr_configureDevices, "configureDevices", false },
        {&API_TEST_nullptr_configureDevice, "configureDevice", false },
        {&API_TEST_nullptr_configurePrescalers, "configurePrescalers", false },
        {&API_TEST_nullptr_clearRrOfDevice, "clearRrOfDevice", false },
        {&API_TEST_nullptr_getNewDevices, "getNewDevices", false },
        {&API_TEST_nullptr_configureInterrupts, "configureInterrupts", false },
        {&API_TEST_nullptr_configureThresholds, "configureThresholds", false },
        {&API_TEST_nullptr_cmdExec, "cmdExec", false },
        {&API_TEST_nullptr_cmdExecImmediate, "cmdExecImmediate", false },
        {&API_TEST_nullptr_enableMcs, "enableMcs", false },
        {&API_TEST_nullptr_disableMcs, "disableMcs", false },
        {&API_TEST_nullptr_manualCommandStart, "manualCommandStart", false },
        {&API_TEST_nullptr_cmdCount, "cmdCount", false },
        {&API_TEST_nullptr_cmdMaxCount, "cmdMaxCount", false },
        {&API_TEST_nullptr_cmdClearAll, "cmdClearAll", false },
        {&API_TEST_nullptr_devPrint, "devPrint", false },
        {&API_TEST_nullptr_enableTc, "enableTc", false },
        {&API_TEST_nullptr_cmdAddPrivWrite, "cmdAddPrivWrite", false },
        {&API_TEST_nullptr_cmdAddPrivRead, "cmdAddPrivRead", false },
        {&API_TEST_nullptr_cmdAddPrivI2CWrite, "cmdAddPrivI2CWrite", false },
        {&API_TEST_nullptr_cmdAddPrivI2CRead, "cmdAddPrivI2CRead", false },
        {&API_TEST_nullptr_cmdAddDdrWrite, "cmdAddDdrWrite", false },
        {&API_TEST_nullptr_cmdAddDdrRead, "cmdAddDdrRead", false },
        {&API_TEST_nullptr_cmdAddSetSlaveEvents, "cmdAddSetSlaveEvents", false },
        {&API_TEST_nullptr_cmdAddEnterActivityState, "cmdAddEnterActivityState", false },
        {&API_TEST_nullptr_cmdAddResetDaa, "cmdAddResetDaa", false },
        {&API_TEST_nullptr_cmdAddEnterDaa, "cmdAddEnterDaa", false },
        {&API_TEST_nullptr_cmdAddSetMaxWriteLength, "cmdAddSetMaxWriteLength", false },
        {&API_TEST_nullptr_cmdAddGetMaxWriteLength, "cmdAddGetMaxWriteLength", false },
        {&API_TEST_nullptr_cmdAddSetMaxReadLength, "cmdAddSetMaxReadLength", false },
        {&API_TEST_nullptr_cmdAddGetMaxReadLength, "cmdAddGetMaxReadLength", false },
        {&API_TEST_nullptr_cmdAddGetMaxDataSpeed, "cmdAddGetMaxDataSpeed", false },
        {&API_TEST_nullptr_getSlavesList, "getSlavesList", false },
        {&API_TEST_nullptr_cmdAddDefineSlavesList, "cmdAddDefineSlavesList", false },
        {&API_TEST_nullptr_cmdAddEnterTestMode, "cmdAddEnterTestMode", false },
        {&API_TEST_nullptr_cmdAddSetBuscon, "cmdAddSetBuscon", false },
        {&API_TEST_nullptr_cmdAddEnterHdrMode, "cmdAddEnterHdrMode", false },
        {&API_TEST_nullptr_cmdAddSetAaSa, "cmdAddSetAaSa", false },
        {&API_TEST_nullptr_cmdSetDaFromSa, "cmdSetDaFromSa", false },
        {&API_TEST_nullptr_cmdAddSetNewDa, "cmdAddSetNewDa", false },
        {&API_TEST_nullptr_cmdAddSetRstAct, "cmdAddSetRstAct", false },
        {&API_TEST_nullptr_cmdAddSetXTime, "cmdAddSetXTime", false },
        {&API_TEST_nullptr_cmdAddSetGroupAddr, "cmdAddSetGroupAddr", false },
        {&API_TEST_nullptr_cmdAddDefineGroupList, "cmdAddDefineGroupList", false },
        {&API_TEST_nullptr_cmdAddResetGrpa, "cmdAddResetGrpa", false },
        {&API_TEST_nullptr_cmdAddGetProvisionalId, "cmdAddGetProvisionalId", false },
        {&API_TEST_nullptr_cmdAddGetBcr, "cmdAddGetBcr", false },
        {&API_TEST_nullptr_cmdAddGetDcr, "cmdAddGetDcr", false },
        {&API_TEST_nullptr_cmdAddGetStatus, "cmdAddGetStatus", false },
        {&API_TEST_nullptr_cmdAddGetAccMst, "cmdAddGetAccMst", false },
        {&API_TEST_nullptr_cmdAddGetXTime, "cmdAddGetXTime", false },
        {&API_TEST_nullptr_CmdSetNCAMode, "CmdSetNCAMode", false },
        {&API_TEST_nullptr_ibiConfigureDevices, "ibiConfigureDevices", false },
        {&API_TEST_nullptr_ibiModifyDeviceConfig, "ibiModifyDeviceConfig", false },
        {&API_TEST_nullptr_ibiGetAddressOfIssuer, "ibiGetAddressOfIssuer", false },
        {&API_TEST_nullptr_ibiGetData, "ibiGetData", false },
        {&API_TEST_nullptr_hjConfigureResponse, "hjConfigureResponse", false },
        {&API_TEST_nullptr_configureSlaveInterrupts, "configureSlaveInterrupts", false },
        {&API_TEST_nullptr_slaveModeConfigure, "slaveModeConfigure", false },
        {&API_TEST_nullptr_slaveModeReqSdrRead, "slaveModeReqSdrRead", false },
        {&API_TEST_nullptr_slaveModeReqSdrWrite, "slaveModeReqSdrWrite", false },
        {&API_TEST_nullptr_slaveModeReqDdrRead, "slaveModeReqDdrRead", false },
        {&API_TEST_nullptr_slaveModeReqDdrWrite, "slaveModeReqDdrWrite", false },
        {&API_TEST_nullptr_slaveModeRequestHotJoin, "slaveModeRequestHotJoin", false },
        {&API_TEST_nullptr_slaveModeMastershipReq, "slaveModeMastershipReq", false },
        {&API_TEST_nullptr_slaveModeRequestIbi, "slaveModeRequestIbi", false },
        {&API_TEST_nullptr_slaveModeWriteIbiPayload, "slaveModeWriteIbiPayload", false },
        {&API_TEST_nullptr_slaveModeReadIbiPayload, "slaveModeReadIbiPayload", false },
        {&API_TEST_nullptr_slaveModeReqFlowControl, "slaveModeReqFlowControl", false },
        {&API_TEST_nullptr_slaveModeReadApbRo, "slaveModeReadApbRo", false },
        {&API_TEST_nullptr_slaveModeReadApbRw, "slaveModeReadApbRw", false },
        {&API_TEST_nullptr_slaveModeWriteApbRw, "slaveModeWriteApbRw", false },
        {&API_TEST_nullptr_slaveModeReadGpo, "slaveModeReadGpo", false },
        {&API_TEST_nullptr_slaveModeReadGpi, "slaveModeReadGpi", false },
        {&API_TEST_nullptr_slaveModeReadMWL, "slaveModeReadMWL", false },
        {&API_TEST_nullptr_slaveModeReadMRL, "slaveModeReadMRL", false },
        {&API_TEST_nullptr_getFifoFillLvl, "getFifoFillLvl", false },
        {&API_TEST_nullptr_setSdrFifoFlush, "setSdrFifoFlush", false },
        {&API_TEST_nullptr_slaveGetIbiStatus, "slaveGetIbiStatus", false },
        {&API_TEST_nullptr_getAsfInfo, "getAsfInfo", false },
        {&API_TEST_nullptr_checkOperationMode, "checkOperationMode", false },
    };

    memset(&testData[0], 0, sizeof(TestData));

    if (94 > 0)
    {
        testData[0].groupName = "nullptr";
        testData[0].groupIndex = 0;
        START_TESTING(testData[0]);
    }
    else
    {
        return 0;
    }

    for (i = 0; i < 94; i++)
    {
        TESTING_RUNNING_TEST_EX(tests[i].name, testData[0], (i+1), 94);
        if (tests[i].disabled)
            ret = NOTSUP;
        else
            ret = API_TEST_generic(obj, tests[i].test);

        switch (ret)
        {
        case PASS:
            TESTING_TEST_PASSED(tests[i].name, testData[0]);
            break;
        case NOTSUP:
            TESTING_TEST_NOTSUP(tests[i].name, testData[0]);
            break;
        default:
            TESTING_TEST_FAILED(tests[i].name, testData[0]);
            break;
        }
    }
    TESTING_SUMMARY(testData[0]);
    return 0;
}



/* Range check tests */


uint32_t API_TEST_ranges(I3C_OBJ *obj)
{
    uint32_t ret, i;
    struct
    {
        API_TEST_internal test;
        const char *name;
        bool disabled;
    } tests[] =
    {
        {&API_TEST_ranges_probe, "probe", false },
        {&API_TEST_ranges_init, "init", false },
        {&API_TEST_ranges_isr, "isr", false },
        {&API_TEST_ranges_start, "start", false },
        {&API_TEST_ranges_stop, "stop", false },
        {&API_TEST_ranges_destroy, "destroy", false },
        {&API_TEST_ranges_enableCore, "enableCore", false },
        {&API_TEST_ranges_disableCore, "disableCore", false },
        {&API_TEST_ranges_setBusMode, "setBusMode", false },
        {&API_TEST_ranges_getBusMode, "getBusMode", false },
        {&API_TEST_ranges_setBcr, "setBcr", false },
        {&API_TEST_ranges_setDcr, "setDcr", false },
        {&API_TEST_ranges_setPid, "setPid", false },
        {&API_TEST_ranges_configureDevices, "configureDevices", false },
        {&API_TEST_ranges_configureDevice, "configureDevice", false },
        {&API_TEST_ranges_configurePrescalers, "configurePrescalers", false },
        {&API_TEST_ranges_clearRrOfDevice, "clearRrOfDevice", false },
        {&API_TEST_ranges_getNewDevices, "getNewDevices", false },
        {&API_TEST_ranges_configureInterrupts, "configureInterrupts", false },
        {&API_TEST_ranges_configureThresholds, "configureThresholds", false },
        {&API_TEST_ranges_cmdExec, "cmdExec", false },
        {&API_TEST_ranges_cmdExecImmediate, "cmdExecImmediate", false },
        {&API_TEST_ranges_enableMcs, "enableMcs", false },
        {&API_TEST_ranges_disableMcs, "disableMcs", false },
        {&API_TEST_ranges_manualCommandStart, "manualCommandStart", false },
        {&API_TEST_ranges_cmdCount, "cmdCount", false },
        {&API_TEST_ranges_cmdMaxCount, "cmdMaxCount", false },
        {&API_TEST_ranges_cmdClearAll, "cmdClearAll", false },
        {&API_TEST_ranges_devPrint, "devPrint", false },
        {&API_TEST_ranges_enableTc, "enableTc", false },
        {&API_TEST_ranges_cmdAddPrivWrite, "cmdAddPrivWrite", false },
        {&API_TEST_ranges_cmdAddPrivRead, "cmdAddPrivRead", false },
        {&API_TEST_ranges_cmdAddPrivI2CWrite, "cmdAddPrivI2CWrite", false },
        {&API_TEST_ranges_cmdAddPrivI2CRead, "cmdAddPrivI2CRead", false },
        {&API_TEST_ranges_cmdAddDdrWrite, "cmdAddDdrWrite", false },
        {&API_TEST_ranges_cmdAddDdrRead, "cmdAddDdrRead", false },
        {&API_TEST_ranges_cmdAddSetSlaveEvents, "cmdAddSetSlaveEvents", false },
        {&API_TEST_ranges_cmdAddEnterActivityState, "cmdAddEnterActivityState", false },
        {&API_TEST_ranges_cmdAddResetDaa, "cmdAddResetDaa", false },
        {&API_TEST_ranges_cmdAddEnterDaa, "cmdAddEnterDaa", false },
        {&API_TEST_ranges_cmdAddSetMaxWriteLength, "cmdAddSetMaxWriteLength", false },
        {&API_TEST_ranges_cmdAddGetMaxWriteLength, "cmdAddGetMaxWriteLength", false },
        {&API_TEST_ranges_cmdAddSetMaxReadLength, "cmdAddSetMaxReadLength", false },
        {&API_TEST_ranges_cmdAddGetMaxReadLength, "cmdAddGetMaxReadLength", false },
        {&API_TEST_ranges_cmdAddGetMaxDataSpeed, "cmdAddGetMaxDataSpeed", false },
        {&API_TEST_ranges_getSlavesList, "getSlavesList", false },
        {&API_TEST_ranges_cmdAddDefineSlavesList, "cmdAddDefineSlavesList", false },
        {&API_TEST_ranges_cmdAddEnterTestMode, "cmdAddEnterTestMode", false },
        {&API_TEST_ranges_cmdAddSetBuscon, "cmdAddSetBuscon", false },
        {&API_TEST_ranges_cmdAddEnterHdrMode, "cmdAddEnterHdrMode", false },
        {&API_TEST_ranges_cmdAddSetAaSa, "cmdAddSetAaSa", false },
        {&API_TEST_ranges_cmdSetDaFromSa, "cmdSetDaFromSa", false },
        {&API_TEST_ranges_cmdAddSetNewDa, "cmdAddSetNewDa", false },
        {&API_TEST_ranges_cmdAddSetRstAct, "cmdAddSetRstAct", false },
        {&API_TEST_ranges_cmdAddSetXTime, "cmdAddSetXTime", false },
        {&API_TEST_ranges_cmdAddSetGroupAddr, "cmdAddSetGroupAddr", false },
        {&API_TEST_ranges_cmdAddDefineGroupList, "cmdAddDefineGroupList", false },
        {&API_TEST_ranges_cmdAddResetGrpa, "cmdAddResetGrpa", false },
        {&API_TEST_ranges_cmdAddGetProvisionalId, "cmdAddGetProvisionalId", false },
        {&API_TEST_ranges_cmdAddGetBcr, "cmdAddGetBcr", false },
        {&API_TEST_ranges_cmdAddGetDcr, "cmdAddGetDcr", false },
        {&API_TEST_ranges_cmdAddGetStatus, "cmdAddGetStatus", false },
        {&API_TEST_ranges_cmdAddGetAccMst, "cmdAddGetAccMst", false },
        {&API_TEST_ranges_cmdAddGetXTime, "cmdAddGetXTime", false },
        {&API_TEST_ranges_CmdSetNCAMode, "CmdSetNCAMode", false },
        {&API_TEST_ranges_ibiConfigureDevices, "ibiConfigureDevices", false },
        {&API_TEST_ranges_ibiModifyDeviceConfig, "ibiModifyDeviceConfig", false },
        {&API_TEST_ranges_ibiGetAddressOfIssuer, "ibiGetAddressOfIssuer", false },
        {&API_TEST_ranges_ibiGetData, "ibiGetData", false },
        {&API_TEST_ranges_hjConfigureResponse, "hjConfigureResponse", false },
        {&API_TEST_ranges_configureSlaveInterrupts, "configureSlaveInterrupts", false },
        {&API_TEST_ranges_slaveModeConfigure, "slaveModeConfigure", false },
        {&API_TEST_ranges_slaveModeReqSdrRead, "slaveModeReqSdrRead", false },
        {&API_TEST_ranges_slaveModeReqSdrWrite, "slaveModeReqSdrWrite", false },
        {&API_TEST_ranges_slaveModeReqDdrRead, "slaveModeReqDdrRead", false },
        {&API_TEST_ranges_slaveModeReqDdrWrite, "slaveModeReqDdrWrite", false },
        {&API_TEST_ranges_slaveModeRequestHotJoin, "slaveModeRequestHotJoin", false },
        {&API_TEST_ranges_slaveModeMastershipReq, "slaveModeMastershipReq", false },
        {&API_TEST_ranges_slaveModeRequestIbi, "slaveModeRequestIbi", false },
        {&API_TEST_ranges_slaveModeWriteIbiPayload, "slaveModeWriteIbiPayload", false },
        {&API_TEST_ranges_slaveModeReadIbiPayload, "slaveModeReadIbiPayload", false },
        {&API_TEST_ranges_slaveModeReqFlowControl, "slaveModeReqFlowControl", false },
        {&API_TEST_ranges_slaveModeReadApbRo, "slaveModeReadApbRo", false },
        {&API_TEST_ranges_slaveModeReadApbRw, "slaveModeReadApbRw", false },
        {&API_TEST_ranges_slaveModeWriteApbRw, "slaveModeWriteApbRw", false },
        {&API_TEST_ranges_slaveModeReadGpo, "slaveModeReadGpo", false },
        {&API_TEST_ranges_slaveModeReadGpi, "slaveModeReadGpi", false },
        {&API_TEST_ranges_slaveModeReadMWL, "slaveModeReadMWL", false },
        {&API_TEST_ranges_slaveModeReadMRL, "slaveModeReadMRL", false },
        {&API_TEST_ranges_getFifoFillLvl, "getFifoFillLvl", false },
        {&API_TEST_ranges_setSdrFifoFlush, "setSdrFifoFlush", false },
        {&API_TEST_ranges_slaveGetIbiStatus, "slaveGetIbiStatus", false },
        {&API_TEST_ranges_getAsfInfo, "getAsfInfo", false },
        {&API_TEST_ranges_checkOperationMode, "checkOperationMode", false },
    };

    memset(&testData[1], 0, sizeof(TestData));

    if (94 > 0)
    {
        testData[1].groupName = "ranges";
        testData[1].groupIndex = 1;
        START_TESTING(testData[1]);
    }
    else
    {
        return 0;
    }

    for (i = 0; i < 94; i++)
    {
        TESTING_RUNNING_TEST_EX(tests[i].name, testData[1], (i+1), 94);
        if (tests[i].disabled)
            ret = NOTSUP;
        else
            ret = API_TEST_generic(obj, tests[i].test);

        switch (ret)
        {
        case PASS:
            TESTING_TEST_PASSED(tests[i].name, testData[1]);
            break;
        case NOTSUP:
            TESTING_TEST_NOTSUP(tests[i].name, testData[1]);
            break;
        default:
            TESTING_TEST_FAILED(tests[i].name, testData[1]);
            break;
        }
    }
    TESTING_SUMMARY(testData[1]);
    return 0;
}



/* Get/set tests */


uint32_t API_TEST_getset(I3C_OBJ *obj)
{
    uint32_t ret, i;
    struct
    {
        API_TEST_internal test;
        const char *name;
        bool disabled;
    } tests[] =
    {
        {&API_TEST_getset_BusMode, "BusMode", true },
    };

    memset(&testData[2], 0, sizeof(TestData));

    if (1 > 0)
    {
        testData[2].groupName = "getset";
        testData[2].groupIndex = 2;
        START_TESTING(testData[2]);
    }
    else
    {
        return 0;
    }

    for (i = 0; i < 1; i++)
    {
        TESTING_RUNNING_TEST_EX(tests[i].name, testData[2], (i+1), 1);
        if (tests[i].disabled)
            ret = NOTSUP;
        else
            ret = API_TEST_generic(obj, tests[i].test);

        switch (ret)
        {
        case PASS:
            TESTING_TEST_PASSED(tests[i].name, testData[2]);
            break;
        case NOTSUP:
            TESTING_TEST_NOTSUP(tests[i].name, testData[2]);
            break;
        default:
            TESTING_TEST_FAILED(tests[i].name, testData[2]);
            break;
        }
    }
    TESTING_SUMMARY(testData[2]);
    return 0;
}


int runAllMechanicalTests(void)
{
    I3C_OBJ *obj;

    uint32_t ret, i;

    ret = 0; /* the function result - assume OK */

    /* variables using for summary */
    uint32_t executed, passed, failed, notsup;

    obj = I3C_GetInstance();

    API_TEST_printTables();

    API_TEST_nullptr(obj);
    API_TEST_getset(obj);
    API_TEST_ranges(obj);

    printf("\n----- TEST GROUPS RESULTS: ----\n");
    for (i = 0; i < sizeof(testData) / sizeof(TestData); ++i)
    {
        if (testData[i].calls)
        {
            printf("%s: ", testData[i].groupName);
            printf("%d executed", testData[i].calls);
            printf(", %d passed", testData[i].calls - testData[i].failed - testData[i].notsup);
            printf(", %d failed", testData[i].failed);
            printf("\n");
            ret += testData[i].failed;
        }
    }

    executed = passed = failed = notsup = 0;
    printf("\n---- OVERALL TESTS RESULTS: ----\n");
    for (i = 0; i < sizeof(testData) / sizeof(TestData); ++i)
    {
        if (testData[i].calls)
        {
            executed +=  testData[i].calls;
            failed += testData[i].failed;
            notsup += testData[i].notsup;
        }
    }
    printf("%d tests executed\n", executed);
    printf("%d tests passed\n", executed - failed - notsup);
    printf("%d failed\n", failed);
    printf("%d not supported\n", notsup);
    printf("\n--------------------------------\n");

    return ret;
}
