#include<iostream>
using namespace std;

void  gcd(int a,int b){

    if(a==0){
        cout << "The gcd is : " << b << endl;
        return;
  
    }
    else if(b==0){
        cout << "The gcd is : " << a << endl;
        return;
   
    }
    // while(a!=0 && b!=0){
    //     if(a>b){
    //         a=a%b;//a=a-b;
    //     }
    //     else{
    //         b=b%a;//b=b-a;
    //     }
    // }
    // cout << "The gcd is : " << (a==0?b:a) << endl;
    // return;
    while(a!=b){
        if(a>b){
            a=a-b;//a=a-b;
        }
        else{
            b=b-a;//b=b-a;
        }
    }
    cout << "The gcd is : " << (a==0?b:a) << endl;
    return;
    }

    


int main(){
    cout << "GCD(a,b) * LCM(a,b) = a*b" << endl;
    cout << "HCF(gcd) of 2 Numbers" << endl;
    cout << "gcd(a,b)= gcd(a-b,b) = gc(a%b,b)" << endl;
    cout<< "Keep doing the above till a or b  becomes 0" << endl;
    int a,b;
    cout << "Enter the 2 numbers : " <<" ";
    cin >> a >> b ; 

    gcd(a,b);
}