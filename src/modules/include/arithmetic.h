/**
 * @file arithmetic.h
 * @author emmonbea (https://github.com/emmonbear)
 * @brief
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

typedef enum {
  OK,
  BIG,
  SMALL,
  ZERO_DIV,
} arithmetic_code;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int add_positive(s21_decimal value_1, s21_decimal value_2, s21_decimal *res);

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int sub_positive(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int mul_positive(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

#endif  // ARITHMETIC_H