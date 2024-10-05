#include <stdio.h>
#include <string.h>

int bracketBalance(char* string) {
    int count = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == '(') {
            count++;
        } else if (string[i] == ')') {
            count--;
        }
    }
    if ((count < 0) || (count > 0)) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {
    char string[] = "(())()((()))";
    if (bracketBalance(string)) {
        printf("There is no bracket balance\n");
    } else {
        printf("The line is balanced\n");
    }
    
    return 0;
}

