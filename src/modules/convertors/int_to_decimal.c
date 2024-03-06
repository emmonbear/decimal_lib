/**
 * @file int_to_decimal.c
 * @author kossadda (https://github.com/kossadda)
 * @brief Main module for s21_from_int_to_decimal function
 * @version 1.0
 * @date 2024-03-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./../include/convertors.h"

/**
 * @brief Converting a int number to a decimal_t number.
 *
 * @param[in] src source
 * @param[out] dst destination
 * @return int - CONVERSION_ERROR code.
 * @retval CONVERSION_OK = 0 - successful conversion. A valid number that fits
 * into a decimal.
 * @retval CONVERSION_ERROR = 1 - conversion CONVERSION_ERROR. Invalid number or
 * does not fit into decimal.
 */
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  if (!dst) {
    return CONVERSION_ERROR;
  }

  *dst = DCML_ZERO;

  dst->bits[0] = abs(src);
  SET_SIGN(dst->bits[SERVICE], (src > 0) ? POSITIVE : NEGATIVE);

  return CONVERSION_OK;
}
