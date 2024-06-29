#include "s21_tests.h"

void act_and_assert(const char *tested_string) {
  // Act
  s21_size_t actual_result = s21_strlen(tested_string);
  size_t expected_result = strlen(tested_string);

  // Assert
  ck_assert_int_eq(actual_result, expected_result);
}

START_TEST(string_length_is_15) {
  // Arrange
  char *tested_string = "Now it was time";

  act_and_assert(tested_string);
}
END_TEST

START_TEST(empty_string) {
  // Arrange
  act_and_assert("");
}
END_TEST

START_TEST(string_length_is_6) {
  // Arrange
  char *tested_string = "It was";

  act_and_assert(tested_string);
}
END_TEST

Suite *strlen_suite(void) {
  Suite *s = suite_create("strlen_suite");
  TCase *tc = tcase_create("strlen_tc");

  tcase_add_test(tc, string_length_is_15);
  tcase_add_test(tc, empty_string);
  tcase_add_test(tc, string_length_is_6);

  suite_add_tcase(s, tc);
  return s;
}