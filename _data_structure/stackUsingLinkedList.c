#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int data;
    struct Stack *next;
};

struct Stack *generateStack();
void push(int value, struct Stack **stack);
void pop(struct Stack **stack);
void display(struct Stack *stack);
void search(int value, struct Stack *stack);

int main() {
    struct Stack *stack = generateStack();

    push(4, &stack);
    push(8, &stack);
    push(12, &stack);
    display(stack);

    push(7, &stack);
    display(stack);

    search(12, stack);
    search(4, stack);
    search(7, stack);
    search(99, stack);

    pop(&stack);
    pop(&stack);
    display(stack);

    pop(&stack);
    pop(&stack);
    pop(&stack);
    display(stack);

    push(3, &stack);
    push(1, &stack);
    display(stack);

    return 0;
}

struct Stack *generateStack() {
    struct Stack *stack = NULL;
    return stack;
}

void push(int value, struct Stack **stack) {
    if (*stack == NULL) {
        *stack = (struct Stack *)malloc(sizeof(struct Stack));
        (*stack)->data = value;
        (*stack)->next = NULL;

        return;
    }

    struct Stack *newNode = (struct Stack *)malloc(sizeof(struct Stack));
    newNode->data = value;
    newNode->next = *stack;

    *stack = newNode;
}

void pop(struct Stack **stack) {
    if (*stack == NULL) {
        printf("Underflow, stack is empty.\n");
        return;
    }

    printf("Popping %d.\n", (*stack)->data);

    struct Stack *temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}

void display(struct Stack *stack) {
    if (stack == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Stack *current = stack;
    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}

void search(int value, struct Stack *stack) {
    if (stack == NULL) {
        printf("Stack is empty, nothing to search.\n");
        return;
    }

    struct Stack *current = stack;
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
