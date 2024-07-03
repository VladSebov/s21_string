#include "s21_tests.h"

void test_strstr(const char *haystack, const char *needle) {
  // Act
  char *actual_result = s21_strstr(haystack, needle);
  char *expected_result = strstr(haystack, needle);

  // Assert
  ck_assert_pstr_eq(actual_result, expected_result);
}

START_TEST(occurance_is_not_null) { test_strstr("Now it was time", "it was"); }
END_TEST

START_TEST(occurance_is_null) { test_strstr("Now it was time", "If I could"); }
END_TEST

START_TEST(needle_larger_than_haystack) {
  test_strstr("Now it was time", "If I could say something");
}
END_TEST

START_TEST(needle_larger_than_haystack_2) {
  test_strstr("Now it was time", "Now it was time to make up his mind");
}
END_TEST

START_TEST(zero_in_the_middle) { test_strstr("Now it was\0 time", "time"); }
END_TEST

START_TEST(empty_haystack) { test_strstr("", "nevermind"); }
END_TEST

START_TEST(empty_needle) { test_strstr("Now it was time", ""); }
END_TEST

START_TEST(newline_in_the_middle) { test_strstr("Now it was\n time", "time"); }
END_TEST

Suite *strstr_suite(void) {
  Suite *s = suite_create("strstr_suite");
  TCase *tc = tcase_create("strstr_tc");

  tcase_add_test(tc, occurance_is_not_null);
  tcase_add_test(tc, occurance_is_null);
  tcase_add_test(tc, zero_in_the_middle);
  tcase_add_test(tc, empty_needle);
  tcase_add_test(tc, empty_haystack);
  tcase_add_test(tc, needle_larger_than_haystack);
  tcase_add_test(tc, needle_larger_than_haystack_2);
  tcase_add_test(tc, newline_in_the_middle);

  suite_add_tcase(s, tc);
  return s;
}
