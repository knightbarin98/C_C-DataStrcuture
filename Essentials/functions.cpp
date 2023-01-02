#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*
1.What are functions
Function a piece of code that performs a task.
Group related statements that perform a task.
2.Parameter passing
    -Pass by value
    -Pass by address
    -Pass by reference
C is a procedural or modular programming

int add(int a, int b) prototype/signature of a function  formal parameters
{
    int c;
    c = a + b;
    return (c);
};

int main()
{
    int z = add(10,15); actual parameters
}

*/

int add(int a, int b)
{
    int c;
    c = a + b;
    return (c);
};

int main()
{   
    int num1 = 10, num2 = 15, sum;

    sum = add(num1,num2);

    printf("%d\n",sum);

    return 0;
}