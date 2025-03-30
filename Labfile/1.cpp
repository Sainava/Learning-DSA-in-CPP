#include<iostream>
using namespace std;


bool isLeap(int n){

    if ((n%4==0) && (n%400==0) || (n%100!=0)){
        return true;
    }
    return false;
}


int main(){
    int n;
    cout << "Enter the year:" << " ";
    cin>>n;
    if(isLeap(n)){
        cout << "Leap year" << endl;
    }
    else{
        cout << "Not a leap year" << endl;
    }

}