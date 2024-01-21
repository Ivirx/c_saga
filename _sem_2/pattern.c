#include <stdio.h>

void simplePattern(int n);
void invertedPattern(int n);
void reversePattern(int n);
void reverseInvertedPattern(int n);
void trianglePattern(int n);
void evenTrianglePattern(int n);

int main() {
    int number;
    printf("Enter a size : ");
    scanf("%d", &number);

    simplePattern(number);
    invertedPattern(number);
    reversePattern(number);
    reverseInvertedPattern(number);
    trianglePattern(number);
    evenTrianglePattern(number);

    return 0;
}

// --------------------------------------------------

/*

&
& &
& & &
& & & &
& & & & &
& & & & & &

 */

void simplePattern(int n) {
    printf("\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("& ");
        }
        printf("\n");
    }
}

// --------------------------------------------------

/*

& & & & & &
. & & & & &
. . & & & &
. . . & & &
. . . . & &
. . . . . &

 */

void invertedPattern(int n) {
    printf("\n");
    for (int i = n; i >= 1; i--) {
        for (int j = n - i; j >= 1; j--) {
            // printf(". ");
            printf("  ");
        }
        for (int j = 1; j <= i; j++) {
            printf("& ");
        }
        printf("\n");
    }
}

// --------------------------------------------------

/*

& & & & & &
& & & & &
& & & &
& & &
& &
&

 */

void reversePattern(int n) {
    printf("\n");
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("& ");
        }
        printf("\n");
    }
}

// --------------------------------------------------

/*

. . . . . &
. . . . & &
. . . & & &
. . & & & &
. & & & & &
& & & & & &

 */

void reverseInvertedPattern(int n) {
    printf("\n");
    for (int i = 1; i <= n; i++) {
        for (int j = n - i; j >= 1; j--) {
            // printf(". ");
            printf("  ");
        }
        for (int j = 1; j <= i; j++) {
            printf("& ");
        }
        printf("\n");
    }
}

// --------------------------------------------------

/*

. . . . . &
. . . . & & &
. . . & & & & &
. . & & & & & & &
. & & & & & & & & &
& & & & & & & & & & &

 */

void trianglePattern(int n) {
    printf("\n");
    for (int i = 1; i <= n; i++) {
        for (int j = n - i; j >= 1; j--) {
            // printf(". ");
            printf("  ");
        }
        for (int j = 1; j <= i + i - 1; j++) {
            printf("& ");
        }
        /* for (int j = 1; j <= i; j++) {
            printf("& ");
        }
        for (int j = 1; j < i; j++) {
            printf("& ");
        } */
        printf("\n");
    }
}

// --------------------------------------------------

/*

. . . . . &
. . . . & . &
. . . & . & . &
. . & . & . & . &
. & . & . & . & . &
& . & . & . & . & . &

 */

void evenTrianglePattern(int n) {
    printf("\n");
    for (int i = 1; i <= n; i++) {
        for (int j = n - i; j >= 1; j--) {
            // printf(". ");
            printf("  ");
        }
        for (int j = 1; j <= i + i - 1; j++) {
            if (j % 2 == 0)
                printf("  ");  // printf(". ");
            else
                printf("& ");
        }
        /* for (int j = 1; j <= i; j++) {
            if (j % 2 == 0)
                printf("  ");  // printf(". ");
            else
                printf("& ");
        }
        for (int j = i - 1; j >= 1; j--) {
            if (j % 2 == 0)
                printf("  ");  // printf(". ");
            else
                printf("& ");
        } */
        printf("\n");
    }
}

// --------------------------------------------------