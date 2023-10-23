//
// Created by shawn on 23-9-18.
//
#include <stdio.h>

//函数指针 指向了函数的指针
//什么是函数指针？
//指针函数 函数返回值是指针的函数

//函数名称的本质就是一个函数指针
//可以利用函数指针 调用函数
typedef int (*Comparator)(int, int);

int compareAscending(int a, int b) {
    return a - b;
}

int compareDescending(int a, int b) {
    return b - a;
}

void bubbleSort(int *arr, int n, Comparator cmp) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cmp(arr[j], arr[j + 1]) > 0) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    //函数指针做函数参数（回调函数）

    //提供一个打印函数，可以打印任意类型的数据
    int arr[] = {5, 2, 9, 1, 7};
    int length = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, length, compareAscending);
    printf("Ascending order: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bubbleSort(arr, length, compareDescending);
    printf("Descending order: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
//这样写forEach只能干一件事，就是打印每个元素
//如果外界想拿到每个元素做一些别的操作，forEach就不能用了，
// 能不能把要做的事情不写死在方法内，而是通过方法的参数传递进来
//Java中要做这件事就是转递进来一个函数式接口
//forEach能给函数式接口提供什么 函数式接口给forEach返回什么