/*
For the final challenge, Nom comes to the top of a cliff. Below he sees a N×N matrix-like
ground filled with landmines. But, there is a possibility that there could be one block without any
mines. In order to obtain the final jar of peanut butter, he must jump on that one block only, about
which is written in the scroll, if it exists. Otherwise, he will lose all the previous peanut butter jars.
It is given that each row is sorted and the last block of i-th row is strictly lesser than the first block
of (i + 1)-th row. Find out whether or not Nom should jump down.
Input
The first line contains a single integer N (1 ≤ N ≤ 2 ∗ 103
) - dimensions of the matrix-like land.
The second line contains a single integer K (−109 ≤ K ≤ 109
) - the block on which Nom should
land.
Consequent N lines contain N integers (a0, . . . , aN−1) separated with a space (−109 ≤ ai ≤ 109
).
Output
”YES” if the block exists, otherwise ”NO”.
Your solution should run in O(log(N×N)) time complexity.
input
3
34
2 20 21
25 30 31
34 37 40
output
YES
input
4
16
2 20 21 23
25 30 31 32
34 37 40 42
44 48 49 50
output
NO
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    int start=0,end=n;
    int flag=0;
    while(start<end){
        int mid=(start+end)/2;
        if(arr[mid][n-1]>=k && arr[mid][0]<=k){
            flag=mid;
            break;
        }
        else if(arr[mid][n-1]>k){
            end=mid;
        }
        else if(arr[mid][n-1]<k){
            start=mid;
        }
    }
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=arr[flag][i];
    }

    int high=n-1,low=0;

    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==k){
            printf("YES");
            return 0;
        }
        else if (a[mid]>k){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    printf("NO");
    return 0;
}