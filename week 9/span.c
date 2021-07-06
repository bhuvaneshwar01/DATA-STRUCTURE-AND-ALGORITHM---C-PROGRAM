#include<stdio.h>

int n = 4;

int minkey(int key[],int visited[])
{
    int min = 1000,min_index;
    for(int v=0;v<n;v++)
    {
        if(visited[v] == 0 && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int print_MST(int parent[], int cost[n][n])
{
    int mincost = 0;
    printf("Edge \tWeight\n");
    for(int i=1;i<n;i++)
    {
        printf("%d - %d\t%d\n",parent[i],i,cost[i][parent[i]]);
        mincost+=cost[i][parent[i]];
    }
    printf("Total cost is %d\n",mincost);
}
void find_MST(int cost[n][n])
{
    int parent[n],key[n];
    int visited[n];
    int i;
    for(i=0;i<n;i++)
    {
        key[i] = 100;
        visited[i] = 0;
        parent[i]= i;
    }
    key[0]=0;
    parent[0] = -1;

    for(i=0;i<n-1;i++)
    {
        int u = minkey(key,visited);

        visited[u] = 1;

        for(int v=0;v<n;v++)
        {
           if(cost[u][v] != 0 && cost[u][v] <key[v])
           {
               parent[v] = u;
               key[v] = cost[u][v];
           } 
        }
    }
    print_MST(parent,cost);

}

int main()
{
    int i,cost[n][n];

    for(i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("enter the element [%d][%d] : ",i,j);
            scanf("%d",&cost[i][j]);
        }
    }
    find_MST(cost);
    return 0;
}