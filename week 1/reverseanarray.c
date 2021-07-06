#include<stdio.h>
#define size 100

int main(){
    int i,j,flag=0,n;
    char c,a[size],*p,b[size];

    printf("Enter the character :-\n");
    for(i=0;((i<=(size))&&((c=getchar())!='\n'));i++){
        a[i]=c;
        flag++;
    }
    a[i]='\0';

    p=a;

    n=flag-1;

    for(i=0;i<=n;i++){
            b[i]=*(p+(n-i));
    }

    printf("Reverse of the string is %s\n",b);
}