//
// Created by shawn on 23-10-11.
//
#include <stdio.h>
#include <stdlib.h>

// 函数指针类型
typedef int (*Predicate)(int);

typedef char *(*Function)(int);

// 过滤函数，接收一个数组、数组长度和函数指针，对数组中的元素进行过滤，并返回过滤后的结果数组
int *filter(int *array, int length, Predicate predicate, int *resultLength) {
    int *result = (int *) malloc(length * sizeof(int));
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (predicate(array[i])) {
            result[count++] = array[i];
        }
    }
    *resultLength = count;
    return result;
}

// 转换函数，接收一个数组和数组长度，对数组中的元素进行转换，并返回转换后的结果数组
char **map(int *array, int length, Function function) {
    char **result = (char **) malloc(length * sizeof(char *));
    for (int i = 0; i < length; i++) {
        result[i] = function(array[i]);
    }
    return result;
}

// 回调函数示例：判断一个数是否为偶数
int isEven(int num) {
    return num % 2 == 0;
}

// 回调函数示例：判断一个数是否为正数
int isPositive(int num) {
    return num > 0;
}

// 回调函数示例：将一个数转换为字符串
char *intToString(int num) {
    char *str = (char *) malloc(20 * sizeof(char));
    sprintf(str, "Number: %d", num);
    return str;
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(array) / sizeof(array[0]);

    // 使用函数指针进行过滤和转换
    int resultLength;
    int *filteredNumbers = filter(array, length, isEven, &resultLength);
    char **convertedNumbers = map(filteredNumbers, resultLength, intToString);

    // 打印结果
    for (int i = 0; i < resultLength; i++) {
        printf("%s\n", convertedNumbers[i]);
        free(convertedNumbers[i]);
    }

    // 释放内存
    free(filteredNumbers);
    free(convertedNumbers);

    return 0;
}