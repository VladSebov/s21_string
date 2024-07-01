#include "s21_tests.h"

void test_strtok(char *tested_string, const char *delim) {
  // Act
  char *actual_result = strtok(tested_string, delim);
  char *expected_result = strtok(tested_string, delim);

  // Assert
  ck_assert_str_eq(actual_result, expected_result);
}

START_TEST(space_delim) {
  test_strtok("Now it was time", " ");
}
END_TEST

Suite *strtok_suite(void) {
  Suite *s = suite_create("strtok_suite");
  TCase *tc = tcase_create("strtok_tc");

  tcase_add_test(tc, space_delim);

  suite_add_tcase(s, tc);
  return s;
}
