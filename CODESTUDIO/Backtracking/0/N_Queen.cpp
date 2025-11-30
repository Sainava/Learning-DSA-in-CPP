/*
Problem statement
The N Queens puzzle is the problem of placing N chess queens on an N * N chessboard such that no two queens attack each other.

Given an integer ‘N’, print all distinct solutions to the ‘N’ queen puzzle.

Two queens on the same chessboard can attack each other if any of the below condition satisfies:  
1. They share a row. 
2. They share a column. 
3. They share a diagonal. 
*/

#include <iostream> 
#include <vector>
#include <unordered_map>
using namespace std;

void addsolution(int n ,vector<vector<int>> &board ,vector<vector<int>> &ans){
	vector<int> temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			temp.push_back(board[i][j]);
		}
	}
	ans.push_back(temp);
}

bool isSafe(int row ,int col ,int n, vector<vector<int>> &board ,vector<vector<int>> &ans ){
	//check if col attack 
	for(int i=0;i<row;i++){
		if(board[i][col]==1){
			return false;
		}
	}

	//upper left diagonal
	int i=row-1,j=col-1;
	while(i>=0 && j>=0){
		if(board[i][j]==1){
			return false;
		}
		i--;j--;
	}

	//upper-right diagonal
	i=row-1;j=col+1;
	while(i>=0 && j<n){
		if(board[i][j]==1){
			return false;
		}
		i--;
		j++;
	}

	return true;
}

void solve(int row, int n ,vector<vector<int>> &board ,vector<vector<int>> &ans,
           unordered_map<int,bool> &colCheck,
           unordered_map<int,bool> &upperDiagonalCheck,
           unordered_map<int,bool> &lowerDiagonalCheck){

	if (row==n){
		addsolution(n,board,ans);
		return;
	}

	//check placing for every column in this row 
	for (int col=0;col<n;col++){
		if (colCheck[col]==0 && upperDiagonalCheck[(n-1) + (col - row)]==0 &&
           lowerDiagonalCheck[row + col]==0
		){
			// MARK
            board[row][col] = 1;
            colCheck[col] = 1;
            upperDiagonalCheck[(n-1)+(col-row)] = 1;
            lowerDiagonalCheck[row+col] = 1;

            // RECURSE FOR NEXT ROW
            solve(row+1, n, board, ans,
                  colCheck, upperDiagonalCheck, lowerDiagonalCheck);

            // UNMARK
            board[row][col] = 0;
            colCheck[col] = 0;
            upperDiagonalCheck[(n-1)+(col-row)] = 0;
            lowerDiagonalCheck[row+col] = 0;
		}
	}
}

vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> board(n,vector<int> (n,0));
	vector<vector<int>> ans;

	unordered_map<int,bool> colCheck;
    unordered_map<int,bool> upperDiagonalCheck;
    unordered_map<int,bool> lowerDiagonalCheck;

	solve(0,n,board,ans,colCheck,upperDiagonalCheck,lowerDiagonalCheck);

	return ans ;
}


/*
Solution 2
#include <bits/stdc++.h> 

void addsolution(int n ,vector<vector<int>> &board ,vector<vector<int>> &ans){
	vector<int> temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			temp.push_back(board[i][j]);
		}
	}
	ans.push_back(temp);
}

bool isSafe(int row ,int col ,int n, vector<vector<int>> &board ,vector<vector<int>> &ans ){
	//check if col attack 
	for(int i=0;i<row;i++){
		if(board[i][col]==1){
			return false;
		}
	}

	//upper left diagonal
	int i=row-1,j=col-1;
	while(i>=0 && j>=0){
		if(board[i][j]==1){
			return false;
		}
		i--;j--;
	}

	//upper-right diagonal
	i=row-1;j=col+1;
	while(i>=0 and j<n){
		if(board[i][j]==1){
			return false;
		}
		i--;
		j++;
	}

	return true;

}

void solve(int row, int n ,vector<vector<int>> &board ,vector<vector<int>> &ans){
	if (row==n){
		addsolution(n,board,ans);
		return;
	}

	//check placing for every column in this row 
	for (int col=0;col<n;col++){
		if (isSafe(row,col,n,board,ans)){
			board[row][col]=1;

			//next call for next row 
			solve(row+1,n,board,ans);

			//backtrack 
			board[row][col]=0;
		}
	}
}

vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> board(n,vector<int> (n,0));
	vector<vector<int>> ans;

	solve(0,n,board,ans);

	return ans ;
	
}
*/

/*
Solution 3
#include <bits/stdc++.h> 

void addSolution(vector<vector<int>> &ans,vector<vector<int>> &board,int n){
	vector<int>temp;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			temp.push_back(board[i][j]);
		}
	}

	ans.push_back(temp);
}


void solve(vector<vector<int>> &ans,vector<vector<int>> &board,int col,int n,unordered_map<int,bool> &rowCheck,unordered_map<int,bool> &upperDiagonalCheck,unordered_map<int,bool> &lowerDiagonalCheck){
	if(col==n){
		addSolution(ans,board,n);
		return;
	}
	// We have a col ,now we need to check which row we need the place the queen in 

	for(int row=0;row<n;row++){
		if (rowCheck[row]==0 && upperDiagonalCheck[(n+1)+(col-row)]==0 &&lowerDiagonalCheck[row+col]==0 ){
			rowCheck[row]=1;
			upperDiagonalCheck[(n+1)+(col-row)]=1;
			lowerDiagonalCheck[row+col]=1;
			board[row][col]=1;
			solve(ans,board,col+1,n,rowCheck,upperDiagonalCheck,lowerDiagonalCheck);

			// backtracking 
			board[row][col]=0;
			rowCheck[row] = 0;
			upperDiagonalCheck[(n+1)+(col-row)] = 0;
			lowerDiagonalCheck[row+col] = 0;

		}
	}
	
}
vector<vector<int>> nQueens(int n)
{
	//Sc:O(n*n)
	vector<vector<int>> board(n,vector<int>(n,0));

	vector<vector<int>> ans;

	int col=0;

	unordered_map<int,bool> rowCheck;
	unordered_map<int,bool> upperDiagonalCheck;
	unordered_map<int,bool> lowerDiagonalCheck;	
	solve(ans,board,col,n,rowCheck,upperDiagonalCheck,lowerDiagonalCheck);

	// TC:O(n!) and SC:O(n*n) see below for explanation -> IN both the submissions
	return ans;
	/*
	Great! ? Let?s break down the **time** and **space complexity** for your **final working `N-Queens` backtracking solution**:

---

## ?? **Time Complexity**

**Worst case:**

* For each column, you try all `n` rows ? for `n` columns.
* So, in theory: `O(n^n)` (exponential)

  * At column 1 ? n choices
  * At column 2 ? n choices
  * ? and so on ? total: `n^n` possible placements.

However:

* The **`isSafe` check** takes `O(n)` for each placement (checks row + 2 diagonals ? max `n` cells).
* So each placement takes `O(n)`.

Putting it together:

$$
\text{TC} = O(n^n \cdot n) = O(n^{n+1})
$$

But we often **simplify** to `O(n!)` for backtracking, because in practice you never place two queens in the same row. So each queen has ??n choices but only one per row in a valid placement.

? So **tight bound:**

$$
\text{TC} = O(n!) \cdot O(n) = O(n! \cdot n)
$$

---

## ?? **Space Complexity**

**Auxiliary space:**

* The board is `n x n` ? `O(n^2)`
* The recursion stack can go up to `n` calls deep ? `O(n)`

**Output space:**

* If you store all valid solutions, you could have up to `O(n!)` solutions.
* Each solution is `O(n^2)` (you store a flattened `n x n` board).

So the output space is **huge** for large `n`. But usually, we only care about **auxiliary space**, which is:

$$
\text{SC} = O(n^2) + O(n) = O(n^2)
$$

---

## ? **Final**

**Time Complexity:** `O(n! ? n)`
**Space Complexity:** `O(n^2)` (excluding output)

---

**Let me know if you?d like the same for the optimized version with hash arrays!** ??

	
}
*/


/*
#include <bits/stdc++.h> 

void addSolution(vector<vector<int>> &ans,vector<vector<int>> &board,int n){
	vector<int>temp;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			temp.push_back(board[i][j]);
		}
	}

	ans.push_back(temp);
}

bool isSafe(int row,int col,vector<vector<int>> &board,int n){

	int x=row;
	int y=col;

	// check no queens in the same row
	while(y>=0){
		if(board[x][y]==1){
			return false;
		}
		y--;
	}

	//Upper left Diagonals
	x=row;
	y=col;

	while(x>=0 && y>=0){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y--;
	}

	//lower left Diagonals
	x=row;
	y=col;

	while(x<n && y>=0){
		if(board[x][y]==1){
			return false;
		}
		x++;
		y--;
	}

	return true;	
}


void solve(vector<vector<int>> &ans,vector<vector<int>> &board,int col,int n){
	if(col==n){
		addSolution(ans,board,n);
		return;
	}
	// We have a col ,now we need to check which row we need the place the queen in 

	for(int row=0;row<n;row++){
		if (isSafe(row,col,board,n)){
			board[row][col]=1;
			solve(ans,board,col+1,n);

			// backtracking 
			board[row][col]=0;
		}
	}
	
}
vector<vector<int>> nQueens(int n)
{
	//Sc:O(n*n)
	vector<vector<int>> board(n,vector<int>(n,0));

	vector<vector<int>> ans;

	int col=0;
	solve(ans,board,col,n);

	// TC:O(n!) and SC:O(n*n) see below for explanation
	return ans;
	/*
	Great! ? Let?s break down the **time** and **space complexity** for your **final working `N-Queens` backtracking solution**:

---

## ?? **Time Complexity**

**Worst case:**

* For each column, you try all `n` rows ? for `n` columns.
* So, in theory: `O(n^n)` (exponential)

  * At column 1 ? n choices
  * At column 2 ? n choices
  * ? and so on ? total: `n^n` possible placements.

However:

* The **`isSafe` check** takes `O(n)` for each placement (checks row + 2 diagonals ? max `n` cells).
* So each placement takes `O(n)`.

Putting it together:

$$
\text{TC} = O(n^n \cdot n) = O(n^{n+1})
$$

But we often **simplify** to `O(n!)` for backtracking, because in practice you never place two queens in the same row. So each queen has ??n choices but only one per row in a valid placement.

? So **tight bound:**

$$
\text{TC} = O(n!) \cdot O(n) = O(n! \cdot n)
$$

---

## ?? **Space Complexity**

**Auxiliary space:**

* The board is `n x n` ? `O(n^2)`
* The recursion stack can go up to `n` calls deep ? `O(n)`

**Output space:**

* If you store all valid solutions, you could have up to `O(n!)` solutions.
* Each solution is `O(n^2)` (you store a flattened `n x n` board).

So the output space is **huge** for large `n`. But usually, we only care about **auxiliary space**, which is:

$$
\text{SC} = O(n^2) + O(n) = O(n^2)
$$

---

## ? **Final**

**Time Complexity:** `O(n! ? n)`
**Space Complexity:** `O(n^2)` (excluding output)

---

**Let me know if you?d like the same for the optimized version with hash arrays!** ??

	
}
*/