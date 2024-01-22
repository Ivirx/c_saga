#include <stdio.h>

struct player {
    char name[64];
    float battingAvg;
};

int main() {
    struct player p1;
    printf("Enter the name of the player: ");
    scanf("%s", p1.name);
    printf("Enter the batting average of the player: ");
    scanf("%f", &p1.battingAvg);

    printf("\nPlayer Info\n");
    printf("Name: %s\nBatting Average: %.2f\n", p1.name, p1.battingAvg);

    return 0;
}