for(int i=0;i<=subindex;i++){
        sub[i]+=arr[index];
        checkBeauty(arr,sub,index+1,i,k,n);
        sub[i]-=arr[index];
    }
    if(subindex+1<k){
        sub[subindex+1]+=arr[index];
        checkBeauty(arr,sub,index+1,subindex+1,k,n);
        sub[subindex+1]-=arr[index];
    }