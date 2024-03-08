/**
 * @file filld.c
 * @author kossadda (https://github.com/kossadda)
 * @brief Main module for filld function
 * @version 1.0
 * @date 2024-03-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./../include/debug.h"

/**
 * @brief Fill the decimal with the number specified at the input
 *
 * @param[out] input required number as a string
 * @return s21_decimal - string number as decimal
 */
s21_decimal filld(char *input) {
  s21_decimal num = {{0x0}};
  char *mantiss;

  int sign = 0;
  int scale = 0;

  if (input[0] == '-') {
    sign = 1;
    input++;
  }

  int len = strlen(input);
  char full[len + 1];
  sprintf(full, "%s", input);
  char *dot = strchr(full, '.');
  if (dot) {
    scale = strlen(dot) - 1;
    dot[0] = '\0';
  }
  char *bit_ptr = decimal_bits((SERVICE)*UINT_BITS - 1);
  mantiss = divide(full, bit_ptr);
  free(bit_ptr);
  if (strlen(mantiss) > 1 || mantiss[0] - '0' != 0) {
    fprintf(stderr, "\nfilld: Number %s exceeds of decimal size.\n", input);
    free(mantiss);
    exit(1);
  }
  if (dot) {
    int shift = len - strlen(full) - 1;
    for (int i = 0; i < shift; i++) {
      char remind = dot[i + 1];
      dot[i + 1] = dot[i];
      dot[i] = remind;
    }
  }

  free(mantiss);
  bit_ptr = decimal_bits((SERVICE * UINT_BITS) - 1);
  mantiss = divide(full, bit_ptr);
  free(bit_ptr);
  while (strlen(mantiss) > 1 || mantiss[0] - '0' != 0) {
    free(mantiss);
    full[strlen(full) - 1] = '\0';
    bit_ptr = decimal_bits((SERVICE)*UINT_BITS);
    mantiss = divide(full, bit_ptr);
    free(bit_ptr);
    scale--;
  }

  for (int i = DEC_SIZE - 2; i >= 0; i--) {
    free(mantiss);
    if (i == 0) {
      num.bits[i] = atoi(full);
    } else {
      bit_ptr = decimal_bits(i * 32);
      mantiss = divide(full, bit_ptr);
      free(bit_ptr);
      num.bits[i] = atoi(mantiss);
      bit_ptr = decimal_bits(i * 32);
      char *temp = multiply(mantiss, bit_ptr);
      char *temp2 = subtract(full, temp);
      sprintf(full, "%s", temp2);
      free(bit_ptr);
      free(temp);
      free(temp2);
    }
  }

  num.bits[SERVICE] = (scale << 16) | (sign << (UINT_BITS - 1));

  return num;
}