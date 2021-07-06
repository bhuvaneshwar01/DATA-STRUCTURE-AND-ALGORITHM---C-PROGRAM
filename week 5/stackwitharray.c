#include<stdio.h>
#include<stdlib.h>

#define size 100

int top=-1,stack[size];

int push()
{
    int item;
    if(top>size)
    {
        printf("Stack Overflow");
    }
    else
    {
        top = top + 1;
        printf("Enter the Number :\t");
        scanf("%d",&item);
        stack[top] = item;
    }
}

int pop()
{
    if(top<0)
    {
        printf("Stack Underflow");
    }
    else
    {
        printf("Deleting an element is :\t%d\n",stack[top]);
        top = top - 1;
    }
}

int peek()
{
    printf("peek element is %d\n",stack[top]);
}

int display()
{
    int i;
    for(i=0;i<=top;i++)
    {
        printf("%d\n",stack[i]);
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