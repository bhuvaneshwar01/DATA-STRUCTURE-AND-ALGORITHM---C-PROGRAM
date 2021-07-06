#include<stdio.h>
#define size 100

int main(){
    int count=0,i;
    char *p,a[size],c;

    printf("Enter the character:-\n");

    for(i=0;(i<(size-1))&&((c=getchar())!='\n');i++){
       a[i]=c;
        
    }
    a[i]='\0';
    p=a;
    for(i=0;i<size;i++){
        if((*(p+i))!='\0'){
            count++;
        }
        else{
            break;
        }
    }

    printf("The length of the string using pointer is %d\n",count);

    return 0;
}