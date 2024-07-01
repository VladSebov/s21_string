#include "s21_tests.h"

void test_memcmp(const void *string_1, const void *string_2,
                 s21_size_t n) {
  // Act
  int actual_result = memcmp(string_1, string_2, n);
  int expected_result = memcmp(string_1, string_2, n);

  // Assert
  ck_assert_int_eq(actual_result, expected_result);
}

START_TEST(bytes_are_equal) { test_memcmp("Now it was time", "Now it was mine", 6); }
END_TEST

Suite *memcmp_suite(void) {
  Suite *s = suite_create("memcmp_suite");
  TCase *tc = tcase_create("memcmp_tc");

  tcase_add_test(tc, bytes_are_equal);
  suite_add_tcase(s, tc);
  return s;
}
