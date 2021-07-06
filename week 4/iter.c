#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define size 100

void iter(char a[],int n){
    int i,j=0,k=0;
    char b[size],c[size];
    for(i=0;i<=n;i++){
        if(isupper(a[i])){
            b[k]=a[i];
            k++;
        }
        else{
             c[j]=a[i];
            j++;
        }
        }
    
    printf("EXPECTED OUTPUT \n");
    puts(strcat(b,c));
}
  
    

int main(){
    int i,flag=0;
    char arr[size],c;

    printf("Enter the character :-\t");
    for(i=0;((i<size)&&((c=getchar())!='\n'));i++)
    {
        arr[i]=c;
        flag++;
    }
    arr[i]='\0';

    iter(arr,flag);

    return 0;
}