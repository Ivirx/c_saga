#include <stdio.h>

int main() {
    const int ROWS = 3, COLS = 4;
    int arr[ROWS][COLS];

    // Store elements in the array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    // Display the elements
    printf("Transpose Array:\n");
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            printf("%d\t", arr[j][i]);
        }
        printf("\n");
    }

    return 0;
}
