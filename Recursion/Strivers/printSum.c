#include<stdio.h>
#include<stdlib.h>

//printing subsequences whose sum is k...
void checkTarget(int arr[],int sub[],int index, int subindex,int target, int n,int sum){
    if(index==n){
        return ;
    }
    if (sum==target){
        for(int i=0;i<subindex;i++){
            printf("%d ",sub[i]);
        }
        printf("\n");
        return ;
    }
    sum+=arr[index];
    sub[subindex]=arr[index];
    checkTarget(arr,sub,index+1,subindex+1,target,n,sum);
    sum-=sub[subindex];
    checkTarget(arr,sub,index+1,subindex,target,n,sum);
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int sub[n];
    checkTarget(arr,sub,0,0,k,n,0);
}


/*
template:
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}
*/