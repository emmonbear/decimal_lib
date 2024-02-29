#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[93m"
#define OKCYAN "\033[96m"
#define RESET "\033[0m"

#include "./debug.h"

/**
 * @brief Вывести s21_decimal в двоичной системе счисления
 * @param value s21_decimal
 */
void s21_print_binary_decimal(s21_decimal value) {
  s21_print_bit(value.bits[3], 1);
  s21_print_bit(value.bits[2], 0);
  s21_print_bit(value.bits[1], 0);
  s21_print_bit(value.bits[0], 0);
  putchar('\n');
}

void s21_print_binary_uint192(uint192_t value) {
  for (int i = LDEC_SIZE - 1; i >= 0; i--) {
    s21_print_bit(value.Lbits[i], 0);
    if (i % 3 == 0) {
      putchar('\n');
    }
  }
  putchar('\n');
}

/**
 * @brief Вывести s21_big_decimal для калькулятора
 * @param value
 */
void s21_print_int128_for_calc(s21_decimal value) {
  printf("%u*2^96+%u*2^64+%u*2^32+%u*2^0\n", value.bits[3], value.bits[2],
         value.bits[1], value.bits[0]);
}

void s21_print_bit(int number, int color) {
  s21_print_bits(sizeof(number), &number, color);
}

void s21_print_bits(size_t const size, void const *const ptr, int color) {
  unsigned char *p = (unsigned char *)ptr;
  unsigned char byte;
  int count = 31;
  for (int i = size - 1; i >= 0; i--) {
    for (int j = 7; j >= 0; j--) {
      if (color == 1) {
        if (count == 31) printf("%s", GREEN);
        if ((count == 30) || (count == 15)) printf("%s", YELLOW);
      }
      byte = (p[i] >> j) & 1;
      if (byte == 1) {
        if ((color == 1) && (count == 31))
          printf("%u", byte);
        else
          printf("%s%u%s", RED, byte, RESET);
      } else {
        printf("%u", byte);
      }
      if (color == 1) {
        if ((count == 0) || (count == 24) || (count = 31)) printf("%s", RESET);
      }
      count--;
    }
    putchar(' ');
  }
  putchar('|');
  putchar(' ');
}