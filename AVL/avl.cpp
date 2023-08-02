#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    int height;  //mantain height of every node
    struct Node *rchild;
} *root = NULL;

int Nodeheight(struct Node * p)
{
    int hl, hr;
    hl = p && p->lchild ?p->lchild->height:0;
    hr = p && p->rchild ?p->rchild->height:0;

    return hl > hr ? hl+1 : hr +1;
}

int BalanceFactor(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild ?p->lchild->height:0;
    hr = p && p->rchild ?p->rchild->height:0;
    return hl - hr;
}

struct Node * LLRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = Nodeheight(p);
    pl->height = Nodeheight(pl);

    if(root == p)
    {
        root = pl;
    }

    return pl;
}

struct Node * LRRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    p->lchild = plr->rchild;
    pl->rchild = plr->lchild;

    plr->rchild = p;
    plr->lchild = pl;
    
    pl->height = Nodeheight(pl);
    p->height = Nodeheight(p);
    plr->height = Nodeheight(plr);

    if(root == p)
    {
        root = plr;
    }

    return plr;
}

struct Node * RRRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;
    p->height = Nodeheight(p);
    pr->height = Nodeheight(pr);

    if(root == p)
    {
        root = pr;
    }

    return pr;
}

struct Node * RLRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;

    prl->lchild = p;
    prl->rchild = pr;
    
    pr->height = Nodeheight(pr);
    p->height = Nodeheight(p);
    prl->height = Nodeheight(prl);

    if(root == p)
    {
        root = prl;
    }

    return prl;
}

struct Node * Rinsert(struct Node *p, int key)
{   
    struct Node *t;

    if(p == NULL)
    {
        t = (struct Node *) malloc(sizeof(struct Node *));
        t->data = key;
        t->height = 1;
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

    p->height = Nodeheight(p);

    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    {
        return LLRotation(p);
    }
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    {
        return LRRotation(p); 
    }
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == -1)
    {
        return RRRotation(p); 
    }
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == 1)
    {
        return RLRotation(p); 
    }

    return p;
}

int main()
{

    return 0;
}