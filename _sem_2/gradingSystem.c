#include <stdio.h>

int main() {
    int marks[5], m;

    printf("Enter the marks of 5 subjects :\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d : ", i + 1);
        scanf("%d", &marks[i]);
    }

    printf("\nGrades :\n");
    for (int i = 0; i < 5; i++) {
        m = marks[i];
        printf("Subject %d (%d) : ", i + 1, m);

        if (m >= 60 && m <= 100) {
            printf("1st Division\n");
        } else if (m >= 45 && m < 60) {
            printf("2nd Division\n");
        } else if (m >= 35 && m < 45) {
            printf("3rd Division\n");
        } else {
            printf("Fail\n");
        }
    }

    return 0;
}
