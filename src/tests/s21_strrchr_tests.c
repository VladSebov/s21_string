#include "s21_tests.h"

void test_strrchr(const char *tested_string, int tested_char) {
  // Act
  char *actual_result = s21_strrchr(tested_string, tested_char);
  char *expected_result = strrchr(tested_string, tested_char);

  // Assert
  ck_assert_ptr_eq(actual_result, expected_result);
}

START_TEST(last_occurance_is_not_null) { test_strrchr("Now it was time", 'i'); }
END_TEST

START_TEST(last_occurance_is_null) { test_strrchr("Now it was time", 'f'); }
END_TEST

START_TEST(zero_in_the_middle) { test_strrchr("Now it was\0 time", 'i'); }
END_TEST

START_TEST(empty_string) { test_strrchr("", 'i'); }
END_TEST

START_TEST(zero_char) { test_strrchr("Now it was time", '\0'); }
END_TEST

START_TEST(newline_in_the_middle) { test_strrchr("Now it was\n time", 'i'); }
END_TEST

Suite *strrchr_suite(void) {
  Suite *s = suite_create("strrchr_suite");
  TCase *tc = tcase_create("strrchr_tc");

  tcase_add_test(tc, last_occurance_is_not_null);
  tcase_add_test(tc, last_occurance_is_null);
  tcase_add_test(tc, zero_in_the_middle);
  tcase_add_test(tc, empty_string);
  tcase_add_test(tc, zero_char);
  tcase_add_test(tc, newline_in_the_middle);

  suite_add_tcase(s, tc);
  return s;
}
