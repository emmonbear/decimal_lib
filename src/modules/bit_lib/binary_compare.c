/**
 * @file binary_compare.c
 * @author emmonbea (https://github.com/emmonbear)
 * @brief
 * @version 0.1
 * @date 2024-02-25
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/bit_lib.h"

/**
 * @brief 
 * 
 * @param value_1 
 * @param value_2 
 * @retval LESS = -1 - value_1 < value_2
 * @retval EQUAL = 0 - value_1 = value_2
 * @retval GREAT = 1 - value_1 > value_2
 * 
 */
int binary_compare(uint192_t value_1, uint192_t value_2) {
  int res = EQUAL;

  for (int i = MAX_BITS - 1; i >= 0; i--) {
    bool bit_1 = IS_SET_BIT(value_1, i);
    bool bit_2 = IS_SET_BIT(value_2, i);

    if ((!bit_1) && (bit_2)) {
      res = LESS;
      break;
    } else if ((bit_1) && (!bit_2)) {
      res = GREATER;
      break;
    }
  }

  return res;
}