/**
 * @file div.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief Division two decimals
 * @version 0.1
 * @date 2024-03-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/arithmetic.h"

static int div_additional(uint192_t divider, uint192_t quotient, uint192_t remainder, s21_decimal *result);
static int calc_fract_part(uint192_t *quotient, uint192_t divider, uint192_t *remainder);

/**
 * @brief Division two decimals
 *
 * @param[in] value_1 divisible
 * @param[in] value_2 divider
 * @param[out] result quotient
 * @return int - error code
 * @retval OK = 0 - OK;
 * @retval BIG = 1 - the number is too large or equal to infinity;
 * @retval SMALL = 2 - number is too small or equal to negative infinity;
 * @retval ZERO_DIV = 3 - division by 0;
 * @retval INCORRECT = 4 - incorrect decimal_t;
 */
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (!check_args(value_1, value_2, result)) {
    return INCORRECT;
  }

  if (s21_is_equal(value_2, DCML_ZERO)) {
    return ZERO_DIV;
  }

  if (s21_is_equal(value_1, DCML_ZERO)) {
    *result = DCML_ZERO;
    return OK;
  }

  *result = DCML_ZERO;
  int err_code = OK;

  uint8_t sign_1 = GET_SIGN(value_1.bits[SERVICE]);
  uint8_t sign_2 = GET_SIGN(value_2.bits[SERVICE]);

  uint192_t Lvalue_1 = decimal_to_uint192(value_1);
  uint192_t Lvalue_2 = decimal_to_uint192(value_2);

  binary_normalizaton(&Lvalue_1, &Lvalue_2);

  uint192_t remainder = LDCML_ZERO;
  uint192_t res = binary_div(Lvalue_1, Lvalue_2, &remainder);

  if (check_overflow(res)) {
    return (sign_1 != sign_2) ? SMALL : BIG;
  }

  err_code = div_additional(Lvalue_2, res, remainder, result);

  if (sign_1 != sign_2) {
    SET_SIGN(result->bits[SERVICE], NEGATIVE);
  }

  if (err_code == OK && s21_is_equal(*result, DCML_ZERO)) {
    err_code = SMALL;
  }

  return err_code;
}

/**
 * @brief Auxiliary function of division
 *
 * @param[in] divider
 * @param[in] quotient
 * @param[in] remainder
 * @param[out] result
 * @return int - error code
 * @retval OK = 0 - OK;
 * @retval BIG = 1 - the number is too large or equal to infinity;
 * @retval SMALL = 2 - number is too small or equal to negative infinity;
 * @retval ZERO_DIV = 3 - division by 0;
 * @retval INCORRECT = 4 - incorrect decimal_t;
 */
static int div_additional(uint192_t divider, uint192_t quotient, uint192_t remainder, s21_decimal *result) {
  int err_code = OK;

  uint8_t power_1 = calc_fract_part(&quotient, divider, &remainder);
  uint192_t res_tmp = LDCML_ZERO;
  uint8_t power_2 = calc_fract_part(&res_tmp, divider, &remainder);
  SET_POWER(res_tmp.Lbits[SERVICE], power_2);

  quotient = bank_rouding(quotient, res_tmp);
  SET_POWER(quotient.Lbits[SERVICE], power_1);

  *result = uint192_to_decimal(quotient);

  return err_code;
}

/**
 * @brief Calculate the resulting degree of the result and relate the quotient
 * to the remainder
 *
 * @param quotient
 * @param divider
 * @param remainder
 * @return int - error code
 * @retval OK = 0 - OK;
 * @retval BIG = 1 - the number is too large or equal to infinity;
 * @retval SMALL = 2 - number is too small or equal to negative infinity;
 * @retval ZERO_DIV = 3 - division by 0;
 * @retval INCORRECT = 4 - incorrect decimal_t;
 */
static int calc_fract_part(uint192_t *quotient, uint192_t divider, uint192_t *remainder) {
  int power = 0;
  uint192_t number = *quotient;
  uint192_t remainder_tmp = *remainder;

  while (!(is_eq_zero(*remainder)) && power < MAX_SCALE) {
    uint192_t number_storage = number;
    uint192_t remainder_storage = remainder_tmp;
    number = ten_mul(number, 1);
    remainder_tmp = ten_mul(remainder_tmp, 1);
    uint192_t tmp = binary_div(remainder_tmp, divider, &remainder_tmp);
    number = binary_add(number, tmp);

    if (!is_correct(uint192_to_decimal(number))) {
      number = number_storage;
      remainder_tmp = remainder_storage;
      break;
    }
    ++power;
  }
  *quotient = number;
  *remainder = remainder_tmp;

  return power;
}
