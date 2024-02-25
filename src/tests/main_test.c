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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void test_function(Suite *(**array)(void), size_t size, char *name,
                          int *passed_count, int *failed_count);
static void conclusion(int passed_count, int failed_count);
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

#ifdef ADD
  Suite *(*s21_add_cases[])(void) = {
    s21_add_case_1,
    s21_add_case_2,
    s21_add_case_3,
    s21_add_case_4,
    s21_add_case_5,
    s21_add_case_6,
    s21_add_case_7,
    s21_add_case_8,
    s21_add_case_9,
    s21_add_case_10,
    s21_add_case_11,
    s21_add_case_12,
    s21_add_case_13,
    s21_add_case_14,
    s21_add_case_15,
    s21_add_case_16,
    s21_add_case_17,
    s21_add_case_18,
    s21_add_case_19,
    s21_add_case_20,
    s21_add_case_21,
    s21_add_case_22,
    s21_add_case_23,
    s21_add_case_24,
    s21_add_case_25,
    s21_add_case_26,
    s21_add_case_27,
    s21_add_case_28,
    s21_add_case_29,
    s21_add_case_30,
    s21_add_case_31,
    s21_add_case_32,
    s21_add_case_33,
    s21_add_case_34,
    s21_add_case_35,
    s21_add_case_36,
    s21_add_case_37,
    s21_add_case_38,
    s21_add_case_39,
    s21_add_case_40,
    s21_add_case_41,
    s21_add_case_42,
    s21_add_case_43,
    s21_add_case_44,
    s21_add_case_45,
    s21_add_case_46,
    s21_add_case_47,
    s21_add_case_48,
    s21_add_case_49,
    s21_add_case_50,
    s21_add_case_51,
    s21_add_case_52,
    s21_add_case_53,
    s21_add_case_54,
    s21_add_case_55,
    s21_add_case_56,
    s21_add_case_57,
    s21_add_case_58,
    s21_add_case_59,
    s21_add_case_60,
    s21_add_case_61,
    s21_add_case_62,
    s21_add_case_63,
    s21_add_case_64,
    s21_add_case_65,
    s21_add_case_66,
    s21_add_case_67,
    s21_add_case_68,
    s21_add_case_69,
    s21_add_case_70,
    s21_add_case_71,
    s21_add_case_72,
    s21_add_case_73,
    s21_add_case_74,
    s21_add_case_75,
    s21_add_case_76,
    s21_add_case_77,
    s21_add_case_78,
    s21_add_case_79,
    s21_add_case_80,
    s21_add_case_81,
    s21_add_case_82,
    s21_add_case_83,
    s21_add_case_84,
    s21_add_case_85,
    s21_add_case_86,
    s21_add_case_87,
    s21_add_case_88,
    s21_add_case_89,
    s21_add_case_90,
    s21_add_case_91,
    s21_add_case_92,
    s21_add_case_93,
    s21_add_case_94,
    s21_add_case_95,
    s21_add_case_96,
    s21_add_case_97,
    s21_add_case_98,
    s21_add_case_99,
    s21_add_case_100,
  };
  test_function(s21_add_cases, sizeof(s21_add_cases) / sizeof(s21_add_cases[0]), "ADD", &passed_count, &failed_count);
#endif // ADD

#ifdef SUB
  Suite *(*s21_sub_cases[])(void) = {
    s21_sub_case_1,
    s21_sub_case_2,
    s21_sub_case_3,
    s21_sub_case_4,
    s21_sub_case_5,
    s21_sub_case_6,
    s21_sub_case_7,
    s21_sub_case_8,
    s21_sub_case_9,
    s21_sub_case_10,
    s21_sub_case_11,
    s21_sub_case_12,
    s21_sub_case_13,
    s21_sub_case_14,
    s21_sub_case_15,
    s21_sub_case_16,
    s21_sub_case_17,
    s21_sub_case_18,
    s21_sub_case_19,
    s21_sub_case_20,
    s21_sub_case_21,
    s21_sub_case_22,
    s21_sub_case_23,
    s21_sub_case_24,
    s21_sub_case_25,
    s21_sub_case_26,
    s21_sub_case_27,
    s21_sub_case_28,
    s21_sub_case_29,
    s21_sub_case_30,
    s21_sub_case_31,
    s21_sub_case_32,
    s21_sub_case_33,
    s21_sub_case_34,
    s21_sub_case_35,
    s21_sub_case_36,
    s21_sub_case_37,
    s21_sub_case_38,
    s21_sub_case_39,
    s21_sub_case_40,
    s21_sub_case_41,
    s21_sub_case_42,
    s21_sub_case_43,
    s21_sub_case_44,
    s21_sub_case_45,
    s21_sub_case_46,
    s21_sub_case_47,
    s21_sub_case_48,
    s21_sub_case_49,
    s21_sub_case_50,
    s21_sub_case_51,
    s21_sub_case_52,
    s21_sub_case_53,
    s21_sub_case_54,
    s21_sub_case_55,
    s21_sub_case_56,
    s21_sub_case_57,
    s21_sub_case_58,
    s21_sub_case_59,
    s21_sub_case_60,
    s21_sub_case_61,
    s21_sub_case_62,
    s21_sub_case_63,
    s21_sub_case_64,
    s21_sub_case_65,
    s21_sub_case_66,
    s21_sub_case_67,
    s21_sub_case_68,
    s21_sub_case_69,
    s21_sub_case_70,
    s21_sub_case_71,
    s21_sub_case_72,
    s21_sub_case_73,
    s21_sub_case_74,
    s21_sub_case_75,
    s21_sub_case_76,
    s21_sub_case_77,
    s21_sub_case_78,
    s21_sub_case_79,
    s21_sub_case_80,
    s21_sub_case_81,
    s21_sub_case_82,
    s21_sub_case_83,
    s21_sub_case_84,
    s21_sub_case_85,
    s21_sub_case_86,
    s21_sub_case_87,
    s21_sub_case_88,
    s21_sub_case_89,
    s21_sub_case_90,
    s21_sub_case_91,
    s21_sub_case_92,
    s21_sub_case_93,
    s21_sub_case_94,
    s21_sub_case_95,
    s21_sub_case_96,
    s21_sub_case_97,
    s21_sub_case_98,
    s21_sub_case_99,
    s21_sub_case_100,
  };
  test_function(s21_sub_cases, sizeof(s21_sub_cases) / sizeof(s21_sub_cases[0]), "SUB", &passed_count, &failed_count);
#endif // SUB

#ifdef MUL

#endif // MUL

#ifdef DIV
  Suite *(*s21_div_cases[])(void) = {
    s21_div_case_1,
    s21_div_case_2,
    s21_div_case_3,
    s21_div_case_4,
    s21_div_case_5,
    s21_div_case_6,
    s21_div_case_7,
    s21_div_case_8,
    s21_div_case_9,
    s21_div_case_10,
    s21_div_case_11,
    s21_div_case_12,
    s21_div_case_13,
    s21_div_case_14,
    s21_div_case_15,
    s21_div_case_16,
    s21_div_case_17,
    s21_div_case_18,
    s21_div_case_19,
    s21_div_case_20,
    s21_div_case_21,
    s21_div_case_22,
    s21_div_case_23,
    s21_div_case_24,
    s21_div_case_25,
    s21_div_case_26,
    s21_div_case_27,
    s21_div_case_28,
    s21_div_case_29,
    s21_div_case_30,
    s21_div_case_31,
    s21_div_case_32,
    s21_div_case_33,
    s21_div_case_34,
    s21_div_case_35,
    s21_div_case_36,
    s21_div_case_37,
    s21_div_case_38,
    s21_div_case_39,
    s21_div_case_40,
    s21_div_case_41,
    s21_div_case_42,
    s21_div_case_43,
    s21_div_case_44,
    s21_div_case_45,
    s21_div_case_46,
    s21_div_case_47,
    s21_div_case_48,
    s21_div_case_49,
    s21_div_case_50,
    s21_div_case_51,
    s21_div_case_52,
    s21_div_case_53,
    s21_div_case_54,
    s21_div_case_55,
    s21_div_case_56,
    s21_div_case_57,
    s21_div_case_58,
    s21_div_case_59,
    s21_div_case_60,
    s21_div_case_61,
    s21_div_case_62,
    s21_div_case_63,
    s21_div_case_64,
    s21_div_case_65,
    s21_div_case_66,
    s21_div_case_67,
    s21_div_case_68,
    s21_div_case_69,
    s21_div_case_70,
    s21_div_case_71,
    s21_div_case_72,
    s21_div_case_73,
    s21_div_case_74,
    s21_div_case_75,
    s21_div_case_76,
    s21_div_case_77,
    s21_div_case_78,
    s21_div_case_79,
    s21_div_case_80,
    s21_div_case_81,
    s21_div_case_82,
    s21_div_case_83,
    s21_div_case_84,
    s21_div_case_85,
    s21_div_case_86,
    s21_div_case_87,
    s21_div_case_88,
    s21_div_case_89,
    s21_div_case_90,
    s21_div_case_91,
    s21_div_case_92,
    s21_div_case_93,
    s21_div_case_94,
    s21_div_case_95,
    s21_div_case_96,
    s21_div_case_97,
    s21_div_case_98,
    s21_div_case_99,
    s21_div_case_100,
  };
  test_function(s21_div_cases, sizeof(s21_div_cases) / sizeof(s21_div_cases[0]), "DIV", &passed_count, &failed_count);
#endif // DIV

#ifdef IS_EQUAL

#endif // IS_EQUAL

#ifdef NOT_EQUAL

#endif // NOT_EQUAL

#ifdef IS_LESS

#endif // IS_LESS

#ifdef LESS_OR_EQUAL

#endif // LESS_OR_EQUAL

#ifdef IS_GREATER

#endif // IS_GREATER

#ifdef GREATER_OR_EQUAL

#endif // GREATER_OR_EQUAL

#ifdef INT_TO_DECIMAL

#endif // INT_TO_DECIMAL

#ifdef FLOAT_TO_DECIMAL

#endif // FLOAT_TO_DECIMAL

#ifdef DECIMAL_TO_INT

#endif // DECIMAL_TO_INT

#ifdef DECIMAL_TO_FLOAT

#endif // DECIMAL_TO_FLOAT

#ifdef ROUND

#endif // ROUND

#ifdef FLOOR

#endif // FLOOR

#ifdef TRUNCATE

#endif // TRUNCATE

#ifdef NEGATE

#endif // NEGATE

  conclusion(passed_count, failed_count);

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
  printf(ORANGE"\t\t\t\t __          __  _                            _          _            _   _\n");
  printf("\t\t\t\t \\ \\        / / | |                          | |        | |          | | (_)            \n");
  printf("\t\t\t\t  \\ \\  /\\  / /__| | ___ ___  _ __ ___   ___  | |_ ___   | |_ ___  ___| |_ _ _ __   __ _ \n");
  printf("\t\t\t\t   \\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\  | __/ _ \\/ __| __| | '_ \\ / _` |\n");
  printf("\t\t\t\t    \\  /\\  /  __/ | (_| (_) | | | | | |  __/ | || (_) | | ||  __/\\__ \\ |_| | | | | (_| |\n");
  printf("\t\t\t\t     \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/   \\__\\___||___/\\__|_|_| |_|\\__, |\n");
  printf("\t\t\t\t                                                                                   __/ |\n");
  printf("\t\t\t\t                                                                                  |___/ \n");
  printf("\t\t\t\t                                    _\n");
  printf("\t\t\t\t                                   | |\n");
  printf("\t\t\t\t                                   | |__  _   _\n");
  printf("\t\t\t\t                                   | '_ \\| | | |\n");
  printf("\t\t\t\t                                   | |_) | |_| |\n");
  printf("\t\t\t\t                                   |_.__/ \\__, |\n");
  printf("\t\t\t\t                       _                   __/ |   _     _\n");
  printf("\t\t\t\t                      | |                 |___/   | |   | |\n");
  printf("\t\t\t\t                      | | _____  ___ ___  __ _  __| | __| | __ _\n");
  printf("\t\t\t\t                      | |/ / _ \\/ __/ __|/ _` |/ _` |/ _` |/ _` |\n");
  printf("\t\t\t\t                      |   < (_) \\__ \\__ \\ (_| | (_| | (_| | (_| |\n");
  printf("\t\t\t\t                      |_|\\_\\___/|___/___/\\__,_|\\__,_|\\__,_|\\__,_|\n");
  printf("\t\t\t\t                                                     | |               \n");
  printf("\t\t\t\t                  ___ _ __ ___  _ __ ___   ___  _ __ | |__   ___  __ _ \n");
  printf("\t\t\t\t                 / _ \\ '_ ` _ \\| '_ ` _ \\ / _ \\| '_ \\| '_ \\ / _ \\/ _` |\n");
  printf("\t\t\t\t                |  __/ | | | | | | | | | | (_) | | | | |_) |  __/ (_| |\n");
  printf("\t\t\t\t                 \\___|_| |_| |_|_| |_| |_|\\___/|_| |_|_.__/ \\___|\\__,_|\n"RESET);
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
  char space[10] = {0};
  int str_len = strlen(function);
  if (str_len == 3) {
    strcpy(space, "      ");
  } else if (str_len == 8) {
    strcpy(space, " ");
  }
  printf(ORANGE"\n\n ________________________________________________________________________________________________________________________________________________________\n");
  printf("|                                                                                                                                                        |\n");
  printf("|                                                                    %s TESTS %s                                                                    |\n", function, space);
  printf("|________________________________________________________________________________________________________________________________________________________|\n\n\n"RESET);
}

/**
 * @brief Prints the dividing line.
 */
static void line() {
  printf(ORANGE"===========================================================================================================================================================\n");
}

/**
 * @brief Prints test results.
 *
 * @param[in] passed_count number of tests passed.
 * @param[in] failed_count number of failed tests.
 */
static void conclusion(int passed_count, int failed_count) {
  printf(ORANGE"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TOTAL RESULTS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
  printf("                                                            PASSED %d tests from %d\n\n", passed_count, passed_count + failed_count);
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"RESET"\n\n");
}

