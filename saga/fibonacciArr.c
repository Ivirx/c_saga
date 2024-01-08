#include <stdio.h>

int main() {
    int nth;
    printf("Enter the nth term : ");
    scanf("%d", &nth);

    if (nth == 0) {
        printf("Enter a positive number.\n");
        return 0;
    }

    int fib[nth];
    if (nth >= 1)
        fib[0] = 0;
    if (nth >= 2)
        fib[1] = 1;

    for (int i = 2; i < nth; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    printf("First %d terms of Fibonacci Series are : ", nth);
    for (int i = 0; i < nth; i++) {
        printf("%d\t", fib[i]);
    }
    printf("\n");

    return 0;
}