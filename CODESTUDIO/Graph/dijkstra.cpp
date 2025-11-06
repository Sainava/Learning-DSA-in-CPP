/*
Problem statement
You have been given an undirected graph of ‘V’ vertices (labeled 0,1,..., V-1) and ‘E’ edges. Each edge connecting two nodes (‘X’,’Y’) will have a weight denoting the distance between node ‘X’ and node ‘Y’.

Your task is to find the shortest path distance from the source node, which is the node labeled as 0, to all vertices given in the graph.

Example:

Input:
4 5
0 1 5
0 2 8
1 2 9
1 3 2
2 3 6

In the given input, the number of vertices is 4, and the number of edges is 5.

In the input, following the number of vertices and edges, three numbers are given. The first number denotes node ‘X’, the second number denotes node ‘Y’ and the third number denotes the distance between node ‘X’ and ‘Y’.

As per the input, there is an edge between node 0 and node 1 and the distance between them is 5.

The vertices 0 and 2 have an edge between them and the distance between them is 8.
The vertices 1 and 2 have an edge between them and the distance between them is 9.
The vertices 1 and 3 have an edge between them and the distance between them is 2.
The vertices 2 and 3 have an edge between them and the distance between them is 6.
Note:

1. There are no self-loops(an edge connecting the vertex to itself) in the given graph.

2. There can be parallel edges i.e. two vertices can be directly connected by more than 1 edge.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <set>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Create adjacency list
    // SC: O(V + E)
    unordered_map<int, list<pair<int, int>>> adj; // <node, <neighbour, weight>>

    // TC: O(E)
    for (auto &p : vec) {
        int u = p[0];
        int v = p[1];
        int weight = p[2];

        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    // Create the distance array, initialized to INF
    // SC: O(V)
    vector<int> dist(vertices, INT_MAX);

    // Min-heap: stores {distance, node}
    // SC: O(V)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source}); // Push source with distance 0

    // TC: O((V + E) * log V)
    while (!pq.empty()) {
        // Get the node with the smallest distance
        // O(log V)
        auto top = pq.top();
        pq.pop();

        int nodeDist = top.first;
        int topNode = top.second;

        // Optimization: skip outdated entries
        if (nodeDist > dist[topNode]) continue;

        // Traverse all adjacent nodes
        // Total across all nodes: O(E)
        for (auto &neighbour : adj[topNode]) {
            int adjNode = neighbour.first;
            int weight = neighbour.second;

            // Relaxation step
            if (nodeDist + weight < dist[adjNode]) {
                dist[adjNode] = nodeDist + weight;
                pq.push({dist[adjNode], adjNode}); // O(log V)
                // No need to remove existing entry; we allow duplicates and ignore outdated ones
            }
        }
    }

    // Final distance vector from source to all other nodes
    return dist;
}

/*
Time Complexity:
- Building adjacency list: O(E)
- Heap operations:
    - Insertion: O(log V)
    - In total, each node may be added multiple times (but only V * log V entries matter due to the visited check)
    - Edge relaxations: O(E * log V)
? Overall: O((V + E) * log V)

Space Complexity:
- Adjacency list: O(V + E)
- Distance array: O(V)
- Min-heap: O(V) (in worst case)
? Overall: O(V + E)
*/


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Create adjacency list

    // SC:O(m)
    unordered_map<int,list<pair<int,int>>> adj;// <node,<neighbour,dist>
    //TC:O(n)
    for(auto p:vec){
        int u=p[0];
        int v=p[1];
        int weight=p[2];

        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});
    }

    // Create the distance array
    //SC:O(n)
    vector<int> dist(vertices,INT_MAX);

    //Create the set
    set<pair<int,int>> st; // <dist,node>

    dist[source]=0;
    st.insert(make_pair(0,source));

    // TC: O((n + m) * log n)
while(!st.empty()){
    // Fetch the top record ? O(log n)
    auto top = *(st.begin());

    int nodeDist = top.first;
    int topNode = top.second;

    // O(log n): Removing the smallest distance node
    st.erase(st.begin());

    // Traverse all neighbours ? total work across all iterations: O(m)
    for(auto neighbour : adj[topNode]){
        // Relaxation condition
        if(nodeDist + neighbour.second < dist[neighbour.first]){
            // Find the old record in set ? O(log n)
            auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

            // If record found, erase ? O(log n)
            if(record != st.end()){
                st.erase(record);
            }

            // Update the distance and insert new pair ? O(log n)
            dist[neighbour.first] = nodeDist + neighbour.second;
            st.insert(make_pair(dist[neighbour.first], neighbour.first));
        }
    }
}


    //Overall TC:O(n+m) and SC:O(n+m)
    return dist;

    /*
In C++, std::set is an ordered container, not unordered like unordered_set.
It automatically keeps its elements sorted in ascending order using the < operator by default.

For set<pair<int, int>>, the comparison is lexicographical:

First compares the first element (which is distance here),

If those are equal, compares the second (the node ID).
    */

}
