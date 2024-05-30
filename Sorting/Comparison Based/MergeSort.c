#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int mid, int left, int right){
    int n1=mid-left+1;
    int n2=right-mid;
    int leftArray[n1];
    int rightArray[n2];

    //now we merge the left and right array based on the value
    //let's first insert values into the left and right sub arrays
    for(int i=0;i<n1;i++){
        leftArray[i]=arr[left+i];
    }
    for(int i=0;i<n2;i++){
        rightArray[i]=arr[mid+1+i];
    }
    int left_cnt=0,right_cnt=0;
    int i = left;
    while(left_cnt<n1 && right_cnt<n2){
        if(leftArray[left_cnt]<=rightArray[right_cnt]){
            arr[i]=leftArray[left_cnt];
            left_cnt++;
        }
        else{
            arr[i]=rightArray[right_cnt];
            right_cnt++;
        }
        i++;
    }
    while(left_cnt<n1){
        arr[i]=leftArray[left_cnt];
        left_cnt++;
        i++;
    }
    while(right_cnt<n2){
        arr[i]=rightArray[right_cnt];
        right_cnt++;
        i++;
    }
}

void mergeSort(int arr[],int l, int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);

        merge(arr,m,l,r);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    int i;
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0,n-1);

    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}