#include<iostream>
#include<math.h>
using namespace std;

int main(){

    int n;
    cout << "Enter the negative number :" << " ";
    cin >> n;

    // Handle the sign bit 
     bool isnegative= n<0;
     if ( isnegative){
        n=abs(n);
     }
    
    // First convert to binary

    int ans=0;
    int i=0;


    while(n){

        int bit=n & 1;
        ans=(bit* pow ( 10 , i )) + ans;
        n= n>>1;
        i++;

    }

    cout << "Ignoring sign binary representation is :" << ans << endl;

    // Now take 1's complement of 1

    int comp_1=0;
    int j=0;
    while(ans){
        int digit=ans%10;
        // if (digit==0){
        //     digit=1;
        // }
        // else{
        //     digit=0;
        // }
        digit=1-digit;// reverse the digits 
        cout << "digit is"<< " "<<  digit << endl;
        cout << "j is " << " " << j << endl;

        comp_1=(digit * pow (10,j)) + comp_1;
        cout <<  "c1 is :" << " " <<comp_1 << endl;
        ans=ans/10;
        j++;
}

cout << " comp1 :" << " " << comp_1 << endl;

// Now take 2's complement 
 
 int comp_2=comp_1 + 1;

 cout << "The binary equivalent of negative number is :" << comp_2 << endl;


}