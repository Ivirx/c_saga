#include <stdio.h>

int main()
{
    // Celsius to Fahrenheit
    float tempInCelsius;

    printf("Enter the temperature (in C): ");
    scanf("%f", &tempInCelsius);

    printf("Temperature in Fahrenheit: %.2f\n", (tempInCelsius * 9 / 5) + 32);

    // Fahrenheit to Celsius
    float tempInFahrenheit;

    printf("Enter the temperature (in F): ");
    scanf("%f", &tempInFahrenheit);

    printf("Temperature in Celsius: %.2f\n", (tempInFahrenheit - 32) * 5 / 9);

    // Using if-else
    /* float temp;
    char unit;

    printf("Enter the temperature: ");
    scanf("%f", &temp);
    printf("Enter the unit (C/F): ");
    scanf(" %c", &unit);

    if (unit == 'C' || unit == 'c')
    {
        printf("Temperature in Fahrenheit: %.2f", (temp * 9 / 5) + 32);
    }
    else if (unit == 'F' || unit == 'f')
    {
        printf("Temperature in Celsius: %.2f", (temp - 32) * 5 / 9);
    }
    else
    {
        printf("Invalid unit");
    } */

    return 0;
}