#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<char>> grid(n,vector<char>(n,'.'));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char x;
            cin>>x;
            grid[i][j]=x;
        }
    }
    vector<vector<int>> dp(n,vector<int>(n,0));
    long mod=pow(10,9)+7;
    if(grid[0][0]=='*'){
        cout<<0;
        return 0;
    }
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='*'){
                dp[i][j]=0;
                continue;
            }
            if(i==0){
                if(j==0){
                    dp[0][0]=1;
                    continue;
                }
                dp[i][j]=dp[i][j-1];
                continue;
            }
            else if(j==0){
                dp[i][j]=dp[i-1][0];
                continue;
            }
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
        }
    }
    cout<<dp[n-1][n-1];
}