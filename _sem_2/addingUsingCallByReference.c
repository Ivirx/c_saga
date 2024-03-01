#include <stdio.h>

void add(float a, float b, float *sum);

int main() {
    float a, b, sum = 0.0;
    printf("Enter two numbers : ");
    scanf("%f %f", &a, &b);

    add(a, b, &sum);
    printf("Sum of %f and %f is : %f\n", a, b, sum);

    return 0;
}

void add(float a, float b, float *sum) { *sum = a + b; }
