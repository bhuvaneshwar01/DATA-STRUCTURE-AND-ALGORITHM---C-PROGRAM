#include<stdio.h>
#include<stdlib.h>

#define size 10

struct graph {
    struct node *head[size];
};

struct node {
    int data;
    struct node *next;
};

struct edge {
    int src,data;
};

struct graph *insert(struct edge e[], int n)
{
    int i;
    struct graph *gr=(struct graph *)malloc(sizeof(struct graph));

    for(i=0;i<size;i++)
        gr->head[i] = NULL;

    for(i=0;i<n;i++)
    {
        int src = e[i].src;
        int data = e[i].data;

        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;

        newnode->next = gr->head[src];

        gr->head[src] = newnode;
    }
    return gr;
}

void display(struct graph *g)
{
    int i;
    for(i=0;i<size;i++)
    {
        struct node *ptr = g->head[i];
        while(ptr != NULL)
        {
            printf("(%d -> %d)\t",i,ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}
int main()
{
    struct edge e[size];
    int pos, ele;
    while(1)
    {
        int ch;
        printf("Enter the option no.\n\t1)Insert\n\t2)printgraph\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the position number:-\n");
                scanf("%d",&(e->src));
                printf("Enter the element :-\n");
                scanf("%d",&(e->data));
                break;
        
            case 2:
                int length;
                length = sizeof(e)/sizeof(e[0]);
                struct graph *g = insert(e,length);
                display(g);

            case 3:
        

        else
        {
            printf("Wrong number\n");
        }
    }
    return 0;
}
