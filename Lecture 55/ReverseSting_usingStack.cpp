#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<char> s;

    string str;
    cout<< "Enter a string : " << " ";
    cin>> str;

    for(char c:str){
        s.push(c);
    }

    string ans="";
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    cout << "Reversed string: " << ans << endl;

    return 0;
}