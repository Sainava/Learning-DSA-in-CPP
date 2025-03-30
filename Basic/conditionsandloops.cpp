#include<iostream>
using namespace std;

int main(){
    int a,b;
    cout << "Enter first value" << endl;
    cin >> a;
    cout << "Enter second value" << endl;
    cin>>b;
    if (a>b){
        cout << "First number is greater";
    }
    else{
        cout << "Second number is greater";
    }
}