#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define max 10

long int hashno[max];
char hashstring[max][max];


int init()
{
    int i;
    for(i=0;i<max;i++)
    {
        hashno[i] = -1;
        hashstring[i][0] = 0;
    }
}

long int compute_hash(const char string[])
{
    int m = 1e9 + 9;
    long int power = 1;
    long int hash_value = 0;
    for( int i = 0;i<strlen(string);i++)
    {
        hash_value = (hash_value + (string[i] - 'a' + 1)*power) % m;
    }
    return hash_value;

}

void insert()
{

    char string[100];
    printf("enter the string to insert\n");
    scanf("%s",string);
    int index = 0,i;
    long int hkey;
    long int key = compute_hash(string);
    hkey = key % max;
    for(i=0;i<max;i++)
    {
        index = (hkey + i)%max;

        if(hashno[index] == -1)
        {
            hashno[index] = key;
            a = index;
            strcpy( hashstring[index],string);
            break;
        }
    }
    
}

void search()
{
    char string[100];
    int i,pos,flag = 0,a;
    printf("enter the string to search\n");
    scanf("%s",string);
    long int key = compute_hash(string);
    for(i=0;i<max;i++)
    {
        if( key == hashno[i])
        {
            pos = i;
            flag =1;
            break;
        }
    }
    if(flag == 1)
    {
        printf("the given string is found at the index %d\n",pos);
    }
    else
    {
        printf("Given string is not founded\n");
    }
}

void delete()
{
    char string[100];
    int i,pos,flag = 0;
    printf("enter the string to delete\n");
    scanf("%s",string);
    long int key = compute_hash(string);
    for(i=0;i<max;i++)
    {
        if( key == hashno[i])
        {
            hashno[i] = -1;
            hashstring[i][0] = 0;
            break;
        }
    }
}

void display()
{
    int i;
    printf("----------------------------------------------\n");
    printf("INDEX\t| HASH VALUE\t| STRING |\n");
    printf("----------------------------------------------\n");
    for(i=0;i<max;i++)
    {
        if(hashstring[i][0] == 0)
        {
            hashstring[i][0] = -1;
        }
    }
    for(i=0;i<max;i++)
    {
        if(hashno[i] == -1)
        {
            printf("| %d\t| %d\t\t| --\n",i, hashno[i]);
            printf("---------------------------------------------\n");
        }
        else
        {
            printf("| %d\t| %d\t\t| %s\n",i, hashno[i], hashstring[i]);
            printf("---------------------------------------------\n");
        }
    }
}

int main()
{
    init();
    int ch=0;
    while(1)
    {
        printf("Enter the option no. \n\t1)INSERTION \n\t2)DELETION\n\t3)DISPLAY \n\t4)SEARH\n\t5)EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert();
                break;
            
            case 2:
                delete();
                break;

            case 3:
                display();
                break;
            
            case 4:
                search();
                break;

            case 5:
                exit(1);
            
            case 6:
                printf("Wrong number :/\n");
        }
       
    }
    return 0;
}