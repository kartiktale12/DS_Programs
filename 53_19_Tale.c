// 53_19_Tale.c
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int n, adj[MAX][MAX], visited[MAX], disc[MAX], low[MAX], parent[MAX], timeCount;
int isBiconnectedFlag = 1;

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
        parent[i] = -1;
    }

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

void DFS_Biconnected(int u) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeCount;
    int children = 0;

    for (int v = 0; v < n; v++) {
        if (adj[u][v]) {
            if (!visited[v]) {
                children++;
                parent[v] = u;
                DFS_Biconnected(v);
                if (low[v] >= disc[u] && parent[u] != -1) {
                    isBiconnectedFlag = 0;
                }
                if (low[v] < low[u]) {
                    low[u] = low[v];
                }
            } 
            else if (v != parent[u] && disc[v] < low[u]) {
                low[u] = disc[v];
            }
        }
    }

    if (parent[u] == -1 && children > 1) {
        isBiconnectedFlag = 0;
    }
}

int main() {
    int start;
    createGraph();
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    timeCount = 0;
    isBiconnectedFlag = 1;
    DFS_Biconnected(start);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            isBiconnectedFlag = 0;
            break;
        }
    }

    if (isBiconnectedFlag) {
        printf("Graph is Bi-Connected.\n");
    } else {
        printf("Graph is NOT Bi-Connected.\n");
    }

    return 0;
}
