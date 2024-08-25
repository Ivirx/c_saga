#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PolishNotation {
    char *infixNotation;
    int length;

    char **stack;
    int topOfStack;

    char **postfixNotation;
    int topOfPostfixNotation;

    char **prefixNotation;
    int topOfPrefixNotation;
} PN;

void takeUserInput(PN *n);
void infixToPostfix(PN *n);
void infixToPrefix(PN *n);

void pushStack(char *symbol, PN *n);
char *popStack(PN *n);
char *peekStack(PN *n);
void displayStack(PN *n);

void pushPostfixNotation(char *digits, PN *n);
char *popPostfixNotation(PN *n);
char *peekPostfixNotation(PN *n);
void displayPostfixNotation(PN *n);

void pushPrefixNotation(char *digits, PN *n);
char *popPrefixNotation(PN *n);
char *peekPrefixNotation(PN *n);
void displayPrefixNotation(PN *n);

int isLower(char alreadyIn, char toBeInserted);
int isSymbol(char symbol);

int main() {
    PN *notation = (PN *)malloc(sizeof(PN));

    takeUserInput(notation);

    infixToPostfix(notation);
    displayPostfixNotation(notation);

    infixToPrefix(notation);
    displayPrefixNotation(notation);

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
    n->stack = (char **)malloc(sizeof(char *) * n->length);
    n->topOfStack = -1;
    n->postfixNotation = (char **)malloc(sizeof(char *) * n->length);
    n->topOfPostfixNotation = -1;
    n->prefixNotation = (char **)malloc(sizeof(char *) * n->length);
    n->topOfPrefixNotation = -1;
}

void infixToPostfix(PN *n) {
    char symbol, digits[9], operator[2];
    int position = -1;
    operator[1] = '\0';

    for (int i = 0; i < n->length; i++) {
        symbol = n->infixNotation[i];

        if (symbol == ')') {
            symbol = popStack(n)[0];
            while (symbol != '(' || symbol == '!') {
                operator[0] = symbol;
                pushPostfixNotation(operator, n);
                symbol = popStack(n)[0];
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
                pushPostfixNotation(digits, n);
                position = -1;
                digits[0] = '\0';
            }

        } else {
            while (symbol != '(' && isLower(peekStack(n)[0], symbol)) {
                operator[0] = popStack(n)[0];
                pushPostfixNotation(operator, n);
            }
            operator[0] = symbol;
            pushStack(operator, n);
        }
    }
}

void infixToPrefix(PN *n) {
    char symbol, digits[9], operator[2];
    int position = -1;
    operator[1] = '\0';

    for (int i = n->length - 1; i >= 0; i--) {
        symbol = n->infixNotation[i];
        if (symbol == ')')
            symbol = '(';
        else if (symbol == '(')
            symbol = ')';

        if (symbol == ')') {
            symbol = popStack(n)[0];
            while (symbol != '(' || symbol == '!') {
                operator[0] = symbol;
                pushPrefixNotation(operator, n);
                symbol = popStack(n)[0];
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
                pushPrefixNotation(digits, n);
                position = -1;
                digits[0] = '\0';
            }

        } else {
            while (symbol != '(' && isLower(peekStack(n)[0], symbol)) {
                operator[0] = popStack(n)[0];
                pushPrefixNotation(operator, n);
            }
            operator[0] = symbol;
            pushStack(operator, n);
        }
    }
}

void pushStack(char *symbol, PN *n) {
    if (n->topOfStack == n->length - 1) {
        printf("Overflow, stack is full.\n");
        return;
    }

    n->topOfStack += 1;
    n->stack[n->topOfStack] = (char *)malloc(sizeof(char) * (strlen(symbol) + 1));
    strcpy(n->stack[n->topOfStack], symbol);
}
char *popStack(PN *n) {
    if (n->topOfStack == -1) {
        printf("Underflow, stack is empty.\n");
        return "!";
    }

    n->topOfStack -= 1;
    return n->stack[n->topOfStack + 1];
}
char *peekStack(PN *n) {
    if (n->topOfStack == -1) {
        printf("Underflow, stack is empty.\n");
        return "!";
    }

    return n->stack[n->topOfStack];
}
void displayStack(PN *n) {
    if (n->topOfStack == -1) {
        printf("Underflow, stack is empty.\n");
        return;
    }

    printf("Stack is : ");
    for (int i = 0; i <= n->topOfStack; i++) {
        printf("%s ", n->stack[i]);
    }

    printf("\n");
}

void pushPostfixNotation(char *digits, PN *n) {
    if (n->topOfPostfixNotation == n->length - 1) {
        printf("Overflow, Postfix Notation is full.\n");
        return;
    }

    n->topOfPostfixNotation += 1;
    n->postfixNotation[n->topOfPostfixNotation] = (char *)malloc(sizeof(char) * (strlen(digits) + 1));
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

    printf("Postfix Expression is : ");
    for (int i = 0; i <= n->topOfPostfixNotation; i++) {
        printf("%s ", n->postfixNotation[i]);
    }

    printf("\n");
}

void pushPrefixNotation(char *digits, PN *n) {
    if (n->topOfPrefixNotation == n->length - 1) {
        printf("Overflow, Prefix Notation is full.\n");
        return;
    }

    n->topOfPrefixNotation += 1;
    n->prefixNotation[n->topOfPrefixNotation] = (char *)malloc(sizeof(char) * (strlen(digits) + 1));
    strcpy(n->prefixNotation[n->topOfPrefixNotation], digits);
}
char *popPrefixNotation(PN *n) {
    if (n->topOfPrefixNotation == -1) {
        printf("Underflow, Prefix Notation is empty.\n");
        return NULL;
    }

    n->topOfPrefixNotation -= 1;
    return n->prefixNotation[n->topOfPrefixNotation + 1];
}
char *peekPrefixNotation(PN *n) {
    if (n->topOfPrefixNotation == -1) {
        printf("Underflow, Prefix Notation is empty.\n");
        return NULL;
    }

    return n->prefixNotation[n->topOfPrefixNotation];
}
void displayPrefixNotation(PN *n) {
    if (n->topOfPrefixNotation == -1) {
        printf("Underflow, Prefix Notation is empty.\n");
        return;
    }

    printf("Prefix Expression is : ");
    for (int i = n->topOfPrefixNotation; i >= 0; i--) {
        printf("%s ", n->prefixNotation[i]);
    }

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
