/*
Problem statement
You have been given weights and values of ‘N’ items. You are also given a knapsack of size ‘W’.

Your task is to put the items in the knapsack such that the total value of items in the knapsack is maximum.

Note:
You are allowed to break the items.
Example:
If 'N = 4' and 'W = 10'. The weights and values of items are weights = [6, 1, 5, 3] and values = [3, 6, 1, 4]. 
Then the best way to fill the knapsack is to choose items with weight 6, 1 and  3. The total value of knapsack = 3 + 6 + 4 = 13.00   
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    double r1 = (double)a.second / a.first;
    double r2 = (double)b.second / b.first;
    return r1 > r2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(), items.end(), cmp);

    double maximumValue = 0.0;
    int capacity = w;

    for(int i = 0; i < n; i++) {
        int wt = items[i].first;
        int value = items[i].second;

        if(capacity == 0) break;

        if(wt <= capacity) {
            maximumValue += value;
            capacity -= wt;
        }
        else {
            // fraction
            double fraction = (double)capacity / wt;
            maximumValue += value * fraction;
            capacity = 0;
        }
    }

    return maximumValue;
}
