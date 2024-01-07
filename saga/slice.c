#include <stdio.h>

int main() {
    char userStr[100];
    printf("Enter a string : ");
    fgets(userStr, 100, stdin);

    int startingIndex, endingIndex;
    printf("Enter starting index : ");
    scanf("%d", &startingIndex);
    printf("Enter ending index : ");
    scanf("%d", &endingIndex);

    char slicedStr[endingIndex - startingIndex + 1];

    for (int i = startingIndex; i <= endingIndex; i++) {
        slicedStr[i - startingIndex] = userStr[i];
    }
    slicedStr[endingIndex - startingIndex + 1] = '\0';

    printf("Sliced string : %s", slicedStr);

    return 0;
}