#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void quickSort(int array[], int lowElement, int highElement);
void swap(int* a, int* b);
void printArray(int array[], int length);
int partition(int array[], int lowElement, int highElement);
int binarySearch(int array[], int k, int length);
bool testBinarySearch(void);
bool testQuickSort(void);

int main(void) {
    if (testBinarySearch() && testQuickSort()) {
        printf("Tests passed!\n");
    } else {
        printf("Tests failed\n");
    }
    
    int n = 0;
    printf("Enter the number n: ");
    scanf("%d", &n);
    int k = 0;
    printf("Enter the number k: ");
    scanf("%d", &k);
    
    int *array = calloc(n, sizeof(int));
    if (array == NULL) {
        return -1;
    }
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100;
    }
    quickSort(array, 0, n - 1);
    
    for (int i = 0; i < k; i++){
        int number = rand() % 100;
        printf("The desired number %d - %s\n", number, binarySearch(array, number, n) ? "Found" : "Not found");
    }
    
    free(array);
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
    if (lowElement < highElement) {
        int pi = partition(array, lowElement, highElement);
        
        quickSort(array, lowElement, pi - 1);
        quickSort(array, pi + 1, highElement);
    }
}

int binarySearch(int array[], int k, int length) {
    int left = 0;
    int right = length - 1;
    if (k == array[0]) {
        return k;
    }
    while (left <= right) {
        int middle = (left + right) / 2;
        if (k < array[middle]) {
            right = middle - 1;
        } else if (k > array[middle]) {
            left = middle + 1;
        } else {
            return middle;
        }
    }
    return 0;
}

bool testBinarySearch(void) {
    const int length = 10;
    const int number = 9;
    int array[length] = {9, 10, 5, 44, 709, 233, 45, 2, -1, 0};
    return binarySearch(array, number, length);
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
