#include <stdio.h>

//
// Created by shawn on 23-9-18.
//
struct Student {
    char name[64];
    int age;
};

int main() {
    //写在栈上 没有问题
    struct Student s1 = {"Tom", 18};
    struct Student s2 = {"Jerry", 20};
    s1 = s2;
    printf("s1的姓名: %s 年龄: %d\n", s1.name, s1.age);
    printf("s2的姓名: %s 年龄: %d\n", s2.name, s2.age);
}