#ifndef DEBUG_H
#define DEBUG_H

#define _POSIX_C_SOURCE 200809L
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/common.h"

#define GET_DEC_BIT(value, index) \
  GET_BIT(value.bits[(index) / UINT_BITS], (index) % UINT_BITS)

char *add(char *num_1, char *num_2);
char *subtract(char *num_1, char *num_2);
char *multiply(char *num1, char *num2);
char *divide(char *num1, char *num2);

void s21_print_binary_decimal(s21_decimal value);
void s21_print_bit(int number, int color);
void s21_print_bits(size_t const size, void const *const ptr, int color);
void s21_print_int128_for_calc(s21_decimal value);
void s21_print_binary_uint192(uint192_t value);
void printd(s21_decimal value, char *new_line);
void printLd(uint192_t value, char *new_line);
s21_decimal dcml_fill(char *input);

#endif  // DEBUG_H