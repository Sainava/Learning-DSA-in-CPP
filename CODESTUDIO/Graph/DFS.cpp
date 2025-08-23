/*
Problem statement
Given an undirected and disconnected graph G(V, E), containing 'V' vertices and 'E' edges, the information about edges is given using 'GRAPH' matrix, where i-th edge is between GRAPH[i][0] and GRAPH[i][1]. print its DFS traversal.

V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 

E is the number of edges present in graph G.
Note :
The Graph may not be connected i.e there may exist multiple components in a graph.

*/

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

void dfs(int node,unordered_map<int,bool> &visited,unordered_map<int ,vector<int>> &adj,vector<int> &ans){
    visited[node]=true;
    ans.push_back(node);

    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            dfs(neighbour,visited,adj,ans);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Create the adjacency list 

    //SC:O(V+E) 
    unordered_map<int ,vector<int>> adj;

    //TC:O(E)
    for(auto p:edges){
        int u=p[0];
        int v=p[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //SC:O(V)
    // Make the data structures 
    unordered_map<int,bool> visited;
    vector<vector<int>> ans;


    // To traverse through each component
    //TC:O(V+E)
    for(int i=0;i<adj.size();i++){
        vector<int> component;
        if(!visited[i]){
            dfs(i,visited,adj,component);
            ans.push_back(component);
        }
    }

    //TC:O(V+E)
    //SC:O(V+E)
    return ans;

}