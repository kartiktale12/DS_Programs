// 53_17_Tale.c
#include <stdio.h>
#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n;

void createGraph() {
    int edges, src, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d%d", &src, &dest);
        adj[src][dest] = 1;
        adj[dest][src] = 1;
    }
}

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void DFSUtil(int v) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            DFSUtil(i);
        }
    }
}

void DFS(int start) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    printf("DFS Traversal: ");
    DFSUtil(start);
    printf("\n");
}

int main() {
    int choice, start;

    while (1) {
        printf("\n1. Create Graph\n2. BFS Traversal\n3. DFS Traversal\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            createGraph();
        } else if (choice == 2) {
            printf("Enter starting vertex: ");
            scanf("%d", &start);
            BFS(start);
        } else if (choice == 3) {
            printf("Enter starting vertex: ");
            scanf("%d", &start);
            DFS(start);
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
