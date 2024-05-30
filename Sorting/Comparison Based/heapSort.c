#include<stdio.h>

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

//heapify converts the given data structure, here an array to a heap

void heapify(int arr[], int n, int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        heapify(arr,n,largest);//it'd traverse through the whole heap to check for the property of maxHEap...
    }
}

void buildMaxHeap(int arr[],int n){
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr,n,i);
    }
}

void heapSort(int arr[],int n){
    buildMaxHeap(arr,n);
    //now we push the largest element in the heap succesfully into the last part
    //of the array and consecutively move on...
    for(int i=n-1;i>=0;i--){
        swap(&arr[i],&arr[0]);
        heapify(arr,i,0);//we heapfiy the root... on the i elements
    }
}

void printHeap(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    //bubbleSort(arr,n);
    //selectionSort(arr, n);

    heapSort(arr,n);
    printHeap(arr,n);
    return 0;
}