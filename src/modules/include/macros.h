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
#define DCML_ZERO \
  {               \
    { 0 }         \
  }

#define SET_ONE \
  {             \
    { 1 }       \
  }

#define DCML_MAX                              \
  {                                           \
    { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0 } \
  }

#define DCML_POINT_FIVE        \
  {                            \
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

#define SET_SCALE(value, scale) value |= (scale) << 16
/// @todo На вход должна подаваться мантисса, исправить везде на дефайн выше.
#define SET_POWER(value, power) value.Lbits[DEC_SIZE - 1] |= (power) << 16

// #define DCML_SET_POWER(value, power) value,bits[DEC_SIZE - 1] |= (power) <<
// 16

#define SET_ZIGN(value, sign) value |= (sign) << 31
/// @todo Zдесь тоже самое.
#define SET_SIGN(value, sign) value.Lbits[DEC_SIZE - 1] |= (sign) << 31

#endif  // MACROS_H