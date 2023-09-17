//
// Created by 86138 on 2023/9/6.
//
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;
typedef struct {
    ElemType elem[MAXSIZE];
    int length;
} SeqList;

void DeleteX(SeqList *q, ElemType x) {
    int count = 0;
    for (int i = 0; i < q->length; i++) {
        if (q->elem[i] == x) {
            count++;
        } else {
            q->elem[i - count] = q->elem[i];
        }
    }
}