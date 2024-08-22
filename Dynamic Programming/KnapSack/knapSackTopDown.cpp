#include<bits/stdc++.h>
using namespace std;

//TOP DOWN Programming
//This is considered the real dynamic programming
//Here we use the dp vectdsdor

int knapsack(vector<int>wt,vector<int>val,int weight,int n){
    if(n==0||w==0){
        return 0;
    }
    //we want to ommit the idea of calling a recursive function, we dont make recursive calls...
    //That's why we prefer this approach
    //If we use the recursive calls for the function, at times we might get a stack voerflow,
    //so we use the top down tabulation

}


//We make the recursive function conveted to top down approach
//We only use the table here
//WE MAKE THE TABLE FROM THE VARIABLES THAT CHANGE

//Here the variables that are changing is n and the weight,
//Here we the grid point to the maxm profit given that particular value of i and j

int main(){
    
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
    int t[n+1][w+1];//fill with -1
    //the first row and column should be zero here
    //coz if(n==0||w==0), our recursive base condition

    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0||j==0){
                t[i][j]=0;
            }
            //the remaining recursive function is written here
            if(wt[i-1]<=j){
                t[i][j]=max(val[i]+t[i-1][j-val[n-1]],t[i-1][j]);//very little is changed if you notice...
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }

    //Neednt call for the function, we could do it with for loops here itself
    //cout<<knapsack(wt,val,weight,n);
    //Maximise the amount of profit you get from the knapsack

    //we Just show this for the result instead
    cout<<t[n][w];    
}