#include<stdio.h>

#define max 100

int a[max];
int b[max];

void merging(int low,int mid, int high)
{
    int l1,l2,i;
    for(l1=low,l2 = mid+1,i = low; l1<=mid && l2 <= high;i++)
    {
        if(a[l1]<a[l2]) b[i] = a[l1++];
        
        else    b[i] = a[l2++];
    }
    while(l1<=mid)  b[i++] = a[l1++];
    while(l2<=high) b[i++] = a[l2++];

    for(i=low;i<=high;i++)  a[i] = b[i];
}

void sort(int low,int high)
{
    int mid;
    if(low < high)
    {
        mid= (low+high)/2;
        sort(low,mid);
        sort(mid+1,high);
        merging(low,mid,high);
    }
    else    return;
}

int main()
{
    int n,i;
    printf("Enter the size of the array :-\n");
    scanf("%d",&n);
    printf("Enter the %d element\n",n);
    for(i=0;i<n;i++)
    {
        printf("Enter the %dth element :\t",i+1);
        scanf("%d",&a[i]);
    }
   
    printf("\nLIST BEFORE MERGE SORT\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    sort(0, n-1);
    printf("\nLIST AFTER MERGE SORT\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}