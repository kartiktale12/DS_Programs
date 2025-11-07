//53_6_Tale.c

#include <stdio.h>
#define SIZE 50

int stack[SIZE];
int top = -1;

void push(int value) {
    if (top == SIZE - 1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = value;
}
int pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int main() {
    int num, rem;

    printf("------ Decimal to Binary using Stack ------\n");
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    int n = num;

    while (num > 0) {
        rem = num % 2;
        push(rem);
        num = num / 2;
    }
    printf("Binary equivalent of %d is: ", n);
    while (top != -1) {
        printf("%d", pop());
    }
    printf("\n");

    return 0;
}
