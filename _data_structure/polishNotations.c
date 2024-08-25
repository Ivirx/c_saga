#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PolishNotation {
    char *infixNotation;
    int length;

    char *stack;
    int topOfStack;

    char **postfixNotation;
    int topOfPostfixNotation;
} PN;

void takeUserInput(PN *n);
void infixToPostfix(PN *n);

void pushStack(char data, PN *n);
char popStack(PN *n);
char peekStack(PN *n);
void displayStack(PN *n);

void pushPostfixNotation(char *number, int position, PN *n);
char *popPostfixNotation(PN *n);
char *peekPostfixNotation(PN *n);
void displayPostfixNotation(PN *n);

int isLower(char alreadyIn, char toBeInserted);
int isSymbol(char symbol);

int main() {
    PN *notation = (PN *)malloc(sizeof(PN));

    takeUserInput(notation);
    infixToPostfix(notation);

    printf("Postfix Expression is : ");
    for (int i = 0; i <= notation->topOfPostfixNotation; i++) {
        printf("%s ", notation->postfixNotation[i]);
    }

    return 0;
}

void takeUserInput(PN *n) {
    char input[99];
    printf("Enter the expression : ");
    scanf("%s", input);

    n->infixNotation = (char *)malloc(sizeof(char) * (strlen(input) + 3));  // (expression)\0
    sprintf(n->infixNotation, "(%s)", input);
    n->length = strlen(n->infixNotation);
    printf("Expression : %s\n", n->infixNotation);

    // initializing stacks
    n->stack = (char *)malloc(sizeof(char) * n->length);
    n->topOfStack = -1;
    n->postfixNotation = (char **)malloc(sizeof(char *) * n->length);
    n->topOfPostfixNotation = -1;
}

void infixToPostfix(PN *n) {
    char symbol, digits[9], operator[2];
    int position = -1;
    operator[1] = '\0';

    for (int i = 0; i < n->length; i++) {
        symbol = n->infixNotation[i];

        if (symbol == ')') {
            operator[0] = popStack(n);
            while (operator[0] != '(' || operator[0] == '!') {
                pushPostfixNotation(operator, 2, n);
                operator[0] = popStack(n);
            }
            continue;
        }

        if (!isSymbol(symbol)) {
            position++;
            digits[position] = symbol;

            if (isSymbol(n->infixNotation[i + 1])) {
                // push into the postfix notation if next symbol is not a digit
                position++;
                digits[position] = '\0';
                pushPostfixNotation(digits, position, n);
                position = -1;
                digits[0] = '\0';
            }

        } else {
            while (symbol != '(' && isLower(peekStack(n), symbol)) {
                operator[0] = popStack(n);
                pushPostfixNotation(operator, 2, n);
            }
            pushStack(symbol, n);
        }
    }
}

void pushStack(char data, PN *n) {
    if (n->topOfStack == n->length - 1) {
        printf("Overflow, stack is full.\n");
        return;
    }

    n->topOfStack += 1;
    n->stack[n->topOfStack] = data;
}
char popStack(PN *n) {
    if (n->topOfStack == -1) {
        printf("Underflow, stack is empty.\n");
        return '!';
    }

    n->topOfStack -= 1;
    return n->stack[n->topOfStack + 1];
}
char peekStack(PN *n) {
    if (n->topOfStack == -1) {
        printf("Underflow, stack is empty.\n");
        return '!';
    }

    return n->stack[n->topOfStack];
}
void displayStack(PN *n) {
    if (n->topOfStack == -1) {
        printf("Underflow, stack is empty.\n");
        return;
    }

    for (int i = 0; i <= n->topOfStack; i++)
        printf("%c\t", n->stack[i]);

    printf("\n");
}

void pushPostfixNotation(char *digits, int size, PN *n) {
    if (n->topOfPostfixNotation == n->length - 1) {
        printf("Overflow, Postfix Notation is full.\n");
        return;
    }

    n->topOfPostfixNotation += 1;
    n->postfixNotation[n->topOfPostfixNotation] = (char *)malloc(sizeof(char) * size);
    strcpy(n->postfixNotation[n->topOfPostfixNotation], digits);
}
char *popPostfixNotation(PN *n) {
    if (n->topOfPostfixNotation == -1) {
        printf("Underflow, Postfix Notation is empty.\n");
        return NULL;
    }

    n->topOfPostfixNotation -= 1;
    return n->postfixNotation[n->topOfPostfixNotation + 1];
}
char *peekPostfixNotation(PN *n) {
    if (n->topOfPostfixNotation == -1) {
        printf("Underflow, Postfix Notation is empty.\n");
        return NULL;
    }

    return n->postfixNotation[n->topOfPostfixNotation];
}
void displayPostfixNotation(PN *n) {
    if (n->topOfPostfixNotation == -1) {
        printf("Underflow, Postfix Notation is empty.\n");
        return;
    }

    for (int i = 0; i <= n->topOfPostfixNotation; i++)
        printf("%s\t", n->postfixNotation[i]);

    printf("\n");
}

// ^ * / + -
int isLower(char alreadyIn, char toBeInserted) {
    if (alreadyIn == '(') return 0;

    if (toBeInserted == alreadyIn) return 1;

    if (toBeInserted == '-') return 1;

    if (toBeInserted == '+' && (alreadyIn == '/' || alreadyIn == '*' || alreadyIn == '^')) return 1;

    if (toBeInserted == '/' && (alreadyIn == '*' || alreadyIn == '^')) return 1;

    if (toBeInserted == '*' && (alreadyIn == '^')) return 1;

    return 0;
}

int isSymbol(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^' || symbol == '(' || symbol == ')');
}
