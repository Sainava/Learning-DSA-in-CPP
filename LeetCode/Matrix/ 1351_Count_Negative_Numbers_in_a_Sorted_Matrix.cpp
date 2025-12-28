/*
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

 

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100
 

Follow up: Could you find an O(n + m) solution?
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // Grid is sorted in non-decreasing order both by rows and columns

        int m = grid.size();
        int n = grid[0].size();
        
        int row = 0 , col = n-1;

        int count=0 ;

        // We will only count column wise to avoid double counting 
        while(row < m && col >=0){

            // Two cases 

            if(grid[row][col] < 0){
                // Then below, all are negative // basically all negatives in this column can be counted at once
                int belowCount = m - row;
                count +=belowCount;
                col --;
            }else{
                // grid [row][col] >=0;
                // To the left , all must be non negative , so we are done with this row 
                row ++ ;
            }

        }
        // We traverse in staircase style , at each element we change rows or columns so
        // TC :O(m + n )
        //SC:(1)
        return count ;

        }
};