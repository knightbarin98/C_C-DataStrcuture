#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*
int main()
{
    int length = 0, breadth = 0;
    printf("Enter length and breadt\n");
    cin>>length>>breadth;

    int area = length * breadth;
    int peri = 2*(length+breadth);

    printf("Area: %d\n", area);
    printf("Perimeter: %d\n", peri);
    
    return 0;
}
*/

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

    printf("Area: %d\n", a);
    printf("Perimeter: %d\n", peri);
    
    return 0;
}