/**
 * @file rounders.h
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-03-02
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef ROUNDERS_H_
#define ROUNDERS_H_

#include "./common.h"

typedef enum {
  ROUND_OK,
  ROUND_ERROR,
} rounder_code;

int s21_truncate(s21_decimal value, s21_decimal *result);

#endif  // ROUNDERS_H_