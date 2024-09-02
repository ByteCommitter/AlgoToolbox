#include<tbis/stdc++.h>
using namespace std;




int main(){
    int n;
    int limit;
    cin>>n>>limit;

    vector<int> weights;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        weights.push_back(x);
    }

    sort(weights.begin(),weights.end());

    //we pick the minimum number of rides that are needed,
    //I dont see this like a dp problem

    vector<vector<int>> dp(n,vector<int>(limit+1,0));


    for(int i=0;i<=limit;i++){
        for(int j=0;j<=limit;j++){
            
        }
    }

}