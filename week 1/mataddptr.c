#include<stdio.h>
#define row 100
#define column 100
int addition(int r,int c){
    
    int a[row][column],b[row][column],sum[row][column];
    int i,j;

    printf("Enter the Matrix A:-\n");
    for(i=0;i<r;i++)    
    {    
        for(j=0;j<c;j++)    
        {      
            scanf("%d",&a[i][j]);    
        }    
    }    
    
    printf("Enter the Matrix B :-\n");    
    for(i=0;i<r;i++)    
    {    
        for(j=0;j<c;j++)    
        {    
            scanf("%d",&b[i][j]);    
        }    
    }  
    
  

    for(i=0;i<r;i++)    
    {    
        for(j=0;j<c;j++)    
        {    
            sum[i][j]=(*(*(a+i)+j))+(*(*(b+i)+j)); 
        }    
    }  

    for(i=0;i<r;i++)    
    {    
        for(j=0;j<c;j++)    
        {    
            printf("%d\t",sum[i][j]);    
        }    
        printf("\n");
    }  

    return 0;

}
int main(){
    
    int x,y;

    printf("Enter the number of row :-\n");
    scanf("%d",&x);

    printf("Enter the number of column :-\n");
    scanf("%d",&y);

    if(x==y){
        printf("The number of rows and columns are equal\n");
        addition(x,y);
    }
    else{
        printf("The number of rows and columns are not equal....\n...try again....\n");
    }
}