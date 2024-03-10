#include <stdio.h>
#include <stdlib.h>

void takeInput(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));

        // printf("Row %d : ", i);
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void addMatrices(int **m1, int **m2, int **result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        result[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Enter rows and columns : ");
    scanf("%d %d", &rows, &cols);

    int **m1 = (int **)malloc(rows * sizeof(int *)),
        **m2 = (int **)malloc(rows * sizeof(int *)),
        **result = (int **)malloc(rows * sizeof(int *));

    printf("Enter elements of matrix 1 : \n");
    takeInput(m1, rows, cols);
    printf("Enter elements of matrix 2 : \n");
    takeInput(m2, rows, cols);

    addMatrices(m1, m2, result, rows, cols);
    printf("Resultant matrix : \n");
    printMatrix(result, rows, cols);

    return 0;
}