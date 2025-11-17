/*
Problem statement
You are given an unweighted directed graph having 'V' vertices and 'E' edges. Your task is to count the number of strongly connected components (SCCs) present in the graph.

A directed graph is said to be strongly connected if every vertex is reachable from every other vertex. The strongly connected components of a graph are the subgraphs which are themselves strongly connected.

Note :
Use zero-based indexing for the vertices.

The given graph doesn’t contain any self-loops.
*/

#include <iostream>
#include <vector>
#include<unordered_map>
#include<stack>
using namespace std;

void dfs(int node,unordered_map<int,vector<int>> &adj,unordered_map<int,bool> &visited,stack<int> &st){

	visited[node]=true;
	for(auto neighbour: adj[node]){
		if(!visited[neighbour]){
			dfs(neighbour,adj,visited,st);
		}
	}

	st.push(node);
}

void revDfs(int top,unordered_map<int,vector<int>> &transpose,unordered_map<int,bool> &visited){
	visited[top]=true;
	for(auto neighbour:transpose[top]){
		if(!visited[neighbour]){
			revDfs(neighbour,transpose,visited);
		}
	}

}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.

	//SC:O(V+E) and TC:O(E)
	// Create the adjacency list
	unordered_map<int,vector<int>> adj;
	for(auto p:edges){
		int U=p[0];
		int V=p[1];

		adj[U].push_back(V);
	}

	// Topological sort
	stack<int> st;
	unordered_map<int,bool> visited;
	//SC:O(V) and TC:O(V+E)
	for(int i=0;i<v;i++){
		if(!visited[i]){
			dfs(i,adj,visited,st);
		}
	}

	//Transpose(reverse) the edges
	// Create a transpose graph
	unordered_map<int,vector<int>> transpose;

	//TC:O(V+E) and SC:O
	for(int i=0;i<v;i++){
		visited[i]=false;
		for(auto neighbour:adj[i]){
			transpose[neighbour].push_back(i);
		}
	}

	// dfs call using above ordering
	//TC:O(V+E)
	int count=0;
	while(!st.empty()){
		int top=st.top();
		st.pop();

		if(!visited[top]){
			count++;
			revDfs(top,transpose,visited);
		}
	}

	//Overall TC:O(V+E) and  SC:O(V+E)
	return count;

}