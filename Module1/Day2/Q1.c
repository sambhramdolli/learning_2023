#include <stdio.h>

void printExponent(double num) {
    unsigned long long *ptr = (unsigned long long *)&num; 

    unsigned long long exponentBits = (*ptr >> 52) & 0x7FF; 

    printf("Exponent (hex): 0x%llX\n", exponentBits);

    printf("Exponent (binary): 0b");
    for (int i = 11; i >= 0; i--) {
        unsigned long long bit = (exponentBits >> i) & 1;
        printf("%llu", bit);
    }
    printf("\n");
}

int main() {
    double x = 0.7;
    printExponent(x);

    return 0;
}
