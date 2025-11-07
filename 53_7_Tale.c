//53_7_Tale.c

#include <stdio.h>
#include <ctype.h>
#define SIZE 50

char stack[SIZE];
int top = -1;

void push(char ch) {
    if (top == SIZE - 1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = ch;
}

char pop() {
    if (top == -1)
        return '\0';
    else
        return stack[top--];
}

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}
void infixToPostfix(char infix[]) {
    char postfix[SIZE];
    int i = 0, j = 0;
    char ch, temp;

    printf("\nPostfix Expression: ");

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            printf("%c", ch);
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while ((temp = pop()) != '(')
                printf("%c", temp);
        }
        else {
            while (precedence(stack[top]) >= precedence(ch))
                printf("%c", pop());
            push(ch);
        }
    }

    while (top != -1)
        printf("%c", pop());

    printf("\n");
}

int main() {
    char infix[SIZE];

    printf("------ Infix to Postfix using Stack ------\n");
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
