#ifndef Queue_h
#define Queue_h

#include<stdio.h>
#include<stdlib.h>


struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};


struct Queue
{
    int size;
    int front;
    int rear;
    Node **Q;
};

void createQ(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (Node **) malloc(q->size*sizeof(Node *));
}

void enqueue(struct Queue *q, Node  *x)
{
    if((q->rear+1)%q->size == q->size -1)
    {
        printf("Queue is full");
        return ;
    } 

    q->rear = (q->rear+1)%q->size; // to apply circular queue and return to the beginning
    q->Q[q->rear] = x;
}

Node * dequeue (struct Queue *q)
{
    Node  *x = NULL;
    if(q->front == q->rear) return NULL;
    q->front = (q->front +1)%q->size;
    x=q->Q[q->front];
    return x;
}

int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}

#endif