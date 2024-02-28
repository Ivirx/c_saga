#include <stdio.h>

int main() {
    int a, b, c;
    printf("Enter three numbers : ");
    scanf("%d %d %d", &a, &b, &c);

    printf("Sum : %d\n", a + b + c);
    printf("Average : %.2f\n", (a + b + c) / 3.0);

    return 0;
}