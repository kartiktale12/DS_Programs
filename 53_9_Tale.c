//53_9_Tale.c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;


void push(int value) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("\nStack Overflow! Memory not allocated.\n");
    } 
    else {
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        printf("\n%d pushed into stack.\n", value);
    }
}

void pop() {
    struct Node *temp;

    if (top == NULL) {
        printf("\nStack Underflow! No elements to pop.\n");
    } 
    else {
        temp = top;
        printf("\n%d popped from stack.\n", top->data);
        top = top->next;
        free(temp);
    }
}

void display() {
    struct Node *temp;

    if (top == NULL) {
        printf("\nStack is empty.\n");
    } 
    else {
        temp = top;
        printf("\nStack elements are:\n");
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int choice, value;

    printf("------ Stack Implementation using Linked List ------\n");

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
        } 
        else if (choice == 2) {
            pop();
        } 
        else if (choice == 3) {
            display();
        } 
        else if (choice == 4) {
            printf("\nExiting program...\n");
            break;
        } 
        else {
            printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
