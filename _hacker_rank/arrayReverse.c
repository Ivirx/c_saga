#include <stdio.h>

int main() {
    int num = 5, arr[] = {1, 2, 3, 4, 5}, i;

    int temp;
    for (i = 0; i < num / 2; i++) {
        temp = arr[i];
        arr[i] = arr[num - 1 - i];
        arr[num - 1 - i] = temp;
    }

    for (i = 0; i < num; i++)
        printf("%d ", *(arr + i));

    return 0;
}