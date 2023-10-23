#include <stdio.h>
#include <string.h>

//
// Created by shawn on 23-9-7.
//
//栈的生长方向
void test01() {
    //栈底 高地址
    int a = 10;
    int b = 10;
    int c = 10;
    //栈顶 低地址
    int d = 10;
    printf("%d\n", &a);
    printf("%d\n", &b);
    printf("%d\n", &c);
    printf("%d\n", &d);
}

//2.内存存放方向
void test02() {
    int a = 0x11223344;
    char *p = &a;
    printf("%x\n", *p); //44 低位字节数据 低地址
    printf("%x\n", *(p + 1)); //33 高位字节数据 高地址
}

void test03() {
    int data1[2][3] = {{0x636c6557, 0x20656d6f, 0x58206f74},
                       {0x756f7969, 0x6e694c20, 0x00000000}};
    int data2[] = {0x47207875, 0x70756f72, 0x32303220, 0x00000a32};
    char *a = (char *) data1;
    char *b = (char *) data2;
    char buf[1024];
    strcpy(buf, a);
    strcat(buf, b);
    printf("%s \n", buf);
}

//高地址---高位字节数据 小端对齐
//高地址---低位字节数据 大端对齐
int main() {
//    test01();
//    test02();
    test03();
    printf("%d\n", test01);
    printf("%d\n", test02);
    printf("%d\n", test03);
    printf("%c", 111);
}