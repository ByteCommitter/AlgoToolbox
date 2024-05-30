/*
Kira finds out that life is not very simple. He wanted to get even richer. So kira realised that
revenue doesn’t matter. All the big money lies in stocks. So he decided to start trading. He wants
your help with basic trading initially, where he has a list of prices of a stock for N days and you
have to find out the maximum profit he can make out of that certain stock.
Note: Kira can buy the stock only on 1 day and can sell it any day after the day he bought it.
Although, it is not necessary that Kira buys a stock.
Input
The first line contains a positive integer N(1 ≤ N ≤ 106
) - the number of days.
The second line contains N integers a1, a2, . . . , aN (1 ≤ ai ≤ 109
) - prices across N days of the
stock.
Output
A single integer telling the maximum profit Kira can make
input
5
7 1 4 5 2
output
4
input
7
5 6 9 1 2 3 4
output
4
input
5
7 6 5 4 3
output
0
*/


#include<stdio.h>
#include<stdlib.h>


void findSum(int x,int y, int arr[]){
    int sum=0;
    for(int i=x;i<=y;i++){
        sum+=arr[i];
    }
    printf("%d\n",sum);
}

int main(){
    int n,k;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int max=0;
    for(int i=0;i<n;i++){
        int 
    }
    
}