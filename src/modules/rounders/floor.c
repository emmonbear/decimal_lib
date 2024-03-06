/**
 * @file floor.c
 * @author kossadda (https://github.com/kossadda)
 * @brief Main module for s21_floor function
 * @version 1.0
 * @date 2024-03-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./../include/arithmetic.h"
#include "./../include/comparison.h"
#include "./../include/rounders.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  if (!result || !is_correct(value)) {
    return ROUND_ERROR;
  }

  bool sign = GET_SIGN(value.bits[SERVICE]);
  uint8_t power = GET_POWER(value.bits[SERVICE]);
  value.bits[SERVICE] = 0;

  uint192_t fractional = LDCML_ZERO;
  uint192_t integer =
      binary_div(decimal_to_uint192(value), get_ten_pow(power), &fractional);
  SET_POWER(fractional.Lbits[SERVICE], power);
  *result = uint192_to_decimal(integer);
  if (sign && s21_is_greater(uint192_to_decimal(fractional), DCML_ZERO)) {
    add_positive(*result, DCML_ONE, result);
  }

  SET_SIGN(result->bits[SERVICE], sign);

  return ROUND_OK;
}
