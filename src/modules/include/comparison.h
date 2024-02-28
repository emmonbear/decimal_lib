/**
 * @file is_equal.h
 * @author emmonbea (https://github.com/emmonbear)
 * @brief
 * @version 0.1
 * @date 2024-02-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef COMPARISON_H
#define COMPARISON_H

#include "./common.h"

typedef enum {
  COMPARISON_FALSE,
  COMPARISON_TRUE,
} comparison_code;

int s21_is_equal(decimal_t value_1, decimal_t value_2);

int s21_is_not_equal(decimal_t value_1, decimal_t value_2);

int s21_is_less(decimal_t value_1, decimal_t value_2);
int is_less_positive(decimal_t value_1, decimal_t value_2);

int s21_is_less_or_equal(decimal_t value_1, decimal_t value_2);

int s21_is_greater(decimal_t value_1, decimal_t value_2);

int s21_is_greater_or_equal(decimal_t value_1, decimal_t value_2);

#endif  // COMPARISON_H