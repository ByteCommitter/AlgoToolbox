#include<bits/stdc++.h>
using namespace std;

/*
Question:
Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
For example, if n=3, there are 4 ways:

1+1+1
1+2
2+1
3

Input
The only input line has an integer n.
Output
Print the number of ways modulo 10^9+7.
*/
int main(){
    long MOD=pow(10,9)+7;
    int n;
    cin>>n;
    vector<int>dp(n+1,0);
    if(n==0){
        return 0;
    }
    else if(n<=6){
        cout<< pow(2,n-1);
        return 0;
    }
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    dp[4]=8;
    dp[5]=16;dp[6]=32;
    
    for(int i=7;i<=n;i++){
        long long sum=0;
        for(int j=1;j<=6;j++){
            sum+=dp[i-j];
            sum=sum%MOD;
        }
        dp[i]=sum;
    }
    cout<<dp[n];
    
    return 0;
}