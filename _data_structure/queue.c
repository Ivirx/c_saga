#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int *arr;
    int size;
    int at;
    int nodes;
};

struct Queue *generateQueue(int size);
void push(int value, struct Queue *queue);
void pop(struct Queue *queue);
void display(struct Queue *queue);
void search(int value, struct Queue *queue);

int main() {
    struct Queue *queue = generateQueue(6);

    push(4, queue);
    push(9, queue);
    push(1, queue);
    push(6, queue);
    push(3, queue);
    push(5, queue);
    display(queue);

    pop(queue);
    pop(queue);
    pop(queue);
    pop(queue);
    pop(queue);
    display(queue);

    push(2, queue);
    push(4, queue);
    push(1, queue);
    push(3, queue);
    display(queue);

    search(3, queue);
    search(99, queue);
    search(2, queue);
    search(5, queue);

    return 0;
}

struct Queue *generateQueue(int size) {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->arr = (int *)malloc(sizeof(int) * size);
    queue->size = size;
    queue->at = -1;
    queue->nodes = 0;

    return queue;
}

void push(int value, struct Queue *queue) {
    if (queue->nodes == 0) {
        queue->arr[0] = value;
        queue->at = 0;
        queue->nodes += 1;

        return;
    }

    if (queue->nodes == queue->size) {
        printf("Overflow, queue is full.\n");
        return;
    }

    queue->arr[(queue->at + queue->nodes) % queue->size] = value;
    queue->nodes += 1;
}

void pop(struct Queue *queue) {
    if (queue->nodes == 0) {
        printf("Underflow, queue is empty.\n");
        return;
    }

    printf("Deleting %d.\n", queue->arr[queue->at]);
    queue->at = (queue->at + 1) % queue->size;
    queue->nodes -= 1;
}

void display(struct Queue *queue) {
    if (queue->nodes == 0) {
        printf("Queue is empty.\n");
        return;
    }

    // printf("Size : %d, At : %d, Nodes : %d.\n", queue->size, queue->at, queue->nodes);

    for (int i = queue->at; i < queue->at + queue->nodes; i++) {
        printf("%d\t", queue->arr[i % queue->size]);
    }
    printf("\n");
}

void search(int value, struct Queue *queue) {
    if (queue->nodes == 0) {
        printf("Queue is empty, nothing to search.\n");
        return;
    }

    // printf("Size : %d, At : %d, Nodes : %d.\n", queue->size, queue->at, queue->nodes);

    int flag = 0;
    for (int i = queue->at; i < queue->at + queue->nodes; i++) {
        if (queue->arr[i % queue->size] == value) {
            if (flag == 0)
                printf("%d PRESENT at ", value);
            else
                printf(", ");

            printf("%d", i - queue->at);
            flag = 1;
        }
    }

    if (flag == 1)
        printf(".\n");
    else
        printf("%d NOT PRESENT!\n", value);
}
