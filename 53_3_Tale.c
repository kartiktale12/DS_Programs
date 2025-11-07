//53_3_Tale.c

#include <stdio.h>
#define SIZE 10

int stack[SIZE];
int top1 = -1;
int top2 = SIZE;

void push1(int value) {
    if (top1 + 1 == top2)
        printf("\nStack Overflow! No space to push %d in Stack 1\n", value);
    else {
        top1++;
        stack[top1] = value;
        printf("\n%d pushed into Stack 1\n", value);
    }
}

void push2(int value) {
    if (top1 + 1 == top2)
        printf("\nStack Overflow! No space to push %d in Stack 2\n", value);
    else {
        top2--;
        stack[top2] = value;
        printf("\n%d pushed into Stack 2\n", value);
    }
}

void pop1() {
    if (top1 == -1)
        printf("\nStack Underflow! Stack 1 is empty\n");
    else {
        printf("\n%d popped from Stack 1\n", stack[top1]);
        top1--;
    }
}

void pop2() {
    if (top2 == SIZE)
        printf("\nStack Underflow! Stack 2 is empty\n");
    else {
        printf("\n%d popped from Stack 2\n", stack[top2]);
        top2++;
    }
}

void display1() {
    if (top1 == -1)
        printf("\nStack 1 is empty\n");
    else {
        printf("\nStack 1 elements are:\n");
        for (int i = top1; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

void display2() {
    if (top2 == SIZE)
        printf("\nStack 2 is empty\n");
    else {
        printf("\nStack 2 elements are:\n");
        for (int i = top2; i < SIZE; i++)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    int choice, value;

    printf("------ Two Stacks Using Single Array ------\n");

    while (1) {
        printf("\n1. Push Stack 1\n2. Pop Stack 1\n3. Display Stack 1");
        printf("\n4. Push Stack 2\n5. Pop Stack 2\n6. Display Stack 2");
        printf("\n7. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value for Stack 1: ");
                scanf("%d", &value);
                push1(value);
                break;
            case 2:
                pop1();
                break;
            case 3:
                display1();
                break;
            case 4:
                printf("Enter value for Stack 2: ");
                scanf("%d", &value);
                push2(value);
                break;
            case 5:
                pop2();
                break;
            case 6:
                display2();
                break;
            case 7:
                printf("\nExiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
