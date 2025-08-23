/*
Problem statement
You are given a directed graph having ‘N’ nodes. A matrix ‘EDGES’ of size M x 2 is given which represents the ‘M’ edges such that there is an edge directed from node EDGES[i][0] to node EDGES[i][1].

Find whether the graph contains a cycle or not, return true if a cycle is present in the given directed graph else return false.
*/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


int dfsCycle(int node,unordered_map<int,bool> &visited, unordered_map<int,bool> &dfs_visited,unordered_map<int,vector<int>> &adj){
    visited[node]=true;
    dfs_visited[node]=true;

    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            int isCycle=dfsCycle(neighbour,visited,dfs_visited,adj);
            if(isCycle){
                return 1;
            }
        }
        //if visited --> check if also dfs visited
        //dfs_visited =true means the node is still in the recursion stack , so a second call to that would mean cycle exists 
        else{
            if(dfs_visited[neighbour]){
                return 1;
            }     
        }
    }
    dfs_visited[node]=false;
    return 0;
}


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  //Create the adj list
  //SC:O(V+E)
  unordered_map<int,vector<int>> adj;


  for(auto &p:edges){
      int u=p.first;
      int v=p.second;

      adj[u].push_back(v);
  }

  //SC:O(V)  
  unordered_map<int,bool> visited;
  unordered_map<int,bool> dfs_visited;

  //TC:O(V+E)
  for(int i=0;i<n;i++){
      if(!visited[i]){
          int isCycle=dfsCycle(i,visited,dfs_visited,adj);
          if(isCycle){
              return 1;
          }
      }
  }
  //TC:O(V+E)
  //SC:O(V+E)
  return 0;
}