#include <stdio.h>

void swap(void *ptr1, void *ptr2, size_t size) {
    unsigned char *temp = (unsigned char *)malloc(size);

    memcpy(temp, ptr1, size);

    memcpy(ptr1, ptr2, size);

    memcpy(ptr2, temp, size);

    free(temp);
}

int main() {
    int a = 5, b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);

    swap(&a, &b, sizeof(int));
    printf("After swap: a = %d, b = %d\n", a, b);

    double x = 2.5, y = 7.8;
    printf("Before swap: x = %.2f, y = %.2f\n", x, y);

    swap(&x, &y, sizeof(double));
    printf("After swap: x = %.2f, y = %.2f\n", x, y);

    char c1 = 'A', c2 = 'B';
    printf("Before swap: c1 = %c, c2 = %c\n", c1, c2);

    swap(&c1, &c2, sizeof(char));
    printf("After swap: c1 = %c, c2 = %c\n", c1, c2);

    return 0;
}
