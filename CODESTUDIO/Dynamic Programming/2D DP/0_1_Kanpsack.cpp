/*
Problem statement
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Solution 1
int solve(vector<int> weight, vector<int> value, int index, int capacity,vector<vector<int>> &dp){
	//Base Case
	if(index==0){
		if(weight[0]<=capacity){
			return value[0];//included
		}else{
			return 0;//not included
		}
	}

	//Step 2:
	if(dp[index][capacity]!=-1){
		return  dp[index][capacity];
	}

	//Include current item in the knapsack
	int include=0; // Total value if we include current item
	if(weight[index]<=capacity){
		include=value[index] + solve(weight,value,index-1,capacity-weight[index],dp);
	}

	int exclude=0 + solve(weight,value,index-1,capacity,dp);// No change in capacity


	//Step 3:
	dp[index][capacity]=max(include,exclude);
	return dp[index][capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{	
	//This is 2-D DP as index and capacity both change so 2 values are changing 

	//Top-Down -- Recursion + Memoization

	//Step 1 
	vector<vector<int>> dp(n,vector<int> (maxWeight+1,-1));

	//TC:O(n x maxWeight)
	//SC:O(n x maxWeight)
	return solve(weight,value,n-1,maxWeight,dp);
}