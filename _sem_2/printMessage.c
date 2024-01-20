#include <stdio.h>

int main() {
    printf("Hello World!\n");

    // greeting the user input
    char msg[50];
    printf("Enter your name : ");
    scanf("%s", msg);
    printf("\nHello, %s!\n", msg);

    return 0;
}