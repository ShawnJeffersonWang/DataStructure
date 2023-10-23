#include<stdio.h>

#define MAXSIZE 1000
typedef struct {
    int row, col;
    int val;
} Triple;

typedef struct {
    int row, col, nums;
    Triple data[MAXSIZE + 1];
} TSMatrix;

//比较三元组a,b的位置
//相同，返回0
//a在b前，返回-1；b在a前，返回1；
int cmp(Triple a, Triple b) {
    if (a.row == b.row) {
        if (a.col == b.col) {
            return 0;
        } else if (a.col < b.col) {
            return -1;
        } else {
            return 1;
        }
    } else if (a.row < b.row) {
        return -1;
    } else {
        return 1;
    }
}

void addMatrices(TSMatrix A, TSMatrix B, TSMatrix *C) {
    int p = 1, q = 1;
    C->nums = 0;
    while (p <= A.nums && q <= B.nums) {
        if (cmp(A.data[p], B.data[q]) == -1) {
            C->data[C->nums].row = A.data[p].row;
            C->data[C->nums].col = A.data[p].col;
            C->data[C->nums++].val = A.data[p].val;
            p++;
        }
        if (cmp(A.data[p], B.data[q]) == 1) {
            C->data[C->nums].row = B.data[q].row;
            C->data[C->nums].col = B.data[q].col;
            C->data[C->nums++].val = B.data[q].val;
            q++;
        }
        if (cmp(A.data[p], B.data[q]) == 0) {
            if (A.data[p].val + B.data[q].val) {
                C->data[C->nums].row = A.data[p].row;
                C->data[C->nums].col = A.data[p].col;
                C->data[C->nums++].val = A.data[p].val + B.data[q].val;
            }
            p++;
            q++;
        }
    }
    C->row = A.row;
    C->col = A.col;
    while (p <= A.nums) {
        C->data[C->nums].row = A.data[p].row;
        C->data[C->nums].col = A.data[p].col;
        C->data[C->nums++].val = A.data[p].val;
        p++;

    }
    while (q <= B.nums) {
        C->data[C->nums].row = B.data[q].row;
        C->data[C->nums].col = B.data[q].col;
        C->data[C->nums++].val = B.data[q].val;
        q++;
        C->row = B.row;
        C->col = B.col;
    }

}

void subtractMatrices(TSMatrix A, TSMatrix B, TSMatrix *D) {
    for (int i = 1; i <= B.nums; i++) {
        B.data[i].val *= -1;
    }
    addMatrices(A, B, D);
}

int main() {
    TSMatrix A, B, C, D;
    int k;
    scanf("%d%d%d", &A.row, &A.col, &A.nums);
    for (k = 1; k <= A.nums; k++) {
        scanf(" (%d,%d,%d)", &A.data[k].row, &A.data[k].col, &A.data[k].val);
    }


    scanf("%d%d%d", &B.row, &B.col, &B.nums);
    for (k = 1; k <= B.nums; k++) {
        scanf(" (%d,%d,%d)", &B.data[k].row, &B.data[k].col, &B.data[k].val);
    }

    addMatrices(A, B, &C);
    printf("%d %d %d\n", C.row, C.col, C.nums);
    for (k = 0; k < C.nums; k++) {
        printf("(%d,%d,%d)", C.data[k].row, C.data[k].col, C.data[k].val);
    }
    printf("\n");

    subtractMatrices(A, B, &D);
    printf("%d %d %d\n", D.row, D.col, D.nums);
    for (k = 0; k < D.nums; k++) {
        printf("(%d,%d,%d)", D.data[k].row, D.data[k].col, D.data[k].val);
    }
    printf("\n");
    return 0;
}

