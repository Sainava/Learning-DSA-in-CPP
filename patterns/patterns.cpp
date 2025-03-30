#include<iostream>
using namespace std;

int main(){
    int n;
    cout<< "Enter:" << "\t";
    cin >> n;
    int i=1;
    while (i<=n){
        int j=1;
        while (j<=n){
            cout<< n-j+1 << " ";
            j+=1;
        }
        cout << "\n";
        i+=1;
    }
}