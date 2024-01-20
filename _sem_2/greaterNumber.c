#include <stdio.h>

int main() {
    int numberOne, numberTwo, numberThree;
    printf("Enter the first number : ");
    scanf("%d", &numberOne);
    printf("Enter the second number : ");
    scanf("%d", &numberTwo);

    if (numberOne > numberTwo) {
        printf("%d is greater than %d.\n", numberOne, numberTwo);
    } else if (numberOne < numberTwo) {
        printf("%d is greater than %d.\n", numberTwo, numberOne);
    } else {
        printf("Numbers are equal.\n");
    }

    printf("Enter the first number : ");
    scanf("%d", &numberOne);
    printf("Enter the second number : ");
    scanf("%d", &numberTwo);
    printf("Enter the third number : ");
    scanf("%d", &numberThree);

    if (numberOne > numberTwo && numberOne > numberThree) {
        printf("%d is the greatest.\n", numberOne);
    } else if (numberTwo > numberThree) {
        printf("%d is the greatest.\n", numberTwo);
    } else {
        printf("%d is the greatest.\n", numberThree);
    }

    return 0;
}