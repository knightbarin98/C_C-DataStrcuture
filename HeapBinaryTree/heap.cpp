#include<stdio.h>
#include<stdlib.h>


void insert(int A[], int n)
{
    int i = n, temp;
    temp = A[i];
    while(i>1 && temp > A[i/2])
    {
        A[i] = A[i/2];
        i = i/2;
    }

    A[i] = temp;
}

int Delete(int A[], int n)
{
    int i,j, lastVal, temp, firstVal;
    firstVal = A[1];
    lastVal = A[n];
    A[1] = A[n];
    A[n] = firstVal;
    i=1;
    j=2*i;
    while(j<n-1)
    {
        if(A[j+1]>A[j])
        {
            j = j +1;
        }

        if(A[i]<A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            j= 2*j;
        }
        else
        {
            break;
        }
    }
    return firstVal;
}

int main()
{
    int H[] = {0,10,20,30,25,5,40,35};
    //40,25,35,10,5,20,30

    for(int i = 2; i<=7; i++)
    {
        insert(H,i);
    }

    for(int i = 7; i>1; i--)
    {
        Delete(H,i);
    }

     for(int i = 1; i<=7; i++)
    {
        printf("%d ", H[i]);
    }
    printf("\n");

    return 0;
}