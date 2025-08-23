/*
Problem statement
Given an adjacency list representation of a directed graph with ‘n’ vertices and ‘m’ edges. Your task is to return a list consisting of Breadth-First Traversal (BFS) starting from vertex 0.



In this traversal, one can move from vertex 'u' to vertex 'v' only if there is an edge from 'u' to 'v'. The BFS traversal should include all nodes directly or indirectly connected to vertex 0.



Note:
The traversal should proceed from left to right according to the input adjacency list.


Example:
Adjacency list: { {1,2,3},{4}, {5}, {},{},{}}

The interpretation of this adjacency list is as follows:
Vertex 0 has directed edges towards vertices 1, 2, and 3.
Vertex 1 has a directed edge towards vertex 4.
Vertex 2 has a directed edge towards vertex 5.
Vertices 3, 4, and 5 have no outgoing edges.
*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>

using namespace std;

void bfs(int node,unordered_map<int,bool> &visited,vector<vector<int>> &adj,vector<int> &ans){

    visited[node]=true;
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        
        ans.push_back(frontNode);


        for(auto neighbour:adj[frontNode]){
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=true;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // BFS

    // Make the data structures 
    unordered_map<int,bool> visited;
    vector<int> ans;

    //To traverse all the componenets
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bfs(i,visited,adj,ans);
        }
    }


    //TC:(n+m) as n nodes are traversed and m edges are traversed total as well when adding neighbours to queue
    //SC:O(n)
    return ans;
}