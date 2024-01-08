#include <stdio.h>

void reverseThis(int arr[], int length);

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int length = sizeof(arr) / sizeof(arr[0]);

    reverseThis(arr, length);
    printf("After reversing the array : ");
    for (int i = 0; i < length; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    return 0;
}

void reverseThis(int arr[], int length) {
    int firstElement, lastElement;

    for (int i = 0; i < (length / 2); i++) {
        firstElement = arr[i];
        lastElement = arr[length - i - 1];

        arr[i] = lastElement;
        arr[length - i - 1] = firstElement;
    }
}