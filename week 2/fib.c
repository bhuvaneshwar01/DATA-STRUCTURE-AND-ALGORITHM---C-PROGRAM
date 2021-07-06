#include<stdio.h>
#include <time.h>

int fibo(int n){
    if(n<=1)
        return n;

    else
        return fibo(n-1) + fibo(n-2);
}

int fibogoto(int n){
   if(n<=1)
    return n;

    int current=1, prev=0,i=1;
    start:
    if(i>=n)
        return current;
    else
    {
        int next = current + prev;
        prev = current;
        current = next;
        i++;
        goto start;
    }
    
}

int fibowhile(int n){
    int current = 1;
    int prev = 0, i=1;
    while(i<n){
        int next = current + prev;
        prev = current;
        current = next;
        i++;
    }
    return current;
}
int main(){

    int x;
    clock_t t,r,s; 
    scanf("%d", &x);
    t = clock(); 
    fibo(x);
    t = clock() - t; 
    double time_taken_rec = ((double)t)/CLOCKS_PER_SEC;
    r = clock(); 
    fibogoto(x);
    r = clock() - r; 
    double time_taken_1 = ((double)t)/CLOCKS_PER_SEC;
    s = clock(); 
    fibowhile(x);
    s = clock() - s; 
    double time_taken_2 = ((double)t)/CLOCKS_PER_SEC;
   
    printf("The %dth fibo no. is: %d\nUsing goto: %d\n Using while: %d\n", x, fibo(x),fibogoto(x) , fibowhile(x));
     printf("Recursion took %f seconds to execute \n", time_taken_rec);
     printf("goto took %f seconds to execute \n", time_taken_1);
     printf("fibowhile took %f seconds to execute \n", time_taken_2);
    return 0;
}