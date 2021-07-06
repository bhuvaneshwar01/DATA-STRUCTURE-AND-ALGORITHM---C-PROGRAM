#include<stdio.h>
void printMatrix(int V,int arr[][V])
{
     printf("Matrix representing weight of the edges:\n");
     int i, j;
     for (i = 0; i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            if ( i == j)
                arr[i][j] = 0;
        }
    }
     for(i = 0; i < V; i++)
     {
         for(j = 0; j < V; j++)
         {
             if(arr[i][j]==9999)
                printf("INF     ");
            else
                printf(" %d\t", arr[i][j]);
         }
         printf("\n");
     }
}
void printFloyd(int V,int arr[][V])
{
     printf("Matrix representing shortest path:\n");
     int i, j;

     for(i = 0; i < V; i++)
     {
         for(j = 0; j < V; j++)
         {
             if(arr[i][j]==9999)
                printf("INF\t");
           
             else
                printf(" %d\t", arr[i][j]);
         }
         printf("\n");
     }
}
void floyd(int V,int adjMatrix[][V]){
    int dist[V][V], i, j, k;
    for(i=0;i<V;i++){
        for(j=0;j<V;j++)
            dist[i][j]=adjMatrix[i][j];
    }
    for(k=0;k<V;k++){
        for(i=0;i<V;i++){
            for(j=0;j<V;j++){
                if(dist[i][j]>(dist[i][k]+dist[k][j])){
                     dist[i][j]=dist[i][k]+dist[k][j];

                }
            }
        }
    }
    for (i = 0; i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            if ( i == j)
                dist[i][j] = 0;
        }
    }
    printFloyd(V,dist);
}

int main() {
    int nodes,n, i, j;
    printf("Enter number of nodes:");
    scanf("%d",&nodes);
    int adjMatrix[nodes][nodes];
    int weight;
    printf("ENTER THE WEIGHT OF THE EDGES(enter 9999 for infinity):\n");
    for(i=0;i<nodes;i++){
        for(j=0;j<nodes;j++){
            printf("Enter the weight of the edge (%d,%d):",i,j);
            scanf("%d",&weight);
            adjMatrix[i][j]=weight;
        }
    }
    printMatrix(nodes,adjMatrix);
    floyd(nodes,adjMatrix);
    return 0;
}