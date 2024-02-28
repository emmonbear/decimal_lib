/**
 * @file add.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief
 * @version 0.1
 * @date 2024-02-26
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/arithmetic.h"

int s21_add_positive(decimal_t value_1, decimal_t value_2, decimal_t *res) {
  int err_code = OK;

  int8_t power_1 = GET_POWER(value_1.bits[3]);
  int8_t power_2 = GET_POWER(value_2.bits[3]);

  uint192_t Lvalue_1 = decimal_to_uint192(value_1);
  uint192_t Lvalue_2 = decimal_to_uint192(value_2);

  binary_normalizaton(&Lvalue_1, &Lvalue_2);
  uint192_t res_tmp = binary_add(Lvalue_1, Lvalue_2);
  uint8_t power_tmp = get_divider(res_tmp);

  int8_t res_power = GET_MAX(power_1, power_2) - power_tmp;

  if (res_power < 0) {
    err_code = BIG;
  }

  uint192_t remainder = DCML_ZERO;
  res_tmp = binary_div(res_tmp, get_ten_pow(power_tmp), &remainder);
  SET_POWER(remainder, power_tmp);
  res_tmp = bank_rouding(res_tmp, remainder);
  SET_POWER(res_tmp, res_power);
  *res = uint192_to_decimal(res_tmp);

  return err_code;
}
