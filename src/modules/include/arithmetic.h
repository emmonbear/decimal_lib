/**
 * @file arithmetic.h
 * @author emmonbea (https://github.com/emmonbear)
 * @brief Arithmetic header
 * @version 0.1
 * @date 2024-02-26
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include "./common.h"
#include "./comparison.h"

/// @brief Enumeration of arithmetic error codes
typedef enum {
  OK,         ///< correct result
  BIG,        ///< the number is too large or equal to infinity
  SMALL,      ///< the number is too small or equal to negative infinity
  ZERO_DIV,   ///< division by 0
  INCORRECT,  ///< incorrect decimal_t
} arithmetic_code;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int add_positive(s21_decimal value_1, s21_decimal value_2, s21_decimal *res);

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int sub_positive(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int mul_positive(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int div_additional(uint192_t divider, uint192_t quotient, uint192_t remainder,
                   s21_decimal *result);
int calc_fract_part(uint192_t *quotient, uint192_t divider,
                    uint192_t *remainder);
#endif  // ARITHMETIC_H