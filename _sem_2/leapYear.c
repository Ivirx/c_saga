#include <stdio.h>

int main() {
    int year;
    printf("Enter the year : ");
    scanf("%d", &year);

    // leap year : divisible by 4 and for century years it should be divisible by 400
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("Leap Year\n");
    } else {
        printf("Not a Leap Year\n");
    }

    return 0;
}