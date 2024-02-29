/**
 * @file macros.h
 * @author emmonbea (https://github.com/emmonbear)
 * @brief
 * @version 0.1
 * @date 2024-02-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef MACROS_H
#define MACROS_H

/// @brief Fill uin196_t with zeros {{0, 0, 0, 0, 0, 0}}
#define LDCML_ZERO \
  (uint192_t) {    \
    { 0 }          \
  }

#define DCML_ZERO \
  (decimal_t) {   \
    { 0 }         \
  }

#define ONE     \
  (uint192_t) { \
    { 1 }       \
  }

#define TEN     \
  (uint192_t) { \
    { 10 }      \
  }

#define DCML_MAX                           \
  (uint192_t) {                            \
    { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF } \
  }

#define POINT_FIVE             \
  (uint192_t) {                \
    { 0x5, 0x0, 0x0, 0x10000 } \
  }

#define GET_BIT(number, index) ((number) & (1 << (index)))

#define GET_MAX(x, y) ((x) > (y)) ? (x) : (y)

/// @todo *** stack smashing detected ***: terminated при index >= MAX_BITS
#define IS_SET_BIT(value, index) \
  GET_BIT(value.Lbits[(index) / UINT_BITS], (index) % UINT_BITS)

#define IS_EVEN(value) (!(value.Lbits[0] & 1))

#define SET_BIT(value, index) \
  (value.Lbits[(index) / UINT_BITS] |= (1 << ((index) % UINT_BITS)))

#define GET_POWER(value) (((value) << 1) >> 17)

#define GET_SIGN(value) ((value) >> 31)

#define SET_POWER(value, scale) value |= (scale) << 16

#define SET_SIGN(value, sign) value |= (sign) << 31

#endif  // MACROS_H