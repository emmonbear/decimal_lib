/**
 * @file is_equal.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief Is_equal module
 * @version 0.1
 * @date 2024-02-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/comparison.h"

/**
 * @brief Check that value_1 = value_2
 *
 * @param[in] value_1
 * @param[in] value_2
 * @retval COMPARISON_TRUE - numbers is equal
 * @retval COMPARISON_FALSE - numbers is not equal
 */
int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  if ((dcml_is_zero(value_1) && dcml_is_zero(value_2))) {
    return COMPARISON_TRUE;
  }
  
  int err_code = COMPARISON_TRUE;

  int8_t sign_1 = GET_SIGN(value_1.bits[DEC_SIZE - 1]);
  int8_t sign_2 = GET_SIGN(value_2.bits[DEC_SIZE - 1]);

  uint192_t Lvalue_1 = decimal_to_uint192(value_1);
  uint192_t Lvalue_2 = decimal_to_uint192(value_2);

  binary_normalizaton(&Lvalue_1, &Lvalue_2);

  SET_SIGN(Lvalue_1.Lbits[DEC_SIZE - 1], sign_1);
  SET_SIGN(Lvalue_2.Lbits[DEC_SIZE - 1], sign_2);

  for (uint8_t i = 0; i < (LDEC_SIZE - 1); i++) {
    if (Lvalue_1.Lbits[i] != Lvalue_2.Lbits[i]) {
      err_code = COMPARISON_FALSE;
      break;
    }
  }

  return err_code;
}
