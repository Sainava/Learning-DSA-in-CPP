/*
You have been given a directed weighted graph of ‘N’ vertices labeled from 1 to 'N' and ‘M’ edges. Each edge connecting two nodes 'u' and 'v' has a weight 'w' denoting the distance between them.



Your task is to calculate the shortest distance of all vertices from the source vertex 'src'.



Note:
If there is no path between 'src' and 'ith' vertex, the value at 'ith' index in the answer array will be 10^8.
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    
    vector<int> dist(n+1,1e8);

    dist[src]=0;

    //Run the followinf n-1 times
    for(int i=1;i<n;i++){
        //traverse all edge list
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];

            //dist[u]!=1e8 && dist[u]+wt<dist[v] 
            if((dist[u]+wt<dist[v])){
                dist[v]=dist[u]+wt;
            }
        }
    }

    // check for negative cycle
    // bool flag=0; // NO negative cylce present
    // for(int j=0;j<m;j++){
    //     int u=edges[j][0];
    //     int v=edges[j][1];
    //     int wt=edges[j][2];

    //     //dist[u]!=1e8 && dist[u]+wt<dist[v]
    //     if((dist[u]+wt<dist[v])){
    //         flag=1;//negative cycle present
    //         break;
    //     }
    // }


    // Bellman Ford cannot be applied on negative cycle

    vector<int>ans(n);

    for(int i=0;i<n;i++){
        ans[i]=dist[i+1];
    }

    // if(flag==0){
    //     return dist;// Actually should be return
    // }
    
    // return {};

    //TC :O(n*m) and SC:O(n)
    return dist;
}