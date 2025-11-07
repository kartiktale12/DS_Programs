// 53_16_Tale.c
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

int findMin(struct Node* root) {
    if (root == NULL) {
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int findMax(struct Node* root) {
    if (root == NULL) {
        return -1;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Insert Node\n2. Find Minimum\n3. Find Maximum\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            root = insert(root, value);
        } else if (choice == 2) {
            int min = findMin(root);
            if (min != -1) {
                printf("Minimum value in BST: %d\n", min);
            } else {
                printf("Tree is empty\n");
            }
        } else if (choice == 3) {
            int max = findMax(root);
            if (max != -1) {
                printf("Maximum value in BST: %d\n", max);
            } else {
                printf("Tree is empty\n");
            }
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
