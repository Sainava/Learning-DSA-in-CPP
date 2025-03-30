#include<iostream>
using namespace std;

void fib(int n){
    int a=1;
    int b=1;
    cout << a << " " << b << " " ;
    int sum= a+b;

    for (int i=1 ;i<=n-2;i++){
        cout << sum << " " ;
        a=b;
        b=sum;
        sum=a+b;
    }
}

int main(){
    int n ;
    cout << "Enter the terms" << " ";
    cin >> n;
    fib(n);
}