#include <stdio.h>

int main()
{
    int number;
    double product = 1;
    printf("Enter the number : ");
    scanf("%d", &number);

    for (int i = 1; i <= number; i++)
        product *= i;

    printf("Factorial of %d is %.0lf.\n", number, product);

    return 0;
}