#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int recursiveFibonacci(int number);
int iterativeFibonacci(int number);
bool testFibonacci(int number, int expectedResult);

int main(void) {
    testFibonacci(0, 0);
    testFibonacci(2, 1);
    testFibonacci(5, 5);
    testFibonacci(7, 21);
    testFibonacci(9, 34);
    testFibonacci(13, 233);
    
    for (int i = 20; i <= 100; i++) {
        clock_t startTime = 0;
        clock_t endTime = 0;
        double timeRecursive = 0;
        double timeIterative = 0;
        
        startTime = clock();
        recursiveFibonacci(i);
        endTime = clock();
        timeRecursive = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;

        startTime = clock();
        iterativeFibonacci(i);
        endTime = clock();
        timeIterative = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
        
        if (timeRecursive > (timeIterative + 0.3)) {
            printf("The running time of the recursive algorithm: %f\n", timeRecursive);
            printf("The running time of the iterative algorithm: %f\n", timeIterative);
            printf("The recursive version has become noticeably slower than the iterative one on the number = %d\n", i);
            break;
        }
    }
    return 0;
}

int recursiveFibonacci(int number) {
    if (number == 1) {
        return number;
    } else if (number <= 0){
        return 0;
    }
    return recursiveFibonacci(number - 1) + recursiveFibonacci(number - 2);
}

int iterativeFibonacci(int number) {
    if (number == 1) {
        return number;
    } else if (number <= 0) {
        return 0;
    }
    int first = 0;
    int second = 1;
    int result = 0;
    for (int i = 2; i <= number; i++) {
        result = first + second;
        first = second;
        second = result;
    }
    return result;
}

bool testFibonacci(int number, int expectedResult) {
    int recursiveResult = recursiveFibonacci(number);
    int iterativeResult = iterativeFibonacci(number);
    
    if (recursiveResult == expectedResult && iterativeResult == expectedResult) {
        return true;
    }
    return false;
}
