#include "s21_tests.h"

void test_strncmp(const char *string_1, const char *string_2, s21_size_t n) {
  // Act
  int actual_result = strncmp(string_1, string_2, n);
  int expected_result = strncmp(string_1, string_2, n);

  // Assert
  ck_assert_int_eq(actual_result, expected_result);
}

START_TEST(strings_are_equal) {
  test_strncmp("Now it was time", "Now it was time", 6);
}
END_TEST

Suite *strncmp_suite(void) {
  Suite *s = suite_create("strncmp_suite");
  TCase *tc = tcase_create("strncmp_tc");

  tcase_add_test(tc, strings_are_equal);
  suite_add_tcase(s, tc);
  return s;
}
