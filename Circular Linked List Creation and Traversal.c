#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* createCircularList(int n) {
    if (n == 0) return NULL;

    int val;
    scanf("%d", &val);

    struct Node* head = createNode(val);
    struct Node* temp = head;

    for (int i = 1; i < n; i++) {
        scanf("%d", &val);
        temp->next = createNode(val);
        temp = temp->next;
    }

    temp->next = head;
    return head;
}

void printCircularList(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = createCircularList(n);
    printCircularList(head);

    return 0;
}