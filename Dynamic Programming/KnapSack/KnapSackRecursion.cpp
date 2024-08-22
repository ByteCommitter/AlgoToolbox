#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int>wt,vector<int>val,int weight,int n){
    //after the base condition, make the choice diagram
    if(n==0||weight==0){
        return 0;
    }
    if(wt[n-1]<=w){
        return max(val[n-1]+knapsack(wt,val,weight-wt[n-1],index-1),knapsack(wt,val,weight,index));
    }                                       
    else if(wt[index-1]>w){ 
        return knapsack(wt,val,weight,index);
    }
}

int main(){
    //first try to think of the base conditions...
    //think of the smallest valid input
    
    int n;
    cin>>n;

    vector<int>wt,val;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        wt.push_back(x);
        val.push_back(y);
    }

    int weight;
    cin>>weight;

    cout<<knapsack(wt,val,weight,n);
    //Maximise the amount of profit you get from the knapsack
     
}