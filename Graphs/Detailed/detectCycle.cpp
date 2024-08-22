#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<int> adj[],vector<int>& bfsVec){

}

int main(){
    int n,m;//n for the number of nodes and m for the number of edges

    cin>>n>>m;
    vector<int> adj[n+1];

    for(int i=0;i<n;i++){
        int x,y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }        
    //if we are able to come back to the same node, we come
    //we'll solve it using BFS this time


    //The intuition behind this is if two nodes in the parent, clash and lead to the same node which is UNVISITED then there is a cycle...
     

}