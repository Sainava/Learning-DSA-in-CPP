#include<iostream>
using namespace std;

int setbits(int n){
        int count=0;
        while(n){
            if(n&1){
                count++;
            }
            n=n>>1;
        }
        return count;
}

int main(){
    int a,b;
    cout << "Enter number a and b"<< " ";
    cin >> a >> b;
    cout << setbits(a) + setbits(b) << endl;
    return 0;
}