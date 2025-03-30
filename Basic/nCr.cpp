#include<iostream>
using namespace std;

long long fact(int num){
    if (num==0){
        return 1;
    }
    long long fact=1;
    int  i=1;
    while(i<=num){
        fact*=i;
        i++;
    }
    return fact;
}

long long   nCr(int  n,int  r){
        long long   num=fact(n);

        long long  den=(fact(r)*fact(n-r));
       
        return num/den;

}

 int main(){
    int n,r;
    cout << "Enter value of n and r " << " " ;
    cin >> n >> r;
    cout << " nCr is " << nCr(n,r) << endl;
}


