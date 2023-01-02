#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*

It can be passed as value or address

int areaValue(struct Rectangle r1)
{
    return r.length * r.breath;
};

int areaReference(struct Rectangle &r1)
{
    return r.length * r.breath;
};

int changeLength(struct Rectangle *p, int length)
{
    p->length = length;
};

int main()
{
    struct Rectangle r = {10,5};
    printf("%d", areaValue(r));
    printf("%d", areaReference(r));
    changeLength(&r,20);
}

struct Test
{
    int A[5];
    int n;
};

int fun(struct Test t1) despite having an array inside the strcuture, this is not treated like a pointer, instead as a value
{
    t1.A[0] = 4; only change the value from A[0] of the t1 in the assigned memory from the function
};

int main()
{
    struct Test t = {{2,4,6,8,10},5};
    fun(t);
}

*/

struct Rectangle
{
    int length;
    int breadth;
};

void funCallByValue(struct Rectangle r)
{
    r.length = 20;
    cout<<"By Value"<<endl<<"Lenght:"<<r.length<<endl<<"Breadth:"<<r.breadth<<endl;
};

void funCallByAddress(struct Rectangle *r)
{
    r->length = 20;
    cout<<"By Address"<<endl<<"Lenght:"<<r->length<<endl<<"Breadth:"<<r->breadth<<endl;
};

struct Rectangle * funStructHeap()
{
    struct Rectangle *p;
    p = new Rectangle;
    //p = (struct Rectangle *)malloc(sizeof(struct Rectangle));

    p->length = 15;
    p->breadth = 7;
    return p;
}

int main()
{
    struct Rectangle r = {10,5};
    funCallByValue(r);
    funCallByAddress(&r);

    printf("Main\nLength: %d\nBreadth: %d\n", r.length, r.breadth);

    struct Rectangle *ptr = funStructHeap();
    cout<<"Struct Heap"<<endl<<"Length:"<<ptr->length<<endl<<"Breadth:"<<ptr->breadth<<endl;

    return 0;
}
