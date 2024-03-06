/**
 * @file is_greater.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief is_greater module
 * @version 0.1
 * @date 2024-02-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/comparison.h"

/**
 * @brief Check that value_1 > value_2
 *
 * @param[in] value_1
 * @param[in] value_2
 * @retval COMPARISON_TRUE - value_1 > value_2
 * @retval COMPARISON_FALSE - !(value_1 > value_2)
 */
int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  return s21_is_less(value_2, value_1);
}
