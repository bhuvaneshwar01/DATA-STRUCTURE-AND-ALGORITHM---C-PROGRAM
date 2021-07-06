#include<stdio.h>
#include<stdlib.h>

int total_nodes;

void printsubset(int a[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}

void sumofsubset(int s[], int t[],int s_size, int t_size, int sum, int ite, int target)
{
    total_nodes++;
    if(target == sum)
    {
        printsubset(t,t_size);
        sumofsubset(s,t,s_size,t_size-1,sum - s[ite], ite + 1, target);
        //return;
    }
    else
    {
        for(int i = ite;i<s_size;i++)
        {
            t[t_size] = s[i];
            sumofsubset(s,t,s_size,t_size+1,sum + s[i],i+1,target);
        }
    }

}

void generate(int s[], int size, int target)
{
    int *p = (int *)malloc(size * sizeof(int));
    sumofsubset(s, p, size, 0,0,0, target);
    free(p);
}

int main()
{
    int i,m,weights[100],n;

    printf("Enter the size of the array :\t");
    scanf("%d",&n);

    printf("Enter %d numbers :\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&weights[i]);
    }

    
    printf("Enter the number :\t");
    scanf("%d",&m);

    generate(weights,n,m);
    printf("Nodes generated %d",total_nodes);

    return 0;
}