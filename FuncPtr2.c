//
// Created by shawn on 23-9-18.
//
#include <stdio.h>
#include <stdlib.h>

// 定义一个函数指针类型，用于表示接受一个任意类型的数组和数组长度的函数
typedef void (*ArrayConsumer)(void*, int);

// 接受一个任意类型的数组和数组长度，并执行用户提供的操作
void accept(ArrayConsumer consumer, void* arr, int length) {
    //这里有了面向对象的雏形，类似于多态在运行时动态绑定方法
    consumer(arr, length);
}
//printIntArray,printFloatArray,sortIntArray,sortFloatArray,printEmployeeArray等方法有相同的函数名和返回值
// 类似于Java中的接口Interface，类似于都继承了ArrayConsumer接口并重写了consumer方法
// 示例操作函数：打印整数数组
void printIntArray(void* arr, int length) {
    int* intArr = (int*)arr;

    printf("Array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", intArr[i]);
    }
    printf("\n");
}

// 示例操作函数：打印浮点数数组
void printFloatArray(void* arr, int length) {
    float* floatArr = (float*)arr;

    printf("Array: ");
    for (int i = 0; i < length; i++) {
        printf("%f ", floatArr[i]);
    }
    printf("\n");
}

// 示例操作函数：排序整数数组（使用冒泡排序算法）
void sortIntArray(void* arr, int length) {
    int* intArr = (int*)arr;

    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (intArr[j] > intArr[j + 1]) {
                int temp = intArr[j];
                intArr[j] = intArr[j + 1];
                intArr[j + 1] = temp;
            }
        }
    }
}

// 示例操作函数：排序浮点数数组（使用冒泡排序算法）
void sortFloatArray(void* arr, int length) {
    float* floatArr = (float*)arr;

    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (floatArr[j] > floatArr[j + 1]) {
                float temp = floatArr[j];
                floatArr[j] = floatArr[j + 1];
                floatArr[j + 1] = temp;
            }
        }
    }
}

// 示例结构体类型
typedef struct {
    int id;
    char name[20];
    float salary;
} Employee;

// 示例操作函数：打印员工数组
void printEmployeeArray(void* arr, int length) {
    Employee* employeeArr = (Employee*)arr;

    printf("Employee Array:\n");
    for (int i = 0; i < length; i++) {
        printf("ID: %d, Name: %s, Salary: %f\n", employeeArr[i].id, employeeArr[i].name, employeeArr[i].salary);
    }
}

int main() {
    int intArr[] = {4, 2, 5, 1, 3};
    float floatArr[] = {4.4, 2.2, 5.5, 1.1, 3.3};
    Employee employeeArr[] = {
            {101, "John", 5000.0},
            {102, "Alice", 6000.0},
            {103, "Bob", 4500.0},
            {104, "Jane", 5500.0},
            {105, "Mike", 4000.0}
    };
    int length = sizeof(intArr) / sizeof(intArr[0]);

    accept(printIntArray, intArr, length);
    accept(sortIntArray, intArr, length);
    accept(printIntArray, intArr, length);

    printf("\n");

    accept(printFloatArray, floatArr, length);
    accept(sortFloatArray, floatArr, length);
    accept(printFloatArray, floatArr, length);

    printf("\n");

    accept(printEmployeeArray, employeeArr, length);

    return 0;
}