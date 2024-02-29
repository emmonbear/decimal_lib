/**
 * @file from_float_to_decimal.c
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-02-27
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "./../include/convertors.h"

static void get_clean_value(char *str);
static int get_char_exponent(char *str);

/**
 * @brief Converting a float number to a decimal number.
 *
 * @param src convertible number.
 * @param dst conversion result.
 * @return int - error code.
 * @retval OK = 0 - successful conversion. A valid number that fits into a
 * decimal.
 * @retval ERROR = 1 - conversion error. Invalid number or does not fit into
 * decimal.
 */
int s21_from_float_to_decimal(float src, decimal_t *dst) {
  if (!dst) {
    return ERROR;
  } else {
    *dst = (decimal_t){0};
  }

  if (IS_NAN(src) || IS_INF(src) || fabs(src) > DECIMAL_MAX) {
    return ERROR;
  } else if (!src) {
    return OK;
  }

  char str[MIN_NEED_SIZE];
  sprintf(str, "%.6E", fabsf(src));
  int exponent = get_char_exponent(str);

  if (exponent < -(DCML_PRECISION + 1)) {
    return ERROR;
  } else if (exponent <= -(DCML_PRECISION - FLT_PRECISION)) {
    int correct = (exponent >= -DCML_PRECISION) ? exponent + DCML_PRECISION : 0;
    sprintf(str, "%.*E", correct, fabsf(src));
    exponent = get_char_exponent(str) + FLT_PRECISION - correct;
  }

  get_clean_value(str);
  dst->bits[0] = atoi(str);

  if (!dst->bits[0]) {
    return ERROR;
  } else if (exponent <= 0) {
    SET_POWER(dst->bits[DEC_SIZE - 1], (FLT_PRECISION + abs(exponent)));
  } else if (exponent > FLT_PRECISION) {
    uint192_t long_dst = LDCML_ZERO;
    long_dst = binary_mul(long_dst, get_ten_pow(exponent - FLT_PRECISION));
    *dst = uint192_to_decimal(long_dst);
  } else {
    SET_POWER(dst->bits[DEC_SIZE - 1], (FLT_PRECISION - abs(exponent)));
  }

  SET_SIGN(dst->bits[DEC_SIZE - 1], ((src < 0) ? 1 : 0));

  return OK;
}

/**
 * @brief Extracts all digits from a normalized number.
 *
 * @param str string with a normalized number.
 */
static void get_clean_value(char *str) {
  str[strlen(str) - EXP_LEN] = '\0';
  char *dot_position = strchr(str, '.');

  if (dot_position) {
    dot_position++;
    sprintf(str, "%c%s\n", str[0], dot_position);
  }
}

/**
 * @brief Extracts the power from a normalized number.
 *
 * @param str string with a normalized number.
 * @return int - normalized number power.
 */
static int get_char_exponent(char *str) {
  char *ptr = strchr(str, 'E');
  ptr++;

  return strtol(ptr, NULL, 10);
}
