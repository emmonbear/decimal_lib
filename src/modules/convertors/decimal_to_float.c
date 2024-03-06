/**
 * @file decimal_to_float.c
 * @author kossadda (https://github.com/kossadda)
 * @brief Decimal_to_float module
 * @version 1.0
 * @date 2024-03-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <math.h>

#include "./../include/convertors.h"

/**
 * @brief Converting a decimal_t number to a float number.
 *
 * @param[in] src source
 * @param[out] dst destination
 * @return int - CONVERSION_ERROR code.
 * @retval CONVERSION_OK = 0 - successful conversion. A valid number that fits
 * into a decimal.
 * @retval CONVERSION_ERROR = 1 - conversion CONVERSION_ERROR. Invalid number or
 * does not fit into decimal.
 */
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  if (!dst || !is_correct(src)) {
    return CONVERSION_ERROR;
  }

  long double tmp = 0;
  for (int i = SERVICE - 1; i >= 0; i--) {
    tmp += powl(2.0, i * UINT_BITS) * src.bits[i];
  }
  *dst = ((GET_SIGN(src.bits[SERVICE])) ? -1 : 1) * tmp /
         powl(10.0, GET_POWER(src.bits[SERVICE]));

  return CONVERSION_OK;
}
