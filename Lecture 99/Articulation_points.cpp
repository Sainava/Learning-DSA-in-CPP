#include<iostream>
using namespace std;

void dfs(int node,int parent,int timer,unordered_map<int,bool> &visited, vector<int> &disc,vector<int> &low,unordered_map<int,vector<int>> &adj,unordered_map<int,bool> &ap){
    visited[node]=true;

    disc[node]=low[node]=timer++;
    int child=0;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            dfs(neighbour,node,timer,visited,disc,low,adj,ap);
            low[node]=min(low[node],low[neighbour]);

            // check if articulation point
            if(low[neighbour]>=disc[node] && parent!=-1){
                ap[node]=1;
            }
            child++;
        }
        else{
            if(neighbour==parent){
                continue;
            }
            else{
                //backedge
                low[node]=min(low[node],disc[neighbour]);
            }
        }
    }

    if(parent==-1 && child>1){
        ap[node]=1;
    }

}



int main(){

    int n=5;
    int e=5;

    vector<pair<int,int>> edges;
    edges.push_back({0,3});
    edges.push_back({3,4});
    edges.push_back({0,4});
    edges.push_back({0,1});
    edges.push_back({1,2});

    //adj list
   unordered_map<int,vector<int>> adj;
    for(auto &p:edges){
        int u=p.first;
        int v=p.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Create the data structures 
    vector<int> disc(n,-1);
    vector<int> low(n,-1);
    int parent=-1;
    unordered_map<int,bool> visited;

    int timer=0;
    unordered_map<int,bool> ap;

    //dfs 
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,parent,timer,visited,disc,low,adj,ap);
        }
    }


    cout << "Articulation Points: ";
    for(auto &point:ap){
        if(point.second){
            cout << point.first << " ";
        }
    }
    cout << endl;

    cout <<"Time and Space Complexity : O(V + E) " << endl;
    return 0;
}