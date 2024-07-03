#include "s21_tests.h"

void test_strcspn(const char *string_1, const char *string_2) {
  // Act
  s21_size_t actual_result = strcspn(string_1, string_2);
  size_t expected_result = strcspn(string_1, string_2);

  // Assert
  ck_assert_int_eq(actual_result, expected_result);
}

START_TEST(jghf) { test_strcspn("Now it was time", "jhgf"); }
END_TEST

Suite *strcspn_suite(void) {
  Suite *s = suite_create("strcspn_suite");
  TCase *tc = tcase_create("strcspn_tc");

  tcase_add_test(tc, jghf);

  suite_add_tcase(s, tc);
  return s;
}
