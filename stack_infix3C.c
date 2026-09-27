#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = c;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

char peek() {
    if (top == -1)
        return -1;
    else
        return stack[top];
}

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char* infix) {
    char postfix[MAX];
    int i = 0, k = 0;
    char symbol;

    while (infix[i] != '\0') {
        symbol = infix[i];

        if (isalnum(symbol)) {
            postfix[k++] = symbol;
        }
        else if (symbol == '(') {
            push(symbol);
        }

        else if (symbol == ')') {
            while (peek() != '(')
                postfix[k++] = pop();

            pop(); // Remove '('
        }

        else {
            while (top != -1 &&
                   precedence(peek()) >= precedence(symbol))
                postfix[k++] = pop();

            push(symbol);
        }

        i++;
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
