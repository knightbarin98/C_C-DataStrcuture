#include<stdio.h>
#include<stdlib.h>
using namespace std;


struct Matrix
{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x )
{
    if(i == j)
    {
        m->A[i-1] = x;
    }
}

int Get(struct Matrix m, int i, int j)
{
    if(i == j)
    {
        return m.A[i-1];
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct Matrix m;
    m.n = 4;
    m.A = (int *) malloc(m.n * sizeof(int));


    return 0;
}