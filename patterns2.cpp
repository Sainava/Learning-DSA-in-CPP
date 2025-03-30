#include<iostream>
using namespace std;

int main(){
    int n;
    cout<< "Enter:" << "\t";
    cin >> n;
    int i=1;
     /*while (i<=n){
        int count=i;
        int j=1;
        while (j<=i){
            cout<< count << " ";
            j+=1;
            count+=1;
        }
        cout << "\n";
        i+=1;
    }
    */
   /*
    while (i<=n){
      
        int j=i;
        while (j>=1){
            cout<< j << " ";
            j-=1;
        }
        cout << "\n";
        i+=1;
    }
    */
     while (i<=n){
      
        int j=1;
        while (j<=i){
            cout<< i-j+1 << " ";
            j+=1;
        }
        cout << "\n";
        i+=1;
    }
    }