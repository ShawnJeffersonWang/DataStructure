#include <stdio.h>

int main() {
    int endYear;
    scanf("%d", &endYear);
    if (endYear <= 2000 || endYear > 2099) {
        printf("Invalid year!\n");
        return 0;
    }
    int isLeapYear = 0;
    for (int year = 2004; year <= endYear; year++) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            printf("%d\n", year);
            isLeapYear = 1;
        }
    }
    if (!isLeapYear) {
        printf("None\n");
    }
    return 0;
}