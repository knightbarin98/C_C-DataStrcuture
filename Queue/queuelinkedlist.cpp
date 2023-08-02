#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;


void enqueque(int x)
{
    struct Node *t;
    t = (struct Node *) malloc(sizeof(struct Node));
    if(t == NULL)
    {
        printf("Queue is full");
        return;

    }
    t->data = x;
    t->next=NULL;
    if(front == NULL) front=rear=t;
    else
    {
        rear->next = t;
        rear = t;
    }
}

int dequeue()
{
    int x = -1;
    struct Node *t;
    if(front == NULL)
    {
        printf("Queue is empty ");
        return -1;
    }

    x = front->data;
    t = front;
    front = front->next;
    free(t);
    return x;
}

void Display(struct Node *p)
{
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{

    enqueque(10);
    enqueque(20);
    enqueque(30);

    Display(front);

    dequeue();

    return 0;
}