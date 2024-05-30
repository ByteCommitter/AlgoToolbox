/*
Now that Nom has got all of his peanut butter, he went to sleep. Now, Kira wants you to
help him with his financial problems. For the first problem, you’ve been given an array of size N
consisting of annual revenues in millions. Here, Kira will ask you Q queries to find out the revenue
from element l of the array to element r (both inclusive). Assume 1-based indexing.
Input
The first line contains two integers N and Q (1 ≤ N, Q ≤ 106
).
The second line contains N elements a1, a2, . . . , aN (−109 ≤ ai ≤ 109
).
Next Q lines contain two integers l and r (1 ≤ l < r ≤ N).
Output
Q lines each with the cumulative revenue of their respective queries.
input
5 3
2 4 0 -1 4
1 3
2 3
1 4
output
6
4
5
input
4 4
3 -2 -1 7
1 4
2 3
3 4
2 4
output
7
-3
6
4
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
    scanf("%d",&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<k;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        findSum(x-1,y-1,arr);
    }
}