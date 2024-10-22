#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int incompleteQuotient(int a, int b, int *errorCode) {
    if (b == 0) {
        *errorCode = 1;
        return 0;
    }
    *errorCode = 0;
    int sign = 1;
    if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
        sign = -1;
    }
    
    int result = 0;
    int absA = abs(a);
    int absB = abs(b);
    while (absA >= absB) {
        absA -= absB;
        result++;
    }
    
    if ((a < 0 && b > 0) && (result * sign * absB) != a) {
        return (result * sign) - 1;
    } else if ((b + a) < 0) {
        return result + 1;
    }
    return result * sign;
}
 
int main(void) {
    int a = 0;
    int b = 0;
    int errorCode = 0;
    
    printf("Enter the divisible: ");
    scanf("%d", &a);
    printf("Enter the divisor: ");
    scanf("%d", &b);
    
    int result = incompleteQuotient(a, b, &errorCode);
    
    if (errorCode != 0) {
        printf("Division by zero is not possible\n");
    } else {
        printf("Incomplete quotient: %d\n", result);
    }
        
    return 0;
}
