#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *s, ch;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);

    for (int i = 0; i < strlen(s); i++) {
        ch = s[i];

        if (ch == ' ') {
            printf("\n");
            continue;
        }

        printf("%c", ch);
    }

    return 0;
}
