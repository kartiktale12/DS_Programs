//53_14_Tale.c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } 
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void BFS(struct Node *root) {
    if (root == NULL) {
        printf("\nTree is empty.\n");
        return;
    }

    struct Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    printf("\nBFS Traversal: ");
    while (front < rear) {
        struct Node *current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
    printf("\n");
}

void DFS(struct Node *root) {
    printf("\nDFS (Preorder): ");
    preorder(root);
    printf("\nDFS (Inorder): ");
    inorder(root);
    printf("\nDFS (Postorder): ");
    postorder(root);
    printf("\n");
}

struct Node* mirror(struct Node *root) {
    struct Node *temp;
    if (root == NULL) {
        return root;
    }

    mirror(root->left);
    mirror(root->right);

    temp = root->left;
    root->left = root->right;
    root->right = temp;

    return root;
}

struct Node* findParent(struct Node *root, int value) {
    if (root == NULL || root->data == value) {
        return NULL;
    }

    if ((root->left != NULL && root->left->data == value) ||
        (root->right != NULL && root->right->data == value)) {
        return root;
    }

    if (value < root->data) {
        return findParent(root->left, value);
    } 
    else {
        return findParent(root->right, value);
    }
}

void findChildren(struct Node *root, int value) {
    if (root == NULL) {
        printf("\nTree is empty.\n");
        return;
    }

    if (root->data == value) {
        if (root->left != NULL) {
            printf("\nLeft Child: %d", root->left->data);
        } 
        else {
            printf("\nLeft Child: NULL");
        }

        if (root->right != NULL) {
            printf("\nRight Child: %d", root->right->data);
        } 
        else {
            printf("\nRight Child: NULL");
        }
        return;
    }

    if (value < root->data) {
        findChildren(root->left, value);
    } 
    else {
        findChildren(root->right, value);
    }
}

void findSibling(struct Node *root, int value) {
    struct Node *parent = findParent(root, value);

    if (parent == NULL) {
        printf("\nNo Sibling (root or not found)\n");
        return;
    }

    if (parent->left != NULL && parent->left->data == value && parent->right != NULL) {
        printf("\nSibling of %d is %d\n", value, parent->right->data);
    } 
    else if (parent->right != NULL && parent->right->data == value && parent->left != NULL) {
        printf("\nSibling of %d is %d\n", value, parent->left->data);
    } 
    else {
        printf("\nNo Sibling Found.\n");
    }
}

void findGrandParent(struct Node *root, int value) {
    struct Node *parent = findParent(root, value);
    if (parent == NULL) {
        printf("\nNo Parent, hence no Grandparent.\n");
        return;
    }

    struct Node *grandParent = findParent(root, parent->data);
    if (grandParent != NULL) {
        printf("\nGrandparent of %d is %d\n", value, grandParent->data);
    } 
    else {
        printf("\nNo Grandparent found.\n");
    }
}

void findUncle(struct Node *root, int value) {
    struct Node *parent = findParent(root, value);
    if (parent == NULL) {
        printf("\nNo Parent, hence no Uncle.\n");
        return;
    }

    struct Node *grandParent = findParent(root, parent->data);
    if (grandParent == NULL) {
        printf("\nNo Grandparent, hence no Uncle.\n");
        return;
    }

    if (grandParent->left == parent && grandParent->right != NULL) {
        printf("\nUncle of %d is %d\n", value, grandParent->right->data);
    } 
    else if (grandParent->right == parent && grandParent->left != NULL) {
        printf("\nUncle of %d is %d\n", value, grandParent->left->data);
    } 
    else {
        printf("\nNo Uncle Found.\n");
    }
}

int main() {
    struct Node *root = NULL;
    int choice, value;
    struct Node *parent;

    printf("------ Binary Search Tree (BST) Menu Driven Program ------\n");

    while (1) {
        printf("\n============ MENU ============\n");
        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. BFS Traversal\n");
        printf("6. DFS Traversal\n");
        printf("7. Mirror Tree\n");
        printf("8. Find Children\n");
        printf("9. Find Sibling\n");
        printf("10. Find Parent\n");
        printf("11. Find Grandparent\n");
        printf("12. Find Uncle\n");
        printf("13. Exit\n");
        printf("==============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
        } 
        else if (choice == 2) {
            printf("\nInorder: ");
            inorder(root);
            printf("\n");
        } 
        else if (choice == 3) {
            printf("\nPreorder: ");
            preorder(root);
            printf("\n");
        } 
        else if (choice == 4) {
            printf("\nPostorder: ");
            postorder(root);
            printf("\n");
        } 
        else if (choice == 5) {
            BFS(root);
        } 
        else if (choice == 6) {
            DFS(root);
        } 
        else if (choice == 7) {
            root = mirror(root);
            printf("\nMirror Created!\n");
        } 
        else if (choice == 8) {
            printf("Enter node value to find children: ");
            scanf("%d", &value);
            findChildren(root, value);
        } 
        else if (choice == 9) {
            printf("Enter node value to find sibling: ");
            scanf("%d", &value);
            findSibling(root, value);
        } 
        else if (choice == 10) {
            printf("Enter node value to find parent: ");
            scanf("%d", &value);
            parent = findParent(root, value);
            if (parent != NULL) {
                printf("\nParent of %d is %d\n", value, parent->data);
            } 
            else {
                printf("\nParent not found (root node or invalid value).\n");
            }
        } 
        else if (choice == 11) {
            printf("Enter node value to find grandparent: ");
            scanf("%d", &value);
            findGrandParent(root, value);
        } 
        else if (choice == 12) {
            printf("Enter node value to find uncle: ");
            scanf("%d", &value);
            findUncle(root, value);
        } 
        else if (choice == 13) {
            printf("\nExiting program... Thank you!\n");
            break;
        } 
        else {
            printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
