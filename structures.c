#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
    float height;
};

void printInfo(struct Person person);

int main() {
    struct Person p1;
    p1.age = 20;
    p1.height = 171;
    strcpy(p1.name, "John");

    printf("\nP1\n");
    printf("Name : %s\n", p1.name);
    printf("Age : %d\n", p1.age);
    printf("Height : %.2f\n", p1.height);

    // Array of Structure
    struct Person people[10];
    people[0].age = 27;
    people[0].height = 178;
    strcpy(people[0].name, "Didi");

    printf("\nPeople[0]\n");
    printf("Age : %d\n", people[0].age);
    printf("Height : %.2f\n", people[0].height);
    printf("Name : %s\n", people[0].name);

    // Initializing Structure
    struct Person p2 = {"Jane", 22, 172.3};

    printf("\nP2\n");
    printf("Age : %d\n", p2.age);
    printf("Height : %.2f\n", p2.height);
    printf("Name : %s\n", p2.name);

    struct Person p3 = {.age = 23, .height = 173.5, .name = "Jack"};
    printInfo(p3);

    return 0;
}

void printInfo(struct Person person) {
    printf("\n");
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Height: %.2f\n", person.height);
    printf("\n");
}