#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n){
    int done=0;
    do{
        done=0;
        for(int i=0;i<n;i++){
            if(arr[i]>arr[i+1]){
                swap(&arr[i],&arr[i+1]);
                done=1;
            }
        }
    }while(done);
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    int i;
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}