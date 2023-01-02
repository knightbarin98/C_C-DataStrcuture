#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*
Call by value
send to a function values from main, but not be affected directed
the function creates their own values with their own address and in the end are destroyed

swap(int x, int y)  formal parameters  x address 300/301 y address 302/302 temp 403/404
{
    int temp;
    temp = x;
    x = y ;
    y = temp;
}

int main()
{
    int a = 10, b = 5;
    swap(a,b);  actual parameters a 201/202 b 203/204 
    printf("%d %d", a, b); ---> 10 5
}

the values are swap but only in the scope of the function.
NOte functions' values are created in the stack memory, but not in the memory reserved on the main code workload


Call by address
Use pointers to refer to addresses and values from the parameters to be affected, indirectly 

swap(int *x, int *y)  formal parameters are pointers x value 201 y value 203 temp 403/404
{
    int temp;
    temp = *x;
    *x = *y ;
    *y = temp;
}

int main()
{
    int a = 10, b = 5;
    swap(&a,&b);  actual parameters a 201/202 b 203/204 
    printf("%d %d", a, b); ---> 5 10
}


Call by reference (just in C++)

swap(int &x, int &y)  formal parameters are references
{
    int temp;
    temp = x;
    x = y ;
    y = temp;
}

int main()
{
    int a = 10, b = 5;
    swap(a,b);  actual parameters a 201/202 b 203/204 
    printf("%d %d", a, b); ---> 5 10
}

*/


int add( int a, int b)  // call by value
{
    int c;
    c = a + b;
    return c;
};

void swapAddress( int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swapReferences(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main()
{
    //call by value
    int num1, num2, sum;
    num1 = 10;
    num2 = 5;
    sum = add(num1,num2);
    cout<<"Sum is "<<sum<<endl;

    //Call by address
    int a = 10, b = 15;
    swapAddress(&a, &b);

    cout<<"First number "<<a<<endl;
    cout<<"Second number "<<b<<endl;

    //Call by reference
    //Calls work by the support of inline function concept, but depends on the compiler
    //compiler can interpret it as pointers, in syntax are as reference
    int r = 10, s= 5;
    swap(r,s);
    cout<<"First number "<<r<<endl;
    cout<<"Second number "<<s<<endl;

    return 0;
}