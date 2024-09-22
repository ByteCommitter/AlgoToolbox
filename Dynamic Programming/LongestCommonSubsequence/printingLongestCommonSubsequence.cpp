#include<bits/stdc++.h>
using namespace std;


string printLCS(string s1,string s2){
    int n=s1.length(),m=s2.length();

    string t[n+1][m+1]; 

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            t[i][j]="";
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                t[i][j]=t[i-1][j-1]+s1[i-1];
            }
            else{
                if(t[i-1][j].length()>t[i][j-1].length()){
                    t[i][j]=t[i-1][j];
                }
                else{
                    t[i][j]=t[i][j-1];
                }
            }
        }
    }
    return t[n][m];
}

int main(){
    //Printing the longest common Subsequence instead of getting the length of the sequence
    string s1,s2;
    cin>>s1>>s2;

    cout<<printLCS(s1,s2)<<endl;
    
    return 0;
}