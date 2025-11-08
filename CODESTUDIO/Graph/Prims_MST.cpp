/*
Problem statement
You are given an undirected connected weighted graph having ‘N’ nodes numbered from 1 to 'N'. A matrix ‘E’ of size M x 2 is given which represents the ‘M’ edges such that there is an edge directed from node E[i][0] to node E[i][1]. You are supposed to return the minimum spanning tree where you need to return weight for each edge in the MST.

For example :

The MST (Minimum Spanning Tree) for the above graph is:

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 ≤ T ≤ 5
2 <= N <= 100
1 <= M <= min(1000, N(N - 1) / 2)
1 <= E[i][0], E[i][1] <= N

*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Create adjacency list
    // SC: O(m)
    unordered_map<int, vector<pair<int, int>>> adj;
    for (auto &p : g) {
        int u = p.first.first;
        int v = p.first.second;
        int weight = p.second;

        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    // SC: O(n)
    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    // Min-heap: {key, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start from node 1
    key[1] = 0;
    pq.push({0, 1});

    // TC: O((n + m) log n)
    while (!pq.empty()) {
        auto [wt, u] = pq.top();
        pq.pop();

        if (mst[u]) continue;

        mst[u] = true;

        for (auto &[v, w] : adj[u]) {
            if (!mst[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;

    // Build MST result edges
    for (int i = 2; i <= n; i++) {
        result.push_back({{parent[i], i}, key[i]});
    }

    // Overall:
    // Time Complexity: O((n + m) log n)
    // Space Complexity: O(n + m)
    return result;
}
