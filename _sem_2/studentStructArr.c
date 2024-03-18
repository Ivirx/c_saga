#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int rollNo;
    char name[50];
    int marks;
    char grade;
} Student;

int main() {
    Student students[MAX_STUDENTS];
    int n, i;
    char searchName[50];

    printf("Enter the number of students : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d :\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%d", &students[i].marks);

        if (students[i].marks >= 90)
            students[i].grade = 'A';
        else if (students[i].marks >= 80)
            students[i].grade = 'B';
        else if (students[i].marks >= 70)
            students[i].grade = 'C';
        else if (students[i].marks >= 60)
            students[i].grade = 'D';
        else
            students[i].grade = 'F';
    }

    printf("\nEnter the name of the student to get their marks : ");
    scanf("%s", searchName);

    for (i = 0; i < n; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("Marks of %s are %d with grade %c.\n", searchName, students[i].marks, students[i].grade);
            break;
        }
    }

    if (i == n)
        printf("Student not found.\n");

    return 0;
}