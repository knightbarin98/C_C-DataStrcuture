#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class Diagonal
{
    private:
        int *A;
        int n;
    public:
        Diagonal()
        {
            n = 2;
            A = new int[2];
        }
        Diagonal(int n)
        {
            this->n = n;
            A = new int[n];
        }
        void set(int i, int j, int x);
        int get(int i, int j);
        void Display();
        ~Diagonal()
        {
            delete []A;
        }
};

//scope resolution
void Diagonal::set(int i, int j, int x)
{
    if (i == j) A[i-1] = x;
}

int Diagonal::get(int i, int j)
{
    if(i == j) return A[i-1];
    else return 0;
}

void Diagonal::Display()
{
    int i,j;
    for(i = 0; i < n;i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j ) cout<<A[i-1]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
}

int main()
{
    Diagonal d(4);
    d.set(1,1,1); d.set(2,2,2); d.set(3,3,3); d.set(4,4,5);
    d.Display();
    
    return 0;
}