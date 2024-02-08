#include <stdio.h>

int main() {
    int n;
    printf("Enter the number : ");
    scanf("%d", &n);

    int mockI;
    for (int i = 1; i <= (n * 2) - 1; i++) {
        mockI = i >= n ? (n * 2) - i : i;

        for (int j = 1; j <= (n * 2) - 1; j++) {
            if (j > (n * 2) - mockI) {
                printf("%d ", j - n + 1);
                continue;
            }
            if (j > mockI && j <= (n * 2) - mockI) {
                printf("%d ", n - mockI + 1);
                continue;
            }

            printf("%d ", n - j + 1);
        }

        printf("\n");
    }

    return 0;
}

// 5 5 5 5 5 5 5 5 5
// 5 4 4 4 4 4 4 4 5
// 5 4 3 3 3 3 3 4 5
// 5 4 3 2 2 2 3 4 5
// 5 4 3 2 1 2 3 4 5
// 5 4 3 2 2 2 3 4 5
// 5 4 3 3 3 3 3 4 5
// 5 4 4 4 4 4 4 4 5
// 5 5 5 5 5 5 5 5 5

/* for (int i = 1; i <= n; i++) {
    for (int j = 1; j < (n * 2); j++) {
        if (j > (n * 2) - i) {
            printf("%d ", j - n + 1);
            continue;
        }
        if (j > i && j <= (n * 2) - i) {
            printf("%d ", n - i + 1);
            continue;
        }

        printf("%d ", n - j + 1);
    }

    printf("\n");
}

for (int i = n - 1; i >= 1; i--) {
    for (int j = 1; j < (n * 2); j++) {
        if (j > (n * 2) - i) {
            printf("%d ", j - n + 1);
            continue;
        }
        if (j > i && j <= (n * 2) - i) {
            printf("%d ", n - i + 1);
            continue;
        }

        printf("%d ", n - j + 1);
    }

    printf("\n");
} */