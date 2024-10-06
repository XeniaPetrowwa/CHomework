#include <stdio.h>

int root(int number) {
    int root = 0;
    for (int i = 1; i <= number; i++) {
        if ((i * i) <= number) {
            root = i;
        } else {
            break;
        }
    }
    return root;
}

void primeNumber(int number) {
    int countDivisors = 0;
    for (int i = 2; i <= root(number); i++) {
        if (number % i == 0) {
            countDivisors += 1;
        }
    }
    if (countDivisors == 0) {
        printf("%d\n", number);
    }
}

int main(void) {
    int digit = 0;
    printf("Enter the number: ");
    scanf("%d", &digit);
    
    printf("Prime numbers <= entered:\n");
    for (int i = 2; i <= digit; i++) {
        primeNumber(i);
    }
    
    return 0;
}
