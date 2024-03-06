/**
 * @file binary_logic.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief Binary logic module
 * @version 0.1
 * @date 2024-02-25
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/common.h"

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
