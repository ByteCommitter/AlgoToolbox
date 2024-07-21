#include<bits/stdc++.h>

void dfs(vector<int> adj[],vector<int> vis,vector<int> dfsVec,int node){    
    vis[node]=1;
    dfsVec.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it);
        }
    }
}   

int main(){
    int n,m;
    cin>> n >> m ;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    //making a Depth First Search
    //it'd be a recursive function, we can traverse and go deeper through the graph easily this way
    vector<int> dfsVec;
    //we go down to each node and put it in the same recursive function and insert all the unvisited nodes onto the vector.
    vector<int> vis(n+1,0);
    dfs(adj[],vis,dfsVec,0);    
}