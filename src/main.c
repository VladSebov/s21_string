#include <stdlib.h>

#include "tests/s21_tests.h"

int main() {
  Suite *suits_set[] = {memchr_suite(),
                        memcmp_suite(),
                        memcpy_suite(),
                        memset_suite(),
                        strchr_suite(),
                        strcspn_suite(),
                        strlen_suite(),
                        strncat_suite(),
                        strncmp_suite(),
                        strncpy_suite(),
                        strpbrk_suite(),
                        strrchr_suite(),
                        strstr_suite(),
                        strtok_suite(),
                        NULL};
  return (run_tests(suits_set) == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int run_tests(Suite **suits_set) {
  int failed = 0;
  for (int i = 0; suits_set[i] != NULL; i++) {
    SRunner *runner = srunner_create(suits_set[i]);
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
  }
  return failed;
}