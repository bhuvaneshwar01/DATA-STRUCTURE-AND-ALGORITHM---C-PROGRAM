#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *front;
struct node *rear;

int enqueue()
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        int item;
        printf("Enter the number :\t");
        scanf("%d",&item);
        ptr->data=item;
        ptr->next=NULL;
        if(front == NULL)
        {
            rear = ptr;
            front = ptr;
            rear->next = NULL;
            front->next = NULL;
        }
        else
        {
            rear -> next = ptr; 
            rear = ptr;
            rear->next = NULL;
        }
        printf("The given number is successfully pushed\n");
    }
}

int dequeue()
{
    int item;
    struct node *ptr;
    if(front == NULL )
    {
        printf("Queue underflow\n");
    }
    else
    {
        item = front -> data;
        printf("Deleting an element is :\t%d\n",item);
        ptr = front;
        front = front->next;
        free(ptr);
        printf("This number is popped successfully\n");
    }
}

int display()
{
    struct node *p;
    p = front;
    if(p == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Displaying all the elements in a stack are\n");
        while(p!=NULL)
        {
            printf("%d\n",p->data);  
            p = p->next;  
        }
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("Which one do you want\n\t1)Insert\n\t2)Delete\n\t3)diplay\n\t4)exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
                enqueue();
                break;
            case 2 :
                dequeue();
                break;
            case 3 :
                display();
                break;
            case 4 :
                exit(0);
                break;
            default : 
                printf("Incorrect option no.\n");
                break;
        }
    }
    return 0;
}