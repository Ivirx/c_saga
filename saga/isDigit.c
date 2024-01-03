#include <stdio.h>

int main()
{
    char input;

    printf("Enter a character: ");
    scanf(" %c", &input);

    if (input >= '0' && input <= '9')
    {
        printf("%c is a digit.\n", input);
    }
    else
    {
        printf("%c is not a digit.\n", input);
    }

    return 0;
}
