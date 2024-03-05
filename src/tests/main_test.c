/**
 * @file tests.c
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-02-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./main_test.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h> 

static void test_function(Suite *(**array)(void), size_t size, char *name,
                          int *passed_count, int *failed_count);
static void conclusion(int passed_count, int failed_count, double time);
static void function_declaration(char *function);
static int test_suite(Suite *test, int *passed_count);
static void greetings();
static void line();

/**
 * @brief Function to start testing modules.
 *
 * @return int - error code.
 * @retval EXIT_SUCCESS = 0 - if the tests pass successfully.
 * @retval EXIT_FAILURE = 1 - if the tests pass unsuccessful.
 */
int main(void) {
  
  int failed_count = 0;
  int passed_count = 0;

  greetings();
  struct timeval start, end;
  
  gettimeofday(&start, NULL);
#ifdef TEST_ADD
  Suite *(*s21_add_cases[])(void) = {
      s21_add_case_1,  s21_add_case_2,  s21_add_case_3,  s21_add_case_4,
      s21_add_case_5,  s21_add_case_6,  s21_add_case_7,  s21_add_case_8,
      s21_add_case_9,  s21_add_case_10, s21_add_case_11, s21_add_case_12,
      s21_add_case_13, s21_add_case_14, s21_add_case_15, s21_add_case_16,
      s21_add_case_17, s21_add_case_18, s21_add_case_19, s21_add_case_20,
      s21_add_case_21, s21_add_case_22, s21_add_case_23, s21_add_case_24,
      s21_add_case_25, s21_add_case_26, s21_add_case_27, s21_add_case_28,
      s21_add_case_29, s21_add_case_30, s21_add_case_31, s21_add_case_32,
      s21_add_case_33, s21_add_case_34, s21_add_case_35, s21_add_case_36,
      s21_add_case_37, s21_add_case_38, s21_add_case_39, s21_add_case_40,
      s21_add_case_41, s21_add_case_42, s21_add_case_43, s21_add_case_44,
      s21_add_case_45, s21_add_case_46, s21_add_case_47, s21_add_case_48,
      s21_add_case_49, s21_add_case_50, s21_add_case_51, s21_add_case_52,
      s21_add_case_53, s21_add_case_54, s21_add_case_55, s21_add_case_56,
      s21_add_case_57, s21_add_case_58, s21_add_case_59, s21_add_case_60,
      s21_add_case_61, s21_add_case_62, s21_add_case_63, s21_add_case_64,
      s21_add_case_65, s21_add_case_66, s21_add_case_67, s21_add_case_68,
      s21_add_case_69, s21_add_case_70, s21_add_case_71, s21_add_case_72,
      s21_add_case_73, s21_add_case_74, s21_add_case_75, s21_add_case_76,
      s21_add_case_77, s21_add_case_78, s21_add_case_79, s21_add_case_80,
      s21_add_case_81, s21_add_case_82, s21_add_case_83, s21_add_case_84,
      s21_add_case_85, s21_add_case_86, s21_add_case_87, s21_add_case_88,
      s21_add_case_89, s21_add_case_90, s21_add_case_91, s21_add_case_92,
      s21_add_case_93, s21_add_case_94, s21_add_case_95, s21_add_case_96,
      s21_add_case_97, s21_add_case_98, s21_add_case_99, s21_add_case_100,
      s21_add_edge_case,
  };
  test_function(s21_add_cases, sizeof(s21_add_cases) / sizeof(s21_add_cases[0]),
                "ADD", &passed_count, &failed_count);
#endif  // TEST_ADD

#ifdef TEST_SUB
  Suite *(*s21_sub_cases[])(void) = {
      s21_sub_case_1,  s21_sub_case_2,  s21_sub_case_3,  s21_sub_case_4,
      s21_sub_case_5,  s21_sub_case_6,  s21_sub_case_7,  s21_sub_case_8,
      s21_sub_case_9,  s21_sub_case_10, s21_sub_case_11, s21_sub_case_12,
      s21_sub_case_13, s21_sub_case_14, s21_sub_case_15, s21_sub_case_16,
      s21_sub_case_17, s21_sub_case_18, s21_sub_case_19, s21_sub_case_20,
      s21_sub_case_21, s21_sub_case_22, s21_sub_case_23, s21_sub_case_24,
      s21_sub_case_25, s21_sub_case_26, s21_sub_case_27, s21_sub_case_28,
      s21_sub_case_29, s21_sub_case_30, s21_sub_case_31, s21_sub_case_32,
      s21_sub_case_33, s21_sub_case_34, s21_sub_case_35, s21_sub_case_36,
      s21_sub_case_37, s21_sub_case_38, s21_sub_case_39, s21_sub_case_40,
      s21_sub_case_41, s21_sub_case_42, s21_sub_case_43, s21_sub_case_44,
      s21_sub_case_45, s21_sub_case_46, s21_sub_case_47, s21_sub_case_48,
      s21_sub_case_49, s21_sub_case_50, s21_sub_case_51, s21_sub_case_52,
      s21_sub_case_53, s21_sub_case_54, s21_sub_case_55, s21_sub_case_56,
      s21_sub_case_57, s21_sub_case_58, s21_sub_case_59, s21_sub_case_60,
      s21_sub_case_61, s21_sub_case_62, s21_sub_case_63, s21_sub_case_64,
      s21_sub_case_65, s21_sub_case_66, s21_sub_case_67, s21_sub_case_68,
      s21_sub_case_69, s21_sub_case_70, s21_sub_case_71, s21_sub_case_72,
      s21_sub_case_73, s21_sub_case_74, s21_sub_case_75, s21_sub_case_76,
      s21_sub_case_77, s21_sub_case_78, s21_sub_case_79, s21_sub_case_80,
      s21_sub_case_81, s21_sub_case_82, s21_sub_case_83, s21_sub_case_84,
      s21_sub_case_85, s21_sub_case_86, s21_sub_case_87, s21_sub_case_88,
      s21_sub_case_89, s21_sub_case_90, s21_sub_case_91, s21_sub_case_92,
      s21_sub_case_93, s21_sub_case_94, s21_sub_case_95, s21_sub_case_96,
      s21_sub_case_97, s21_sub_case_98, s21_sub_case_99, s21_sub_case_100,
      s21_sub_edge_case,
  };
  test_function(s21_sub_cases, sizeof(s21_sub_cases) / sizeof(s21_sub_cases[0]),
                "SUB", &passed_count, &failed_count);
#endif  // TEST_SUB

#ifdef TEST_MUL
  Suite *(*s21_mul_cases[])(void) = {
      s21_mul_case_1,  s21_mul_case_2,  s21_mul_case_3,  s21_mul_case_4,
      s21_mul_case_5,  s21_mul_case_6,  s21_mul_case_7,  s21_mul_case_8,
      s21_mul_case_9,  s21_mul_case_10, s21_mul_case_11, s21_mul_case_12,
      s21_mul_case_13, s21_mul_case_14, s21_mul_case_15, s21_mul_case_16,
      s21_mul_case_17, s21_mul_case_18, s21_mul_case_19, s21_mul_case_20,
      s21_mul_case_21, s21_mul_case_22, s21_mul_case_23, s21_mul_case_24,
      s21_mul_case_25, s21_mul_case_26, s21_mul_case_27, s21_mul_case_28,
      s21_mul_case_29, s21_mul_case_30, s21_mul_case_31, s21_mul_case_32,
      s21_mul_case_33, s21_mul_case_34, s21_mul_case_35, s21_mul_case_36,
      s21_mul_case_37, s21_mul_case_38, s21_mul_case_39, s21_mul_case_40,
      s21_mul_case_41, s21_mul_case_42, s21_mul_case_43, s21_mul_case_44,
      s21_mul_case_45, s21_mul_case_46, s21_mul_case_47, s21_mul_case_48,
      s21_mul_case_49, s21_mul_case_50, s21_mul_case_51, s21_mul_case_52,
      s21_mul_case_53, s21_mul_case_54, s21_mul_case_55, s21_mul_case_56,
      s21_mul_case_57, s21_mul_case_58, s21_mul_case_59, s21_mul_case_60,
      s21_mul_case_61, s21_mul_case_62, s21_mul_case_63, s21_mul_case_64,
      s21_mul_case_65, s21_mul_case_66, s21_mul_case_67, s21_mul_case_68,
      s21_mul_case_69, s21_mul_case_70, s21_mul_case_71, s21_mul_case_72,
      s21_mul_case_73, s21_mul_case_74, s21_mul_case_75, s21_mul_case_76,
      s21_mul_case_77, s21_mul_case_78, s21_mul_case_79, s21_mul_case_80,
      s21_mul_case_81, s21_mul_case_82, s21_mul_case_83, s21_mul_case_84,
      s21_mul_case_85, s21_mul_case_86, s21_mul_case_87, s21_mul_case_88,
      s21_mul_case_89, s21_mul_case_90, s21_mul_case_91, s21_mul_case_92,
      s21_mul_case_93, s21_mul_case_94, s21_mul_case_95, s21_mul_case_96,
      s21_mul_case_97, s21_mul_case_98, s21_mul_case_99, s21_mul_case_100,
      s21_mul_edge_case,
  };
  test_function(s21_mul_cases, sizeof(s21_mul_cases) / sizeof(s21_mul_cases[0]),
                "MUL", &passed_count, &failed_count);
#endif  // TEST_MUL

#ifdef TEST_DIV
  Suite *(*s21_div_cases[])(void) = {
      s21_div_case_1,  s21_div_case_2,  s21_div_case_3,  s21_div_case_4,
      s21_div_case_5,  s21_div_case_6,  s21_div_case_7,  s21_div_case_8,
      s21_div_case_9,  s21_div_case_10, s21_div_case_11, s21_div_case_12,
      s21_div_case_13, s21_div_case_14, s21_div_case_15, s21_div_case_16,
      s21_div_case_17, s21_div_case_18, s21_div_case_19, s21_div_case_20,
      s21_div_case_21, s21_div_case_22, s21_div_case_23, s21_div_case_24,
      s21_div_case_25, s21_div_case_26, s21_div_case_27, s21_div_case_28,
      s21_div_case_29, s21_div_case_30, s21_div_case_31, s21_div_case_32,
      s21_div_case_33, s21_div_case_34, s21_div_case_35, s21_div_case_36,
      s21_div_case_37, s21_div_case_38, s21_div_case_39, s21_div_case_40,
      s21_div_case_41, s21_div_case_42, s21_div_case_43, s21_div_case_44,
      s21_div_case_45, s21_div_case_46, s21_div_case_47, s21_div_case_48,
      s21_div_case_49, s21_div_case_50, s21_div_case_51, s21_div_case_52,
      s21_div_case_53, s21_div_case_54, s21_div_case_55, s21_div_case_56,
      s21_div_case_57, s21_div_case_58, s21_div_case_59, s21_div_case_60,
      s21_div_case_61, s21_div_case_62, s21_div_case_63, s21_div_case_64,
      s21_div_case_65, s21_div_case_66, s21_div_case_67, s21_div_case_68,
      s21_div_case_69, s21_div_case_70, s21_div_case_71, s21_div_case_72,
      s21_div_case_73, s21_div_case_74, s21_div_case_75, s21_div_case_76,
      s21_div_case_77, s21_div_case_78, s21_div_case_79, s21_div_case_80,
      s21_div_case_81, s21_div_case_82, s21_div_case_83, s21_div_case_84,
      s21_div_case_85, s21_div_case_86, s21_div_case_87, s21_div_case_88,
      s21_div_case_89, s21_div_case_90, s21_div_case_91, s21_div_case_92,
      s21_div_case_93, s21_div_case_94, s21_div_case_95, s21_div_case_96,
      s21_div_case_97, s21_div_case_98, s21_div_case_99, s21_div_case_100,
  };
  test_function(s21_div_cases, sizeof(s21_div_cases) / sizeof(s21_div_cases[0]),
                "DIV", &passed_count, &failed_count);
#endif  // TEST_DIV

#ifdef TEST_IS_EQUAL
  Suite *(*s21_is_equal_cases[])(void) = {
    s21_is_equal_case_1,
    s21_is_equal_case_2,
    s21_is_equal_case_3,
    s21_is_equal_case_4,
    s21_is_equal_case_5,
    s21_is_equal_case_6,
    s21_is_equal_case_7,
    s21_is_equal_case_8,
    s21_is_equal_case_9,
    s21_is_equal_case_10,
    s21_is_equal_case_11,
    s21_is_equal_case_12,
    s21_is_equal_case_13,
    s21_is_equal_case_14,
    s21_is_equal_case_15,
    s21_is_equal_case_16,
    s21_is_equal_case_17,
    s21_is_equal_case_18,
    s21_is_equal_case_19,
    s21_is_equal_case_20,
    s21_is_equal_case_21,
    s21_is_equal_case_22,
    s21_is_equal_case_23,
    s21_is_equal_case_24,
    s21_is_equal_case_25,
    s21_is_equal_case_26,
    s21_is_equal_case_27,
    s21_is_equal_case_28,
    s21_is_equal_case_29,
    s21_is_equal_case_30,
    s21_is_equal_case_31,
    s21_is_equal_case_32,
    s21_is_equal_case_33,
    s21_is_equal_case_34,
    s21_is_equal_case_35,
    s21_is_equal_case_36,
    s21_is_equal_case_37,
    s21_is_equal_case_38,
    s21_is_equal_case_39,
    s21_is_equal_case_40,
    s21_is_equal_case_41,
    s21_is_equal_case_42,
    s21_is_equal_case_43,
    s21_is_equal_case_44,
    s21_is_equal_case_45,
    s21_is_equal_case_46,
    s21_is_equal_case_47,
    s21_is_equal_case_48,
    s21_is_equal_case_49,
    s21_is_equal_case_50,
    s21_is_equal_case_51,
    s21_is_equal_case_52,
    s21_is_equal_case_53,
    s21_is_equal_case_54,
    s21_is_equal_case_55,
    s21_is_equal_case_56,
    s21_is_equal_case_57,
    s21_is_equal_case_58,
    s21_is_equal_case_59,
    s21_is_equal_case_60,
    s21_is_equal_case_61,
    s21_is_equal_case_62,
    s21_is_equal_case_63,
    s21_is_equal_case_64,
    s21_is_equal_case_65,
    s21_is_equal_case_66,
    s21_is_equal_case_67,
    s21_is_equal_case_68,
    s21_is_equal_case_69,
    s21_is_equal_case_70,
    s21_is_equal_case_71,
    s21_is_equal_case_72,
    s21_is_equal_case_73,
    s21_is_equal_case_74,
    s21_is_equal_case_75,
    s21_is_equal_case_76,
    s21_is_equal_case_77,
    s21_is_equal_case_78,
    s21_is_equal_case_79,
    s21_is_equal_case_80,
    s21_is_equal_case_81,
    s21_is_equal_case_82,
    s21_is_equal_case_83,
    s21_is_equal_case_84,
    s21_is_equal_case_85,
    s21_is_equal_case_86,
    s21_is_equal_case_87,
    s21_is_equal_case_88,
    s21_is_equal_case_89,
    s21_is_equal_case_90,
    s21_is_equal_case_91,
    s21_is_equal_case_92,
    s21_is_equal_case_93,
    s21_is_equal_case_94,
    s21_is_equal_case_95,
    s21_is_equal_case_96,
    s21_is_equal_case_97,
    s21_is_equal_case_98,
    s21_is_equal_case_99,
    s21_is_equal_case_100,
  };
  test_function(s21_is_equal_cases, sizeof(s21_is_equal_cases) / sizeof(s21_is_equal_cases[0]), "IS EQUAL", &passed_count, &failed_count);
#endif  // TEST_IS_EQUAL

#ifdef TEST_NOT_EQUAL
  Suite *(*s21_is_not_equal_cases[])(void) = {
    s21_is_not_equal_case_1,
    s21_is_not_equal_case_2,
    s21_is_not_equal_case_3,
    s21_is_not_equal_case_4,
    s21_is_not_equal_case_5,
    s21_is_not_equal_case_6,
    s21_is_not_equal_case_7,
    s21_is_not_equal_case_8,
    s21_is_not_equal_case_9,
    s21_is_not_equal_case_10,
    s21_is_not_equal_case_11,
    s21_is_not_equal_case_12,
    s21_is_not_equal_case_13,
    s21_is_not_equal_case_14,
    s21_is_not_equal_case_15,
    s21_is_not_equal_case_16,
    s21_is_not_equal_case_17,
    s21_is_not_equal_case_18,
    s21_is_not_equal_case_19,
    s21_is_not_equal_case_20,
    s21_is_not_equal_case_21,
    s21_is_not_equal_case_22,
    s21_is_not_equal_case_23,
    s21_is_not_equal_case_24,
    s21_is_not_equal_case_25,
    s21_is_not_equal_case_26,
    s21_is_not_equal_case_27,
    s21_is_not_equal_case_28,
    s21_is_not_equal_case_29,
    s21_is_not_equal_case_30,
    s21_is_not_equal_case_31,
    s21_is_not_equal_case_32,
    s21_is_not_equal_case_33,
    s21_is_not_equal_case_34,
    s21_is_not_equal_case_35,
    s21_is_not_equal_case_36,
    s21_is_not_equal_case_37,
    s21_is_not_equal_case_38,
    s21_is_not_equal_case_39,
    s21_is_not_equal_case_40,
    s21_is_not_equal_case_41,
    s21_is_not_equal_case_42,
    s21_is_not_equal_case_43,
    s21_is_not_equal_case_44,
    s21_is_not_equal_case_45,
    s21_is_not_equal_case_46,
    s21_is_not_equal_case_47,
    s21_is_not_equal_case_48,
    s21_is_not_equal_case_49,
    s21_is_not_equal_case_50,
    s21_is_not_equal_case_51,
    s21_is_not_equal_case_52,
    s21_is_not_equal_case_53,
    s21_is_not_equal_case_54,
    s21_is_not_equal_case_55,
    s21_is_not_equal_case_56,
    s21_is_not_equal_case_57,
    s21_is_not_equal_case_58,
    s21_is_not_equal_case_59,
    s21_is_not_equal_case_60,
    s21_is_not_equal_case_61,
    s21_is_not_equal_case_62,
    s21_is_not_equal_case_63,
    s21_is_not_equal_case_64,
    s21_is_not_equal_case_65,
    s21_is_not_equal_case_66,
    s21_is_not_equal_case_67,
    s21_is_not_equal_case_68,
    s21_is_not_equal_case_69,
    s21_is_not_equal_case_70,
    s21_is_not_equal_case_71,
    s21_is_not_equal_case_72,
    s21_is_not_equal_case_73,
    s21_is_not_equal_case_74,
    s21_is_not_equal_case_75,
    s21_is_not_equal_case_76,
    s21_is_not_equal_case_77,
    s21_is_not_equal_case_78,
    s21_is_not_equal_case_79,
    s21_is_not_equal_case_80,
    s21_is_not_equal_case_81,
    s21_is_not_equal_case_82,
    s21_is_not_equal_case_83,
    s21_is_not_equal_case_84,
    s21_is_not_equal_case_85,
    s21_is_not_equal_case_86,
    s21_is_not_equal_case_87,
    s21_is_not_equal_case_88,
    s21_is_not_equal_case_89,
    s21_is_not_equal_case_90,
    s21_is_not_equal_case_91,
    s21_is_not_equal_case_92,
    s21_is_not_equal_case_93,
    s21_is_not_equal_case_94,
    s21_is_not_equal_case_95,
    s21_is_not_equal_case_96,
    s21_is_not_equal_case_97,
    s21_is_not_equal_case_98,
    s21_is_not_equal_case_99,
    s21_is_not_equal_case_100,
  };
  test_function(s21_is_not_equal_cases, sizeof(s21_is_not_equal_cases) / sizeof(s21_is_not_equal_cases[0]), "IS NOT EQUAL", &passed_count, &failed_count);
#endif  // TEST_NOT_EQUAL

#ifdef TEST_IS_LESS
  Suite *(*s21_is_less_cases[])(void) = {
    s21_is_less_case_1,
    s21_is_less_case_2,
    s21_is_less_case_3,
    s21_is_less_case_4,
    s21_is_less_case_5,
    s21_is_less_case_6,
    s21_is_less_case_7,
    s21_is_less_case_8,
    s21_is_less_case_9,
    s21_is_less_case_10,
    s21_is_less_case_11,
    s21_is_less_case_12,
    s21_is_less_case_13,
    s21_is_less_case_14,
    s21_is_less_case_15,
    s21_is_less_case_16,
    s21_is_less_case_17,
    s21_is_less_case_18,
    s21_is_less_case_19,
    s21_is_less_case_20,
    s21_is_less_case_21,
    s21_is_less_case_22,
    s21_is_less_case_23,
    s21_is_less_case_24,
    s21_is_less_case_25,
    s21_is_less_case_26,
    s21_is_less_case_27,
    s21_is_less_case_28,
    s21_is_less_case_29,
    s21_is_less_case_30,
    s21_is_less_case_31,
    s21_is_less_case_32,
    s21_is_less_case_33,
    s21_is_less_case_34,
    s21_is_less_case_35,
    s21_is_less_case_36,
    s21_is_less_case_37,
    s21_is_less_case_38,
    s21_is_less_case_39,
    s21_is_less_case_40,
    s21_is_less_case_41,
    s21_is_less_case_42,
    s21_is_less_case_43,
    s21_is_less_case_44,
    s21_is_less_case_45,
    s21_is_less_case_46,
    s21_is_less_case_47,
    s21_is_less_case_48,
    s21_is_less_case_49,
    s21_is_less_case_50,
    s21_is_less_case_51,
    s21_is_less_case_52,
    s21_is_less_case_53,
    s21_is_less_case_54,
    s21_is_less_case_55,
    s21_is_less_case_56,
    s21_is_less_case_57,
    s21_is_less_case_58,
    s21_is_less_case_59,
    s21_is_less_case_60,
    s21_is_less_case_61,
    s21_is_less_case_62,
    s21_is_less_case_63,
    s21_is_less_case_64,
    s21_is_less_case_65,
    s21_is_less_case_66,
    s21_is_less_case_67,
    s21_is_less_case_68,
    s21_is_less_case_69,
    s21_is_less_case_70,
    s21_is_less_case_71,
    s21_is_less_case_72,
    s21_is_less_case_73,
    s21_is_less_case_74,
    s21_is_less_case_75,
    s21_is_less_case_76,
    s21_is_less_case_77,
    s21_is_less_case_78,
    s21_is_less_case_79,
    s21_is_less_case_80,
    s21_is_less_case_81,
    s21_is_less_case_82,
    s21_is_less_case_83,
    s21_is_less_case_84,
    s21_is_less_case_85,
    s21_is_less_case_86,
    s21_is_less_case_87,
    s21_is_less_case_88,
    s21_is_less_case_89,
    s21_is_less_case_90,
    s21_is_less_case_91,
    s21_is_less_case_92,
    s21_is_less_case_93,
    s21_is_less_case_94,
    s21_is_less_case_95,
    s21_is_less_case_96,
    s21_is_less_case_97,
    s21_is_less_case_98,
    s21_is_less_case_99,
    s21_is_less_case_100,
  };
  test_function(s21_is_less_cases, sizeof(s21_is_less_cases) / sizeof(s21_is_less_cases[0]), "IS LESS", &passed_count, &failed_count);
#endif  // TEST_IS_LESS

#ifdef TEST_LESS_OR_EQUAL

#endif  // TEST_LESS_OR_EQUAL

#ifdef TEST_IS_GREATER

#endif  // TEST_IS_GREATER

#ifdef TEST_GREATER_OR_EQUAL

#endif  // TEST_GREATER_OR_EQUAL

#ifdef TEST_INT_TO_DECIMAL
  Suite *(*int_to_decimal_cases[])(void) = {
      s21_from_int_to_decimal_case_1,  s21_from_int_to_decimal_case_2,
      s21_from_int_to_decimal_case_3,  s21_from_int_to_decimal_case_4,
      s21_from_int_to_decimal_case_5,  s21_from_int_to_decimal_case_6,
      s21_from_int_to_decimal_case_7,  s21_from_int_to_decimal_case_8,
      s21_from_int_to_decimal_case_9,  s21_from_int_to_decimal_case_10,
      s21_from_int_to_decimal_case_11, s21_from_int_to_decimal_case_12,
      s21_from_int_to_decimal_case_13, s21_from_int_to_decimal_case_14,
      s21_from_int_to_decimal_case_15, s21_from_int_to_decimal_case_16,
      s21_from_int_to_decimal_case_17, s21_from_int_to_decimal_case_18,
      s21_from_int_to_decimal_case_19, s21_from_int_to_decimal_case_20,
      s21_from_int_to_decimal_case_21, s21_from_int_to_decimal_case_22,
      s21_from_int_to_decimal_case_23, s21_from_int_to_decimal_case_24,
      s21_from_int_to_decimal_case_25, s21_from_int_to_decimal_case_26,
      s21_from_int_to_decimal_case_27, s21_from_int_to_decimal_case_28,
      s21_from_int_to_decimal_case_29, s21_from_int_to_decimal_case_30,
      s21_from_int_to_decimal_case_31, s21_from_int_to_decimal_case_32,
      s21_from_int_to_decimal_case_33, s21_from_int_to_decimal_case_34,
      s21_from_int_to_decimal_case_35, s21_from_int_to_decimal_case_36,
      s21_from_int_to_decimal_case_37, s21_from_int_to_decimal_case_38,
      s21_from_int_to_decimal_case_39, s21_from_int_to_decimal_case_40,
      s21_from_int_to_decimal_case_41, s21_from_int_to_decimal_case_42,
      s21_from_int_to_decimal_case_43, s21_from_int_to_decimal_case_44,
      s21_from_int_to_decimal_case_45, s21_from_int_to_decimal_case_46,
      s21_from_int_to_decimal_case_47, s21_from_int_to_decimal_case_48,
      s21_from_int_to_decimal_case_49, s21_from_int_to_decimal_case_50,
      s21_from_int_to_decimal_case_51, s21_from_int_to_decimal_case_52,
      s21_from_int_to_decimal_case_53, s21_from_int_to_decimal_case_54,
      s21_from_int_to_decimal_case_55, s21_from_int_to_decimal_case_56,
      s21_from_int_to_decimal_case_57, s21_from_int_to_decimal_case_58,
      s21_from_int_to_decimal_case_59, s21_from_int_to_decimal_case_60,
      s21_from_int_to_decimal_case_61, s21_from_int_to_decimal_case_62,
      s21_from_int_to_decimal_case_63, s21_from_int_to_decimal_case_64,
      s21_from_int_to_decimal_case_65, s21_from_int_to_decimal_case_66,
      s21_from_int_to_decimal_case_67, s21_from_int_to_decimal_case_68,
      s21_from_int_to_decimal_case_69, s21_from_int_to_decimal_case_70,
      s21_from_int_to_decimal_case_71, s21_from_int_to_decimal_case_72,
      s21_from_int_to_decimal_case_73, s21_from_int_to_decimal_case_74,
      s21_from_int_to_decimal_case_75, s21_from_int_to_decimal_case_76,
      s21_from_int_to_decimal_case_77, s21_from_int_to_decimal_case_78,
      s21_from_int_to_decimal_case_79, s21_from_int_to_decimal_case_80,
      s21_from_int_to_decimal_case_81, s21_from_int_to_decimal_case_82,
      s21_from_int_to_decimal_case_83, s21_from_int_to_decimal_case_84,
      s21_from_int_to_decimal_case_85, s21_from_int_to_decimal_case_86,
      s21_from_int_to_decimal_case_87, s21_from_int_to_decimal_case_88,
      s21_from_int_to_decimal_case_89, s21_from_int_to_decimal_case_90,
      s21_from_int_to_decimal_case_91, s21_from_int_to_decimal_case_92,
      s21_from_int_to_decimal_case_93, s21_from_int_to_decimal_case_94,
      s21_from_int_to_decimal_case_95, s21_from_int_to_decimal_case_96,
      s21_from_int_to_decimal_case_97, s21_from_int_to_decimal_case_98,
      s21_from_int_to_decimal_case_99, s21_from_int_to_decimal_case_100,
  };
  test_function(int_to_decimal_cases,
                sizeof(int_to_decimal_cases) / sizeof(int_to_decimal_cases[0]),
                "INT TO DECIMAL", &passed_count, &failed_count);
#endif  // TEST_INT_TO_DECIMAL

#ifdef TEST_FLOAT_TO_DECIMAL
  Suite *(*float_to_decimal_cases[])(void) = {
      s21_from_float_to_decimal_case_1,  s21_from_float_to_decimal_case_2,
      s21_from_float_to_decimal_case_3,  s21_from_float_to_decimal_case_4,
      s21_from_float_to_decimal_case_5,  s21_from_float_to_decimal_case_6,
      s21_from_float_to_decimal_case_7,  s21_from_float_to_decimal_case_8,
      s21_from_float_to_decimal_case_9,  s21_from_float_to_decimal_case_10,
      s21_from_float_to_decimal_case_11, s21_from_float_to_decimal_case_12,
      s21_from_float_to_decimal_case_13, s21_from_float_to_decimal_case_14,
      s21_from_float_to_decimal_case_15, s21_from_float_to_decimal_case_16,
      s21_from_float_to_decimal_case_17, s21_from_float_to_decimal_case_18,
      s21_from_float_to_decimal_case_19, s21_from_float_to_decimal_case_20,
      s21_from_float_to_decimal_case_21, s21_from_float_to_decimal_case_22,
      s21_from_float_to_decimal_case_23, s21_from_float_to_decimal_case_24,
      s21_from_float_to_decimal_case_25, s21_from_float_to_decimal_case_26,
      s21_from_float_to_decimal_case_27, s21_from_float_to_decimal_case_28,
      s21_from_float_to_decimal_case_29, s21_from_float_to_decimal_case_30,
      s21_from_float_to_decimal_case_31, s21_from_float_to_decimal_case_32,
      s21_from_float_to_decimal_case_33, s21_from_float_to_decimal_case_34,
      s21_from_float_to_decimal_case_35, s21_from_float_to_decimal_case_36,
      s21_from_float_to_decimal_case_37, s21_from_float_to_decimal_case_38,
      s21_from_float_to_decimal_case_39, s21_from_float_to_decimal_case_40,
      s21_from_float_to_decimal_case_41, s21_from_float_to_decimal_case_42,
      s21_from_float_to_decimal_case_43, s21_from_float_to_decimal_case_44,
      s21_from_float_to_decimal_case_45, s21_from_float_to_decimal_case_46,
      s21_from_float_to_decimal_case_47, s21_from_float_to_decimal_case_48,
      s21_from_float_to_decimal_case_49, s21_from_float_to_decimal_case_50,
      s21_from_float_to_decimal_case_51, s21_from_float_to_decimal_case_52,
      s21_from_float_to_decimal_case_53, s21_from_float_to_decimal_case_54,
      s21_from_float_to_decimal_case_55, s21_from_float_to_decimal_case_56,
      s21_from_float_to_decimal_case_57, s21_from_float_to_decimal_case_58,
      s21_from_float_to_decimal_case_59, s21_from_float_to_decimal_case_60,
      s21_from_float_to_decimal_case_61, s21_from_float_to_decimal_case_62,
      s21_from_float_to_decimal_case_63, s21_from_float_to_decimal_case_64,
      s21_from_float_to_decimal_case_65, s21_from_float_to_decimal_case_66,
      s21_from_float_to_decimal_case_67, s21_from_float_to_decimal_case_68,
      s21_from_float_to_decimal_case_69, s21_from_float_to_decimal_case_70,
      s21_from_float_to_decimal_case_71, s21_from_float_to_decimal_case_72,
      s21_from_float_to_decimal_case_73, s21_from_float_to_decimal_case_74,
      s21_from_float_to_decimal_case_75, s21_from_float_to_decimal_case_76,
      s21_from_float_to_decimal_case_77, s21_from_float_to_decimal_case_78,
      s21_from_float_to_decimal_case_79, s21_from_float_to_decimal_case_80,
      s21_from_float_to_decimal_case_81, s21_from_float_to_decimal_case_82,
      s21_from_float_to_decimal_case_83, s21_from_float_to_decimal_case_84,
      s21_from_float_to_decimal_case_85, s21_from_float_to_decimal_case_86,
      s21_from_float_to_decimal_case_87, s21_from_float_to_decimal_case_88,
      s21_from_float_to_decimal_case_89, s21_from_float_to_decimal_case_90,
      s21_from_float_to_decimal_case_91, s21_from_float_to_decimal_case_92,
      s21_from_float_to_decimal_case_93, s21_from_float_to_decimal_case_94,
      s21_from_float_to_decimal_case_95, s21_from_float_to_decimal_case_96,
      s21_from_float_to_decimal_case_97, s21_from_float_to_decimal_case_98,
      s21_from_float_to_decimal_case_99, s21_from_float_to_decimal_case_100,
  };
  test_function(
      float_to_decimal_cases,
      sizeof(float_to_decimal_cases) / sizeof(float_to_decimal_cases[0]),
      "FLOAT TO DECIMAL", &passed_count, &failed_count);
#endif  // TEST_FLOAT_TO_DECIMAL

#ifdef TEST_DECIMAL_TO_INT
  Suite *(*decimal_to_int_cases[])(void) = {
      s21_from_decimal_to_int_case_1,  s21_from_decimal_to_int_case_2,
      s21_from_decimal_to_int_case_3,  s21_from_decimal_to_int_case_4,
      s21_from_decimal_to_int_case_5,  s21_from_decimal_to_int_case_6,
      s21_from_decimal_to_int_case_7,  s21_from_decimal_to_int_case_8,
      s21_from_decimal_to_int_case_9,  s21_from_decimal_to_int_case_10,
      s21_from_decimal_to_int_case_11, s21_from_decimal_to_int_case_12,
      s21_from_decimal_to_int_case_13, s21_from_decimal_to_int_case_14,
      s21_from_decimal_to_int_case_15, s21_from_decimal_to_int_case_16,
      s21_from_decimal_to_int_case_17, s21_from_decimal_to_int_case_18,
      s21_from_decimal_to_int_case_19, s21_from_decimal_to_int_case_20,
      s21_from_decimal_to_int_case_21, s21_from_decimal_to_int_case_22,
      s21_from_decimal_to_int_case_23, s21_from_decimal_to_int_case_24,
      s21_from_decimal_to_int_case_25, s21_from_decimal_to_int_case_26,
      s21_from_decimal_to_int_case_27, s21_from_decimal_to_int_case_28,
      s21_from_decimal_to_int_case_29, s21_from_decimal_to_int_case_30,
      s21_from_decimal_to_int_case_31, s21_from_decimal_to_int_case_32,
      s21_from_decimal_to_int_case_33, s21_from_decimal_to_int_case_34,
      s21_from_decimal_to_int_case_35, s21_from_decimal_to_int_case_36,
      s21_from_decimal_to_int_case_37, s21_from_decimal_to_int_case_38,
      s21_from_decimal_to_int_case_39, s21_from_decimal_to_int_case_40,
      s21_from_decimal_to_int_case_41, s21_from_decimal_to_int_case_42,
      s21_from_decimal_to_int_case_43, s21_from_decimal_to_int_case_44,
      s21_from_decimal_to_int_case_45, s21_from_decimal_to_int_case_46,
      s21_from_decimal_to_int_case_47, s21_from_decimal_to_int_case_48,
      s21_from_decimal_to_int_case_49, s21_from_decimal_to_int_case_50,
      s21_from_decimal_to_int_case_51, s21_from_decimal_to_int_case_52,
      s21_from_decimal_to_int_case_53, s21_from_decimal_to_int_case_54,
      s21_from_decimal_to_int_case_55, s21_from_decimal_to_int_case_56,
      s21_from_decimal_to_int_case_57, s21_from_decimal_to_int_case_58,
      s21_from_decimal_to_int_case_59, s21_from_decimal_to_int_case_60,
      s21_from_decimal_to_int_case_61, s21_from_decimal_to_int_case_62,
      s21_from_decimal_to_int_case_63, s21_from_decimal_to_int_case_64,
      s21_from_decimal_to_int_case_65, s21_from_decimal_to_int_case_66,
      s21_from_decimal_to_int_case_67, s21_from_decimal_to_int_case_68,
      s21_from_decimal_to_int_case_69, s21_from_decimal_to_int_case_70,
      s21_from_decimal_to_int_case_71, s21_from_decimal_to_int_case_72,
      s21_from_decimal_to_int_case_73, s21_from_decimal_to_int_case_74,
      s21_from_decimal_to_int_case_75, s21_from_decimal_to_int_case_76,
      s21_from_decimal_to_int_case_77, s21_from_decimal_to_int_case_78,
      s21_from_decimal_to_int_case_79, s21_from_decimal_to_int_case_80,
      s21_from_decimal_to_int_case_81, s21_from_decimal_to_int_case_82,
      s21_from_decimal_to_int_case_83, s21_from_decimal_to_int_case_84,
      s21_from_decimal_to_int_case_85, s21_from_decimal_to_int_case_86,
      s21_from_decimal_to_int_case_87, s21_from_decimal_to_int_case_88,
      s21_from_decimal_to_int_case_89, s21_from_decimal_to_int_case_90,
      s21_from_decimal_to_int_case_91, s21_from_decimal_to_int_case_92,
      s21_from_decimal_to_int_case_93, s21_from_decimal_to_int_case_94,
      s21_from_decimal_to_int_case_95, s21_from_decimal_to_int_case_96,
      s21_from_decimal_to_int_case_97, s21_from_decimal_to_int_case_98,
      s21_from_decimal_to_int_case_99, s21_from_decimal_to_int_case_100,
  };
  test_function(decimal_to_int_cases,
                sizeof(decimal_to_int_cases) / sizeof(decimal_to_int_cases[0]),
                "DECIMAL TO INT", &passed_count, &failed_count);
#endif  // TEST_DECIMAL_TO_INT

#ifdef TEST_DECIMAL_TO_FLOAT
  Suite *(*decimal_to_float_cases[])(void) = {
      s21_from_decimal_to_float_case_1,  s21_from_decimal_to_float_case_2,
      s21_from_decimal_to_float_case_3,  s21_from_decimal_to_float_case_4,
      s21_from_decimal_to_float_case_5,  s21_from_decimal_to_float_case_6,
      s21_from_decimal_to_float_case_7,  s21_from_decimal_to_float_case_8,
      s21_from_decimal_to_float_case_9,  s21_from_decimal_to_float_case_10,
      s21_from_decimal_to_float_case_11, s21_from_decimal_to_float_case_12,
      s21_from_decimal_to_float_case_13, s21_from_decimal_to_float_case_14,
      s21_from_decimal_to_float_case_15, s21_from_decimal_to_float_case_16,
      s21_from_decimal_to_float_case_17, s21_from_decimal_to_float_case_18,
      s21_from_decimal_to_float_case_19, s21_from_decimal_to_float_case_20,
      s21_from_decimal_to_float_case_21, s21_from_decimal_to_float_case_22,
      s21_from_decimal_to_float_case_23, s21_from_decimal_to_float_case_24,
      s21_from_decimal_to_float_case_25, s21_from_decimal_to_float_case_26,
      s21_from_decimal_to_float_case_27, s21_from_decimal_to_float_case_28,
      s21_from_decimal_to_float_case_29, s21_from_decimal_to_float_case_30,
      s21_from_decimal_to_float_case_31, s21_from_decimal_to_float_case_32,
      s21_from_decimal_to_float_case_33, s21_from_decimal_to_float_case_34,
      s21_from_decimal_to_float_case_35, s21_from_decimal_to_float_case_36,
      s21_from_decimal_to_float_case_37, s21_from_decimal_to_float_case_38,
      s21_from_decimal_to_float_case_39, s21_from_decimal_to_float_case_40,
      s21_from_decimal_to_float_case_41, s21_from_decimal_to_float_case_42,
      s21_from_decimal_to_float_case_43, s21_from_decimal_to_float_case_44,
      s21_from_decimal_to_float_case_45, s21_from_decimal_to_float_case_46,
      s21_from_decimal_to_float_case_47, s21_from_decimal_to_float_case_48,
      s21_from_decimal_to_float_case_49, s21_from_decimal_to_float_case_50,
      s21_from_decimal_to_float_case_51, s21_from_decimal_to_float_case_52,
      s21_from_decimal_to_float_case_53, s21_from_decimal_to_float_case_54,
      s21_from_decimal_to_float_case_55, s21_from_decimal_to_float_case_56,
      s21_from_decimal_to_float_case_57, s21_from_decimal_to_float_case_58,
      s21_from_decimal_to_float_case_59, s21_from_decimal_to_float_case_60,
      s21_from_decimal_to_float_case_61, s21_from_decimal_to_float_case_62,
      s21_from_decimal_to_float_case_63, s21_from_decimal_to_float_case_64,
      s21_from_decimal_to_float_case_65, s21_from_decimal_to_float_case_66,
      s21_from_decimal_to_float_case_67, s21_from_decimal_to_float_case_68,
      s21_from_decimal_to_float_case_69, s21_from_decimal_to_float_case_70,
      s21_from_decimal_to_float_case_71, s21_from_decimal_to_float_case_72,
      s21_from_decimal_to_float_case_73, s21_from_decimal_to_float_case_74,
      s21_from_decimal_to_float_case_75, s21_from_decimal_to_float_case_76,
      s21_from_decimal_to_float_case_77, s21_from_decimal_to_float_case_78,
      s21_from_decimal_to_float_case_79, s21_from_decimal_to_float_case_80,
      s21_from_decimal_to_float_case_81, s21_from_decimal_to_float_case_82,
      s21_from_decimal_to_float_case_83, s21_from_decimal_to_float_case_84,
      s21_from_decimal_to_float_case_85, s21_from_decimal_to_float_case_86,
      s21_from_decimal_to_float_case_87, s21_from_decimal_to_float_case_88,
      s21_from_decimal_to_float_case_89, s21_from_decimal_to_float_case_90,
      s21_from_decimal_to_float_case_91, s21_from_decimal_to_float_case_92,
      s21_from_decimal_to_float_case_93, s21_from_decimal_to_float_case_94,
      s21_from_decimal_to_float_case_95, s21_from_decimal_to_float_case_96,
      s21_from_decimal_to_float_case_97, s21_from_decimal_to_float_case_98,
      s21_from_decimal_to_float_case_99, s21_from_decimal_to_float_case_100,
  };
  test_function(
      decimal_to_float_cases,
      sizeof(decimal_to_float_cases) / sizeof(decimal_to_float_cases[0]),
      "DECIMAL TO FLOAT", &passed_count, &failed_count);
#endif  // TEST_DECIMAL_TO_FLOAT

#ifdef TEST_ROUND
  Suite *(*s21_round_cases[])(void) = {
      s21_round_case_1,   s21_round_case_2,  s21_round_case_3,
      s21_round_case_4,   s21_round_case_5,  s21_round_case_6,
      s21_round_case_7,   s21_round_case_8,  s21_round_case_9,
      s21_round_case_10,  s21_round_case_11, s21_round_case_12,
      s21_round_case_13,  s21_round_case_14, s21_round_case_15,
      s21_round_case_16,  s21_round_case_17, s21_round_case_18,
      s21_round_case_19,  s21_round_case_20, s21_round_case_21,
      s21_round_case_22,  s21_round_case_23, s21_round_case_24,
      s21_round_case_25,  s21_round_case_26, s21_round_case_27,
      s21_round_case_28,  s21_round_case_29, s21_round_case_30,
      s21_round_case_31,  s21_round_case_32, s21_round_case_33,
      s21_round_case_34,  s21_round_case_35, s21_round_case_36,
      s21_round_case_37,  s21_round_case_38, s21_round_case_39,
      s21_round_case_40,  s21_round_case_41, s21_round_case_42,
      s21_round_case_43,  s21_round_case_44, s21_round_case_45,
      s21_round_case_46,  s21_round_case_47, s21_round_case_48,
      s21_round_case_49,  s21_round_case_50, s21_round_case_51,
      s21_round_case_52,  s21_round_case_53, s21_round_case_54,
      s21_round_case_55,  s21_round_case_56, s21_round_case_57,
      s21_round_case_58,  s21_round_case_59, s21_round_case_60,
      s21_round_case_61,  s21_round_case_62, s21_round_case_63,
      s21_round_case_64,  s21_round_case_65, s21_round_case_66,
      s21_round_case_67,  s21_round_case_68, s21_round_case_69,
      s21_round_case_70,  s21_round_case_71, s21_round_case_72,
      s21_round_case_73,  s21_round_case_74, s21_round_case_75,
      s21_round_case_76,  s21_round_case_77, s21_round_case_78,
      s21_round_case_79,  s21_round_case_80, s21_round_case_81,
      s21_round_case_82,  s21_round_case_83, s21_round_case_84,
      s21_round_case_85,  s21_round_case_86, s21_round_case_87,
      s21_round_case_88,  s21_round_case_89, s21_round_case_90,
      s21_round_case_91,  s21_round_case_92, s21_round_case_93,
      s21_round_case_94,  s21_round_case_95, s21_round_case_96,
      s21_round_case_97,  s21_round_case_98, s21_round_case_99,
      s21_round_case_100,
  };
  test_function(s21_round_cases,
                sizeof(s21_round_cases) / sizeof(s21_round_cases[0]), "ROUND",
                &passed_count, &failed_count);
#endif  // TEST_ROUND

#ifdef TEST_FLOOR
  Suite *(*s21_floor_cases[])(void) = {
      s21_floor_case_1,   s21_floor_case_2,  s21_floor_case_3,
      s21_floor_case_4,   s21_floor_case_5,  s21_floor_case_6,
      s21_floor_case_7,   s21_floor_case_8,  s21_floor_case_9,
      s21_floor_case_10,  s21_floor_case_11, s21_floor_case_12,
      s21_floor_case_13,  s21_floor_case_14, s21_floor_case_15,
      s21_floor_case_16,  s21_floor_case_17, s21_floor_case_18,
      s21_floor_case_19,  s21_floor_case_20, s21_floor_case_21,
      s21_floor_case_22,  s21_floor_case_23, s21_floor_case_24,
      s21_floor_case_25,  s21_floor_case_26, s21_floor_case_27,
      s21_floor_case_28,  s21_floor_case_29, s21_floor_case_30,
      s21_floor_case_31,  s21_floor_case_32, s21_floor_case_33,
      s21_floor_case_34,  s21_floor_case_35, s21_floor_case_36,
      s21_floor_case_37,  s21_floor_case_38, s21_floor_case_39,
      s21_floor_case_40,  s21_floor_case_41, s21_floor_case_42,
      s21_floor_case_43,  s21_floor_case_44, s21_floor_case_45,
      s21_floor_case_46,  s21_floor_case_47, s21_floor_case_48,
      s21_floor_case_49,  s21_floor_case_50, s21_floor_case_51,
      s21_floor_case_52,  s21_floor_case_53, s21_floor_case_54,
      s21_floor_case_55,  s21_floor_case_56, s21_floor_case_57,
      s21_floor_case_58,  s21_floor_case_59, s21_floor_case_60,
      s21_floor_case_61,  s21_floor_case_62, s21_floor_case_63,
      s21_floor_case_64,  s21_floor_case_65, s21_floor_case_66,
      s21_floor_case_67,  s21_floor_case_68, s21_floor_case_69,
      s21_floor_case_70,  s21_floor_case_71, s21_floor_case_72,
      s21_floor_case_73,  s21_floor_case_74, s21_floor_case_75,
      s21_floor_case_76,  s21_floor_case_77, s21_floor_case_78,
      s21_floor_case_79,  s21_floor_case_80, s21_floor_case_81,
      s21_floor_case_82,  s21_floor_case_83, s21_floor_case_84,
      s21_floor_case_85,  s21_floor_case_86, s21_floor_case_87,
      s21_floor_case_88,  s21_floor_case_89, s21_floor_case_90,
      s21_floor_case_91,  s21_floor_case_92, s21_floor_case_93,
      s21_floor_case_94,  s21_floor_case_95, s21_floor_case_96,
      s21_floor_case_97,  s21_floor_case_98, s21_floor_case_99,
      s21_floor_case_100,
  };
  test_function(s21_floor_cases,
                sizeof(s21_floor_cases) / sizeof(s21_floor_cases[0]), "FLOOR",
                &passed_count, &failed_count);
#endif  // TEST_FLOOR

#ifdef TEST_TRUNCATE
  Suite *(*s21_truncate_cases[])(void) = {
      s21_truncate_case_1,   s21_truncate_case_2,  s21_truncate_case_3,
      s21_truncate_case_4,   s21_truncate_case_5,  s21_truncate_case_6,
      s21_truncate_case_7,   s21_truncate_case_8,  s21_truncate_case_9,
      s21_truncate_case_10,  s21_truncate_case_11, s21_truncate_case_12,
      s21_truncate_case_13,  s21_truncate_case_14, s21_truncate_case_15,
      s21_truncate_case_16,  s21_truncate_case_17, s21_truncate_case_18,
      s21_truncate_case_19,  s21_truncate_case_20, s21_truncate_case_21,
      s21_truncate_case_22,  s21_truncate_case_23, s21_truncate_case_24,
      s21_truncate_case_25,  s21_truncate_case_26, s21_truncate_case_27,
      s21_truncate_case_28,  s21_truncate_case_29, s21_truncate_case_30,
      s21_truncate_case_31,  s21_truncate_case_32, s21_truncate_case_33,
      s21_truncate_case_34,  s21_truncate_case_35, s21_truncate_case_36,
      s21_truncate_case_37,  s21_truncate_case_38, s21_truncate_case_39,
      s21_truncate_case_40,  s21_truncate_case_41, s21_truncate_case_42,
      s21_truncate_case_43,  s21_truncate_case_44, s21_truncate_case_45,
      s21_truncate_case_46,  s21_truncate_case_47, s21_truncate_case_48,
      s21_truncate_case_49,  s21_truncate_case_50, s21_truncate_case_51,
      s21_truncate_case_52,  s21_truncate_case_53, s21_truncate_case_54,
      s21_truncate_case_55,  s21_truncate_case_56, s21_truncate_case_57,
      s21_truncate_case_58,  s21_truncate_case_59, s21_truncate_case_60,
      s21_truncate_case_61,  s21_truncate_case_62, s21_truncate_case_63,
      s21_truncate_case_64,  s21_truncate_case_65, s21_truncate_case_66,
      s21_truncate_case_67,  s21_truncate_case_68, s21_truncate_case_69,
      s21_truncate_case_70,  s21_truncate_case_71, s21_truncate_case_72,
      s21_truncate_case_73,  s21_truncate_case_74, s21_truncate_case_75,
      s21_truncate_case_76,  s21_truncate_case_77, s21_truncate_case_78,
      s21_truncate_case_79,  s21_truncate_case_80, s21_truncate_case_81,
      s21_truncate_case_82,  s21_truncate_case_83, s21_truncate_case_84,
      s21_truncate_case_85,  s21_truncate_case_86, s21_truncate_case_87,
      s21_truncate_case_88,  s21_truncate_case_89, s21_truncate_case_90,
      s21_truncate_case_91,  s21_truncate_case_92, s21_truncate_case_93,
      s21_truncate_case_94,  s21_truncate_case_95, s21_truncate_case_96,
      s21_truncate_case_97,  s21_truncate_case_98, s21_truncate_case_99,
      s21_truncate_case_100,
  };
  test_function(s21_truncate_cases,
                sizeof(s21_truncate_cases) / sizeof(s21_truncate_cases[0]),
                "TRUNCATE", &passed_count, &failed_count);
#endif  // TEST_TRUNCATE

#ifdef TEST_NEGATE
  Suite *(*s21_negate_cases[])(void) = {
    s21_negate_case_1,
  };
  test_function(s21_negate_cases,
                sizeof(s21_negate_cases) / sizeof(s21_negate_cases[0]),
                "NEGATE", &passed_count, &failed_count);
#endif  // TEST_NEGATE
  gettimeofday(&end, NULL);
  double micros = (((double)((end.tv_sec - start.tv_sec) * 1000000.0) + (double)end.tv_usec) - (double)(start.tv_usec)) / 1000000.0;
  conclusion(passed_count, failed_count, micros);

  return (failed_count) ? EXIT_FAILURE : EXIT_SUCCESS;
}

/**
 * @brief Function for testing the specified Suite.
 *
 * @param[out] test input Suite test.
 * @param[out] passed_count counter of successfully passed tests.
 *
 * @return int - error code.
 * @retval EXIT_SUCCESS = 0 - if the tests pass successfully.
 * @retval EXIT_FAILURE = 1 - if the tests pass unsuccessful.
 */
static int test_suite(Suite *test, int *passed_count) {
  SRunner *suite_runner = srunner_create(test);

  srunner_run_all(suite_runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(suite_runner);
  *passed_count += srunner_ntests_run(suite_runner) - failed_count;
  srunner_free(suite_runner);

  return failed_count;
}

/**
 * @brief Prints greeting message.
 */
static void greetings() {
  printf(ORANGE
         "\t\t\t\t __          __  _                            _          _   "
         "         _   _\n");
  printf(
      "\t\t\t\t \\ \\        / / | |                          | |        | |   "
      "       | | (_)            \n");
  printf(
      "\t\t\t\t  \\ \\  /\\  / /__| | ___ ___  _ __ ___   ___  | |_ ___   | |_ "
      "___  ___| |_ _ _ __   __ _ \n");
  printf(
      "\t\t\t\t   \\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\  "
      "| __/ _ \\/ __| __| | '_ \\ / _` |\n");
  printf(
      "\t\t\t\t    \\  /\\  /  __/ | (_| (_) | | | | | |  __/ | || (_) | | ||  "
      "__/\\__ \\ |_| | | | | (_| |\n");
  printf(
      "\t\t\t\t     \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/  "
      " \\__\\___||___/\\__|_|_| |_|\\__, |\n");
  printf(
      "\t\t\t\t                                                                "
      "                   __/ |\n");
  printf(
      "\t\t\t\t                                                                "
      "                  |___/ \n");
  printf("\t\t\t\t                                    _\n");
  printf("\t\t\t\t                                   | |\n");
  printf("\t\t\t\t                                   | |__  _   _\n");
  printf("\t\t\t\t                                   | '_ \\| | | |\n");
  printf("\t\t\t\t                                   | |_) | |_| |\n");
  printf("\t\t\t\t                                   |_.__/ \\__, |\n");
  printf(
      "\t\t\t\t                       _                   __/ |   _     _\n");
  printf(
      "\t\t\t\t                      | |                 |___/   | |   | |\n");
  printf(
      "\t\t\t\t                      | | _____  ___ ___  __ _  __| | __| | __ "
      "_\n");
  printf(
      "\t\t\t\t                      | |/ / _ \\/ __/ __|/ _` |/ _` |/ _` |/ "
      "_` |\n");
  printf(
      "\t\t\t\t                      |   < (_) \\__ \\__ \\ (_| | (_| | (_| | "
      "(_| |\n");
  printf(
      "\t\t\t\t                      "
      "|_|\\_\\___/|___/___/\\__,_|\\__,_|\\__,_|\\__,_|\n");
  printf(
      "\t\t\t\t                                                     | |        "
      "       \n");
  printf(
      "\t\t\t\t                  ___ _ __ ___  _ __ ___   ___  _ __ | |__   "
      "___  __ _ \n");
  printf(
      "\t\t\t\t                 / _ \\ '_ ` _ \\| '_ ` _ \\ / _ \\| '_ \\| '_ "
      "\\ / _ \\/ _` |\n");
  printf(
      "\t\t\t\t                |  __/ | | | | | | | | | | (_) | | | | |_) |  "
      "__/ (_| |\n");
  printf(
      "\t\t\t\t                 \\___|_| |_| |_|_| |_| |_|\\___/|_| |_|_.__/ "
      "\\___|\\__,_|\n" RESET);
}

/**
 * @brief Collects all functions for testing into a single block.
 *
 * @param array array of function under test.
 * @param size array size.
 * @param name name of the function being tested.
 * @param passed_count number of tests passed.
 * @param failed_count number of failed tests.
 */
static void test_function(Suite *(**array)(void), size_t size, char *name,
                          int *passed_count, int *failed_count) {
  function_declaration(name);
  for (size_t i = 0; i < size; i++) {
    line();
    *failed_count += test_suite(array[i](), passed_count);
  }
  line();
}

/**
 * @brief Prints function declaration message.
 *
 * @param[in] function name of testing function.
 */
static void function_declaration(char *function) {
  char space[] = "                                                                         ";
  char space1[100];
  char space2[100];
  sprintf(space1, "%s", space);
  sprintf(space2, "%s", space);
  int len = strlen(function) / 2;
  space1[strlen(space1) - len] = '\0';
  space2[strlen(space2) - (len + ((strlen(function) % 2) ? 1 : 0))] = '\0';
  printf(ORANGE"\n\n__________________________________________________________________________________________________________________________________________________________\n");
  printf("|                                                                                                                                                         |\n");
  printf("|%s%s TESTS %s|\n", space1, function, space2);
  printf("|_________________________________________________________________________________________________________________________________________________________|\n\n\n" RESET);
}

/**
 * @brief Prints the dividing line.
 */
static void line() {
  printf(ORANGE
         "====================================================================="
         "====================================================================="
         "=================\n");
}

/**
 * @brief Prints test results.
 *
 * @param[in] passed_count number of tests passed.
 * @param[in] failed_count number of failed tests.
 */
static void conclusion(int passed_count, int failed_count, double time) {
  char result[] = "                                                               ";
  char temp[50];
  sprintf(temp, "%d", passed_count);
  result[strlen(result) - strlen(temp)] = '\0';
  sprintf(temp, "%d", failed_count);
  result[strlen(result) - strlen(temp)] = '\0';
  sprintf(temp, "%.2lf", time);
  result[strlen(result) - strlen(temp)] = '\0';

  printf(ORANGE
         "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
         "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
         "~~~~~~~~~~~~~~~~~~~~~\n");
  printf(
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "
      "TOTAL RESULTS "
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
      "~~\n");
  printf(
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
      "~~~~~~~~~~~\n\n");
  printf("%sPASSED %d tests from %d for %.2lf seconds\n\n", result, passed_count, passed_count + failed_count, time);
  printf(
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
      "~~~~~~~~~~~" RESET "\n\n");
}
