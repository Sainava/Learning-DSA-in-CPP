#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template<typename T>
class Graph {
public: 
    // Graph data structure can be defined here
    // For example, using an adjacency list or matrix

    //Adjacency list representation

    unordered_map<T,list<T>> adjList;

    // Adjacency matrix representation can also be used if needed
    vector<vector<int>> adjMatrix;

    Graph(int n){
        // Initialization of adjacency matrix
        adjMatrix.resize(n, vector<int>(n, 0));
    }

    Graph() {
        // Default constructor
        // This can be used to initialize an empty graph
    }

    // TC: O(1) for adding an edge in adjacency list
    void addEdgeMatrix(T u, T v, bool directed=false) {
        // Function to add an edge in the adjacency matrix
        adjMatrix[u][v] = 1;
        if(directed == false) {
            adjMatrix[v][u] = 1; // For undirected graph
        }
    }

    void addEdge(T u, T v,bool directed=false) {
        // Function to add an edge between vertices u and v
        adjList[u].push_back(v);
        if(directed==false){
            adjList[v].push_back(u);
        }
    }

    // TC: O(V+E) for displaying the graph using adjacency list
    // where V is the number of vertices and E is the number of edges
    void display() {
        // Function to display the graph
        
        // Iterate through each element in the map

        for(auto i : adjList){
            // Now i is a pair ,where i.first is the node and i.second is all the nodes connected to it
            cout<< i.first << "-> ";

            // i.second is a list of nodes connected to i.first
            for(auto j: i.second){
                cout << j << ", ";
            }
            cout << endl;
        }
    }

        void displayMatrix() {
            // Function to display the adjacency matrix
            for(int i = 0; i < adjMatrix.size(); i++) {
                for(int j = 0; j < adjMatrix[i].size(); j++) {
                    cout << adjMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }
    };


// Additional functions for graph operations can be added here
// For example, BFS, DFS, shortest path algorithms, etc.

int main(){
   cout << "Hello, Graph!" << endl;

//    Graph<int> g;

   cout << "Enter the number of vertices: ";
   int n;
   cin >> n;
   cout << "Enter the number of edges: ";
   int m;
   cin >> m;
   cout << "Enter whether directed (0/1):" << endl;
   bool directed;
   cin >> directed;

//     cout << "Enter the edges (u v):" << endl;
//    for(int i=0;i<m;i++){
//         int u,v;
//         cin >> u >> v;
//         g.addEdge(u, v, directed);
//    }
//     cout << "Graph representation:" << endl;
//     g.display();

    Graph<int> g(n); // Create a graph with n vertices

    cout << "Enter the edges for adjacency matrix (u v):" << endl;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdgeMatrix(u, v, directed);
    }

    cout << "Adjacency Matrix representation:" << endl;

    g.displayMatrix();
    return 0;

// 4-> 3, 0, 
// 3-> 2, 1, 4, 
// 2-> 1, 3, 
// 1-> 0, 2, 3, 
// 0-> 1, 4, 
}