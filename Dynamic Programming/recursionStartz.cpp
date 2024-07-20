//Dynamic Programming

//Those who cannot remember the past are bound to repeat it.

//1.Memoization (Top-Down Dynamic Programming)
//2.Tabulation (Bottom-Up Dyanmic Programming)

#include<bits/stdc++.h>
using namespace std;
int Fibonacci(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    return Fibonacci(n-1)+Fibonacci(n-2);
}
//why solve the sam problem over and over again?
//we solve and store the answers of over-lapping subproblems
//we store the answer of these problems in some map/table

int revFibo(int n,vector<int> dp){
    if(dp[n]!=-1){//we have memoized...
        return dp[n];
    }
    dp[n]=revFibo(n-1,dp)+revFibo(n-2,dp);
    return dp[n];
}

int main(){
    //Fibonacci sequence:
    int n;
    cin>>n;
    //cout<<Fibonacci(n);
    //Every type we solve a subproblem,we store the value
    //and every time before we start solving a particular sub problem
    //we check whether there is a solution for it on the dp vector...

    //Revised Fibonacci
    vector<int> dp(n+1,-1);
    dp[0]=0;dp[1]=1;
    cout<<revFibo(n,dp);

    
}
