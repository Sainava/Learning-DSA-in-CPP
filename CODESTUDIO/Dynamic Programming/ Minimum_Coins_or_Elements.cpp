/*
You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum. You have to tell the minimum number of elements you have to take to reach the target sum ‘X’.

Note:
You have an infinite number of elements of each type.
*/

#include<iostream>
#include<vector>
using namespace std;


//Soluition 1
int solve(vector<int> &num, int x,vector<int> &dp){
    if(x==0){
        return 0;
    }

    if(x<0){
        return INT_MAX;
    }

    //Step 2 --> Check if the value already exits 
    if(dp[x]!=-1){
        return dp[x];
    }
    int mini = INT_MAX;
    for(int i=0;i<num.size();i++){
        int ans=solve(num,x-num[i],dp);

        if(ans!=INT_MAX){
            mini=min(mini,1+ans);
        }
    }

    //Step 3 -- > Store current value in dp
    dp[x]=mini;
    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{   
    //Top-Down --> Recursion + Memoization
    //Step 1 --> Create the dp
    vector<int> dp(x+1,-1); 
    int ans = solve(num,x,dp);

    if(ans==INT_MAX){
        return -1;
    }

    //TC:O(x.n) where n is the size of num as x times call in max recursion stack and each calls all n of num
    //SC:O(x)
    return ans;
}

//Solution 2
int minimumElements(vector<int> &num, int x)
{
    // Bottom- Up ---> Tabulation

    vector<int> dp(x+1,INT_MAX);

    dp[0]=0;

    // dp[i] shows the minimum number of coins required to make target(amount) i

    //Solve for every amout  from  1 to x

    for(int i=1;i<=x;i++){

        // Try for each coin provided in num

        for(int j=0;j<num.size();j++){
            if(i-num[j]>=0 && dp[i-num[j]]!=INT_MAX){
                dp[i]=min(dp[i],1+dp[i-num[j]]);
                //dp[i-num[j]]!=INT_MAX prevents overflow of size as INT_MAX + 1 will cause overflow
            }
        }
    }

    if(dp[x]==INT_MAX){
        return -1;
    }

    //TC :O(x.n)
    //SC:O(x)
    return dp[x];

}


//Space Optimsation is not possible here

/*

In problems like climbing stairs, the number of ways to reach step i only depends on a fixed, constant number of previous steps (e.g., `i-1` and `i-2`).
 This predictable dependency allows us to optimize space by only storing the results for those few preceding states.

In contrast, for the coin change problem, to find the solution for amount i, we might need to look back at any previous amount `i - num[j]`. 
Since the `num` array can have many different coin numbers, we have to consider a variable number of previous states that could be located anywhere before `i`. Because we can't predict which ones we'll need, we must store the solution for every amount up to i, which prevents space optimization. 
The size of num may be equal to x as well so space optimisation is not guaranteed in cases like this

*/