#include <iostream>
#include<cmath>
#include<string>
using namespace std;

int main() {

    string s;
    cout <<" Enter the string: ";
    getline(cin,s,',');// Reads until , is encountered .
    cout <<"The string is : "<< s << endl;


   char arr[20];
   cout << "Enter the string : ";
   cout << "Only reads till 9 characters";
   cin.getline (arr,10);
   cout << "THE string is : " << arr<<endl;
    
    
    
    return 0;
}