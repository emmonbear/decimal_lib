/**
 * @file negate.c
 * @author kossadda (https://github.com/kossadda)
 * @brief Main module for s21_negate function
 * @version 1.0
 * @date 2024-03-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./../include/rounders.h"

/**
 * @brief Returns the result of multiplying the specified Decimal value by
 * negative one
 *
 * @param[in] value decimal to be rounded
 * @param[out] result rounded decimal
 * @return int - ROUND_ERROR code
 * @retval ROUND_OK = 0 - successful negate. A valid number that fits
 * into a decimal.
 * @retval ROUND_ERROR = 1 - invalid number or does not fit into decimal.
 */
int s21_negate(s21_decimal value, s21_decimal *result) {
  if (!result || !is_correct(value)) {
    return ROUND_ERROR;
  }

  *result = value;
  SET_SIGN(result->bits[SERVICE], !(GET_SIGN(value.bits[SERVICE])));

  return ROUND_OK;
}
