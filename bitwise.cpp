#include<iostream>
using namespace std;

int main(){

    int a=4;
    int b=6;
    int c = a & b;
    int d=a | b;
    int e= ~a;
    int f= a ^ b;

    cout <<c <<'\n';
    cout << d << '\n';
    cout << e << endl;
    cout << f << endl;
 // left shift (<<) multiply by power of two ( but not applicable for extremely large numbers)
 // right shift (>>) divide by powers of two
    cout << (17>>1) << endl;
    cout << (17>>2) << endl;
    cout << (19<<1) << endl;
    cout << (21<<2) << endl;

    int i=7;
     
    cout << i++ << endl;
    cout << ++i << endl;
    cout << i-- << endl;
    cout << --i << endl;
}