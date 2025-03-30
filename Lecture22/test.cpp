#include <iostream>
#include<cmath>
#include<string>
using namespace std;

int main() {
    // std::string s="Sainava";
    // cout<< s[7]<<endl;
    
    // char name[8]="sainava";
    // cout << name[7]<<endl;
    // char arr[20]="Sainava";
    // arr[9] = 'Z';
    // for(int i=0;i<20;i++){
    // cout << int(arr[i])<< endl;
    // }
    string s("Sainava\0Modak");
    s.push_back('\0');
    s.push_back('z');
    cout<< s.length() << endl;
    cout << s<<endl ;
    s[0]='x';
    cout << s<< endl;


    char arr[20]="Sainava\0Modak" ;
    arr[13]='\0';
    arr[14]='z';
    cout << arr<<endl ;

    
     return 0;


}