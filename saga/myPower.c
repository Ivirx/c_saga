#include <stdio.h>

int power(int number, int exponent);
int recursivePower(int number, int exponent);

int main() {
    int number, exponent, value;
    printf("Enter number : ");
    scanf("%d", &number);
    printf("Enter exponent : ");
    scanf("%d", &exponent);

    value = power(number, exponent);
    printf("%d to the power %d is %d.\n", number, exponent, value);

    value = recursivePower(number, exponent);
    printf("%d to the power %d is %d.\n", number, exponent, value);

    return 0;
}

int power(int number, int exponent) {
    int value = 1;
    for (int i = 1; i <= exponent; i++) {
        value *= number;
    }

    return value;
}

int recursivePower(int number, int exponent) {
    if (exponent == 0)
        return 1;

    int value = number * recursivePower(number, exponent - 1);
    return value;
}