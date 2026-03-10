#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

void push_front(int x){
    if(front == 0){
        printf("Deque Overflow\n");
        return;
    }
    if(front == -1){
        front = rear = 0;
    } else {
        front--;
    }
    deque[front] = x;
}

void push_back(int x){
    if(rear == MAX-1){
        printf("Deque Overflow\n");
        return;
    }
    if(front == -1){
        front = rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
}

void pop_front(){
    if(front == -1){
        printf("Deque Underflow\n");
        return;
    }
    front++;
    if(front > rear){
        front = rear = -1;
    }
}

void pop_back(){
    if(front == -1){
        printf("Deque Underflow\n");
        return;
    }
    rear--;
    if(front > rear){
        front = rear = -1;
    }
}

void get_front(){
    if(front == -1)
        printf("Deque is empty\n");
    else
        printf("%d\n", deque[front]);
}

void get_back(){
    if(front == -1)
        printf("Deque is empty\n");
    else
        printf("%d\n", deque[rear]);
}

void size(){
    if(front == -1)
        printf("0\n");
    else
        printf("%d\n", rear - front + 1);
}

void empty(){
    if(front == -1)
        printf("true\n");
    else
        printf("false\n");
}

void display(){
    if(front == -1){
        printf("Deque is empty\n");
        return;
    }
    for(int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main(){
    int choice, value;

    while(1){
        scanf("%d", &choice);

        switch(choice){

            case 1:
                scanf("%d",&value);
                push_front(value);
                break;

            case 2:
                scanf("%d",&value);
                push_back(value);
                break;

            case 3:
                pop_front();
                break;

            case 4:
                pop_back();
                break;

            case 5:
                get_front();
                break;

            case 6:
                get_back();
                break;

            case 7:
                size();
                break;

            case 8:
                empty();
                break;

            case 9:
                display();
                break;

            case 0:
                return 0;
        }
    }
}