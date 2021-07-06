#include<stdio.h>
#include<string.h>
//#include<bits/stdc++.h>

int max(int a, int b)
{
    return  (a > b)? a : b;
}
int longcomseq(char *x,char *y,int la,int lb)
{
    int l[la+1][lb+1],r[100][100];
    int i,j,n=0,m=0;
    char a[100];
    int k=l[la+1][lb+1];
    
    for(i = 0; i<=la;i++)
    {
        for(j=0;j<=lb;j++)
        {
            if(i==0 || j==0)
            {
                l[i][j] = 0;
                //r[n++][m++] = l[i][j];
                r[i][j] = l[i][j];
            }
            else if(x[i-1] == y[j-1])
            {
                l[i][j]=l[i-1][j-1] +1;
               // r[n++][m++] = l[i][j];
                r[i][j] = l[i][j];
            }
            else
            {
                l[i][j] = max(l[i-1][j-1], l[i][j-1]);
               // r[n++][m++] = l[i][j];
               r[i][j] = l[i][j];
            }
        }
    }
    n = l[la][lb];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d\t",r[i][j]);
        }
        printf("\n");
    }
    
    a[n] = '\0';
    i = la;
    j = lb;
    while(i>=0 && j>=0)
    {
        if(x[i-1] == y[i-1])
        {
            a[--n] = x[i-1];
            i--;
            j--;
        }
        else
        {
            if(l[i-1][j] > l[i][j-1])
                i--;
            else    
                j--;
        }
    }

    printf("longest common sequence string is %s\n",a);
    return l[la][lb];
}

int main()
{
    int i,al=0,bl=0;
    char a[100],b[100],c;

    printf("Enter the Character String 1 :\t");
    for(i=0;((i<100)&&((c = getchar())!='\n'));i++)
    {
        a[i] = c;
        al++;
    }
    a[i] = '\0';
    printf("Enter the Character String 2 :\t");
    for(i=0;((i<100)&&((c = getchar())!='\n'));i++)
    {
        b[i] = c;
        bl++;
    }
    a[i] = '\0';

    printf("\nthe length of string 1 is %d\n",al);
    printf("\nthe length of string 2 is %d\n",bl);
    int lcs = longcomseq(a,b,al,bl);
    printf("\nThe longest common sequence is\t%d\n",lcs);
}