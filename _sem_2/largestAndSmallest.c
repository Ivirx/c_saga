#include <stdio.h>

int main() {
    int numbers[10], smallest, largest;
    printf("Enter the numbers : ");
    for (int i = 0; i < 10; i++)
        scanf("%d", &numbers[i]);

    smallest = numbers[0];
    largest = numbers[0];

    for (int i = 0; i < 10; i++) {
        if (numbers[i] < smallest)
            smallest = numbers[i];
        if (numbers[i] > largest)
            largest = numbers[i];
    }

    printf("Smallest number is %d.\n", smallest);
    printf("Largest number is %d.\n", largest);

    return 0;
}