#ifndef Queueplusplus_h
#define Queueplusplus_h

#include<stdio.h>
#include<iostream>
using namespace std;

class Node
{
    public:
        Node * lchild;
        int data;
        Node * rchild;

};

class Queue
{
    private:
        int front;
        int rear;
        int size;
        Node **Q;
    public:
        Queue()
        {
            front=rear=-1;
            size=10;
            Q = new Node *[size];
        }
        Queue(int size)
        {
            front =rear= -1;
            this->size = size;
            Q = new Node *[this->size];
        }
        void enqueue(Node  *x);
        Node * dequeue();
        void display();
        int isEmpty();
        ~Queue()
        {
            delete [] Q;
        }    
};

void Queue::enqueue(Node *x)
{
    if(rear == size -1) return;
    rear++;
    Q[rear] = x;
}

Node * Queue::dequeue()
{
    Node * x = NULL;
    if(front == rear) return NULL;
    front ++;
    x = Q[front];
    return x;
}

int Queue::isEmpty()
{
    return front == rear;
}
#endif