#include <stdio.h>
#include <string.h>

int main() {
    char str[] = {'H', 'e', 'l', 'l', 'o', '\0'};  // have to include null character at the end to make it a string
    printf("%s, length : %d, size : %d\n", str, strlen(str), sizeof(str));

    char str2[] = "Hello";  // automatically adds null character at the end
    printf("%s, length : %d, size : %d\n", str2, strlen(str2), sizeof(str2));

    int i = 0;
    char ch;
    while (1) {
        ch = str[i];
        if (ch == '\0')
            break;
        printf("%c\t", ch);
        i++;
    }

    return 0;
}