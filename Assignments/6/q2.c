/*
Given an array of size n, you have to sort it using only quick sort algorithm.
Input
The first line contains one positive integer n (1 ≤ n ≤ 2 ∗ 103
), the size of array a.
The second line contains n integers a1, a2, . . . , an (−109 ≤ ai ≤ 109
).
Output
The only line of output should contain n integers of the sorted array a.
input
4
3 4 5 2
output
2 3 4 5
input
2
6 4
output
4 6
*/

#include<stdio.h>
#include<stdlib.h>

//we have to use the quick sort method over here...


int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    //quick sort
    int temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
    
    
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
