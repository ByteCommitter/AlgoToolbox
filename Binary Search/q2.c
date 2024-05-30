/*
After a full belly, Nom entered the mountains. As he ascended, the path became steeper and
more treacherous. To navigate the complex landscape, our panda friend faced the challenge of
identifying the peak index, the point where the mountain slope reached its summit. Furthermore,
the peak was known as the peanut butter peak since ages. Now, in order to get there, Nom has to
find the best strategy to obtain the index of the peak, thus reaching it. The problem is as follows.
You are given an array with N integers, such that there exists an i:
• a1 < a2 < . . . < ai
• ai > ai+1 > . . . > an
You have to help Nom find the index of the peak. Assume 1-based indexing.
Input
The first line contains a positive integer N (1 ≤ N ≤ 106
).
The second line contains N integers a1, a2, . . . , aN (−109 ≤ ai ≤ 109
).
Output
A single positive integer indicating the peak index of the mountain.
Your solution should run in O(logN) time complexity.
input
6
1 2 4 6 4 3
output
4
input
10
12 14 17 20 23 21 17 12 9 3
output
5
*/
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int start=0,end=n-1;

    while(start<end){
        int mid=(start+end)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            printf("%d",mid+1);
            break;
        }
        else if (arr[mid]<arr[mid+1] ){
            start=mid;
        }
        else if(arr[mid]>arr[mid+1]){
            end=mid;
        }
    }
    
}