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
  if (!result) {
    return ROUND_ERROR;
  }

  bool sign = GET_SIGN(value.bits[DEC_SIZE - 1]);
  uint8_t power = GET_POWER(value.bits[DEC_SIZE - 1]);
  value.bits[DEC_SIZE - 1] = 0;

  uint192_t fractional = LDCML_ZERO;
  uint192_t integer =
      binary_div(decimal_to_uint192(value), get_ten_pow(power), &fractional);
  SET_POWER(fractional.Lbits[DEC_SIZE - 1], power);
  *result = uint192_to_decimal(bank_rouding(integer, fractional, NULL));
  SET_SIGN(result->bits[DEC_SIZE - 1], sign);

  return ROUND_OK;
}
