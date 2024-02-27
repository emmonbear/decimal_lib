#include <stdio.h>
#include <limits.h>
#include "./decimal.h"
#include "stdbool.h"

#define MINUS 0x80000000
#define E 0x10000

int main()
{
  decimal_t value_1 = {{0x1, 0x0, 0x0, 0x0, 0x0, 0x0, (E * 60) | MINUS}};

  // uint192_t value_2= {{2321}};
  printd(value_1, "\n");
  // s21_print_binary_uint192(value_2);

  // uint192_t res = binary_mul(value_1, value_2);
  // s21_print_binary_uint192(res);

  return 0;
}
