/**
 * @file binary_sub.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief Module for bitwise addition of numbers of type uin192_t
 * @version 0.1
 * @date 2024-02-25
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/bit_lib.h"

uint192_t binary_sub(uint192_t value_1, uint192_t value_2) {
  uint192_t one = SET_ONE;
  value_2 = binary_not(value_2);
  value_2 = binary_add(value_2, one);
  uint192_t res = binary_add(value_1, value_2);

  return res;
}