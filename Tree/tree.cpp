#include<stdio.h>
#include<stdlib.h>
#include"../Tree/Queue.h"
#include"../Tree/Stack.h"

struct Node *root = NULL;

void create()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    createQ(&q, 100);


    printf("Enter root value");
    scanf("%d", &x);
    root = (struct Node *) malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d :", p->data);
        scanf("%d",&x);
        if(x != -1)
        {
            t = (struct Node *) malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q,t);
        }

        printf("Enter right child of %d: ", p->data);
        scanf("%d",&x);
        if(x != -1)
        {
            t = (struct Node *) malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q,t);
        }
    }
}

void preorder(struct Node *p)
{
    if(p)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node *p)
{
    if(p)
    {
        
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

void postorder(struct Node *p)
{
    if(p)
    {
        
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
        
    }
}

void Ipreorder(struct Node *p)
{
    struct Stack stk;
    Stackcreate(&stk, 100);

    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            printf("%d ", p->data);
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            p = p->rchild;
        }
    }
}

void Iinorder(struct Node *p)
{
    struct Stack stk;
    Stackcreate(&stk, 100);

    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

void Ipostorder(struct Node *p)
{
    struct Stack stk;
    long int temp;
    Stackcreate(&stk, 100);

    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            temp = (long) pop(&stk);
            if(temp > 0)
            {
                push(&stk, (Node *) -temp);
                p = ((Node *) temp)->rchild;
            }
            else
            {
                printf("%d ", p->data);
                p = NULL;
            }
        }
    }
}


void levelorder(struct Node *p)
{
    struct Queue q;
    createQ(&q, 100);

    printf("%d ", p->data);
    enqueue(&q, p);
    while(!isEmpty(q))
    {
        p = dequeue(&q);
        if(p->lchild)
        {
            printf("%d ", p->lchild->data);
            enqueue(&q, p->lchild);
        }

        if(p->rchild)
        {
            printf("%d ", p->rchild->data);
            enqueue(&q, p->rchild);
        }
    }
}


int count(struct Node *p)
{
    if(p)
        return count(p->lchild) + count(p->rchild) +1;
    return 0;    
}

int height(struct Node *p)
{
    int x =0, y=0;
    if(p == NULL) return 0;
    x = height(p->lchild);
    y = height(p->rchild);
    if(x>y)
        return x + 1;
    else
        return y + 1;    
}

int main()
{
    create();
    printf("Count : %d\n", count(root));
    printf("Height: %d\n", height(root));
    return 0;
}