#include<stdio.h>

int binary_search(int arr[], int low, int high, int target){
    while(low<high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return mid+1;
        }
        else if(arr[mid]>target){
            low=mid;
        }
        else{
            high=mid;
        }
    }
    return -1;
}

int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    int arr[x];
    for(int i=0;i<x;i++){
        scanf("%d",&arr[i]);
    }
    //binary search for element
    int low=0,high=x-1,mid;
    int z=binary_search(arr,low,high,y);
    printf("%d", z);
}