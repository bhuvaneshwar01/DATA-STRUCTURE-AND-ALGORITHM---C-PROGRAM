#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define size 100

int top=-1;
char stack[size];

void push(char item)
{
    if(top>size)
    {
        printf("Stack Overlow\n");
    }
    else
    {
        top=top+1;
        stack[top]=item;
    }
}
void pop()
{
    if(top<0)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        top=top-1;
    }
}
void count()
{
    int a=0,b=0,c=0,i;
    int d=0,e=0,f=0;
    
    //fpr "()" count
    for(i=0;i<=top;i++)
    {
        if(stack[i]=='(')
        {
            a++;
        }
        if(stack[i]==')')
        {
            b++;
        }
    }
    for(i=0;i<=top;i++)
    {
        if(stack[i]=='[')
        {
            c++;
        }
        if(stack[i]==']')
        {
            d++;
        }
    }
    for(i=0;i<=top;i++)
    {
        if(stack[i]=='{')
        {
            e++;
        }
        if(stack[i]=='}')
        {
            f++;
        }
    }
    int t,x,y;
    if(a!=b)
    {
        t=0;
    }
    else
    {
        t=1;
    }
    if(c!=d)
    {
        x=0;
    }
    else
    {
        x=1;
    }
    if(e!=f)
    {
        y=0;
    }
    else
    {
        y=1;
    }
    if((t==1)&&(x==1)&&(y==1))
    {
        printf("The Given string is balanced\n");
    }
    else
    {
        printf("The Given string is not balanced\n");
    }
    
}

int main()
{
    char c,a[size];
    int i,n=0;
    printf("Enter the equation :-\n\t");
    for(i=0;((i<size)&&((c=getchar())!='\n'));i++)
    {
        a[i]=c;
        n++;
    }
    a[i]='\0';
    for(i=0;i<=n;i++)
    {
        push(a[i]);
    }
    count();

}