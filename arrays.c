#include <stdio.h>

int main() {
    int arr[] = {2, 3, 4, 5, 6};

    int arr2[3];
    arr2[0] = 23;
    arr2[1] = 34;
    arr2[2] = 45;

    printf("arr : %p\n", arr);
    printf("arr : %p\n", &arr[0]);

    printf("Element of 'arr' : ");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d, ", arr[i]);
    }

    printf("\nElement of 'arr2' : ");
    for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++) {
        printf("%d, ", arr2[i]);
    }

    int *ptrArr = arr;
    printf("\nElement of 'ptrArr' : %i", *ptrArr);
    printf("\nElement of 'ptrArr' : %i", *(ptrArr + 1));
    printf("\nElement of 'arr' : %i", *(arr + 1));

    return 0;
}