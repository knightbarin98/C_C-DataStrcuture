#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*

struct Rectangle
{
    int length;
    int breadth;
};

void initializing(struct Rectangle *r, int l, int b)
{   
    r->length = l;
    r->breadth = b;    
};

int area(struct Rectangle r)
{
    return r.length * r.breadth;
};

void changeLength(struct Rectangle *r, int l)
{
   r->length = l;
}

int main()
{
    struct Rectangle r;
    initializing(&r,10,5);
    area(r);
    changeLength(&r,20);

    return 0;
}

*/

class Rectangle
{
    private: int length;
    private: int breadth;

    public: Rectangle(int l, int b)
    {   
        length = l;
        breadth = b;    
    }
    
    public: int area()    
    {
        return length * breadth;
    }

    public: void changeLength(int l)
    {
        length = l;
    }
};


int main()
{
    Rectangle r(10,5);

    r.area();
    r.changeLength(20);
}