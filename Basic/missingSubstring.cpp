#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

vector<string> substring(string s,string t){
    vector<string>og;
    vector<string>sub;
    istringstream ss(s);
    istringstream tt(t);
    string word;
    while(ss>>word){
        og.push_back(word);
    }
    while(tt>>word){
        sub.push_back(word);
    }
    int i=0;
    int j=0;
    vector<string> ans;
    while(i<og.size() && j<sub.size()){
        if(og[i]==sub[j]){
            i++;
            j++;
        }else{
            ans.push_back(og[i]);
            i++;    
        }
    }

    if(i<og.size()){
        for(int k=i;k<og.size();k++){
            ans.push_back(og[k]);
        }
    }
    return ans;
}

int main(){
    string s = "I like cheese and cheese is good";
    string t = "I cheese";
    vector<string> ans = substring(s,t);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}