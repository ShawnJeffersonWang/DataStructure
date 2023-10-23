#include <stdio.h>
#include <string.h>

void func(int num, char c) {
    printf("func: %d, %c\n", num, c);
}

void func1() {
    printf("func1 调用了\n");
}

void func2() {
    printf("func2 调用了\n");
}

void func3() {
    printf("func3 调用了\n");
}

void print_int(void *data) {
    int *num = data;
    printf("print_int: %d\n", *num);
}

void print_any(void *data, void(*my_print)()) {
//    int *d = data;
//    printf("%d\n", *d);
    my_print(data);
}

struct Student {
    char name[64];
    int age;
};

void printPerson(void *data) {
    struct Student *p = data;
    printf("printPerson: 姓名: %s 年龄: %d\n", p->name, p->age);
}

//void printArray(int *array, int len) {
//    for (int i = 0; i < len; i++) {
//        printf("%d ", array[i]);
//    }
//}

void myPrintInt(void *data) {
    int *num = data;
    printf("%d\n", *num);
}

void myPrintPerson(void *data) {
    struct Student *p = data;
    printf("姓名: %s 年龄: %d\n", p->name, p->age);
}

void printArray(void *array, int elementSize, int len, void(*myPrint)(void *)) {
    char *p = array;
    for (int i = 0; i < len; i++) {
        //获取数组中每个元素的首地址
        char *firstAddr = p + elementSize * i;
        //printf("%d ", *(int *) firstAddr);
        //交还给用户做打印操作
        myPrint(firstAddr);
    }
}

//参数1 数组首地址 参数2 每个元素的大小 参数3 数组元素个数 参数4 查找数据的地址
int findArrayElement(void *arr, int elementSize, int len, void *data, int(*myCompare)(void *, void *)) {
    char *p = arr;
    for (int i = 0; i < len; i++) {
        char *elementAddr = p + elementSize * i;
        if (myCompare(data, elementAddr)) {
            return 1;
        }
    }
    return 0;
}

int myCompare(void *data1, void *data2) {
    struct Student *p1 = data1;
    struct Student *p2 = data2;
//    if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age) {
//        return 1;
//    }
//    return 0;
    return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}
//什么是函数指针？
//函数指针 指向了函数的指针
//指针函数 函数返回值是指针的函数

//函数名称的本质就是一个函数指针
//可以利用函数指针 调用函数
int main() {
    //1.先定义出函数类型，再通过类型定义函数指针变量
    typedef void(func_type)(int, char);
    func_type *ptr1 = func;
    ptr1(10, 97);
//    printf("%d\n", func);
//    printf("%d\n", ptr);
    //2.先定义出函数指针类型，通过类型定义函数指针变量
    typedef void(*func_ptr_type)(int, char);
    func_ptr_type ptr2 = func;
    ptr2(20, 'b');
    //3.直接定义函数指针变量
    void (*ptr3)(int, char) =func;
    ptr3(30, 'c');
    //函数指针数组
    void (*func_ptr_arr[3])();
    func_ptr_arr[0] = func1;
    func_ptr_arr[1] = func2;
    func_ptr_arr[2] = func3;
    for (int i = 0; i < 3; i++) {
        func_ptr_arr[i]();
    }
    //函数指针做函数参数（回调函数）

    //提供一个打印函数，可以打印任意类型的数据
    int a = 10;
    print_any(&a, print_int);
    struct Student p1 = {"Tom", 18};
    print_any(&p1, printPerson);
    //打印任意类型的数组
    int arr[5] = {1, 2, 3, 4, 5};
    int len1 = sizeof(arr) / sizeof(int);
    printArray(arr, sizeof(int), len1, myPrintInt);
    struct Student personArray[] = {
            {"aaa", 10},
            {"bbb", 20},
            {"ccc", 30},
            {"ddd", 40},
    };
    int len2 = sizeof(personArray) / sizeof(struct Student);
    printArray(personArray, sizeof(struct Student), len2, myPrintPerson);
    //查找数组中指定的元素是否存在
    struct Student p2 = {"bbb", 20};
    int ret = findArrayElement(personArray, sizeof(struct Student), len2, &p2, myCompare);
    if (ret) printf("找到了元素\n");
    else printf("未找到\n");
    //提供一个函数，实现对任意类型的数组进行排序，排序规则利用选择排序，排序的顺序 用户可以自己制定
    return 0;
}
