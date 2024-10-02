#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

long double exponentiationLine(long long number, long degree);
long double exponentiationLog(long long number, long degree);
bool test(void);

int main(void) {
    test();
    
    printf("%Lf\n", exponentiationLine(2, -3));
    printf("%Lf\n", exponentiationLog(2, -3));
    
    return 0;
}

long double exponentiationLine(long long number, long degree) {
    long double result = 1;
    bool negativeDegree = false;
    
    if (degree < 0) {
        degree = -degree;
        negativeDegree = true;
    } else if (degree == 0) {
        return result;
    }
    
    for (int i = 0; i < degree; i++) {
        result *= number;
    }
    
    if (negativeDegree) {
        return (1.0 / result);
    } else {
        return result;
    }
}

long double exponentiationLog(long long number, long degree) {
    bool negativeDegree = false;
    if (degree == 0) {
        return 1.0;
    } else if (degree < 0) {
        degree = -degree;
        negativeDegree = true;
    }
    
    long double half = exponentiationLog(number, degree / 2);
    
    if (degree % 2 == 0) {
        if (negativeDegree) {
            return (1.0 / (half * half));
        } else {
            return half * half;
        }
    } else {
        if (negativeDegree) {
            return (1.0 / (number * half * half));
        } else {
            return number * half * half;
        }
    }
}

bool test(void) {
    assert(exponentiationLine(2, 3) == 8);
    assert(exponentiationLine(2, -3) == 0.125);
    assert(exponentiationLine(2, 0) == 1);
    assert(exponentiationLine(-2, 3) == -8);
    assert(exponentiationLine(-2, -2) == 0.25);

    assert(exponentiationLog(2, 3) == 8);
    assert(exponentiationLog(2, -3) == 0.125);
    assert(exponentiationLog(2, 0) == 1);
    assert(exponentiationLog(-2, 3) == -8);
    assert(exponentiationLog(-2, -2) == 0.25);

    return true;
}
