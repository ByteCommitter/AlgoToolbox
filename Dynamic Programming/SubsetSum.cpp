//to check whether the the particular target is there in our array, by taking a combination
//of the elements

#include<bits/stdc++.h>
using namespace std;

bool isThereSubset(vector<int>nums,int target){
    int n=nums.size();
    bool t[n+1][target+1];

    //Base condition:
    //We return true when sum==0
    //We return false when n==0
    //ifn==0 and sum==0 , then true
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<=target;j++){
            if(i==0){
                t[i][j]=false;
            }
            if(j==0){
                t[i][j]=true;
            }
        }
    }

    for(int i=1;i<=nums.size();i++){
        for(int j=1;j<=target;j++){
            if(nums[i-1]<=j){
                t[i][j]=t[i-1][j-nums[i]]||t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
}

int main(){
    //to take or not take the elements in the array, is what we contemplate on

    ///bLACK BALCH BLAH BLAH
}