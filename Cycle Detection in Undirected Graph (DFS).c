#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100005

// Adjacency list
int* adj[MAX];
int size[MAX];
bool visited[MAX];

// Add edge
void addEdge(int u, int v) {
    adj[u] = (int*)realloc(adj[u], (size[u] + 1) * sizeof(int));
    adj[u][size[u]++] = v;

    adj[v] = (int*)realloc(adj[v], (size[v] + 1) * sizeof(int));
    adj[v][size[v]++] = u;
}

// DFS to detect cycle
bool dfs(int node, int parent) {
    visited[node] = true;

    for (int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node))
                return true;
        }
        else if (neighbor != parent) {
            return true; // cycle found
        }
    }
    return false;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    // Initialize
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        size[i] = 0;
        visited[i] = false;
    }

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Check all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}