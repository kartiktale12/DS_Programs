//53_10_Tale.c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("\nMemory Allocation Failed! Queue Overflow.\n");
    } 
    else {
        newNode->data = value;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
        } 
        else {
            rear->next = newNode;
            rear = newNode;
        }

        printf("\n%d inserted into queue.\n", value);
    }
}
void dequeue() {
    struct Node *temp;

    if (front == NULL) {
        printf("\nQueue Underflow! No elements to delete.\n");
    } 
    else {
        temp = front;
        printf("\n%d deleted from queue.\n", front->data);
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        free(temp);
    }
}
void display() {
    struct Node *temp;

    if (front == NULL) {
        printf("\nQueue is empty.\n");
    } 
    else {
        temp = front;
        printf("\nQueue elements are:\n");

        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }

        printf("\n");
    }
}
int main() {
    int choice, value;

    printf("------ Queue Implementation using Linked List ------\n");

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &value);
            enqueue(value);
        } 
        else if (choice == 2) {
            dequeue();
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
