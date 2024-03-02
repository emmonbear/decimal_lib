/**
 * @file from_decimal_to_int.c
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-03-02
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./../include/comparison.h"
#include "./../include/convertors.h"
#include "./../include/rounders.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  if (!dst) {
    return CONVERSION_ERROR;
  }

  *dst = (GET_SIGN(src.bits[3])) ? -1 : 1;
  if ((*dst > 0) ? s21_is_greater(src, DCML_INT_MAX)
                 : s21_is_less(src, DCML_INT_MIN)) {
    *dst = 0;
    return CONVERSION_ERROR;
  }

  s21_truncate(src, &src);
  *dst *= src.bits[0];

  return CONVERSION_OK;
}