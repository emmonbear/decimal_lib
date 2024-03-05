/**
 * @file is_not_equal.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief Is_not_equal module
 * @version 0.1
 * @date 2024-02-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/comparison.h"

/**
 * @brief Check that value_1 != value_2
 *
 * @param[in] value_1
 * @param[in] value_2
 * @retval COMPARISON_TRUE - numbers is not equal
 * @retval COMPARISON_FALSE - numbers is equal
 */
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_equal(value_1, value_2);
}