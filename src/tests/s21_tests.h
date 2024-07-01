#ifndef S21_TESTS_H
#define S21_TESTS_H

#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

int run_tests(Suite **suits_set);

void test_memchr(const void *tested_string, int tested_char, s21_size_t n);
void test_memcmp(const void *string_1, const void *string_2, s21_size_t n);
void test_memcpy(void *dest, const void *src, s21_size_t n);
void test_memset(void *str, int c, s21_size_t n);
void test_strchr(const char *str, int c);
void test_strcspn(const char *string_1, const char *string_2);
void test_strerror(int errnum);
void test_strlen(const char *tested_string);
void test_strncat(char *dest, const char *src, s21_size_t n);
void test_strncmp(const char *string_1, const char *string_2, s21_size_t n);
void test_strncpy(char *dest, const char *src, s21_size_t n);
void test_strpbrk(const char *string_1, const char *string_2);
void test_strrchr(const char *tested_string, int tested_char);
void test_strstr(const char *haystack, const char *needle);
void test_strtok(char *tested_string, const char *delim);

Suite *memchr_suite(void);
Suite *memcmp_suite(void);
Suite *memcpy_suite(void);
Suite *memset_suite(void);
Suite *strncat_suite(void);
Suite *strchr_suite(void);
Suite *strncmp_suite(void);
Suite *strcspn_suite(void);
Suite *strerror_suite(void);
Suite *strlen_suite(void);
Suite *strncpy_suite(void);
Suite *strpbrk_suite(void);
Suite *strrchr_suite(void);
Suite *strstr_suite(void);
Suite *strtok_suite(void);
Suite *sprintf_suite(void);
Suite *to_upper_suite(void);
Suite *to_lower_suite(void);
Suite *insert(void);
Suite *trim(void);

#endif