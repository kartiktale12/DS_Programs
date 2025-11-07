//53_12_Tale.c

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head1 = NULL;
struct Node *head2 = NULL;

struct Node* createList() {
    struct Node *head = NULL, *newNode, *temp;
    int n, value;

    printf("\nEnter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("\nMemory Allocation Failed!\n");
            return head;
        }

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } 
        else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    printf("\nLinked List Created Successfully!\n");
    return head;
}
void display(struct Node *head) {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nLinked List: ");
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* insertNode(struct Node *head) {
    int pos, value;
    struct Node *newNode, *temp;
    int i;

    printf("\nEnter position to insert (1 for start): ");
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &value);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
    } 
    else {
        temp = head;
        for (i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("\nPosition out of range!\n");
        } 
        else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    return head;
}

struct Node* deleteNode(struct Node *head) {
    int pos, i;
    struct Node *temp, *del;

    printf("\nEnter position to delete: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("\nList is empty!\n");
        return head;
    }

    if (pos == 1) {
        del = head;
        head = head->next;
        free(del);
        printf("\nNode deleted successfully.\n");
        return head;
    }

    temp = head;
    for (i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("\nPosition out of range!\n");
    } 
    else {
        del = temp->next;
        temp->next = del->next;
        free(del);
        printf("\nNode deleted successfully.\n");
    }

    return head;
}

struct Node* reverseList(struct Node *head) {
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    printf("\nList Reversed Successfully!\n");
    return prev;
}

void findMiddle(struct Node *head) {
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

struct Node* sortList(struct Node *head) {
    struct Node *i, *j;
    int temp;

    if (head == NULL) {
        printf("\nList is empty!\n");
        return head;
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
    return head;
}

void detectLoop(struct Node *head) {
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
        printf("\nLoop detected in the list!\n");
    } 
    else {
        printf("\nNo loop found in the list.\n");
    }
}

void sumOfData(struct Node *head) {
    int sum = 0;
    struct Node *temp = head;

    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }

    printf("\nSum of all node data = %d\n", sum);
}
void printOddEven(struct Node *head) {
    struct Node *temp = head;

    printf("\nOdd Data: ");
    while (temp != NULL) {
        if (temp->data % 2 != 0) {
            printf("%d ", temp->data);
        }
        temp = temp->next;
    }

    temp = head;
    printf("\nEven Data: ");
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            printf("%d ", temp->data);
        }
        temp = temp->next;
    }

    printf("\n");
}

struct Node* mergeLists(struct Node *l1, struct Node *l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }

    if (l1->data < l2->data) {
        l1->next = mergeLists(l1->next, l2);
        return l1;
    } 
    else {
        l2->next = mergeLists(l1, l2->next);
        return l2;
    }
}

int main() {
    struct Node *head = NULL;
    int choice;

    printf("------ Menu Driven Linked List Program ------\n");

    while (1) {
        printf("\n=========== MENU ===========\n");
        printf("1. Create Linked List\n");
        printf("2. Display\n");
        printf("3. Insert Node\n");
        printf("4. Delete Node\n");
        printf("5. Reverse List\n");
        printf("6. Sort List\n");
        printf("7. Find Middle Node\n");
        printf("8. Detect Loop\n");
        printf("9. Sum of Data\n");
        printf("10. Print Odd & Even Data\n");
        printf("11. Create and Merge Two Lists\n");
        printf("12. Exit\n");
        printf("============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            head = createList();
        } 
        else if (choice == 2) {
            display(head);
        } 
        else if (choice == 3) {
            head = insertNode(head);
        } 
        else if (choice == 4) {
            head = deleteNode(head);
        } 
        else if (choice == 5) {
            head = reverseList(head);
        } 
        else if (choice == 6) {
            head = sortList(head);
        } 
        else if (choice == 7) {
            findMiddle(head);
        } 
        else if (choice == 8) {
            detectLoop(head);
        } 
        else if (choice == 9) {
            sumOfData(head);
        } 
        else if (choice == 10) {
            printOddEven(head);
        } 
        else if (choice == 11) {
            printf("\nCreate List 1:\n");
            head1 = createList();
            printf("\nCreate List 2:\n");
            head2 = createList();
            printf("\nMerging Lists...\n");
            head = mergeLists(head1, head2);
            printf("\nMerged List: ");
            display(head);
        } 
        else if (choice == 12) {
            printf("\nExiting program... Thank you!\n");
            break;
        } 
        else {
            printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}
