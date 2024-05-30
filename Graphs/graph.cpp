#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> bfs(vector<int> adj[],int n){//adjacency list...
    int vis[n]={0};
    vis[0]=1;//0 is already visited.... cant be the case if we have 0 in the bfs...
    queue<int> q;
    q.push(0);//so that we can run atleast one while loop..
    vector<int> vec;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it: adj[node]){
            if(vis[it]!=1){
                vis[it]=1;
                q.push(it);
            }
        }
        vec.push_back(node);
    }
    return vec;
}

int main(){
    int n,m;
    cin>>n>>m;
    int adj[n+1][n+1];
    vector<int> list[n+1];//notice the difference in the declaration...
    //this special declaration holds n+1 vectors and is an array of n+1 vectors..

    //storage of the graph:
    
    //Adjacency Matrix:
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //Adjacency Matrix...
        adj[u][v]=1;
        adj[v][u]=1;
        //Adjacency List
        list[u].push_back(v);
        list[v].push_back(u);//in case of directed graph, we wont need this..
    }
    vector<int> res=bfs(list,n);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
}

