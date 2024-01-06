#include <stdio.h>

float factorial(int n);

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    printf("Factorial of number %d is %.0f.", number, factorial(number));

    return 0;
}

float factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}