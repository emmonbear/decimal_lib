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

typedef enum {
  DCML_PRECISION = 28,
  FLT_PRECISION = 6,
} constants;

int s21_from_float_to_decimal(float src, decimal_t *dst) {
  *dst = (decimal_t){0};

  if (!dst || src != src || src == 1.0 / 0.0 ||
      fabs(src) > 79228162514264337593543950335.0) {
    return ERROR;
  }

  if (!src) {
    return OK;
  }

  char str[15];
  sprintf(str, "%.6E", fabsf(src));
  int exponent = get_char_exponent(str);

  if (exponent <= -23) {
    int correct_scale = exponent + DCML_PRECISION;
    sprintf(str, "%.*E", correct_scale, fabsf(src));
    exponent = get_char_exponent(str) + FLT_PRECISION - correct_scale;
  }

  get_clean_value(str);

  dst->bits[0] = atoi(str);

  if (exponent <= 0) {
    SET_SCALE(dst->bits[3], (FLT_PRECISION + abs(exponent)));
  } else if (exponent > FLT_PRECISION) {
    uint192_t long_dst = DCML_ZERO;
    long_dst = binary_mul(long_dst, get_ten_pow(exponent - FLT_PRECISION));
    *dst = uint192_to_decimal(long_dst);
  } else {
    SET_SCALE(dst->bits[3], (FLT_PRECISION - abs(exponent)));
  }

  SET_ZIGN(dst->bits[3], ((src < 0) ? 1 : 0));

  return OK;
}

static void get_clean_value(char *str) {
  str[strlen(str) - 4] = '\0';
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
