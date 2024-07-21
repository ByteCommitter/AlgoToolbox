#include<bits/stdc++.h>
using namespace std;

//level-wise traversal
vector<int> bfs(int n,vector<int> adj[]){
    vector<int> bfs;
    int vis[n]=0;
    //missed an important line:
    vis[0]=1;//we're doing this as the prelim step...
    //as we're going to input the first node onto the bfs level vector...
    queue<int> q;

    q.push(0);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);   
            }
        }
    }
    return bfs;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    //calling the level order function
    vector<int> levelOrderTraversed=bfs();

} 