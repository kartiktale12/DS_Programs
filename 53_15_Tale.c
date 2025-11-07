// 53_15_Tale.c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

void printInRange(struct Node* root, int low, int high) {
    if (root == NULL) {
        return;
    }
    if (root->data > low) {
        printInRange(root->left, low, high);
    }
    if (root->data >= low && root->data <= high) {
        printf("%d ", root->data);
    }
    if (root->data < high) {
        printInRange(root->right, low, high);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value, low, high;

    while (1) {
        printf("\n1. Insert Node\n2. Print Range\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            root = insert(root, value);
        } else if (choice == 2) {
            printf("Enter range (low high): ");
            scanf("%d%d", &low, &high);
            printf("Values in range [%d, %d]: ", low, high);
            printInRange(root, low, high);
            printf("\n");
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
