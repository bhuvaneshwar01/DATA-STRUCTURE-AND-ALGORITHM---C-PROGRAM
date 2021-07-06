#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#define MAX 50

typedef struct Node
{
	int vertex;
	struct Node *next;
} node;

typedef struct Graph
{
	int visited;
	struct Node *adjList;
} graph;


int front = -1;
int rear = -1;
int queue[MAX];

void enqueue(int v)
{
	if (front == -1 && rear == -1)
	{
		queue[++front] = queue[++rear] = v;
		return;
	}

	queue[++rear] = v;
	return;
}
int dequeue()
{
	return queue[front++];
}
int getFront()
{
	return queue[front];
}
int isQueueEmpty()
{
	if (front > rear)
	{
		return 1;
	}
	return 0;
}
node *createNode(int v)
{
	node *newnode = (node *)malloc(sizeof(node));
	newnode->vertex = v;
	newnode->next = NULL;

	return newnode;
}
void createGraph(graph *p, int v)
{
	int i;
	for (i = 0; i < v; i++)
	{
		p[i].adjList = (node *)malloc(sizeof(node));
		p[i].visited = -1;
		p[i].adjList = NULL;
	}

	return;
}
void addEdge(graph *graph, int src, int dest)
{
	node *newNode = createNode(dest);
	newNode->next = graph[src].adjList;
	graph[src].adjList = newNode;

	return;
}
int getAdjunvisited(graph *graph, int vertex)
{
	node *temp = graph[vertex].adjList;

	while (temp)
	{
		if (graph[temp->vertex].visited == -1)
		{
			return temp->vertex;
		}
		temp = temp->next;
	}

	return -1;
}
void BFS(graph *graph, int v)
{
	int vertex, i;
	printf("Enter the starting vertex for BFS search: ");
	scanf("%d", &vertex);

	graph[vertex].visited = 1;
	enqueue(vertex);

	while (!isQueueEmpty())
	{
		node *temp = graph[vertex].adjList;
		while (temp)
		{
			if (graph[temp->vertex].visited == -1)
			{
				enqueue(temp->vertex);
				graph[temp->vertex].visited = 1;
			}
			temp = temp->next;
		}
		printf("%d\t", getFront());
		dequeue();

		vertex = getFront();
	}

	printf("\n");

	for (i = 0; i < v; i++)
	{
		graph[i].visited = -1;
	}
	return;
}

void printAdjNodes(graph *g, int v)
{
	for (int i = 0; i < v; i++)
	{
		node *temp = g[i].adjList;
		printf("%d : ", i);
		while (temp != NULL)
		{
			printf("%d,", temp->vertex);
			temp = temp->next;
		}
		printf("\n");
	}
}
int main()
{
	//clrscr();
	int n, i, adj, j;
	graph g[15];
	//printf("-----------------------BFS--------------------\n");
	printf("\nEnter the number of vertices : ");
	scanf("%d", &n);
	printf("\n");


	createGraph(g, n);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			printf("Enter the adjacent node of %d(-1 to exit): ", i);
			scanf("%d", &adj);
			if (adj == -1)
			{
				break;
			}
			addEdge(g, i, adj);
		}
	}

	printAdjNodes(g, n);
	printf("\n");
	BFS(g, n);
	getch();
	return 0;
}