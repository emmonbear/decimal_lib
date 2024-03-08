/**
 * @file convertors.h
 * @author kossadda (https://github.com/kossadda)
 * @brief Convertors header
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

#define DECIMAL_MAX 79228162514264337593543950335.0  ///< Decimal max num
#define IS_NAN(x) x != x                             ///< Is not a number check
#define IS_INF(x) x == 1.0 / 0.0                     ///< Is infinity check

/// @brief INT_MAX as decimal
#define DCML_INT_MAX \
  (s21_decimal) {    \
    { 0x7FFFFFFF }   \
  }

/// @brief INT_MIN as decimal
#define DCML_INT_MIN \
  (s21_decimal) {    \
    { 0x80000000 }   \
  }

/// @brief Enumeration of conversion error codes
typedef enum {
  CONVERSION_OK,     ///< Conversion error
  CONVERSION_ERROR,  ///< Conversion ok
} converter_code;

/// @brief Enumeration of main convertors constants
typedef enum {
  FLT_PRECISION = 6,   ///< Precision of float value
  MIN_NEED_SIZE = 15,  ///< Min need size for sprintf num with sciece notation
  EXP_LEN = 4,         ///< Length of science write of sprintf
} constants;

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

#endif  // CONVERTERS_H_
