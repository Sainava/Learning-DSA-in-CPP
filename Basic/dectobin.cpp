#include<iostream>
#include<math.h>
using namespace std;

int main(){

    int n;
    cout << "Enter the number :" << " ";
    cin >> n;

   
    int ans=0;
    int i=0;

    //Method 1
    while(n){

        int bit=n & 1;
        ans=(bit* pow ( 10 , i )) + ans;
        n= n>>1;
        i++;

    }   

    /*Method 2
   while(n){
        int rem=n % 2;
        ans=rem * pow(10,i) +ans;
        n=n/2;   
        i++;    
    }
    */
    cout << "The binary equivalent is : " << ans << endl;
}