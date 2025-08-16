/*
You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.

Note:
A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list, leaving the remaining elements in their original order.
*/
#include <iostream>
#include <vector>
using namespace std;

//Solution 1
int solve(vector<int> &nums,int n,vector<int> &dp){
    //Base case :
    if(n<0){
        return 0;
    }

    if(n==0){
        return nums[n];
    }

    //Check if the answer exits in dp 
    if(dp[n]!=-1){
        return dp[n];
    }

    // Two cases ---> Either include or exclude
    int inc=solve(nums,n-2,dp) + nums[n];
    int exc=solve(nums,n-1,dp)+ 0;

    //Step 3 --> Store in dp array and return
    dp[n]= max(inc,exc);
    return dp[n];
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();

    //Top - Down ---> Recursion + Memoization
    //Step 1 -> Create the dp array
    vector<int> dp(n,-1);
    //The dp stores the max sum value at each number --> i.e it stores maximum of (sum if included and sum if excluded)
 


    int ans=solve(nums,n-1,dp);

    //TC:O(n)
    /*
    The time complexity is O(n) because of the memoization. The recursive function solve is called for each index from n-1 down to 0. With the dp array, each state (dp[i]) is calculated only once. The calculations within each state are constant time operations (simple arithmetic and comparisons). Therefore, you perform a constant amount of work for each of the n states, resulting in a linear time complexity. 
    Think of it this way , the recursion stack will have at max n elements (when all are excluded) so O(n)
    */

    //SC:O(n)
    return ans;
}


//Solution 2
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();

    //Tabulation ----> Bottom- UP
    vector<int> dp(n,-1);

    dp[0]=nums[0];

    if(n>1){
        dp[1]=max(nums[0],nums[1]);
    }

    for(int i=2;i<n;i++){
        
        int inc =dp[i-2] + nums[i];
        int exc=dp[i-1] + 0;

        dp[i]=max(inc,exc);
    }

    //TC:O(n)
    //SC:O(n)
    return dp[n-1];
}


//Solution 3
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();

    //Space Optimisation

    int prev2=0; // Handles <0
    int prev1=nums[0]; // Handles 0

    for(int i=1;i<n;i++){
        
        int inc =prev2 + nums[i];
        int exc=prev1 + 0;

        int curr=max(inc,exc);

        prev2=prev1;
        prev1=curr;
    }

    //TC:O(n)
    //SC:O(1)
    return prev1;
}