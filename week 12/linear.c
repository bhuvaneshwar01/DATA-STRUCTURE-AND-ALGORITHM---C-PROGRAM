#include<stdio.h>
#include<stdlib.h>

#define max 10

int hash[max];

int init()
{
    int i;
    for(i=0;i<max;i++)
    {
        hash[i] = 0;
    }
}

int insert(int key)
{
    int index,i,flag =0 , hkey;
    hkey = key % max;
    for(i=0;i<max;i++)
    {
        index = (hkey + i)%max;

        if(hash[index] == 0)
        {
            hash[index] = key;
            break;
        }
    }
}

int search(int key)
{
    int i,a,flag =0;
    for(i=0;i<max;i++)
    {
        if(key == hash[i])
        {
            a =i;
            flag =1;
            break;
        }
        else
        {
            flag =0;
        }
    }
    if(flag == 1)
    {
        printf("the given number is found at the position %d\n",a);
    }
    else
    {
        printf("THe given is not founded :/\n");
    }

}

void display()
{
    int i;
    for(i=0;i<max;i++)
    {
        printf("index %d -> value %d\n",i, hash[i]);
    }
}

int delete(int key)
{
    int i;
    for(i=0;i<max;i++)
    {
        if(key == hash[i])
        {
            hash[i] = 0;
            printf("Given number (%d) is deleted at the position is %d\n",hash[i],i);
            break;
        }
    }
}
int main()
{
    int key,ch;
    init();
    while(1)
    {
        printf("Enter the option no. \n\t1)INSERTION \n\t2)DELETION\n\t3)DISPLAY \n\t4)SEARH\n\t5)EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the number to insert\n");
                scanf("%d",&key);
                insert(key);
                break;
            
            case 2:
                printf("Enter the number to delete\n");
                scanf("%d",&key);
                delete(key);
                break;

            case 3:
                display();
                break;
            
            case 4:
                printf("Enter the number to search\n");
                scanf("%d",&key);
                search(key);
                break;

            case 5:
                exit(1);
            
            case 6:
                printf("Wrong number :/\n");
        }
       
    }
    return 0;
}