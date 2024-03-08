/**
 * @file shifts.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief Main module for shifting functions
 * @version 1.0
 * @date 2024-02-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/common.h"

/**
 * @brief Shift value by shift bits to the left
 *
 * @param[in] num number of uint192_t type to be shifted to the left by shift
 * @param[in] shift number specifying by how much to shift value to the left
 * @return uint192_t - shifted number
 */
uint192_t shift_left(uint192_t num, unsigned int shift) {
  for (; shift >= UINT_BITS; shift -= UINT_BITS) {
    for (int16_t i = LDEC_SIZE - 1; i > 0; i--) {
      num.Lbits[i] = num.Lbits[i - 1];
    }

    num.Lbits[0] = 0;
  }

  for (uint32_t prev = 0, crnt = 0, i = 0; i < LDEC_SIZE && shift; i++) {
    prev = num.Lbits[i] >> (UINT_BITS - shift);
    num.Lbits[i] = num.Lbits[i] << shift | crnt;
    crnt = prev;
  }

  return num;
}

/**
 * @brief Shift value by shift bits to the right
 *
 * @param[in] num number of uint192_t type to be shifted to the left by shift
 * @param[in] shift number specifying by how much to shift value to the left
 * @return uint192_t - shifted number
 */
uint192_t shift_right(uint192_t num, unsigned int shift) {
  for (; shift >= UINT_BITS; shift -= UINT_BITS) {
    for (int16_t i = 0; i < LDEC_SIZE - 1; i++) {
      num.Lbits[i] = num.Lbits[i + 1];
    }

    num.Lbits[LDEC_SIZE - 1] = 0;
  }

  for (uint32_t prev = 0, crnt = 0, i = LDEC_SIZE; i != 0 && shift; i--) {
    crnt = num.Lbits[i - 1] << (UINT_BITS - shift);
    num.Lbits[i - 1] = num.Lbits[i - 1] >> shift | prev;
    prev = crnt;
  }

  return num;
}
