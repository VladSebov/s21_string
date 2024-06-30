#include <stdlib.h>

#include "tests/s21_tests.h"

int main() {
  int failed = 0;
  Suite *s = strrchr_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}