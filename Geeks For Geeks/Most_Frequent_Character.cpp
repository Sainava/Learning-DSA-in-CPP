/*
Given a string s of lowercase alphabets. The task is to find the maximum occurring character in the string s. If more than one character occurs the maximum number of times then print the lexicographically smaller character.
*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        vector<int> count(26,0);
        
        for(int i=0;i<s.length();i++){
            int index=s[i]-'a';
            count[index]++;
        }
            
        char maxChar='a';
        int maxCount=INT_MIN;
        for(int i=0;i<26;i++){
            if(count[i] > maxCount){
                maxCount=count[i];
                maxChar=i+'a';
            }
            
        }
        
        //TC:O(n) == n-> Size of string
        //SC:(1)
        
        return maxChar;
        
    }
};