/*
Problem statement
Ninja has given a fence, and he gave a task to paint this fence. The fence has 'N' posts, and Ninja has 'K' colors. Ninja wants to paint the fence so that not more than two adjacent posts have the same color.

Ninja wonders how many ways are there to do the above task, so he asked for your help.

Your task is to find the number of ways Ninja can paint the fence. Print the answer modulo 10^9 + 7.

Example:
Input: 'N' = 3, 'K' = 2
Output: 6

Say we have the colors with the numbers 1 and 0. We can paint the fence with 3 posts with the following different combinations.
*/

#include<iostream>
using namespace std;
#define MOD 1000000007

//Solution 1
int add(int a,int b){
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a,int b){
    return (a%MOD *1LL* b%MOD)%MOD;
}

int solve(int n,int k,vector<int> &dp){
    //Base Case
    if(n==1){
        return k;
    }
    if(n==2){
        return add(k,mul(k,k-1)); //k + k(k-1)
    }

    //Step 2
    if(dp[n]!=-1){
        return dp[n];
    }

    //Step 3
    dp[n]= mul(k-1,add(solve(n-2,k,dp),solve(n-1,k,dp))); // (k-1)(solve(k-1) + solve(k-2))
    return dp[n];
}

int numberOfWays(int n, int k) {
    //Top-Down - Recursion + Memoization
    //Step 1
    vector<int> dp(n+1,-1);

    //TC:O(n)
    //SC:O(n)
    return solve(n,k,dp);
}


//Solution 2
int add(int a,int b){
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a,int b){
    return (a%MOD *1LL* b%MOD)%MOD;
}

int numberOfWays(int n, int k) {
    //Bottom-Up - Tabulation
    vector<int> dp(n+1,-1);

    dp[1]=k;
    dp[2]=add(k,mul(k,k-1));

    for(int i=3;i<=n;i++){
        dp[i]= mul(k-1,add(dp[i-2],dp[i-1]));
    }

    //TC:O(n)
    //SC:O(n)
    return dp[n];
}




//Solution 3
int add(long long a, long long b) {
    return (int)((a % MOD + b % MOD) % MOD);
}

int mul(long long a, long long b) {
    return (int)(((a % MOD) * (b % MOD)) % MOD);
}

int numberOfWays(int n, int k) {
    //Space optimisation
    if (n == 1) return k % MOD;
    if (n == 2) return add(k, mul(k, k - 1));

    long long prev1 = k % MOD;
    long long prev2 = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++) {
        long long curr = mul(k - 1, add(prev1, prev2));
        prev1 = prev2;
        prev2 = curr;
    }
    
    //TC:O(n)
    //SC:O(1)
    return (int)(prev2 % MOD);
}
