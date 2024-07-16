#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void createSubsequences(vector<int> v,int size,int ptr,vector<int>&subseq){
    if(ptr==size){
        cout<<"{";
        for(int i=0;i<subseq.size();i++){
            cout<<subseq[i]<<", ";
        }
        cout<<"}";
        cout<<endl;
        return ;
    }
    //we pick the certain element from the subsequence
    subseq.push_back(v[ptr]);
    createSubsequences(v,size,ptr+1,subseq);
    //we dont pick the element from the subsequence
    subseq.pop_back();
    createSubsequences(v,size,ptr+1,subseq);
}


int main(){
    int n;
    vector<int> v={1,4,2,6,7,9,0};
    //we need to create all subSequences from the given vector and print each possible subsequence...
    vector<int> subSeq;
    createSubsequences(v,v.size(),0,subSeq);
}