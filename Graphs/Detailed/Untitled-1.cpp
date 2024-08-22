#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int solution(vector<int> &A, vector<int> &B, int X, int Y) {
    int n = A.size();
    n += 1;
    n *= 2;
    vector<pair<int, int>> adj[n];

    for (int i = 0; i < n / 2 - 1; i++) {
        adj[2 * i].push_back({2 * i + 2, A[i]});
        adj[2 * i + 1].push_back({2 * i + 3, B[i]});
        adj[2 * i].push_back({2 * i + 1, X});
        adj[2 * i + 1].push_back({2 * i, Y});
    }

    // Dijkstra's Algorithm
    vector<int> dist(n, INT_MAX);  // Distance array initialized to infinity
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Starting nodes: 0 and 1
    dist[0] = 0;
    dist[1] = 0;
    pq.push({0, 0});
    pq.push({0, 1});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (currentDist > dist[u]) continue;  // Ignore outdated entries

        for (auto &neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // End nodes: n-2 and n-1
    int end1 = n - 2;
    int end2 = n - 1;

    return min(dist[end1], dist[end2]);
}


int main() {
    vector<int> A = {8,3,3};  // Example weights for path 0 -> 2, 2 -> 4, etc.
    vector<int> B = {6,1,10};  // Example weights for path 1 -> 3, 3 -> 5, etc.
    int X = 4;  // Example cross edge weight from even-indexed node to odd-indexed node
    int Y = 3;  // Example cross edge weight from odd-indexed node to even-indexed node

    int result = solution(A, B, X, Y);
    cout << "Shortest path to the end node is: " << result << endl;

    return 0;
}
