#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,x;
    cin>>n>>x;
    long mod=pow(10,9)+7;
    vector<int> coins;
    for(int i=0;i<n;i++){
        int ent;
        cin>>ent;
        coins.push_back(ent);
    }

    //Give the number of all combinations that add up to the specific target mentioned

    int dp[n+1][x+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(i==0){
                dp[i][j]=0;
            }
            if(j==0){
                dp[i][j]=1;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(coins[i-1]<=j){
                dp[i][j]=(dp[i][j-coins[i-1]]+dp[i-1][j])%mod;
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][x];

    return 0;
}