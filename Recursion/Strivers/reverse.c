#include<stdio.h>
#include<stdlib.h>

void reverse(int arr[],int n){
    int i=0,j=n-1;
    if(i==j || i>j){
        return;
    }
    
    reverse()
}

int main(){
    int n;
    scanf("%d",&n);
    
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //reverse an array using recursion:
    reverse(arr,n);
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    } 

}