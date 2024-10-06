#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

void swap(int* a, int* b);
void printArray(int array[], int length);
void bubbleSort(int* array, int length);
void countingSort(int* array, int length);
bool testSortingAlgorithms(void);

int main(void) {
    testSortingAlgorithms();
    
    const int length = 100000;
    int arrayForBubble[length] = {176317, 44, 65, 3355, -4354, -5, 7, 8, 2, -1, -25, 5, 8};
    
    double timeBubble = 0;
    
    clock_t startTimeBubble = clock();
    bubbleSort(arrayForBubble, length);
    timeBubble = ((double)(clock() - startTimeBubble)) / CLOCKS_PER_SEC;
    
    int arrayForCount[length] = {176317, 44, 65, 3355, -4354, -5, 7, 8, 2, -1, -25, 5, 8};
    
    double timeCount = 0;
    
    clock_t startTimeCount = clock();
    countingSort(arrayForCount, length);
    timeBubble = ((double)(clock() - startTimeCount)) / CLOCKS_PER_SEC;
    
    printf("Bubble time - %f\n", timeBubble);
    printf("Counting time - %f\n", timeCount);
    
    return 0;
}

bool testSortingAlgorithms(void) {
    const int n = 10;
    int array1[] = {5, 3, 8, 4, 2, 1, 0, 10, 9, 6};
    int sortedArray[] = {0, 1, 2, 3, 4, 5, 6, 8, 9, 10};

    bubbleSort(array1, n);
    for (int i = 0; i < n; i++) {
        if (array1[i] != sortedArray[i]) {
            return false;
        }
    }
    
    int array2[] = {5, 3, 8, 4, 2, 1, 0, 10, 9, 6};
    countingSort(array2, n);
    for (int i = 0; i < n; i++) {
        if (array2[i] != sortedArray[i]) {
            return false;
        }
    }
    return true;
}

void swap(int* a, int* b) {
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

void bubbleSort(int* array, int length) {
    bool count = true;
    
    while (count) {
        count = false;
        for (int i = 0; i < (length - 1); i++) {
            if (array[i] > array[i + 1]) {
                swap(&array[i], &array[i + 1]);
                
                count = true;
            }
        }
    }
}

void countingSort(int* array, int length) {
    int maxNumber = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] > maxNumber) {
            maxNumber = array[i];
        }
    }
    
    int* tempArray = (int*) malloc((maxNumber + 1) * sizeof(*array));
    memset(tempArray, 0, (maxNumber + 1) * sizeof(*array));

    for (int i = 0; i < length; i++) {
        tempArray[array[i]]++;
    }
        
    int b = 0;
    for (int i = 0; i < (maxNumber + 1); i++){
        for (int j = 0; j < tempArray[i]; j++) {
            array[b++] = i;
        }
    }

    free(tempArray);
 }
