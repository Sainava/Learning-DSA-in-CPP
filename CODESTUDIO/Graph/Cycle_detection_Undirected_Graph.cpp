/*
Problem statement
You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 to 'N'.

Your task is to find if the graph contains a cycle or not.

A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle.
*/

#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;

bool bfsCycle(int node,unordered_map<int,bool> &visited,unordered_map<int,vector<int>> &adj){
    visited[node]=true;

    queue<int> q;
    q.push(node);

    unordered_map<int,int> parent;
    parent[node]=-1;

    while(!q.empty()){
        int frontNode=q.front();
        q.pop();

        for(auto neighbour:adj[frontNode]){
            if(!visited[neighbour]){
                visited[neighbour]=true;
                q.push(neighbour);
                parent[neighbour]=frontNode;
            }
            //if visited
            else{
                if(parent[frontNode]!=neighbour){
                    return true;
                }
            }
        }
    }

    return false;

}

bool dfsCycle(int node,int parent,unordered_map<int,bool> &visited,unordered_map<int,vector<int>> &adj){
    visited[node]=true;

    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            visited[neighbour]=true;
            bool isCycle=dfsCycle(neighbour,node,visited,adj);
            if(isCycle){
                return true;
            }
        }
        //if visited
        else{
            if(parent!=neighbour){
                return true;
            }
        }
    }
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //Create the adj list
    unordered_map<int,vector<int>> adj;

    for(auto p: edges){
        int u=p[0];
        int v=p[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //Create the data structures
    unordered_map<int,bool> visited;

    //TC:O(n+m)
    //SC:O(n+m)
    //BFS
    for(int i=0;i<n;i++){
        bool isCycle=0;
        if(!visited[i]){
            isCycle=bfsCycle(i,visited,adj);
            if(isCycle){
                return "Yes";
            }
        }
    }

    //TC:O(n+m)
    //SC:O(n+m)
    //DFS
    for(int i=0;i<n;i++){
        bool isCycle=0;
        if(!visited[i]){
            isCycle=dfsCycle(i,-1,visited,adj);
            if(isCycle){
                return "Yes";
            }
        }
    }

    return "No";
}
