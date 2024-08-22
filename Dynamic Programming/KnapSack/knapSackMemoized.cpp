#include<bits/stdc++.h>
using namespace std;



int knapsack(vector<int>wt,vector<int>val,int weight,int n){
    //after the base condition, make the choice diagram
    if(n==0||weight==0){
        return 0;
    }
    //Memoized portion, so that we dont need to repeat
    
    if(t[n][weight]!=-1){
        return t[n][weight];
    }

    if(wt[n-1]<=weight){
        return t[n][weight]=max(val[n-1]+knapsack(wt,val,weight,n-1),knapsack(wt,val,weight,n-1));
    }
    else{
        return t[n][weight]=knapsack(wt,val,weight,n-1);
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
    static vector<vector<int>> t[n+1][w+1];
    cout<<knapsack(wt,val,weight,n);
    //Maximise the amount of profit you get from the knapsack
     
}