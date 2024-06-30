#include "s21_tests.h"

void test_strrchr(const char *tested_string, int tested_char) {
  // Act
  char *actual_result = s21_strrchr(tested_string, tested_char);
  char *expected_result = strrchr(tested_string, tested_char);

  // Assert
  ck_assert_ptr_eq(actual_result, expected_result);
}

START_TEST(last_occurance_of_i) {
  test_strrchr("Now it was time", 'i');
}
END_TEST

Suite *strrchr_suite(void) {
  Suite *s = suite_create("strrchr_suite");
  TCase *tc = tcase_create("strrchr_tc");

  tcase_add_test(tc, last_occurance_of_i);

  suite_add_tcase(s, tc);
  return s;
}
