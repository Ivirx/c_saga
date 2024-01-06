#include <stdio.h>

int main() {
    int nth, first = 0, second = 1, current, c;

    printf("Enter the nth term : ");
    scanf("%d", &nth);

    printf("First %d terms of Fibonacci series are : ", nth);

    for (c = 0; c < nth; c++) {
        if (c <= 1) {
            current = c;
        } else {
            current = first + second;
            first = second;
            second = current;
        }
        printf("%d\t", current);
    }

    return 0;
}