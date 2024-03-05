/**
 * @file is_equal.h
 * @author emmonbea (https://github.com/emmonbear)
 * @brief Comparison header
 * @version 0.1
 * @date 2024-02-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef COMPARISON_H
#define COMPARISON_H

#include "./common.h"

/// @brief Enumeration of comparison error codes
typedef enum {
  COMPARISON_FALSE,  ///< Comparison error
  COMPARISON_TRUE,   ///< Comparison ok
} comparison_code;

int s21_is_equal(s21_decimal value_1, s21_decimal value_2);

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

int s21_is_less(s21_decimal value_1, s21_decimal value_2);
bool is_less_positive(s21_decimal value_1, s21_decimal value_2);

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);

int s21_is_greater(s21_decimal value_1, s21_decimal value_2);

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);

#endif  // COMPARISON_H