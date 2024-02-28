/**
 * @file shifts.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief 
 * @version 0.1
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/common.h" 

/**
 * @brief Shift ${value} by ${shift} bits to the left
 *
 * @param[out] value number of uint192_t type to be shifted to the left by
 * ${shift}
 * @param[in] shift number specifying by how much to shift ${value} to the left
 */
void shift_left(uint192_t *value, unsigned int shift) {
  for (unsigned int i = 0; i < shift; i++) {
    bool carry = false;

    for (uint8_t j = 0; j < LDEC_SIZE; j++) {
      unsigned int temp = (value->Lbits[j] >> 31) & 1;
      value->Lbits[j] <<= 1;
      value->Lbits[j] |= carry;
      carry = temp;
    }
  }
}

/**
 * @brief Shift ${value} by ${shift} bits to the left
 *
 * @param[out] value number of uint192_t type to be shifted to the left by
 * ${shift}
 * @param[in] shift number specifying by how much to shift ${value} to the left
 */
void shift_right(uint192_t *value, unsigned int shift) {
  for (unsigned int i = 0; i < shift; i++) {
    bool carry = false;

    for (int8_t j = LDEC_SIZE - 1; j >= 0; j--) {
      unsigned int temp = value->Lbits[j] & 1;
      value->Lbits[j] >>= 1;
      value->Lbits[j] |= carry ? 1 << 31 : 0;
      carry = temp;
    }
  }
}