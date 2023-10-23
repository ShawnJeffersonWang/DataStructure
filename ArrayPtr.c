#include <stdio.h>

//
// Created by shawn on 23-9-3.
//

void test03() {
    //直接定义数组指针变量
    int arr[5] = {1, 2, 3, 4, 5};
    int (*p)[5] = &arr;
    for (int i = 0; i < 5; i++) {
        printf("%d\n", (*p)[i]);
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    //代表存放5个int类型元素的数组 的数组类型
    typedef int(ARRAY_TYPE)[5];
    ARRAY_TYPE arr2;
//    for(int i=0;i<5;i++){
//        arr2[i]=100+i;
//    }
//    for(int i=0;i<5;i++){
//        printf("%d\n",arr2[i]);
//    }
    ARRAY_TYPE *arrayPtr = &arr;
    //*arrayPtr==arr==数组名
    for (int i = 0; i < 5; i++) {
        printf("%d\n", (*arrayPtr)[i]);
    }
    //先定义数组指针类型，再通过类型定义数组指针
    typedef int(*ARRAY_PTR_TYPE)[5];
    ARRAY_PTR_TYPE arrP = &arr;
    for (int i = 0; i < 5; i++) {
        printf("%d\n", *(arrP)[i]);
    }
    test03();
}