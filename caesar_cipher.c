#include <stdio.h>

void caesar_cipher(int offset, char *text) {
    int i = 0;
    while (text[i] != '\0') {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + offset) % 26 + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + offset) % 26 + 'a';
        }
        i++;
    }
}

int main() {
    int offset;
    char text[100];
    scanf("%d", &offset);
    scanf("%s", text);
    caesar_cipher(offset, text);
    printf("%s\n", text);
}