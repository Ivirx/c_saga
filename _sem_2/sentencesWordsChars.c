#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /* Assuming that the string has only the spaces and periods as special characters in it. */
    int len = 1024, sentences = 0, words = 0, chars = 0, ch;
    char *str = (char *)malloc(len * sizeof(char));

    printf("Enter the string (max length of %d) : ", len);
    fgets(str, len, stdin);

    len = strlen(str);
    str = realloc(str, (len + 1) * sizeof(char));

    for (int i = 0; i < len; i++) {
        ch = str[i];

        if (ch == '.')
            sentences++;

        if (ch == ' ' || ch == '.')
            words++;
        else
            chars++;
    }

    printf("Sentences : %d\n", sentences);
    printf("Words : %d\n", words);
    printf("Characters : %d\n", chars);

    free(str);

    return 0;
}