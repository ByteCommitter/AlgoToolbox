/*
Given an array of integers, find the sum of all min(a) where a is every possible contiguous subarray
of the original array.
Since Twiggy cannot handle large numbers, help him find the answer modulo 109 + 7.
Input
The first line contains a single integer n (1 ≤ n ≤ 106
) - the number of elements in the array.
The second line contains n integers a1, a2, . . . , an (1 ≤ ai ≤ 109
).
Output
A single integer - sum of all min(a).
input
12
776 181 356 708 184 699 409 603 669 119 430 926
output
18236
*/

#include<stdio.h>
#include<stdlib.h>
#define MOD 10000007

int que[1000];
int front=-1;
int end=-1;

void enque(int x){
    if(front==-1){
        front=0;
        end++;
        que[end]=x;
    }
    else{
        if(end==999){
            printf("Overflow!!");
        }
        end++;
        que[end]=x;
    }
}

void deque(){
    if(front==-1){
        printf("UnderFlow!!");
    }
    else{
        front++;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        enque(x);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        front=i;
        int min=que[front];
        //sum+=(min%MOD);
        for(int j=front;j<n;j++){
            if(que[j]<min){
                min=que[j];
            }
            sum+=(min%MOD);
        }
        deque();
    }
    printf("%d ",sum);
}