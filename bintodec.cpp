#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n ;
    cout << " Enter the number :" << " " << endl;
    cin >> n;
    
    
    int ans=0;
    int i=0;

    /*Method 1
    while(n){
        int digit=n%10;
        ans=(digit * pow(2,i)) + ans;
        n=n/10;
        i++;
    }
    */

   //Method 2
   while(n){
    int digit = n%10;
    if (digit==1){
        ans=ans + pow(2,i);
       
    }
    n=n/10;
    i++;
   }
    cout << " The decimal equivalent is " << ans << endl;
    
}