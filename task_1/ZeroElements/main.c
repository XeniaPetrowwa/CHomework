#include <stdio.h>
 
int main(void) {
    int elements = 0;
    int countZero = 0;
    
    printf("Введите количество элементов массива: ");
    scanf("%d", &elements);
    int array[elements];
 
    for (int i = 0; i < elements; i++) {
        printf("Введите элемент: ");
        scanf("%d", &array[i]);
        if (array[i] == 0) {
            countZero++;
        }
    }
    
    printf("\nКоличество нулей: %d\n", countZero);
    return 0;
}
