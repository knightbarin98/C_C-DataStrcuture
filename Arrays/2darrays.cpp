#include<stdio.h>
#include<stdlib.h>

int main()
{

    int A[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int *B[3];
    B[0] = (int*)malloc(4*sizeof(int));
    B[1] = (int*)malloc(4*sizeof(int));
    B[2] = (int*)malloc(4*sizeof(int));

    int **C;
    C = (int **)malloc(3*sizeof(int *));
    C[1] = (int *)malloc(4*sizeof(int));
    C[2] = (int *)malloc(4*sizeof(int));
    C[3] = (int *)malloc(4*sizeof(int));

    int i,j;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }

    return 0;
}