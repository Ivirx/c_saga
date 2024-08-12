/* Stack using array. */

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int *arr;
    int top;
    int size;
};

void generateStack(int size, struct Stack **stack);
void push(int data, struct Stack *stack);
void pop(struct Stack *stack);
void display(struct Stack *);
void search(int value, struct Stack *stack);

int main() {
    struct Stack *myStack = (struct Stack *)malloc(sizeof(struct Stack));

    generateStack(6, &myStack);

    push(10, myStack);
    push(5, myStack);
    push(1, myStack);
    push(8, myStack);

    display(myStack);

    pop(myStack);

    display(myStack);

    push(69, myStack);
    push(3, myStack);
    push(7, myStack);
    push(0, myStack);
    push(0, myStack);
    push(0, myStack);

    display(myStack);
    search(3, myStack);
    search(7, myStack);
    search(420, myStack);

    // pop(myStack);
    // pop(myStack);
    // pop(myStack);
    // pop(myStack);
    // pop(myStack);
    // pop(myStack);
    // pop(myStack);
    // pop(myStack);

    // display(myStack);

    return 0;
}

void generateStack(int size, struct Stack **stack) {
    (*stack)->arr = (int *)malloc(sizeof(int) * size);
    (*stack)->size = size;
    (*stack)->top = -1;
}

void push(int data, struct Stack *stack) {
    if (stack->top == stack->size - 1) {
        printf("Overflow, stack is full.\n");
        return;
    }

    stack->top += 1;
    stack->arr[stack->top] = data;
}

void pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Underflow, stack is empty.\n");
        return;
    }

    printf("Deleting : %d\n", stack->arr[stack->top]);
    stack->top -= 1;
}

void display(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    for (int i = stack->top; i >= 0; i--)
        printf("%d\t", stack->arr[i]);

    printf("\n");
}

void search(int value, struct Stack *stack) {
    int flag = 0;

    for (int i = stack->top; i >= 0; i--) {
        if (stack->arr[i] == value) {
            if (flag == 0)
                printf("%d PRESENT at ", value);
            else
                printf(", ");

            printf("%d", stack->size - i - 1);
            flag = 1;
        }
    }

    if (flag == 1)
        printf(".\n");
    else
        printf("%d NOT PRESENT!\n", value);
}
