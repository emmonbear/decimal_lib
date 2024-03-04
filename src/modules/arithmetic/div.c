/**
 * @file div.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief
 * @version 0.1
 * @date 2024-03-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/arithmetic.h"

/**
 * @brief
 *
 * @param value_1
 * @param value_2
 * @param result
 * @return int
 */
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int err_code = OK;

  if (s21_is_equal(value_2, DCML_ZERO)) {
    return ZERO_DIV;
  }

  uint8_t sign_1 = GET_SIGN(value_1.bits[DEC_SIZE - 1]);
  uint8_t sign_2 = GET_SIGN(value_2.bits[DEC_SIZE - 1]);

  uint192_t Lvalue_1 = decimal_to_uint192(value_1);
  uint192_t Lvalue_2 = decimal_to_uint192(value_2);

  binary_normalizaton(&Lvalue_1, &Lvalue_2);

  uint192_t remainder = LDCML_ZERO;
  uint192_t res = binary_div(Lvalue_1, Lvalue_2, &remainder);

  if ((res.Lbits[DEC_SIZE - 1] != 0) ||
      (res.Lbits[LDEC_SIZE - 1] == 0) && (res.Lbits[LDEC_SIZE - 2] == 0)) {
    err_code = (sign_1 != sign_2) ? SMALL : BIG;
    *result = DCML_ZERO;
  } else {
    err_code = div_additional(Lvalue_2, res, remainder, result);

    if (sign_1 != sign_2) {
      SET_SIGN(result->bits[DEC_SIZE - 1], NEGATIVE);
    }

    if ((GET_SIGN(result->bits[DEC_SIZE - 1]) == NEGATIVE) &&
        (err_code == BIG)) {
      err_code = SMALL;
    }

    if ((err_code = OK) && (s21_is_not_equal(value_1, DCML_ZERO)) &&
        (s21_is_equal(*result, DCML_ZERO))) {
      err_code = SMALL;
    }
  }

  return err_code;
}

/**
 * @brief
 *
 * @param divider
 * @param quotient
 * @param remainder
 * @param result
 * @return int
 */
int div_additional(uint192_t divider, uint192_t quotient, uint192_t remainder,
                   s21_decimal *result) {
  int err_code = OK;

  uint8_t power_1 = calc_fract_part(&quotient, divider, &remainder);
  uint192_t res_tmp = LDCML_ZERO;
  uint8_t power_2 = calc_fract_part(&res_tmp, divider, &remainder);
  SET_POWER(res_tmp.Lbits[DEC_SIZE - 1], power_2);

  quotient = bank_rouding(quotient, res_tmp, &err_code);
  SET_POWER(quotient.Lbits[DEC_SIZE - 1], power_1);

  if (((quotient.Lbits[LDEC_SIZE - 1] != 0) &&
       (quotient.Lbits[LDEC_SIZE - 2] != 0)) ||
      (!is_correct(uint192_to_decimal(quotient)))) {
    err_code = BIG;
    *result = DCML_ZERO;
  } else {
    *result = uint192_to_decimal(quotient);
  }

  return err_code;
}

/**
 * @brief
 *
 * @param quotient
 * @param divider
 * @param remainder
 * @return int
 */
int calc_fract_part(uint192_t *quotient, uint192_t divider,
                    uint192_t *remainder) {
  int power = 0;
  uint192_t number = *quotient;
  uint192_t remainder_tmp = *remainder;

  while (is_eq_zero(*remainder) && power < 28) {
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
