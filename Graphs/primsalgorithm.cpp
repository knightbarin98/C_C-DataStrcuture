#include<stdio.h>
#include<stdlib.h>
#define I __INT_MAX__
using namespace std;
#include<iostream>



int main()
{
    int cost[][8] = {
        {I,I,I,I,I,I,I,I},
        {I,I,25,I,I,I,5,I},
        {I,25,I,12,I,I,I,10},
        {I,I,12,I,8,I,I,I},
        {I,I,I,8,I,16,I,14},
        {I,I,I,I,16,I,20,18},
        {I,5,I,I,I,20,I,I},
        {I,I,10,I,14,18,I,I},
    };

  int near[8] = {I,I,I,I,I,I,I,I};
  int t[2][6];  
  int i,j,k,u,v,n=7, min=I;

//Find minimum cost using upper triangle matrix
  for(i=1;i<=n;i++)
  {
    for(j=i;j<=n;j++)
    {
        if(cost[i][j]<min)
        {
            min = cost[i][j];
            u=i; v=j;
        }
    }
  }
  t[0][0] = u; t[1][0]=v;
  near[u]=near[v]=0;

  for(i=1;i<=n;i++)
  {
    if(near[i] != 0 && cost[i][u]< cost[i][v])
    {
        near[i] = u;
    }
    else if(near[i] != 0)
    {
        near[i] = v;
    }
  }

  //To run to all vertices
  for(i=1; i<n-1;i++)
  {
    min = I;
    for(j=1; j<=n; j++)
    {
        if(near[j] != 0 && cost[j][near[j]]< min)
        {
            min = cost[j][near[j]];
            k=j;
        }
    }

    t[0][i] = k; t[1][i] = near[k];
    near[k] = 0;

    for(j=1;j<=n;j++)
    {
        if(near[j] != 0 && cost[j][k]< cost[j][near[j]])
        {
            near[j] = k;
        }
    }    

  }

  for(i=0; i<n-1;i++)
  {
    cout<<"("<<t[0][i] <<","<<t[1][i]<<")"<<endl;
  }  
}