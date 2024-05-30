#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> graphBFS(vector<int> adj[],int n){
    int vis[n]={0};
    queue<int> q;
    vector<int> res;
    vis[0]=1;
    q.push(0);
    //create a queue and push an initial element onto it
    while(!q.empty()){//push elements into the queue
        int front=q.front();
        res.push_back(front);
        q.pop();//the front of the queue is popped and pushed into a vector which is the result of the bfs...
        for(auto it:adj[front]){//goes through all its neighbours...
            if(!vis[it]){//if the neighbour hasnt been visited, it'd be added to the queue
                vis[it]=1;
                q.push(it);
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
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> res;
    printRes(graphBFS(adj,n));
}