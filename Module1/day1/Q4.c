#include <stdio.h>

int main() {
    float operand1, operand2;
    char operator;

    printf("Enter Number1: ");
    scanf("%f", &operand1);

    printf("Enter the operator: ");
    scanf(" %c", &operator);

    printf("Enter Number2: ");
    scanf("%f", &operand2);

    float result;

    switch (operator) {2
        case '+';
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            result = operand1 / operand2;
            break;
        default:
            printf("Invalid operator\n");
            return 0;
    }

    printf("Result: %.2f\n", result);

    return 0;
}
