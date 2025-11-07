//53_13_Tale.c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL, *tail = NULL;

void createList() {
    int n, value;
    struct Node *newNode;

    printf("\nEnter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("\nMemory Allocation Failed!\n");
            return;
        }

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } 
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    printf("\nDoubly Linked List Created Successfully!\n");
}

void displayForward() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nList (Forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayReverse() {
    struct Node *temp = tail;

    if (tail == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nList (Reverse): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void insertNode() {
    int pos, value;
    struct Node *newNode, *temp;
    int i;

    printf("\nEnter position to insert (1 for start): ");
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &value);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (pos == 1) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == NULL) {
            tail = newNode;
        }
    } 
    else {
        temp = head;
        for (i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("\nInvalid position!\n");
            free(newNode);
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newNode;
        } 
        else {
            tail = newNode;
        }

        temp->next = newNode;
    }

    printf("\nNode Inserted Successfully!\n");
}

void deleteNode() {
    int pos, i;
    struct Node *temp;

    if (head == NULL) {
        printf("\nList is empty!\n");
        return;
    }

    printf("\nEnter position to delete: ");
    scanf("%d", &pos);

    temp = head;
    for (i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nInvalid position!\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } 
    else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    } 
    else {
        tail = temp->prev;
    }

    free(temp);
    printf("\nNode Deleted Successfully!\n");
}

void reverseList() {
    struct Node *temp = NULL;
    struct Node *current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }

    printf("\nList Reversed Successfully!\n");
}

void sortList() {
    struct Node *i, *j;
    int temp;

    if (head == NULL) {
        printf("\nList is empty!\n");
        return;
    }

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("\nList Sorted Successfully!\n");
}

void findMiddle() {
    struct Node *slow = head, *fast = head;

    if (head == NULL) {
        printf("\nList is empty!\n");
        return;
    }

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("\nMiddle element is: %d\n", slow->data);
}

void sumOfData() {
    int sum = 0;
    struct Node *temp = head;

    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }

    printf("\nSum of all node data = %d\n", sum);
}

void printOddEven() {
    struct Node *temp = head;

    printf("\nOdd Nodes: ");
    while (temp != NULL) {
        if (temp->data % 2 != 0) {
            printf("%d ", temp->data);
        }
        temp = temp->next;
    }

    temp = head;
    printf("\nEven Nodes: ");
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            printf("%d ", temp->data);
        }
        temp = temp->next;
    }

    printf("\n");
}

void detectLoop() {
    struct Node *slow = head, *fast = head;
    int found = 0;

    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("\nLoop Detected in the List!\n");
    } 
    else {
        printf("\nNo Loop Found in the List.\n");
    }
}

int main() {
    int choice;

    printf("------ Menu Driven Doubly Linked List Program ------\n");

    while (1) {
        printf("\n========== MENU ==========\n");
        printf("1. Create List\n");
        printf("2. Display (Forward)\n");
        printf("3. Display (Reverse)\n");
        printf("4. Insert Node\n");
        printf("5. Delete Node\n");
        printf("6. Reverse List\n");
        printf("7. Sort List\n");
        printf("8. Find Middle Node\n");
        printf("9. Sum of Data\n");
        printf("10. Print Odd & Even Nodes\n");
        printf("11. Detect Loop\n");
        printf("12. Exit\n");
        printf("==========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            createList();
        } 
        else if (choice == 2) {
            displayForward();
        } 
        else if (choice == 3) {
            displayReverse();
        } 
        else if (choice == 4) {
            insertNode();
        } 
        else if (choice == 5) {
            deleteNode();
        } 
        else if (choice == 6) {
            reverseList();
        } 
        else if (choice == 7) {
            sortList();
        } 
        else if (choice == 8) {
            findMiddle();
        } 
        else if (choice == 9) {
            sumOfData();
        } 
        else if (choice == 10) {
            printOddEven();
        } 
        else if (choice == 11) {
            detectLoop();
        } 
        else if (choice == 12) {
            printf("\nExiting program... Thank you!\n");
            break;
        } 
        else{
            printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}