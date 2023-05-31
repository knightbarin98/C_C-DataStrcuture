#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*
    struct Rectangle r = {10,5};
    struct Rectangle *p = &r;

    r.length = 15;
    (*p).length = 20;
    p -> length = 20;

    struct Rectangle *p;
    p = (strcut Rectangle*)malloc(sizeof(struct Rectangle)); --- dinamic assing on heap

*/

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{   
    //struct Rectangle r = {10,5};
    /*Rectangle r = {10,5};
    cout<<r.length<<endl<<r.breadth<<endl;

    Rectangle *p = &r;*/

    //Rectangle object in heap
    Rectangle *p;
    //with C
    //p=(struct Rectangle *)malloc(sizeof(struct Rectangle));
    //with C++
    
    p = new Rectangle;

    p->length = 15;
    p->breadth = 7;

    cout<<p->length<<endl<<p->breadth<<endl;

    return 0;
}