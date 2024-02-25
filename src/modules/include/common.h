/**
 * @file common.h
 * @author emmonbea (https://github.com/emmonbear)
 * @brief Common header
 * @version 0.1
 * @date 2024-02-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include <stdio.h>

#include "./macros.h"
#include "stdbool.h"

/// @brief enumerations with array sizes
typedef enum {
  DEC_SIZE = 4,  ///< Size bits array used for the final result
  LDEC_SIZE =
      (DEC_SIZE - 1) *
      2,  ///< Size of decimal_t array used for intermediate calculations
} array_size;

/// @brief Decimal representation
typedef struct {
  unsigned int bits[DEC_SIZE];  ///< 128 bits
} decimal_t;

/// @brief
typedef struct {
  unsigned int Lbits[LDEC_SIZE];  ///< 192 bits
} uint192_t;

/// @brief Enumeration of decimal_t signs
typedef enum {
  SIGN_POSITIVE = 0,  ///< Positive sign
  SIGN_NEGATIVE = 1,  ///< Negative sign
} decimal_sign;

#endif  // COMMON_H
