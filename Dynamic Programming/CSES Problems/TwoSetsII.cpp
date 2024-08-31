#include<bits/stdc++.h>
using namespace std;

long countSubsets(vector<int>nums,int target){
    int n=nums.size();
    long t[n+1][target+1];
    int mod=pow(10,9)+7;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            if(i==0){
                t[i][j]=0;
            }
            if(j==0){
                t[i][j]=1;
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(nums[i-1]<=j){
                t[i][j]=(t[i-1][j]+t[i-1][j-nums[i-1]])%mod;
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }

    return t[n][target];
}


int main(){
    int n;
    cin>>n;
    int sum=(n*(n+1))/2;


    vector<int>nums;
    for(int i=1;i<=n;i++){
        nums.push_back(i);
    }

    if(sum%2!=0){
        cout<< 0;
        return 0;
    } 
    sum=sum/2;
    
    long totalSubsets = countSubsets(nums, sum);




    //IMPORTANT NOTE:
    //If you want to divide after applying mod, this is the only way...
    //coz after mod, it's the remainder which is there...

    //For any number finding out the inverse would be by the formula:
    //k^(mod-2)%mod
    
    // Calculate modular inverse of 2 under mod 1e9+7
    long mod = 1e9 + 7;
    long inverseOf2 = 500000004;  // Pre-calculated value of 2^(mod-2) % mod

    // Output the result after applying modular division
    cout << (totalSubsets * inverseOf2) % mod;

    return 0;
}