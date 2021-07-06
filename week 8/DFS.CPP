#include <stdio.h>
#include<conio.h>
#define MAX 50
int matrix[MAX][MAX], visited[MAX];
int top = -1;
int stack[MAX];

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
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			matrix[i][j] = 0;
		}
	}
}
void addEdge(int n)
{
	int i, j, v;

	for (i = 0; i < n; i++)
	{
		visited[i] = -1;
		for (j = 0; j < n - 1; j++)
		{
			printf("Enter the %d's adjacent node: ", i);
			scanf("%d", &v);
			if (v == -1)
			{
				break;
			}
			matrix[i][v] = 1;
		}
	}

	return;
}
int getAdjNode(int vertex, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (matrix[vertex][i] == 1 && visited[i] == -1)
		{
			return i;
		}
	}
	return -1;
}

void DFS(int n)
{
	int vertex, i;

	printf("Enter the starting vertex for DFS search: ");
	scanf("%d", &vertex);

	visited[vertex] = 1;
	printf("DFS search:\n");
	printf("%d\t", vertex);
	push(vertex);

	while (!isStackEmpty())
	{
		int adjunviNode = getAdjNode(peek(), n);
		if (adjunviNode == -1)
		{
			pop();
		}
		else
		{
			visited[adjunviNode] = 1;
			printf("%d\t", adjunviNode);
			push(adjunviNode);
		}
	}

	for (i = 0; i < n; i++)
	{
		visited[i] = -1;
	}
	return;
}

void printMatrix(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int n;
	clrscr();
	printf("------------------DFS------------------\n");
	printf("Enter total number of vertices: ");
	scanf("%d", &n);
	init(n);
	addEdge(n);
	printf("\nThe adjacency matrix is:\n");
	printMatrix(n);

	printf("\n");
	DFS(n);
	getch();
	return 0;
}