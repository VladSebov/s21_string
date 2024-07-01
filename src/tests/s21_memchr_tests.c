#include "s21_tests.h"

void test_memchr(const void *tested_string, int tested_char, s21_size_t n) {
  // Act
  void *actual_result = memchr(tested_string, tested_char, n);
  void *expected_result = memchr(tested_string, tested_char, n);

  // Assert
  ck_assert_ptr_eq(actual_result, expected_result);
}

START_TEST(occurance_is_not_null) {
  test_memchr("Now it was time to make up his mind", 't', 15);
}
END_TEST

Suite *memchr_suite(void) {
  Suite *s = suite_create("memchr_suite");
  TCase *tc = tcase_create("memchr_tc");

  tcase_add_test(tc, occurance_is_not_null);
  suite_add_tcase(s, tc);
  return s;
}
