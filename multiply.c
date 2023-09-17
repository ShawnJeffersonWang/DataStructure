//
// Created by 86138 on 2023/9/14.
//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
    int coef;
    int expn;
    struct Node *next;
} Node, *List;

List Creat(int i) {
    List head;
    head = (List) malloc(sizeof(Node));
    List pre, pnew;
    pre = head;
    char a, b;
    for (int j = 0; j <= i; j++) {
        pnew = (List) malloc(sizeof(Node));
        scanf("%c%d,%d%c", &a, &pnew->coef, &pnew->expn, &b);
        pre->next = pnew;
        pre = pnew;
    }
    return head;
}

void Print(List head) {
    List q = head->next->next;
    int flag = 1;
    if (!q) {
        putchar('0');
        printf("\n");
        return;
    }
    while (q) {
        if (q->coef > 0 && flag != 1) {
            putchar('+');
        }
        if (q->coef != 1 && q->coef != -1) {
            printf("%d", q->coef);
            if (q->expn == 1) {
                putchar('X');
            } else if (q->expn) {
                printf("X^%d", q->expn);
            }
        } else {
            if (q->coef == 1) {
                if (!q->expn) {
                    putchar('1');
                } else if (q->expn == 1) {
                    putchar('X');
                } else {
                    printf("X^%d", q->expn);
                }
            }
            if (q->coef == -1) {
                if (!q->expn) {
                    printf("-1");
                } else if (q->expn == 1) {
                    printf("-X");
                } else {
                    printf("-X^%d", q->expn);
                }
            }
        }
        q = q->next;
        flag++;
    }
}

List CopyList(List head) {
    List newHead = (List) malloc(sizeof(Node));
    newHead->next = NULL;
    List p = head->next;
    List p2 = newHead;
    while (p) {
        List new = (List) malloc(sizeof(Node));
        new->coef = p->coef;
        new->expn = p->expn;
        p2->next = new;
        p2 = new;
        p = p->next;
    }
    p2->next = NULL;
    return newHead;
}

List Plus(List head1, List head2) {
    List pre = NULL, p = NULL, qre = NULL, q = NULL;
    pre = head1->next;
    p = head1->next->next;
    qre = head2->next;
    q = head2->next->next;
    int index = 1;
    while (p != NULL) {
        if (q == NULL) {
            return head1;
        }
        if (p->expn == q->expn) {
            p->coef = p->coef + q->coef;
            if (p->coef == 0) {
                pre->next = p->next;
                free(p);
                if (pre) {
                    p = pre->next;
                } else {
                    p = NULL;
                }
                qre->next = q->next;
                free(q);
                if (qre) {
                    q = qre->next;
                } else {
                    q = NULL;
                }
            } else {
                pre = p;
                p = p->next;
                qre->next = q->next;
                free(q);
                if (qre) {
                    q = qre->next;
                } else {
                    q = NULL;
                }
            }
//            printf("4\n");
        } else if (p->expn > q->expn) {
            qre->next = q->next;
            q->next = p;
            pre->next = q;
            pre = q;
            q = qre->next;
        } else if (q->expn > p->expn && p->next && q->expn < (p->next)->expn) {
            qre->next = q->next;
            pre = p;
            p = p->next;
            q->next = p;
            pre->next = q;
            pre = q;
            q = qre->next;
        } else if (q->expn > p->expn && p->next && q->expn >= (p->next)->expn) {
            pre = p;
            p = p->next;
        } else {
            pre = p;
            break;
        }
        index++;
    }
    if (q) {
        pre->next = q;
    }
    return head1;
}

List Multiply(List head1, List head2) {
    List p2 = head2->next->next;
    List newHead = (List) malloc(sizeof(Node));
    List pp = (List) malloc(sizeof(Node));
    newHead->next = pp;
    pp->next = NULL;
    List p1;
    List head1Pre = CopyList(head1);
    List res = NULL;
    while (p2) {
        p1 = head1->next->next;
        while (p1) {
            p1->coef *= p2->coef;
            p1->expn += p2->expn;
            p1 = p1->next;
        }
        p2 = p2->next;
        res = Plus(head1, newHead);
        newHead = CopyList(head1);
        head1 = CopyList(head1Pre);
    }
    return res;
}

int main() {
    int i1, i2;
    List head1, head2;
    scanf("%d", &i1);
    head1 = Creat(i1);
    scanf("%d", &i2);
    head2 = Creat(i2);
    List head = Multiply(head1, head2);
    Print(head);
}