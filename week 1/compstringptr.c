#include<stdio.h>
#define size 100

int main(){
    int i,count=0,flag=0,t;
    char a[size],b[size],c,f,*p,*q;

    printf("Enter the string 1 :-\n");

    for(i=0;((i<size)&&((c=getchar())!='\n'));i++){
        a[i]=c;
        count++;
    }

    printf("Enter the string 2 :-\n");
    for(i=0;((i<size)&&((f=getchar())!='\n'));i++){
        b[i]=f;
        flag++;
    }

    p=a;
    q=b;

        for(i=0;i<=flag-1;i++){
            if(*(p+i)!=*(q+i)){
                t=0;
            }
            else{
                t=1;
            }
        }
  

    if(t==1){
         printf("Given two strings are equal\n");
    }
    else{
         printf("Given two strings are not equal\n");
    }
}