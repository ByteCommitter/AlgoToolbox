/*
As time passed by, having not had enough Peanut Butter in his life, Nom started to grow old
and weak. He decided to send one of his juniors to gather all the Peanut Butter jars from just the
longest path between any two nodes. Each node has a jar. The tree was not binary anymore, it
also grew more branches as Nom grew older.
Help Nom have as many Peanut Butter jars as he can during his last times.
Input
The first line contains a single integer n (1 ≤ n ≤ 106
) - number of edges in the tree.
The next n lines contain two integers each, specifying the edge between two nodes.
Output
A single integer - the maximum number of jars Nom can have.
input
12
0 1
0 2
0 3
1 4
1 5
1 6
3 7
3 8
6 9
6 10
7 11
9 12
output
8
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> adj[1000005];
int visited[1000005];
int maxD,maxNode;

void dfs(int node, int d) {
    visited[node] = 1;
    if(d > maxD) maxD = d, maxNode = node;
    for(int child : adj[node])
        if(visited[child] == 0)
            dfs(child, d+1);
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    maxD = -1;
    dfs(0, 0);

    for(int i = 0; i <= n; i++){
        visited[i] = 0;
    }

    maxD = -1;
    dfs(maxNode, 0);
    cout << maxD+1 << "\n";
    return 0;
}