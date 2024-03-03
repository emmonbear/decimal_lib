#include <stdio.h>
#include <limits.h>
#include "./s21_decimal.h"
#include "stdbool.h"
#include "./tests/debug/debug_test.h"

#define MINUS 0x80000000
#define E 0x10000

int main()
{
  // char *example = "truncate(-783.60048511462222060164039) = -783";
  // s21_decimal value = {{0xDFAD93C7, 0xBDDA2485, 0x40D162, 0x80170000}};
  // s21_decimal result = {{0x30F, 0x0, 0x0, 0x80000000}};

  // s21_decimal res = DCML_ZERO;
  // s21_truncate(value, &res);

  // printf("\ntruncate(");
  // printd(value, ") = ");
  // printd(res, "\n\n");

  // both_decimal_bits(res, result);

  int v1 = 125;

  // s21_decimal value = {{0x30D56CC1, 0x2E84, 0x0, 0x80010000}};
  int res = (v1 >> 1) + (v1 >> 2);
  // s21_from_decimal_to_int(value, &res);
  printf("\n\nresult = %d\n\n", res);
  return 0;
}
