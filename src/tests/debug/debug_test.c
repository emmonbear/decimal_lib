/**
 * @file debug.c
 * @author kossadda (https://github.com/kossadda)
 * @brief Module for debug decimal modules
 * @version 1.0
 * @date 2024-02-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./debug_test.h"

#include <stdint.h>

void calculator_write(s21_decimal value) {
  printf("   %d * (%u * 2^64 + %u * 2^32 + %u) / 10^%d\n",
         ((value.bits[3] >> 31) ? -1 : 1), value.bits[2], value.bits[1],
         value.bits[0], (value.bits[3] << 1) >> 17);
}

void print_decimal_bits(s21_decimal value) {
#ifdef CALCULATOR
  calculator_write(value);
#endif
  int8_t bit_1 = 0;

  for (int8_t i = 3; i >= 0; i--) {
    printf(RESET " | ");

    if (i == 3) {
      printf(ORANGE);
    }

    for (int8_t j = 31; j >= 0; j--) {
      bit_1 = (value.bits[i] >> j) & 1;

      if (bit_1) {
        printf(RED);
      }

      printf("%d", bit_1);

      if (i == 3) {
        if (j == 31 || j == 24 || j == 16) {
          printf(" ");
        }
        printf(ORANGE);
      } else {
        printf(RESET);
      }
    }
  }
  printf(RESET " |\n");
}

void both_decimal_bits(s21_decimal value_1, s21_decimal value_2) {
  printf("implement:");
  print_decimal_bits(value_1);
  printf("calculate:");
  print_decimal_bits(value_2);
}

void both_float_values(float value_1, float value_2) {
  printf("implement: %f\n", value_1);
  printf("calculate: %f\n", value_2);
}

void print_line() {
  printf(ORANGE
         "\n-------------------------------------------------------------------"
         "---------------------------------------------------------------------"
         "-------------------\n" YELLOW);
}
