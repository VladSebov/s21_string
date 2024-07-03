#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i = 0;
  while (i < s21_strlen(str1)) {
    if (s21_memchr(str2, *(str1 + i), s21_strlen(str2)) == s21_NULL) {
      i++;
    } else {
      break;
    }
  }
  return (i);
}