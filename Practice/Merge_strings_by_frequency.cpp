/*
Given two strings, merge them with the following merge function: instead of comparing the characters in the usual lexicographical order, compare them based on how many times they occur in their respective strings. Fewer occurrences mean the character is considered smaller; in case of equality, compare them lexicographically; in case of equality, take the character from the first string.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

string merge(string &first,string &second){
    unordered_map<char,int> freq1;
    unordered_map<char,int> freq2;

    for(char c:first){
        freq1[c]++;
    }
    for(char c:second){
        freq2[c]++;
    }

    string merged;
    int i=0,j=0;
    while(i<first.size() && j<second.size())
    {
        int c1=first[i];
        int c2=second[j];

        int f1=freq1[c1];
        int f2=freq2[c2];

        if(f1<f2){
            merged.push_back(c1);
            i++;
        }
        else if(f2<f1){
            merged.push_back(c2);
            j++;
        }else{
            if(c1<c2){
                merged.push_back(c1);
                i++;
            }else if(c2<c1){
                merged.push_back(c2);
                j++;
            }else{
                merged.push_back(c1);
                i++;
            }
        }
    }
    while(i<first.size()){
        merged.push_back(first[i]);
        i++;
    }
    while(j<second.size()){
        merged.push_back(second[j]);
        j++;
    }

    return merged;
}

int main(){
    string first;
    cin >>first;
    string second;
    cin >>second;

    string ans=merge(first,second);

    cout<<ans<<endl;
    return 0;
}