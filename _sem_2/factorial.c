#include <stdio.h>

double nonRecursiveWay(int num);
double recursiveWay(int num);

int main() {
    int number;
    printf("Enter the number : ");
    scanf("%d", &number);

    printf("Factorial of %d is %.0lf.\n", number, nonRecursiveWay(number));
    printf("Factorial of %d is %.0lf.\n", number, recursiveWay(number));

    return 0;
}

double nonRecursiveWay(int num) {
    double product = 1;

    for (int i = 1; i <= num; i++)
        product *= i;

    return product;
}

double recursiveWay(int num) {
    if (num == 0)
        return 1;

    return num * recursiveWay(num - 1);
}