/*
You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi=INT_MIN;
        int n=accounts.size();
        int m=accounts[0].size();
        for(int i=0;i<n;i++){
            int wealth=0;
            for(int j=0;j<m;j++){
                wealth+=accounts[i][j];
            }
            maxi=max(maxi,wealth);
        }

        //TC:O(n*m)
        //SC:O(1);
        return maxi;
    }
};