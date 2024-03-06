/**
 * @file round.c
 * @author kossadda (https://github.com/kossadda)
 * @brief Main module for s21_round function
 * @version 1.0
 * @date 2024-03-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./../include/rounders.h"

/**
 * @brief Round decimal_t to the nearest integer.
 *
 * @param[in] value decimal_t to be rounded
 * @param[out] result rounded decimal_t
 * @return int - ROUND_ERROR code
 * @retval ROUND_OK = 0 - successful rounding. A valid number that fits
 * into a decimal.
 * @retval ROUND_ERROR = 1 - invalid number or does not fit into decimal.
 */
int s21_round(s21_decimal value, s21_decimal *result) {
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
  *result = uint192_to_decimal(bank_rouding(integer, fractional, NULL));
  SET_SIGN(result->bits[SERVICE], sign);

  return ROUND_OK;
}
