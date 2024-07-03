#include "s21_tests.h"

void test_strncat(char *dest, const char *src, s21_size_t n) {
  // Act
  char *actual_result = strncat(dest, src, n);
  char *expected_result = strncat(dest, src, n);

  // Assert
  ck_assert_pstr_eq(actual_result, expected_result);
}

START_TEST(test) {
  char dest[15] = "test: ";
  char src[] = "Now it was time";
  test_strncat(dest, src, 3);
}
END_TEST

Suite *strncat_suite(void) {
  Suite *s = suite_create("strncat_suite");
  TCase *tc = tcase_create("strncat_tc");

  tcase_add_test(tc, test);
  suite_add_tcase(s, tc);
  return s;
}
