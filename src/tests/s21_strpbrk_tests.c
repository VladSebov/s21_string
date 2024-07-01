#include "s21_tests.h"

void test_strpbrk(const char *string_1, const char *string_2) {
  // Act
  char *actual_result = strpbrk(string_1, string_2);
  char *expected_result = strpbrk(string_1, string_2);

  // Assert
  ck_assert_ptr_eq(actual_result, expected_result);
}

START_TEST(occurance_is_not_null) {
  test_strpbrk("Now it was time", "i");
}
END_TEST

START_TEST(occurance_is_null) {
  test_strpbrk("Now it was time", "f");
}
END_TEST

Suite *strpbrk_suite(void) {
  Suite *s = suite_create("strpbrk_suite");
  TCase *tc = tcase_create("strpbrk_tc");

  tcase_add_test(tc, occurance_is_not_null);
  tcase_add_test(tc, occurance_is_null);

  suite_add_tcase(s, tc);
  return s;
}
