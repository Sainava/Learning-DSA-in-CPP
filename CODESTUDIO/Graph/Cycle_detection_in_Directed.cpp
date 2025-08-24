/*
Problem statement
You are given a directed graph having ‘N’ nodes. A matrix ‘EDGES’ of size M x 2 is given which represents the ‘M’ edges such that there is an edge directed from node EDGES[i][0] to node EDGES[i][1].

Find whether the graph contains a cycle or not, return true if a cycle is present in the given directed graph else return false.
*/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


//Solution 1: DFS
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

//Solution 2: BFS or Kahn's algo
#include<queue>
#include<unordered_map>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
   //Cycle detection using Topological Sort using Kahn's Algo

    //Create the adj list
    //SC:O(V+E)
    unordered_map<int,vector<int>> adj;

    //TC:O(E)
    for(auto p:edges){
        int u=p.first-1;
        int v=p.second-1; // Since in this question , the node starts from 1 ,so we make them start from zero so we can use our earlier logic 

        adj[u].push_back(v);
    }

    //Create the indegree list
    vector<int> indegree(n);

    //TC:O(V+E)
    for(auto pairs:adj){
        for(auto neighbour:pairs.second){
            indegree[neighbour]++;
        }
    }

    queue<int> q;

    //Push the nodes with indegree 0 into the queue

    //TC:O(V)
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    int count=0;

    //Do the Modified BFS
    //TC:O(V+E)
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();

        count++;

        for(auto neighbour:adj[frontNode]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }

    //TC:O(V+E)
    //SC:O(V+E)
    if(count==n){
        return false;
        //All elements traversed , valid  topological sort  -> no cycle
    }

    return true;
}