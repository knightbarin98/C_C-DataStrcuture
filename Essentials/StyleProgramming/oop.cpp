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

void initialise(struct Rectangle *r, int l, int b)
{
    r->length = l;
    r->breadth = b;
}

int area(struct Rectangle r)
{
    return r.length * r.breadth;
}

int perimeter(struct Rectangle r)
{
    int p;
    p = 2 * (r.length+r.breadth);
    return p;
}

int main()
{
    Rectangle r = {0,0};

    int l,b;
    printf("Enter length and breadt\n");
    cin>>l>>b;

    initialise(&r,l,b);

    int a = area(r);
    int peri = perimeter(r);

    printf("Area: %d\n", area);
    printf("Perimeter: %d\n", peri);
    
    return 0;
}
*/

//In c++ structures can have functions
/*struct Rectangle
{
    int length;
    int breadth;

    void initialise( int l, int b)
    {
        length = l;
        breadth = b;
    }

    int area()
    {
        return length * breadth;
    }

    int perimeter()
    {
        int p;
        p = 2 * (length+breadth);
        return p;
    }
};*/

//With structure by default everything is public, with C++ everything by default is private
class Rectangle
{
public:
    int length;
    int breadth;

    void initialise( int l, int b)
    {
        length = l;
        breadth = b;
    }

    int area()
    {
        return length * breadth;
    }

    int perimeter()
    {
        int p;
        p = 2 * (length+breadth);
        return p;
    }
};


int main()
{
    Rectangle r;

    int l,b;
    printf("Enter length and breadt\n");
    cin>>l>>b;

    r.initialise(l,b);

    int a = r.area();
    int peri = r.perimeter();

    printf("Area: %d\n", a);
    printf("Perimeter: %d\n", peri);
    
    return 0;
}