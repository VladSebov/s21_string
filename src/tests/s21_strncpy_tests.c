#include "s21_tests.h"

void test_strncpy(char *dest, const char *src, s21_size_t n) {
  // Act
  char *actual_result = s21_strncpy(dest, src, n);
  char *expected_result = strncpy(dest, src, n);

  // Assert
  ck_assert_pstr_eq(actual_result, expected_result);
}

START_TEST(test) {
  char dest[15] = "test: ";
  char src[] = "Now it was time";
  test_strncpy(dest, src, 6);
}
END_TEST

Suite *strncpy_suite(void) {
  Suite *s = suite_create("strncpy_suite");
  TCase *tc = tcase_create("strncpy_tc");

  tcase_add_test(tc, test);

  suite_add_tcase(s, tc);
  return s;
}
