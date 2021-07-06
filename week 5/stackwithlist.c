#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head;

int push()
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Stack Overflow");
    }
    else
    {
        int item;
        printf("Enter the Number :\t");
        scanf("%d",&item);
        if(head == NULL)
        {
            ptr->data = item;
            ptr->next = NULL;
            head = ptr;
        }
        else
        {
            ptr->data = item;
            ptr->next = head;
            head = ptr;
        }
        printf("Given Number is pushed successfully\n");
    }
}

int pop()
{
    int item;
    struct node *ptr;
    if(head == NULL)
    {
        printf("Stack underflow\n");
    }
    else
    {
        item = head -> data;
        printf("Deleting an element is :\t%d\n",item);
        ptr = head;
        head = head->next;
        free(ptr);
        printf("This number is popped successfully\n");
    }
}
int peek()
{
    printf("peek element is %d\n",head->data);
}
int display()
{
    struct node *p;
    p = head;
    if(p == NULL)
    {
        printf("Stack is empty\n");
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
        printf("Which one do you want\n\t1)Insert\n\t2)Delete\n\t3)peek\n\t4)diplay\n\t5)exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
                push();
                break;
            case 2 :
                pop();
                break;
            case 3 :
                peek();
                break;
            case 4 : 
                display();
                break;
            case 5 :
                exit(0);
                break;
            default : 
                printf("Incorrect option no.\n");
                break;
        }
    }
     return 0;
}