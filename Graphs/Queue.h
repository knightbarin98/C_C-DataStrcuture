#ifndef Queue_h
#define Queue_h

#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node *next;
}*front=NULL, *rear=NULL;

void *malloc_safe(size_t size)
{
    void* ptr = malloc(size);
    if(ptr == NULL)
        return malloc_safe(size); 
    else
        return ptr;
}

void enqueue(int x)
{
    struct Node *t;
    t = (struct Node *) malloc_safe(sizeof(struct Node));
    if(t == NULL)
    {
        printf("Queue is FULL\n");
    }
    else
    {
        t->data - x;
        t->next = NULL;
        if(front == NULL)
            front=rear=t;
        else
        {
            rear->next=t;
            rear=t;
        }    
    }
}

int dequeue ()
{
    int x =-1;
    struct Node *t;
    if(front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        x = front->data;
        t=front;
        front=front->next;
        free(t);
    }

    return x;
}

int isEmpty()
{
    return front == NULL;
}

#endif