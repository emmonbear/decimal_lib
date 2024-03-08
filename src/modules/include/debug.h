/**
 * @file debug.h
 * @author kossadda (https://github.com/kossadda)
 * @brief Main header of debug modules
 * @version 1.0
 * @date 2024-03-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef DEBUG_H
#define DEBUG_H

#define _POSIX_C_SOURCE 200809L
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "./common.h"

/// @brief To obtain the decimal bit of a number
#define GET_DEC_BIT(value, index) \
  GET_BIT(value.bits[(index) / UINT_BITS], (index) % UINT_BITS)

char *add(char *num_1, char *num_2);
char *subtract(char *num_1, char *num_2);
char *multiply(char *num1, char *num2);
char *divide(char *num1, char *num2);

char *decimal_bits(int index);

void printd(s21_decimal value, char *new_line);
s21_decimal filld(char *input);

#endif  // DEBUG_H