#include<iostream>
using namespace std;

int ispower2(int n){
    int count=0;
    while(n!=0){
        if(n&1){
            count++;
        }
        n>>=1;
    }
    return count;
}

int main(){
    int num;
    cout << "Enter the number " << " ";
    cin>> num;

    int ans =ispower2(num);
    if(ans==1){
        cout << "IS a power of 2"<< endl;
    }
    else{
        cout << " Not a power of 2"<< endl;
    }

}