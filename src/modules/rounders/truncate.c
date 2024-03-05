/**
 * @file truncate.c
 * @author kossadda (https://github.com/kossadda)
 * @brief Main module for s21_truncate function
 * @version 1.0
 * @date 2024-03-02
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./../include/rounders.h"

/**
 * @brief Return the integer digits of the specified decimal_t number; any
 * fractional digits are discarded, including finite zeros.
 *
 * @param[in] value decimal_t to be truncate
 * @param[out] result truncated decimal_t
 * @return int - ROUND_ERROR code
 * @retval ROUND_OK = 0 - successful rounding. A valid number that fits
 * into a decimal.
 * @retval ROUND_ERROR = 1 - invalid number or does not fit into decimal.
 */
int s21_truncate(s21_decimal value, s21_decimal *result) {
  if (!result) {
    return ROUND_ERROR;
  }

  *result = DCML_ZERO;

  if (!is_correct(value)) {
    return ROUND_ERROR;
  }

  bool sign = GET_SIGN(value.bits[DEC_SIZE - 1]);
  uint8_t power = GET_POWER(value.bits[DEC_SIZE - 1]);
  value.bits[DEC_SIZE - 1] = 0;

  *result = uint192_to_decimal(
      binary_div(decimal_to_uint192(value), get_ten_pow(power), NULL));
  SET_SIGN(result->bits[DEC_SIZE - 1], sign);

  return ROUND_OK;
}
