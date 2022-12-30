#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*
References features only available in C++
References is a nickname or alias to a variable
Useful for paremeter passing
References do not consume memory
    int a = 10; a variable inside stack memory
    int &r = a; reference to a, same size and same directions
    cout<<a; --- 10
    r++;
    cout<<r; --- 11
    cout<<a; --- 11
*/

int main()
{   
    int a = 10;
    int &r = a;
    //r = 25;
    int b = 30;
    r=b;
    cout<<a<<endl<<r<<endl;

    return 0;
}