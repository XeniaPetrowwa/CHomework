#include <stdio.h>
#include <string.h>

int countEntry(char * s, char * s1) {
    float lens = strlen(s);
    float lens1 = strlen(s1);
    int count = 0;

    for (int i = 0; i <= (lens - lens1); i++) {
        int j = 0;
        for (j = 0; j < lens1; j++) {
            if (s[i + j] != s1[j]) {
                break;
            }
        }
        if (j == lens1) {
            count++;
        }
    }

    return count;
}

int main(void) {
    char s[] = "AABABABABJFBAHDMBAABSBSBABK";
    char s1[] = "BA";
    int result = countEntry(s, s1);
    printf("The number of occurrences of S1 in S: %d\n", result);
    return 0;
}
