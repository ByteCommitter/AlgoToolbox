#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int * b){
    int temp=*b;
    *b=*a;
    *a=temp;
}

void heapify(){

}

void heapSort(int arr[], int n){
    for(int i=n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }
    for(int i=n-1; i>=0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }

}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    //Q1: Merge Sort
    
    //Q2: Quick Sort

    //Q3: Heap Sort
    heapSort(arr, n);

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}