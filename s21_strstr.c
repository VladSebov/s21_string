#include "s21_string.h"
#include <stdio.h>


//поиск в  haystack строки needle
char *strstr(const char *haystack, const char *needle)
{
   char *result = NULL; // Инициализируем указатель result значением NULL, если совпадение не будет найдено
   if (s21_strlen(haystack) == s21_strlen(needle) && s21_strlen(needle) == 0)
   {
      result = (char *)"";
   }
   while (*haystack)
   {
      const char *h = haystack;
      const char *n = needle;

      // Пока символы совпадают и не достигнут конец строки needle
      while (*h && *n && *h == *n)
      {
         h++;
         n++;
      }

      // Если достигнут конец строки needle, значит совпадение найдено
      if (!*n)
      {
         result = (char *)haystack;
         break; // Нашли совпадение - выходим из цикла
      }

      haystack++; // шагаем по строке
   }

   return result; // Возвращаем найденное совпадение или NULL, если ничего не было найдено
}