/*
Kira practiced a lot of trees but was still scared during his ICPCs in case a tree problem came.
There was a problem he did in binary trees in which he had to find the sum of depths of all subtree nodes in a given binary tree. But in ICPC it came as a general tree instead of a binary one.
Even the example they gave was not of a general tree. Help Kira solve this problem for a general tree.
Input
The first line contains a single integer n (1 ≤ n ≤ 106
) - number of edges in the tree.
The next n lines contain two integers each, specifying the edge between two nodes.
Output
A single integer - sum of depths of all subtree nodes in the tree.
input
8
1 2
1 3
2 4
2 5
3 6
3 7
4 8
4 9
output
26
input
4
1 2
1 3
1 4
3 5
output
6
*/

#include<iostream>
#include<vector>
using namespace std;

const int MAX = 1e6+5;
vector<int> adj[MAX];
int size[MAX];
long long depth[MAX];

void dfs1(int u, int p) {
    size[u] = 1;
    for(int v : adj[u]) {
        if(v == p) continue;
        dfs1(v, u);
        size[u] += size[v];
    }
}

void dfs2(int u, int p) {
    for(int v : adj[u]) {
        if(v == p) continue;
        depth[v] = depth[u] + size[u] - size[v];
        dfs2(v, u);
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1, 0);
    dfs2(1, 0);

    long long totalDepth = 0;
    for(int i = 1; i <= n; i++) totalDepth += depth[i];

    cout << totalDepth << "\n";

    return 0;
}