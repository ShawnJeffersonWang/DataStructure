//
// Created by 86138 on 2023/9/17.
//
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    int password;
    struct node *next;
} Node;

Node *Create();

int n, m;            //创建约瑟夫环
void Josephus(Node *tail);

int main(void) {
    Node *tail;
    tail = Create();
    Josephus(tail);
}

Node *Create() {
    Node *tail = NULL, *p;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        p = (Node *) malloc(sizeof(Node));
        if (!tail) {
            tail = p->next = p;
            p->data = i + 1;
            scanf("%d", &p->password);
        } else {
            p->data = i + 1;
            scanf("%d", &p->password);
            p->next = tail->next;
            tail = tail->next = p;
        }
    }
    return tail;
}

void Josephus(Node *tail) {
    int i = 0;
    Node *p = NULL;
    while (n) {
        i = (i + 1) % m;
        if (i)
            tail = tail->next;
        else {
            p = tail->next;
            tail->next = p->next;
            printf("%d ", p->data);
            m = p->password;
            free(p);
            n--;
            i = 0;
        }
    }
}