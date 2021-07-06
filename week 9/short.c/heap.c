#include<stdio.h>
#define max 5

int arr[max],t,a;

void heap_adjust(int n,int i)
{
    int large = i;
    int left = 2*i;
    int right = 2*i +2;

    if(left < n && arr[left] > arr[large])
        large = left;

    if(right < n && arr[right] > arr[large])
        large = right;

    if(large != i)
    {
        t = arr_sort[i];
        arr_sort[i] = arr_sort[large];
        arr_sort[large] = t;
        heap_adjust(n, large);
    } 
}

void heap_sort()
{
    int i;
    for(i=max/2-1;i>=0;i++)
        heap_adjust(max,i)

    for(i=max-1;i>=0;i--)
    {
        t = arr[0];
        arr[0] = arr [i];
        arr[i]= t;
        heap_adjust(i,0);

         printf("\nHeap Sort Iteration %d : ", i);
         for ( a = 0; a < MAX_SIZE; a++) {
            printf("\t%d", arr_sort[a]);
        }
    }
}

int main()
{
    int i;

    printf("\n Enter %d elements for sorting \n", max);
    for(i=0;i<max;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\n Given data :\t");
    for(i=0;i<max;i++)
    {
        printf("%d\t",arr[i]);
    }

    heap_sort();

    printf("after heap sort\n");
    for(i=0;i<max;i++)
    {
        printf("%d\t",arr[i]);
    }
}