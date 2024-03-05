/**
 * @file sub.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief Subtraction module
 * @version 0.1
 * @date 2024-02-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/arithmetic.h"

/**
 * @brief Subtracting two decimal
 *
 * @param[in] value_1 diminishable
 * @param[in] value_2 subtracted
 * @param[out] result difference
 * @return int - error code
 * @retval OK = 0 - OK;
 * @retval BIG = 1 - the number is too large or equal to infinity;
 * @retval SMALL = 2 - number is too small or equal to negative infinity;
 * @retval ZERO_DIV = 3 - division by 0;
 * @retval INCORRECT = 4 - incorrect decimal_t;
 */
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int err_code = OK;

  if (!check_args(value_1, value_2, result)) {
    return INCORRECT;
  }

  uint8_t sign_1 = GET_SIGN(value_1.bits[DEC_SIZE - 1]);
  uint8_t sign_2 = GET_SIGN(value_2.bits[DEC_SIZE - 1]);

  if (sign_1 == POSITIVE) {
    if (sign_2 == POSITIVE) {
      if (s21_is_greater_or_equal(value_1, value_2)) {
        err_code = sub_positive(value_1, value_2, result);
      } else {
        err_code = sub_positive(value_2, value_1, result);
        SET_SIGN(result->bits[DEC_SIZE - 1], NEGATIVE);
      }
    } else {
      err_code = s21_add(value_1, dabs(value_2), result);
    }
  } else {
    if (sign_2 == POSITIVE) {
      err_code = s21_add(dabs(value_1), value_2, result);
      SET_SIGN(result->bits[DEC_SIZE - 1], NEGATIVE);
    } else {
      if (s21_is_greater_or_equal(value_1, value_2)) {
      err_code = sub_positive(dabs(value_2), dabs(value_1), result);
      } else {
      err_code = sub_positive(dabs(value_1), dabs(value_2), result);
      SET_SIGN(result->bits[DEC_SIZE - 1], NEGATIVE);
      }
    }
  }

  if ((GET_SIGN(result->bits[DEC_SIZE - 1]) == NEGATIVE) && (err_code == BIG)) {
    err_code = SMALL;
  }

  return err_code;
}

/**
 * @brief Subtracting two positive decimal
 *
 * @param[in] value_1 diminishable
 * @param[in] value_2 subtracted
 * @param[out] result difference
 * @return int - error code
 * @retval OK = 0 - OK;
 * @retval BIG = 1 - the number is too large or equal to infinity;
 * @retval SMALL = 2 - number is too small or equal to negative infinity;
 * @retval ZERO_DIV = 3 - division by 0;
 * @retval INCORRECT = 4 - incorrect decimal_t;
 */
int sub_positive(s21_decimal value_1, s21_decimal value_2, s21_decimal *res) {
  int err_code = OK;

  int8_t power_1 = GET_POWER(value_1.bits[3]);
  int8_t power_2 = GET_POWER(value_2.bits[3]);

  uint192_t Lvalue_1 = decimal_to_uint192(value_1);
  uint192_t Lvalue_2 = decimal_to_uint192(value_2);

  binary_normalizaton(&Lvalue_1, &Lvalue_2);
  uint192_t res_tmp = binary_sub(Lvalue_1, Lvalue_2);
  uint8_t power_tmp = get_divider(res_tmp);

  int8_t res_power = GET_MAX(power_1, power_2) - power_tmp;
  uint192_t remainder = LDCML_ZERO;
  res_tmp = binary_div(res_tmp, get_ten_pow(power_tmp), &remainder);
  SET_POWER(remainder.Lbits[DEC_SIZE - 1], power_tmp);
  res_tmp = bank_rouding(res_tmp, remainder, &err_code);
  SET_POWER(res_tmp.Lbits[DEC_SIZE - 1], res_power);
  *res = uint192_to_decimal(res_tmp);

  return err_code;
}