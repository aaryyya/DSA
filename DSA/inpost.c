#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};

void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, char item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

char peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top];
}

int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char operator) {
    switch (operator) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    initializeStack(&stack);

    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            push(&stack, infix[i++]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && peek(&stack) != '(') {
                printf("Invalid expression\n");
                exit(EXIT_FAILURE);
            } else {
                pop(&stack);
            }
            i++;
        } else {
            while (!isEmpty(&stack) && precedence(infix[i]) <= precedence(peek(&stack))) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i++]);
        }
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

void postfixToInfix(char postfix[], char infix[]) {
    struct Stack stack;
    initializeStack(&stack);

    int i, j;
    i = j = 0;

    while (postfix[i] != '\0') {
        if (isOperand(postfix[i])) {
            push(&stack, postfix[i]);
        } else {
            char operand2 = pop(&stack);
            char operand1 = pop(&stack);
            char temp[MAX_SIZE];

            snprintf(temp, sizeof(temp), "(%c%c%c)", operand1, postfix[i], operand2);

            for (int k = 0; temp[k] != '\0'; k++) {
                push(&stack, temp[k]);
            }
        }
        i++;
    }

    while (!isEmpty(&stack)) {
        infix[j++] = pop(&stack);
    }

    infix[j] = '\0';
}

int main() {
    char expression[MAX_SIZE];
    char result[MAX_SIZE];
    int choice;

    printf("Enter an expression: ");
    scanf("%s", expression);

    printf("Choose operation:\n");
    printf("1. Infix to Postfix\n");
    printf("2. Postfix to Infix\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            infixToPostfix(expression, result);
            printf("Postfix expression: %s\n", result);
            break;
        case 2:
            postfixToInfix(expression, result);
            printf("Infix expression: %s\n", result);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}
