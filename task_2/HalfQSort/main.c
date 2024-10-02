#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* a, int* b);
void printArray(int array[], int length);
void halfQsort(int array[], int length);
bool test(void);

int main(void) {
    test();
    
    const int length = 100;
    int array[length] = {0};
    for (int i = 0; i < length; i++) {
        array[i] = rand() % 100;
    }
    
    printf("Initial array: \n");
    printArray(array, length);
    
    halfQsort(array, length);
    
    printf("Sorted array: \n");
    printArray(array, length);
    
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

void halfQsort(int array[], int length) {
    int firstElement = array[0];
    for (int i = 1; i < length; i++) {
        if (firstElement > array[i]) {
            swap(&array[i - 1], &array[i]);
        } else if (array[i] == array[length - 1]) {
            length--;
            i--;
            continue;
        } else {
            swap(&array[i], &array[length - 1]);
            length--;
            i--;
        }
    }
}

bool test(void) {
    const int size = 9;
    int array[size] = {10, 5, 3, 7, 26, 44, 0, 3, 5};
    int sortedArray[size] = {5, 3, 7, 5, 3, 0, 10, 44, 26};
    halfQsort(array, size);
    
    for (int i = 0; i < size; i++) {
        if (array[i] != sortedArray[i]) {
            return false;
        }
    }
    
    return true;
}
