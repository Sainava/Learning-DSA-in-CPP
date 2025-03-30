#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


int main(){

    string s="My name is Sainava";
    int n=s.size();
    string temp;
    string ans;

    for(int i=0;i<=n;i++){
            if(s[i]==' ' || s[i]=='\0'){
                reverse(temp.begin(),temp.end());
                ans.append(temp);
                ans.push_back(s[i]);
                temp.clear();
               
            }
            else{
                temp.push_back(s[i]);
            }
    }

    cout << ans << endl;

}