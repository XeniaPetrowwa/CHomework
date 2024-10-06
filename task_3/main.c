#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void quickSort(int array[], int lowElement, int highElement);
int partition(int array[], int lowElement, int highElement);
void insertionSort(int array[], int lowElement, int highElement);
void swap(int* a, int* b);
void printArray(int array[], int length);
bool testInsertionSort(void);
bool testQuickSort(void);

int main(void) {
    if (testQuickSort() && testInsertionSort()) {
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

void insertionSort(int array[], int lowElement, int highElement) {
    int newElement = 0;
    int location = 0;
    
    for (int i = 1; i <= highElement; i++) {
        newElement = array[i];
        location = i - 1;
        while (location >= 0 && array[location] > newElement) {
            swap(&array[location + 1], &array[location]);
            location--;
        }
        array[location + 1] = newElement;
    }
}

int partition(int array[], int lowElement, int highElement) {
    int pivot = array[highElement];
    int index = (lowElement - 1);

    for (int i = lowElement; i < highElement; i++) {
        if (array[i] <= pivot) {
            index++;
            swap(&array[index], &array[i]);
        }
    }
    swap(&array[index + 1], &array[highElement]);
    return (index + 1);
}

void quickSort(int array[], int lowElement, int highElement) {
    if (highElement - lowElement < 10) {
        insertionSort(array, lowElement, highElement);
        return;
    } else if (lowElement < highElement) {
        int pi = partition(array, lowElement, highElement);

        quickSort(array, lowElement, pi - 1);
        quickSort(array, pi + 1, highElement);
    }
}

bool testQuickSort(void) {
    const int length = 10;
    int array[length] = {78, 93, 6, -5, -256, 6, 88, 4, 9, 34};
    int expectedSortedArray[length] = {-256, -5, 4, 6, 6, 9, 34, 78, 88, 93};
    quickSort(array, 0, length - 1);
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] == expectedSortedArray[i]) {
            count++;
        }
    }
    return count == length;
}

bool testInsertionSort(void) {
    const int length = 10;
    int array[length] = {78, 93, 6, -5, -256, 6, 88, 4, 9, 34};
    int expectedSortedArray[length] = {-256, -5, 4, 6, 6, 9, 34, 78, 88, 93};
    insertionSort(array, 0, length - 1);
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] == expectedSortedArray[i]) {
            count++;
        }
    }
    return count == length;
}
