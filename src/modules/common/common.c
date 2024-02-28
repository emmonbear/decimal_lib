/**
 * @file bank_rouding.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief
 * @version 0.1
 * @date 2024-02-27
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/common.h"

uint192_t bank_rouding(uint192_t integer, uint192_t fractional) {
  uint192_t point_five = DCML_POINT_FIVE;
  uint192_t res = DCML_ZERO;

  if (binary_compare(fractional, point_five) == EQUAL) {
    if (IS_EVEN(integer)) {
      for (uint8_t i = 0; i < (LDEC_SIZE - 1); i++) {
        res.Lbits[i] = integer.Lbits[i];
      }
    } else {
      res = binary_add(integer, (uint192_t)SET_ONE);
    }
  } else if (binary_compare(fractional, point_five) == GREATER) {
    res = binary_add(integer, (uint192_t)SET_ONE);
  } else {
    res = integer;
  }

  return res;
}

decimal_t dcml_abs(decimal_t value) {
  decimal_t res = value;
  res.bits[DEC_SIZE - 1] |= 0x80000000;
  return res;
}