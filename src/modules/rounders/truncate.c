/**
 * @file truncate.c
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-03-02
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./../include/rounders.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  if (!result) {
    return ROUND_ERROR;
  }

  *result = DCML_ZERO;

  if (!is_correct(value)) {
    return ROUND_ERROR;
  }

  bool sign = GET_SIGN(value.bits[3]);
  uint8_t power = GET_POWER(value.bits[3]);
  value.bits[3] = 0;

  *result = uint192_to_decimal(
      binary_div(decimal_to_uint192(value), get_ten_pow(power), NULL));
  SET_SIGN(result->bits[3], sign);

  return ROUND_OK;
}