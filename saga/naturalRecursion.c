#include <stdio.h>

int sum(int number);

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    printf("Sum of numbers from 1 to %d is %d.", number, sum(number));

    return 0;
}

int sum(int number) {
    if (number <= 0) {
        return 0;
    }
    return sum(number - 1) + number;
}