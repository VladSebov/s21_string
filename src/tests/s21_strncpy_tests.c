#include "s21_tests.h"

void test_strncpy(char *dest, const char *src, s21_size_t n) {
  // Act
  char *actual_result = strncpy(dest, src, n);
  char *expected_result = strncpy(dest, src, n);

  // Assert
  ck_assert_str_eq(actual_result, expected_result);
}

START_TEST(he_made_up) {
  test_strncpy("Now it was time", "he made up", 6);
}
END_TEST

Suite *strncpy_suite(void) {
  Suite *s = suite_create("strncpy_suite");
  TCase *tc = tcase_create("strncpy_tc");

  tcase_add_test(tc, he_made_up);

  suite_add_tcase(s, tc);
  return s;
}
