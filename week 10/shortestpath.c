#include<stdio.h>
#define max 100
#define temp 0
#define infinity 9999
#define nil -1
#define perm 1

int n, adj[max][max],predecessor[max],pathlength[max],status[max];

void creat_graph()
{
    int i,max_edges,origin,dest,weight;

    printf("\nEnter number of vertices :\t");
    scanf("%d",&n);
    max_edges = n*(n-1);

    for(i=1;i<=max_edges;i++)
    {
        printf("\nEnter edge %d (-1  -1 to exist) :\t",i);
        scanf("%d %d",&origin,&dest);

        if(origin == -1 && dest == -1)  break;

        printf("Enter the weight for this edge :\t");
        scanf("%d",&weight);

        if(origin >= n || dest >= n|| origin < 0|| dest <0)
        {
            printf("Invalid :/");
            i--;
        }
        else    adj[origin][dest] = weight;
    }
}

int min_temp()
{
    int i;
    int min = infinity;
    int k = nil;
    for(i=0;i<n;i++)
    {
        if(status[i] == temp && pathlength[i] < min)
        {
            min = pathlength[i];
            k=i;
        }
    }
    return k;
}

void find_path(int s, int v)
{
    int i,u;
    int path[max];
    int shortdist = 0;
    int count = 0;

    while( v!= s)
    {
        count++;
        path[count] = v;
        u = predecessor[v];
        shortdist += adj[u][v];
        v = u;
    }
    count++;
    path[count] = s;
    for(i=count; i>=1; i--)
        printf("%d  ",path[i]);
    printf("\nShortest distance is : %d\n",shortdist);
}

void dijistra(int s)
{
    int i,current;

    for(i=0;i<n;i++)
    {
        predecessor[i] = nil;
        pathlength[i] = infinity;
        status[i] = temp;
    }
    pathlength[s] = 0;

    while(1)
    {
        current = min_temp();
        if(current == nil)
        {
            return;
        }
        status[current] = perm;

        for(i=0;i<n;i++)
        {
            if(adj[current][i]!= 0 && status[i] == temp)
            {
                if(pathlength[current] + adj[current][i] < pathlength[i])
                {
                    predecessor[i] =  current;
                    pathlength[i] = pathlength[current] + adj[current][i];
                } 
            }
        }
    }
}
int main()
{
    int s,v;
    creat_graph();

    printf("\nEnter source vertex : \t");
    scanf("%d",&s);

    dijistra(s);

    while(1)
    {
        printf("Enter the destination vertex (-1 to exist):\t");
        scanf("%d",&v);

        if( v == -1)    break;
        if( v < 0 || v >=n )    printf("\nGiven vertices doesnt exist\n");
        else if ( v == s)      printf("Source and destination vertices are same\n");
        else    find_path(s,v);
    }
    return 0;
}