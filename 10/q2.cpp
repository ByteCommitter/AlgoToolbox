/*
Kira has gone to UP to give his ICPC Continentals, so Nom has to make this Assignment in
loneliness. Thus, Nom decided to steal all of Kira’s prize money to go visit new cities which he
had never been to. Assume that Kira’s prize money never ends. Not all cities are connected together.
Now, Nom gets the news the Kira damaged all these roads through which he was planning to
travel, to get his money back. Nom called up the Road Department and they told him that it will
take a few years to get the roads back up again, unless..., he paid them some amount per road.
Nom reluctantly agreed. Now, they gave him roads and the cost to rebuild them. Help Nom find
the minimum cost to rebuild the roads such that he can go to all cities.
Input
The first line contains a single integer n (1 ≤ n ≤ 2 ∗ 103
) - number of roads.
The next n lines contain three integers each, specifying the two cities connected by a road and the
cost to rebuild it.
Output
A single integer - minimum cost to rebuild the roads to connect all cities.
input
7
1 2 1
1 3 2
1 4 3
1 5 4
2 3 5
2 5 7
3 4 6
output
10
*/

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

const int MAX = 2005;
vector<pair<int, int>> adj[MAX];
bool visited[MAX];
int cost[MAX];

int main() {
    int n;
    cin >> n;
    int max_city = 0;
    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        max_city = max(max_city, max(a, b));
    }

    for(int i = 1; i <= max_city; i++) cost[i] = INT_MAX;
    cost[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while(!pq.empty()) {
        int a = pq.top().second; pq.pop();
        if(visited[a]) continue;
        visited[a] = true;
        for(auto u : adj[a]) {
            int b = u.first, w = u.second;
            if(w < cost[b]) {
                cost[b] = w;
                pq.push({w, b});
            }
        }
    }

    int totalCost = 0;
    for(int i = 1; i <= max_city; i++) totalCost += cost[i];

    cout << totalCost << "\n";

    return 0;
}