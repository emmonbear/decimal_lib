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
  uint192_t res = LDCML_ZERO;

  if (binary_compare(fractional, POINT_FIVE) == EQUAL) {
    if (IS_EVEN(integer)) {
      for (uint8_t i = 0; i < (LDEC_SIZE - 1); i++) {
        res.Lbits[i] = integer.Lbits[i];
      }
    } else {
      res = binary_add(integer, ONE);
    }
  } else if (binary_compare(fractional, POINT_FIVE) == GREATER) {
    res = binary_add(integer, ONE);
  } else {
    res = integer;
  }

  return res;
}

s21_decimal dabs(s21_decimal value) {
  value.bits[DEC_SIZE - 1] = (value.bits[DEC_SIZE - 1] << 1) >> 1;
  return value;
}
