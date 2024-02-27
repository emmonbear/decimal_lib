/**
 * @file bit_lib.h
 * @author emmonbea (https://github.com/emmonbear)
 * @brief
 * @version 0.1
 * @date 2024-02-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef BIT_LIB_H
#define BIT_LIB_H

#include "./common.h"

typedef enum {
  UINT_BITS = 32,
  MAX_BITS = LDEC_SIZE * UINT_BITS,
} bits_count;

typedef enum {
  LESS = -1,
  EQUAL,
  GREATER,
} compare_code;

typedef enum {
  ADD,
  SUB,
} div_operation;

void shift_left(uint192_t *value, unsigned int shift);
void shift_right(uint192_t *value, unsigned int shift);
void binary_normalizaton(uint192_t *value_1, uint192_t *value_2);

uint192_t binary_add(uint192_t value_1, uint192_t value_2);
uint192_t binary_sub(uint192_t value_1, uint192_t value_2);
uint192_t binary_mul(uint192_t value_1, uint192_t value_2);
uint192_t binary_div(uint192_t value_1, uint192_t value_2,
                     uint192_t *remainder);

bool is_eq_zero(uint192_t value);
int get_high_bit(uint192_t value);

uint192_t binary_and(uint192_t value_1, uint192_t value_2);
uint192_t binary_xor(uint192_t value_1, uint192_t value_2);
uint192_t binary_not(uint192_t value);

int binary_compare(uint192_t value_1, uint192_t value_2);

uint192_t decimal_to_uint192(decimal_t value);
uint192_t get_ten_pow(uint8_t pow);
void zero_service_bits(uint192_t *value_1, uint192_t *value_2);

#endif  // BIT_LIB_H