/**
 * @file char_arithmetic.c
 * @author kossadda (https://github.com/kossadda)
 * @brief Includes string arithmetic functionality
 * @version 1.0
 * @date 2024-03-03
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./../include/debug.h"

static void strrev(char* str);
static int compare_strings(const char* num1, const char* num2);

/**
 * @brief Addition by char
 *
 * @param[in] num_1 str with first number
 * @param[in] num_2 str with second number
 * @return char* - result of operation
 */
char* add(char* num_1, char* num_2) {
  int remind = 0;
  int len_1 = strlen(num_1);
  int len_2 = strlen(num_2);
  int max_len = (len_1 > len_2) ? len_1 : len_2;
  char* result = (char*)calloc((max_len + 2), sizeof(char));
  char temp[max_len + 2];
  temp[max_len + 1] = 0;

  for (int i = 0; i < max_len; i++) {
    int digit_1 = (i < len_1) ? (num_1[len_1 - 1 - i] - '0') : 0;
    int digit_2 = (i < len_2) ? (num_2[len_2 - 1 - i] - '0') : 0;

    int sum = digit_1 + digit_2 + remind;
    temp[max_len - i] = (sum % 10) + '0';
    remind = sum / 10;
  }

  if (remind) {
    temp[0] = remind + '0';
  } else {
    char remind_char;
    for (int i = 0; i < max_len + 2; i++) {
      remind_char = temp[i + 1];
      temp[i] = temp[i + 1];
      temp[i + 1] = remind_char;
    }
  }

  sprintf(result, "%s", temp);

  return result;
}

/**
 * @brief Subrtract by char
 *
 * @param[in] num_1 str with first number
 * @param[in] num_2 str with second number
 * @return char* - result of operation
 */
char* subtract(char* num_1, char* num_2) {
  int borrow = 0;
  int len_1 = strlen(num_1);
  int len_2 = strlen(num_2);
  int max_len = (len_1 > len_2) ? len_1 : len_2;
  char* result = (char*)calloc((max_len + 1), sizeof(char));
  result[max_len] = '\0';

  for (int i = 0; i < max_len; i++) {
    int digit_1 = (i < len_1) ? (num_1[len_1 - 1 - i] - '0') : 0;
    int digit_2 = (i < len_2) ? (num_2[len_2 - 1 - i] - '0') : 0;

    if (borrow) {
      if (digit_1 == 0) {
        digit_1 = 9;
      } else {
        digit_1 -= 1;
        borrow = 0;
      }
    }

    if (digit_1 < digit_2) {
      digit_1 += 10;
      borrow = 1;
    }

    int diff = digit_1 - digit_2;
    result[max_len - 1 - i] = diff + '0';
  }

  int start = 0;

  while (result[start] == '0' && start < max_len - 1) {
    start++;
  }

  if (start > 0) {
    char* trimmed_result = (char*)calloc((max_len - start + 1), sizeof(char));
    strcpy(trimmed_result, &result[start]);
    free(result);
    return trimmed_result;
  }

  return result;
}

/**
 * @brief Divide by char
 *
 * @param[in] num_1 str with first number
 * @param[in] num_2 str with second number
 * @return char* - result of operation
 */
char* divide(char* num1, char* num2) {
  int len1 = strlen(num1), len2 = strlen(num2);

  if (compare_strings(num1, num2) < 0) {
    char* result = (char*)malloc(2);
    strcpy(result, "0");
    return result;
  } else if (compare_strings(num1, num2) == 0) {
    char* result = (char*)malloc(2);
    strcpy(result, "1");
    return result;
  }

  char* result = calloc(len1 + 1, sizeof(char));
  char* div_part = calloc(len2 + 2, sizeof(char));
  int resultPos = 0;

  strncpy(div_part, num1, len2 - 1);

  for (int i = len2 - 1; i < len1; i++) {
    int div_part_len = strlen(div_part);
    div_part[div_part_len] = num1[i];
    div_part[div_part_len + 1] = '\0';

    int count = 0;
    while (compare_strings(div_part, num2) >= 0) {
      char* temp = subtract(div_part, num2);
      strcpy(div_part, temp);
      free(temp);
      count++;
    }

    result[resultPos++] = count + '0';

    char* temp = div_part;
    while (*temp == '0') temp++;
    if (strlen(temp) == 0) {
      strcpy(div_part, "0");
    } else {
      if (temp != div_part) {
        strcpy(div_part, temp);
      }
    }
  }

  char* tempResult = result;
  while (*tempResult == '0') tempResult++;
  char* finalResult = strdup(tempResult);

  free(div_part);
  free(result);

  return finalResult;
}

/**
 * @brief Multiply by char
 *
 * @param[in] num_1 str with first number
 * @param[in] num_2 str with second number
 * @return char* - result of operation
 */
char* multiply(char* num1, char* num2) {
  int len1 = strlen(num1), len2 = strlen(num2);
  char* result = calloc(len1 + len2 + 1, sizeof(char));
  if (!result) {
    return NULL;
  }

  for (int i = 0; i < len1 + len2; i++) result[i] = '0';

  strrev(num1);
  strrev(num2);

  for (int i = 0; i < len1; i++) {
    for (int j = 0; j < len2; j++) {
      int mul = (num1[i] - '0') * (num2[j] - '0') + (result[i + j] - '0');
      result[i + j] = (mul % 10) + '0';
      result[i + j + 1] += (mul / 10);
    }
  }

  strrev(result);

  int i = 0;
  while (result[i] == '0' && i < len1 + len2 - 1) i++;
  char* finalResult = strdup(result + i);
  free(result);

  return finalResult;
}

/**
 * @brief For expand string
 *
 * @param[out] str expandable string
 */
static void strrev(char* str) {
  int len = strlen(str);

  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = temp;
  }
}

/**
 * @brief Compare string sizes
 *
 * @param[in] num_1 str with first number
 * @param[in] num_2 str with second number
 * @retval first - difference between string lengths
 * @retval second - the length of the string if they are equal
 */
static int compare_strings(const char* num1, const char* num2) {
  int len1 = strlen(num1), len2 = strlen(num2);
  return (len1 != len2) ? len1 - len2 : strcmp(num1, num2);
}
