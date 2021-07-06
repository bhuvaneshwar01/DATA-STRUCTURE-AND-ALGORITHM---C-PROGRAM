#include<stdio.h>
#include<stdlib.h>

#define size 100

int front = -1,rear= -1;
int queue[size];

int enqueue(){
    if(size<rear)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if(front == -1){
            front = 0;
        }

            rear = rear + 1;
            int item;
            printf("Enter the Number :\t");
            scanf("%d",&item);
            printf("\n");
            queue[rear]=item;
       
    }
}
int dequeue()
{
    if(front == -1||front > rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Deleting an element is :\t%d\n",queue[front]);
        front = front + 1;
    }
}
int display()
{
    int i;
    for(i=front;i<=rear;i++)
    {
        printf("%d\n",queue[i]);
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