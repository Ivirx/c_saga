#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    scanf("%s", str);

    int frequencies[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, index;
    for (int i = 0; i < strlen(str); i++)
        if (isdigit(str[i])) {
            index = ((int)str[i]) - 48;
            frequencies[index] += 1;
        }

    for (int i = 0; i <= 9; i++)
        printf("%d ", frequencies[i]);

    return 0;
}