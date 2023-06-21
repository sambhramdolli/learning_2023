#include <stdio.h>
#include <stdarg.h>

void find_smallest_and_largest_digits(int n, ...) {
    if (n < 1) {
        printf("Not Valid\n");
        return;
    }

    int num;
    va_list args;
    va_start(args, n);

    int smallest_digit = 9;  
    int largest_digit = 0;   

    int i;
    for (i = 0; i < n; i++) {
        num = va_arg(args, int);

        while (num != 0) {
            int digit = num % 10;
            smallest_digit = (digit < smallest_digit) ? digit : smallest_digit;
            largest_digit = (digit > largest_digit) ? digit : largest_digit;
            num /= 10;
        }
    }

    va_end(args);

    if (smallest_digit == 9 && largest_digit == 0) {
        printf("Not Valid\n");
    } else {
        printf("Smallest Digit: %d\n", smallest_digit);
        printf("Largest Digit: %d\n", largest_digit);
    }
}

int main() {
    find_smallest_and_largest_digits(3, 8, 156, 123450);
    return 0;
}