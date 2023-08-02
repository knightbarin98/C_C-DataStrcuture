#include<iostream>
using namespace std;
#include "../Tree/Queueplusplus.h"

class Tree
{
    public:
        Node *root;
        Tree()
        {
            root = NULL;
        }
        void createTree();
        void preorder(Node *p);
        void postorder(Node *p);
        void inorder(Node *p);
        void levelorder(Node *p);
        int count(Node *p);
        int height(Node *p);

};


void Tree::createTree()
{
    struct Node *p, *t;
    int x;
    Queue q(100);


    cout<<"Enter root value";
    cin>>x;
    cout<<endl;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while(!q.isEmpty())
    {
        p = q.dequeue();
        cout<<"Enter right child of "<<p->data<<endl;
        cin>>x;
        cout<<endl;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }

        cout<<"Enter right child of "<<p->data<<endl;
        cin>>x;
        cout<<endl;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::preorder(Node *p)
{
    if(p)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void Tree::inorder(Node *p)
{
    if(p)
    {
        
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

void Tree::postorder(Node *p)
{
    if(p)
    {
        
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
        
    }
}

void Tree::levelorder(Node *p)
{
    Queue q(100);
    cout<<root->data<<endl;

    while(!q.isEmpty())
    {
        root = q.dequeue();
        if(root->lchild)
        {
            cout<<root->lchild->data;
            q.enqueue(root->lchild);
        }

        if(root->rchild)
        {
            cout<<root->rchild->data;
            q.enqueue(root->rchild);
        }

    }
    
}

int Tree::count(Node *p)
{
    if(root)
        return count(root->lchild)+count(root->rchild) +1;
    return 0;    
}

int Tree::height(Node *p)
{
    int x=0,y=0;
    if(root == NULL) return 0;
    x = height(root->lchild);
    y = height(root->rchild);
    if(x > y)
        return x+1;
    else
        return y+1;    
}

int main()
{
    Tree t;
    t.createTree();
    //t.height(t.root);
    return 0;
}