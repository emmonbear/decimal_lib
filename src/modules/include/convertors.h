/**
 * @file convertors.h
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-02-27
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef CONVERTERS_H_
#define CONVERTERS_H_

#include <stdlib.h>

#include "./common.h"

#define DECIMAL_MAX 79228162514264337593543950335.0
#define IS_NAN(x) x != x
#define IS_INF(x) x == 1.0 / 0.0
#define DCML_INT_MAX \
  (s21_decimal) {    \
    { 0x7FFFFFFF }   \
  }
#define DCML_INT_MIN                     \
  (s21_decimal) {                        \
    { 0x80000000, 0x0, 0x0, 0x80000000 } \
  }

typedef enum {
  CONVERSION_OK,
  CONVERSION_ERROR,
} converter_code;

typedef enum {
  DCML_PRECISION = 28,
  FLT_PRECISION = 6,
  MIN_NEED_SIZE = 15,
  EXP_LEN = 4,
} constants;

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

#endif  // CONVERTERS_H_
