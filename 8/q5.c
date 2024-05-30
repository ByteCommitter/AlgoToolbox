/*
Kira loves to short stocks. One day he got a special offer in his dreams. He could sell 1 stock
at spot price, remove k digits from the spot price of the stock and buy the stock back at the new
price. Find the total profit made by Kira.
Note: After each operation of removing a digit, all the leading zeroes should be removed as
well, if any.
Input
The first line contains two integers n and k (1 ≤ k ≤ n ≤ 106
- number of digits of the spot price
and the number of digits to remove respectively.
The second line contains a string s of length n having digits from 0-9 (The first digit is never 0).
Output
A single integer giving the total profit of Kira.
input
7 3
1432219
output
1431000
input
18 3
107220268174334033
output
107200000000000000
input
6 4
345063
output
345060*/


#include<stdio.h>
#include<stdlib.h>
#define size 100000;

int stack[size];
int top=-1;

void push(int n){
    if(isFull){
        printf("Overflow!!\n");
        return;
    }
    else{
        top++;
        stack[top]=n;
    }
}

int pop(){
    if(isEmpty){
        printf("Underflow!!\n");
        return -1;
    }
    else{
        int x=stack[top];
        top--;
        return x;
    }
}

bool isFull(){
    if(top==size-1){
        return true;
    }
    else{
        return false;
    }
}

bool isEmpty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    int n,k;
    scanf("%d",&n,&k);
    int num;
    scanf("%d",&num);
    while(num>0){
        int digit=num%10;
        push(digit);
        num=num/10;
    }

}