/**
 * @file sub.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief
 * @version 0.1
 * @date 2024-02-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/arithmetic.h"

// int s21_sub(decimal_t value_1, decimal_t value_2, decimal_t *result) {

//   int err_code = OK;

//   uint8_t sign_1 = GET_SIGN(value_1.bits[DEC_SIZE - 1]);
//   uint8_t sign_2 = GET_SIGN(value_2.bits[DEC_SIZE - 1]);

//   decimal_t res_tmp = DCML_ZERO;
//   if((sign_1 == POSITIVE) && (sign_2 == POSITIVE)) {
//     if (s21_is_greater_or_equal(value_1, value_2)) {
//       err_code = sub_positive(value_1, value_2, result);
//     } else {
//       err_code = sub_positive(value_2, value_1, result);
//       dcml_set_sign(result);
//     }
//   } else if ((sign_1 == POSITIVE) && (sign_2 == NEGATIVE)) {
//     err_code = s21_add(value_1, dcml_abs(value_2), &res_tmp);
//   } else if ((sign_1 == NEGATIVE) && (sign_2 == POSITIVE)) {
//     err_code = s21_add(dcml_abs(value_1), value_2, &res_tmp);
//     dcml_set_sign(&res_tmp);
//   } else if ((sign_1 == NEGATIVE) && (sign_2 == NEGATIVE)) {
//     if (s21_is_greater_or_equal(value_1, value_2)) {
//       err_code = sub_positive(dcml_abs(value_2), dcml_abs(value_1),
//       &res_tmp);
//     } else {
//       err_code = sub_positive(dcml_abs(value_1), dcml_abs(value_2),
//       &res_tmp); dcml_set_sign(&res_tmp);
//     }
//   }

//   return err_code;
// }

int sub_positive(decimal_t value_1, decimal_t value_2, decimal_t *res) {
  int err_code = OK;

  int8_t power_1 = GET_POWER(value_1.bits[3]);
  int8_t power_2 = GET_POWER(value_2.bits[3]);

  uint192_t Lvalue_1 = decimal_to_uint192(value_1);
  uint192_t Lvalue_2 = decimal_to_uint192(value_2);

  binary_normalizaton(&Lvalue_1, &Lvalue_2);
  uint192_t res_tmp = binary_sub(Lvalue_1, Lvalue_2);
  uint8_t power_tmp = get_divider(res_tmp);

  int8_t res_power = GET_MAX(power_1, power_2) - power_tmp;

  if (res_power < 0) {
    err_code = BIG;
  }

  uint192_t remainder = LDCML_ZERO;
  res_tmp = binary_div(res_tmp, get_ten_pow(power_tmp), &remainder);
  SET_POWER(remainder.Lbits[DEC_SIZE - 1], power_tmp);
  res_tmp = bank_rouding(res_tmp, remainder);
  SET_POWER(res_tmp.Lbits[DEC_SIZE - 1], res_power);
  *res = uint192_to_decimal(res_tmp);

  return err_code;
}