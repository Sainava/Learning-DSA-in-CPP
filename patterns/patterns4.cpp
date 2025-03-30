#include<iostream>
using namespace std;

int main(){
    int n;
    cout<< "Enter:" << "\t";
    cin >> n;
    int i=1;
    /*
    while (i<=n){
        int j=1;
        char ch='A' +i-1;
        while (j<=i){
            cout<< ch << " ";
            j+=1;
        }
        cout << "\n";
        i+=1;
    }
    */
   /*
    char ch='A';
    while (i<=n){
        int j=1;
        while (j<=i){
            cout<< ch << " ";
            j+=1;
            ch+=1;
        }
        cout << "\n";
        i+=1;
    }
    */
   while (i<=n){
    char ch='D'-i+1;
        int j=1;
        while (j<=i){
            cout<< ch << " ";
            j+=1;
            ch+=1;
        }
        cout << "\n";
        i+=1;
    }

}