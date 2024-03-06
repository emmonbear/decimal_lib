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

int s21_negate(s21_decimal value, s21_decimal *result) {
  if (!result || !is_correct(value)) {
    return ROUND_ERROR;
  }

  *result = value;
  SET_SIGN(result->bits[DEC_SIZE - 1], !(GET_SIGN(value.bits[DEC_SIZE - 1])));

  return ROUND_OK;
}
