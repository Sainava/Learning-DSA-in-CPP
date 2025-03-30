#include<iostream>
using namespace std;
//Given a=3 and d =7

int nAp(int n){

    return (3*n+7);

}

int main(){
    int n;
    cout << "Enter n" << endl;
    cin >> n;

    cout << "nth term of the ap is " << nAp(n) << endl;
}
