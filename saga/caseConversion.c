#include <stdio.h>
#include <string.h>

void lowerToUpper(char str[]);
void viceVersa(char str[]);

int main() {
    char str[] = "The quick brown fox jumps over the lazy dog.";
    lowerToUpper(str);
    puts(str);

    char str2[] = "thE QuiCk BrOWn fOX juMpS oVeR THE LaZY dOg.";
    puts(str2);
    viceVersa(str2);
    puts(str2);

    return 0;
}

void lowerToUpper(char str[]) {
    char ch;

    for (int i = 0; i < strlen(str); i++) {
        ch = str[i];

        switch (ch) {
            case 'a':
                str[i] = 'A';
                break;
            case 'e':
                str[i] = 'E';
                break;
            case 'i':
                str[i] = 'I';
                break;
            case 'o':
                str[i] = 'O';
                break;
            case 'u':
                str[i] = 'U';
                break;
            default:
                str[i] = ch;
                break;
        }
    }
}

void viceVersa(char str[]) {
    const int CONSTANT = 32;
    char ch;

    for (int i = 0; i < strlen(str); i++) {
        ch = str[i];

        if (ch >= 65 && ch <= 90)  // A - Z
            str[i] = ch + CONSTANT;

        if (ch >= 97 && ch <= 122)  // a - z
            str[i] = ch - CONSTANT;
    }
}
