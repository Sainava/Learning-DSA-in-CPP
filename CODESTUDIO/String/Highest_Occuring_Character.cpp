/*
Problem statement
For a given a string(str), find and return the highest occurring character.

Example:
Input String: "abcdeapapqarr"
Expected Output: 'a'
Since 'a' has appeared four times in the string which happens to be the highest frequency character, the answer would be 'a'.
If there are two characters in the input string with the same frequency, return the character which comes first.

Consider:
Assume all the characters in the given string to be in lowercase always.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second
Sample Input 1:
abdefgbabfba
Sample Output 1:
b
Sample Input 2:
xy
Sample Output 2:
x
*/

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>
using namespace std;

char highestOccurringChar(char input[]) {

    vector<int> freq(26,0);

    for(int i=0;input[i]!='\0';i++){
        int index=input[i]-'a';
        freq[index]++;
    }

    int maxfreq=INT_MIN;
    int maxIdx=0;
    for(int i=0;i<26;i++){
        if(freq[i] > maxfreq){
            maxfreq=freq[i];
            maxIdx=i;
        }
    }
    char ans='a' + maxIdx;;
    return ans;

}