#include<iostream>
using namespace std;

int power(int a , int b){
    if(b==0){
        return 1;
    }
    if (b==1){
        return a;
    }

    int ans=power(a,b/2);

    if(b%2==0){
        return ans*ans;
    } else {
        return a*ans*ans;
    }
}

int main(){
    int a, b;
    cout << "Enter base (a): ";
    cin >> a;
    cout << "Enter exponent (b): ";
    cin >> b;
    if (b < 0) {
        cout << "Exponent must be a non-negative integer." << endl;
        return 1; // Exit with an error code
    }
    int result = power(a, b);
    cout << "Result of " << a << " raised to the power of " << b << " is: " << result << endl;
    
    return 0;
}