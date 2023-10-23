#include <string.h>
#include <stdio.h>

//
// Created by shawn on 23-9-21.
//
const char *strca(const char *a, const char *b);

int main() {
    const char *a = "ac";
    const char *b = "ab";
    printf("%s", strca(a, b));
}

const char *strca(const char *a, const char *b) {
    char* result=(char*)a;
    while(*result!='\0'){
        result++;
    }
    while (*b != '\0') {
        *result=*b;
        result++;
        b++;
    }
    *result='\0';
    return a;
}