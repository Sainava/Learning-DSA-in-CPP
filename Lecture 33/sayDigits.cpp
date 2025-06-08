#include<iostream>
using namespace std;

 void sayDigits(int n,string *arr){
    if(n==0){
        return;
    }
    int digit=n%10;
    sayDigits(n/10,arr);
    cout<< arr[digit] << " ";

 }

int main(){
    
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if(n<0){
        cout << "Negative numbers are not supported." << endl;
        return 1;
    }
    cout << "The digits are: ";
    sayDigits(n, arr);
    cout << endl;
    return 0;
}