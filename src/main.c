#include <stdio.h>
#include <limits.h>
#include "./s21_decimal.h"
#include "stdbool.h"
#include "./tests/debug/debug_test.h"

#define MINUS 0x80000000
#define E 0x10000

int main()
{
// char *example =
//       "1442836296606862626875055847 + -1.9952280371801951234980360 = "
//       "1442836296606862626875055845.0";
  s21_decimal value_1 = {{1}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal result = {{0x76791EE5, 0x5DB90EC1, 0x4A97C78, 0x0}};
  // int code = 0;
  // int count = 9995;

  s21_decimal res = DCML_ZERO;
  s21_add(value_1, value_2, &res);

  s21_print_binary_decimal(result);
  s21_print_binary_decimal(res);
  both_decimal_bits(result, res);
  return 0;
}
