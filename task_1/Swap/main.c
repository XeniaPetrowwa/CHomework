#include <stdio.h>
 
int main(void) {
    int a = 0, b = 0;
    printf("Введите первое число (число а): ");
    scanf("%d", &a);
    
    printf("Введите второе число (число b): ");
    scanf("%d", &b);
    
    a += b;
    b = a - b;
    a = a - b;
    
    printf("Число а: %d\nЧисло b: %d\n", a, b);
    return 0;
}

