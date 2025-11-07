// 53_20_Tale.c
#include <stdio.h>
#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

void createGraph() {
    int edges, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v) meaning u -> v: ");
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
    }
}

void topologicalSortUtil(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            topologicalSortUtil(i);
        }
    }
    stack[++top] = v;
}

void topologicalSort() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i);
        }
    }
    printf("Topological Sort: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Create Graph\n2. Topological Sort\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            createGraph();
        } else if (choice == 2) {
            topologicalSort();
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
