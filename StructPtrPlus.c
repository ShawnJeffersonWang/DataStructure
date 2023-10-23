#include <stdio.h>
#include <stdlib.h>

//
// Created by shawn on 23-9-4.
//
struct Teacher {
    char *name;
    char **students;
};

void allocateSpace(struct Teacher ***teachers) {
    if (teachers == NULL) {
        return;
    }
    struct Teacher **ts = malloc(sizeof(struct Teacher *) * 3);
    //给每个老师分配内存
    for (int i = 0; i < 3; i++) {
        ts[i] = malloc(sizeof(struct Teacher));
        //给老师的姓名分配内存
        ts[i]->name = malloc(sizeof(char) * 64);
        //给老师起名称
        sprintf(ts[i]->name, "Teacher_%d", i + 1);
        //给学生的数组分配内存
        ts[i]->students = malloc(sizeof(char *) * 4);
        //给学生的姓名开辟内存 以及赋值
        for (int j = 0; j < 4; j++) {
            ts[i]->students[j] = malloc(sizeof(char) * 64);
            sprintf(ts[i]->students[j], "%s_Student_%d", ts[i]->name, j + 1);
        }
    }
    //建立关系
    *teachers = ts;
}

void printTeachers(struct Teacher **teacherArray) {
    if (teacherArray == NULL) {
        return;
    }
    for (int i = 0; i < 3; i++) {
        printf("%s\n", teacherArray[i]->name);
        for (int j = 0; j < 4; ++j) {
            printf("         %s\n", teacherArray[i]->students[j]);
        }
    }
}

void freeSpace(struct Teacher **teacherArray) {
    if (teacherArray == NULL) {
        return;
    }
    for (int i = 0; i < 3; i++) {
        //先释放老师姓名
        if (teacherArray[i]->name != NULL) {
            free(teacherArray[i]->name);
            teacherArray[i]->name = NULL;
        }
        //释放学生姓名
        for (int j = 0; j < 4; j++) {
            if (teacherArray[i]->students[j] != NULL) {
                free(teacherArray[i]->students[j]);
                teacherArray[i]->students[j] = NULL;
            }
        }
        //释放学生的数组
        if (teacherArray[i]->students != NULL) {
            free(teacherArray[i]->students);
            teacherArray[i]->students = NULL;
        }
        //释放老师
        if (teacherArray[i] != NULL) {
            free(teacherArray[i]);
            teacherArray[i] = NULL;
        }
    }
    //释放老师数组
    if (teacherArray != NULL) {
        free(teacherArray);
        teacherArray = NULL;
    }
}

int main() {
//    int arr[5]={1,2,3,4,5};
//    printf("%d\n",&arr[0]);
//    printf("%d\n",arr);
    struct Teacher **teacherArray = NULL;
    allocateSpace(&teacherArray);
    printTeachers(teacherArray);
    freeSpace(teacherArray);
    teacherArray = NULL;
}