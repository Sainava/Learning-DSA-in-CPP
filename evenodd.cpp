#include<iostream>
using namespace std;

bool isEven(int n){

    if(n&1){
        return 0;
    }
    return 1;
}

int main(){
    int n;
    cout << "Enter the number : " << " " ;
    cin >> n;
    
    int ans=isEven(n);
    if(ans){
        cout <<"The number is even"<< endl;
    }
    else{
        cout << "The number is odd" << endl;
    }
    
}