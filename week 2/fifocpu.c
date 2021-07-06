#include<stdio.h>
#define size 5

int front=-1,rear=-1;
int b[size],p[size],a[size];

void enqueue(){
    int i,x,y,k;
    if (rear == size - 1)
       printf("Overflow \n");
    else
    {
        if (front == - 1)
       
        front = 0;
        printf("\nEnter the arrival time process(%d) in the Queue : ",rear+1);
        scanf("%d", &x);
        printf("\nEnter the burst time in the Queue : ");
        scanf("%d", &y);
        rear = rear + 1;
        p[rear] = rear;
        a[rear] = x;
        b[rear]=y;
    }
}

void display(){
    if(rear == -1){
        printf("\nQueue is empty\n");
    }
    else{
        int i;
        printf("\nQueue elements are \n");
        printf("\nPROCESS\tARRIVAL TIME\tBURST TIME\n");
        for(i=front;i<=rear;i++){
            printf("%d\t\t%d\t\t%d\n",i+1,a[i],b[i]);
        }
    }
    printf("\n");
}

void average(){
    int i,wt[size],sum=0,ct[size]={0};
    int tat[size]={0};
    float totalwt=0,average,totaltat=0;
    for(i=front;i<=rear;i++){
        sum+=b[i];
        ct[i]+=sum;
    }
    for(i=front;i<=rear;i++){
        tat[i]=ct[i]-a[i];
        totaltat+=tat[i];
    }
    for(i=front;i<=rear;i++){
        wt[i]=tat[i]-b[i];
        totalwt+=wt[i];
    }
    average = totalwt/5;

    printf("\nAverage Waiting time is %f\n",average);
}

int main(){
    int i;
    int x[size],y[size],z[size];
    for(i=0;i<5;i++){
        enqueue();
    }
    display();
    average();
    return 0; 
}

