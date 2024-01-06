#include <stdio.h>

void printHello(char dead[]);  // name of the placeholder is just a placeholder, it can be different from the definition parameter name

int main() {
    char name[] = "John";
    printHello(name);

    return 0;
}

void printHello(char name[]) {
    printf("Hello, %s!", name);
}