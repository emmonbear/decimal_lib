#include <stdio.h>
#include <limits.h>
#include "./decimal.h"
#include "stdbool.h"


int main()
{
  uint192_t value_1 = SET_ZERO;

  // uint192_t value_2= {{2321}};

  s21_print_binary_uint192(value_1);
  // s21_print_binary_uint192(value_2);

  // uint192_t res = binary_mul(value_1, value_2);
  // s21_print_binary_uint192(res);

  return 0;
}