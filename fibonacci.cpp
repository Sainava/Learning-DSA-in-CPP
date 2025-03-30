#include<iostream>
using namespace std;

int main(){
    int a,b,n;
    cout << "Enter the number upto whichh term" << endl;
    cin >>n;
    a=0;
    b=1;
    cout << a << " " << b << " "; 
    int sum=0;
    for ( int i=1;i<=n-2;i++){
        sum= a+b;
        cout << sum << " ";
        a=b;
        b=sum;
    }
    
}