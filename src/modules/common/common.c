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
  if (binary_compare(integer, dcml_max()) == EQUAL &&
      !s21_is_equal(uint192_to_decimal(fractional), DCML_ZERO)) {
    *code = (GET_SIGN(integer.Lbits[SERVICE])) ? 2 : 1;
    return LDCML_ZERO;
  }

  uint192_t res = LDCML_ZERO;
  s21_decimal point_five = {{5}};
  SET_POWER(point_five.bits[SERVICE], 1);

  if (s21_is_equal(uint192_to_decimal(fractional), point_five)) {
    if (IS_EVEN(integer)) {
      res = integer;
    } else {
      res = binary_add(integer, ONE);
    }
  } else if (s21_is_greater(uint192_to_decimal(fractional), point_five)) {
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
  value.bits[SERVICE] = (value.bits[SERVICE] << 1) >> 1;
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
 * @param[in] value number being checked
 * @retval false - incorrect decimal
 * @retval true - correct decimal
 */
bool is_correct(s21_decimal value) {
  unsigned int empty = value.bits[SERVICE] & 0x7F00FFFF;
  uint8_t power = GET_POWER(value.bits[SERVICE]);

  return ((empty) || (power > MAX_SCALE)) ? false : true;
}

/**
 * @brief Input arguments validation
 *
 * @param[in] value_1 first number
 * @param[in] value_2 second number
 * @param[in] result result number
 * @return true - all arguments is valid
 * @return false - contains one or more invalid arguments
 */
bool check_args(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  return (!result || !is_correct(value_1) || !is_correct(value_2)) ? false
                                                                   : true;
}

/**
 * @brief Check that insignificant bits are zero
 *
 * @param value checked number decimal_t
 * @retval false - all bits zero
 * @retval true - not all bits are zeros
 */
bool check_overflow(uint192_t value) {
  int err_code = false;

  for (uint8_t i = SERVICE; i < LDEC_SIZE; i++) {
    if (value.Lbits[i]) {
      err_code = true;
      break;
    }
  }

  return err_code;
}

/**
 * @brief Check if all bits of ${value} are zeros.
 *
 * @param[in] value number of uint192_t type, bits of which must be checked.
 * @retval true - all bits are zero.
 * @retval false - not all bits are zero.
 */
bool is_eq_zero(uint192_t value) {
  bool res = true;

  for (uint8_t i = 0; i < LDEC_SIZE; i++) {
    if (value.Lbits[i]) {
      res = false;
      break;
    }
  }

  return res;
}

/**
 * @brief Check if all significant bits of a decimal_t number are zero
 *
 * @param[in] value Checked number decimal_t
 * @retval true - no significant bits
 * @retval false - contains significant bits
 */
bool dcml_is_zero(s21_decimal value) {
  bool res = true;

  for (uint8_t i = 0; i < SERVICE; i++) {
    if (value.bits[i]) {
      res = false;
      break;
    }
  }

  return res;
}

/**
 * @brief Check if all significant bits of a decimal_t number are zero
 *
 * @param[in] value Checked number decimal_t
 * @retval true - no significant bits
 * @retval false - contains significant bits
 */
uint192_t dcml_max() {
  uint192_t value = LDCML_ZERO;

  for (uint8_t i = 0; i < SERVICE; i++) {
    value.Lbits[i] = 0xFFFFFFFF;
  }

  return value;
}
