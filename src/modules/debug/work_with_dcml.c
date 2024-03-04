#include "./../include/common.h"
#include "./debug.h"

static char *pars_service_mantiss(s21_decimal value, char *math_str);
static void insert_dot(char *str, int pos);
static char *decimal_bits(int index);

void printd(s21_decimal value, char *new_line) {
  char result[100];
  char *temp;
  sprintf(result, "%s", "0");
  for (int i = 0; i < ((DEC_SIZE - 1) * UINT_BITS); i++) {
    if (GET_DEC_BIT(value, i)) {
      char *bit = decimal_bits(i);
      temp = add(result, bit);
      sprintf(result, "%s", temp);
      free(temp);
      free(bit);
    }
  }

  temp = pars_service_mantiss(value, result);
  printf("%s%s", temp, new_line);
  free(temp);
}

static char *pars_service_mantiss(s21_decimal value, char *math_str) {
  char *result = (char *)calloc(strlen(math_str) + 1, sizeof(char));
  sprintf(result, "%s", math_str);

  int scale = (value.bits[DEC_SIZE - 1] << 1) >> 17;
  int sign = value.bits[DEC_SIZE - 1] >> 31;
  int len = strlen(result);

  if (scale > (DEC_SIZE - 1) * 10) {
    sprintf(result, "%s", "0");
  } else if (scale == len) {
    result = (char *)realloc(result, 103 * sizeof(char));
    sprintf(result, "0.%s", math_str);
  } else if (scale < len) {
    result = (char *)realloc(result, 103 * sizeof(char));
    insert_dot(result, len - scale);
  } else if (scale > len) {
    result = (char *)realloc(result, 103 * sizeof(char));
    char temp[scale + 4];
    for (int i = 0; i < scale - len; i++) {
      strcpy(temp, result);
      sprintf(result, "0%s", temp);
    }
    strcpy(temp, result);
    sprintf(result, "0.%s", temp);
  }

  if (sign) {
    result = (char *)realloc(result, (strlen(result) + 2) * sizeof(char));
    char temp[strlen(result) + 2];
    strcpy(temp, result);
    sprintf(result, "-%s", temp);
  }

  return result;
}

static void insert_dot(char *str, int pos) {
  for (int i = strlen(str); i >= pos; --i) {
    str[i + 1] = str[i];
  }

  if (str[pos] != '\0') {
    str[pos] = '.';
  }
}

s21_decimal filld(char *input) {
  s21_decimal num = {{0x0}};
  char *mantiss;

  int sign = 0;
  int scale = 0;

  if (input[0] == '-') {
    sign = 1;
    input++;
  }

  int len = strlen(input);
  char full[len + 1];
  sprintf(full, "%s", input);
  char *dot = strchr(full, '.');
  if (dot) {
    scale = strlen(dot) - 1;
    dot[0] = '\0';
  }
  mantiss = divide(full, decimal_bits((DEC_SIZE - 1) * UINT_BITS));
  if (strlen(mantiss) > 1 || mantiss[0] - '0' != 0) {
    fprintf(stderr, "\nERROR: Number %s exceeds of decimal size.\n", input);
    free(mantiss);
    exit(1);
  }
  if (dot) {
    int shift = len - strlen(full) - 1;
    for (int i = 0; i < shift; i++) {
      char remind = dot[i + 1];
      dot[i + 1] = dot[i];
      dot[i] = remind;
    }
  }

  free(mantiss);
  mantiss = divide(full, decimal_bits((DEC_SIZE - 1) * UINT_BITS));
  while (strlen(mantiss) > 1 || mantiss[0] - '0' != 0) {
    free(mantiss);
    full[strlen(full) - 1] = '\0';
    mantiss = divide(full, decimal_bits((DEC_SIZE - 1) * UINT_BITS));
    scale--;
  }

  for (int i = DEC_SIZE - 2; i >= 0; i--) {
    free(mantiss);
    if (i == 0) {
      num.bits[i] = atoi(full);
    } else {
      mantiss = divide(full, decimal_bits(i * 32));
      num.bits[i] = atoi(mantiss);
      char *temp = multiply(mantiss, decimal_bits(i * 32));
      char *temp2 = subtract(full, temp);
      sprintf(full, "%s", temp2);
      free(temp);
      free(temp2);
    }
  }

  num.bits[DEC_SIZE - 1] = (scale << 16) | (sign << (UINT_BITS - 1));

  return num;
}

void printLd(uint192_t value, char *new_line) {
  char result[100];
  char *temp;
  sprintf(result, "%s", "0");
  for (int i = 0; i < (LDEC_SIZE * UINT_BITS); i++) {
    if (IS_SET_BIT(value, i)) {
      char *bit = decimal_bits(i);
      temp = add(result, bit);
      sprintf(result, "%s", temp);
      free(temp);
      free(bit);
    }
  }

  printf("%s%s", result, new_line);
}

static char *decimal_bits(int index) {
  char bits[192][60] = {
      "1",                                                           // 2^0
      "2",                                                           // 2^1
      "4",                                                           // 2^2
      "8",                                                           // 2^3
      "16",                                                          // 2^4
      "32",                                                          // 2^5
      "64",                                                          // 2^6
      "128",                                                         // 2^7
      "256",                                                         // 2^8
      "512",                                                         // 2^9
      "1024",                                                        // 2^10
      "2048",                                                        // 2^11
      "4096",                                                        // 2^12
      "8192",                                                        // 2^13
      "16384",                                                       // 2^14
      "32768",                                                       // 2^15
      "65536",                                                       // 2^16
      "131072",                                                      // 2^17
      "262144",                                                      // 2^18
      "524288",                                                      // 2^19
      "1048576",                                                     // 2^20
      "2097152",                                                     // 2^21
      "4194304",                                                     // 2^22
      "8388608",                                                     // 2^23
      "16777216",                                                    // 2^24
      "33554432",                                                    // 2^25
      "67108864",                                                    // 2^26
      "134217728",                                                   // 2^27
      "268435456",                                                   // 2^28
      "536870912",                                                   // 2^29
      "1073741824",                                                  // 2^30
      "2147483648",                                                  // 2^31
      "4294967296",                                                  // 2^32
      "8589934592",                                                  // 2^33
      "17179869184",                                                 // 2^34
      "34359738368",                                                 // 2^35
      "68719476736",                                                 // 2^36
      "137438953472",                                                // 2^37
      "274877906944",                                                // 2^38
      "549755813888",                                                // 2^39
      "1099511627776",                                               // 2^40
      "2199023255552",                                               // 2^41
      "4398046511104",                                               // 2^42
      "8796093022208",                                               // 2^43
      "17592186044416",                                              // 2^44
      "35184372088832",                                              // 2^45
      "70368744177664",                                              // 2^46
      "140737488355328",                                             // 2^47
      "281474976710656",                                             // 2^48
      "562949953421312",                                             // 2^49
      "1125899906842624",                                            // 2^50
      "2251799813685248",                                            // 2^51
      "4503599627370496",                                            // 2^52
      "9007199254740992",                                            // 2^53
      "18014398509481984",                                           // 2^54
      "36028797018963968",                                           // 2^55
      "72057594037927936",                                           // 2^56
      "144115188075855872",                                          // 2^57
      "288230376151711744",                                          // 2^58
      "576460752303423488",                                          // 2^59
      "1152921504606846976",                                         // 2^60
      "2305843009213693952",                                         // 2^61
      "4611686018427387904",                                         // 2^62
      "9223372036854775808",                                         // 2^63
      "18446744073709551616",                                        // 2^64
      "36893488147419103232",                                        // 2^65
      "73786976294838206464",                                        // 2^66
      "147573952589676412928",                                       // 2^67
      "295147905179352825856",                                       // 2^68
      "590295810358705651712",                                       // 2^69
      "1180591620717411303424",                                      // 2^70
      "2361183241434822606848",                                      // 2^71
      "4722366482869645213696",                                      // 2^72
      "9444732965739290427392",                                      // 2^73
      "18889465931478580854784",                                     // 2^74
      "37778931862957161709568",                                     // 2^75
      "75557863725914323419136",                                     // 2^76
      "151115727451828646838272",                                    // 2^77
      "302231454903657293676544",                                    // 2^78
      "604462909807314587353088",                                    // 2^79
      "1208925819614629174706176",                                   // 2^80
      "2417851639229258349412352",                                   // 2^81
      "4835703278458516698824704",                                   // 2^82
      "9671406556917033397649408",                                   // 2^83
      "19342813113834066795298816",                                  // 2^84
      "38685626227668133590597632",                                  // 2^85
      "77371252455336267181195264",                                  // 2^86
      "154742504910672534362390528",                                 // 2^87
      "309485009821345068724781056",                                 // 2^88
      "618970019642690137449562112",                                 // 2^89
      "1237940039285380274899124224",                                // 2^90
      "2475880078570760549798248448",                                // 2^91
      "4951760157141521099596496896",                                // 2^92
      "9903520314283042199192993792",                                // 2^93
      "19807040628566084398385987584",                               // 2^94
      "39614081257132168796771975168",                               // 2^95
      "79228162514264337593543950336",                               // 2^96
      "158456325028528675187087900672",                              // 2^97
      "316912650057057350374175801344",                              // 2^98
      "633825300114114700748351602688",                              // 2^99
      "1267650600228229401496703205376",                             // 2^100
      "2535301200456458802993406410752",                             // 2^101
      "5070602400912917605986812821504",                             // 2^102
      "10141204801825835211973625643008",                            // 2^103
      "20282409603651670423947251286016",                            // 2^104
      "40564819207303340847894502572032",                            // 2^105
      "81129638414606681695789005144064",                            // 2^106
      "162259276829213363391578010288128",                           // 2^107
      "324518553658426726783156020576256",                           // 2^108
      "649037107316853453566312041152512",                           // 2^109
      "1298074214633706907132624082305024",                          // 2^110
      "2596148429267413814265248164610048",                          // 2^111
      "5192296858534827628530496329220096",                          // 2^112
      "10384593717069655257060992658440192",                         // 2^113
      "20769187434139310514121985316880384",                         // 2^114
      "41538374868278621028243970633760768",                         // 2^115
      "83076749736557242056487941267521536",                         // 2^116
      "166153499473114484112975882535043072",                        // 2^117
      "332306998946228968225951765070086144",                        // 2^118
      "664613997892457936451903530140172288",                        // 2^119
      "1329227995784915872903807060280344576",                       // 2^120
      "2658455991569831745807614120560689152",                       // 2^121
      "5316911983139663491615228241121378304",                       // 2^122
      "10633823966279326983230456482242756608",                      // 2^123
      "21267647932558653966460912964485513216",                      // 2^124
      "42535295865117307932921825928971026432",                      // 2^125
      "85070591730234615865843651857942052864",                      // 2^126
      "170141183460469231731687303715884105728",                     // 2^127
      "340282366920938463463374607431768211456",                     // 2^128
      "680564733841876926926749214863536422912",                     // 2^129
      "1361129467683753853853498429727072845824",                    // 2^130
      "2722258935367507707706996859454145691648",                    // 2^131
      "5444517870735015415413993718908291383296",                    // 2^132
      "10889035741470030830827987437816582766592",                   // 2^133
      "21778071482940061661655974875633165533184",                   // 2^134
      "43556142965880123323311949751266331066368",                   // 2^135
      "87112285931760246646623899502532662132736",                   // 2^136
      "174224571863520493293247799005065324265472",                  // 2^137
      "348449143727040986586495598010130648530944",                  // 2^138
      "696898287454081973172991196020261297061888",                  // 2^139
      "1393796574908163946345982392040522594123776",                 // 2^140
      "2787593149816327892691964784081045188247552",                 // 2^141
      "5575186299632655785383929568162090376495104",                 // 2^142
      "11150372599265311570767859136324180752990208",                // 2^143
      "22300745198530623141535718272648361505980416",                // 2^144
      "44601490397061246283071436545296723011960832",                // 2^145
      "89202980794122492566142873090593446023921664",                // 2^146
      "178405961588244985132285746181186892047843328",               // 2^147
      "356811923176489970264571492362373784095686656",               // 2^148
      "713623846352979940529142984724747568191373312",               // 2^149
      "1427247692705959881058285969449495136382746624",              // 2^150
      "2854495385411919762116571938898990272765493248",              // 2^151
      "5708990770823839524233143877797980545530986496",              // 2^152
      "11417981541647679048466287755595961091061972992",             // 2^153
      "22835963083295358096932575511191922182123945984",             // 2^154
      "45671926166590716193865151022383844364247891968",             // 2^155
      "91343852333181432387730302044767688728495783936",             // 2^156
      "182687704666362864775460604089535377456991567872",            // 2^157
      "365375409332725729550921208179070754913983135744",            // 2^158
      "730750818665451459101842416358141509827966271488",            // 2^159
      "1461501637330902918203684832716283019655932542976",           // 2^160
      "2923003274661805836407369665432566039311865085952",           // 2^161
      "5846006549323611672814739330865132078623730171904",           // 2^162
      "11692013098647223345629478661730264157247460343808",          // 2^163
      "23384026197294446691258957323460528314494920687616",          // 2^164
      "46768052394588893382517914646921056628989841375232",          // 2^165
      "93536104789177786765035829293842113257979682750464",          // 2^166
      "187072209578355573530071658587684226515959365500928",         // 2^167
      "374144419156711147060143317175368453031918731001856",         // 2^168
      "748288838313422294120286634350736906063837462003712",         // 2^169
      "1496577676626844588240573268701473812127674924007424",        // 2^170
      "2993155353253689176481146537402947624255349848014848",        // 2^171
      "5986310706507378352962293074805895248510699696029696",        // 2^172
      "11972621413014756705924586149611790497021399392059392",       // 2^173
      "23945242826029513411849172299223580994042798784118784",       // 2^174
      "47890485652059026823698344598447161988085597568237568",       // 2^175
      "95780971304118053647396689196894323976171195136475136",       // 2^176
      "191561942608236107294793378393788647952342390272950272",      // 2^177
      "383123885216472214589586756787577295904684780545900544",      // 2^178
      "766247770432944429179173513575154591809369561091801088",      // 2^179
      "1532495540865888858358347027150309183618739122183602176",     // 2^180
      "3064991081731777716716694054300618367237478244367204352",     // 2^181
      "6129982163463555433433388108601236734474956488734408704",     // 2^182
      "12259964326927110866866776217202473468949912977468817408",    // 2^183
      "24519928653854221733733552434404946937899825954937634816",    // 2^184
      "49039857307708443467467104868809893875799651909875269632",    // 2^185
      "98079714615416886934934209737619787751599303819750539264",    // 2^186
      "196159429230833773869868419475239575503198607639501078528",   // 2^187
      "392318858461667547739736838950479151006397215279002157056",   // 2^188
      "784637716923335095479473677900958302012794430558004314112",   // 2^189
      "1569275433846670190958947355801916604025588861116008628224",  // 2^190
      "3138550867693340381917894711603833208051177722232017256448",  // 2^191
  };

  char *need_bit = (char *)malloc(strlen(bits[index]) + 1);
  sprintf(need_bit, "%s", bits[index]);

  return need_bit;
}
