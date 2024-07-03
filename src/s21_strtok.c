#include "s21_string.h"
#include <stdio.h>

char *s21_strtok(char *str, const char *delim) {
  static char *token_pointer = s21_NULL;
  if (str != s21_NULL) token_pointer = str;
  char *delim_pointer = s21_strstr(token_pointer,delim);
  //if (delim_pointer!=s21_NULL) printf("delim pointer:%s\n",delim_pointer);
  //if (token_pointer!=s21_NULL) printf("token pointer:%s\n",token_pointer);
  if (delim_pointer!=s21_NULL) delim_pointer[0] = '\0';
  return token_pointer;
  }
/*
find_first_token()
find_token_after_first
*/