#include<iostream>
#include<cctype>
using namespace std;

bool isPalindrome(string &str,int i,int j){
    if(i>=j){
        return true;
    }
    if(tolower(str[i])!=tolower(str[j])){
        return false;
    }

    return isPalindrome(str,i+1,j-1);
}

int main(){
   string str;
    cout << "Enter a string: ";
    cin >> str;
    int n = str.length();

    isPalindrome(str, 0, n - 1) ? cout << "The string is a palindrome." << endl : cout << "The string is not a palindrome." << endl;
    return 0;
}