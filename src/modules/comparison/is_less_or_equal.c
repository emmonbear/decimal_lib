/**
 * @file is_less_or_equal.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief is_less_or_equal module
 * @version 0.1
 * @date 2024-02-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/comparison.h"

/**
 * @brief Check that value_1 <= value_2
 *
 * @param[in] value_1
 * @param[in] value_2
 * @retval COMPARISON_TRUE - value_1 <= value_2
 * @retval COMPARISON_FALSE - !(value_1 <= value_2)
 */
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  if (!is_correct(value_1) || !is_correct(value_2)) {
    return COMPARISON_FALSE;
  }
  
  return s21_is_less(value_1, value_2) || s21_is_equal(value_1, value_2);
}
