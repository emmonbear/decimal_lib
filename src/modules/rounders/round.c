/**
 * @file round.c
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-03-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./../include/rounders.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  if (!result) {
    return ROUND_ERROR;
  }

  bool sign = GET_SIGN(value.bits[3]);
  uint8_t power = GET_POWER(value.bits[3]);
  value.bits[3] = 0;

  uint192_t fractional = LDCML_ZERO;
  uint192_t integer =
      binary_div(decimal_to_uint192(value), get_ten_pow(power), &fractional);
  SET_POWER(fractional.Lbits[3], power);
  *result = uint192_to_decimal(bank_rouding(integer, fractional, NULL));
  SET_SIGN(result->bits[3], sign);

  return ROUND_OK;
}