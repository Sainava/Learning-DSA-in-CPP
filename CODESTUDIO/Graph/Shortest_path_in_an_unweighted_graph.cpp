/*
Problem statement
The city of Ninjaland is analogous to the unweighted graph. The city has ‘N’ houses numbered from 1 to ‘N’ respectively and are connected by M bidirectional roads. If a road is connecting two houses ‘X’ and ‘Y’ which means you can go from ‘X’ to ‘Y’ or ‘Y’ to ‘X’. It is guaranteed that you can reach any house from any other house via some combination of roads. Two houses are directly connected by at max one road.

A path between house ‘S’ to house ‘T’ is defined as a sequence of vertices from ‘S’ to ‘T’. Where starting house is ‘S’ and the ending house is ‘T’ and there is a road connecting two consecutive houses. Basically, the path looks like this: (S , h1 , h2 , h3 , ... T). you have to find the shortest path from ‘S’ to ‘T’.

For example
In the below map of Ninjaland let say you want to go from S=1 to T=8, the shortest path is (1, 3, 8). You can also go from S=1 to T=8  via (1, 2, 5, 8)  or (1, 4, 6, 7, 8) but these paths are not shortest.
*/

#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	//In BFS -> addition of nodes takes place through the shortest path 
	//Say from 1 to 8 - > shortest path -3 nodes in between -> 3 times addirtion in graph -> 1st addition =2,3,4 -> 2nd addiotion=5,6 -> 3rd additon = 7

	//SC:O(n)
	vector<int> parent(n+1); // n+1 as nodes here start from 1
	unordered_map<int,bool> visited;
	queue<int> q;

	//Create the adjacency lst
	// SC:O(n+m)
	unordered_map<int,vector<int>> adj;

	//TC:O(m)
	for(auto p: edges){
		int u=p.first;
		int v=p.second;

		adj[u].push_back(v);
		adj[v].push_back(u);

	}

	q.push(s);
	visited[s]=true;
	parent[s]=-1;

	//Do modified bfs
	//TC:O(n+m)
	while(!q.empty()){
		int frontNode=q.front();
		q.pop();

		for(auto neighbour:adj[frontNode]){
			if(!visited[neighbour]){
				q.push(neighbour);
				visited[neighbour]=true;
				parent[neighbour]=frontNode;
			}
		}
	}

	vector<int> ans;
	int currentNode=t;
	ans.push_back(t);

	//TC:O(n) == Worst Case
	while(currentNode!=s){
		currentNode=parent[currentNode];
		ans.push_back(currentNode);
	}


	//TC:O(n) == Worst Case
	reverse(ans.begin(),ans.end());

	//TC:O(n+m) and SC:O(n+m)
	return ans;
}
