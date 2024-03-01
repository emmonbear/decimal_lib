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

#include "../include/comparison.h"

uint192_t bank_rouding(uint192_t integer, uint192_t fractional) {
  uint192_t res = LDCML_ZERO;

  if (s21_is_equal(uint192_to_decimal(fractional), POINT_FIVE)) {
    if (IS_EVEN(integer)) {
      for (uint8_t i = 0; i < (LDEC_SIZE - 1); i++) {
        res.Lbits[i] = integer.Lbits[i];
      }
    } else {
      res = binary_add(integer, ONE);
    }
  } else if (s21_is_greater(uint192_to_decimal(fractional), POINT_FIVE)) {
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

/**
 * @brief
 *
 * @param value
 * @retval 0 - incorrect decimal
 * @retval 1 - correct decimal
 */
int is_correct(s21_decimal value) {
  unsigned int empty = value.bits[DEC_SIZE - 1] & 0x7F00FFFF;
  uint8_t power = GET_POWER(value.bits[DEC_SIZE - 1]);

  return ((empty) || (power > 28)) ? 0 : 1;
}
