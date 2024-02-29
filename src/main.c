#include <stdio.h>
#include <limits.h>
#include "./s21_decimal.h"
#include "stdbool.h"

#define MINUS 0x80000000
#define E 0x10000

int main()
{
  s21_decimal value_1 = {{0xFFFFFF, 0xABCD, 0xBBB, 0x0}};
  s21_decimal value_2 = {{0x14523, 0xAB43, 0x0, 0x0}};
  uint192_t result = binary_div(decimal_to_uint192(value_2), decimal_to_uint192(value_1), NULL);
  printd(value_1, " / ");
  printd(value_2, " = ");
  printLd(result, "\n\n");
  // s21_print_binary_uint192(value_2);

  // uint192_t res = binary_mul(value_1, value_2);
  // s21_print_binary_uint192(res);

  return 0;
}
