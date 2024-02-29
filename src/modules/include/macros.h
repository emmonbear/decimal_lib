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

/// @brief Buffer decimal equal to 0.
#define DCML_ZERO \
  (decimal_t) {   \
    { 0 }         \
  }

/// @brief Buffer long decimal equal to 0.
#define LDCML_ZERO \
  (uint192_t) {    \
    { 0 }          \
  }

/// @brief Buffer long decimal equal to 0.5.
#define POINT_FIVE             \
  (uint192_t) {                \
    { 0x5, 0x0, 0x0, 0x10000 } \
  }

/// @brief Buffer long decimal equal to 1.
#define ONE     \
  (uint192_t) { \
    { 1 }       \
  }

/// @brief Buffer long decimal equal to 10.
#define TEN     \
  (uint192_t) { \
    { 10 }      \
  }

/// @brief Buffer long decimal equal to decimal max number (2^96 - 1).
#define DCML_MAX                           \
  (uint192_t) {                            \
    { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF } \
  }

/**
 * @brief Determines whether the bit is set in uint.
 *
 * @param uint number whose bit needs to be determined.
 * @param index number of the desired bit.
 * @retval 1 - bit is set.
 * @retval 0 - bit is not set.
 */
#define GET_BIT(uint, index) (((uint) >> (index)) & 1)

/**
 * @brief Determines whether the bit is set in decimal.
 *
 * @param Ldec long decimal whose bit needs to be determined.
 * @param index number of the desired bit.
 * @retval 1 - bit is set.
 * @retval 0 - bit is not set.
 */
#define IS_SET_BIT(Ldec, index) \
  GET_BIT(Ldec.Lbits[(index) / UINT_BITS], (index) % UINT_BITS)
/// @todo *** stack smashing detected ***: terminated при index >= MAX_BITS

/**
 * @brief Returns the largest of two numbers.
 *
 * @param int_1 first number.
 * @param int_2 second number.
 * @return int - max value.
 */
#define GET_MAX(int_1, int_2) ((int_1) > (int_2)) ? (int_1) : (int_2)

/**
 * @brief Sets a bit in decimal.
 *
 * @param Ldec long decimal bit which needs to be set.
 * @param index bit number to be set.
 */
#define SET_BIT(Ldec, index) \
  (Ldec.Lbits[(index) / UINT_BITS] |= 1 << ((index) % UINT_BITS))

/**
 * @brief Determines decimal number for an even number.
 *
 * @param Ldec defined decimal.
 */
#define IS_EVEN(Ldec) (!(Ldec.Lbits[0] & 1))

/**
 * @brief Determines the power specified in the exponent of a decimal number.
 *
 * @param uint service mantissa of decimal number.
 * @return uint - decimal power.
 */
#define GET_POWER(uint) (((uint) << 1) >> 17)

/**
 * @brief Determines the sign of a decimal number.
 *
 * @param uint service mantissa of decimal number.
 * @return uint - decimal sign.
 * @retval POSITIVE = 0 - decimal is positive.
 * @retval NEGATIVE = 1 - decimal is negative.
 */
#define GET_SIGN(uint) ((uint) >> 31)

/**
 * @brief Sets the power to the exponent of a decimal number.
 *
 * @param uint service mantissa of decimal number.
 * @param power setting power.
 */
#define SET_POWER(uint, power) uint |= (power) << 16

/**
 * @brief Sets the sign of a decimal number.
 *
 * @param uint service mantissa of decimal number.
 * @param sign setting sign. POSITIVE = 0, NEGATIVE = 1.
 */
#define SET_SIGN(uint, sign) uint |= (sign) << 31

#endif  // MACROS_H