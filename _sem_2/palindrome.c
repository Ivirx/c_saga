#include <stdio.h>

int main() {
    int original, copy, number = 0;
    printf("Enter a number : ");
    scanf("%d", &original);

    copy = original;

    while (copy > 0) {
        number = (number * 10) + copy % 10;

        copy /= 10;
    }

    if (number == original) {
        printf("Palindrome Number\n");
    } else {
        printf("Not a Palindrome Number\n");
    }

    return 0;
}