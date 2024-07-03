#include "s21_tests.h"

void test_memcpy(void *dest, const void *src, s21_size_t n) {
  // Act
  void *actual_result = memcpy(dest, src, n);
  void *expected_result = memcpy(dest, src, n);

  // Assert
  ck_assert_ptr_eq(actual_result, expected_result);
}

START_TEST(copying_first_6_bytes) {
  char dest[] = "Now it was time";
  char src[] = "xxxxxx...";
  test_memcpy(dest, src, 6);
}
END_TEST

Suite *memcpy_suite(void) {
  Suite *s = suite_create("memcpy_suite");
  TCase *tc = tcase_create("memcpy_tc");

  tcase_add_test(tc, copying_first_6_bytes);

  suite_add_tcase(s, tc);
  return s;
}
