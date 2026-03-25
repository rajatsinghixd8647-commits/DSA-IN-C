#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct QueueNode {
    struct Node* node;
    int hd;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Node* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

void verticalOrder(struct Node* root) {
    if (!root) return;

    struct QueueNode queue[2000];
    int front = 0, rear = 0;

    int map[4000][200];
    int count[4000] = {0};

    int offset = 2000;

    queue[rear++] = (struct QueueNode){root, 0};

    while (front < rear) {
        struct QueueNode temp = queue[front++];
        struct Node* node = temp.node;
        int hd = temp.hd + offset;

        map[hd][count[hd]++] = node->data;

        if (node->left)
            queue[rear++] = (struct QueueNode){node->left, temp.hd - 1};

        if (node->right)
            queue[rear++] = (struct QueueNode){node->right, temp.hd + 1};
    }

    for (int i = 0; i < 4000; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}