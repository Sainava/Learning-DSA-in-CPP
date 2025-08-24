/*
Problem statement
A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles.

Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge from vertex ‘u’ to vertex ‘v’, vertex ‘u’ comes before ‘v’ in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

Given a DAG consisting of ‘V’ vertices and ‘E’ edges, you need to find out any topological sorting of this DAG. Return an array of size ‘V’ representing the topological sort of the vertices of the given DAG.
*/

#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>

using namespace std;

//Solution 1 --> USING DFS

void dfs_topology(int node,unordered_map<int,bool> &visited,unordered_map<int,vector<int>> &adj,stack<int> &st){
    visited[node]=true;

    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            dfs_topology(neighbour,visited,adj,st);
        }
    }

    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Create the adj list
    //SC:O(V+E)
    unordered_map<int,vector<int>> adj;

    //Topological sort can only be applied on Directed Acyclic Graph(DAG)
    //TC:O(E)
    for(auto p:edges){
        int u=p[0];
        int v=p[1];

        adj[u].push_back(v);
    }

    //TC:O(V)
    unordered_map<int,bool> visited;
    stack<int> st;

    //TC:O(V+E)
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs_topology(i,visited,adj,st);
        }
    }

    vector<int> ans;

    //TC:O(V)
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    //TC:O(V+E)
    //SC:O(V+E)
    return ans;
}


//Solution 2: BFS or Kahn's algo

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //Topological Sort using Kahn's Algo

    //Create the adj list
    //SC:O(V+E)
    unordered_map<int,vector<int>> adj;

    //TC:O(E)
    for(auto p:edges){
        int u=p[0];
        int v=p[1];

        adj[u].push_back(v);
    }

    //Create the indegree list
    vector<int> indegree(v);

    //TC:O(V+E)
    for(auto pairs:adj){
        for(auto neighbour:pairs.second){
            indegree[neighbour]++;
        }
    }

    queue<int> q;

    //Push the nodes with indegree 0 into the queue

    //TC:O(V)
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int> ans;

    //Do the Modified BFS
    //TC:O(V+E)
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();

        ans.push_back(frontNode);

        for(auto neighbour:adj[frontNode]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }

    //TC:O(V+E)
    //SC:O(V+E)
    return ans;
}