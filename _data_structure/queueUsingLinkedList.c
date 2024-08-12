#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int data;
    struct Queue *next;
};

struct Queue *generateQueue();
void push(int value, struct Queue **queue);
void pop(struct Queue **queue);
void display(struct Queue *queue);
void search(int value, struct Queue *queue);
// TODO : Delete the queue

int main() {
    struct Queue *queue = generateQueue();

    push(7, &queue);
    push(8, &queue);
    push(2, &queue);
    display(queue);

    pop(&queue);
    display(queue);
    pop(&queue);
    pop(&queue);
    pop(&queue);

    display(queue);

    push(6, &queue);
    push(8, &queue);
    push(9, &queue);
    push(2, &queue);
    display(queue);

    search(9, queue);
    search(6, queue);
    search(99, queue);

    return 0;
}

struct Queue *generateQueue() {
    struct Queue *queue = NULL;
    return queue;
}

void push(int value, struct Queue **queue) {
    if (*queue == NULL) {
        struct Queue *newNode = (struct Queue *)malloc(sizeof(struct Queue));
        newNode->data = value;
        newNode->next = NULL;

        *queue = newNode;

        return;
    }

    struct Queue *current = *queue;
    while (current->next != NULL) {
        current = current->next;
    }

    struct Queue *newNode = (struct Queue *)malloc(sizeof(struct Queue));
    newNode->data = value;
    newNode->next = NULL;

    current->next = newNode;
}

void pop(struct Queue **queue) {
    if (*queue == NULL) {
        printf("Underflow, queue is empty.\n");
        return;
    }

    printf("Deleting %d.\n", (*queue)->data);
    struct Queue *temp = *queue;
    *queue = (*queue)->next;
    free(temp);
}

void display(struct Queue *queue) {
    if (queue == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Queue *current = queue;
    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}

void search(int value, struct Queue *queue) {
    if (queue == NULL) {
        printf("queue is empty, nothing to search.\n");
        return;
    }

    struct Queue *current = queue;
    int i = 0, flag = 0;
    while (current != NULL) {
        if (current->data == value) {
            if (flag == 0)
                printf("%d PRESENT at ", value);
            else
                printf(", ");

            printf("%d", i);
            flag = 1;
        }

        current = current->next;
        i++;
    }

    if (flag)
        printf(".\n");
    else
        printf("%d NOT PRESENT!\n", value);
}