#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    char *type;
    char **stack;
    int top;
} Stack;

typedef struct PolishNotations {
    char *infix;
    int length;

    Stack *stack;
    Stack *postfix;
    Stack *prefix;
} PNs;

void init(PNs *n);
void initStack(char *type, Stack **s, int length);

void toPostfix(PNs *n);
void toPrefix(PNs *n);

void push(char *data, Stack *s, int length);
char *pop(Stack *s);
char *peek(Stack *s);
void display(Stack *s);

int isLower(char alreadyIn, char toBeInserted);
int isSymbol(char symbol);

int main() {
    PNs *notation = (PNs *)malloc(sizeof(PNs));
    init(notation);

    toPostfix(notation);
    display(notation->postfix);

    toPrefix(notation);
    display(notation->prefix);

    return 0;
}

void init(PNs *n) {
    char input[99];
    printf("Enter the expression : ");
    scanf("%s", input);

    n->infix = (char *)malloc(sizeof(char) * (strlen(input) + 3));  // (expression)\0
    sprintf(n->infix, "(%s)", input);
    n->length = strlen(n->infix);
    printf("Expression : %s\n", n->infix);

    // Initializing Stacks
    initStack("Stack", &(n->stack), n->length);
    initStack("Postfix Notation", &(n->postfix), n->length);
    initStack("Prefix Notation ", &(n->prefix), n->length);
}

void initStack(char *type, Stack **s, int length) {
    *s = (Stack *)malloc(sizeof(Stack));
    (*s)->type = (char *)malloc(sizeof(char) * (strlen(type) + 1));
    strcpy((*s)->type, type);
    (*s)->stack = (char **)malloc(sizeof(char *) * length);
    (*s)->top = -1;
}

void toPostfix(PNs *n) {
    char symbol, digits[9], operator[2];
    int position = -1;
    operator[1] = '\0';

    for (int i = 0; i < n->length; i++) {
        symbol = n->infix[i];

        if (symbol == ')') {
            operator[0] = pop(n->stack)[0];
            while (operator[0] != '(' || operator[0] == '!') {
                push(operator, n->postfix, n->length);
                operator[0] = pop(n->stack)[0];
            }
            continue;
        }

        if (!isSymbol(symbol)) {
            position++;
            digits[position] = symbol;

            if (isSymbol(n->infix[i + 1])) {
                // push into the postfix notation if next symbol is not a digit
                position++;
                digits[position] = '\0';
                push(digits, n->postfix, n->length);

                // resetting digits
                position = -1;
                digits[0] = '\0';
            }

        } else {
            while (symbol != '(' && isLower(peek(n->stack)[0], symbol)) {
                operator[0] = pop(n->stack)[0];
                push(operator, n->postfix, n->length);
            }
            operator[0] = symbol;
            push(operator, n->stack, n->length);
        }
    }
}

void toPrefix(PNs *n) {
    char symbol, digits[9], operator[2];
    int position = -1;
    operator[1] = '\0';

    for (int i = n->length - 1; i >= 0; i--) {
        symbol = n->infix[i];
        if (symbol == ')')
            symbol = '(';
        else if (symbol == '(')
            symbol = ')';

        if (symbol == ')') {
            operator[0] = pop(n->stack)[0];
            while (operator[0] != '(' || operator[0] == '!') {
                push(operator, n->prefix, n->length);
                operator[0] = pop(n->stack)[0];
            }
            continue;
        }

        if (!isSymbol(symbol)) {
            position++;
            digits[position] = symbol;

            if (isSymbol(n->infix[i - 1])) {
                // push into the postfix notation if next symbol is not a digit

                int start = 0, end = position;
                while (start < end) {
                    char temp = digits[start];
                    digits[start] = digits[end];
                    digits[end] = temp;

                    start++;
                    end--;
                }

                position++;
                digits[position] = '\0';
                push(digits, n->prefix, n->length);

                // resetting digits
                position = -1;
                digits[0] = '\0';
            }

        } else {
            while (symbol != '(' && isLower(peek(n->stack)[0], symbol)) {
                operator[0] = pop(n->stack)[0];
                push(operator, n->prefix, n->length);
            }
            operator[0] = symbol;
            push(operator, n->stack, n->length);
        }
    }

    int start = 0, end = n->prefix->top;
    while (start < end) {
        char *temp = n->prefix->stack[start];
        n->prefix->stack[start] = n->prefix->stack[end];
        n->prefix->stack[end] = temp;

        start++;
        end--;
    }
}

void push(char *data, Stack *s, int length) {
    if (s->top == length - 1) {
        printf("Overflow, %s is full.\n", s->type);
        return;
    }

    s->top += 1;
    s->stack[s->top] = (char *)malloc(sizeof(char) * (strlen(data) + 1));
    strcpy(s->stack[s->top], data);
}

char *pop(Stack *s) {
    if (s->top == -1) {
        printf("Underflow, %s is empty.\n", s->type);
        return "!";
    }

    s->top -= 1;
    return s->stack[s->top + 1];
}

char *peek(Stack *s) {
    if (s->top == -1) {
        printf("Underflow, %s is empty.\n", s->type);
        return "!";
    }

    return s->stack[s->top];
}

void display(Stack *s) {
    if (s->top == -1) {
        printf("Underflow, %s is empty.\n", s->type);
        return;
    }

    printf("%s is : ", s->type);
    for (int i = 0; i <= s->top; i++) {
        printf("%s ", s->stack[i]);
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
