#include<stdio.h>
#include<stdlib.h>

typedef struct student {
    int gender;
    char name[50];
    int flag;
} ss;

int main() {
    int N;
    scanf("%d", &N);
    ss *p = (ss *) calloc(N, sizeof(ss));
    for (int i = 0; i < N; i++) {
        scanf("%d %s", &(p + i)->gender, (p + i)->name);
        (p + i)->flag = 1;
    }
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= i; j--) {
            if ((p + i)->gender != (p + j)->gender && (p + j)->flag == 1) {
                printf("%s %s\n", (p + i)->name, (p + j)->name);
                (p + j)->flag = 0;
                break;
            }
        }
    }
    return 0;
}