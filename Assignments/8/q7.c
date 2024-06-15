/*
Orakash is a very smart guy. Kira had very high expectations of Orakash, but Orakash shifted
domains and Kira felt sad. Now Orakash wanted to start his comeback arc. So Kira felt happy and
gave him a trivially easy problem to get him started. The problem is as follows:
Given an array of size n, find the number of all (non-empty) contiguous subarrays such that no two
elements in the subarray have an absolute difference more than k.
Help Orakash in his comeback to become a Master-Candidate.
Input
The first line contains two integers n k (1 ≤ n ≤ 106
, 1 ≤ k ≤ 109
), as mentioned in the problem..
The second line contains n integers a1, a2, . . . , an (1 ≤ ai ≤ 109
).
Output
A single integer - the number of (non-empty) subarrays which satisfy the given condition.
input
4 2
5 4 2 4
output
8
explanation
subarrays of size 1: [5], [4], [2], [4].
subarrays of size 2: [5,4], [4,2], [2,4].
subarrays of size 3: [4,2,4].
There are no subarrys of size 4.
Total continuous subarrays = 4 + 3 + 1 = 8.
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
    int cnt=0;
    for(int i=0;i<n;i++){
        int min=arr[i];
        cnt++;
        for(int j=i;j<n;j++){
            if((arr[j]-min)>=k){
                cnt++;
            }
            if(arr[j]<=min){
                min=arr[j];
                printf("%d  %d\n",min,arr[j]);
            }
        }
    }
    printf("%d ",cnt);
}