#include <stdio.h>

struct Student {
    char name[20];
    int year;
    int month;
    int day;
};

void bubbleSort(struct Student arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].year < arr[j + 1].year ||
                (arr[j].year == arr[j + 1].year && arr[j].month < arr[j + 1].month) ||
                (arr[j].year == arr[j + 1].year && arr[j].month == arr[j + 1].month && arr[j].day < arr[j + 1].day)) {
                // 交换两个元素
                struct Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Student students[n];
    int i;
    for (i = 0; i < n; i++) {
        scanf("%s %d %d %d", students[i].name, &students[i].year, &students[i].month, &students[i].day);
    }

    bubbleSort(students, n);

    for (i = 0; i < n; i++) {
        printf("%s\n", students[i].name);
    }

    return 0;
}