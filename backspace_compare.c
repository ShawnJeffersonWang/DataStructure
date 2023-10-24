#include <stdio.h>
#include <string.h>

void processString(char *str) {
    int stackIndex = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '#') {
            str[stackIndex] = str[i];
            stackIndex++;
        } else if (stackIndex > 0) {
            stackIndex--;
        }
    }
    str[stackIndex] = '\0';
}

int backspaceCompare(char *s, char *t) {
    processString(s);
    processString(t);
    return strcmp(s, t) == 0;
}

int main() {
    char s1[] = "ab##a#b";
    char t1[] = "c#d#ab";
    printf("%s\n", backspaceCompare(s1, t1) ? "true" : "false");
}