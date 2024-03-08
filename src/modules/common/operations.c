/**
 * @file binary_operations.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief Main module for operations functions
 * @version 1.0
 * @date 2024-02-26
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/common.h"

static int get_high_bit(uint192_t value);

/**
 * @brief Bitwise addition of two positive numbers of uint192_t type
 *
 * @param[in] value_1 first summand
 * @param[in] value_2 second summand
 * @return uint192_t - value_1 + value_2
 */
uint192_t binary_add(uint192_t value_1, uint192_t value_2) {
  uint192_t res = value_1;
  uint192_t tmp = value_2;

  while (!is_eq_zero(tmp)) {
    uint192_t overflow_bits = binary_and(res, tmp);
    overflow_bits = shift_left(overflow_bits, 1);
    res = binary_xor(res, tmp);
    tmp = overflow_bits;
  }

  return res;
}

/**
 * @brief Bitwise subtraction of two positive numbers of uint192_t type
 *
 * @param[in] value_1 removable
 * @param[in] value_2 subtracted
 * @return uint192_t - value_1 - value_2
 */
uint192_t binary_sub(uint192_t value_1, uint192_t value_2) {
  value_2 = binary_not(value_2);
  value_2 = binary_add(value_2, ONE);
  uint192_t res = binary_add(value_1, value_2);

  return res;
}

/**
 * @brief Bitwise multiplication of two positive numbers of uint192_t type
 *
 * @param[in] value_1 multiplied
 * @param[in] value_2 multiplier
 * @return uint192_t - value_1 * value_2
 */
uint192_t binary_mul(uint192_t value_1, uint192_t value_2) {
  uint192_t res = LDCML_ZERO;
  uint192_t tmp = value_1;
  uint16_t high_bit = get_high_bit(value_2);

  for (uint16_t i = 0; i <= high_bit; i++) {
    if (IS_SET_BIT(value_2, i)) {
      res = binary_add(res, tmp);
    }

    tmp = shift_left(tmp, 1);
  }

  return res;
}

/**
 * @brief Bitwise division of two positive numbers of uint192_t type
 *
 * @param[in] value_1 divisible
 * @param[in] value_2 divider
 * @param[out] remainder remainder of division
 * @return uint192_t - value_1 / value_2
 */
uint192_t binary_div(uint192_t value_1, uint192_t value_2,
                     uint192_t *remainder) {
  if (is_eq_zero(value_1)) {
    *remainder = (remainder) ? LDCML_ZERO : *remainder;
    return LDCML_ZERO;
  }

  if (binary_compare(value_1, value_2) == LESS) {
    *remainder = (remainder) ? value_1 : *remainder;
    return LDCML_ZERO;
  }

  uint192_t tmp_remaider = LDCML_ZERO;
  uint192_t quotient = LDCML_ZERO;

  unsigned int high_bit_1 = get_high_bit(value_1);
  unsigned int high_bit_2 = get_high_bit(value_2);
  int shift = high_bit_1 - high_bit_2;

  uint192_t shifted_divisor = shift_left(value_2, shift);
  bool operation = SUB;

  for (uint192_t dividend = value_1; shift >= 0; shift--) {
    tmp_remaider = (operation == SUB) ? binary_sub(dividend, shifted_divisor)
                                      : binary_add(dividend, shifted_divisor);

    quotient = shift_left(quotient, 1);

    if (!IS_SET_BIT(tmp_remaider, (MAX_BITS - 1))) {
      quotient.Lbits[0] |= 1;
    }

    dividend = shift_left(tmp_remaider, 1);

    operation = (!IS_SET_BIT(tmp_remaider, (MAX_BITS - 1))) ? SUB : ADD;
  }

  if (IS_SET_BIT(tmp_remaider, (MAX_BITS - 1))) {
    tmp_remaider = binary_add(tmp_remaider, shifted_divisor);
  }

  *remainder = (remainder)
                   ? shift_right(tmp_remaider, (high_bit_1 - high_bit_2))
                   : *remainder;

  return quotient;
}

/**
 * @brief Normalization the orders of powers of the numbers value_1 and value_2
 *
 * @param[out] value_1 Pointer to number of uint192_t type
 * @param[out] value_2 Pointer to number of uint192_t type
 */
void binary_normalizaton(uint192_t *Lvalue_1, uint192_t *Lvalue_2) {
  uint16_t power_1 = GET_POWER(Lvalue_1->Lbits[SERVICE]);
  uint16_t power_2 = GET_POWER(Lvalue_2->Lbits[SERVICE]);

  zero_service_bits(Lvalue_1, Lvalue_2);
  if (power_1 > power_2) {
    *Lvalue_2 = ten_mul(*Lvalue_2, power_1 - power_2);
  } else if (power_1 < power_2) {
    *Lvalue_1 = ten_mul(*Lvalue_1, power_2 - power_1);
  }
}

/**
 * @brief Zero out decimal_t[SERVICE]
 *
 * @param[out] value_1
 * @param[out] value_2
 */
void zero_service_bits(uint192_t *value_1, uint192_t *value_2) {
  value_1->Lbits[SERVICE] = 0;
  value_2->Lbits[SERVICE] = 0;
}

/**
 * @brief Convert decimal_t number to uint192_t
 *
 * @param[in] value conversion number
 * @return uint192_t - converted number
 */
uint192_t decimal_to_uint192(s21_decimal value) {
  uint192_t res = LDCML_ZERO;

  for (uint8_t i = 0; i < DEC_SIZE; i++) {
    res.Lbits[i] = value.bits[i];
  }

  return res;
}

/**
 * @brief Convert uint192_t number to uint192_t decimal_t
 *
 * @param[in] value conversion number
 * @return s21_decimal - converted number
 */
s21_decimal uint192_to_decimal(uint192_t value) {
  s21_decimal res = DCML_ZERO;

  for (uint8_t i = 0; i < DEC_SIZE; i++) {
    res.bits[i] = value.Lbits[i];
  }

  return res;
}

/**
 * @brief Return 10 to degree index as uint192_t
 *
 * @param[in] pow power of ten
 * @return uint192_t - multiplication result
 */
uint192_t get_ten_pow(uint8_t pow) {
  uint192_t res = ONE;

  for (uint16_t i = 0; i < pow; i++) {
    res = binary_add(shift_left(res, 3), shift_left(res, 1));
  }

  return res;
}

/**
 * @brief Multiply a number of uint192_t type by 10e (index)
 *
 * @param[in] num multiplied number
 * @param[in] pow power of ten
 * @return uint192_t - multiplication result
 */
uint192_t ten_mul(uint192_t num, uint8_t pow) {
  for (uint16_t i = 0; i < pow; i++) {
    num = binary_add(shift_left(num, 3), shift_left(num, 1));
  }

  return num;
}

/**
 * @brief Return the degree 10 required to fit a uint192_t into a decimal_t
 *
 * @details
 *
 * In fact, this function shows how much decimal_t MAX is possessed in the
 * number of uint192_t The usual abbreviation
 *
 * @param[in] value number to be reduced
 * @return uint8_t - power of ten
 */
uint16_t get_divider(uint192_t value) {
  uint16_t res = 0;
  uint192_t quotient = binary_div(value, dcml_max(), NULL);
  uint192_t pow = ONE;
  int8_t compare = LESS;

  for (;; res++, pow = ten_mul(pow, 1)) {
    compare = binary_compare(quotient, pow);
    if (compare != GREATER) {
      break;
    }
  }

  uint192_t tmp = binary_div(value, pow, NULL);
  if (check_overflow(tmp)) {
    res++;
  }

  return res;
}

/**
 * @brief Get the high bit object
 *
 * @param[in] value uint192_t type number
 * @return int - high bit index
 */
static int get_high_bit(uint192_t value) {
  int16_t bit = MAX_BITS - 1;

  for (int j = LDEC_SIZE - 1; !value.Lbits[j]; j--) {
    bit -= UINT_BITS;
  }

  for (; bit >= 0; bit--) {
    if (IS_SET_BIT(value, bit)) {
      break;
    }
  }

  return bit;
}
