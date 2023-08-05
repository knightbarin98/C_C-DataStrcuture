#include<iostream>
#define I __INT_MAX__
using namespace std;

int costs[3][9] = {
    {1,1,2,2,3,4,4,5,5},
    {2,6,3,7,4,5,7,6,7},
    {25,5,12,10,8,16,14,20,18}
};

int set[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
int included[9] = {0};
int t[2][6];

void join(int u, int v)
{
    if(set[u]<set[v])
    {
        set[u]+=set[v];
        set[v] = u;
    }
    else
    {
        set[v] += set[u];
        set[u] = v;
    }
}

int find(int u)
{
    int x = u;
    while(set[x]>0) x = set[x];
    return x;
}


int main()
{
    int i=0,j,k, min, nodes=7, edges=9, u,v;
    while(i<nodes-1)
    {   
        min = I;
        for(j=0;j<edges;j++)
        {
            if(included[j] == 0 && costs[2][j]<min)
            {
                min = costs[2][j];
                k=j; u=costs[0][j]; v=costs[1][j];
            }
        }
        //find out if they have different parent
        if(find(u) != find(v))
        {
            t[0][i] = u; t[1][i] = v;
            //union with their respective parents;
            join(find(u),find(v));
            i++;
        }
        included[k] = 1;
    }

    for(i=0;i<6;i++)
    {
         cout<<"("<<t[0][i] <<","<<t[1][i]<<")"<<endl;
    }
    return 0;

}


