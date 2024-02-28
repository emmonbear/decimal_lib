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

int s21_add(decimal_t value_1, decimal_t value_2, decimal_t *result);
int add_positive(decimal_t value_1, decimal_t value_2, decimal_t *res);

int sub_positive(decimal_t value_1, decimal_t value_2, decimal_t *result);

#endif  // ARITHMETIC_H