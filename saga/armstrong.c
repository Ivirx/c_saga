#include <stdio.h>
#include <math.h>

int main()
{
    int num, copyNum, digit, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &num);

    copyNum = num;

    while (copyNum > 0)
    {
        digit = copyNum % 10;
        printf("Digit: %d\t", digit);
        int power = (float)pow(digit, 3);
        printf("Power: %d\t", power);
        sum += power;
        printf("Sum: %d\n", sum);

        copyNum /= 10;
    }

    if (sum == num)
    {
        printf("The number is Armstrong Number.");
    }
    else
    {
        printf("The number is not Armstrong Number.");
    }

    return 0;
}