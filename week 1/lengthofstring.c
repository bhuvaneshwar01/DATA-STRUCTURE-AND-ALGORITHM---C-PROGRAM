#include<stdio.h>
#define size 100
int main(){
    int i,count=0,length;
    char a[size],c;

    printf("Enter the character :- \n");

    for(i=0; (i<size-1)&&((c=getchar())!='\n');i++){
		a[i] = c;
    }
	a[i]='\0';

    for(i=0;i<size-1;i++){
        if(a[i]!='\0'){
            count++;
        }
        else{
            break;
        }
    }

    printf("The length of the string is %d \n",count);

    return 0;
}