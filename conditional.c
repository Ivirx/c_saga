#include <stdio.h>

int main()
{
    // Conditional Statements
    // if-else
    /* int age;
    printf("Enter your age : ");
    scanf("%d", &age); */

    /* if (age >= 18) {
      printf("You are an adult.\n");
    } else {
      printf("You are not an adult.\n");
    } */

    // else-if
    /* if (age >= 18) {
      printf("You are an adult.\n");
    } else if (age > 13 && age < 18) {
      printf("You are a teenager.\n");
    } else {
      printf("You are a kid.\n");
    } */

    // Ternary Operator
    /* printf((age >= 18) ? "Adult\n" : "Not Adult\n");
    printf("Can Drive? : %s\n", (age >= 18) ? "Y" : "N");

    char canVote = age > 18 ? 'Y' : 'N';
    printf("Can Vote? : %c\n", canVote); */

    // Switch Case
    /* char grade;
    printf("Enter your Grade : ");
    scanf("%c", &grade);

    switch (grade) {
    case 'a':
      printf("You Scored : 90+\n");
      break;
    case 'b':
      printf("You Scored : 80-89\n");
      break;
    case 'c':
      printf("You Scored : 70-79\n");
      break;
    case 'd':
      printf("You Scored : 60-69\n");
      break;
    case 'e':
      printf("You Scored : 50-59\n");
      break;
    case 'f':
      printf("You Scored : 40-49\n");
      break;
    default:
      printf("Invalid Input\n");
    } */

    // Interesting
    /* int x = 2;
    if ((x = 0)) {
      printf("YES : %d\n", x = 3);
    } else {
      printf("NO: %d\n", x = 69);
    } */

    return 0;
}