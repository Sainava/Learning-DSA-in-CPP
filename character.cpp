#include<iostream>
using namespace std;

int main(){
    char  ch;
    cout << "Enter the character: " ;
    cin >> ch;
    int a=int(ch);
    if(a>=65 && a<=90){
        cout << "The character is upper case" << endl;
    }
    else if (a>=97 && a<=122){
        cout << "The character is lower case " << endl;
    }
     else{
        cout << "The character is a numeric value" << endl;
     }

}