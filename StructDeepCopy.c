//
// Created by shawn on 23-9-18.
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Student {
    char *name;
    int age;
};

int main() {
    struct Student s1;
    s1.name = malloc(sizeof(char) * 64);
    strcpy(s1.name, "Tom");
    s1.age = 18;
    struct Student s2;
    s2.name = malloc(sizeof(char) * 128);
    strcpy(s2.name, "Jerry");
    s2.age = 28;
    s1 = s2;
    printf("s1的姓名: %s 年龄: %d\n", s1.name, s1.age);
    printf("s2的姓名: %s 年龄: %d\n", s2.name, s2.age);
    if (s1.name != NULL) {
        free(s1.name);
        s1.name = NULL;
    }
    if (s2.name != NULL) {
        free(s2.name);
        s2.name = NULL;
    }
}