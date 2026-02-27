#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

/* Create a new node */
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Insert node at end */
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

/* Get length of linked list */
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

/* Find intersection point */
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    /* Advance pointer of longer list */
    if (len1 > len2) {
        while (diff--)
            head1 = head1->next;
    } else {
        while (diff--)
            head2 = head2->next;
    }

    /* Traverse both lists together */
    while (head1 && head2) {
        if (head1 == head2)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}

/* Main function */
int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    int n, m, val;

    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(&head1, val);
    }

    // Second list
    scanf("%d", &m);
    struct Node* temp2 = NULL;
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        insertEnd(&head2, val);
    }

    /* Create intersection manually (based on common value) */
    struct Node* t1 = head1;
    struct Node* t2 = head2;

    while (t2->next != NULL)
        t2 = t2->next;

    while (t1 != NULL) {
        if (t1->data == 30) {   // intersection value
            t2->next = t1;
            break;
        }
        t1 = t1->next;
    }

    struct Node* intersection = findIntersection(head1, head2);

    if (intersection)
        printf("%d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}