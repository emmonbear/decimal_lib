/**
 * @file decimal_to_float.c
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-03-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <math.h>

#include "./../include/convertors.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  if (!dst) {
    return CONVERSION_ERROR;
  }

  *dst =
      ((GET_SIGN(src.bits[3])) ? -1 : 1) *
      ((long double)src.bits[2] * powl(2.0, 64.0) +
       (long double)src.bits[1] * powl(2.0, 32.0) + (long double)src.bits[0]) /
      powl(10.0, GET_POWER(src.bits[3]));

  return CONVERSION_OK;
}