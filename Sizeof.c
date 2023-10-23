//
// Created by shawn on 23-9-9.
//
#include <stdio.h>
//宏定义
//内存地址偏移
//取址符
#define MySizeof(value) (char*)(&value+1)-(char*)(&value)

void test01() {
    int i;
    double f;
    double a[4];
    double *q;
    printf("%d\n", MySizeof(i));
    printf("%d\n", MySizeof(f));
    printf("%d\n", MySizeof(a));
    printf("%d\n", MySizeof(q));
}

int main() {
//    int i;
//    printf("%p\n", &i);
//    printf("%p\n", &i + 1);
//    printf("%lu\n", MySizeof(i));
    test01();
    return 0;
}