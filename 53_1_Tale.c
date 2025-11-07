// 53_1_Tale.c
#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

void push(int value) {
    if (top == SIZE - 1)
        printf("\nStack Overflow! Cannot push %d\n", value);
    else {
        top++;
        stack[top] = value;
        printf("\n%d pushed into stack\n", value);
    }
}

void pop() {
    if (top == -1)
        printf("\nStack Underflow! Nothing to pop\n");
    else {
        printf("\n%d popped from stack\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1)
        printf("\nStack is empty\n");
    else {
        printf("\nStack elements are:\n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}
int main() {
    int choice, value;

    printf("------ Stack Implementation using Array ------\n");

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

