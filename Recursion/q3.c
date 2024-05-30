/*
Tinku is very fond of doing CodeLeet problems. He does almost 10 problems daily. Due to
circumstances, he wanted to improve his coding skills, he decided to start solving as many hard
problems as possible. Given he has k minutes of free time, a list of ratings of problems he plans to
solve and also an estimate for the time he would need to solve this list, find the maximum sum of
ratings of problems which he can solve in his free time.
Input
The first line contains a two integers n, k (1 ≤ n ≤ 20; 1 ≤ k ≤ 104
) - number of problems that
Tinku plans to solve in his free time (in minutes).
The second line contains n integers a1, a2, . . . , an (1 ≤ ai ≤ 2000) - the ratings of the problems.
The third line contains n integers t1, t2, . . . , tn (1 ≤ ti ≤ 104
) - the time needed to solve the problems
(in minutes).
Output
Single integer containing the maximum sum of ratings mentioned in the question.
input
3 8
30 50 60
3 4 5
output
90
Explanation: He can solve the problems with rating 30, 60 and take use of his full free time 8
minutes, so the maximum sum is 90.
input
8 30
100 200 300 400 500 600 700 700
1 2 3 4 5 6 7 7
output
3000
*/
#include<stdio.h>
#include<stdlib.h>

int maxC=0;
void maxifyTime(int coins[],int times[],int n, int k,int sub[],int subindex,int time,int money,int index){
    //find out times that our suitable with us...
    if(index==n && time<=k){
        for(int i=0;i<subindex;i++){
            printf("%d ",sub[i]);
        }
        printf("\n");
        if(maxC<money){
            maxC=money;
        }
        return ;
    }
    if(time>k||index==n){
        return ;
    }
    time+=times[index];
    money+=coins[index];
    sub[subindex]=times[index];
    maxifyTime(coins,times, n,k,sub,subindex+1,time,money,index+1);
    time-=times[index];
    money-=coins[index];
    maxifyTime(coins,times, n,k,sub,subindex,time,money,index+1);
}


int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int coins[n],times[n];
    for(int i=0;i<n;i++){
        scanf("%d",&coins[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&times[i]);
    }
    int money=0;
    int sub[n];
    maxifyTime(coins,times,n,k,sub,0,0,0,0);
    printf("%d",maxC);
}