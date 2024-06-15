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
90*/
#include<stdio.h>
#include<stdlib.h>

void CodeLeet(int i,int p, int t, int ratings[],int time[],int sum, int *max){
    if(i==p){
        if(t>=0){
            int val=sum;
            if(val>*max){
                *max=val;
            }
        }
        return;
    }
    CodeLeet(i+1,p,t-time[i],ratings,time,sum+ratings[i],max);
    CodeLeet(i+1,p,t,ratings,time,sum,max);
}

int main(){
    int p,t;
    scanf("%d %d",&p,&t);
    int ratings[p];
    int  time[p];
    for(int i=0;i<p;i++){
        scanf("%d",&ratings[i]);
    }
    for(int i=0;i<p;i++){
        scanf("%d",&time[i]);
    }
    int max=0;
    CodeLeet(0,p,t,ratings,time,0,&max);
    printf("%d",max);
}

void CodeLeet(int i,int p,int t,int ratings[], int time[], int sum, int*max){
    if(i==n){
        int val=sum;
        if(val>*max){
            *max=val;
        }
        return ;
    }
    CodeLeet(i+1,p,t-time[i],ratings,time,sum+ratings[i],max);
    CodeLeet(i+1,p,,ratings,time,sum,max);
}