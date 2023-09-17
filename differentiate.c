//
// Created by 86138 on 2023/9/14.
//
#include<stdio.h>

int main() {
    int n;
    int a[100][3];
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++) {
        scanf("(%d,%d)", &a[i][1], &a[i][2]);
    }
    for (int i = 1; i <= n; i++) {
        a[i][1] *= a[i][2];
        a[i][2] -= 1;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i][1] == 0)
            continue;
        else
            printf("%d", a[i][1]);
        if (a[i][2] == 0)
            printf("");
        else if (a[i][2] == 1)
            printf("X");
        else
            printf("X^%d", a[i][2]);
        if (i != n && a[i + 1][1] > 0)
            printf("+");
    }
}