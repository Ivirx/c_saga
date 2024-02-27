#include <stdio.h>
#include <string.h>

void maxOccurance(char str[], int length, char *letter, int *maxCount);

int main() {
    char str[] = "The quick brown fox jumps over the lazy dog.", letter;
    int maxCount = 0;

    maxOccurance(str, strlen(str), &letter, &maxCount);
    printf("Maximum occuring letter is '%c', and its frequency is %d.\n", letter, maxCount);

    return 0;
}

void maxOccurance(char str[], int length, char *letter, int *maxCount) {
    int thisCount = 0;
    char ch;

    for (int i = 0; i < length; i++) {
        ch = str[i];
        if (ch == ' ')
            continue;

        thisCount = 0;
        for (int j = 0; j < length; j++) {
            if (ch == str[j])
                thisCount++;
        }

        if (thisCount > *maxCount) {
            *maxCount = thisCount;
            *letter = ch;
        }
    }
}