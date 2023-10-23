//
// Created by shawn on 23-9-4.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Student {
    char *name;
    int age;
};

struct Student **allocateSpace() {
    struct Student **temp = malloc(sizeof(struct Student *) * 3);
    for (int i = 0; i < 3; i++) {
        temp[i] = malloc(sizeof(struct Student));
        temp[i]->name = malloc(sizeof(char) * 64);
        sprintf(temp[i]->name, "name_%d", i + 1);
        temp[i]->age = 18 + i;
    }
    return temp;
}

void printPerson(struct Student **personArray, int len) {
    for (int i = 0; i < len; i++) {
        printf("姓名: %s 年龄: %d\n", personArray[i]->name, personArray[i]->age);
    }
}

void freeSpace(struct Student **personArray, int len) {
    if (personArray == NULL) {
        return;
    }
    if (len <= 0) {
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (personArray[i]->name != NULL) {
            free(personArray[i]->name);
            personArray[i]->name = NULL;
        }
        free(personArray[i]);
        personArray[i] = NULL;
    }
    free(personArray);
    personArray = NULL;
}

int main() {
    struct Student **personArray = NULL;
    personArray = allocateSpace();
    //打印数组
    printPerson(personArray, 3);
    //释放内存
    freeSpace(personArray, 3);
    personArray = NULL;
    int arr[5] = {1, 2, 3, 4, 5};
    printf("%d\n", *arr);
    char *p = malloc(sizeof(char) * 10);
    char *q = malloc(sizeof(char) * 10);
    strcpy(p, "wang");
    strcpy(q, "wang");
    if (strcpy(p, q)) {
        printf("相等");
    } else {
        printf("不等");
    }
}