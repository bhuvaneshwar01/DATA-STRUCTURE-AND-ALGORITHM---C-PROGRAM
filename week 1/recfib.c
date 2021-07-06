#include<stdio.h>

int fibonacci(int n){
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(){
    int x;

    printf("Enter the number :-\n");
    scanf("%d",&x);

    printf("%d\n",fibonacci(x));

    return 0;
}