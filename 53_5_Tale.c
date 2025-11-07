//53_5_Tale.c

#include <stdio.h>
#include <string.h>

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
int match(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '[' && close == ']') return 1;
    if (open == '{' && close == '}') return 1;
    return 0;
}

int checkBalanced(char exp[]) {
    char ch, temp;
    for (int i = 0; i < strlen(exp); i++) {
        ch = exp[i];
        if (ch == '(' || ch == '{' || ch == '[')
            push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            temp = pop();
            if (!match(temp, ch))
                return 0;
        }
    }

    if (top == -1)
        return 1;
    else
        return 0;
}

int main() {
    char exp[SIZE];

    printf("------ Parenthesis Matching using Stack ------\n");
    printf("Enter an expression: ");
    scanf("%s", exp);

    if (checkBalanced(exp))
        printf("\n Expression is Balanced.\n");
    else
        printf("\n Expression is NOT Balanced.\n");

    return 0;
}
