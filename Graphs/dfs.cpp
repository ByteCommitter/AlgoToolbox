#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

vector<int> dfs(vector<int> adj[],int start, int n){
    int vis[n+1]={0};
    stack<int> s;
    vector<int> res;
    //the stack works well here like a stack, which prroves useful, instead of doing the recursion...
    s.push(start);

    while(!s.empty()){
        int node=s.top();
        s.pop();
        if(!vis[node]){
            //we may continue goign deeper into the graph for the depth traversal...
            res.push_back(node);
            vis[node]=1;
            for(int i=0;i<adj[node].size();i++){
                if(!vis[adj[node][i]]){
                    s.push(adj[node][i]);
                }
            }
        }
    }
    return res;
}

void printRes(vector<int> res){
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
}

int main(){
    int n,k,start;
    cin>>n>>k>>start;
    //we'll work with adjacency list only here onwards...
    vector<int> adj[n+1];//array of vectors...
    for(int i=0;i<k;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    printRes(dfs(adj,start,n));
}