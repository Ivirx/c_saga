#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void generateLinkedList(struct Node **start, int size);
void printNode(struct Node *start);
void search(int value, struct Node *start);  // Index of element
void delete(struct Node **start);

int main() {
    int SIZE = 10;
    struct Node *start = NULL;
    generateLinkedList(&start, SIZE);
    printNode(start);

    search(0, start);
    search(1, start);
    search(2, start);
    search(3, start);
    search(4, start);
    search(5, start);
    search(6, start);
    search(7, start);
    search(8, start);
    search(9, start);

    delete (&start);

    return 0;
}

// --------------------------------------------------

void generateLinkedList(struct Node **start, int size) {
    struct Node *previous, *current;

    for (int i = 0; i < size; i++) {
        current = (struct Node *)malloc(sizeof(struct Node));

        current->data = rand() % size;
        current->next = NULL;

        if (*start == NULL) {
            *start = current;
            previous = current;
        } else {
            previous->next = current;
            previous = current;
        }
    }
}

void printNode(struct Node *start) {
    struct Node *current = start;
    while (current != NULL) {
        printf("%d \n", current->data);
        current = current->next;
    }
}

void search(int value, struct Node *start) {
    struct Node *current = start;
    int position = 0, flag = 0;

    while (current != NULL) {
        if (current->data == value) {
            if (flag == 0)
                printf("PRESENT at ");
            else
                printf(", ");

            printf("%d", position);
            flag = 1;
        }

        current = current->next;
        position++;
    }

    if (flag == 1)
        printf(".\n");
    else
        printf("NOT PRESENT!\n");
}

void delete(struct Node **start) {
    struct Node *current = *start, *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    *start = NULL;
}

/* struct Node *generate(int size) {
    struct Node *start = NULL, *previous, *current;

    for (int i = 0; i < size; i++) {
        current = (struct Node *)malloc(sizeof(struct Node));

        current->data = i;
        current->next = NULL;

        if (start == NULL) {
            start = current;
            previous = current;
        } else {
            previous->next = current;
            previous = current;
        }
    }

    return start;
} */

/* void printNode(struct Node *start, int size) {
    struct Node *current = start;

    for (int i = 0; i < size; i++) {
        printf("%d \n", current->data);

        current = current->next;
    }
} */

/* void printNode(struct Node *start) {
    struct Node *current = start;
    while (1) {
        printf("%d \n", current->data);

        if (current->next == NULL) break;
        current = current->next;
    }

    struct Node *current = start;
    while (current != NULL) {
        printf("%d \n", current->data);
        current = current->next;
    }
} */

/* void insert(struct Node **start, int position, int value) {
    struct Node *current = *start, *previous = NULL;
    int iterations = 1;

    while (current != NULL) {
        if (position == iterations) {
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = value;

            if (previous == NULL) {  // position is 1
                newNode->next = current;
                *start = newNode;
                break;
            }

            newNode->next = current;
            previous->next = newNode;
            break;
        }

        previous = current;
        current = current->next;
        iterations++;
    }

    if (iterations > position) {
        printf("Position out of bound!");
    }
} */
