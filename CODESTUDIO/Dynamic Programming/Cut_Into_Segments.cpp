/*
Problem statement
You are given an integer ‘N’ denoting the length of the rod. You need to determine the maximum number of segments you can make of this rod provided that each segment should be of the length 'X', 'Y', or 'Z'.
*/

#include<iostream>
#include<limits.h>
#include<algorithm>
#include<vector>
using namespace std;

//Solution 1
int solve(int n, int x, int y, int z,vector<int> dp){
	//Base Case 
	if(n==0){
		return 0;
	}

	if(n<0){
		return INT_MIN; //This basically means it cannot be made using this combination of segments
	}

	//Step 2 --> check if value exits
	if(dp[n]!=-1){
		return dp[n];
	}

	int a=solve(n-x,x,y,z,dp) + 1;
	int b=solve(n-y,x,y,z,dp) +1;
	int c=solve(n-z,x,y,z,dp) + 1;

	dp[n]= max(a,max(b,c));
	return dp[n];
}


int cutSegments(int n, int x, int y, int z) {

	//Top - Down --> Recursion + Memoization
	//Step 1 -> Create the dp array 
	vector<int> dp(n+1,-1);
	//dp[i] contains the max number of segments that can be used to make a rod of this length
	//Likewise dp[n] represents the final ans so dp size is n+1

	int ans=solve(n,x,y,z,dp);

	if(ans<0){
		return 0;
	}

	//TC:O(n)
	//SC:O(n)

	return ans;
}


//Solution 2
int cutSegments(int n, int x, int y, int z) {
	// Tabulation --> Bottom - Up

	vector<int> dp(n+1,INT_MIN);

	dp[0]=0;

	for(int i=1;i<=n;i++){
		if(i-x>=0) {
			dp[i]=max(dp[i],dp[i-x] + 1);
		}
		if(i-y>=0) {
			dp[i]=max(dp[i],dp[i-y] +1 ) ;
		}
			
		if(i-z>=0) {
			dp[i]=max(dp[i],dp[i-z] +1) ;
		}
	}

	if(dp[n]<0){
		return 0;
	}

	//TC:O(n)
	//SC:O(n)
	return dp[n];

}