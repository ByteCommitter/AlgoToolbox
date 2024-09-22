#include<bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(string s1,string s2){
    //to get the length, get the lcs length and subtract it from the sum of lengths of s1 and s2

    //Worst case supersequence would be that string which is concatenated with each other...
    int n=s1.length(),m=s2.length();

    int t[n+1][m+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0){
                t[i][j]=0;
                continue;
            }
            if(s1[i-1]==s2[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j- 1]);
            }
        }
    }

    return m+n-(t[n][m]);
}

int main(){
     //get the length of the shortestCommonSupersequence
     string s1,s2;
     cin>>s1>>s2;

     cout<<shortestCommonSupersequence(s1,s2)<<endl;
}