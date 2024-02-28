#include <stdio.h>

int main() {
    int nth = 7;
    printf("Enter the nth term : ");
    scanf("%d", &nth);

    printf("First %d terms of Fibonacci series are : ", nth);
    int prePre = 0, pre = 1, current = prePre;
    for (int i = 1; i <= nth; i++) {
        printf("%d\t", current);
        current = prePre + pre;

        if (i > 1) {
            prePre = pre;
            pre = current;
        }

        /* if (i > 1) {
          current = prePre + pre;
          prePre = pre;
          pre = current;
        } else {
          current = i;
        }
        printf("%d\t", current); */
    }
    printf("\n");

    return 0;
}