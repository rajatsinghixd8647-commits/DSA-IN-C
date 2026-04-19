#include <stdio.h>
#include <limits.h>

#define MAX 100

int n, m;
int graph[MAX][MAX];
int visited[MAX];

// Function to find vertex with minimum key value
int minKey(int key[]) {
    int min = INT_MAX, min_index = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int primMST() {
    int key[MAX];
    
    // Initialize all keys as infinite
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    // Start from node 1
    key[1] = 0;

    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        int u = minKey(key);
        visited[u] = 1;
        totalWeight += key[u];

        // Update key values of adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

int main() {
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected graph
    }

    int result = primMST();
    printf("%d\n", result);

    return 0;
}
