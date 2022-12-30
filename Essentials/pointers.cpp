#include<iostream>
#include<stdio.h>
#include<stdlib.h>  //library that helps to access heap memory using malloc()
using namespace std;

/*
Pointers are address variable.

Pointers are used to inderictly link to a variable.

Main memory is main --> stack --> heap
in main it's where code goes, the program have access to main and stack, not heap
to access to heap we use pointers
Pointers are meant to be used to access the resources that are outside the program.

Access to monitor, keyboard, file and internet, are accessed by pointers.

1. Accessing Heap
2. Accessing resources
3. Parameter Passing

E.g.
    data variable int a = 10;  a is 2 bytes, each byte has a direction for each is 200 and 2001
    address variable int *p; pointers also have direction 210 and 211, each space saved the direcctions --- declaration
    p = &a;  --- initialization
    printf("%d",a) ---> 10
    printf("%d", p) ---> 200 
    printf("%d", *p) ---> 10 --- dereferencing
*/

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    /*int *p;
    p = (int*)malloc(5*sizeof(int)); // C
    p = new int[5]; //c++*/

    /*int a = 10;
    int *p;

    p = &a;

    cout<<a<<endl;
    printf("using pointer %d\n", *p);*/

    /*int A[5] = {2,4,6,8,10};
    int *p;
    p=A; //not neccessary use &

    for(int i =0;i<5;i++)
    {
        cout<<A[i]<<endl;
        cout<<p[i]<<endl;
    }*/

    /*int *p;
    //p = (int*)malloc(5*sizeof(int)); //C
    p = new int[5]; //dinamicly location
    p[0]=10; p[1]=14; p[2]=15; p[3]=21; p[4]=31;

    for(int i=0; i < 5; i++){
        cout<<p[i]<<endl;
    }


    delete [ ] p; //whenever you use dinamic allocated memory, you need to realize it
    //free(p);*/

    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;

    cout<<sizeof(p1)<<endl; //8
    cout<<sizeof(p2)<<endl; //8
    cout<<sizeof(p3)<<endl; //8
    cout<<sizeof(p4)<<endl; //8
    cout<<sizeof(p5)<<endl; //8

    //all pointers have the same size, because pointer 
    //size is independent from the data type

    return 0;
}