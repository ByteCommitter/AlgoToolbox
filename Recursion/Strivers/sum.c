#include<stdio.h>
#include<stdlib.h>

void findsumtoN(int i,int n,int sum){
    if(i==n){
        printf("%d",sum);
        return ;
    }
    i++;
    sum+=i;
    findsumtoN(i,n,sum);
}

int sum(int n){
    if(n==0){
        return 0;
    }
    return n+sum(n-1);
}

int fibonacci(int n){
    if (n==1){
        return 0;
    }
    else if (n==2){
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    int n;
    scanf("%d",&n);
    //parametrized way:
    findsumtoN(0,n,0);
    //functional method of solving:
    printf("\n%d\n",sum(n));
    printf("Fibonacci:\n%d",fibonacci(n));
}