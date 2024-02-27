#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, *arr, sum = 0;

    scanf("%d", &size);
    arr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("%d\n", sum);

    return 0;
}