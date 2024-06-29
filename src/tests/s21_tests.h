#ifndef S21_TESTS_H
#define S21_TESTS_H

#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

void act_and_assert(const char *tested_string);

Suite *strlen_suite(void);

#endif