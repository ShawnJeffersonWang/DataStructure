//
// Created by shawn on 23-9-18.
//
#include <stdio.h>
//一维数组
//元素类型角度： 数组是相同类型的变量的有序集合
//内存角度： 连续的一大片内存空间
void printArray(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\n", arr[i]);
    }
}

int main() {
    //一维数组名是不是指针？
    int arr[5] = {1, 2, 3, 4, 5};
    printf("%lu\n", sizeof(arr));
    //有两种特殊情况，一位数组名不是指向的一个元素的指针
    //1.sizeof
    //2.对数组名取地址 得到数组指针 步长是整个数组的长度
    printf("%d\n", &arr);
    //退化为指向数组的指针常量，指向整个数组的起始位置
    printf("%d\n", &arr + 1);
    int *ptr = arr;
//    for(int i=0;i<5;i++){
//        printf("%d\n",(ptr+i));
//    }
    int len = sizeof(arr) / sizeof(int);
    printArray(arr, len);
    //arr数组名 它是一个指针常量 指针的指向不可以修改的，而指针指向的值可以改int* const a;
    //arr[0]=100;
    //arr=NULL;
}