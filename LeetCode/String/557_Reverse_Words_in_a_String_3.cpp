/*
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "Mr Ding"
Output: "rM gniD"
 

Constraints:

1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int n=s.length()-1;
        while(i<=n){

            //Skip initial spaces if any 
            while(i<=n && s[i]==' '){
                i++;
            }
            
            //i is at start of a word
            int start=i;

            //now find the length of word
            while(i<=n && s[i]!=' '){
                i++;
            }

            int end=i-1;

            //Now reverse the word
            while(start < end){
                swap(s[start++],s[end--]);
            }
        }
         return s;
    }

   
};