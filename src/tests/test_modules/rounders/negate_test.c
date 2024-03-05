/**
 * @file negate_test.c
 * @author kossadda (https://github.com/kossadda)
 * @brief 
 * @version 1.0
 * @date 2024-03-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "./../../main_test.h"

static void s21_test_negate(s21_decimal value, s21_decimal result, int code, char *text, int count);

//############################# EDGE CASE #####################################
START_TEST(s21_negate_edge_1) {
  s21_decimal value_1 = {{0xD487DA, 0x0, 0x0, 0x0}};
  s21_decimal *value_2 = NULL;
  int code = 1;
  int my_code = s21_negate(value_1, value_2);
  ck_assert_int_eq(code, my_code);
}
//#############################################################################

START_TEST(s21_negate_1) {
  char *example = "negate(19098936919503535661) = -19098936919503535661";
  s21_decimal value = {{0x1299FE2D, 0x90D0DF0, 0x1, 0x0}};
  s21_decimal result = {{0x1299FE2D, 0x90D0DF0, 0x1, 0x80000000}};
  int code = 0;
  int count = 1;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_2) {
  char *example = "negate(1906583) = -1906583";
  s21_decimal value = {{0x1D1797, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0x1D1797, 0x0, 0x0, 0x80000000}};
  int code = 0;
  int count = 2;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_3) {
  char *example = "negate(1780822449682064037376934733) = -1780822449682064037376934733";
  s21_decimal value = {{0xB60FC34D, 0x70147C55, 0x5C10FD2, 0x0}};
  s21_decimal result = {{0xB60FC34D, 0x70147C55, 0x5C10FD2, 0x80000000}};
  int code = 0;
  int count = 3;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_4) {
  char *example = "negate(-816.411081109) = 816.411081109";
  s21_decimal value = {{0x15E47995, 0xBE, 0x0, 0x80090000}};
  s21_decimal result = {{0x15E47995, 0xBE, 0x0, 0x90000}};
  int code = 0;
  int count = 4;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_5) {
  char *example = "negate(143884967844877110953869362) = -143884967844877110953869362";
  s21_decimal value = {{0x877F8032, 0xBC7C43E0, 0x7704D3, 0x0}};
  s21_decimal result = {{0x877F8032, 0xBC7C43E0, 0x7704D3, 0x80000000}};
  int code = 0;
  int count = 5;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_6) {
  char *example = "negate(-1.975823357) = 1.975823357";
  s21_decimal value = {{0x75C4ABFD, 0x0, 0x0, 0x80090000}};
  s21_decimal result = {{0x75C4ABFD, 0x0, 0x0, 0x90000}};
  int code = 0;
  int count = 6;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_7) {
  char *example = "negate(1902103676873890659608060368) = -1902103676873890659608060368";
  s21_decimal value = {{0x86E861D0, 0xF01E9971, 0x625621E, 0x0}};
  s21_decimal result = {{0x86E861D0, 0xF01E9971, 0x625621E, 0x80000000}};
  int code = 0;
  int count = 7;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_8) {
  char *example = "negate(192638) = -192638";
  s21_decimal value = {{0x2F07E, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0x2F07E, 0x0, 0x0, 0x80000000}};
  int code = 0;
  int count = 8;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_9) {
  char *example = "negate(1805868391709870380853978073) = -1805868391709870380853978073";
  s21_decimal value = {{0x5C9B63D9, 0xACFD1E1D, 0x5D5C781, 0x0}};
  s21_decimal result = {{0x5C9B63D9, 0xACFD1E1D, 0x5D5C781, 0x80000000}};
  int code = 0;
  int count = 9;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_10) {
  char *example = "negate(-6.620298) = 6.620298";
  s21_decimal value = {{0x65048A, 0x0, 0x0, 0x80060000}};
  s21_decimal result = {{0x65048A, 0x0, 0x0, 0x60000}};
  int code = 0;
  int count = 10;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_11) {
  char *example = "negate(177314180768163) = -177314180768163";
  s21_decimal value = {{0x2CC221A3, 0xA144, 0x0, 0x0}};
  s21_decimal result = {{0x2CC221A3, 0xA144, 0x0, 0x80000000}};
  int code = 0;
  int count = 11;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_12) {
  char *example = "negate(-6.9211415) = 6.9211415";
  s21_decimal value = {{0x4201517, 0x0, 0x0, 0x80070000}};
  s21_decimal result = {{0x4201517, 0x0, 0x0, 0x70000}};
  int code = 0;
  int count = 12;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_13) {
  char *example = "negate(14832201871929400500606291) = -14832201871929400500606291";
  s21_decimal value = {{0x4D92D553, 0x464D224C, 0xC44D7, 0x0}};
  s21_decimal result = {{0x4D92D553, 0x464D224C, 0xC44D7, 0x80000000}};
  int code = 0;
  int count = 13;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_14) {
  char *example = "negate(123188804) = -123188804";
  s21_decimal value = {{0x757B644, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0x757B644, 0x0, 0x0, 0x80000000}};
  int code = 0;
  int count = 14;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_15) {
  char *example = "negate(-266.772473) = 266.772473";
  s21_decimal value = {{0xFE69FF9, 0x0, 0x0, 0x80060000}};
  s21_decimal result = {{0xFE69FF9, 0x0, 0x0, 0x60000}};
  int code = 0;
  int count = 15;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_16) {
  char *example = "negate(1766480549492840212) = -1766480549492840212";
  s21_decimal value = {{0x57285714, 0x1883CCB3, 0x0, 0x0}};
  s21_decimal result = {{0x57285714, 0x1883CCB3, 0x0, 0x80000000}};
  int code = 0;
  int count = 16;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_17) {
  char *example = "negate(17) = -17";
  s21_decimal value = {{0x11, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0x11, 0x0, 0x0, 0x80000000}};
  int code = 0;
  int count = 17;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_18) {
  char *example = "negate(1253265616116) = -1253265616116";
  s21_decimal value = {{0xCC73ACF4, 0x123, 0x0, 0x0}};
  s21_decimal result = {{0xCC73ACF4, 0x123, 0x0, 0x80000000}};
  int code = 0;
  int count = 18;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_19) {
  char *example = "negate(1562352443924) = -1562352443924";
  s21_decimal value = {{0xC3766214, 0x16B, 0x0, 0x0}};
  s21_decimal result = {{0xC3766214, 0x16B, 0x0, 0x80000000}};
  int code = 0;
  int count = 19;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_20) {
  char *example = "negate(1587965240343957693896399406) = -1587965240343957693896399406";
  s21_decimal value = {{0x74551A2E, 0x2BADB41D, 0x52188B8, 0x0}};
  s21_decimal result = {{0x74551A2E, 0x2BADB41D, 0x52188B8, 0x80000000}};
  int code = 0;
  int count = 20;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_21) {
  char *example = "negate(1081436230125845625841999) = -1081436230125845625841999";
  s21_decimal value = {{0xEA1A294F, 0xC68784BE, 0xE500, 0x0}};
  s21_decimal result = {{0xEA1A294F, 0xC68784BE, 0xE500, 0x80000000}};
  int code = 0;
  int count = 21;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_22) {
  char *example = "negate(-459.4) = 459.4";
  s21_decimal value = {{0x11F2, 0x0, 0x0, 0x80010000}};
  s21_decimal result = {{0x11F2, 0x0, 0x0, 0x10000}};
  int code = 0;
  int count = 22;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_23) {
  char *example = "negate(1286733) = -1286733";
  s21_decimal value = {{0x13A24D, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0x13A24D, 0x0, 0x0, 0x80000000}};
  int code = 0;
  int count = 23;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_24) {
  char *example = "negate(-479.0280268231957097) = 479.0280268231957097";
  s21_decimal value = {{0x22875A69, 0x427A7E86, 0x0, 0x80100000}};
  s21_decimal result = {{0x22875A69, 0x427A7E86, 0x0, 0x100000}};
  int code = 0;
  int count = 24;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_25) {
  char *example = "negate(-5.73821458) = 5.73821458";
  s21_decimal value = {{0x2233D212, 0x0, 0x0, 0x80080000}};
  s21_decimal result = {{0x2233D212, 0x0, 0x0, 0x80000}};
  int code = 0;
  int count = 25;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_26) {
  char *example = "negate(-95.9420354393674) = 95.9420354393674";
  s21_decimal value = {{0x7569F64A, 0x36896, 0x0, 0x800D0000}};
  s21_decimal result = {{0x7569F64A, 0x36896, 0x0, 0xD0000}};
  int code = 0;
  int count = 26;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_27) {
  char *example = "negate(12466373) = -12466373";
  s21_decimal value = {{0xBE38C5, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0xBE38C5, 0x0, 0x0, 0x80000000}};
  int code = 0;
  int count = 27;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_28) {
  char *example = "negate(1157) = -1157";
  s21_decimal value = {{0x485, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0x485, 0x0, 0x0, 0x80000000}};
  int code = 0;
  int count = 28;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_29) {
  char *example = "negate(-30.126238961358858656731592) = 30.126238961358858656731592";
  s21_decimal value = {{0xE7A0D1C8, 0xAFC0D50B, 0x18EB7A, 0x80180000}};
  s21_decimal result = {{0xE7A0D1C8, 0xAFC0D50B, 0x18EB7A, 0x180000}};
  int code = 0;
  int count = 29;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_30) {
  char *example = "negate(15269) = -15269";
  s21_decimal value = {{0x3BA5, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0x3BA5, 0x0, 0x0, 0x80000000}};
  int code = 0;
  int count = 30;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_31) {
  char *example = "negate(12.6210709) = -12.6210709";
  s21_decimal value = {{0x785D295, 0x0, 0x0, 0x70000}};
  s21_decimal result = {{0x785D295, 0x0, 0x0, 0x80070000}};
  int code = 0;
  int count = 31;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_32) {
  char *example = "negate(-2.6299426803126) = 2.6299426803126";
  s21_decimal value = {{0x4FFE0DB6, 0x17EB, 0x0, 0x800D0000}};
  s21_decimal result = {{0x4FFE0DB6, 0x17EB, 0x0, 0xD0000}};
  int code = 0;
  int count = 32;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_33) {
  char *example = "negate(16840376236719) = -16840376236719";
  s21_decimal value = {{0xF4A4BAAF, 0xF50, 0x0, 0x0}};
  s21_decimal result = {{0xF4A4BAAF, 0xF50, 0x0, 0x80000000}};
  int code = 0;
  int count = 33;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_34) {
  char *example = "negate(-192.99977563512174830434113) = 192.99977563512174830434113";
  s21_decimal value = {{0x2BE43741, 0xE1526EB6, 0xFF6ED, 0x80170000}};
  s21_decimal result = {{0x2BE43741, 0xE1526EB6, 0xFF6ED, 0x170000}};
  int code = 0;
  int count = 34;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_35) {
  char *example = "negate(-3287.725688132) = 3287.725688132";
  s21_decimal value = {{0x7BB8C544, 0x2FD, 0x0, 0x80090000}};
  s21_decimal result = {{0x7BB8C544, 0x2FD, 0x0, 0x90000}};
  int code = 0;
  int count = 35;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_36) {
  char *example = "negate(1911490122356959404930577012) = -1911490122356959404930577012";
  s21_decimal value = {{0xBD073274, 0x2ACD9CE6, 0x62D25C7, 0x0}};
  s21_decimal result = {{0xBD073274, 0x2ACD9CE6, 0x62D25C7, 0x80000000}};
  int code = 0;
  int count = 36;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_37) {
  char *example = "negate(1930540629161011253029240331) = -1930540629161011253029240331";
  s21_decimal value = {{0x59D9FE0B, 0x35DC732D, 0x63CE7E1, 0x0}};
  s21_decimal result = {{0x59D9FE0B, 0x35DC732D, 0x63CE7E1, 0x80000000}};
  int code = 0;
  int count = 37;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_38) {
  char *example = "negate(11259902) = -11259902";
  s21_decimal value = {{0xABCFFE, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0xABCFFE, 0x0, 0x0, 0x80000000}};
  int code = 0;
  int count = 38;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_39) {
  char *example = "negate(17835711283506) = -17835711283506";
  s21_decimal value = {{0xB33C4132, 0x1038, 0x0, 0x0}};
  s21_decimal result = {{0xB33C4132, 0x1038, 0x0, 0x80000000}};
  int code = 0;
  int count = 39;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_40) {
  char *example = "negate(516.85795) = -516.85795";
  s21_decimal value = {{0x314A9A3, 0x0, 0x0, 0x50000}};
  s21_decimal result = {{0x314A9A3, 0x0, 0x0, 0x80050000}};
  int code = 0;
  int count = 40;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_41) {
  char *example = "negate(-5883.5567762142) = 5883.5567762142";
  s21_decimal value = {{0xB91DDADE, 0x3582, 0x0, 0x800A0000}};
  s21_decimal result = {{0xB91DDADE, 0x3582, 0x0, 0xA0000}};
  int code = 0;
  int count = 41;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_42) {
  char *example = "negate(0.5154872488060) = -0.5154872488060";
  s21_decimal value = {{0x56F31A6, 0x78, 0x0, 0xC0000}};
  s21_decimal result = {{0x56F31A6, 0x78, 0x0, 0x800C0000}};
  int code = 0;
  int count = 42;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_43) {
  char *example = "negate(14987) = -14987";
  s21_decimal value = {{0x3A8B, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0x3A8B, 0x0, 0x0, 0x80000000}};
  int code = 0;
  int count = 43;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_44) {
  char *example = "negate(-6) = 6";
  s21_decimal value = {{0x6, 0x0, 0x0, 0x80000000}};
  s21_decimal result = {{0x6, 0x0, 0x0, 0x0}};
  int code = 0;
  int count = 44;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_45) {
  char *example = "negate(-1.2267542234100111736567151) = 1.2267542234100111736567151";
  s21_decimal value = {{0xD487F56F, 0xCC0C59AE, 0xA25C0, 0x80190000}};
  s21_decimal result = {{0xD487F56F, 0xCC0C59AE, 0xA25C0, 0x190000}};
  int code = 0;
  int count = 45;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_46) {
  char *example = "negate(143445) = -143445";
  s21_decimal value = {{0x23055, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0x23055, 0x0, 0x0, 0x80000000}};
  int code = 0;
  int count = 46;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_47) {
  char *example = "negate(13) = -13";
  s21_decimal value = {{0xD, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0xD, 0x0, 0x0, 0x80000000}};
  int code = 0;
  int count = 47;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_48) {
  char *example = "negate(11) = -11";
  s21_decimal value = {{0xB, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0xB, 0x0, 0x0, 0x80000000}};
  int code = 0;
  int count = 48;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_49) {
  char *example = "negate(1744995428159274973157685775) = -1744995428159274973157685775";
  s21_decimal value = {{0x77BC7A0F, 0xB599CB03, 0x5A36D27, 0x0}};
  s21_decimal result = {{0x77BC7A0F, 0xB599CB03, 0x5A36D27, 0x80000000}};
  int code = 0;
  int count = 49;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_50) {
  char *example = "negate(12643) = -12643";
  s21_decimal value = {{0x3163, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0x3163, 0x0, 0x0, 0x80000000}};
  int code = 0;
  int count = 50;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_51) {
  char *example = "negate(1622141731000273676810774741) = -1622141731000273676810774741";
  s21_decimal value = {{0x7C2E8D5, 0x7105CB7D, 0x53DCDDF, 0x0}};
  s21_decimal result = {{0x7C2E8D5, 0x7105CB7D, 0x53DCDDF, 0x80000000}};
  int code = 0;
  int count = 51;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_52) {
  char *example = "negate(1855094137412369170524854892) = -1855094137412369170524854892";
  s21_decimal value = {{0x57B8DA6C, 0xB2878A41, 0x5FE7F76, 0x0}};
  s21_decimal result = {{0x57B8DA6C, 0xB2878A41, 0x5FE7F76, 0x80000000}};
  int code = 0;
  int count = 52;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_53) {
  char *example = "negate(-3) = 3";
  s21_decimal value = {{0x3, 0x0, 0x0, 0x80000000}};
  s21_decimal result = {{0x3, 0x0, 0x0, 0x0}};
  int code = 0;
  int count = 53;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_54) {
  char *example = "negate(0.359980634051236942) = -0.359980634051236942";
  s21_decimal value = {{0xBAA4D44E, 0x4FEE87A, 0x0, 0x120000}};
  s21_decimal result = {{0xBAA4D44E, 0x4FEE87A, 0x0, 0x80120000}};
  int code = 0;
  int count = 54;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_55) {
  char *example = "negate(11454152373254) = -11454152373254";
  s21_decimal value = {{0xE0AEF406, 0xA6A, 0x0, 0x0}};
  s21_decimal result = {{0xE0AEF406, 0xA6A, 0x0, 0x80000000}};
  int code = 0;
  int count = 55;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_56) {
  char *example = "negate(17) = -17";
  s21_decimal value = {{0x11, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0x11, 0x0, 0x0, 0x80000000}};
  int code = 0;
  int count = 56;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_57) {
  char *example = "negate(-6.8710406913716550292895449) = 6.8710406913716550292895449";
  s21_decimal value = {{0x31F276D9, 0x9F564F2E, 0x38D5FE, 0x80190000}};
  s21_decimal result = {{0x31F276D9, 0x9F564F2E, 0x38D5FE, 0x190000}};
  int code = 0;
  int count = 57;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_58) {
  char *example = "negate(1553543762755519976218962) = -1553543762755519976218962";
  s21_decimal value = {{0x4062A152, 0xC6B08E86, 0x148F9, 0x0}};
  s21_decimal result = {{0x4062A152, 0xC6B08E86, 0x148F9, 0x80000000}};
  int code = 0;
  int count = 58;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_59) {
  char *example = "negate(19) = -19";
  s21_decimal value = {{0x13, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0x13, 0x0, 0x0, 0x80000000}};
  int code = 0;
  int count = 59;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_60) {
  char *example = "negate(0.66209) = -0.66209";
  s21_decimal value = {{0x102A1, 0x0, 0x0, 0x50000}};
  s21_decimal result = {{0x102A1, 0x0, 0x0, 0x80050000}};
  int code = 0;
  int count = 60;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_61) {
  char *example = "negate(1068524526828760602337096930) = -1068524526828760602337096930";
  s21_decimal value = {{0xC51C34E2, 0xAAC65EE1, 0x373DCDE, 0x0}};
  s21_decimal result = {{0xC51C34E2, 0xAAC65EE1, 0x373DCDE, 0x80000000}};
  int code = 0;
  int count = 61;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_62) {
  char *example = "negate(-263.76) = 263.76";
  s21_decimal value = {{0x6708, 0x0, 0x0, 0x80020000}};
  s21_decimal result = {{0x6708, 0x0, 0x0, 0x20000}};
  int code = 0;
  int count = 62;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_63) {
  char *example = "negate(-89) = 89";
  s21_decimal value = {{0x59, 0x0, 0x0, 0x80000000}};
  s21_decimal result = {{0x59, 0x0, 0x0, 0x0}};
  int code = 0;
  int count = 63;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_64) {
  char *example = "negate(36.0679862286315953135) = -36.0679862286315953135";
  s21_decimal value = {{0x1CAC1BEF, 0x8D7047C9, 0x13, 0x130000}};
  s21_decimal result = {{0x1CAC1BEF, 0x8D7047C9, 0x13, 0x80130000}};
  int code = 0;
  int count = 64;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_65) {
  char *example = "negate(-8.8032603427738011085018393) = 8.8032603427738011085018393";
  s21_decimal value = {{0xE4339519, 0xFE8A250A, 0x48D1A0, 0x80190000}};
  s21_decimal result = {{0xE4339519, 0xFE8A250A, 0x48D1A0, 0x190000}};
  int code = 0;
  int count = 65;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_66) {
  char *example = "negate(1457166680017138095830786428) = -1457166680017138095830786428";
  s21_decimal value = {{0x307EE17C, 0x1E532F6, 0x4B5570C, 0x0}};
  s21_decimal result = {{0x307EE17C, 0x1E532F6, 0x4B5570C, 0x80000000}};
  int code = 0;
  int count = 66;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_67) {
  char *example = "negate(174845843527086708572) = -174845843527086708572";
  s21_decimal value = {{0x9D89175C, 0x7A793850, 0x9, 0x0}};
  s21_decimal result = {{0x9D89175C, 0x7A793850, 0x9, 0x80000000}};
  int code = 0;
  int count = 67;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_68) {
  char *example = "negate(186455133416276349023934) = -186455133416276349023934";
  s21_decimal value = {{0xC205F6BE, 0xC0C6F877, 0x277B, 0x0}};
  s21_decimal result = {{0xC205F6BE, 0xC0C6F877, 0x277B, 0x80000000}};
  int code = 0;
  int count = 68;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_69) {
  char *example = "negate(-9.293855174630249) = 9.293855174630249";
  s21_decimal value = {{0x48471B69, 0x2104B6, 0x0, 0x800F0000}};
  s21_decimal result = {{0x48471B69, 0x2104B6, 0x0, 0xF0000}};
  int code = 0;
  int count = 69;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_70) {
  char *example = "negate(1727505142759896607218742328) = -1727505142759896607218742328";
  s21_decimal value = {{0x4D643438, 0x70214BFC, 0x594F571, 0x0}};
  s21_decimal result = {{0x4D643438, 0x70214BFC, 0x594F571, 0x80000000}};
  int code = 0;
  int count = 70;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_71) {
  char *example = "negate(-3873.3586983773647369350516) = 3873.3586983773647369350516";
  s21_decimal value = {{0x7DF2D74, 0xF53242FD, 0x200A27, 0x80160000}};
  s21_decimal result = {{0x7DF2D74, 0xF53242FD, 0x200A27, 0x160000}};
  int code = 0;
  int count = 71;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_72) {
  char *example = "negate(1390748252) = -1390748252";
  s21_decimal value = {{0x52E5225C, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0x52E5225C, 0x0, 0x0, 0x80000000}};
  int code = 0;
  int count = 72;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_73) {
  char *example = "negate(-790.8536464712380) = 790.8536464712380";
  s21_decimal value = {{0xF6AAD046, 0x2CF46, 0x0, 0x800C0000}};
  s21_decimal result = {{0xF6AAD046, 0x2CF46, 0x0, 0xC0000}};
  int code = 0;
  int count = 73;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_74) {
  char *example = "negate(1834711850605117098034023366) = -1834711850605117098034023366";
  s21_decimal value = {{0xEE3D4BC6, 0xB72E2E3D, 0x5EDA358, 0x0}};
  s21_decimal result = {{0xEE3D4BC6, 0xB72E2E3D, 0x5EDA358, 0x80000000}};
  int code = 0;
  int count = 74;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_75) {
  char *example = "negate(17038739060) = -17038739060";
  s21_decimal value = {{0xF7968674, 0x3, 0x0, 0x0}};
  s21_decimal result = {{0xF7968674, 0x3, 0x0, 0x80000000}};
  int code = 0;
  int count = 75;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_76) {
  char *example = "negate(11908410802123833269628102) = -11908410802123833269628102";
  s21_decimal value = {{0x4912CC6, 0x3E3D7B22, 0x9D9B4, 0x0}};
  s21_decimal result = {{0x4912CC6, 0x3E3D7B22, 0x9D9B4, 0x80000000}};
  int code = 0;
  int count = 76;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_77) {
  char *example = "negate(1717448190011151251709761728) = -1717448190011151251709761728";
  s21_decimal value = {{0xC62E18C0, 0xEFE3C765, 0x58CA3CC, 0x0}};
  s21_decimal result = {{0xC62E18C0, 0xEFE3C765, 0x58CA3CC, 0x80000000}};
  int code = 0;
  int count = 77;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_78) {
  char *example = "negate(1706244103013851) = -1706244103013851";
  s21_decimal value = {{0xE9A905DB, 0x60FD1, 0x0, 0x0}};
  s21_decimal result = {{0xE9A905DB, 0x60FD1, 0x0, 0x80000000}};
  int code = 0;
  int count = 78;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_79) {
  char *example = "negate(143393126211510) = -143393126211510";
  s21_decimal value = {{0x5059DFB6, 0x826A, 0x0, 0x0}};
  s21_decimal result = {{0x5059DFB6, 0x826A, 0x0, 0x80000000}};
  int code = 0;
  int count = 79;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_80) {
  char *example = "negate(15698249) = -15698249";
  s21_decimal value = {{0xEF8949, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0xEF8949, 0x0, 0x0, 0x80000000}};
  int code = 0;
  int count = 80;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_81) {
  char *example = "negate(-2.247952234869876170155) = 2.247952234869876170155";
  s21_decimal value = {{0xE8719DAB, 0xDC9AA773, 0x79, 0x80150000}};
  s21_decimal result = {{0xE8719DAB, 0xDC9AA773, 0x79, 0x150000}};
  int code = 0;
  int count = 81;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_82) {
  char *example = "negate(-5.6129703588948203804410147) = 5.6129703588948203804410147";
  s21_decimal value = {{0x7119C123, 0x541F794E, 0x2E6DED, 0x80190000}};
  s21_decimal result = {{0x7119C123, 0x541F794E, 0x2E6DED, 0x190000}};
  int code = 0;
  int count = 82;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_83) {
  char *example = "negate(8.53848496E-10) = -8.53848496E-10";
  s21_decimal value = {{0x32E4B1B0, 0x0, 0x0, 0x120000}};
  s21_decimal result = {{0x32E4B1B0, 0x0, 0x0, 0x80120000}};
  int code = 0;
  int count = 83;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_84) {
  char *example = "negate(596.871592733663) = -596.871592733663";
  s21_decimal value = {{0xFF42EBDF, 0x21ED9, 0x0, 0xC0000}};
  s21_decimal result = {{0xFF42EBDF, 0x21ED9, 0x0, 0x800C0000}};
  int code = 0;
  int count = 84;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_85) {
  char *example = "negate(1376133166454352) = -1376133166454352";
  s21_decimal value = {{0xF88CD650, 0x4E395, 0x0, 0x0}};
  s21_decimal result = {{0xF88CD650, 0x4E395, 0x0, 0x80000000}};
  int code = 0;
  int count = 85;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_86) {
  char *example = "negate(11587768015567086340405) = -11587768015567086340405";
  s21_decimal value = {{0x3552C935, 0x2C95EF88, 0x274, 0x0}};
  s21_decimal result = {{0x3552C935, 0x2C95EF88, 0x274, 0x80000000}};
  int code = 0;
  int count = 86;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_87) {
  char *example = "negate(1268) = -1268";
  s21_decimal value = {{0x4F4, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0x4F4, 0x0, 0x0, 0x80000000}};
  int code = 0;
  int count = 87;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_88) {
  char *example = "negate(1417314028112499203285308307) = -1417314028112499203285308307";
  s21_decimal value = {{0x7185D393, 0x6B2F1D17, 0x4945FEB, 0x0}};
  s21_decimal result = {{0x7185D393, 0x6B2F1D17, 0x4945FEB, 0x80000000}};
  int code = 0;
  int count = 88;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_89) {
  char *example = "negate(-5.457831452434221) = 5.457831452434221";
  s21_decimal value = {{0x68F75F2D, 0x1363DE, 0x0, 0x800F0000}};
  s21_decimal result = {{0x68F75F2D, 0x1363DE, 0x0, 0xF0000}};
  int code = 0;
  int count = 89;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_90) {
  char *example = "negate(129774) = -129774";
  s21_decimal value = {{0x1FAEE, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0x1FAEE, 0x0, 0x0, 0x80000000}};
  int code = 0;
  int count = 90;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_91) {
  char *example = "negate(1946859925502793772684004280) = -1946859925502793772684004280";
  s21_decimal value = {{0x694FCBB8, 0x9AA4CB5, 0x64A67A0, 0x0}};
  s21_decimal result = {{0x694FCBB8, 0x9AA4CB5, 0x64A67A0, 0x80000000}};
  int code = 0;
  int count = 91;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_92) {
  char *example = "negate(1222506) = -1222506";
  s21_decimal value = {{0x12A76A, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0x12A76A, 0x0, 0x0, 0x80000000}};
  int code = 0;
  int count = 92;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_93) {
  char *example = "negate(-191.4570097364) = 191.4570097364";
  s21_decimal value = {{0xC54542D4, 0x1BD, 0x0, 0x800A0000}};
  s21_decimal result = {{0xC54542D4, 0x1BD, 0x0, 0xA0000}};
  int code = 0;
  int count = 93;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_94) {
  char *example = "negate(-6.8401982466732957611640487) = 6.8401982466732957611640487";
  s21_decimal value = {{0x85A0C6A7, 0xE64EA25B, 0x3894AE, 0x80190000}};
  s21_decimal result = {{0x85A0C6A7, 0xE64EA25B, 0x3894AE, 0x190000}};
  int code = 0;
  int count = 94;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_95) {
  char *example = "negate(147674340351793936) = -147674340351793936";
  s21_decimal value = {{0xB71BDB10, 0x20CA507, 0x0, 0x0}};
  s21_decimal result = {{0xB71BDB10, 0x20CA507, 0x0, 0x80000000}};
  int code = 0;
  int count = 95;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_96) {
  char *example = "negate(1225145) = -1225145";
  s21_decimal value = {{0x12B1B9, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0x12B1B9, 0x0, 0x0, 0x80000000}};
  int code = 0;
  int count = 96;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_97) {
  char *example = "negate(1013949685718422556280294603) = -1013949685718422556280294603";
  s21_decimal value = {{0x746B0CCB, 0x9A334F09, 0x346B832, 0x0}};
  s21_decimal result = {{0x746B0CCB, 0x9A334F09, 0x346B832, 0x80000000}};
  int code = 0;
  int count = 97;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_98) {
  char *example = "negate(16.943699067616546) = -16.943699067616546";
  s21_decimal value = {{0x5C1B3D22, 0x3C3234, 0x0, 0xF0000}};
  s21_decimal result = {{0x5C1B3D22, 0x3C3234, 0x0, 0x800F0000}};
  int code = 0;
  int count = 98;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_99) {
  char *example = "negate(19961084) = -19961084";
  s21_decimal value = {{0x13094FC, 0x0, 0x0, 0x0}};
  s21_decimal result = {{0x13094FC, 0x0, 0x0, 0x80000000}};
  int code = 0;
  int count = 99;

  s21_test_negate(value, result, code, example, count);
}

START_TEST(s21_negate_100) {
  char *example = "negate(-711) = 711";
  s21_decimal value = {{0x2C7, 0x0, 0x0, 0x80000000}};
  s21_decimal result = {{0x2C7, 0x0, 0x0, 0x0}};
  int code = 0;
  int count = 100;

  s21_test_negate(value, result, code, example, count);
}

//#####################################################################
//#####################################################################
//#####################################################################

/**
 * @brief Set №1 of decimal tests
 *
 * @return Suite*
 */
Suite *s21_negate_case_1(void)
{
  Suite *decimal = suite_create("\ns21_decimal (s21_negate case №1)\n");

  TCase *tc_s21_negate = tcase_create("s21_negate_test");
  tcase_add_test(tc_s21_negate, s21_negate_1);
  tcase_add_test(tc_s21_negate, s21_negate_2);
  tcase_add_test(tc_s21_negate, s21_negate_3);
  tcase_add_test(tc_s21_negate, s21_negate_4);
  tcase_add_test(tc_s21_negate, s21_negate_5);
  tcase_add_test(tc_s21_negate, s21_negate_6);
  tcase_add_test(tc_s21_negate, s21_negate_7);
  tcase_add_test(tc_s21_negate, s21_negate_8);
  tcase_add_test(tc_s21_negate, s21_negate_9);
  tcase_add_test(tc_s21_negate, s21_negate_10);
  tcase_add_test(tc_s21_negate, s21_negate_11);
  tcase_add_test(tc_s21_negate, s21_negate_12);
  tcase_add_test(tc_s21_negate, s21_negate_13);
  tcase_add_test(tc_s21_negate, s21_negate_14);
  tcase_add_test(tc_s21_negate, s21_negate_15);
  tcase_add_test(tc_s21_negate, s21_negate_16);
  tcase_add_test(tc_s21_negate, s21_negate_17);
  tcase_add_test(tc_s21_negate, s21_negate_18);
  tcase_add_test(tc_s21_negate, s21_negate_19);
  tcase_add_test(tc_s21_negate, s21_negate_20);
  tcase_add_test(tc_s21_negate, s21_negate_21);
  tcase_add_test(tc_s21_negate, s21_negate_22);
  tcase_add_test(tc_s21_negate, s21_negate_23);
  tcase_add_test(tc_s21_negate, s21_negate_24);
  tcase_add_test(tc_s21_negate, s21_negate_25);
  tcase_add_test(tc_s21_negate, s21_negate_26);
  tcase_add_test(tc_s21_negate, s21_negate_27);
  tcase_add_test(tc_s21_negate, s21_negate_28);
  tcase_add_test(tc_s21_negate, s21_negate_29);
  tcase_add_test(tc_s21_negate, s21_negate_30);
  tcase_add_test(tc_s21_negate, s21_negate_31);
  tcase_add_test(tc_s21_negate, s21_negate_32);
  tcase_add_test(tc_s21_negate, s21_negate_33);
  tcase_add_test(tc_s21_negate, s21_negate_34);
  tcase_add_test(tc_s21_negate, s21_negate_35);
  tcase_add_test(tc_s21_negate, s21_negate_36);
  tcase_add_test(tc_s21_negate, s21_negate_37);
  tcase_add_test(tc_s21_negate, s21_negate_38);
  tcase_add_test(tc_s21_negate, s21_negate_39);
  tcase_add_test(tc_s21_negate, s21_negate_40);
  tcase_add_test(tc_s21_negate, s21_negate_41);
  tcase_add_test(tc_s21_negate, s21_negate_42);
  tcase_add_test(tc_s21_negate, s21_negate_43);
  tcase_add_test(tc_s21_negate, s21_negate_44);
  tcase_add_test(tc_s21_negate, s21_negate_45);
  tcase_add_test(tc_s21_negate, s21_negate_46);
  tcase_add_test(tc_s21_negate, s21_negate_47);
  tcase_add_test(tc_s21_negate, s21_negate_48);
  tcase_add_test(tc_s21_negate, s21_negate_49);
  tcase_add_test(tc_s21_negate, s21_negate_50);
  tcase_add_test(tc_s21_negate, s21_negate_51);
  tcase_add_test(tc_s21_negate, s21_negate_52);
  tcase_add_test(tc_s21_negate, s21_negate_53);
  tcase_add_test(tc_s21_negate, s21_negate_54);
  tcase_add_test(tc_s21_negate, s21_negate_55);
  tcase_add_test(tc_s21_negate, s21_negate_56);
  tcase_add_test(tc_s21_negate, s21_negate_57);
  tcase_add_test(tc_s21_negate, s21_negate_58);
  tcase_add_test(tc_s21_negate, s21_negate_59);
  tcase_add_test(tc_s21_negate, s21_negate_60);
  tcase_add_test(tc_s21_negate, s21_negate_61);
  tcase_add_test(tc_s21_negate, s21_negate_62);
  tcase_add_test(tc_s21_negate, s21_negate_63);
  tcase_add_test(tc_s21_negate, s21_negate_64);
  tcase_add_test(tc_s21_negate, s21_negate_65);
  tcase_add_test(tc_s21_negate, s21_negate_66);
  tcase_add_test(tc_s21_negate, s21_negate_67);
  tcase_add_test(tc_s21_negate, s21_negate_68);
  tcase_add_test(tc_s21_negate, s21_negate_69);
  tcase_add_test(tc_s21_negate, s21_negate_70);
  tcase_add_test(tc_s21_negate, s21_negate_71);
  tcase_add_test(tc_s21_negate, s21_negate_72);
  tcase_add_test(tc_s21_negate, s21_negate_73);
  tcase_add_test(tc_s21_negate, s21_negate_74);
  tcase_add_test(tc_s21_negate, s21_negate_75);
  tcase_add_test(tc_s21_negate, s21_negate_76);
  tcase_add_test(tc_s21_negate, s21_negate_77);
  tcase_add_test(tc_s21_negate, s21_negate_78);
  tcase_add_test(tc_s21_negate, s21_negate_79);
  tcase_add_test(tc_s21_negate, s21_negate_80);
  tcase_add_test(tc_s21_negate, s21_negate_81);
  tcase_add_test(tc_s21_negate, s21_negate_82);
  tcase_add_test(tc_s21_negate, s21_negate_83);
  tcase_add_test(tc_s21_negate, s21_negate_84);
  tcase_add_test(tc_s21_negate, s21_negate_85);
  tcase_add_test(tc_s21_negate, s21_negate_86);
  tcase_add_test(tc_s21_negate, s21_negate_87);
  tcase_add_test(tc_s21_negate, s21_negate_88);
  tcase_add_test(tc_s21_negate, s21_negate_89);
  tcase_add_test(tc_s21_negate, s21_negate_90);
  tcase_add_test(tc_s21_negate, s21_negate_91);
  tcase_add_test(tc_s21_negate, s21_negate_92);
  tcase_add_test(tc_s21_negate, s21_negate_93);
  tcase_add_test(tc_s21_negate, s21_negate_94);
  tcase_add_test(tc_s21_negate, s21_negate_95);
  tcase_add_test(tc_s21_negate, s21_negate_96);
  tcase_add_test(tc_s21_negate, s21_negate_97);
  tcase_add_test(tc_s21_negate, s21_negate_98);
  tcase_add_test(tc_s21_negate, s21_negate_99);
  tcase_add_test(tc_s21_negate, s21_negate_100);
  suite_add_tcase(decimal, tc_s21_negate);

  return decimal;
}

Suite *s21_negate_edge_case(void) {
  Suite *decimal = suite_create("\ns21_decimal (s21_negate edge case)\n");

  TCase *tc_s21_negate = tcase_create("s21_negate_test");
  tcase_add_test(tc_s21_negate, s21_negate_edge_1);

  suite_add_tcase(decimal, tc_s21_negate);

  return decimal;
}

static void s21_test_negate(s21_decimal value, s21_decimal result, int code, char *text, int count) {
  s21_decimal implement_result = {{0x0}};
  int implement_code = s21_negate(value, &implement_result);
  int res = (implement_code == code);

  if (res) {
    res += s21_is_equal(result, implement_result);
  }
#ifdef DEBUG
#ifndef ERRORS
  if(res == 2) {
    printf("Test №%d: %s\n%s%s\n", count, GREEN"TEST_PASSED", RESET"Subformul:   ", text);
    both_decimal_bits(implement_result, result);
    print_line();
  }
#endif // ERRORS

  if(res != 2) {
    printf("Test №%d: %s\n%s%s\n", count, RED"TEST_FAILED", RESET"Subformul:   ", text);
    if (res == 0) {
      printf("Implementation code = %s%d%s\nOriginal funcs code = %s%d%s\n\n", RED, implement_code, RESET, GREEN, code, RESET);
    }
    both_decimal_bits(implement_result, result);
    print_line();
  }
#endif // DEBUG
  ck_assert_int_eq(res, 2);
  (void)text;
  (void)count;
}
