#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the number:" ;
    cin >> n;
    
    // int i=2;
    // while (i<n){
    //     if (n%i==0){
    //         cout << "Not a prime number for" << i << endl ;
    //     }
    //     else {
    //         cout << " Prime for " << i << endl;
    //     }
    //     i+=1;
    // }
    bool isprime=1;
    for (int i=2;i<n;i++){
        if (n%i==0){
            isprime=0;
            break;
        }
    }
    if (isprime==0){
        cout << " Is not a prime number" << endl;

    }
    else {
        cout <<"Is a prime number" << endl;
    }


}