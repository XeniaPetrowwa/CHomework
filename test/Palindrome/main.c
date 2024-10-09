#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool palindrome(const char *string);
bool testPalindrome(void);

int main(void) {
    testPalindrome();
    
    const char string[] = "STRrRTS";
    
    if (palindrome(string)) {
        printf("%s - %s\n", string, "This is a palindrome!");
    } else {
        printf("%s - %s\n", string, "It's not a palindrome");
    }
    
    return 0;
}

bool palindrome(const char *string) {
    int leftElement = 0;
    unsigned long rightElement = strlen(string) - 1;
    
    while (leftElement < rightElement) {
        while (string[leftElement] == ' ') {
            leftElement++;
        }
        while (string[rightElement] == ' ') {
            rightElement--;
        }
        
        if (string[leftElement] != string[rightElement]) {
            return false;
        } else {
            leftElement++;
            rightElement--;
        }
    }
    return true;
}

bool testPalindrome(void) {
    const char string1[] = "Sa Sa SaS";
    const char string2[] = " ";
    const char string3[] = "D";
    const char string4[] = "AA a AA A";
    if (palindrome(string1) && palindrome(string2) && palindrome(string3) && !palindrome(string4)) {
        return true;
    }
    return false;
}
