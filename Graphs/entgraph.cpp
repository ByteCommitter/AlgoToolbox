#include<iostream>
#include<vector>

using namespace std;

int main(){
    int v,e;
    cin>>v>>e;
    //Adjacency Matrix
    int adj[n+1][m+1];
    vector<int> adj[n+1];//declaring an adjacency list...
    //it's an vector of n+1 arrays...
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
        //we add weight in here instead of 1 where weights are specified...
        
        //for adjacency list:
        adj[u].push_back[v];
        adj[v].push_back[u];//line not requried in case of a driected graph...
    }
    //Adjacency List

}