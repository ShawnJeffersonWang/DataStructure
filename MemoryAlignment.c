#include <stdio.h>

//
// Created by shawn on 23-9-4.
//
//如果没有内存对齐，获取数据的时候，需要做二次访问
//有内存对齐，提高访问效率
//优点：以空间换时间
//查看当前对齐模数 对齐模数是可以改的，改成2的N次方
#pragma pack(show)
//第一个属性开始 从0开始偏移
//从第二个属性开始 要放在 该类型的大小 与 对齐模数比 取小的值 的整数倍
//所有的属性都计算完后，再整体做二次偏移，将整体计算的结果 要放在 结构体的最大类型 与对齐模数比 取小的值的 整数倍上
typedef struct _STUDENT {
    int a; //0~3
    char b; //4~7
    double c; //8~15
    float d; //16～19
} Student;
//结构体嵌套结构体时候，子结构体放在该结构体中最大类型 和对齐模数比 的整数倍上
typedef struct _STUDENT2 {
    char a;//0~7
    Student b;//8~31
    double c;//32~39
} Student2;

void test01() {
    printf("sizeof Student = %d\n", sizeof(Student));
}

void test02() {
    printf("sizeof Student2 = %d\n", sizeof(Student2));
}

int main() {
//    test01();
    test02();
}