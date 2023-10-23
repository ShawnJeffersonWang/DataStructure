//
// Created by shawn on 23-9-20.
//
#include <stdio.h>
#include <string.h>

void selectionSort(int arr[], int length) {
    int i, j, minIndex, temp;
    for (i = 0; i < length - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < length; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

typedef struct {
    int id;
    char name[20];
} Person;

typedef int (*Comparator)(const void *, const void *);

int comparePersonById(const void *a, const void *b) {
    const Person *person1 = (const Person *) a;
    const Person *person2 = (const Person *) b;
    return person1->id - person2->id;
}

int comparePersonByName(const void *a, const void *b) {
    const Person *person1 = (const Person *) a;
    const Person *person2 = (const Person *) b;
    return strcmp(person1->name, person2->name);
}

void bubbleSort(void *arr, int length, int size, Comparator compare) {
    char *ptr = (char *) arr;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (compare(ptr + j * size, ptr + (j + 1) * size) > 0) {
                char temp[size];
                memcpy(temp, ptr + j * size, size);
                memcpy(ptr + j * size, ptr + (j + 1) * size, size);
                memcpy(ptr + (j + 1) * size, temp, size);
            }
        }
    }
}

void printPeople(Person *arr, int length) {
    for (int i = 0; i < length; i++) {
        printf("ID: %d, Name: %s\n", arr[i].id, arr[i].name);
    }
}

int main() {
    Person people[] = {
            {3, "Charlie"},
            {1, "Alice"},
            {2, "Bob"}
    };
    int length = sizeof(people) / sizeof(people[0]);

    printf("Before sorting:\n");
    printPeople(people, length);

    bubbleSort(people, length, sizeof(Person), comparePersonById);

    printf("\nAfter sorting by ID:\n");
    printPeople(people, length);

    bubbleSort(people, length, sizeof(Person), comparePersonByName);

    printf("\nAfter sorting by Name:\n");
    printPeople(people, length);

    return 0;
}