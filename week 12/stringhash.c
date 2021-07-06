#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>
#define max 10

char hash[max];
int count = -1;

int alphtono(char key)
{
    switch(key)
    {
        case 'a' :  return 1;
        case 'b' :  return 2;
        case 'c' :  return 3;
        case 'd' :  return 4;
        case 'e' :  return 5;
        case 'f' :  return 6;
        case 'g' :  return 7;
        case 'h' :  return 8;
        case 'i' :  return 9;
        case 'j' :  return 10;
        case 'k' :  return 11;
        case 'l' :  return 12;
        case 'm' :  return 13;
        case 'n' :  return 14;
        case 'o' :  return 15;
        case 'p' :  return 16;
        case 'q' :  return 17;
        case 'r' :  return 18;
        case 's' :  return 19;
        case 't' :  return 20;
        case 'u' :  return 21;
        case 'v' :  return 22;
        case 'w' :  return 23;
        case 'x' :  return 24;
        case 'y' :  return 25;
        case 'z' :  return 26;
        default  :  return 0;
    }
}

void insert()
{
    char string[max],c;
    int i,l;

    printf("Enter the string to insert\n");
    for(i=0;((i<100)&&(c=getchar())!='\n'); i++)
    {
        string[i] = c;
        l++;
    }
    string[i] = '\0';
    count = count +1;
    int s[max];

    for(int i=0;i<=l;i++)
    {
        s[i]=alphtono(string[i]);
    }

    int p=31;
    int m = 1e9 + 9;
    long long powerp = 1;
    long long hash_value = 0;

    for(int i=0;i<l;i++)
    {
        hash_value = (hash_value + (string[i])*powerp)%m;
    }
    hash[count] = hash_value;

}

void display()
{
    int i;
    for(i=0;i<=count;i++)
    {
        printf("%d\n",hash[i]);
    }
}

int main()
{
    int ch,i;
    char string,c;

    while(1)
    {
        printf("Enter the option no. \n\t1)INSERTION \n\t2)DELETION\n\t3)DISPLAY \n\t4)SEARH\n\t5)EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                
                insert();
                break;
            
           
            case 3:
                display();
                break;
            
      case 5:
                exit(1);
            
            case 6:
                printf("Wrong number :/\n");
        }
       
    }
    return 0;

}