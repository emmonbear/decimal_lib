/**
 * @file is_less.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief Is_less module
 * @version 0.1
 * @date 2024-02-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/comparison.h"

/**
 * @brief Check that value_1 < value_2
 *
 * @param[in] value_1
 * @param[in] value_2
 * @retval COMPARISON_TRUE - value_1 < value_2
 * @retval COMPARISON_FALSE - !(value_1 < value_2)
 */
int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  if (!is_correct(value_1) || !is_correct(value_2) ||
      (dcml_is_zero(value_1) && dcml_is_zero(value_2))) {
    return COMPARISON_FALSE;
  }

  int err_code = COMPARISON_FALSE;
  int sign_1 = GET_SIGN(value_1.bits[SERVICE]);
  int sign_2 = GET_SIGN(value_2.bits[SERVICE]);

  if (sign_1 == NEGATIVE) {
    err_code = (sign_2 == POSITIVE)
                   ? COMPARISON_TRUE
                   : is_less_positive(dabs(value_2), dabs(value_1));
  } else {
    err_code = (sign_2 == POSITIVE) ? is_less_positive(value_1, value_2)
                                    : COMPARISON_FALSE;
  }

  return err_code;
}

/**
 * @brief Check that value_1 < value_2
 *
 * @param[in] value_1 positive number
 * @param[in] value_2 positive number
 * @retval COMPARISON_TRUE - value_1 < value_2
 * @retval COMPARISON_FALSE - !(value_1 < value_2)
 */
bool is_less_positive(s21_decimal value_1, s21_decimal value_2) {
  uint192_t Lvalue_1 = decimal_to_uint192(value_1);
  uint192_t Lvalue_2 = decimal_to_uint192(value_2);

  binary_normalizaton(&Lvalue_1, &Lvalue_2);

  int compare = binary_compare(Lvalue_1, Lvalue_2);

  return (compare == LESS) ? COMPARISON_TRUE : COMPARISON_FALSE;
}
