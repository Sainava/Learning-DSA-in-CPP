/*
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

 

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
Example 2:

Input: s = "azxxzy"
Output: "ay"
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
 

*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

//Solution 1
class Solution {
public:
    string removeDuplicates(string s) {
       int n=s.length();
       if (n==0) {return "";}

       string result;
       for(int i=0;i<n;i++){
        if (result.length()!=0 && result.back()==s[i]){
            result.pop_back();
        }
        else{
            result.push_back(s[i]);
        }

        
       }
       return result;
    }
 
};

//Solution 2 
class Solution {
public:
    string removeDuplicates(string s) {
    stack<char> st;
    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop();
        } else {  // Fixed: always push if no match
            st.push(c);
        }
    }
    string ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

};

//Solution 3
class Solution {
public:
    string removeDuplicates(string s) {
    
    string stack;

    for(char c:s){
        if(!stack.empty() && stack.back()==c){
            stack.pop_back();
        }else{
            stack.push_back(c);
        }
    }

    return stack;
}

};