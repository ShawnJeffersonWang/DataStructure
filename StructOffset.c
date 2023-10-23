#include <stdio.h>
#include <stddef.h>

//
// Created by shawn on 23-9-4.
//
struct Teacher {
    char a;
    int b;
};

void test01() {
    struct Teacher t1;
    struct Teacher *p = &t1;
    printf("b的属性偏移量: %lu\n", (int) &(p->b) - (int) p);
    printf("b的属性偏移量: %lu\n", offsetof(struct Teacher, b));
}

//通过偏移量 操作内存
void test02() {
    struct Teacher t1 = {'a', 10};
    printf("t1.b=%d\n", *(int *) ((char *) &t1 + offsetof(struct Teacher, b)));
    printf("t1.b=%d\n", *(int *) ((int *) &t1 + 1));
}

struct Teacher2 {
    char a;
    int b;
    struct Teacher c;
};

void test03() {
    struct Teacher2 t1 = {'a', 10, 'b', 20};
    int offset1 = offsetof(struct Teacher2, c);
    int offset2 = offsetof(struct Teacher, b);
    printf("%d\n", *(int *) ((char *) &t1 + offset1 + offset2));
    printf("%d\n", ((struct Teacher *) ((char *) &t1 + offset1))->b);
}

int main() {
//    test01();
//    test02();
    test03();
}