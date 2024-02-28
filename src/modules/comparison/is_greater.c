/**
 * @file is_greater.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief
 * @version 0.1
 * @date 2024-02-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/comparison.h"

int s21_is_greater(decimal_t value_1, decimal_t value_2) {
  return s21_is_less(value_2, value_1);
}