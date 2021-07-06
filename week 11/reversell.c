#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};


void display_node(struct node *stu)
{
    printf("%d ->\t", stu->data);
}

struct node *getdetail()
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));

    if(new == NULL){
        return NULL;
    }

    printf("Enter the number till you enter -1\n");
    scanf("%d",&(new->data));

    if(new->data == -1) 
    {
        return NULL;
    }
    return new;
}

void ins_node(struct node *x, struct node *y){
    y->next = x->next;
    x->next=y;
}

void display_list(struct node *p)
{
	for(p= p->next; p; p = p->next)
	{
		display_node(p);
	}

}
void reverse(struct node *start)
{
    struct node start2,prev =NULL,*current ;
    start2 = 

    
}
int main()
{
    struct node start, *p;
    printf("Insert initial data\n");
    start.next = NULL;
    while(p = getdetail())
    {
        ins_node(&start,p);
    }
    display_list(&start);
}