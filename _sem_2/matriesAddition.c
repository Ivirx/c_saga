#include <stdio.h>

int main() {
    const int ROWS = 3, COLS = 3;

    int m1[3][3];
    int m2[3][3];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            m1[i][j] = i + j;
            m2[j][i] = i * j;
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d + %d = %d\t", m1[i][j], m2[i][j], m1[i][j] + m2[i][j]);
        }
        printf("\n");
    }

    return 0;
}