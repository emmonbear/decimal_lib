/**
 * @file int_to_decimal.c
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-03-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./../include/convertors.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  if (!dst) {
    return CONVERSION_ERROR;
  }

  *dst = (s21_decimal){{abs(src), 0, 0, (src > 0) ? 0 : 1 << 31}};

  return CONVERSION_OK;
}