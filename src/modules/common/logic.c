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

#include "../include/common.h"

/**
 * @brief Check if all bits of ${value} are zeros.
 *
 * @param[in] value number of uint192_t type, bits of which must be checked.
 * @return true - all bits are zero.
 * @return false - not all bits are zero.
 */
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

bool dcml_is_zero(s21_decimal value) {
  bool res = true;

  for (uint8_t i = 0; i < (DEC_SIZE - 1); i++) {
    if (value.bits[i] != 0) {
      res = false;
      break;
    }
  }

  return res;
}

/**
 * @brief Bitwise AND of two positive numbers of uint192_t type
 *
 * @param[in] value_1 uint192_t type number
 * @param[in] value_2 uint192_t type number
 * @return uint192_t - value_1 & value_2
 */
uint192_t binary_and(uint192_t value_1, uint192_t value_2) {
  uint192_t res = LDCML_ZERO;

  for (uint8_t i = 0; i < LDEC_SIZE; i++) {
    res.Lbits[i] = value_1.Lbits[i] & value_2.Lbits[i];
  }

  return res;
}

/**
 * @brief Bitwise Exclusive OR of two positive numbers of uint192_t type
 *
 * @param[in] value_1 uint192_t type number
 * @param[in] value_2 uint192_t type number
 * @return uint192_t - value_1 ^ value_2
 */
uint192_t binary_xor(uint192_t value_1, uint192_t value_2) {
  uint192_t res = LDCML_ZERO;

  for (uint8_t i = 0; i < LDEC_SIZE; i++) {
    res.Lbits[i] = value_1.Lbits[i] ^ value_2.Lbits[i];
  }

  return res;
}

/**
 * @brief Bitwise NOT for positive number uint192_t
 *
 * @param[in] value uint192_t type number
 * @return uint192_t - ~value
 */
uint192_t binary_not(uint192_t value) {
  uint192_t res = LDCML_ZERO;

  for (uint8_t i = 0; i < LDEC_SIZE; i++) {
    res.Lbits[i] = ~value.Lbits[i];
  }

  return res;
}

/**
 * @brief Bitwise compare two numbers of uint192_t type
 *
 * @param[in] value_1 uint192_t type number
 * @param[in] value_2 uint192_t type number
 * @retval LESS = -1 - value_1 < value_2
 * @retval EQUAL = 0 - value_1 = value_2
 * @retval GREAT = 1 - value_1 > value_2
 *
 */
int binary_compare(uint192_t value_1, uint192_t value_2) {
  int res = EQUAL;

  for (int i = MAX_BITS - 1; i >= 0; i--) {
    bool bit_1 = IS_SET_BIT(value_1, i);
    bool bit_2 = IS_SET_BIT(value_2, i);

    if ((!bit_1) && (bit_2)) {
      res = LESS;
      break;
    } else if ((bit_1) && (!bit_2)) {
      res = GREATER;
      break;
    }
  }

  return res;
}