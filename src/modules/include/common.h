/**
 * @file common.h
 * @author emmonbea (https://github.com/emmonbear)
 * @brief Common header
 * @version 0.1
 * @date 2024-02-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include <stdio.h>

#include "./macros.h"
#include "stdbool.h"

/// @brief Enumerations with array sizes.
typedef enum {
  DEC_SIZE = 4,                    ///< Int array used for the final result.
  LDEC_SIZE = (DEC_SIZE - 1) * 2,  ///< Int array used for precise calculations.
} array_size;

/// @brief Decimal representation. Basic project type.
typedef struct {
  unsigned int bits[DEC_SIZE];  ///< Bits: 96 - significant, 32 - service.
} s21_decimal;

/// @brief Long decimal representation. Intended for calculation accuracy.
typedef struct {
  unsigned int Lbits[LDEC_SIZE];  ///< Bits: twice of basic type significants.
} uint192_t;

/// @brief Enumeration of decimal_t signs.
typedef enum {
  POSITIVE = 0,  ///< Positive sign.
  NEGATIVE = 1,  ///< Negative sign.
} decimal_sign;

/// @brief Enumeration of bits counts.
typedef enum {
  UINT_BITS = 32,                    ///< Number of bits in uint.
  MAX_BITS = LDEC_SIZE * UINT_BITS,  ///< Number of bits in uint192_t.
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

//============================== SHIFTS ========================================
void shift_left(uint192_t *value, unsigned int shift);
void shift_right(uint192_t *value, unsigned int shift);
//==============================================================================

//========================== BINARY_OPERATIONS =================================
uint192_t binary_add(uint192_t value_1, uint192_t value_2);
uint192_t binary_sub(uint192_t value_1, uint192_t value_2);
uint192_t binary_mul(uint192_t value_1, uint192_t value_2);
uint192_t binary_div(uint192_t value_1, uint192_t value_2,
                     uint192_t *remainder);
int get_high_bit(uint192_t value);
void binary_normalizaton(uint192_t *value_1, uint192_t *value_2);
uint192_t decimal_to_uint192(s21_decimal value);
uint192_t get_ten_pow(uint8_t pow);
uint8_t get_divider(uint192_t value);
s21_decimal uint192_to_decimal(uint192_t value);
//==============================================================================

//=============================== BINARY_LOGIC =================================
uint192_t binary_and(uint192_t value_1, uint192_t value_2);
uint192_t binary_xor(uint192_t value_1, uint192_t value_2);
uint192_t binary_not(uint192_t value);
bool is_eq_zero(uint192_t value);
int binary_compare(uint192_t value_1, uint192_t value_2);
bool dcml_is_zero(s21_decimal value);
//==============================================================================

//============================= COMMON FUNCTIONS ===============================
s21_decimal dabs(s21_decimal value);
uint192_t bank_rouding(uint192_t integer, uint192_t fractional, int *code);
int is_correct(s21_decimal value);
//==============================================================================

#endif  // COMMON_H
