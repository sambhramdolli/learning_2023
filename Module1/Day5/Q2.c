#include <stdio.h>

struct Complex {
    double real;
    double imaginary;
};

void readComplex(struct Complex* c) {
    printf("Enter the real part: ");
    scanf("%lf", &(c->real));
    
    printf("Enter the imaginary part: ");
    scanf("%lf", &(c->imaginary));
}

void writeComplex(const struct Complex* c) {
    printf("Complex number: %.2f + %.2fi\n", c->real, c->imaginary);
}

struct Complex addComplex(const struct Complex* c1, const struct Complex* c2) {
    struct Complex result;
    
    result.real = c1->real + c2->real;
    result.imaginary = c1->imaginary + c2->imaginary;
    
    return result;
}

struct Complex multiplyComplex(const struct Complex* c1, const struct Complex* c2) {
    struct Complex result;
    
    result.real = c1->real * c2->real - c1->imaginary * c2->imaginary;
    result.imaginary = c1->real * c2->imaginary + c1->imaginary * c2->real;
    
    return result;
}

int main() {
    struct Complex complex1, complex2;
    
    printf("Reading complex number 1:\n");
    readComplex(&complex1);
    
    printf("Reading complex number 2:\n");
    readComplex(&complex2);
    
    printf("\nComplex number 1:\n");
    writeComplex(&complex1);
    
    printf("Complex number 2:\n");
    writeComplex(&complex2);
    
    struct Complex sum = addComplex(&complex1, &complex2);
    printf("\nSum of the complex numbers:\n");
    writeComplex(&sum);
    
    struct Complex product = multiplyComplex(&complex1, &complex2);
    printf("Product of the complex numbers:\n");
    writeComplex(&product);
    
    return 0;
}
