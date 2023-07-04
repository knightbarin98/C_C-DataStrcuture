#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class LowerTriangular
{
    private:
        int *A;
        int n;
    public:
        LowerTriangular()
        {
            n = 4;
            A = new int[4*(4+1)/2];
        }
        LowerTriangular(int n)
        {
            this->n = n;
            A = new int[n*(n+1)/2];
        }
        void set(int i, int j, int x);
        int get(int i, int j);
        void Display();
        int GetDimension() {return n;}
        ~LowerTriangular()
        {
            delete []A;
        }
};

//scope resolution
void LowerTriangular::set(int i, int j, int x)
{
    if (i >= j) A[i* (i-1)/2 + (j-1)] = x; //row-major
    //if (i >= j) A[n*(j-1)-((j-2)*(j-1)/2)+ (i-j)] = x; //column-major
}

int LowerTriangular::get(int i, int j)
{
    if(i< j) return A[i* (i-1)/2 + (j-1)]; //row-major
    //if(i< j) return A[n*(j-1)-((j-2)*(j-1)/2)+ (i-j)]; //column-major
    else return 0;
}

void LowerTriangular::Display()
{
    int i,j;
    for(i = 1; i <= n;i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(i >= j ) cout<<A[i* (i-1)/2 + (j-1)]<<" "; //row-major
            //if(i >= j ) cout<<A[n*(j-1)-((j-2)*(j-1)/2)+ (i-j)]<<" "; //column-major
            else cout<<"0 ";
        }
        cout<<endl;
    }
}

int main()
{
    int dim = 0;
    cout<<"Enter dimension";
    cin>>dim;
    LowerTriangular d(dim);
    //d.set(1,1,1); d.set(2,2,2); d.set(3,3,3); d.set(4,4,5);
    int i,j,x;
    cout<<"Enter all elements"<<endl;
    for(i = 1; i <= dim; i++)
    {
        for(j = 1; j <= dim; j++)
        {
            cin>>x;
            d.set(i,j,x);
        }
    }
    cout<<endl<<endl;
    d.Display();
    
    return 0;
}