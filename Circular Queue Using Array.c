#include <stdio.h>

int main()
{
    int n, m, i;
    scanf("%d", &n);

    int q[n];

    for(i = 0; i < n; i++)
        scanf("%d", &q[i]);

    scanf("%d", &m);

    int front = 0;
    int rear = n - 1;

    front = (front + m) % n;

    for(i = 0; i < n; i++)
    {
        printf("%d ", q[(front + i) % n]);
    }

    return 0;
}