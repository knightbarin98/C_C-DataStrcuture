#include<stdio.h>

int fact(int n)
{
    if(n == 0) return 1;
    return fact(n-1)*n;
}

int ncr(int n, int r)
{
    int num, den;
    num = fact(n);
    den= fact(r)*fact(n-r);
    return num / den;
}

int recurnCr(int n, int r)
{
    if(n == r || r == 0) return 1;
    return recurnCr(n-1,r-1) + recurnCr(n-1,r);
}

int main()
{
    printf("%d \n", ncr(3,2));
    printf("%d \n", recurnCr(3,2));
    return 1;
}