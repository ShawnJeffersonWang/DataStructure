#include <stdio.h>

//
// Created by shawn on 23-9-3.
//
void test01() {
    //可读性高
    int arr[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
    };
    int arr2[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    //行3是可以省略的
    int arr3[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    //除了两种特殊情况外，二维数组名称是指向第一个一维数组 的数组指针
    //特殊情况1 sizeof
    //特殊情况2 对数组名取地址&arr 获取的是二维数组的数组指针 int(*p)[3][3]=&arr
    printf("%d\n", sizeof(arr));
//    printf("%d\n",&arr);
//    printf("%d\n",&arr+1);
    int(*arrayPtr)[3] = arr;
    int (*p)[3][3] = &arr;
    //访问二维数组中的6这个元素
    printf("%d\n", arr[1][2]);
    printf("%d\n", *(*(arrayPtr + 1) + 2));
}

//array[3][3]等价于一维数组的指针 int(*array)[3]
//void printArray(int (*array)[3], int row, int column) {
//void printArray(int array[][3], int row, int column) {
void printArray(int array[3][3], int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
//            printf("%d ",array[i][j]);
            printf("%d ", *(*(array + i) + j));
        }
        printf("\n");
    }
}

//二维数组做函数参数
void test02() {
    int arr[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
    };
    printArray(arr, 3, 3);
}
//数组指针：指向数组的指针
//指针数组：由指针组成数组
int main() {
    test01();
    test02();
}