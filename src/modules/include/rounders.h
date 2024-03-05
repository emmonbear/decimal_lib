/**
 * @file rounders.h
 * @author kossadda (https://github.com/kossadda)
 * @brief Rounders header
 * @version 1.0
 * @date 2024-03-02
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef ROUNDERS_H_
#define ROUNDERS_H_

#include "./common.h"

/// @brief Enumeration of Rounders error codes
typedef enum {
  ROUND_OK,     ///< round error
  ROUND_ERROR,  ///< round ok
} rounder_code;

int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);

#endif  // ROUNDERS_H_