#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char *name;
    float marks[5];
    float total;
    float percentage;
};

void calculateTotalAndPercentage(struct student *s) {
    s->total = 0;
    s->percentage = 0;

    for (int i = 0; i < 5; i++)
        s->total += s->marks[i];

    s->percentage = (s->total / 500) * 100.0;
}

int main() {
    struct student s1;
    char name[32];
    printf("Enter student's name : ");
    scanf("%s", name);
    s1.name = (char *)malloc(strlen(name + 1) * sizeof(char));
    strcpy(s1.name, name);

    for (int i = 0; i < 5; i++) {
        printf("Enter marks of subject %d : ", i + 1);
        scanf("%f", &s1.marks[i]);
    }

    calculateTotalAndPercentage(&s1);

    printf("Students name : %s\n", s1.name);
    printf("Total Marks : %.2f\n", s1.total);
    printf("Percentage : %.2f%%\n", s1.percentage);

    return 0;
}