/**
 * @file binary_operations.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief Bit operations module
 * @version 0.1
 * @date 2024-02-26
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/common.h"

static void zero_service_bits(uint192_t *value_1, uint192_t *value_2);

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
    shift_left(&overflow_bits, 1);
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
  uint8_t high_bit = get_high_bit(value_2);

  for (uint8_t i = 0; i <= high_bit; i++) {
    if (IS_SET_BIT(value_2, i)) {
      res = binary_add(res, tmp);
    }

    shift_left(&tmp, 1);
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

  uint192_t shifted_divisor = value_2;
  shift_left(&shifted_divisor, shift);
  uint192_t dividend = value_1;
  bool operation = SUB;

  while (shift >= 0) {
    if (operation == SUB) {
      tmp_remaider = binary_sub(dividend, shifted_divisor);
    } else {
      tmp_remaider = binary_add(dividend, shifted_divisor);
    }

    shift_left(&quotient, 1);

    if (!IS_SET_BIT(tmp_remaider, (MAX_BITS - 1))) {
      SET_BIT(quotient, 0);
    }

    dividend = tmp_remaider;
    shift_left(&dividend, 1);

    if (!IS_SET_BIT(tmp_remaider, (MAX_BITS - 1))) {
      operation = SUB;
    } else {
      operation = ADD;
    }
    --shift;
  }
  if (IS_SET_BIT(tmp_remaider, (MAX_BITS - 1))) {
    tmp_remaider = binary_add(tmp_remaider, shifted_divisor);
  }

  shift_right(&tmp_remaider, (high_bit_1 - high_bit_2));
  uint192_t res = quotient;
  if (remainder) {
    *remainder = tmp_remaider;
  }
  return res;
}

/**
 * @brief Normalization the orders of powers of the numbers value_1 and value_2
 *
 * @param[out] value_1 Pointer to number of uint192_t type
 * @param[out] value_2 Pointer to number of uint192_t type
 */
void binary_normalizaton(uint192_t *Lvalue_1, uint192_t *Lvalue_2) {
  uint8_t power_1 = GET_POWER(Lvalue_1->Lbits[DEC_SIZE - 1]);
  uint8_t power_2 = GET_POWER(Lvalue_2->Lbits[DEC_SIZE - 1]);

  zero_service_bits(Lvalue_1, Lvalue_2);
  if (power_1 > power_2) {
    *Lvalue_2 = binary_mul(*Lvalue_2, get_ten_pow(power_1 - power_2));
  } else if (power_1 < power_2) {
    *Lvalue_1 = binary_mul(*Lvalue_1, get_ten_pow(power_2 - power_1));
  }
}

static void zero_service_bits(uint192_t *value_1, uint192_t *value_2) {
  value_1->Lbits[DEC_SIZE - 1] = 0;
  value_2->Lbits[DEC_SIZE - 1] = 0;
}

uint192_t decimal_to_uint192(s21_decimal value) {
  uint192_t res = LDCML_ZERO;

  for (uint8_t i = 0; i < DEC_SIZE; i++) {
    res.Lbits[i] = value.bits[i];
  }

  return res;
}

s21_decimal uint192_to_decimal(uint192_t value) {
  s21_decimal res = DCML_ZERO;

  for (uint8_t i = 0; i < DEC_SIZE; i++) {
    res.bits[i] = value.Lbits[i];
  }

  return res;
}

uint192_t get_ten_pow(uint8_t pow) {
  uint192_t res = ONE;

  for (uint8_t i = 0; i < pow; i++) {
    res = binary_mul(res, TEN);
  }

  return res;
}

uint8_t get_divider(uint192_t value) {
  uint8_t res = 0;
  uint192_t quotient = binary_div(value, LDCML_MAX, NULL);

  while (1) {
    int8_t compare = binary_compare(quotient, get_ten_pow(res));
    if ((compare == LESS) || (compare == EQUAL)) {
      break;
    }
    res++;
  }

  uint192_t tmp = binary_div(value, get_ten_pow(res), NULL);
  if (tmp.Lbits[3] != 0 || tmp.Lbits[4] != 0 || tmp.Lbits[5] != 0) {
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