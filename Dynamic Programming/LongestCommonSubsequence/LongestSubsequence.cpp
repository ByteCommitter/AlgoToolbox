#include<bits/stdc++.h>
using namespace std;

//Problem Statement:
//s1: abcdgf
//s2: abedfha
//LCS: abdh
//we return 4, the length of it


int memoizedLongestCommonSubsequence(string s1,string s2,int n,int m,vector<vector<int>>& t){
    if(n==0||m==0){
        return 0;
    }
    
    if(t[n][m]!=-1){ return t[n][m] ;} //Maximise the function

    if(s1[n-1]==s2[m-1]){
        return t[n][m]=1+memoizedLongestCommonSubsequence(s1,s2,n-1,m-1,t);
    }
    else{
        return t[n][m]=max(memoizedLongestCommonSubsequence(s1,s2,n-1,m,t),memoizedLongestCommonSubsequence(s1,s2,n,m-1,t));
    }
}


int longestCommonSubsequence(string s1,string s2,int n,int m){
    if(n==0 || m==0){//easier to deal with n and m instead, as we dont need to constantly keep changing the string
        return 0;
    }
    //Choice Diagram
    int res=0;

    //To make the choice diagram:
    //abcfgh
    //abedfh
    //Last character check
    //if same reduce both
    //if not same, we have two choices- either reducing string s1 or reducing string s2
    //here we return the maximum of both of the two above choices
     
    if(s1[n-1]==s2[m-1]){
        return 1+longestCommonSubsequence(s1,s2,n-1,m-1);
    }
    else{
        return max(longestCommonSubsequence(s1,s2,n,m-1),longestCommonSubsequence(s1,s2,n-1,m));
    }


}


int main(){
    string s1,s2;
    cin>>s1>>s2;


    //Recursive Solution:
    //1.Base cases try to get
    //2.Choice Diagram
    //Think in terms of n->n-1->n-2

    
    //Now think for base case
    //think of the smallest valid input for this
    //Here the smallest case which we would consider as base case - empty string
    //The result for which would also be an empty string obviously...
    //So if either string is empty, our result would be the same which would be an empty string   
    

    cout<<longestCommonSubsequence(s1,s2,s1.length(),s2.length());
    cout<<"\nChecking Memozed"<<endl;
    int n=s1.length(),m=s2.length();
    vector<vector<int>> t(n+1,vector<int>(m+1,-1));
    cout<<memoizedLongestCommonSubsequence(s1,s2,n,m,t);

}