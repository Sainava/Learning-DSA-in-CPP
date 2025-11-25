/*
Problem statement
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// backtracking solver: updates maxValue and bestItems by reference
void solve(int index,
           int currValue,
           int currWeight,
           int &maxValue,
           vector<int> &currItems,
           vector<int> &bestItems,
           const vector<int> &weight,
           const vector<int> &value,
           int n,
           int maxWeight)
{
    // Base condition: considered all items
    if (index == n) {
        if (currValue > maxValue) {
            maxValue = currValue;
            bestItems = currItems;
        }
        return;
    }

    // Exclude current item
    solve(index + 1, currValue, currWeight, maxValue,
          currItems, bestItems, weight, value, n, maxWeight);

    // Include current item (if it fits)
    if (currWeight + weight[index] <= maxWeight) {
        currItems.push_back(index);              
        solve(index + 1,
              currValue + value[index],
              currWeight + weight[index],
              maxValue,
              currItems, bestItems,
              weight, value, n, maxWeight);     
        currItems.pop_back();                    // backtrack
    }
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    int currValue = 0;
    int currWeight = 0;
    int maxValue = 0;
    vector<int> currItems;
    vector<int> bestItems;


    solve(0, currValue, currWeight, maxValue,
          currItems, bestItems, weight, value, n, maxWeight);


	//TC:O(2^n)
	//SC:O(n)
    return maxValue;
}
