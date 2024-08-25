#include<bits/stdc++.h>
using namespace std;


int main(){
    
    int n;
    cin>>n;

    vector<int>val;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        val.push_back(y);
    }

    int target;
    cin>>target;
    
    int t[n+1][target+1];
    
    //How many subsets are there which sum up to the target value...
    //We've done this with backtracking and a value permissible within 2^n

    //Set up the base case:
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            if(i==0){
                t[i][j]=0;
            }
            if(j==0){
                //we can have a null subset for every given array, which would give us one subset
                t[i][j]=1;
            }
        }
    }

    //This method doesnt check whether zeroes are there in the subset or not...
    //So that partially messes up the base condition...
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(arr[i-1]<=j){
                t[i][j]=t[i-1][j]+t[i-1][j-arr[i-1]];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }

    cout<<t[n][w];    
}