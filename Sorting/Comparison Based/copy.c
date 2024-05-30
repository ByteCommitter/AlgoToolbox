#include<stdio.h>
#include<stdbool.h>
void swap(int *a, int *b){
    int temp=*b;
    *b=*a;
    *a=temp;
}

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        bool swappy=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                swappy=true;
            }
        }
        if(swappy==false){
            break;//sorted
        }
    }
}

void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int min=arr[i];
        int flag=i;
        for(int j=i;j<n;j++){
            if(min>arr[j]){
                min=arr[j];
                flag=j;
            }
        }
        swap(&arr[i],&arr[flag]);
    }
}
//all sorting algos worked...

void MergeLists(int arr[],int start,int mid, int end){
    int len1=mid-start+1;
    int len2=end-mid+1;
    int l1[len1];
    int l2[len2];

    for(int i=0;i<len1;i++){
        l1[i]=arr[i+start];
    }
    for(int i=0;i<len2;i++){
        l2[i]=arr[i+mid+1];
    }

    for(int i=0;i<len1;i++){

    }   

}

void MergeSort(int arr[], int start, int end){
    if(start<end){
        int mid=(start+end)/2;
        MergeSort(arr,start, mid);
        MergeSort(arr,mid,end);
        MergeLists(arr, start,mid,end);
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

    MergeSort(arr,0,n);

    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}