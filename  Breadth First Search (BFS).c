#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if(rear == MAX - 1) return;
    if(front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if(front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

void bfs(int n, int adj[MAX][MAX], int s) {
    int visited[MAX] = {0};
    
    enqueue(s);
    visited[s] = 1;

    while(!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for(int i = 0; i < n; i++) {
            if(adj[node][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, m, u, v, s;
    int adj[MAX][MAX] = {0};

    scanf("%d", &n);
    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    scanf("%d", &s);

    bfs(n, adj, s);

    return 0;
}