#include <stdio.h>
#include <string.h>
#include "s21_string.h"

int main(void) {
  char str[] = "Fly...away...in....the midnight air";
  char ch[] = "...";

  char *strtok_res = s21_strtok(str, ch);
  printf("%s\n", strtok_res);
  return 0;
}