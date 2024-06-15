#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>>& graph, int start, int end) {
    vector<bool> visited(graph.size(), false);
    vector<int> parent(graph.size(), -1);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto& neighbor : graph[node]) {
            if(!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = node;
                if(neighbor == end) {
                    vector<int> path;
                    for(int v = end; v != -1; v = parent[v]) {
                        path.push_back(v);
                    }
                    reverse(path.begin(), path.end());
                    return path;
                }
            }
        }
    }
    return {};
}

int main() {
    int V, E, S, D;
    cin >> V >> E >> S >> D;
    vector<vector<int>> graph(V);
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> shortest_path = bfs(graph, S, D);
    for(int node : shortest_path) {
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}