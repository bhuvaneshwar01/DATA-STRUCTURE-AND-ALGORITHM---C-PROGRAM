#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define size 100



char lower[size], upper[size];
int l = 0, u = 0;

void print_caps(char a[], int i) 
{
    if (!a[i])
        return;
    else
    {
        if (isupper(a[i]))
            putchar(a[i]);
        return print_caps(a, ++i);
    }
}

void print_small(char a[], int i) 
{
    if (!a[i])
        return;
    else
    {
        if (islower(a[i]))
            putchar(a[i]);
        return print_small(a, ++i);
    }
}

void string_print_change(char a[]) 
{
    print_caps(a, 0);  
    print_small(a, 0); 
}

void string_change(char a[], int i) 

{
    if (!a[i])
    {
        i = 0;
        int j;
        for (j = 0; upper[j]; j++)
        {
            a[i++] = upper[j];
        }

        for (j = 0; lower[j]; j++) 
        {
            a[i++] = lower[j];
        }

        return;
    }
    else
    {
        if (islower(a[i]))
        {
            lower[l++] = a[i];
            lower[l] = '\0';
        }
        else
        {
            upper[u++] = a[i];
            upper[u] = '\0';
        }
    }
    return string_change(a, i + 1);
}

int main()
{
    int i, l, m;
    char a[size];
    scanf("%s", a);

    string_change(a, 0);

    printf("%s", a);
   
    return 0;
}