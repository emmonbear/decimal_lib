/**
 * @file binary_div.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief Module for bitwise division of numbers of type uin192_t
 * @version 0.1
 * @date 2024-02-25
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/bit_lib.h"

uint192_t binary_div(uint192_t value_1, uint192_t value_2,
                     uint192_t *remainder) {
  uint192_t tmp_remaider = SET_ZERO;
  uint192_t quotient = SET_ZERO;

  if (is_eq_zero(value_1)) {
    *remainder = (uint192_t){{0}};
    return quotient;
  }

  if (binary_compare(value_1, value_2)) }