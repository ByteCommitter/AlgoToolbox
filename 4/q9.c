/*
Kira was furious that he was not able to help Shimmerun convert the numbers into English. So
Kira decided that instead of Billions or something, he now wants to have an m-figure income. In
between all this, since the Supreme Court of BITS decided that whatever income a person gets,
the sum of its digits should be equal to k, Kira wants to find out his lowest possible (for fun) and
highest possible income (The income should not have any leading zeros).
Input
The first line contains 2 integers m and k (1 ≤ m ≤ 100; 0 ≤ k ≤ 900) - the number of digits and
the sum of digits respectively.
Output
2 integers - lowest possible and highest possible numbers, if they exist. If no such pair exists, print
“ − 1 − 1” (without the quotes).
input
10 1
output
1000000000 1000000000
*/

#include<stdio.h>
typedef unsigned long long ll;

void solvemin(int m, int k, int min[]){
    k-=1;
    for(int i=m-1;i>0;i--){
        if(k>9){
            min[i]=9;
            k-=9;
        }
        else{
            min[i]=k;
            k=0;
        }
    }
    min[0]=k+1;
}

void solvemax(int m, int k, int min[]){
    for(int i=0;i<m;i++){
        if(k>9){
            k-=9;
            min[i]=9;
        }else{
            min[i]=k;
            k=0;
        }   
    }
}

int main(){
    int m,k;
    scanf("%d %d",&m,&k);
    int min[m];
    int max[m];
    solvemax(m,k,max);
    solvemin(m,k,min);
    for(int i=0;i<m;i++){
        printf("%d",min[i]);
    }
    printf("\n");
    for(int i=0;i<m;i++){
        printf("%d",max[i]);
    }
}