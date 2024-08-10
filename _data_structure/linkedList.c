#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void generateLinkedList(struct Node **start, int size);
void printList(struct Node *start);
void search(int value, struct Node *start);  // Index of element
void insertNode(int value, int position, struct Node **start);
void deleteNode(int position, struct Node **start);
void deleteAll(struct Node **start);

int main() {
    int SIZE = 10;
    struct Node *start = NULL;
    generateLinkedList(&start, SIZE);
    printList(start);

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

void printList(struct Node *start) {
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

void insertNode(int value, int position, struct Node **start) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (position == 0) {
        newNode->next = *start;
        *start = newNode;
        return;
    }

    struct Node *current = *start;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void deleteNode(int position, struct Node **start) {
    if (*start == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = NULL;

    if (position == 0) {
        temp = *start;
        *start = (*start)->next;
        free(temp);

        return;
    }

    struct Node *current = *start;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    temp = current->next;
    current->next = current->next->next;
    free(temp);
}

void deleteAll(struct Node **start) {
    struct Node *current = *start, *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    *start = NULL;
}
