/*
You are stacking blocks to form a pyramid. Each block has a color, which is represented by a single letter. Each row of blocks contains one less block than the row beneath it and is centered on top.

To make the pyramid aesthetically pleasing, there are only specific triangular patterns that are allowed. A triangular pattern consists of a single block stacked on top of two blocks. The patterns are given as a list of three-letter strings allowed, where the first two characters of a pattern represent the left and right bottom blocks respectively, and the third character is the top block.

For example, "ABC" represents a triangular pattern with a 'C' block stacked on top of an 'A' (left) and 'B' (right) block. Note that this is different from "BAC" where 'B' is on the left bottom and 'A' is on the right bottom.
You start with a bottom row of blocks bottom, given as a single string, that you must use as the base of the pyramid.

Given bottom and allowed, return true if you can build the pyramid all the way to the top such that every triangular pattern in the pyramid is in allowed, or false otherwise.

 

Example 1:


Input: bottom = "BCD", allowed = ["BCC","CDE","CEA","FFF"]
Output: true
Explanation: The allowed triangular patterns are shown on the right.
Starting from the bottom (level 3), we can build "CE" on level 2 and then build "A" on level 1.
There are three triangular patterns in the pyramid, which are "BCC", "CDE", and "CEA". All are allowed.
Example 2:


Input: bottom = "AAAA", allowed = ["AAB","AAC","BCD","BBE","DEF"]
Output: false
Explanation: The allowed triangular patterns are shown on the right.
Starting from the bottom (level 4), there are multiple ways to build level 3, but trying all the possibilites, you will get always stuck before building level 1.
 

Constraints:

2 <= bottom.length <= 6
0 <= allowed.length <= 216
allowed[i].length == 3
The letters in all input strings are from the set {'A', 'B', 'C', 'D', 'E', 'F'}.
All the values of allowed are unique.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool dfs(string row, unordered_map<string, vector<char>>& mp,
            unordered_map<string, bool>& memo) {

        if (row.size() == 1) return true;

        if (memo.count(row)) return memo[row]; // 🔥 key fix

        vector<string> nextRows;
        buildNextRows(row, 0, "", nextRows, mp);

        for (auto &nr : nextRows) {
            if (dfs(nr, mp, memo)) {
                return memo[row] = true;
            }
        }

        return memo[row] = false;
    }

    void buildNextRows(string &row, int idx, string cur,
                   vector<string> &res,
                   unordered_map<string, vector<char>> &mp)
    {
        if (idx == row.size() - 1) {
            res.push_back(cur);
            return;
        }

        string key = row.substr(idx, 2);
        if (!mp.count(key)) return;

        for (char c : mp[key]) {
            buildNextRows(row, idx + 1, cur + c, res, mp);
        }
 
    };
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;
        for (auto &s : allowed)
            mp[s.substr(0,2)].push_back(s[2]);

        unordered_map<string, bool> memo;
        return dfs(bottom, mp, memo);

        // Time Complexity: Exponential in the length of bottom,
        // worst-case O(6^(n²)), but bounded and acceptable since n ≤ 6.

        // Space Complexity: O(n) due to recursion stack and temporary strings.

    }
};
