#include<iostream>
#include<algorithm> // For std::swap
using namespace std;


void reverseString(string &str,int i,int n){
    if(i>=n-1-i){
        return;
    }

    swap(str[i],str[n-1-i]);

    reverseString(str,i+1,n);
}

int main(){
    string str;
    cout << "Enter a string: ";
    cin >> str;
    int n = str.length();
    reverseString(str, 0, n );
    cout << "Reversed string: " << str << endl;

    return 0;
}