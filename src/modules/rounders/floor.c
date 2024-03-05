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
  if (!result) {
    return ROUND_ERROR;
  }

  bool sign = GET_SIGN(value.bits[3]);
  uint8_t power = GET_POWER(value.bits[3]);
  value.bits[DEC_SIZE - 1] = 0;

  uint192_t fractional = LDCML_ZERO;
  uint192_t integer =
      binary_div(decimal_to_uint192(value), get_ten_pow(power), &fractional);
  SET_POWER(fractional.Lbits[3], power);
  *result = uint192_to_decimal(integer);
  if (sign && s21_is_greater(uint192_to_decimal(fractional), DCML_ZERO)) {
    add_positive(*result, DCML_ONE, result);
  }

  SET_SIGN(result->bits[DEC_SIZE - 1], sign);

  return ROUND_OK;
}
