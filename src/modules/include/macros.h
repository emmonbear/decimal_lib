#ifndef MACROS_H
#define MACROS_H

/// @brief Fill uin196_t with zeros {{0, 0, 0, 0, 0, 0}}
#define SET_ZERO \
  {              \
    { 0 }        \
  }

#define SET_ONE \
  {             \
    { 1 }       \
  }

#define GET_BIT(number, index) ((number) & (1 << (index)))

#define IS_SET_BIT(value, index) \
  GET_BIT(value.Lbits[(index) / UINT_BITS], (index) % UINT_BITS)

#endif  // MACROS_H