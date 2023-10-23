#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int val;
} Triple;

void sparse_matrix_add_sub(Triple *A, int len_A, Triple *B, int len_B, char op, Triple **result, int *len_result) {
    int i = 0, j = 0, k = 0;
    int max_len = len_A + len_B;
    *result = (Triple *) malloc(max_len * sizeof(Triple));

    while (i < len_A && j < len_B) {
        if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            if (op == '+') {
                (*result)[k].row = A[i].row;
                (*result)[k].col = A[i].col;
                (*result)[k].val = A[i].val;
            } else if (op == '-') {
                (*result)[k].row = A[i].row;
                (*result)[k].col = A[i].col;
                (*result)[k].val = A[i].val;
            }
            i++;
        } else if (A[i].row > B[j].row || (A[i].row == B[j].row && A[i].col > B[j].col)) {
            if (op == '+') {
                (*result)[k].row = B[j].row;
                (*result)[k].col = B[j].col;
                (*result)[k].val = B[j].val;
            } else if (op == '-') {
                (*result)[k].row = B[j].row;
                (*result)[k].col = B[j].col;
                (*result)[k].val = -B[j].val;
            }
            j++;
        } else {
            if (op == '+') {
                if (A[i].val + B[j].val == 0) {
                    i++;
                    j++;
                    continue;
                }
                (*result)[k].row = A[i].row;
                (*result)[k].col = A[i].col;
                (*result)[k].val = A[i].val + B[j].val;
            } else if (op == '-') {
                if (A[i].val - B[j].val == 0) {
                    i++;
                    j++;
                    continue;
                }
                (*result)[k].row = A[i].row;
                (*result)[k].col = A[i].col;
                (*result)[k].val = A[i].val - B[j].val;
            }
            i++;
            j++;
        }
        k++;
    }

    while (i < len_A) {
        if (op == '+') {
            (*result)[k].row = A[i].row;
            (*result)[k].col = A[i].col;
            (*result)[k].val = A[i].val;
        } else if (op == '-') {
            (*result)[k].row = A[i].row;
            (*result)[k].col = A[i].col;
            (*result)[k].val = -A[i].val;
        }
        i++;
        k++;
    }

    while (j < len_B) {
        if (op == '+') {
            (*result)[k].row = B[j].row;
            (*result)[k].col = B[j].col;
            (*result)[k].val = B[j].val;
        } else if (op == '-') {
            (*result)[k].row = B[j].row;
            (*result)[k].col = B[j].col;
            (*result)[k].val = -B[j].val;
        }
        j++;
        k++;
    }

    *len_result = k;
}

int main() {
    int m_A, n_A, len_A;
    scanf("%d%d%d", &m_A, &n_A, &len_A);
    Triple *A = (Triple *) malloc(len_A * sizeof(Triple));
    for (int i = 0; i < len_A; i++) {
        scanf(" (%d,%d,%d)", &(A[i].row), &(A[i].col), &(A[i].val));
    }

    int m_B, n_B, len_B;
    scanf("%d%d%d", &m_B, &n_B, &len_B);
    Triple *B = (Triple *) malloc(len_B * sizeof(Triple));
    for (int i = 0; i < len_B; i++) {
        scanf(" (%d,%d,%d)", &(B[i].row), &(B[i].col), &(B[i].val));
    }

    Triple *result_add;
    int len_result_add;
    sparse_matrix_add_sub(A, len_A, B, len_B, '+', &result_add, &len_result_add);
    printf("%d %d %d\n", m_A, n_A, len_result_add);
    for (int i = 0; i < len_result_add; i++) {
        printf("(%d,%d,%d)", result_add[i].row, result_add[i].col, result_add[i].val);
    }
    printf("\n");

    Triple *result_sub;
    int len_result_sub;
    sparse_matrix_add_sub(A, len_A, B, len_B, '-', &result_sub, &len_result_sub);
    printf("%d %d %d\n", m_A, n_A, len_result_sub);
    for (int i = 0; i < len_result_sub; i++) {
        printf("(%d,%d,%d)", result_sub[i].row, result_sub[i].col, result_sub[i].val);
    }
    printf("\n");

    free(A);
    free(B);
    free(result_add);
    free(result_sub);

    return 0;
}