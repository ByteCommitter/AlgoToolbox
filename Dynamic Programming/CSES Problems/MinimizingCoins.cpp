#include<bits/stdc++.h>
using namespace std;

/*
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
Output
Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print -1.

Example
Input:
3 11
1 5 7

Output:
3
*/

int getMinimumCoins(vector<int>& nums,int target){
    sort(nums.rbegin(),nums.rend());
    
    int n=nums.size();
    int t[n+1][target+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            if(j==0 ||i==0){
                t[i][j]=0;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(nums[i-1]<=j){
                t[i][j]=max(t[i-1][j-nums[i-1]]+1,t[i-1][j]);
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
    int target;
    cin>>target;

    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        int ent;
        cin>>ent;
        nums[i]=ent;
    }
    cout<<getMinimumCoins(nums,target);
    return 0;
}