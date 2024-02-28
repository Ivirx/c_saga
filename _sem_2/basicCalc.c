#include <stdio.h>

int main() {
    char operator;
    int operand1, operand2, result;

    printf("Enter two integer operands: ");
    scanf("%d %d", &operand1, &operand2);

    printf("Enter an operator (+, -, *, /, %%): ");
    scanf(" %c", &operator);

    switch (operator) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            // Checking for division by zero
            if (operand2 != 0)
                result = operand1 / operand2;
            else {
                printf("Error: Division by zero!\n");
                return 1;
            }
            break;
        case '%':
            // Checking for division by zero
            if (operand2 != 0)
                result = operand1 % operand2;
            else {
                printf("Error: Division by zero!\n");
                return 1;
            }
            break;
        default:
            printf("Error: Invalid operator!\n");
            return 1;
    }

    printf("Result: %d %c %d = %d\n", operand1, operator, operand2, result);

    return 0;
}
