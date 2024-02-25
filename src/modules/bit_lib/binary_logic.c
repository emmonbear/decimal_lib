/**
 * @file binary_logic.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief
 * @version 0.1
 * @date 2024-02-25
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/bit_lib.h"

bool is_eq_zero(uint192_t value) {
  bool res = true;

  for (uint8_t i = 0; i < LDEC_SIZE; i++) {
    if (value.Lbits[i] != 0) {
      res = false;
      break;
    }
  }

  return res;
}

uint192_t binary_and(uint192_t value_1, uint192_t value_2) {
  uint192_t res = SET_ZERO;

  for (uint8_t i = 0; i < LDEC_SIZE; i++) {
    res.Lbits[i] = value_1.Lbits[i] & value_2.Lbits[i];
  }

  return res;
}

uint192_t binary_xor(uint192_t value_1, uint192_t value_2) {
  uint192_t res = SET_ZERO;

  for (uint8_t i = 0; i < LDEC_SIZE; i++) {
    res.Lbits[i] = value_1.Lbits[i] ^ value_2.Lbits[i];
  }

  return res;
}

uint192_t binary_not(uint192_t value) {
  uint192_t res = SET_ZERO;

  for (uint8_t i = 0; i < LDEC_SIZE; i++) {
    res.Lbits[i] = ~value.Lbits[i];
  }

  return res;
}

int get_high_bit(uint192_t value) {
  int res = -1;

  for (int16_t i = MAX_BITS - 1; i >= 0; i--) {
    if (IS_SET_BIT(value, i)) {
      res = i;
      break;
    }
  }

  return res;
}