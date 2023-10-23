//
// Created by shawn on 23-9-3.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//实现对任意数据类型数组进行排序 利用选择排序 对比功能由用户指定 利用回调函数技术来实现对比
void selectSort(void *addr, int elementSize, int len, int(*myCompare)(void *, void *)) {
    char *temp = malloc(sizeof(char) * elementSize);
    for (int i = 0; i < len - 1; i++) {
        //最大值或最小值下标
        int minOrMax = i;
        for (int j = i + 1; j < len; j++) {
            char *jPtr = (char *) addr + elementSize * j;
            char *minOrMaxPtr = (char *) addr + elementSize * minOrMax;
            //1.从小到大还是从大到小符号无法确定 2.addr是void*类型的，不可能通过索引取一个void的元素
            //if (myCompare(addr[j] < addr[minOrMax])
            if (myCompare(jPtr, minOrMaxPtr)) {
                //更新最小值或者最大值下标
                minOrMax = j;
            }
        }
        if (minOrMax != i) {
            //交换i和minOrMax下标元素
            char *iPtr = (char *) addr + elementSize * i;
            char *minOrMaxPtr = (char *) addr + elementSize * minOrMax;
            memcpy(temp, iPtr, elementSize);
            memcpy(iPtr, minOrMaxPtr, elementSize);
            memcpy(minOrMaxPtr, temp, elementSize);
        }
    }
    if (temp != NULL) {
        free(temp);
        temp = NULL;
    }
}

int myCompareInt(void *data1, void *data2) {
    int *num1 = data1;
    int *num2 = data2;
    if (*num1 < *num2) {
        return 1;
    }
    return 0;
}

struct Student {
    char name[64];
    int age;
};

int myComparePerson(void *data1, void *data2) {
    struct Student *p1 = data1;
    struct Student *p2 = data2;
//    if (p1->age<p2->age){
//        return 1;
//    }
//    return 0;
    return p1->age < p2->age;
}

int main() {
    int arr[] = {10, 30, 20, 60, 50, 40};
    int len1 = sizeof(arr) / sizeof(int);
    selectSort(arr, sizeof(int), len1, myCompareInt);
    for (int i = 0; i < len1; i++) {
        printf("%d\n", arr[i]);
    }

    struct Student personArray[] = {
            {"aaa", 10},
            {"bbb", 40},
            {"ccc", 20},
            {"ddd", 30},
    };
    int len2 = sizeof(personArray) / sizeof(struct Student);
    selectSort(personArray, sizeof(struct Student), len2, myComparePerson);
    for (int i = 0; i < len2; i++) {
        printf("姓名: %s 年龄: %d\n", personArray[i].name, personArray[i].age);
    }
}