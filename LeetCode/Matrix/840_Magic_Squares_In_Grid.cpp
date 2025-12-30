/*
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 magic square subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

 

Example 1:


Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:

while this one is not:

In total, there is only one magic square inside the given grid.
Example 2:

Input: grid = [[8]]
Output: 0
 

Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 10
0 <= grid[i][j] <= 15
*/
#include <iostream>
#include <vector>  
using namespace std;


class Solution {
public:
    bool isMagic(vector<vector<int>>& grid , int r , int c){
        // Magic Square is always 3x3

        // Condition 1 : Centre must be 5
        //TC:O(1)
        if( grid[r+1][c+1] != 5 ) return false ;

        // Condition 2 : Numbers are from 1 till 9 all inclusive and distinct
        //TC:O(3 x 3) = TC:O(1)
        //SC:O(10) = SC:O(1)
        vector<bool> seen(10,false);
        for( int i = r ; i < r + 3 ; i++){
            for ( int j= c ; j < c + 3 ; j++){
                int num=grid[i][j];
                if(num < 1 || num > 9 || seen[num]) return false;
                seen[num] = true ;
            }
        }

        // Condition 3 : Sum of each row , col and diagonal = Same
        //TC:O(1)
        // Find Sum From First Row 
        int sum = grid[r][c] + grid[r][c+1] + grid[r][c+2];

         for (int i = 0; i < 3; i++) {
            // Check all rows 
            if (grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != sum)
                return false;
            
            //check all columns 
            if (grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i] != sum)
                return false;
        }

        //Check the diagonals 
        //TC:(1)
        if(grid[r][c] + grid [r + 1][c + 1] + grid[r+2][c+2] != sum ) return false ;
        if(grid[r][c+2] + grid [r + 1][c + 1] + grid[r+2][c] != sum ) return false ;


        return true ;

    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int count = 0 ;

        // runs (row-3) + 1 times = row - 2 times , which is accurate because we need window size of three so there are n-2 possible 
        //TC:O(row x col)
        for( int i = 0 ; i <= row - 3 ;i++){

            for ( int j = 0 ; j <= col - 3 ; j++){

                //TC:O(1)
                if( isMagic(grid , i , j)){
                    count++;
                }
            }
        }

        //TC:O(row x col)
        //SC:(1)
        return count ;
    }
};