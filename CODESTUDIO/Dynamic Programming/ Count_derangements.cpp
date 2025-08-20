/*
Problem statement
A Derangement is a permutation of ‘N’ elements, such that no element appears in its original position. For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is not at its initial position which is 2 and similarly for other elements of the sequence.

Given a number ‘N’, find the total number of derangements possible of a set of 'N’ elements.

Note:
The answer could be very large, output answer %(10 ^ 9 + 7).
*/
#include <iostream>
#include<vector>
using namespace std;

//Solution 1
#define MOD 100000007
long long int solve(int n,vector<long long int> &dp){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }

    //Step 2: 
    if(dp[n]!=-1){
        return dp[n];
    }
    
    //Step 3
    long long sum=(solve(n-1,dp)%MOD + solve(n-2,dp)%MOD)%MOD;
    dp[n]=((long long)(n-1)*sum)%MOD;
    return dp[n]; 
}

long long int countDerangements(int n) {
    // Top - Down - Recursion + Memoization
    vector<long long int> dp(n+1,-1);

    //TC:O(n) because we find out value for every value of n
    //SC:O(n)
    return solve(n,dp);

}


//Solution 2
long long int countDerangements(int n) {
    
    //Bottom-Up - Tabulation
    vector<long long> dp(n+1,-1);

    dp[1]=0;
    dp[2]=1;

    for(int i=3;i<=n;i++){
        long long sum=(dp[i-1]%MOD + dp[i-2]%MOD)%MOD;
        dp[i]=((long long)(i-1)*sum)%MOD;
    }

    //TC:O(n)
    //SC:O(n)
    return dp[n];
}

//Solution 3 
long long int countDerangements(int n) {
    
    //Space Optimisation

    long prev1=0;
    long prev2=1;

    for(int i=3;i<=n;i++){
        long long sum=(prev2%MOD + prev1%MOD)%MOD;
        long long curr=((long long)(i-1)*sum)%MOD;

        prev1=prev2;
        prev2=curr;
    }

    //TC:O(n)
    //SC:O(1)
    return prev2;
}