#include <stdio.h>

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num > 0)
    {
        printf("The number is Natural Number.");
    }
    else
    {
        printf("The number is not Natural Number.");
    }

    return 0;
}