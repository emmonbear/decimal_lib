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

#define DECIMAL_MAX \
  79228162514264337593543950335.0  ///< {{0xFFFFFFF, 0xFFFFFFF, 0xFFFFFFF, 0}}
#define IS_NAN(x) x != x           ///< is not a number check
#define IS_INF(x) x == 1.0 / 0.0   ///< is infinity check

/// @brief INT_MAX as decimal
#define DCML_INT_MAX \
  (s21_decimal) {    \
    { 0x7FFFFFFF }   \
  }
/// @brief INT_MIN as decimal
#define DCML_INT_MIN                     \
  (s21_decimal) {                        \
    { 0x80000000, 0x0, 0x0, 0x80000000 } \
  }

/// @brief Enumeration of conversion error codes
typedef enum {
  CONVERSION_OK,     ///< conversion error
  CONVERSION_ERROR,  ///< conversion ok
} converter_code;

/// @todo Добавить описание
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
