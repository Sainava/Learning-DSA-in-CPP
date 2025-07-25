#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

template<typename T>
class Graph {
public:
    // Adjacency list representation
    unordered_map<T, list<T>> adjList;

    Graph() {
        // Default constructor
    }

    // Function to add an edge between vertices u and v
    void addEdge(T u, T v, bool directed = false) {
        adjList[u].push_back(v);
        if (!directed) {
            adjList[v].push_back(u);
        }
    }

    // Function to display the graph
    void display() {
        for (auto i : adjList) {
            cout << i.first << "-> ";
            for (auto j : i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    // BFS implementation using queue
    // TC: O(V+E), SC: O(V) for visited array and queue
    void BFS(T startNode) {
        cout << "\nBFS Traversal starting from " << startNode << ": ";
        
        unordered_map<T, bool> visited;
        queue<T> q;
        
        // Mark the starting node as visited and enqueue it
        visited[startNode] = true;
        q.push(startNode);
        
        while (!q.empty()) {
            T currentNode = q.front();
            q.pop();
            cout << currentNode << " ";
            
            // Visit all adjacent nodes of the current node
            for (auto neighbor : adjList[currentNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // DFS implementation using recursion
    // TC: O(V+E), SC: O(V) for visited array and recursion stack
    void DFSUtil(T node, unordered_map<T, bool>& visited) {
        visited[node] = true;
        cout << node << " ";
        
        // Visit all adjacent nodes of the current node
        for (auto neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }
    
    void DFS(T startNode) {
        cout << "\nDFS Traversal (Recursive) starting from " << startNode << ": ";
        unordered_map<T, bool> visited;
        DFSUtil(startNode, visited);
        cout << endl;
    }

    // DFS implementation using stack (iterative)
    // TC: O(V+E), SC: O(V) for visited array and stack
    void DFS_Iterative(T startNode) {
        cout << "\nDFS Traversal (Iterative) starting from " << startNode << ": ";
        
        unordered_map<T, bool> visited;
        stack<T> s;
        
        s.push(startNode);
        
        while (!s.empty()) {
            T currentNode = s.top();
            s.pop();
            
            if (!visited[currentNode]) {
                visited[currentNode] = true;
                cout << currentNode << " ";
                
                // Push all adjacent nodes to stack
                // Note: We iterate in reverse to maintain left-to-right order
                for (auto it = adjList[currentNode].rbegin(); it != adjList[currentNode].rend(); ++it) {
                    if (!visited[*it]) {
                        s.push(*it);
                    }
                }
            }
        }
        cout << endl;
    }

    // BFS for disconnected components
    void BFS_Complete() {
        cout << "\nComplete BFS Traversal (handles disconnected components): ";
        unordered_map<T, bool> visited;
        
        for (auto node : adjList) {
            if (!visited[node.first]) {
                queue<T> q;
                visited[node.first] = true;
                q.push(node.first);
                
                while (!q.empty()) {
                    T currentNode = q.front();
                    q.pop();
                    cout << currentNode << " ";
                    
                    for (auto neighbor : adjList[currentNode]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        cout << endl;
    }

    // DFS for disconnected components
    void DFS_Complete() {
        cout << "\nComplete DFS Traversal (handles disconnected components): ";
        unordered_map<T, bool> visited;
        
        for (auto node : adjList) {
            if (!visited[node.first]) {
                DFSUtil(node.first, visited);
            }
        }
        cout << endl;
    }
};

int main() {
    cout << "Graph BFS and DFS Implementation\n";
    cout << "=================================\n";
    
    Graph<int> g;
    
    cout << "Enter the number of vertices: ";
    int n;
    cin >> n;
    
    cout << "Enter the number of edges: ";
    int m;
    cin >> m;
    
    cout << "Enter whether directed (1) or undirected (0): ";
    bool directed;
    cin >> directed;
    
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, directed);
    }
    
    cout << "\nGraph representation:" << endl;
    g.display();
    
    cout << "\nEnter starting node for traversal: ";
    int startNode;
    cin >> startNode;
    
    // Perform BFS
    g.BFS(startNode);
    
    // Perform DFS (Recursive)
    g.DFS(startNode);
    
    // Perform DFS (Iterative)
    g.DFS_Iterative(startNode);
    
    // Complete traversals (for disconnected graphs)
    g.BFS_Complete();
    g.DFS_Complete();
    
    return 0;
}