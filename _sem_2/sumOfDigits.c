#include <stdio.h>

int main() {
    int num, sum = 0;
    printf("Enter a positive integer : ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Invalid Input!\n");
        return 0;
    }

    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    printf("Sum of digits : %d\n", sum);

    return 0;
}