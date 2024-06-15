#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int missing[n];//the missing numbers from which we will be searching for the sum of k
    int tally[n];
    for(int i=1;i<=n;i++){
        tally[i-1]=0;
    }
    for(int i=0;i<n;i++){ 
        int x=arr[i];  
        tally[x-1]++;
    }
    //tally now has the count of all the numbers in the array
    int cnt=0;
    for(int i=0;i<n;i++){
        if(tally[i]==0){
            missing[cnt]=i+1;
            cnt++;
        }
    }  

    for(int i=0;i<cnt-1;i++){
        int sum=missing[i];
        for(int j=i+1;j<cnt;j++){
            if(sum+missing[j]==k){
                sum+=missing[j];
                printf("yes");
                return 0;
            }
        }
    }
    printf("no");

    return 0;
}