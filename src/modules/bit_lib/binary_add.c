/**
 * @file binary_add.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief Module for bitwise addition of numbers of type uin192_t
 * @version 0.1
 * @date 2024-02-25
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/bit_lib.h"

uint192_t binary_add(uint192_t value_1, uint192_t value_2) {
  uint192_t res = value_1;
  uint192_t tmp = value_2;

  while (!is_eq_zero(tmp)) {
    uint192_t overflow_bits = binary_and(res, tmp);
    shift_left(&overflow_bits, 1);
    res = binary_xor(res, tmp);
    tmp = overflow_bits;
  }

  return res;
}