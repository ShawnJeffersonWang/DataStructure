//
// Created by shawn on 23-9-18.
//

#include <stdio.h>

#define MySizeof(value) (char*)(&value+1)-(char*)(&value)

int main() {
    int i;
    double f;
    double a[4];
    double *q;
    printf("%d\n", MySizeof(i));
    printf("%d\n", MySizeof(f));
    printf("%d\n", MySizeof(a));
    printf("%d\n", MySizeof(q));
    return 0;
}