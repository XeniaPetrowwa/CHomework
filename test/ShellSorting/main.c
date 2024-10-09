#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void shellSort(int array[], int length);
void swap(int* a, int* b);
void printArray(int array[], int length);
bool sortingTest(void);
bool oneElementTest(void);
bool emptyArrayTest(void);

int main(void) {
    if (sortingTest() && oneElementTest() && emptyArrayTest()) {
            printf("Tests passed!\n");
        } else {
            printf("Tests failed\n");
        }
    
    return 0;
}

void swap(int* a, int* b) {
    if (*a == *b) {
        return;
    }
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void printArray(int array[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void shellSort(int array[], int length) {
    for (int step = length / 2; step > 0; step /= 2) {
        for (int i = step; i < length; i++) {
            int temp = array[i];
            int j = 0;
            for (j = i; j >= step && array[j - step] > temp; j -= step) {
                array[j] = array[j - step];
            }
            array[j] = temp;
        }
    }
}

bool sortingTest(void) {
    int array[] = {232, -40, 0, 3, -35, 56, 72, 2, 9, 812};
    const int size = 10;
    int expectedArray[] = {-40, -35, 0, 2, 3, 9, 56, 72, 232, 812};
    shellSort(array, size);
    
    for (int i = 0; i < size; i++) {
            if (array[i] != expectedArray[i]) {
                return false;
            }
        }
    return true;
}

bool oneElementTest(void) {
    int array[] = {44};
    const int size = 1;
    int expectedArray[] = {44};
    shellSort(array, size);
    
    for (int i = 0; i < size; i++) {
            if (array[i] != expectedArray[i]) {
                return false;
            }
        }
    return true;
}

bool emptyArrayTest(void) {
    int array[] = {};
    const int size = 0;
    int expectedArray[] = {};
    shellSort(array, size);
    
    for (int i = 0; i < size; i++) {
            if (array[i] != expectedArray[i]) {
                return false;
            }
        }
    return true;
}
