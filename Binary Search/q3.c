    /*
    For his third problem, Nom meets Thala. In the dressing room there were N Jerseys hung,
    numbered from 1 to N in a sorted manner from left to right. Bhajji being the mischievous guy he
    is, decides to steal one random Jersey numbered k and then swaps the bundles of the remaining
    Jerseys from the right of k to its left and vice versa. For example, if initially there were 8 Jerseys
    [1, 2, 3, 4, 5, 6, 7, 8] and Bhajji steals Jersey 5 and swaps the bundles, the final order of the Jerseys
    would be [6, 7, 8, 1, 2, 3, 4].
    Thala’s Jersey Number is 7. Thala is worried that Bhajji might have stolen his Jersey. You’re
    given an integer N and an array of size N − 1 containing the order of the Jerseys after Bhajji stole
    one. Help Nom find out whether Thala’s Jersey is safe or not. If it is present, output its current
    index in the array, otherwise −1. Assume 0-based indexing.
    Input
    The first line contains a single integer N (7 ≤ N ≤ 106
    ) - the number of Jerseys.
    The second line contains an array of size N − 1 containing (a0, a1, . . . , aN−2) where (1 ≤ ai ≤ N).
    Output
    A single integer, index of Thala’s Jersey in the array, if present. -1 otherwise.
    Your solution should run in O(logN) time complexity.
    input
    8
    6 7 8 1 2 3 4
    output
    1
    input
    7
    4 5 6 7 1 2
    output
    3
    */
    #include<stdio.h>
    #include<stdlib.h>

    int main(){
        int n;
        scanf("%d",&n);
        int arr[n-1];
        for(int i=0;i<n-1;i++){
            scanf("%d",&arr[i]);
        }
        int start=0,end=n-2;
        while(start<end){
            int mid=(start+end)/2;
            if(arr[mid]==7){
                printf("%d",mid);
                return 0;
            }
            if(arr[mid]<7 && arr[end]<7){
                end=mid;
            }
            else if(arr[mid]<7 && arr[end]>7){
                start=mid;
            }
            else if(arr[mid]>7 && arr[mid]>7){
                end=mid;
            }
            else if(arr[mid]>7 && arr[mid]<7){
                start=mid;
            }
        }
        printf("-1");
        return 0;
    }