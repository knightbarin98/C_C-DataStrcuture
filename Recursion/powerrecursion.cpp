#include<stdio.h>

int pow(int m, int n)
{
    if(n==0) return 1;
    return pow(m,n-1)*m;
}

int fpow(int m, int n)
{
    if(n==0) return 1;
    if(n%2 == 0) return fpow(m*m,n/2);
    else return m* fpow(m*m,(n-1)/2);
}

int main()
{
    int r;
    r = pow(2,9);
    printf("%d\n",r);
    r = fpow(2,9);
    printf("%d\n",r);
    return 1;
}