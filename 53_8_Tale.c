//53_8_Tale.c

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 50

char stack[SIZE];
int top = -1;

void push(char ch) {
    if (top == SIZE - 1) {
        printf("Stack Overflow!\n");
    } 
    else {
        stack[++top] = ch;
    }
}
char pop() {
    if (top == -1) {
        return '\0';
    } 
    else {
        return stack[top--];
    }
}
int precedence(char op) {
    if (op == '^') {
        return 3;
    } 
    else if (op == '*' || op == '/' || op == '%') {
        return 2;
    } 
    else if (op == '+' || op == '-') {
        return 1;
    } 
    else {
        return 0;
    }
}
void reverse(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
void infixToPrefix(char infix[]) {
    char postfix[SIZE];
    int i, j;
    char ch, temp;

    reverse(infix);

    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } 
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    top = -1;
    j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } 
        else if (ch == '(') {
            push(ch);
        } 
        else if (ch == ')') {
            while (1) {
                temp = pop();
                if (temp == '(' || temp == '\0') {
                    break;
                }
                postfix[j++] = temp;
            }
        } 
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    reverse(postfix);

    printf("\nPrefix Expression: %s\n", postfix);
}
int main() {
    char infix[SIZE];

    printf("------ Infix to Prefix using Stack ------\n");
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix);

    return 0;
}
