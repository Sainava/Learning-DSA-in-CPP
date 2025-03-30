#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the number:" << " ";
    cin>> n;
    cout << " Printing NUmbers from 1 to n: " << endl;
    /*
    for(int i=1;i<=n;i++){
        cout << i << " ";
    }
    */
    // int i=1;
    // for(;;){
    //     if (i<=n){
    //     cout << i << " ";
    //     }
    //     else{
    //         break;
    //     }
    //     i++;
    // }
    for (int a=0,b=1,c=2;a<=0 && b<=1 && c<=2; a++,b++,c++){
        cout << a << " " << b <<" " << c << endl; 
    }
}