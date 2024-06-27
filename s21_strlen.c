#include "s21_string.h"
#include <stdio.h>

size_t  my_strlen(char *str){
    size_t i =0;
    while(str[i] != '\0') i++;
    
    //printf("HELLO!!\n");
        return i;
}

char *strstr(const char *haystack, const char *needle){
    int i =0;
    while (haystack[i] != needle[0]){
        i++;
    }
}