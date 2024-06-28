#include "s21_string.h"
#include <stdio.h>

size_t  my_strlen(char *str){
    size_t i =0;
    while(str[i] != '\0') i++;
    
    //printf("HELLO!!\n");
        return i;
}

