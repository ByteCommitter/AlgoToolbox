//merge sort

#include<stdio.h>
#include<stdlib.h>

int main(){
    int x;
    scanf("%d", &x);
    int arr[x];
    for(int i=0; i<x; i++){
        scanf("%d", &arr[i]);
    }
    int n=x;
    int temp[n];
    int k=1;
    while(k<n){
        int l=0;
        while(l<n){
            int m=l+k;
            int h=l+2*k;
            if(m>=n){
                m=n;
            }
            if(h>=n){
                h=n;
            }
            int i=l;
            int j=m;
            int p=l;
            while(i<m && j<h){
                if(arr[i]<arr[j]){
                    temp[p]=arr[i];
                    i++;
                }
                else{
                    temp[p]=arr[j];
                    j++;
                }
                p++;
            }
            while(i<m){
                temp[p]=arr[i];
                i++;
                p++;
            }
            while(j<h){
                temp[p]=arr[j];
                j++;
                p++;
            }
            for(int i=l; i<h; i++){
                arr[i]=temp[i];
            }
            l=l+2*k;
        }
        k=2*k;
    }

    for(int i=0; i<x; i++){
        printf("%d ", arr[i]);
    }
}