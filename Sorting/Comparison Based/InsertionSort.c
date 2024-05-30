#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[],int n){
    for(int j=1;j<n;j++){
        int key=arr[j];
        int i=j-1;
        while(i>=0 && arr[i]<key){
            arr[i+1]=arr[i];
            i=i-1;
        }
        arr[i+1]=key;
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

    insertionSort(arr, n);

    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}