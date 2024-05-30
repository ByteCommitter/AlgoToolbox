/*
input
6
1 2 4 6 4 3
output
4
*/

#include<stdio.h>

int peakSearch(int arr[],int num){
    int low=0;
    int high=num-1;
    if(arr[low]>arr[low+1]){
        return low;
    }
    if(arr[high]>arr[high-1]){
        return high;
    }
    high=num-2;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }
        else if (arr[mid]>arr[low]){
            low=mid;
        }   
        else if (arr[mid-1]>arr[mid]){//decreasing
            high=mid;
        }
    }
    return -1;
    
}

int main(){
    int num;
    scanf("%d",&num);
    int arr[num];
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    int result=peakSearch(arr,num);
    printf("%d",result+1);
}