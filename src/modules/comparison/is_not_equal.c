/**
 * @file is_not_equal.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief
 * @version 0.1
 * @date 2024-02-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/comparison.h"

int s21_is_not_equal(decimal_t value_1, decimal_t value_2) {
  return !s21_is_equal(value_1, value_2);
}