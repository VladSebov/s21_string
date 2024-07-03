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

START_TEST(n_is_zero) {
    test_memchr("", '\0', 0);
} END_TEST

START_TEST(find_terminated_null_in_string) {
    test_memchr("string", '\0', 7);
} END_TEST

START_TEST(occurance_in_the_end_of_string) {
    test_memchr("stringA", 'A', 7);
} END_TEST

START_TEST(find_num_in_string) {
    test_memchr("Str55333222ingA", '3', 15);
} END_TEST

START_TEST(find_byte_in_int_array) {
    int array[] = {1, 2, 3, 666, 5, 99, 100};
    s21_size_t n = sizeof(int) * 7;
    int byte = 666;
    test_memchr(array, byte, n);
} END_TEST


START_TEST(find_byte_in_double_array) {
    double array[] = {1.5, 2.65, 3.3456, 666.0, 5.01};
    s21_size_t n = sizeof(double) * 5;
    int byte = 666;
    test_memchr(array, byte, n);
} END_TEST

START_TEST(occurance_is_null) {
    test_memchr("array", 'c', 5);
} END_TEST

START_TEST(find_newline_in_string) {
    test_memchr("arr\nay", '\n', 5);
} END_TEST

Suite *memchr_suite(void) {
  Suite *s = suite_create("memchr_suite");
  TCase *tc = tcase_create("memchr_tc");

  tcase_add_test(tc, occurance_is_not_null);
  tcase_add_test(tc, n_is_zero);
  tcase_add_test(tc, find_terminated_null_in_string);
  tcase_add_test(tc, occurance_in_the_end_of_string);
  tcase_add_test(tc, find_num_in_string);
  tcase_add_test(tc, find_byte_in_int_array);
  tcase_add_test(tc, find_byte_in_double_array);
  tcase_add_test(tc, occurance_is_null);
  tcase_add_test(tc, find_newline_in_string);


  suite_add_tcase(s, tc);
  return s;
}
