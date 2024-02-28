/**
 * @file is_less.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief
 * @version 0.1
 * @date 2024-02-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/comparison.h"

int s21_is_less(decimal_t value_1, decimal_t value_2) {
  int err_code = COMPARISON_FALSE;
  int sign_1 = GET_SIGN(value_1.bits[DEC_SIZE - 1]);
  int sign_2 = GET_SIGN(value_2.bits[DEC_SIZE - 1]);

  if ((s21_is_equal(value_1, (decimal_t)DCML_ZERO)) &&
      (s21_is_equal(value_2, (decimal_t)DCML_ZERO))) {
    err_code = COMPARISON_FALSE;
  } else if ((sign_1 == NEGATIVE) && (sign_2 == POSITIVE)) {
    err_code = COMPARISON_FALSE;
  } else if ((sign_1 == POSITIVE) && (sign_2 == NEGATIVE)) {
    err_code = COMPARISON_FALSE;
  } else if ((sign_1 == NEGATIVE) && (sign_2 == NEGATIVE)) {
    err_code = is_less_positive(dcml_abs(value_2), dcml_abs(value_1));
  } else {
    err_code = is_less_positive(value_1, value_2);
  }

  return err_code;
}

int is_less_positive(decimal_t value_1, decimal_t value_2) {
  uint192_t Lvalue_1 = decimal_to_uint192(value_1);
  uint192_t Lvalue_2 = decimal_to_uint192(value_2);

  binary_normalizaton(&Lvalue_1, &Lvalue_2);

  int compare = binary_compare(Lvalue_1, Lvalue_2);

  return compare == LESS ? COMPARISON_TRUE : COMPARISON_FALSE;
}