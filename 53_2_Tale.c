//53_2_Tale.c
#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1)
        printf("\nQueue Overflow! Cannot insert %d\n", value);
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("\n%d inserted into queue\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("\nQueue Underflow! Nothing to delete\n");
    else {
        printf("\n%d deleted from queue\n", queue[front]);
        front++;
        if (front > rear)
            front = rear = -1;
    }
}

void display() {
    if (front == -1)
        printf("\nQueue is empty\n");
    else {
        printf("\nQueue elements are:\n");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, value;

    printf("------ Queue Implementation using Array ------\n");

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
