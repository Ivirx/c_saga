#include <math.h>
#include <stdio.h>

int main() {
    int original, copy, digit, sum = 0;
    printf("Enter a number : ");
    scanf("%d", &original);

    copy = original;

    while (copy > 0) {
        digit = copy % 10;
        int power = (float)pow(digit, 3);
        sum += power;

        copy /= 10;
    }

    if (sum == original) {
        printf("Armstrong Number\n");
    } else {
        printf("Not a Armstrong Number\n");
    }

    return 0;
}