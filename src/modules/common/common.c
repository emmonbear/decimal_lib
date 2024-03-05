/**
 * @file bank_rouding.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief Common module
 * @version 0.1
 * @date 2024-02-27
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/common.h"

#include "../include/comparison.h"

/**
 * @brief Function of bank rounding of a number of uint192_t type
 *
 * @param[in] integer integer part of a number
 * @param[in] fractional fractional part of a number
 * @param[out] code error code
 * @return uint192_t - rounded number
 */
uint192_t bank_rouding(uint192_t integer, uint192_t fractional, int *code) {
  if (s21_is_equal(uint192_to_decimal(integer), DCML_MAX) &&
      !s21_is_equal(uint192_to_decimal(fractional), DCML_ZERO)) {
    *code = (GET_SIGN(integer.Lbits[3])) ? 2 : 1;
    return LDCML_ZERO;
  }

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

/**
 * @brief Return the modulus of a number of type decimal_t
 *
 * @param[in] value the number whose modulus is to be returned
 * @return s21_decimal - modulus of value
 */
s21_decimal dabs(s21_decimal value) {
  value.bits[DEC_SIZE - 1] = (value.bits[DEC_SIZE - 1] << 1) >> 1;
  return value;
}

/**
 * @brief Checking a number of decimal_t type for correctness
 *
 * @details
 *
 * The degree of a decimal number cannot be greater than 28
 * Bits 0 through 15 must be zero
 * Bits 24 through 30 must be zero
 *
 * @param[in] value
 * @retval 0 - incorrect decimal
 * @retval 1 - correct decimal
 */
int is_correct(s21_decimal value) {
  unsigned int empty = value.bits[DEC_SIZE - 1] & 0x7F00FFFF;
  uint8_t power = GET_POWER(value.bits[DEC_SIZE - 1]);

  return ((empty) || (power > 28)) ? 0 : 1;
}

/**
 * @brief Input arguments validation
 *
 * @param[in] value_1
 * @param[in] value_2
 * @param[in] result
 * @return true
 * @return false
 */
bool check_args(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  return (!result || !is_correct(value_1) || !is_correct(value_2)) ? false
                                                                   : true;
}