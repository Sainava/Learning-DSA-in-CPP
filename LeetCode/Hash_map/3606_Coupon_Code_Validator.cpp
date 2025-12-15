/*
You are given three arrays of length n that describe the properties of n coupons: code, businessLine, and isActive. The ith coupon has:

code[i]: a string representing the coupon identifier.
businessLine[i]: a string denoting the business category of the coupon.
isActive[i]: a boolean indicating whether the coupon is currently active.
A coupon is considered valid if all of the following conditions hold:

code[i] is non-empty and consists only of alphanumeric characters (a-z, A-Z, 0-9) and underscores (_).
businessLine[i] is one of the following four categories: "electronics", "grocery", "pharmacy", "restaurant".
isActive[i] is true.
Return an array of the codes of all valid coupons, sorted first by their businessLine in the order: "electronics", "grocery", "pharmacy", "restaurant", and then by code in lexicographical (ascending) order within each category.

 

Example 1:

Input: code = ["SAVE20","","PHARMA5","SAVE@20"], businessLine = ["restaurant","grocery","pharmacy","restaurant"], isActive = [true,true,true,true]

Output: ["PHARMA5","SAVE20"]

Explanation:

First coupon is valid.
Second coupon has empty code (invalid).
Third coupon is valid.
Fourth coupon has special character @ (invalid).
Example 2:

Input: code = ["GROCERY15","ELECTRONICS_50","DISCOUNT10"], businessLine = ["grocery","electronics","invalid"], isActive = [false,true,true]

Output: ["ELECTRONICS_50"]

Explanation:

First coupon is inactive (invalid).
Second coupon is valid.
Third coupon has invalid business line (invalid).
 

Constraints:

n == code.length == businessLine.length == isActive.length
1 <= n <= 100
0 <= code[i].length, businessLine[i].length <= 100
code[i] and businessLine[i] consist of printable ASCII characters.
isActive[i] is either true or false.
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
    bool isValidCode(string &code)
{   
    if(code.empty()) return false;

    for(char c:code){
        if( !isalnum(c) && c!='_'){
            return false;
        }
    }
    return true;
}
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

    unordered_set<string> validBusiness = {
                "electronics", "grocery", "pharmacy", "restaurant"
            };
    
    unordered_map<string, int> order = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };
    
    vector<pair<string, string>> valid;
    //{businessLine,code}

    int n = code.size();

    //O(n.L)
    for(int i=0;i<code.size();i++){

        if(!isActive[i]) continue; //O(1)
        if (!isValidCode(code[i])) continue; //O(L) L being the length of longest code
        if (validBusiness.count(businessLine[i]) == 0) continue; //O(1)

        valid.push_back({businessLine[i], code[i]}); //)(1)
    }

    //O(nlogn.L)
    sort(valid.begin(),valid.end(),[&](pair<string,string> &a,pair<string,string> &b){

        //IF not same business line  
        if(order[a.first]!=order[b.first]){
            return order[a.first] < order[b.first];
        }

        //If same business line 
        //O(L) comparison in worst case
        return a.second<b.second;
    });

    vector<string> result;
    for (auto &p : valid) {
            result.push_back(p.second);
    }


    //TC:O(nlognL) but since L<=100
    //TC:O(nlogn)
    //SC:O(n)
    return result;
    }
};