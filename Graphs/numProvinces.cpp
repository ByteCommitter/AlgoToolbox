#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

vector<int> dfs(vector<int> adj[],int start,int n){
    stack<int> s;
    vector<int> res;
    vector<int> vis(n+1,0);
    s.push(start);
    vis[start]=1;
    while(!s.empty()){
        int node=s.top();
        s.pop();
        res.push_back(node);
        for(int i=0;i<adj[node].size();i++){
            if(!vis[adj[node][i]]){
                vis[adj[node][i]]=1;
                s.push(adj[node][i]);
            }
        }
    }
    return res;
}

int numofProvinces(vector<int> adj[],int n){
    int cnt=0;  
    vector<int> mis(n+1,0);
    for(int i=0;i<n;i++){
        if(mis[i]==0){
            vector<int> check=dfs(adj,adj[i][0],n);
            for(int i=0;i<check.size();i++){
                mis[check[i]]=1;
            }
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int n,k,start;
    cin>>n>>k;
    //we'll work with adjacency list only here onwards...
    vector<int> adj[n+1];//array of vectors...
    for(int i=0;i<k;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<numofProvinces(adj,n);
    
}