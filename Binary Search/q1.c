/*
o. But only bamboo of a certain height can fulfill his hunger,
not bigger, not smaller. He sees a bunch of bamboos lined up from left to right in ascending order
of their heights. Help Nom find the perfect bamboo to beat his hunger.
Note: Assume that bamboo of the height Nom loves, always exists in the bunch.
Input
The first line contains a two integer N and H (1 ≤ N ≤ 106
) and (1 ≤ H ≤ 109
) - the number of
bamboos in the bunch and the height of the bamboo Nom loves respectively.
The second line contains an array of size N containing (a0, a1, . . . , aN−1) where (1 ≤ ai ≤ 109
) -
heights of different bamboos sorted in ascending order.
Output
A single integer, position of the bamboo in the bunch (array). Assume 1-based indexing.
Your solution should run in O(logN) time complexity.
input
5 24
12 23 24 56 37
output
3
input
10 230
99 102 123 126 210 211 230 300 309 415
output
7
*/
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int start=0;
    int end=n-1;

    while(start<end){
        int mid=(start+end)/2;
        if(arr[mid]==k){
            printf("%d",mid+1);
            break;
        }
        else if(arr[mid]>k){
            end=mid-1;
        }
        else if(arr[mid]<k){
            start=mid;
        }
    }
}