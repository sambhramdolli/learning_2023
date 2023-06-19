#include <stdio.h>

int bit_operations(int num, int oper_type) {
    switch (oper_type) {
        case 1:  
            num |= 1; 
            break;
        case 2:  
            num &= ~(1 << 31);
            break;
        case 3:  
            num ^= (1 << 16);  
            break;
        default:2
            printf("Invalid operation type\n");
            return num;
    }

    return num;
}

int main() {
    int num, oper_type;

    printf("Enter a 32-bit integer: ");
    scanf("%d", &num);

    printf("Enter the operation type (1, 2, or 3): ");
    scanf("%d", &oper_type);

    int result = bit_operations(num, oper_type);
    printf("Result: %d\n", result);

    return 0;
}
