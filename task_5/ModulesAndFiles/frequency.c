#include "frequency.h"
#include <stdio.h>
#include <stdlib.h>

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

int *readArrayFromFile(const char *filename, int *size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("File opening error\n");
        exit(EXIT_FAILURE);
    }

    int *array = malloc(100 * sizeof(int));
    *size = 0;
    while (fscanf(file, "%d", &array[*size]) != EOF) {
        (*size)++;
        if (*size % 100 == 0) {
            array = realloc(array, (*size + 100) * sizeof(int));
        }
    }
    fclose(file);
    return array;
}
