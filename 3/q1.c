/*
Karma and Ayanokoji were on a hunt to find the brainiest people like them. So they came
to BITS Hyderabad and decided to enter H-Block. In order to enter there, there was a puzzle.
There was a string given to them written on the floor in blocks, comprising alphabets from a to z,
lowercase. They were required to find the length of the longest substring which could be read the
same from either side. So they decided to brute force manually. Seeing this Nom stops them and
tells them to code it instead or he’ll kick them out of the campus.
Input
The first line contains an integer n (1 ≤ n ≤ 3 ∗ 103
).
The second line contains a string of length n consisting of only lowercase English alphabet.
Your solution should run in O(n2) time complexity.
Output
The length of the longest substring satisfying the condition.
input
5
babad
output
3*/

#include<stdio.h>

int longestSubPal(char a[],int n){
    int max=0;
    for(int i=0;i<n;i++){
        int left=i;
        int right=i;
        //odd
        while(a[right]==a[left] && left>=0 && right<=n){
            if(right-left+1>max){
                max=right-left+1;
            }
            right++;
            left--;
        }
        //even
        left=i;
        left=i+1;
        while(a[right]==a[left] && left>=0 && right<=n){
            if(right-left+1>max){
                max=right-left+1;
            }
            right++;
            left--;
        }
    }
    return max;
}

int main(){
    int n;
    scanf("%d",&n);
    char string[n];
    scanf("%s",string);

    
    int x=longestSubPal(string,n);
    printf("%d",x);

}