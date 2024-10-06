#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int mostFrequentElement(int array[], int length);
bool searchTest(void);
bool emptyArrayTest(void);

int main(void) {
    if (searchTest() && emptyArrayTest()) {
        printf("Tests passed!\n");
    } else {
        printf("Tests failed\n");
    }
    return 0;
}

int mostFrequentElement(int array[], int length) {
    if (length == 0) {
        return -1;
    }
    int *countOfElements = calloc(length, sizeof(int));
    if (countOfElements == NULL) {
        return -1;
    }
    
    for (int i = 0; i < length; i++) {
        countOfElements[array[i]]++;
    }
    
    int maxCount = 0;
    int element = 0;
    for (int i = 0; i < length; i++) {
        if (countOfElements[i] > maxCount) {
            maxCount = countOfElements[i];
            element = i;
        }
    }
    
    free(countOfElements);
    return element;
}

bool searchTest(void) {
    const int length = 10;
    int array[length] = {3, 5, 7, 1, 5, 5, 3, 0, 3, 9};
    int element = mostFrequentElement(array, length);
    return (element == 3 || element == 5);
}

bool emptyArrayTest(void) {
    const int length = 0;
    int array[] = {};
    int expectedResult = -1;
    return mostFrequentElement(array, length) == expectedResult;
}
