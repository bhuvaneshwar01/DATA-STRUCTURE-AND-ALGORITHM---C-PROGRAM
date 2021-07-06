#include<stdio.h>

void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[],int low,int high)
{
    int pivot = array[high];
    int i = (low-1);
    for(int j = low;j < high ;j++)
    {
        if(array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i+1] , &array[high]);
    return (i+1);
}
void quicksort(int array[],int low,int high)
{
    if(low < high)
    { 
        int pi = partition(array,low,high);
       
        quicksort(array,low,pi-1);
        quicksort(array,pi+1,high);
    }
}

void printarrayay(int array[], int size)
{
    int i;
    for(i=0;i< size;i++)
        printf("%d ",array[i]);
    printf("\n");
}

int main()
{
    int array[100];
    int i,t,n;
    printf("Enter the  size of the arrayay :-\n");
    scanf("%d",&t);
    printf("Enter the %d element\n",t);
    for(i=0;i<t;i++)
    {
        printf("Enter the %dth element :\t",i+1);
        scanf("%d",&array[i]);
    }
    quicksort(array,0,t-1);
    printf("Sorted arrayay :\n");
    printarrayay(array,t);
    return 0;
}