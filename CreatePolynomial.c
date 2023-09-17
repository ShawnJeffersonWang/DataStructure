#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int coef;
    int expo;
    struct node *next;
} Node;

Node *createPolynomial(int n);

void printPolynomial(Node *head);

int main() {
    int n;
    scanf("%d", &n);
    Node *head = createPolynomial(n);
    printPolynomial(head);
    return 0;
}

Node *createPolynomial(int n) {
    Node *head = malloc(sizeof(Node));
    Node *newNode;
    Node *prev = head;
    for (int i = 0; i < n; i++) {
        newNode = malloc(sizeof(Node));
        scanf(" (%d,%d)", &(newNode->coef), &(newNode->expo));
        prev->next = newNode;
        prev = newNode;
    }
    newNode->next = NULL;
    return head;
}

void printPolynomial(Node *head) {
    Node *cur = head->next;
    if (cur->expo == 0) {
        printf("%d", cur->coef);
    } else if (cur->expo == 1) {
        printf("%dX", cur->coef);
    } else {
        printf("%dX^%d", cur->coef, cur->expo);
    }
    cur = cur->next;
    while (cur) {
        if (cur->coef > 0) {
            if (cur->expo == 0) {
                printf("%d", cur->coef);
            } else if (cur->expo == 1) {
                printf("+%dX", cur->coef);
            } else {
                printf("+%dX^%d", cur->coef, cur->expo);
            }
        } else if (cur->coef < 0) {
            if (cur->expo == 0) {
                printf("%d", cur->coef);
            } else if (cur->expo == 1) {
                printf("%dX", cur->coef);
            } else {
                printf("%dX^%d", cur->coef, cur->expo);
            }
        }
        cur = cur->next;
    }
}

