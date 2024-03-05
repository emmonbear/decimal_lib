/**
 * @file negate.c
 * @author kossadda (https://github.com/kossadda)
 * @brief 
 * @version 1.0
 * @date 2024-03-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "./../include/rounders.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  if (!result) {
    return ROUND_ERROR;
  }

  *result = value;
  SET_SIGN(result->bits[3], !(GET_SIGN(value.bits[3])));

  return ROUND_OK;
}
