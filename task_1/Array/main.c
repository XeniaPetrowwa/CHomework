#include <stdio.h>

void mirrorArray(int array[], int length) {
    for (int i = 0; i < (length / 2); i++) {
        int temp = array[i];
        array[i] = array[(length / 2) + i];
        array[(length / 2) + i] = temp;
    }
}

int main(void) {
    const int size = 10;
    int array[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    mirrorArray(array, size);
    
    printf("Rearranged array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}
