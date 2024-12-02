#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "frequency.h"

bool testFindMostFrequent(void);

int main(void) {
    if (testFindMostFrequent()) {
        printf("Tests passed!\n");
    }
    
    const char *filename = "elements.txt";
    int size = 0;
    int *array = readArrayFromFile(filename, &size);
    int mostFrequent = mostFrequentElement(array, size);
    
    printf("The most frequent element: %d\n", mostFrequent);
    
    return 0;
}

bool testFindMostFrequent(void) {
    int array1[] = {1, 2, 2, 3, 3, 3};
    assert(mostFrequentElement(array1, 6) == 3);

    int array2[] = {4, 4, 4, 5, 5, 5, 6, 6};
    assert(mostFrequentElement(array2, 8) == 4 || mostFrequentElement(array2, 8) == 5);
    int array3[] = {};
    assert(mostFrequentElement(array3, 0) == -1);
    
    return true;
}
