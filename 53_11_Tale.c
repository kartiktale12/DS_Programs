//53_11_Tale.c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define SIZE 50

int stack[SIZE];
int top = -1;

void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack Overflow!\n");
    } 
    else {
        stack[++top] = value;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return 0;
    } 
    else {
        return stack[top--];
    }
}

int evaluatePostfix(char exp[]) {
    int i = 0;
    char ch;
    int op1, op2, result;

    while ((ch = exp[i++]) != '\0') {
        if (isdigit(ch)) {
            push(ch - '0');
        } 
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            op1 = pop();
            op2 = pop();

            switch (ch) {
                case '+': {
                    result = op2 + op1;
                    break;
                }
                case '-': {
                    result = op2 - op1;
                    break;
                }
                case '*': {
                    result = op2 * op1;
                    break;
                }
                case '/': {
                    result = op2 / op1;
                    break;
                }
                case '^': {
                    result = pow(op2, op1);
                    break;
                }
                default: {
                    printf("Invalid operator encountered!\n");
                    return 0;
                }
            }
            push(result);
        } 
        else if (ch == ' ' || ch == '\t') {
            continue;
        } 
        else {
            printf("Invalid character in expression: %c\n", ch);
            return 0;
        }
    }
    return pop();
}
int main() {
    char exp[SIZE];
    int result;

    printf("------ Arithmetic Expression Evaluation using Stack ------\n");
    printf("Enter a valid postfix expression (use single-digit operands): ");
    scanf("%s", exp);

    result = evaluatePostfix(exp);
    printf("\nResult of expression %s = %d\n", exp, result);

    return 0;
}
