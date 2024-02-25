/**
 * @file binary_mul.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief Module for bitwise multiplication of numbers of type uin192_t
 * @version 0.1
 * @date 2024-02-25
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/bit_lib.h"

uint192_t binary_mul(uint192_t value_1, uint192_t value_2) {
  uint192_t res = SET_ZERO;
  uint192_t tmp = value_1;
  uint8_t high_bit = get_high_bit(value_2);

  for (uint8_t i = 0; i <= high_bit; i++) {
    if (IS_SET_BIT(value_2, i)) {
      res = binary_add(res, tmp);
    }

    shift_left(&tmp, 1);
  }

  return res;
}