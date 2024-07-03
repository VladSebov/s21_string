#include "s21_tests.h"

void test_strtok(char *tested_string, const char *delim) {
  // Checks first token:
  // Act
  char *actual_token = strtok(tested_string, delim);
  char *expected_token = strtok(tested_string, delim);
  // Assert
  ck_assert_pstr_eq(actual_token, expected_token);
  // Checks all the rest tokens:
  while (actual_token != NULL || expected_token != NULL) {
    // Act
    actual_token = strtok(NULL, delim);
    expected_token = strtok(NULL, delim);
    // Assert
    ck_assert_pstr_eq(actual_token, expected_token);
  }
}

START_TEST(space_delim) {
  char str[] = "Geeks for Geeks";
  char delim[] = " ";
  test_strtok(str, delim);
}
END_TEST

START_TEST(slash_delim) {
  char str[] = "Geeks/for/Geeks";
  char delim[] = "/";
  test_strtok(str, delim);
}
END_TEST

START_TEST(minus_delim) {
  char str[] = "Geeks-for-Geeks";
  char delim[] = "-";
  test_strtok(str, delim);
}
END_TEST

START_TEST(empty_str) {
  char str[] = "";
  char delim[] = "-";
  test_strtok(str, delim);
}
END_TEST

START_TEST(empty_delim) {
  char str[] = "Geeks-for-Geeks";
  char delim[] = "";
  test_strtok(str, delim);
}
END_TEST

Suite *strtok_suite(void) {
  Suite *s = suite_create("strtok_suite");
  TCase *tc = tcase_create("strtok_tc");

  tcase_add_test(tc, space_delim);
  tcase_add_test(tc, slash_delim);
  tcase_add_test(tc, minus_delim);
  tcase_add_test(tc, empty_delim);
  tcase_add_test(tc, empty_str);
  suite_add_tcase(s, tc);
  return s;
}
