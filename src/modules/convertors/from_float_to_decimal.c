/**
 * @file from_float_to_decimal.c
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-02-27
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "./../include/convertors.h"

#define INT_PART(x) log10(x) + 1

// static int clear_dot(char *str);

// int s21_from_float_to_decimal(float src, decimal_t *dst) {
// bool sign = 0;

// if (!dst) {
//   return ERROR;
// } else if(src < 0) {
//   src *= -1;
//   sign = 1;
// }

// *dst = (decimal_t){0};
// int integer_part = INT_PART(src);
// int significant = 0;
// short exponent = 0;
// char src_str[exponent + 8];

// while (fabs(src) <= 1) {
//   src *= 10;
//   exponent++;
// }
// while (fabsf(src) >= 10) {
//   src /= 10;
//   exponent--;
// }

// sprintf(src_str, "%f", src);
// clear_dot(src_str);
// significant = atoi(src_str);
// dst->bits[0] = significant;

// if(integer_part < 0) {
//   dst->bits[3] |= exponent << 16;
// } else if(integer_part > 7) {
//   uint192_t long_dst = decimal_to_uint192(*dst);
//   long_dst = binary_mul(long_dst, get_ten_pow(abs(exponent) - 6));
//   dst->bits[0] = long_dst.Lbits[0];
//   dst->bits[1] = long_dst.Lbits[1];
//   dst->bits[2] = long_dst.Lbits[2];
// } else {
//   dst->bits[3] |= (7 - (1 + abs(exponent))) << 16;
// }

// dst->bits[3] |= sign;

// return OK;
// }

// static int clear_dot(char *str) {
// bool dot = 0;
// int after_dot = 0;

// for (size_t i = 0; i < strlen(str); i++) {
//   if(str[i] == '.') {
//     dot = 1;
//   }
//   if(dot) {
//     str[i] = str[i + 1];
//     after_dot++;
//   }
// }

// return after_dot;
// }