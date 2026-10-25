#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n;

void dfs(int v) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

void bfs(int start) {
    int queue[MAX];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

void resetVisited() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter each edge as two vertex numbers (0 to %d), e.g. 0 1:\n", n - 1);
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    resetVisited();
    printf("\nDFS traversal: ");
    dfs(start);

    resetVisited();
    printf("\nBFS traversal: ");
    bfs(start);
    printf("\n");

    return 0;
}
