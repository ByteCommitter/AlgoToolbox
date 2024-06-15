#include<stdio.h>
#include<math.h>
void swap(int *a, int *b){
    int temp=*b;
    *b=*a;
    *a=temp;
}
void Heapify(int arr[], int n, int i){
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
        swap(&arr[i],&arr[largest]);
        Heapify(arr,n,largest);
    }   
}

void buildMaxHeap(int arr[], int n){
    for(int i=(n/2)-1;i>=0;i--){
        Heapify(arr,n,i);
    }
}

void heapSort(int arr[], int n){
    buildMaxHeap(arr,n);
    //we now sort it...
    for(int i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        Heapify(arr,n,i);
    }
}

void printHeap(int arr[],int k){
    for(int i=0;i<k;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n,k,x;
    scanf("%d %d %d",&n,&k,&x);
    int arr[n];
    for(int i=0;i<n;i++){
        int y;
        scanf("%d",&y);
        if((y-x)<0){
            arr[i]=(-1*(y-x));
        }
        else{
            arr[i]=y-x;
        }
    }
    //now we need to sort the given arr using heapsort
    heapSort(arr,n);
    //and display the first k elements...
    printHeap(arr,k);
}