/*Problem statement
The n-th term of Fibonacci series F(n), where F(n) is a function, is calculated using the following formula -

    F(n) = F(n - 1) + F(n - 2), 
    Where, F(1) = 1, F(2) = 1


Provided 'n' you have to find out the n-th Fibonacci Number. Handle edges cases like when 'n' = 1 or 'n' = 2 by using conditionals like if else and return what's expected.

"Indexing is start from 1"
*/
#include<iostream>
#include<vector>
using namespace std;

//Solution 1
int fib(int n,vector<int> &dp){
        //base case
        if(n<=1){
                return n;
        }

        // Step 2 --> check if dp already contains the value
        if(dp[n]!=-1){
                return dp[n];
        }

        // Step 3 -- > save ans in dp and return
        dp[n]=fib(n-1,dp) + fib(n-2,dp);
        return dp[n];
}
int main()
{       
    int n;
    cin>>n;

    // Top - Down == Recursion + Memoization

    // Step 1  - Create the dp vector
    // SC:O(n)
    vector<int> dp(n+1,-1);

    //TC : O(n) as n in recursive call stack and all n elements visited 
    // SC: O(n) for recursion
    cout<< fib(n,dp) << endl;

    // Overall time and Space complexity :O(n)
}

//Solution 2
int main()
{
        int n;
        cin >> n;

        // Bottom - Up ==== Tabulation

        // Step 1 : Create the dp
        //SC:O(n)
        vector<int> dp(n+1,-1);

        //Step 2 set the values of the 0th and 1st term
        dp[0]=0;
        dp[1]=1;

        // Step 3 : Use these to find the rest of the values
        //TC:O(n)
        for(int i=2;i<=n;i++){
                dp[i]=dp[i-1] + dp[i-2];
        }

        //Overall TC:O(n) and SC:O(n) == Still better than Top-down
        cout << dp[n] << endl;
}

//Solution 3
int main()
{
      int n;
      cin >> n;

      //Space optimization 

      //Step 1 : No need for vector 

      int prev1=0;
      int prev2=1;
      
      for(int i=2;i<=n;i++){
              int curr=prev1 + prev2;
              prev1=prev2;
              prev2=curr;
      }

      //TC : O(n)
      // SC:O(1) ==best yet
      cout << prev2<< endl;
}

