#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*

Arrays can be passed only by address,not by value neither in C or C++

void fun(int A[], int n) formal parameters A it basically a pointer, n it just a call by value
{
    for(int i = 0; i < n; i++)
    {
        printf("%d", A[i]);
    }
};

int main()
{
    int A[5] = {2,4,6,8,10};
    fun(A,5);
}

Return an array
int [] fun(int n)  you can use * or [], some compilers do not support [] 
{
    int * p;
    p (int *) malloc(sizeof(int) * n); create an array in heap
    return (p);
}

int main()
{
    int *A;
    A = fun(5); an array pointing to an array in heap
}


*/

void printSizeOfArray(int A[])
{
    cout<<sizeof(A)/sizeof(int)<<endl; // print 2 because arrays are passed as address
};

/*void printValuesArrayWithEach(int A[])
{
    for(int x: A)
    {
        cout<<x<<endl; //we cannot use for each in a pointer
    }
};*/

void printValuesArrayWithFor(int A[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<A[i]<<endl; 
    }
};

void printValuesArrayWithForWithStar(int * A, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<A[i]<<endl; 
    }
};

void changeValue(int * A)
{
    A[0] = 15;
};

int * returnArray(int size) //created in heap
{
    int *p;
    p = new int[size];
    for(int i=0; i<size; i++)
    {
       p[i]=i+1;     
    }

    return p;
};

int main()
{
    int A[] = {2,4,6,8,10};
    int n = 5;
    cout<<sizeof(A)/sizeof(int)<<endl;
    printSizeOfArray(A);
    //printValuesArrayWithEach(A);  error
    printValuesArrayWithFor(A,n);
    printValuesArrayWithForWithStar(A,n);
    for(int x: A)
    {
        cout<<x<<" ";
    }

    int *ptr;
    int size = 5;
    ptr = returnArray(size);
    for(int i=0;i<size;i++)
    {
        cout<<ptr[i]<<endl;
    }
    
    return 0;
}