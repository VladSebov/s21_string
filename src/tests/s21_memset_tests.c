#include "s21_tests.h"

void test_memset(void *str, int c, s21_size_t n) {
  // Act
  void *actual_result = memset(str, c, n);
  void *expected_result = memset(str, c, n);

  // Assert
  ck_assert_ptr_eq(actual_result, expected_result);
}

START_TEST(pasting_b_in_first_6_bytes) {
  test_memset("Now it was time", 'b', 6);
}
END_TEST

Suite *memset_suite(void) {
  Suite *s = suite_create("memset_suite");
  TCase *tc = tcase_create("memset_tc");

  tcase_add_test(tc, pasting_b_in_first_6_bytes);

  suite_add_tcase(s, tc);
  return s;
}
