#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*
int area(int length, int breadth)
{
    return length * breadth;
}

int perimeter(int length, int breadth)
{
    int p;
    p = 2 * (length+breadth);
    return p;
}

int main()
{
    int length = 0, breadth = 0;
    printf("Enter length and breadt\n");
    cin>>length>>breadth;

    int a = area(length, breadth);
    int peri = perimeter(length,breadth);

    printf("Area: %d\n", area);
    printf("Perimeter: %d\n", peri);
    
    return 0;
}
*/

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

    printf("Area: %d\n", a);
    printf("Perimeter: %d\n", peri);
    
    return 0;
}