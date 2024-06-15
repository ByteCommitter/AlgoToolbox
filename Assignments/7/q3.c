#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int max=1;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        arr[i]=x;
        if(max<x){
            max=x;
        }
    }
    int tally[n];
    for(int i=1;i<=max;i++){
        tally[i-1]=0;
    }
    int count[n];
    //count[n] is initialised with everything to 0 and then if it's zero we add numbers and multiply it each time...
    for(int i=0;i<n;i++){
        count[i]=0;
    }

    for(int i=1;i<=n;i++){ 
        int x=arr[i-1];  
        tally[x-1]++;
    }

    
    int cnt=0;
    for(int i=0;i<n;i++){
        while(tally[i]>0){
            printf("%d ",i+1);
            tally[i]--;
        }
    }
    for(int i=n-1;i>=0;i--){
        int x=arr[i];
        int sum=count[x-1];
        if(sum==0){
            sum=i+1;
        }else{
            sum*=10;
            sum+=(i+1);
        }
        count[x-1]=sum;
    }
    printf("\n");
    for(int i=0;i<n;i++){
       while(count[i]>0){
            printf("%d ",count[i]%10);
            count[i]=count[i]/10;
       } 
    }

}