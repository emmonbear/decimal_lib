/**
 * @file float_to_decimal.c
 * @author kossadda (https://github.com/kossadda)
 * @brief Main module for s21_from_float_to_decimal function
 * @version 1.0
 * @date 2024-02-27
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <math.h>
#include <string.h>

#include "./../include/convertors.h"

static void get_clean_value(char *str);
static int get_char_exponent(char *str);

/**
 * @brief Converting a float number to a decimal_t number.
 *
 * @param[in] src convertible number.
 * @param[out] dst conversion result.
 * @return int - CONVERSION_ERROR code.
 * @retval CONVERSION_OK = 0 - successful conversion. A valid number that fits
 * into a decimal.
 * @retval CONVERSION_ERROR = 1 - conversion CONVERSION_ERROR. Invalid number or
 * does not fit into decimal.
 */
int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  if (!dst) {
    return CONVERSION_ERROR;
  }

  *dst = DCML_ZERO;

  if (IS_NAN(src) || IS_INF(src) || fabs(src) > DECIMAL_MAX) {
    return CONVERSION_ERROR;
  } else if (!src) {
    return CONVERSION_OK;
  }

  char str[MIN_NEED_SIZE];
  sprintf(str, "%.6E", fabsf(src));
  int exponent = get_char_exponent(str);

  if (exponent == -(MAX_SCALE + 1)) {
    if ((str[0] - '0') < 5) {
      return CONVERSION_ERROR;
    } else {
      dst->bits[0] = 1;
      SET_POWER(dst->bits[SERVICE], MAX_SCALE);
      return CONVERSION_OK;
    }
  } else if (exponent < -MAX_SCALE) {
    return CONVERSION_ERROR;
  } else if (exponent <= -(MAX_SCALE - FLT_PRECISION)) {
    int correct = (exponent >= -MAX_SCALE) ? exponent + MAX_SCALE : 0;
    sprintf(str, "%.*E", correct, fabsf(src));
    exponent = get_char_exponent(str) + FLT_PRECISION - correct;
  }

  get_clean_value(str);
  dst->bits[0] = atoi(str);

  if (exponent <= 0) {
    SET_POWER(dst->bits[SERVICE], (FLT_PRECISION + abs(exponent)));
  } else if (exponent > FLT_PRECISION) {
    uint192_t long_dst = decimal_to_uint192(*dst);
    long_dst = ten_mul(long_dst, exponent - FLT_PRECISION);
    *dst = uint192_to_decimal(long_dst);
  } else {
    SET_POWER(dst->bits[SERVICE], (FLT_PRECISION - abs(exponent)));
  }

  SET_SIGN(dst->bits[SERVICE], ((src < 0) ? NEGATIVE : POSITIVE));

  return CONVERSION_OK;
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
