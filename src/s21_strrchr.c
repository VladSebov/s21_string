#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *value = "";
  str = str + 1;
  /* for(s21_size_t i = 0; str[i]!='\0'; i++) {
      if (str[i] == c) last_occurance = i;
  } */
  c++;
  return value;
}