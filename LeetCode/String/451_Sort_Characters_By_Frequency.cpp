/*
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 

Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.
 

*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:

    string frequencySort(string s) {
        //SC:O(n)
        unordered_map<char,int> count;

        //TC:O(n)
        for(char c:s){
            count[c]++;
        }

        // Sorting n characters
        // Each comparison is O(1) (hash map lookup + char compare)
        //TC:O(nlogn)
        //SC:O(nlogn) as sorting uses this space complexity 
        sort(s.begin(),s.end(),[&](char a,char b){
            if(count[a]==count[b]){
                return a < b;
            }
            return count[a]>count[b];
        });

        //TC:O(nlogn)
        //SC:O(logn)
        return s;
    }
};