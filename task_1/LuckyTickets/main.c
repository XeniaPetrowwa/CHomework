#include <stdio.h>

int main(void) {
    int array[28] = {0};
    
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                array[i + j + k]++;
            }
        }
    }
    
    int count = 0;
    for (int i = 0; i <= 27; i++) {
        count += array[i] * array[i];
    }
    
    printf("The number of lucky tickets: %d\n", count);
    return 0;
}
