#include "s21_tests.h"

void test_strlen(const char *tested_string) {
  // Act
  s21_size_t actual_result = s21_strlen(tested_string);
  size_t expected_result = strlen(tested_string);

  // Assert
  ck_assert_int_eq(actual_result, expected_result);
}

START_TEST(string_length_is_15) {
  test_strlen("Now it was time");
}
END_TEST

START_TEST(empty_string) {
  test_strlen("");
}
END_TEST

START_TEST(string_length_is_6) {
  test_strlen("It was");
}
END_TEST

START_TEST(null_in_the_middle) {
  test_strlen("It was\0 the great time");
}
END_TEST

Suite *strlen_suite(void) {
  Suite *s = suite_create("strlen_suite");
  TCase *tc = tcase_create("strlen_tc");

  tcase_add_test(tc, string_length_is_15);
  tcase_add_test(tc, empty_string);
  tcase_add_test(tc, string_length_is_6);
  tcase_add_test(tc, null_in_the_middle);

  suite_add_tcase(s, tc);
  return s;
}

