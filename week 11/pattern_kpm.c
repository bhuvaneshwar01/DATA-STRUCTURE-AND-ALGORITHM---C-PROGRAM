#include<stdio.h>
#include<string.h>

void computelpsarray(char *pattern, int m,int *lps)
{
    
    int len =0;
    lps[0] = 0;

    int i = 1;
    while(i < m)
    {
        if(pattern[i]  == pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if( len != 0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void search_KPM( char *text,char *pattern)
{
    
    int m = strlen(pattern);
    int n = strlen(text);

    int lps[m];
    computelpsarray(pattern,m,lps);

    int i = 0;
    int j = 0;

    while(i<n)
    {
        if(pattern[j] == text[i])
        {
            i++;
            j++;

        }

        if(j == m)
        {
            printf("pattern found at index %d\n",i-j);
            j = lps[j-1];
        }

        else if((i<n) && (pattern[j] != text[i]))
        {
            if(j != 0) 
             j = lps[j-1];

            else    
                i = i + 1;
                 
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
        
    }
    text[i] = '\0';

    printf("Enter the pattern :-\t");
    for(i=0;((i<100)&&((c=getchar())!='\n'));i++)
    {
        pattern[i] = c;
        
    }
    pattern[i] = '\0';
   printf("****pattern MATCHING USING KMP ALGORITHM*****\n");
  
    search_KPM(text,pattern);

    return 0;
}