/**
 * @file mul.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief Multiplication module
 * @version 0.1
 * @date 2024-03-02
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/arithmetic.h"

/**
 * @brief Multiplication two decimals
 *
 * @param[in] value_1 multiplied
 * @param[in] value_2 multiplier
 * @param[out] result multiplication
 * @return int - error code
 * @retval OK = 0 - OK;
 * @retval BIG = 1 - the number is too large or equal to infinity;
 * @retval SMALL = 2 - number is too small or equal to negative infinity;
 * @retval ZERO_DIV = 3 - division by 0;
 * @retval INCORRECT = 4 - incorrect decimal_t;
 */
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int err_code = OK;

  if (!check_args(value_1, value_2, result)) {
    return INCORRECT;
  }

  uint8_t sign_1 = GET_SIGN(value_1.bits[DEC_SIZE - 1]);
  uint8_t sign_2 = GET_SIGN(value_2.bits[DEC_SIZE - 1]);

  if ((sign_1 == POSITIVE) && (sign_2 == POSITIVE)) {
    err_code = mul_positive(value_1, value_2, result);
  } else if ((sign_1 == POSITIVE) && (sign_2 == NEGATIVE)) {
    err_code = mul_positive(value_1, dabs(value_2), result);
    SET_SIGN(result->bits[DEC_SIZE - 1], !GET_SIGN(result->bits[DEC_SIZE - 1]));
  } else if ((sign_1 == NEGATIVE) && (sign_2 == POSITIVE)) {
    err_code = mul_positive(dabs(value_1), value_2, result);
    SET_SIGN(result->bits[DEC_SIZE - 1], !GET_SIGN(result->bits[DEC_SIZE - 1]));
  } else if ((sign_1 == NEGATIVE) && (sign_2 == NEGATIVE)) {
    err_code = mul_positive(dabs(value_1), dabs(value_2), result);
  }

  if ((GET_SIGN(result->bits[DEC_SIZE - 1]) == NEGATIVE) && (err_code == BIG)) {
    err_code = SMALL;
  }

  if ((err_code == OK) && (s21_is_not_equal(value_1, DCML_ZERO)) &&
      (s21_is_not_equal(value_2, DCML_ZERO)) &&
      (s21_is_equal(*result, DCML_ZERO))) {
    err_code = SMALL;
  }

  return err_code;
}

/**
 * @brief Multiplication two positive decimals
 *
 * @param[in] value_1 multiplied
 * @param[in] value_2 multiplier
 * @param[out] result multiplication
 * @return int - error code
 * @retval OK = 0 - OK;
 * @retval BIG = 1 - the number is too large or equal to infinity;
 * @retval SMALL = 2 - number is too small or equal to negative infinity;
 * @retval ZERO_DIV = 3 - division by 0;
 * @retval INCORRECT = 4 - incorrect decimal_t;
 */
int mul_positive(s21_decimal value_1, s21_decimal value_2,
                 s21_decimal *result) {
  int err_code = OK;

  int8_t power_1 = GET_POWER(value_1.bits[3]);
  int8_t power_2 = GET_POWER(value_2.bits[3]);

  uint192_t Lvalue_1 = decimal_to_uint192(value_1);
  uint192_t Lvalue_2 = decimal_to_uint192(value_2);

  zero_service_bits(&Lvalue_1, &Lvalue_2);

  uint192_t res_tmp = binary_mul(Lvalue_1, Lvalue_2);

  int8_t power_tmp = get_divider(res_tmp);
  int8_t res_power = (power_1 + power_2) - power_tmp;

  if (res_power < 0) {
    return BIG;
  }

  /// @todo edge case
  while (power_tmp > 28) {
    res_tmp = binary_div(res_tmp, get_ten_pow(1), NULL);
    --power_tmp;
  }

  if (res_power > 28) {
    power_tmp = res_power - 28 + power_tmp;
    res_power = 28;
  }

  uint192_t remainder = LDCML_ZERO;
  res_tmp = binary_div(res_tmp, get_ten_pow(power_tmp), &remainder);
  SET_POWER(remainder.Lbits[DEC_SIZE - 1], power_tmp);
  res_tmp = bank_rouding(res_tmp, remainder, &err_code);

  if ((res_tmp.Lbits[0]) || (res_tmp.Lbits[1]) || (res_tmp.Lbits[2])) {
    SET_POWER(res_tmp.Lbits[DEC_SIZE - 1], res_power);
  }

  *result = uint192_to_decimal(res_tmp);

  if (!is_correct(*result)) {
    err_code = BIG;
  }

  return err_code;
}