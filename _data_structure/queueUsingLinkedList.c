#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int data;
    struct Queue *next;
};

struct Queue *generateQueue();
void enqueue(int value, struct Queue **queue);
void dequeue(struct Queue **queue);
void display(struct Queue *queue);
void search(int value, struct Queue *queue);
// TODO : Delete the queue
int isEmpty(struct Queue *queue);

int main() {
    struct Queue *queue = generateQueue();

    enqueue(7, &queue);
    enqueue(8, &queue);
    enqueue(2, &queue);
    display(queue);

    dequeue(&queue);
    display(queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);

    display(queue);

    enqueue(6, &queue);
    enqueue(8, &queue);
    enqueue(9, &queue);
    enqueue(2, &queue);
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

void enqueue(int value, struct Queue **queue) {
    if (isEmpty(*queue)) {
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

void dequeue(struct Queue **queue) {
    if (isEmpty(*queue)) {
        printf("Underflow, queue is empty.\n");
        return;
    }

    printf("Deleting %d.\n", (*queue)->data);
    struct Queue *temp = *queue;
    *queue = (*queue)->next;
    free(temp);
}

void display(struct Queue *queue) {
    if (isEmpty(queue)) {
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
    if (isEmpty(queue)) {
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

int isEmpty(struct Queue *queue) {
    return queue == NULL;
}