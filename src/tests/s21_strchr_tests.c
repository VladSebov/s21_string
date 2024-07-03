#include "s21_tests.h"

void test_strchr(const char *str, int c) {
  // Act
  char *actual_result = strchr(str, c);
  char *expected_result = strchr(str, c);

  // Assert
  ck_assert_ptr_eq(actual_result, expected_result);
}

START_TEST(first_occurance_is_not_null) { test_strchr("Now it was time", 'i'); }
END_TEST

START_TEST(first_occurance_is_null) { test_strchr("Now it was time", 'f'); }
END_TEST

START_TEST(zero_in_the_middle) { test_strchr("Now it was\0 time", 'i'); }
END_TEST

START_TEST(empty_string) { test_strchr("", 'i'); }
END_TEST

START_TEST(zero_char) { test_strchr("Now it was time", '\0'); }
END_TEST

START_TEST(newline_in_the_middle) { test_strchr("Now it was\n time", 'i'); }
END_TEST

Suite *strchr_suite(void) {
  Suite *s = suite_create("strchr_suite");
  TCase *tc = tcase_create("strchr_tc");

  tcase_add_test(tc, first_occurance_is_not_null);
  tcase_add_test(tc, first_occurance_is_null);
  tcase_add_test(tc, zero_in_the_middle);
  tcase_add_test(tc, empty_string);
  tcase_add_test(tc, zero_char);
  tcase_add_test(tc, newline_in_the_middle);

  suite_add_tcase(s, tc);
  return s;
}
