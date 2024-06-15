/*
Now that Kira knows which years have led to the highest revenues, he has made a plan for each
year. He wants you to calculate which plans to consider so that he can become the richest. You will
be given with an array of revenue plans. You have to find a contiguous subarray with the highest
revenue in order to make him rich.
Input
The first line contains a positive integer N(1 ≤ N ≤ 106
) - number of revenue plans.
The second line contains N plans a1, a2, . . . , aN (−109 ≤ ai ≤ 109
).
Output
A single integer - highest possible revenue which Kira can get.
input
6
2 -1 -2 4 6 10
output
20
input
8
1 2 3 -2 0 0 3 2
output
9
*/

#include<stdio.h>

int main(){
    int q;
    scanf("%d",&q);
    int arr[q];
    for(int i=0;i<q;i++){
        scanf("%d",&arr[q]);
    }
    int max_sum=0;
    for(int i=0;i<q;i++){
        int sum=arr[i];
        for(int j=i+1;j<q-1;j++){
            if(arr[j]+sum>sum){
                sum=sum+arr[j];
            }
        }
        if(sum>max_sum){
            max_sum=sum;
        }
    }
    printf("%d ",max_sum);
}