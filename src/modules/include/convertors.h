/**
 * @file convertors.h
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-02-27
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef CONVERTERS_H_
#define CONVERTERS_H_

#include "./common.h"

typedef enum {
  OK,
  ERROR,
} converter_code;

int s21_from_float_to_decimal(float src, decimal_t *dst);

#endif  // CONVERTERS_H_
