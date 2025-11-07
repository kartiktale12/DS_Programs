// 53_18_Tale.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int isEndOfWord;
};

struct TrieNode* createNode() {
    struct TrieNode *node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(struct TrieNode *root, const char *key) {
    struct TrieNode *p = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (p->children[index] == NULL) {
            p->children[index] = createNode();
        }
        p = p->children[index];
    }
    p->isEndOfWord = 1;
}

int search(struct TrieNode *root, const char *key) {
    struct TrieNode *p = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (p->children[index] == NULL) {
            return 0;
        }
        p = p->children[index];
    }
    return p->isEndOfWord;
}

int main() {
    struct TrieNode *root = createNode();
    int choice;
    char key[50];

    while (1) {
        printf("\n1. Insert Key\n2. Search Key\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter word to insert: ");
            scanf("%s", key);
            insert(root, key);
            printf("Inserted successfully.\n");
        } 
        else if (choice == 2) {
            printf("Enter word to search: ");
            scanf("%s", key);
            if (search(root, key)) {
                printf("Key found in Trie.\n");
            } 
            else {
                printf("Key not found.\n");
            }
        } 
        else if (choice == 3) {
            break;
        } 
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
