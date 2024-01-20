#include <stdio.h>

int main() {
    // Celsius to Fahrenheit Conversion
    float tempInCelsius;

    printf("Enter the temperature (in C): ");
    scanf("%f", &tempInCelsius);

    printf("Temperature in Fahrenheit: %.2f\n", (tempInCelsius * (9.0 / 5.0)) + 32);

    return 0;
}