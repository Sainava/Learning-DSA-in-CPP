/*
You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair.



Each time, you can climb either one step or two steps.



You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.

Note:

Note: Since the number of ways can be very large, return the answer modulo 1000000007.

*/
#include <iostream>
#include<vector>
using namespace std;
#define MOD 1000000007
int solve(int n,vector<int> &dp){
    //Base Case
    if(n==0){
        //Ground floor reached --> One way found
        return 1;
    }
    if(n<0){
        //Invalid way
        return 0;
    }

    //Step 2 --> Check if value already calculted 
    if(dp[n]!=-1){
        return dp[n];
    }

    //Step 3--> Find the new value and store in dp
    dp[n]=solve(n-1,dp)%MOD + solve(n-2,dp)%MOD;

    return dp[n]%MOD;
}

int countDistinctWays(int nStairs) {

    //step 1 : Create the dp
    vector<int> dp (nStairs+1,-1);
    int ans=solve(nStairs,dp);

    return ans;
}