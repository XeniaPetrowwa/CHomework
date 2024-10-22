#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <locale.h>

void convertToBinary(int number, char *binary);
int sumBinary(int numberOne, int numberTwo);
void printBinarySum(int numberOne, int numberTwo);
void assertBinary(int number, const char *expected);
bool test(void);
bool testSum(void);

int main(void) {
    setlocale(LC_ALL, "Rus");
    (test() && testSum()) ? printf("Тесты пройдены!\n") : printf("Тесты не пройдены\n");
    
    int numberOne = 0;
    int numberTwo = 0;

    printf("Введите первое число: ");
    scanf("%d", &numberOne);
    printf("Введите второе число: ");
    scanf("%d", &numberTwo);

    printBinarySum(numberOne, numberTwo);

    return 0;
}

void convertToBinary(int number, char *binary) {
    if (number >= 0) {
        for (int i = 0; i < 32; i++) {
            binary[31 - i] = (number & (1 << i)) ? '1' : '0';
        }
    } else {
        int value = -number;
        for (int i = 0; i < 32; i++) {
            binary[31 - i] = (value & (1 << i)) ? '1' : '0';
        }
        for (int i = 0; i < 32; i++) {
            binary[i] = (binary[i] == '1') ? '0' : '1';
        }
        for (int i = 31; i >= 0; i--) {
            if (binary[i] == '0') {
                binary[i] = '1';
                break;
            } else {
                binary[i] = '0';
            }
        }
    }
    binary[32] = '\0';
}

int sumBinary(int numberOne, int numberTwo) {
    int shift = 0;
    while (numberTwo != 0) {
        shift = numberOne & numberTwo;
        numberOne ^= numberTwo;
        numberTwo = shift << 1;
    }
    return numberOne;
}

void printBinarySum(int numberOne, int numberTwo) {
    char binaryOne[33] = "";
    char binaryTwo[33] = "";
    char binarySum[33] = "";
    
    convertToBinary(numberOne, binaryOne);
    convertToBinary(numberTwo, binaryTwo);
    int sum = sumBinary(numberOne, numberTwo);
    convertToBinary(sum, binarySum);

    printf("Первое число в двоичном представлении(дополнительный код): %s\n", binaryOne);
    printf("Второе число в двоичном представлении(дополнительный код): %s\n", binaryTwo);
    printf("Сумма в двоичном представлении(дополнительный код): %s\n", binarySum);
    printf("Сумма в десятичном виде: %d\n", sum);
}

void assertBinary(int number, const char *expected) {
    char binary[33] = "";
    convertToBinary(number, binary);
    assert(strcmp(binary, expected) == 0);
}

bool test(void) {
    assertBinary(0, "00000000000000000000000000000000");
    assertBinary(1, "00000000000000000000000000000001");
    assertBinary(-1, "11111111111111111111111111111111");
    return true;
}

bool testSum(void) {
    int numberOne = 555;
    int numberTwo = -321;
    int expectedSum = 234;
    char binaryOne[33] = "";
    char binaryTwo[33] = "";
    
    convertToBinary(numberOne, binaryOne);
    convertToBinary(numberTwo, binaryTwo);
    int sum = sumBinary(numberOne, numberTwo);
    
    if (sum == expectedSum) {
        return true;
    }
    return false;
}
