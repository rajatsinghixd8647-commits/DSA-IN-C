#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* insertLevelOrder(int arr[], int i, int n) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct TreeNode* root = newNode(arr[i]);
    root->left = insertLevelOrder(arr, 2*i + 1, n);
    root->right = insertLevelOrder(arr, 2*i + 2, n);

    return root;
}

struct TreeNode* findNode(struct TreeNode* root, int val) {
    if (root == NULL)
        return NULL;
    if (root->val == val)
        return root;

    struct TreeNode* left = findNode(root->left, val);
    if (left != NULL)
        return left;

    return findNode(root->right, val);
}

struct TreeNode* LCA(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL)
        return NULL;

    if (root == p || root == q)
        return root;

    struct TreeNode* left = LCA(root->left, p, q);
    struct TreeNode* right = LCA(root->right, p, q);

    if (left != NULL && right != NULL)
        return root;

    return left != NULL ? left : right;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int p_val, q_val;
    scanf("%d %d", &p_val, &q_val);

    struct TreeNode* root = insertLevelOrder(arr, 0, n);

    struct TreeNode* p = findNode(root, p_val);
    struct TreeNode* q = findNode(root, q_val);

    struct TreeNode* ans = LCA(root, p, q);

    if (ans != NULL)
        printf("%d\n", ans->val);

    return 0;
}