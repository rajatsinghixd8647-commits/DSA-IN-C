#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node* curr = head;
    int count = 1;

    while (curr->next != NULL) {
        curr = curr->next;
        count++;
    }

    curr->next = head;

    k = k % count;
    int steps = count - k;

    struct Node* temp = head;
    for (int i = 1; i < steps; i++)
        temp = temp->next;

    head = temp->next;
    temp->next = NULL;

    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* node = createNode(val);

        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k);
    printList(head);

    return 0;
}