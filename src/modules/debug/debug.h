#ifndef DEBUG_H
#define DEBUG_H

#include <stddef.h>

#include "../include/common.h"

void s21_print_binary_decimal(s21_decimal value);
void s21_print_bit(int number, int color);
void s21_print_bits(size_t const size, void const *const ptr, int color);
void s21_print_int128_for_calc(s21_decimal value);
void s21_print_binary_uint192(uint192_t value);
void printd(s21_decimal value, char *new_line);
void printLd(uint192_t value, char *new_line);

#endif  // DEBUG_H