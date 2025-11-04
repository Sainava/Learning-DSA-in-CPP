/*
Problem statement
You are given a directed acyclic graph of 'N' vertices(0 to 'N' - 1) and 'M' weighted edges.



Return an array that stores the distance(sum of weights) of the shortest path from vertex 0 to all vertices, and if it is impossible to reach any vertex, then assign -1 as distance.



For Example:
'N' = 3, 'M' = 3, 'edges' = [0, 1, 2], [1, 2, 3], [0, 2, 6]].

Distance (0 to 0) = 0.
Distance (0 to 1) = 2.
Distance (0 to 2) = 0->1 + 1->2 = 2+3 = 5.
So our answer is [0, 2, 5].

*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <climits>
using namespace std;

void dfs(int node,unordered_map<int,vector<pair<int,int>>> &adj,unordered_map<int,bool> &visited,stack<int> &st){
    visited[node]=true;

    for(auto pairs:adj[node]){
        if(!visited[pairs.first]){
            dfs(pairs.first,adj,visited,st);
        }
    }

    st.push(node);
}


vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    // Step 1: Create the adj list
    //SC:O(m)
    unordered_map<int,vector<pair<int,int>>> adj;

    //TC:O(n)
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int weight=edges[i][2];

        adj[u].push_back({v,weight});
    }

    // Make the topological sort and store in stack
    unordered_map<int,bool> visited;
    stack<int> st;

    // TC: O(n + m) -> DFS visits each node once and traverses each edge exactly once 
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,adj,visited,st);
        }
    }

    //SC:O(m)
    vector<int> distance(n,INT_MAX);

    distance[0]=0;

    //TC:O(n)
    while(!st.empty()){
        
        int node=st.top();
        st.pop();
        int currDist=distance[node];
        
        if(currDist!=INT_MAX){
            for(auto pairs:adj[node]){
                if(currDist + pairs.second < distance[pairs.first]){
                    distance[pairs.first]=currDist + pairs.second;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        if(distance[i]==INT_MAX){
            distance[i]=-1;
        }
    }

    //Overall TC:O(n+m) and SC:O(n+m)
    return distance;
}
