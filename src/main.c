#include <stdio.h>
#include <limits.h>
#include "./s21_decimal.h"
#include "stdbool.h"
#include "./tests/debug/debug_test.h"

#define MINUS 0x80000000
#define E 0x10000

int main()
{
    // 0.4999999999999999999999999999
  s21_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x1C0000}};

  s21_decimal res = DCML_ZERO;
  int code = s21_mul(decimal1, decimal2, &res); 

  printd(decimal1, "\n");
  s21_print_binary_decimal(decimal1);

  printd(decimal2, "\n");
  s21_print_binary_decimal(decimal2);

  printd(decimal_check, "\n");
  s21_print_binary_decimal(decimal_check);

  printd(res, "\n");
  s21_print_binary_decimal(res);

  printf("\ncode = %d\n", code);

  return 0;
}
