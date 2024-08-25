#include<bits/stdc++.h>
using namespace std;

/*
Question:
You are in a book shop which sells n different books. You know the price and number of pages of each book.
You have decided that the total price of your purchases will be at most x. What is the maximum number of pages you can buy? You can buy each book at most once.
Input
The first input line contains two integers n and x: the number of books and the maximum total price.
The next line contains n integers h_1,h_2,\ldots,h_n: the price of each book.
The last line contains n integers s_1,s_2,\ldots,s_n: the number of pages of each book.
Output
Print one integer: the maximum number of pages.
*/


//THOUGHTS:
//Just a different version of Knapsack...

int knapsack(vector<int>prices,vector<int>pages,int target){
    int n=prices.size();
    int t[n+1][target+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            if(i==0){
                t[i][j]=0;
            }
            else if(j==0){
                t[i][0]=0;
            }
        }
    }

    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(prices[i-1]<=j){
                t[i][j]=max(pages[i-1]+t[i-1][j-prices[i-1]],t[i-1][j]);
            }
            else {
                t[i][j]=t[i-1][j];
            }
        }
    }

    return t[n][target];
    
}

int main(){
    int n,x;
    cin>>n>>x;
    //x is the price limit
    vector<int>prices,pages;
    for(int i=0;i<n;i++){
        int z;
        cin>>z;
        prices.push_back(z);
    }
    
    for(int i=0;i<n;i++){
        int z;
        cin>>z;
        pages.push_back(z);
    }

    cout<<knapsack(prices,pages,x);

    return 0;

}