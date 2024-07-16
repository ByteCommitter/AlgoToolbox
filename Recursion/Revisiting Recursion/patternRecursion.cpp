#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void getTargetSum(vector<int> arr,vector<int> temp,int target, int index, int sum){
    if (index==arr.size()+1){
        //Put this piece of code anywhere, doesnt matter
        // if(sum==target){
        //     for(int i=0;i<temp.size();i++){
        //         cout<<temp[i]<<" ";
        //     }
        //     cout<<endl;
        // }
        return;
    }
    if(sum==target){
        for(int i=0;i<temp.size();i++){
            cout<<temp[i]<<" ";
        }
        cout<<endl;
        return ;
    }
    sum+=arr[index];
    temp.push_back(arr[index]);
    getTargetSum(arr,temp,target,index+1,sum);
    sum-=arr[index];
    temp.pop_back();
    getTargetSum(arr,temp,target,index+1,sum);
}

void printSubsequences(vector<int> arr,vector<int> temp, int ind){
    if(ind == arr.size()){
        for(int i=0;i<temp.size();i++){
            cout<<temp[i]<<" ";
        }
        cout<<endl;
        return ;
    }
    temp.push_back(arr[ind]);
    printSubsequences(arr,temp,ind+1);
    temp.pop_back();
    printSubsequences(arr,temp,ind+1);
}

int main(){
    //int n;
    //cin>>n;
    vector<int> f={1,2,4,6,0,9};
    // for(int i=0;i<n;i++){
    //     int x;
    //     cin>>x;
    //     f.push_back(x);
    // }
    vector<int> temp;
    //To Print All subsequences from a given vector
    //printSubsequences(f,temp,0);

    //To get all the subsequences whose sum is a particular target.
    int target;
    cin>> target;
    getTargetSum(f,temp,target,0,0);
}