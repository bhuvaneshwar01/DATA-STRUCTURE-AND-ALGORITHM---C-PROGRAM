#include<stdio.h>
#include<stdlib.h>

#define size 20

int mat[size][size] , visited[size];
int top = -1, stack[size];

void push(int item)
{
    stack[++top] = item;
}

int pop()
{
    return stack[top--];
}

int peek()
{
    return stack[top];
}
int isStackEmpty()
{
	return top == -1;
}
void init(int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            mat[i][j] = 0;
}
void addedge(int n)
{
    int i,j,v;
    for(i=0;i<n;i++)
    {
        visited[i]=-1;
        for(j=0;j<n;j++)
        {
            printf("Enter the %d's adjacent node: ", i);
			scanf("%d", &v);
            if(v == -1) break;
            mat[i][v] = 1;
        }
    }
}
int getadjnode(int vertex,int n)
{
    int i;
	for (i = 0; i < n; i++)
	{
		if (mat[vertex][i] == 1 && visited[i] == -1)
		{
			return i;
		}
	}
	return -1;
}
void dfs(int n)
{
    int vertex,i;
    printf("Enter the starting vertex for DFS search: ");
	scanf("%d", &vertex);
    visited[vertex] = 1;
	printf("DFS search:\n");
	printf("%d-> ", vertex);
	push(vertex);

	while (!isStackEmpty())
	{
		int a = getadjnode(peek(), n);
		if (a == -1)
		{
			pop();
		}
		else
		{
			visited[a] = 1;
			printf("%d-> ", a);
			push(a);
		}
	}

	for (i = 0; i < n; i++)
	{
		visited[i] = -1;
	}
	return;
}
void printmatrix(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", mat[i][j]);
		}
        printf("\n");
	}
}
int main()
{
    int n;
    printf("Enter  number of vertices :-\t");
    scanf("%d",&n);
    init(n);
    addedge(n);
    printf("\n");
    printmatrix(n);
    printf("\n");
    dfs(n);
    return 0;    
}
