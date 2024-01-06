#include <stdio.h>

int main() {
    int var = 20;
    int *add = &var;

    printf("%d\n", var);
    printf("%p\n", &var);
    printf("%p\n", add);
    printf("%d\n", *add);
    printf("%p\n", &add);

    char star = '*';
    char *starAdd = &star;

    printf("Address of 'star' variable : %p\n", starAdd);

    int **add2 = &add;
    printf("Address of 'add' pointer : %p\n", add2);
    printf("Value at 'add' address pointer : %d\n", **add2);

    return 0;
}