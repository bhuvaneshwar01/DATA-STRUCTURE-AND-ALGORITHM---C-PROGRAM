#include<stdio.h>
#include<stdlib.h>
#define size 10

int top1=-1,top2=size;
int stack1[size],stack2[size];

void push1(int n){
    if(top1>size-1){
        printf("\n*****************Stack_Overflow****************\n");
    }
    else{
        top1=top1+1;
        stack1[top1]=n;
        printf("Value pushed in Stack 1 is %d\n",stack1[top1]);
    }
}

void push2(int n){
    if(top1>size-1){
        printf("\n*****************Stack_Overflow****************\n");
    }
    else{
        top2=top2-1;
        stack2[top2]=n;
        printf("Value pushed in Stack 2 is %d\n",stack2[top2]);
    }
}

void pop_stack1(){
    if (top1 >= 0)
    {
        int popped_value = stack1[top1--];
        printf ("%d is being popped from Stack 1\n", popped_value);
    }
    else
    {
        printf ("Stack Empty! Cannot Pop\n");
    }
}
void pop_stack2 ()
{
  if (top2 < size)
  {
    int popped_value = stack2[top2++];
    printf ("%d is being popped from Stack 2\n", popped_value);
  }
  else
  {
    printf ("Stack Empty! Cannot Pop\n");
  }
}

void print_stack1()
{
    int i;
    printf("The element in stack 1 is \n");
    for (i = top1; i >= 0; --i)
    {
        printf ("%d ", stack1[i]);
    }
     printf ("\n");
}

void print_stack2()
{
    int i;
    printf("The element is stack 2 is \n");
    for (i = top2; i < size; ++i)
    {
        printf ("%d ", stack2[i]);
    }
  printf ("\n");
}

int main(){

    int a[size],i,b[size];
    int x,y,n,k;

    printf("Enter 10 numbers : \n");
    for(i=0;i<size;i++){
        scanf("%d",&a[i]);
    }

    x=size/2+1;
    y=size-x;

    printf("the number of element in stack 1 is %d\n",x);
    printf("the number of element in stack 2 is %d\n",y);

    for(i=0;i<x;i++){
        push1(a[i]);
    }

    for(i=y-1;i>=0;i--){
        
        push2(a[(size-1)-(y-i)]);
    }

    print_stack1();
    print_stack2();

    printf("Which stack do you want to pop all the element??\n\t1)stack 1\n\t2)stack 2\nEnter the option no.\n");
    scanf("%d",&n);
 
    if(n==1){
        k = top1 + 1;
        while (k)
         {
             pop_stack1();
            --k;
        }
        printf("\nTherefore, the reamaining stack is stack 2\n");
        print_stack2();
    }
    else{
        k = top2 + 1;
        while (k)
         {
             pop_stack2();
            --k;
        }
        printf("\nTherefore, the reamaining stack is stack 1\n");
        print_stack1();
    }
    


}