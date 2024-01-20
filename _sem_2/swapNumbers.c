#include <stdio.h>

int main() {
    // with the help of a temperary variable
    int a = 4, b = 9, temp;
    printf("Before Swaping the values :\na = %d and b = %d.\n", a, b);

    temp = a;
    a = b;
    b = temp;
    printf("After Swaping the values :\na = %d and b = %d.\n", a, b);

    // with the help of a temperary variable
    int x = 18, y = 32;
    printf("Before Swaping the values :\nx = %d and y = %d.\n", x, y);

    x = x + y;
    y = x - y;
    x = x - y;
    printf("After Swaping the values :\nx = %d and y = %d.\n", x, y);

    return 0;
}