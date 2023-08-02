#include<stdio.h>
#include<stdlib.h>


struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
} *root = NULL;


void insert(int key)
{
    struct Node *t = root;
    struct Node *r, *p;

    if(root == NULL)
    {
        p = (struct Node *) malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    
    while(t != NULL)
    {
        r = t;
        if(key < t->data)
        {
            t = t->lchild;
        }
        else if(key > t->data)
        {
            t =  t->rchild;
        }
        else
        {
            return;
        }  
    }

    p = (struct Node *) malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if(key < r->data) r->lchild = p;
    else r->rchild = p;
}


void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

struct Node * search(int key)
{
    struct Node *t = root;
    while(t != NULL)
    {
        if(key == t->data)
        {
            return t;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    return NULL;
}

struct Node * Rinsert(struct Node *p, int key)
{   
    struct Node *t;

    if(p == NULL)
    {
        t = (struct Node *) malloc(sizeof(struct Node *));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data)
    {
        p->lchild = Rinsert(p->lchild, key);
    }
    else if(key > p->data)
    {
        p->rchild = Rinsert(p->rchild, key);
    }

    return p;
}

int height(struct Node *p)
{
    int x=0, y=0;
    if(p == NULL) return 0;
    x = height(p->lchild);
    y = height(p->rchild);
    if(x > y)
    {
        return x + 1;
    }
    else
    {
        return y + 1;
    }
}

struct Node * Inpre(struct Node *p)
{
    while(p && p->rchild != NULL) p = p->rchild;

    return p;
}

struct Node * Insucc(struct Node *p)
{
    while(p && p->lchild != NULL) p = p->lchild;

    return p;
}

struct Node * Delete(struct Node *p, int key)
{
    struct Node *q;

    if(p == NULL) return NULL;

    if(p->lchild == NULL && p->rchild == NULL)
    {
        if(p == root) root = NULL;
        free(p);
        return NULL;
    }

    if(key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        if(height(p->lchild) > height(p->rchild))
        {
            q = Inpre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, p->data);
        }
        else
        {
            q = Insucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, p->data);
        }
    }

    return p;
}

int main()
{
    root = Rinsert(root,10);
    Rinsert(root,5);
    Rinsert(root,20);
    Rinsert(root,8);
    Rinsert(root,30);

    Inorder(root);
    printf("\n");

    struct Node *t = search(5);
    if(t != NULL)
    {
        printf("Search result : %d\n", t->data );
    }
    else
    {
        printf("Element not found\n");
    }

    struct Node *del = Delete(root,10);
    printf("Delete : %d\n", del->data);

    Inorder(root);
    printf("\n");

    return 0;
}