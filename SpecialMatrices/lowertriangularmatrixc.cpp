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
    if(i>=j)
    {
        m->A[i*(i-1)/2+j-1]=x; //row-major formula
        //m->A[m->n*(j-1)-((j-2)*(j-1)/2)+ (i-j)]=x; //column-major formula
    }
        
}

int Get(struct Matrix m, int i, int j)
{
    if(i<j)
    {
        return m.A[i*(i-1)/2+j-1];
        // return m.A[m.n*(j-1)-((j-2)*(j-1)/2)+ (i-j)];
    }
    return 0;
}

void Display(struct Matrix m)
{
    int i,j;
    for(i = 1; i <= m.n;i++)
    {
        for(j = 1; j <= m.n; j++)
        {
            if(i >= j ) printf("%d ",m.A[i*(i-1)/2+j-1]); // row-major
            //if(i >= j ) printf("%d ",m.A[m.n*(j-1)-((j-2)*(j-1)/2)+ (i-j)]); // column-major
            else printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;

    printf("Enter dimension: ");
    scanf("%d",&m.n);
    m.A = (int *) malloc(m.n * (m.n+1)/2 *sizeof(int)); // for non-zero elements

    ///Set(&m,1,1,1); Set(&m,2,2,2); Set(&m,3,3,3); Set(&m,4,4,5);
    int x = 0;
    printf("enter all elements\n");
    for(int i=1; i<=m.n;i++)
    {
        for(int j=1; j<=m.n;j++)
        {
            scanf("%d",&x);
            Set(&m,i,j,x);
        }
    }

    printf("\n\n");

    Display(m);

    return 0;
}