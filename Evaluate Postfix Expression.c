#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    struct node *temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int main()
{
    char postfix[100];
    int i = 0;

    fgets(postfix, sizeof(postfix), stdin);

    while (postfix[i] != '\0')
    {
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            int b = pop();
            int a = pop();
            int result;

            if (postfix[i] == '+')
                result = a + b;
            else if (postfix[i] == '-')
                result = a - b;
            else if (postfix[i] == '*')
                result = a * b;
            else
                result = a / b;

            push(result);
        }

        i++;
    }

    printf("%d", pop());

    return 0;
}