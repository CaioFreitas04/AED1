#include <stdio.h>
#include <stdlib.h>
#include "stringprot.h"

typedef struct string{
    char *arr;
} string;

string *strcreate(unsigned L){
    string *temp;
    temp->arr = (char*) calloc(L, sizeof(char));
    return temp;
}

void addstring(string *str, char *text){
    int i;
    for(i = 0; text[i-1] != '\0'; i++){
        str->arr[i] = text[i];
    }
}

int strlength(string *str){
    int i;
    for(i = 0; str->arr[i] != '\0'; i++)
        ;
    return i;
}

int strcharcount(string *str, char c){
    int i, count;
    for(i = 0, count = 0; str->arr[i] != '\0'; i++){
        if(str->arr[i] == c) count++;
    }
    return count;
}

void strdisplay(string *str){
    int i;
    for(i = 0; str->arr[i] != '\0'; i++){
        printf("%c", str->arr[i]);
    }
}