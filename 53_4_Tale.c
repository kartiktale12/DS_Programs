//53_4_Tale.c

#include <stdio.h>
#define SIZE 10

int a[SIZE];
int front1 = -1, rear1 = -1;
int front2 = SIZE, rear2 = SIZE;

int isFull() { return (rear1 + 1 == rear2); }
int isEmpty1() { return (front1 == -1); }
int isEmpty2() { return (front2 == SIZE); }

void enqueue1(int x) {
    if (isFull()) { printf("\nOverflow! No space for Q1\n"); return; }
    if (front1 == -1) front1 = rear1 = 0;
    else rear1++;
    a[rear1] = x;
    printf("Inserted %d into Q1\n", x);
}

void dequeue1() {
    if (isEmpty1()) { printf("\nUnderflow! Q1 empty\n"); return; }
    printf("Deleted %d from Q1\n", a[front1]);
    if (front1 == rear1) front1 = rear1 = -1;
    else front1++;
}

void display1() {
    if (isEmpty1()) { printf("\nQ1 empty\n"); return; }
    printf("Q1 (front→rear): ");
    for (int i = front1; i <= rear1; i++) printf("%d ", a[i]);
    printf("\n");
}

void enqueue2(int x) {
    if (isFull()) { printf("\nOverflow! No space for Q2\n"); return; }
    if (front2 == SIZE) front2 = rear2 = SIZE - 1;
    else rear2--;
    a[rear2] = x;
    printf("Inserted %d into Q2\n", x);
}

void dequeue2() {
    if (isEmpty2()) { printf("\nUnderflow! Q2 empty\n"); return; }
    printf("Deleted %d from Q2\n", a[front2]);
    if (front2 == rear2) front2 = rear2 = SIZE;
    else front2--;
}

void display2() {
    if (isEmpty2()) { printf("\nQ2 empty\n"); return; }
    printf("Q2 (front→rear): ");
    for (int i = front2; i >= rear2; i--) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int ch, val;
    printf("---- Two Queues Using Single Array ----\n");
    while (1) {
        printf("\n1 Enqueue Q1  2 Dequeue Q1  3 Display Q1\n");
        printf("4 Enqueue Q2  5 Dequeue Q2  6 Display Q2\n");
        printf("7 Exit\nEnter choice: ");
        if (scanf("%d", &ch) != 1) return 0;

        switch (ch) {
            case 1: printf("Value: "); scanf("%d", &val); enqueue1(val); break;
            case 2: dequeue1(); break;
            case 3: display1(); break;
            case 4: printf("Value: "); scanf("%d", &val); enqueue2(val); break;
            case 5: dequeue2(); break;
            case 6: display2(); break;
            case 7: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
