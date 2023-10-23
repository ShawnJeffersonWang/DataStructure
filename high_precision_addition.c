#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 10001

void reverse_str(char *str) {
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void high_precision_addition(char *a, char *b, char *sum) {
    int len_a = strlen(a);
    int len_b = strlen(b);

    if (len_a < len_b) {
        char *temp = a;
        a = b;
        b = temp;

        int temp_len = len_a;
        len_a = len_b;
        len_b = temp_len;
    }
    int carry = 0;
    for (int i = 0; i < len_a; i++) {
        int digit_a = i < len_a ? a[len_a - 1 - i] - '0' : 0;
        int digit_b = i < len_b ? b[len_b - 1 - i] - '0' : 0;
        int ab_sums = digit_a + digit_b + carry;
        int sum_digit = ab_sums % 10;
        carry = ab_sums / 10;
        sum[i] = sum_digit + '0';
    }
    if (carry > 0) {
        sum[len_a] = carry + '0';
        sum[len_a + 1] = '\0';
    } else {
        sum[len_a] = '\0';
    }
    reverse_str(sum);
}

int main() {
    char a[MAX_LENGTH];
    char b[MAX_LENGTH];
    char sum[MAX_LENGTH + 1];
    scanf("%s", a);
    scanf("%s", b);
    high_precision_addition(a, b, sum);
    printf("%s\n", sum);
    return 0;
}