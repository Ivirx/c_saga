#include <stdio.h>

// 0 1 1 2 3 5 8 13 21 34 . . .
void fibonacci(int i, int nth, int first, int second);
int fib(int n);

int main() {
    int nth;
    printf("Enter the nth term : ");
    scanf("%d", &nth);

    printf("Fibonacci nth term : %d", fib(nth));

    return 0;
}

void fibonacci(int i, int nth, int first, int second) {
    if (i == nth) return;

    if (i <= 1) {
        printf("%d\t", i);
        fibonacci(i + 1, nth, 0, 1);
    } else {
        printf("%d\t", first + second);
        fibonacci(i + 1, nth, second, first + second);
    }
}

int fib(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;

    return fib(n - 1) + fib(n - 2);
}