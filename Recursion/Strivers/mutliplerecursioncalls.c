#include <stdio.h>
#include <stdlib.h>

// Recursive function to print all possible subsequences for given array
/*
void printSubsequences(int arr[], int index, int *subarr, int subarr_size, int n) {
    // Print the subsequence when reach the leaf of recursion tree
    if (index == n) {
        for (int i = 0; i < subarr_size; i++) {
            printf("%d ", subarr[i]);
        }
        if (subarr_size == 0)
            printf("{}");

        printf("\n");
        return;
    }
    // Pick the current index into the subsequence.
    subarr[subarr_size] = arr[index];
    printSubsequences(arr, index + 1, subarr, subarr_size + 1, n);

    // Not picking the element into the subsequence.
    printSubsequences(arr, index + 1, subarr, subarr_size, n);
}*/

void printSubs(int arr[],int index,int *sub,int subindex,int n){
    if(index==n){
        for(int i=0;i<subindex;i++){
            printf("%d ",sub[i]);
        }
        printf("\n");
        return;
    }
    //addition into the last element of the subarray...
    sub[subindex]=arr[index];
    printSubs(arr,index+1,sub,subindex+1,n);
    //not picking
    printSubs(arr,index+1,sub,subindex,n);
}
// Driver Code
int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int *sub = (int *)malloc(n * sizeof(int));
    printSubs(arr, 0, sub, 0, n);

    free(sub);
    return 0;
}


