#include <stdio.h>
#include <stdlib.h>

void takeInput(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));

        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
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
    int a, b, p, q;
    printf("Enter row and columns of 1st matrix : ");
    scanf("%d %d", &a, &b);
    printf("Enter row and columns of 2nd matrix : ");
    scanf("%d %d", &p, &q);

    if (b != p || a == 0 || b == 0 || p == 0 || q == 0) {
        printf("Invalid Inputs!");
        return 1;
    }

    int **m1 = (int **)malloc(a * sizeof(int *)),
        **m2 = (int **)malloc(p * sizeof(int *)),
        **result = (int **)malloc(a * sizeof(int *));

    printf("Enter elements of matrix 1 : \n");
    takeInput(m1, a, b);
    printf("Enter elements of matrix 2 : \n");
    takeInput(m2, p, q);

    for (int i = 0; i < a; i++) {
        result[i] = (int *)malloc(q * sizeof(int));

        for (int j = 0; j < q; j++) {
            result[i][j] = 0;

            for (int k = 0; k < b; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    printf("Resultant Matrix : \n");
    printMatrix(result, a, q);

    free(m1);
    free(m2);
    free(result);

    return 0;
}
