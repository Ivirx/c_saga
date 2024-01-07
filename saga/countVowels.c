#include <stdio.h>
#include <string.h>

int countVowels(char str[]);

int main() {
    char inputStr[40];
    printf("Enter the string : ");
    fgets(inputStr, 100, stdin);

    printf("Number of vowels are %d.\n", countVowels(inputStr));

    return 0;
}

int countVowels(char str[]) {
    int vowels = 0;
    char ch;

    for (int i = 0; i < strlen(str); i++) {
        ch = str[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            vowels++;
    }

    return vowels;
}