#include <stdio.h>
#include <string.h>

#define MAX 1000

int pq[MAX];
int size = 0;

void insert(int x)
{
    pq[size++] = x;

    for (int i = size - 1; i > 0; i--)
    {
        if (pq[i] < pq[i - 1])
        {
            int temp = pq[i];
            pq[i] = pq[i - 1];
            pq[i - 1] = temp;
        }
        else
            break;
    }
}

int deleteMin()
{
    if (size == 0)
        return -1;

    int val = pq[0];

    for (int i = 1; i < size; i++)
        pq[i - 1] = pq[i];

    size--;
    return val;
}

int peek()
{
    if (size == 0)
        return -1;
    return pq[0];
}

int main()
{
    int N;
    char op[10];
    int x;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0)
        {
            scanf("%d", &x);
            insert(x);
        }
        else if (strcmp(op, "delete") == 0)
        {
            printf("%d\n", deleteMin());
        }
        else if (strcmp(op, "peek") == 0)
        {
            printf("%d\n", peek());
        }
    }

    return 0;
}