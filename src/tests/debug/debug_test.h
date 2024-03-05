/**
 * @file debug.h
 * @author kossadda (https://github.com/kossadda)
 * @brief Header for debug module
 * @version 1.0
 * @date 2024-02-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#define DEBUG
#define CALCULATOR
#define ERRORS

#include <stdio.h>

#include "./../../s21_decimal.h"

#define GREEN "\033[0;32m"
#define ORANGE "\033[1;33m"
#define BLUE "\033[36m"
#define RED "\033[0;31m"
#define YELLOW "\033[93m"
#define OKCYAN "\033[96m"
#define WHITE "\033[1;37m"
#define RESET "\033[0m"

void print_decimal_bits(s21_decimal value_1);
void both_decimal_bits(s21_decimal value_1, s21_decimal value_2);
void both_float_values(float value_1, float value_2);
void both_int_values(int value_1, int value_2);
void print_line();

#endif  // DEBUG_H_
