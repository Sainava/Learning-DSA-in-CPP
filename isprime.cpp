#include<iostream>
using  namespace std;
// 1-prime
// 0- not prime
bool isprime(int n){
    for (int i=2;i<n;i++){
        if (n%i==0){
            return 0;
        }
    }
    return 1;

}

int main(){
    int n;
    cout << "Enter number"<< " ";
    cin >> n;
    int ans=isprime(n);
    if (ans==0){
        cout << " NOt Prime" << endl;
    }
    else{
        cout << "  Prime" << endl;
    }
}
