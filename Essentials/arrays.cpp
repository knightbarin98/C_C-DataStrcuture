#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    /*int A[5];
    A[0]=12;
    A[1]=15;
    A[2]=25;*/

    //int A[] = {2,4,6,8,10,12,14};

    //int A[10] = {2,4,6,8,10,12,14};

    /*for (size_t i = 0; i < 10; i++)
    {
        cout<<A[i]<<endl;
    }

    for(int x:A)
    {
        cout<<x<<endl;
    }*/
    

    /*cout<<sizeof(A)<<endl;
    cout<<A[1]<<endl;
    printf("%d\n",A[2]);
    cout<<"Hello World!";*/

    int n;
    cout<<"Enter size";
    cin>>n;
    int A[n];
    A[0]=2;

    for(int x:A)
    {
        cout<<x<<endl;
    }

    return 0;
}