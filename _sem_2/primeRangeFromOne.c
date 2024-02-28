#include <stdio.h>

int main() {
    int end;
    printf("Enter the ending point : ");
    scanf("%d", &end);

    printf("Prime numbers between 1 and %d are :  ", end);
    for (int num = 1; num <= end; num++) {
        int flag = 0;
        for (int j = 2; j <= num / 2; j++) {
            if (num % j == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            printf("%d\t", num);
        }
    }
    printf("\n");
}