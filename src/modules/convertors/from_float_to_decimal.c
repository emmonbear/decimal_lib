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

#include "./../include/convertors.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

static void get_clean_value(char *str);
static int get_char_exponent(char *str);

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

  if(exponent < -(DCML_PRECISION + 1)) {
    return ERROR;
  } else if (exponent <= -(DCML_PRECISION - FLT_PRECISION)) {
    int correct = (exponent >= -DCML_PRECISION) ? exponent + DCML_PRECISION : 0;
    sprintf(str, "%.*E", correct, fabsf(src));
    exponent = get_char_exponent(str) + FLT_PRECISION - correct;
  }

  get_clean_value(str);
  dst->bits[0] = atoi(str);

  if(!dst->bits[0]) {
    return ERROR;
  } else if (exponent <= 0) {
    SET_SCALE(dst->bits[DEC_SIZE - 1], (FLT_PRECISION + abs(exponent)));
  } else if (exponent > FLT_PRECISION) {
    uint192_t long_dst = DCML_ZERO;
    long_dst = binary_mul(long_dst, get_ten_pow(exponent - FLT_PRECISION));
    *dst = uint192_to_decimal(long_dst);
  } else {
    SET_SCALE(dst->bits[DEC_SIZE - 1], (FLT_PRECISION - abs(exponent)));
  }

  SET_ZIGN(dst->bits[DEC_SIZE - 1], ((src < 0) ? 1 : 0));

  return OK;
}

static void get_clean_value(char *str) {
  str[strlen(str) - EXP_LEN] = '\0';
  char *dot_position = strchr(str, '.');

  if (dot_position) {
    dot_position++;
    sprintf(str, "%c%s\n", str[0], dot_position);
  }
}

static int get_char_exponent(char *str) {
  char *ptr = strchr(str, 'E');
  ptr++;

  return strtol(ptr, NULL, 10);
}
