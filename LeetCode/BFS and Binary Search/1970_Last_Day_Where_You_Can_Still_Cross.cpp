/*
There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.

Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).

You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).

Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.

 

Example 1:


Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
Output: 2
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 2.
Example 2:


Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
Output: 1
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 1.
Example 3:


Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
Output: 3
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 3.
 

Constraints:

2 <= row, col <= 2 * 104
4 <= row * col <= 2 * 104
cells.length == row * col
1 <= ri <= row
1 <= ci <= col
All the values of cells are unique.
*/

#include <iostream>
#include <vector>   
#include <queue> 
using namespace std;

class Solution {
public:

    // Global variables 
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

    // Check if we can cross on this day 
    bool canCross(int day, int row, int col, vector<vector<int>>& cells){

        // Step 1 : make the grid with all cells as land (we need to make the grid since we are not provided the actual grid)
        // SC:O(row x col)
        vector < vector<int>> grid ( row , vector<int>(col , 0 ));

        // Step 2 : make the cells water which were supposed to be till this day 
        for(int i = 0 ; i < day ; i++){
            int r = cells[i][0] - 1 ; 
            int c = cells[i][1] - 1 ;
            grid[r][c] = 1;
        }

        // We do bfs to see if a path exists from top row to bottom row 
        
        queue< pair<int,int> > q; 
        vector<vector<bool>> visited(row,vector<bool> (col , false ));

        // BFS from all land cells in the top row
        for(int j = 0 ; j < col ; j++){
            if(grid[0][j]== 0){
                q.push({0,j});
                visited[0][j]= true ;
            }
        }

        // BFS
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            if(x == row - 1) return true ; // reached final row 

            for(auto &d: directions){
                int newX= x + d[0];
                int newY= y + d[1];

                if( (newX >= 0 && newX<row) && (newY >= 0 and newY < col) && !visited[newX][newY] && grid[newX][newY] == 0 ){
                    q.push({newX,newY});
                    visited[newX][newY]= true ;
                }
            }
        }

        // cannot reach final row 
        return false ;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        // Here if the grid is uncrossable at day 'd' then it will also be crossable at 'd' + 1
        // Also if it is safe at day 'd' then it also safe at day 'd' - 1 
        // So we can safely cross out grater than and less than days , i.e a part of the sample space and hence here binary search can be used 

        // since 1 based indexing and on each day a single cell becomes flooded , so maximum days possible is row*col
        int start = 1 ; 
        int end = row * col ;

        int ans = 0 ;
        // Tc:O(log(row x col))
        while ( start <= end){

            int mid = start + (end - start)/2;

            // TC:O(row x col)
            if(canCross(mid , row , col , cells)){
                ans = mid ; 
                start = mid + 1 ; // It is possible for all days < start 
            }else{
                end = mid -1 ; // Not possible for days > end 
            }
        }

        //TC:O(log(row x col) x row x col)
        //SC:O(row x col)
        return ans;
    }
};