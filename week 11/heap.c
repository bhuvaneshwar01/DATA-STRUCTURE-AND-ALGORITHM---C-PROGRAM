#include<stdio.h>
#include<stdlib.h>

void heapify(int a[],int n,int i)
{
    int temp;
    int large = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l < n && a[l] > a[large])
        large = l;
    
    if(r < n && a[r] > a[large])
        large =  r;

    if(large != i)
    {
        temp = a[i];
        a[i] = a[large];
        a[large] = temp;
        
        heapify(a, n, large);
    }
}

void buildHeap(int a[],int n)
{
    int i;
    for(i=n/2 - 1;i>=0;i--)
        heapify(a,n,i);
    

}

void printHeap(int arr[], int n)
{
    int i;

    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);

    printf("\n");
}

int main()
{
    int a[100],n,i;

    printf("Enter the size of the array :-\t");
    scanf("%d",&n);

    printf("Enter %d element in an array :-\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("The Array is \t");
    printHeap(a,n);

    buildHeap(a,n);
    printf("the heap is\t");
    printHeap(a,n);
    
    return 0;
    
}