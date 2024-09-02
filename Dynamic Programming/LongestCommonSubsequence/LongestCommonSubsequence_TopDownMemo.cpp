#include<bits/stdc++.h>
using namespace std;

int main(){
    //Implementing the top down implementation of the Longest Common Subsequence problem

    string s1,s2;
    cin>>s1>>s2;

    int n=s1.length();
    int m=s2.length();

    vector<vector<int>> t(n+1,vector<int>(m+1,-1));

    for(int i=n;i>=0;i--){
        for(int j=m;j>=0;j--){
            //Setting up the base case
            if(i==0||j==0){
                t[i][j]=0;
            }
        }
    }
    
    //Setting up the choice diagram
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }

    cout<<"The longest Common Subsequence is of length "<<t[n][m];
}