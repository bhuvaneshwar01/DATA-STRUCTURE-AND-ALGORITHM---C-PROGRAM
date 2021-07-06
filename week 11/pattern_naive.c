#include<stdio.h>

void search_Naive(char text[],char pattern[], int n,int m)
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(text[i+j]!= pattern[j])
            break;
        }
        if(j == m)
        {
            printf("pattern is found at index :\t%d \n",i);
        }
    }
}

int main()
{
    int i,ltext,lpattern;
    char c,text[100], pattern[100];

    printf("Enter the Text :-\t");
    for(i=0;((i<100)&&((c=getchar())!='\n'));i++)
    {
        text[i] = c;
        ltext++;
    }
    text[i] = '\0';

    printf("Enter the Pattern :-\t");
    for(i=0;((i<100)&&((c=getchar())!='\n'));i++)
    {
        pattern[i] = c;
        lpattern++;
    }
    pattern[i] = '\0';
    printf("****PATTERN MATCHING USING NAIVE ALGORITHM*****\n");
    search_Naive(text,pattern,ltext,lpattern);
}