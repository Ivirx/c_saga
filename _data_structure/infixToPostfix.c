#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Infix {
    int size;
    char *infix;
    char *stack;
    char *experssion;
    int stackTop;
    int experssionTop;
};

void pushExpression(char data, struct Infix *stack);
char popExpression(struct Infix *stack);
char peekExpression(struct Infix *stack);

void pushStack(char data, struct Infix *stack);
char popStack(struct Infix *stack);
char peekStack(struct Infix *stack);

int isLower(char toBeInserted, char alreadyIn);

int main() {
    struct Infix *infix = (struct Infix *)malloc(sizeof(struct Infix));

    // Taking Input Infix Expression
    char tempStr[99];
    printf("Enter the Infix Expression : ");
    scanf("%s", tempStr);
    infix->infix = (char *)malloc(sizeof(char) * (strlen(tempStr) + 3));
    sprintf(infix->infix, "(%s)", tempStr);
    infix->size = strlen(infix->infix);
    printf("Entered Infix Expression is : %s\n", infix->infix);

    // Initializing Stacks
    infix->stack = (char *)malloc(sizeof(char) * infix->size);
    infix->experssion = (char *)malloc(sizeof(char) * infix->size);
    infix->stackTop = -1;
    infix->experssionTop = -1;

    char symbol, temp;
    for (int i = 0; i < infix->size; i++) {
        symbol = infix->infix[i];

        if (symbol == ')') {
            temp = popStack(infix);
            while (temp != '(' || temp == '!') {
                pushExpression(temp, infix);
                temp = popStack(infix);
            }
            continue;
        }

        if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^' || symbol == '(') {
            while (symbol != '(' && isLower(symbol, peekStack(infix))) {
                pushExpression(popStack(infix), infix);
            }
            pushStack(symbol, infix);
        } else {
            pushExpression(symbol, infix);
        }
    }

    printf("Postfix Expression is : ");
    for (int i = 0; i <= infix->experssionTop; i++) {
        printf("%c ", infix->experssion[i]);
    }

    return 0;
}

void pushExpression(char data, struct Infix *stack) {
    if (stack->experssionTop == stack->size - 1) {
        printf("Overflow, expression is full.\n");
        return;
    }

    // printf("Pushing in Expression : %c\n", data);

    stack->experssionTop += 1;
    stack->experssion[stack->experssionTop] = data;
}
char popExpression(struct Infix *stack) {
    if (stack->experssionTop == -1) {
        printf("Underflow, expression is empty.\n");
        return '!';
    }

    // printf("Popping from Expression : %c\n", stack->experssion[stack->experssionTop]);

    stack->experssionTop -= 1;
    return stack->experssion[stack->experssionTop + 1];
}
char peekExpression(struct Infix *stack) {
    if (stack->experssionTop == -1) {
        printf("Underflow, expression is empty.\n");
        return '!';
    }

    // printf("Peeking in Expression : %c\n", stack->experssion[stack->experssionTop]);

    return stack->experssion[stack->experssionTop];
}

void pushStack(char data, struct Infix *stack) {
    if (stack->stackTop == stack->size - 1) {
        printf("Overflow, stack is full.\n");
        return;
    }

    // printf("Pushing in Stack : %c\n", data);

    stack->stackTop += 1;
    stack->stack[stack->stackTop] = data;
}
char popStack(struct Infix *stack) {
    if (stack->stackTop == -1) {
        printf("Underflow, expression is empty.\n");
        return '!';
    }

    // printf("Popping from Stack : %c\n", stack->stack[stack->stackTop]);

    stack->stackTop -= 1;
    return stack->stack[stack->stackTop + 1];
}
char peekStack(struct Infix *stack) {
    if (stack->stackTop == -1) {
        printf("Underflow, expression is empty.\n");
        return '!';
    }

    // printf("Peeking in Stack : %c\n", stack->stack[stack->stackTop]);

    return stack->stack[stack->stackTop];
}

// ^ * / + -
int isLower(char toBeInserted, char alreadyIn) {
    if (alreadyIn == '(') return 0;

    if (toBeInserted == alreadyIn) return 1;

    if (toBeInserted == '-') return 1;

    if (toBeInserted == '+' && (alreadyIn == '/' || alreadyIn == '*' || alreadyIn == '^')) return 1;

    if (toBeInserted == '/' && (alreadyIn == '*' || alreadyIn == '^')) return 1;

    if (toBeInserted == '*' && (alreadyIn == '^')) return 1;

    return 0;
}