#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void dfs(int v, int n) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }

    stack[++top] = v;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n);
        }
    }

    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
