/*Problem statement
A minimum spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices without any cycles and with the minimum possible total edge weight.



A spanning tree’s weight is the sum of the weights of each edge in the spanning tree.



You have been given a connected undirected weighted graph having 'n' vertices, from 1 to 'n', and 'm' edges.



You are given an array 'edges' of size 'm', containing the details of the edges of the graph.



Each element of 'edges' contains three integers, the two vertices that are being connected and the weight of the edge.



Find the weight of the minimum spanning tree of the given graph.



Example :
Input: 'n' = 5, 'm' = 6
'edges' = [[1, 2, 6], [2, 3, 5], [3, 4, 4], [1, 4, 1], [1, 3, 2], [3, 5, 3]]

Output: 11

Explanation: The given graph is:

The minimum spanning tree of the graph is:

And its weight is 1 + 2 + 5 + 3 = 11.

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool cmp(vector<int> a,vector<int> b){
	return a[2]<b[2];
}


void makeset(vector <int> &parent,vector<int> &rank,int n){
	for(int i=0;i<n;i++){
		parent[i]=i;
		rank[i]=0;
	}
}

int findParent(int node,vector <int> &parent){
	if(parent[node]==node){
		return node;
	}

	return parent[node]=findParent(parent[node],parent);
}

void unionSet(int u,int v,vector <int> &parent,vector<int> &rank){
	u=findParent(u,parent);
	v=findParent(v,parent);

	if(rank[u]<rank[v]){
		parent[u]=v;
	}
	else if(rank[v]<rank[u]){
		parent[v]=u;
	}
	else{
		parent[v]=u;
		rank[u]++;
	}
}

int kruskalMST(int n, vector<vector<int>> &edges)
{
	// create the disjoint set
	vector <int> parent(n);
	vector<int> rank(n);

	//TC:O(n)
	makeset(parent,rank,n);

	// Begin the kruskal algo 

	sort(edges.begin(),edges.end(),cmp); // TC:O(ElogE)

	//TC:O(E)
	int minWeight=0;
	for(auto &edge:edges){
		int u=findParent(edge[0],parent);
		int v=findParent(edge[1],parent);
		int wt=edge[2];

		if(u!=v){
			minWeight+=wt;
			unionSet(edge[0],edge[1],parent,rank);
		}
	}

	// IT is theoretically proposed that both the findParent and unionSet have 4alpha TC
	// BOTH their TC are cosnidered to be constant so TC:O(1) for both



	// Overall TC:O(ElogE) and SC:O(V)
	return minWeight;

}
