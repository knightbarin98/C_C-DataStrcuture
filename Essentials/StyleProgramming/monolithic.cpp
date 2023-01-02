#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

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