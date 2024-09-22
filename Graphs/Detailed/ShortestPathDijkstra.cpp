#include<bits/stdc++.h>
using namespace std;

//level-wise traversal
vector<int> dijkstra(vector<int> adj[],int n, int start){
    vector<int> d(n+1,INT_MAX);//has to be inf, to show that these nodes are unreachable from the given start node for now
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    d[start]=0;
    pq.push({0,start});
    
    while(!pq.empty()){
        int node=pq.top().second;
        int dist=pq.top().first;
        pq.pop();

        for(auto & it:adj[node]){
            int w=it.second;
            int v=it.first;
            if(d[v]>w+dist){
                d[v]=w+dist;
                pq.push({d[v],v});
            }
        }
    }

    return d;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[i].push_back({x,y});
        adj[x].push_back({i,y});
    }

    //calling the Dijkstra function which returns a vector of all distances to all the nodes around it...
    vector<int> distances=dijkstra(adj,n,start);

} 