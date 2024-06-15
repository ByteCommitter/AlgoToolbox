/*
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

int searchThala(int arr[], int cnt){
    if(arr[0]==7){
        return 0;
    }
    else if(arr[cnt-2]==7){
        return cnt-2;
    }
    int low=0;
    int high=cnt-2;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==7){
            return mid;
        }else if (arr[mid] > 7) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main(){
    int cnt;
    scanf("%d",&cnt);
    int arr[cnt-1];
    for(int i=0;i<cnt;i++){
        scanf("%d",&arr[i]);
    }
    int result=searchThala(arr,cnt);
    printf("%d",result);
}